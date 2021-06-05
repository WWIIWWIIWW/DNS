Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

Info<< "Reading field T\n" << endl;
volScalarField T
(
    IOobject
    (
        "T",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Creating field UT\n" << endl;
volVectorField UT
(
    IOobject
    (
        "UT",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    U * T
);

#include "createPhi.H"

label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, pimple.dict(), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());

Info<< "Reading diffusivity DT\n" << endl;

dimensionedScalar DT
(
    transportProperties.lookup("DT")
);

dimensionedScalar heatFlux("heatFlux", dimTemperature/dimTime, transportProperties.lookupOrDefault<scalar>("heatFlux", 0.0));

singlePhaseTransportModel laminarTransport(U, phi);

autoPtr<incompressible::turbulenceModel> turbulence
(
    incompressible::turbulenceModel::New(U, phi, laminarTransport)
);

#include "createMRF.H"
#include "createFvOptions.H"

dimensionedScalar gradP(laminarTransport.lookup("gradP"));

vector flowDirection(1,0,0);

const dictionary& fvOptDic = fvOptions.subDict("gradP");

const word fvOpt(fvOptDic.lookup("active"));
if (fvOpt == "no")
{
Info << "fvOption is off, DNS with assigned u_tau & gradP.\n" << endl;

Info<< "gradp = " << flowDirection*gradP << "\n" << endl; 
}
else
{
Info << "fvOption is on, DNS with Ubar defined in fvOptions.\n" << endl;
}
scalar volTot = gSum(mesh.V());
dimensionedScalar Uavg("Uavg", dimVelocity, gSum((U & flowDirection) * mesh.V())/volTot);
dimensionedScalar one("one", dimVelocity, 1.0);
