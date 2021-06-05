if (U.db().foundObject<volVectorField>("UMean") || U.db().foundObject<volScalarField>("pMean"))
{
    //Preparation
    ksgs_  = turbulence->k(); //Instantaneous subgrid-scale tke m2/s2
    epsgs_ = turbulence->epsilon(); //Instantaneous subgrid-scale dissipation rate m2/s3
    nu_    = turbulence->nu(); //kinematic viscosity m2/s

    const objectRegistry& db = U.db();

    tmp<volVectorField> tUPrime(U - db.lookupObject<volVectorField>("UMean"));
    const volVectorField& UPrime = tUPrime(); //U'

    tmp<volScalarField> tpPrime(p - db.lookupObject<volScalarField>("pMean"));
    const volScalarField& pPrime = tpPrime(); //p'

    tmp<volVectorField> tgradpPrime(fvc::grad(pPrime));
    const volVectorField& gradpPrime = tgradpPrime(); //grad(p')

    tmp<volTensorField> tgradUPrime(fvc::grad(UPrime));
    const volTensorField& gradUPrime = tgradUPrime (); //grad(U')

    tmp<volSymmTensorField> tSPrime(symm(gradUPrime));
    const volSymmTensorField& SPrime = tSPrime(); //symm(grad(U'))
 
    tmp<volTensorField> tUPrimeUPrime(UPrime * UPrime);
    const volTensorField& UPrimeUPrime = tUPrimeUPrime(); //U'U'

    //Calculation Turbulent Stress Diffusion TSDF
    turbDiff  = -0.5 * fvc::div(UPrime * magSqr(UPrime));
    UUTSDF    = - UPrimeUPrime.component(tensor::XX) * UPrime;
    VVTSDF    = - UPrimeUPrime.component(tensor::YY) * UPrime;
    WWTSDF    = - UPrimeUPrime.component(tensor::ZZ) * UPrime;
    UVTSDF    = - UPrimeUPrime.component(tensor::XY) * UPrime;

    //Calculation Turbulent Stress Dissipation TSDP
    turbDiss      = -2 * nu_ * (SPrime && SPrime);
    UUTSDP        = -4 * nu_ * magSqr(SPrime & vector(1,0,0));
    VVTSDP        = -4 * nu_ * magSqr(SPrime & vector(0,1,0));
    WWTSDP        = -4 * nu_ * magSqr(SPrime & vector(0,0,1));
    tmp<volScalarField> ta = (gradUPrime & vector(0,1,0)) & (SPrime & vector(1,0,0));
    volScalarField a = ta();
    tmp<volScalarField> tb = (gradUPrime & vector(1,0,0)) & (SPrime & vector(0,1,0));
    volScalarField b = tb();
    UVTSDP   = -2 * nu_ * (a+b);

    turbDiss_homo = nu_ * (gradUPrime && gradUPrime);
    UUTSDP_homo   = -2 * nu_ * magSqr(gradUPrime & vector(1,0,0));
    VVTSDP_homo   = -2 * nu_ * magSqr(gradUPrime & vector(0,1,0));
    WWTSDP_homo   = -2 * nu_ * magSqr(gradUPrime & vector(0,0,1));
    UVTSDP_homo   = -2 * nu_ * ((gradUPrime & vector(1,0,0)) & (gradUPrime & vector(0,1,0)));

    //Calculation Pressure Velocity Gradient Correlation PVGC or pressure-strain correlation
    pressDiff = - 1.0 * (UPrime & gradpPrime);
    UUPVGC    = - 2.0 * (UPrime.component(vector::X) * gradpPrime.component(vector::X));
    VVPVGC    = - 2.0 * (UPrime.component(vector::Y) * gradpPrime.component(vector::Y));
    WWPVGC    = - 2.0 * (UPrime.component(vector::Z) * gradpPrime.component(vector::Z));
    UVPVGC    = - 1.0 * (UPrime.component(vector::X) * gradpPrime.component(vector::Y)
                            +  UPrime.component(vector::Y) * gradpPrime.component(vector::X));
    //Molecular/Viscous Diffusion MVD
    viscDiff = 2 * nu_ *  fvc::div(UPrime & SPrime);
    UUMVD    = 4 * nu_ *  (UPrime.component(vector::X) * (vector(1,0,0) & SPrime));
    VVMVD    = 4 * nu_ *  (UPrime.component(vector::Y) * (vector(0,1,0) & SPrime));
    WWMVD    = 4 * nu_ *  (UPrime.component(vector::Z) * (vector(0,0,1) & SPrime));
    UVMVD    = 2 * nu_ * ((UPrime.component(vector::X) * (vector(0,1,0) & SPrime))
                       +  (UPrime.component(vector::Y) * (vector(1,0,0) & SPrime)));

    viscDiff_homo = 0.5 * nu_ *  tr(UPrimeUPrime);
    UUMVD_homo    =       nu_ *  UPrimeUPrime.component(tensor::XX);
    VVMVD_homo    =       nu_ *  UPrimeUPrime.component(tensor::YY);
    WWMVD_homo    =       nu_ *  UPrimeUPrime.component(tensor::ZZ);
    UVMVD_homo    =       nu_ *  UPrimeUPrime.component(tensor::XY);

    //Instantaneous resolved tke	    
    kres_ = 0.5*(UPrime & UPrime);
 
    //Total tke = resolve + sgs
    ktot_ = kres_ + ksgs_;

    //Instantaneous resolved tke dissipation rate
    epres_ = - nu_ * gradUPrime && gradUPrime; //equivalent to turbDiss, have it here to remain consistency

    //Total tke dissipation rate = resolve + sgs
    eptot_ = mag(epres_ + epsgs_);

    //Instantaneous ratio of resolved to total (Resolved + SGS) tke
    LESResIndex = kres_/max(kSmall,ktot_); 

    Info << "ESTIMATED LESResIndex min, max, avg: " << min(LESResIndex).value()
					    << ", " << max(LESResIndex).value()
					    << ", " << LESResIndex.weightedAverage(mesh.V()).value()
					    << endl;

    //#include "write.H"
}

else
{
    Info << "Running pimpleDNS without budget!" << endl;
}
