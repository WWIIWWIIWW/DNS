// Solve the Momentum equation

MRF.correctBoundaryVelocity(U);
Info << fvOpt << endl;
tmp<fvVectorMatrix> tUEqn
(
    fvm::ddt(U) + fvm::div(phi, U)
  + MRF.DDt(U)
  + turbulence->divDevReff(U)
 ==    
    fvOptions(U)
  + (
        fvOpt == "no"
      ? flowDirection * gradP
      : 0 * flowDirection * gradP
    )
);
fvVectorMatrix& UEqn = tUEqn.ref();

UEqn.relax();

fvOptions.constrain(UEqn);

if (pimple.momentumPredictor())
{
    solve(UEqn == -fvc::grad(p));

    fvOptions.correct(U);
}
