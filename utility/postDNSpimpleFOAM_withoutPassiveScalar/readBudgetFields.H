    //readFields parts
    //Turbulent Stress Diffusion TSDF
    volScalarField turbDiffMean
    (
        IOobject
        (
            "turbDiffMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volVectorField UUTSDFMean
    (
        IOobject
        (
            "UUTSDFMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volVectorField VVTSDFMean
    (
        IOobject
        (
            "VVTSDFMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volVectorField WWTSDFMean
    (
        IOobject
        (
            "WWTSDFMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volVectorField UVTSDFMean
    (
        IOobject
        (
            "UVTSDFMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    //Turbulent Stress Dissipation TSDP

    volScalarField turbDissMean
    (
        IOobject
        (
            "turbDissMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField UUTSDPMean
    (
        IOobject
        (
            "UUTSDPMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField VVTSDPMean
    (
        IOobject
        (
            "VVTSDPMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField WWTSDPMean
    (
        IOobject
        (
            "WWTSDPMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField UVTSDPMean
    (
        IOobject
        (
            "UVTSDPMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField turbDiss_homoMean
    (
        IOobject
        (
            "turbDiss_homoMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField UUTSDP_homoMean
    (
        IOobject
        (
            "UUTSDP_homoMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField VVTSDP_homoMean
    (
        IOobject
        (
            "VVTSDP_homoMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField WWTSDP_homoMean
    (
        IOobject
        (
            "WWTSDP_homoMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField UVTSDP_homoMean
    (
        IOobject
        (
            "UVTSDP_homoMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    //Pressure Velocity Gradient Correlation PVGC or pressure-strain correlation

    volScalarField pressDiffMean
    (
        IOobject
        (
            "pressDiffMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField UUPVGCMean
    (
        IOobject
        (
            "UUPVGCMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField VVPVGCMean
    (
        IOobject
        (
            "VVPVGCMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField WWPVGCMean
    (
        IOobject
        (
            "WWPVGCMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField UVPVGCMean
    (
        IOobject
        (
            "UVPVGCMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    //Molecular/Viscous Diffusion MVD

    volScalarField viscDiffMean
    (
        IOobject
        (
            "viscDiffMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volVectorField UUMVDMean
    (
        IOobject
        (
            "UUMVDMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volVectorField VVMVDMean
    (
        IOobject
        (
            "VVMVDMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volVectorField WWMVDMean
    (
        IOobject
        (
            "WWMVDMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volVectorField UVMVDMean
    (
        IOobject
        (
            "UVMVDMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField viscDiff_homoMean
    (
        IOobject
        (
            "viscDiff_homoMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField UUMVD_homoMean
    (
        IOobject
        (
            "UUMVD_homoMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField VVMVD_homoMean
    (
        IOobject
        (
            "VVMVD_homoMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField WWMVD_homoMean
    (
        IOobject
        (
            "WWMVD_homoMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

    volScalarField UVMVD_homoMean
    (
        IOobject
        (
            "UVMVD_homoMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );


