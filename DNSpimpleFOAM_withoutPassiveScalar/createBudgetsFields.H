//Extra decaration
volScalarField kres_
(
    IOobject
    (
        "kres_",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("kres_", dimVelocity*dimVelocity, 0.0)
);

volScalarField ksgs_
(
    IOobject
    (
        "ksgs_",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("ksgs_", dimVelocity*dimVelocity, 0.0)
);

volScalarField ktot_
(
    IOobject
    (
        "ktot_",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("ktot_", dimVelocity*dimVelocity, 0.0)
);

volScalarField epres_
(
    IOobject
    (
        "epres_",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("epres_", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField epsgs_
(
    IOobject
    (
        "epsgs_",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("epsgs_", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField eptot_
(
    IOobject
    (
        "eptot_",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("eptot_", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField nu_
(
    IOobject
    (
        "nu_",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    turbulence->nu()
);

volScalarField LESResIndex
(
    IOobject
    (
        "LESResIndex",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("LESResIndex", dimless, 0.0)
);
//Turbulent Stress Diffusion TSDF
volScalarField turbDiff
(
    IOobject
    (
        "turbDiff",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("turbDiff", dimVelocity*dimVelocity/dimTime, 0.0)
);

volVectorField UUTSDF
(
    IOobject
    (
        "UUTSDF",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedVector("UUTSDF", dimVelocity*dimVelocity*dimVelocity, vector(0, 0, 0))
);

volVectorField VVTSDF
(
    IOobject
    (
        "VVTSDF",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedVector("VVTSDF", dimVelocity*dimVelocity*dimVelocity, vector(0, 0, 0))
);

volVectorField WWTSDF
(
    IOobject
    (
        "WWTSDF",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedVector("WWTSDF", dimVelocity*dimVelocity*dimVelocity, vector(0, 0, 0))
);

volVectorField UVTSDF
(
    IOobject
    (
        "UVTSDF",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedVector("UVTSDF", dimVelocity*dimVelocity*dimVelocity, vector(0, 0, 0))
);

//Turbulent Stress Dissipation TSDP
volScalarField turbDiss
(
    IOobject
    (
        "turbDiss",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("turbDiss", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField UUTSDP
(
    IOobject
    (
        "UUTSDP",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("UUTSDP", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField VVTSDP
(
    IOobject
    (
        "VVTSDP",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("VVTSDP", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField WWTSDP
(
    IOobject
    (
        "WWTSDP",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("WWTSDP", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField UVTSDP
(
    IOobject
    (
        "UVTSDP",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("UVTSDP", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField turbDiss_homo
(
    IOobject
    (
        "turbDiss_homo",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("turbDiss_homo", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField UUTSDP_homo
(
    IOobject
    (
        "UUTSDP_homo",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("UUTSDP_homo", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField VVTSDP_homo
(
    IOobject
    (
        "VVTSDP_homo",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("VVTSDP_homo", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField WWTSDP_homo
(
    IOobject
    (
        "WWTSDP_homo",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("WWTSDP_homo", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField UVTSDP_homo
(
    IOobject
    (
        "UVTSDP_homo",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("UVTSDP_homo", dimVelocity*dimVelocity/dimTime, 0.0)
);

//Pressure Velocity Gradient Correlation PVGC or pressure-strain correlation
volScalarField pressDiff
(
    IOobject
    (
        "pressDiff",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("pressDiff", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField UUPVGC
(
    IOobject
    (
        "UUPVGC",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("UUPVGC", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField VVPVGC
(
    IOobject
    (
        "VVPVGC",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("VVPVGC", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField WWPVGC
(
    IOobject
    (
        "WWPVGC",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("WWPVGC", dimVelocity*dimVelocity/dimTime, 0.0)
);

volScalarField UVPVGC
(
    IOobject
    (
        "UVPVGC",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("UVPVGC", dimVelocity*dimVelocity/dimTime, 0.0)
);

//Molecular/Viscous Diffusion MVD
volScalarField viscDiff
(
    IOobject
    (
        "viscDiff",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("viscDiff", dimVelocity*dimVelocity/dimTime, 0.0)
);

volVectorField UUMVD
(
    IOobject
    (
        "UUMVD",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedVector("UUMVD", dimVelocity*dimVelocity*dimVelocity, vector(0, 0, 0))
);

volVectorField VVMVD
(
    IOobject
    (
        "VVMVD",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedVector("VVMVD", dimVelocity*dimVelocity*dimVelocity, vector(0, 0, 0))
);

volVectorField WWMVD
(
    IOobject
    (
        "WWMVD",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedVector("WWMVD", dimVelocity*dimVelocity*dimVelocity, vector(0, 0, 0))
);

volVectorField UVMVD
(
    IOobject
    (
        "UVMVD",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedVector("UVMVD", dimVelocity*dimVelocity*dimVelocity, vector(0, 0, 0))
);

volScalarField viscDiff_homo
(
    IOobject
    (
        "viscDiff_homo",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("viscDiff_homo", dimViscosity*dimViscosity/dimTime, 0.0)
);

volScalarField UUMVD_homo
(
    IOobject
    (
        "UUMVD_homo",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("UUMVD_homo", dimViscosity*dimViscosity/dimTime, 0.0)
);

volScalarField VVMVD_homo
(
    IOobject
    (
        "VVMVD_homo",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("VVMVD_homo", dimViscosity*dimViscosity/dimTime, 0.0)
);

volScalarField WWMVD_homo
(
    IOobject
    (
        "WWMVD_homo",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("WWMVD_homo", dimViscosity*dimViscosity/dimTime, 0.0)
);

volScalarField UVMVD_homo
(
    IOobject
    (
        "UVMVD_homo",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("UVMVD_homo", dimViscosity*dimViscosity/dimTime, 0.0)
);


const volScalarField kSmall
(
    IOobject
    (
        "kSmall",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("kSmall", dimVelocity*dimVelocity, SMALL)
);

