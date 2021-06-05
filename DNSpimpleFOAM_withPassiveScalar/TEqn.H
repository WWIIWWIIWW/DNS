{ 
    fvScalarMatrix TEqn
    (
        fvm::ddt(T)
      + fvm::div(phi, T)
      - fvm::laplacian(DT, T)
     ==
        fvOptions(T)
      - ((heatFlux / Uavg) * (U & flowDirection)) //heat flux = W/m2 /(m * Kg/m3 * J/(Kg.K)) = K/s
      //- heatFlux/(delta*thermo.rho() * thermo.Cp * Uavg) * (U & flowDirection) //compressible formulation
    );

    TEqn.relax();
    fvOptions.constrain(TEqn);
    TEqn.solve();
    fvOptions.correct(T);
}
