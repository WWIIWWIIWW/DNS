    //collapsing part
    //Turbulent Stress Diffusion TSDF
    volScalarField tUUTSDF    = fvc::div(UUTSDFMean);
    volScalarField tVVTSDF    = fvc::div(VVTSDFMean);
    volScalarField tWWTSDF    = fvc::div(WWTSDFMean);
    volScalarField tUVTSDF    = fvc::div(UVTSDFMean);

    scalarField turbDiffValues
    (
        channelIndexing.collapse(turbDiffMean)
    );
    scalarField UUTSDFValues
    (
        channelIndexing.collapse(tUUTSDF)
    );
    scalarField VVTSDFValues
    (
        channelIndexing.collapse(tVVTSDF)
    );
    scalarField WWTSDFValues
    (
        channelIndexing.collapse(tWWTSDF)
    );
    scalarField UVTSDFValues
    (
        channelIndexing.collapse(tUVTSDF)
    );

    makeGraph(y, turbDiffValues, "Turb_diff_k+", path, gFormat);
    makeGraph(y, UUTSDFValues, "Turb_diff_uu+", path, gFormat);
    makeGraph(y, VVTSDFValues, "Turb_diff_vv+", path, gFormat);
    makeGraph(y, WWTSDFValues, "Turb_diff_ww+", path, gFormat);
    makeGraph(y, UVTSDFValues, "Turb_diff_uv+", path, gFormat);

    //Turbulent Stress Dissipation TSDP
    scalarField turbDissValues
    (
        channelIndexing.collapse(turbDissMean)
    );
    scalarField UUTSDPValues
    (
        channelIndexing.collapse(UUTSDPMean)
    );
    scalarField VVTSDPValues
    (
        channelIndexing.collapse(VVTSDPMean)
    );
    scalarField WWTSDPValues
    (
        channelIndexing.collapse(WWTSDPMean)
    );
    scalarField UVTSDPValues
    (
        channelIndexing.collapse(UVTSDPMean)
    );

    scalarField turbDiss_homoValues
    (
        channelIndexing.collapse(turbDiss_homoMean)
    );
    scalarField UUTSDP_homoValues
    (
        channelIndexing.collapse(UUTSDP_homoMean)
    );
    scalarField VVTSDP_homoValues
    (
        channelIndexing.collapse(VVTSDP_homoMean)
    );
    scalarField WWTSDP_homoValues
    (
        channelIndexing.collapse(WWTSDP_homoMean)
    );
    scalarField UVTSDP_homoValues
    (
        channelIndexing.collapse(UVTSDP_homoMean)
    );

    makeGraph(y, turbDissValues, "Diss_k+", path, gFormat);
    makeGraph(y, UUTSDPValues, "Diss_uu+", path, gFormat);
    makeGraph(y, VVTSDPValues, "Diss_vv+", path, gFormat);
    makeGraph(y, WWTSDPValues, "Diss_ww+", path, gFormat);
    makeGraph(y, UVTSDPValues, "Diss_uv+", path, gFormat);

    makeGraph(y, turbDiss_homoValues, "homo_Diss_k+", path, gFormat);
    makeGraph(y, UUTSDP_homoValues, "homo_Diss_uu+", path, gFormat);
    makeGraph(y, VVTSDP_homoValues, "homo_Diss_vv+", path, gFormat);
    makeGraph(y, WWTSDP_homoValues, "homo_Diss_ww+", path, gFormat);
    makeGraph(y, UVTSDP_homoValues, "homo_Diss_uv+", path, gFormat);

    //Pressure Velocity Gradient Correlation PVGC or pressure-strain correlation
    scalarField pressDiffValues
    (
        channelIndexing.collapse(pressDiffMean)
    );
    scalarField UUPVGCValues
    (
        channelIndexing.collapse(UUPVGCMean)
    );
    scalarField VVPVGCValues
    (
        channelIndexing.collapse(VVPVGCMean)
    );
    scalarField WWPVGCValues
    (
        channelIndexing.collapse(WWPVGCMean)
    );
    scalarField UVPVGCValues
    (
        channelIndexing.collapse(UVPVGCMean)
    );


    makeGraph(y, pressDiffValues, "vel_p_grad_k+", path, gFormat);
    makeGraph(y, UUPVGCValues, "vel_p_grad_uu+", path, gFormat);
    makeGraph(y, VVPVGCValues, "vel_p_grad_vv+", path, gFormat);
    makeGraph(y, WWPVGCValues, "vel_p_grad_ww+", path, gFormat);
    makeGraph(y, UVPVGCValues, "vel_p_grad_uv+", path, gFormat);

    // Molecular/Viscous Diffusion MVD
    volScalarField tUUMVD    = fvc::div(UUMVDMean);
    volScalarField tVVMVD    = fvc::div(VVMVDMean);
    volScalarField tWWMVD    = fvc::div(WWMVDMean);
    volScalarField tUVMVD    = fvc::div(UVMVDMean);

    volScalarField tviscDiff_homo = fvc::laplacian(viscDiff_homoMean);
    volScalarField tUUMVD_homo    = fvc::laplacian(UUMVD_homoMean);
    volScalarField tVVMVD_homo    = fvc::laplacian(VVMVD_homoMean);
    volScalarField tWWMVD_homo    = fvc::laplacian(WWMVD_homoMean);
    volScalarField tUVMVD_homo    = fvc::laplacian(UVMVD_homoMean);

    scalarField viscDiffValues
    (
        channelIndexing.collapse(viscDiffMean)
    );
    scalarField UUMVDValues
    (
        channelIndexing.collapse(tUUMVD)
    );
    scalarField VVMVDValues
    (
        channelIndexing.collapse(tVVMVD)
    );
    scalarField WWMVDValues
    (
        channelIndexing.collapse(tWWMVD)
    );
    scalarField UVMVDValues
    (
        channelIndexing.collapse(tUVMVD)
    );
    //homo
    scalarField viscDiff_homoValues
    (
        channelIndexing.collapse(tviscDiff_homo)
    );
    scalarField UUMVD_homoValues
    (
        channelIndexing.collapse(tUUMVD_homo)
    );
    scalarField VVMVD_homoValues
    (
        channelIndexing.collapse(tVVMVD_homo)
    );
    scalarField WWMVD_homoValues
    (
        channelIndexing.collapse(tWWMVD_homo)
    );
    scalarField UVMVD_homoValues
    (
        channelIndexing.collapse(tUVMVD_homo)
    );

    makeGraph(y, viscDiffValues, "Mole_diff_k+", path, gFormat);
    makeGraph(y, UUMVDValues, "Mole_diff_uu+", path, gFormat);
    makeGraph(y, VVMVDValues, "Mole_diff_vv+", path, gFormat);
    makeGraph(y, WWMVDValues, "Mole_diff_ww+", path, gFormat);
    makeGraph(y, UVMVDValues, "Mole_diff_uv+", path, gFormat);

    makeGraph(y, viscDiff_homoValues, "homo_Mole_diff_k+", path, gFormat);
    makeGraph(y, UUMVD_homoValues, "homo_Mole_diff_uu+", path, gFormat);
    makeGraph(y, VVMVD_homoValues, "homo_Mole_diff_vv+", path, gFormat);
    makeGraph(y, WWMVD_homoValues, "homo_Mole_diff_ww+", path, gFormat);
    makeGraph(y, UVMVD_homoValues, "homo_Mole_diff_yv+", path, gFormat);

    // Turbulent stress production TSP
    volScalarField turbProd = - UPrime2Mean && fvc::grad(UMean);
    volScalarField UUTSP    = - 2 * fvc::grad(UMean.component(vector::X)) &  (vector(1,0,0) & UPrime2Mean);
    volScalarField VVTSP    = - 2 * fvc::grad(UMean.component(vector::Y)) &  (vector(0,1,0) & UPrime2Mean);
    volScalarField WWTSP    = - 2 * fvc::grad(UMean.component(vector::Z)) &  (vector(0,0,1) & UPrime2Mean);
    volScalarField UVTSP    = -   ((fvc::grad(UMean.component(vector::Y)) &  (vector(1,0,0) & UPrime2Mean))
                              +    (fvc::grad(UMean.component(vector::X)) &  (vector(0,1,0) & UPrime2Mean)));

    scalarField turbProdValues
    (
        channelIndexing.collapse(turbProd)
    );
    scalarField UUTSPValues
    (
        channelIndexing.collapse(UUTSP)
    );
    scalarField VVTSPValues
    (
        channelIndexing.collapse(VVTSP)
    );
    scalarField WWTSPValues
    (
        channelIndexing.collapse(WWTSP)
    );
    scalarField UVTSPValues
    (
        channelIndexing.collapse(UVTSP)
    );

    makeGraph(y, turbProdValues, "Prod_k+", path, gFormat);
    makeGraph(y, UUTSPValues, "Prod_uu+", path, gFormat);
    makeGraph(y, VVTSPValues, "Prod_vv+", path, gFormat);
    makeGraph(y, WWTSPValues, "Prod_ww+", path, gFormat);
    makeGraph(y, UVTSPValues, "Prod_uv+", path, gFormat);

