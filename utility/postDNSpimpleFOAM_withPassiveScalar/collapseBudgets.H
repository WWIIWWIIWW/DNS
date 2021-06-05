    //collapsing part
    scalarField TMeanvalues
    (
        channelIndexing.collapse(TMean)
    );
    volScalarField ut(UPrimeTPrimeMean.component(vector::X));
    volScalarField vt(UPrimeTPrimeMean.component(vector::Y));
    volScalarField wt(UPrimeTPrimeMean.component(vector::Z));

    scalarField utValues(channelIndexing.collapse(ut));
    scalarField vtValues(channelIndexing.collapse(vt, true));
    scalarField wtValues(channelIndexing.collapse(wt));
    scalarField ttValues(channelIndexing.collapse(TPrime2Mean));
    scalarField trmsValues(sqrt(mag(ttValues)));

    makeGraph(y, TMeanvalues, "T+", path, gFormat);
    makeGraph(y, utValues, "ut+", path, gFormat);
    makeGraph(y, vtValues, "vt+", path, gFormat);
    makeGraph(y, wtValues, "wt+", path, gFormat);
    makeGraph(y, trmsValues, "trms+", path, gFormat);

    //Turbulent Stress Diffusion TSDF
    volScalarField tUUTSDF    = fvc::div(UUTSDFMean);
    volScalarField tVVTSDF    = fvc::div(VVTSDFMean);
    volScalarField tWWTSDF    = fvc::div(WWTSDFMean);
    volScalarField tUVTSDF    = fvc::div(UVTSDFMean);

    volScalarField tUTTSDF     = fvc::div(UTTSDFMean);
    volScalarField tVTTSDF     = fvc::div(VTTSDFMean);
    volScalarField tWTTSDF     = fvc::div(WTTSDFMean);

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
        channelIndexing.collapse(tUVTSDF, true)
    );

    scalarField turbDiff_TValues
    (
        channelIndexing.collapse(turbDiff_TMean)
    );
    scalarField UTTSDFValues
    (
        channelIndexing.collapse(tUTTSDF)
    );
    scalarField VTTSDFValues
    (
        channelIndexing.collapse(tVTTSDF, true)
    );
    scalarField WTTSDFValues
    (
        channelIndexing.collapse(tWTTSDF)
    );
    makeGraph(y, turbDiffValues, "Turb_diff_k+", path, gFormat);
    makeGraph(y, UUTSDFValues, "Turb_diff_uu+", path, gFormat);
    makeGraph(y, VVTSDFValues, "Turb_diff_vv+", path, gFormat);
    makeGraph(y, WWTSDFValues, "Turb_diff_ww+", path, gFormat);
    makeGraph(y, UVTSDFValues, "Turb_diff_uv+", path, gFormat);

    makeGraph(y, turbDiff_TValues, "Turb_diff_kt+", path, gFormat);
    makeGraph(y, UTTSDFValues, "Turb_diff_ut+", path, gFormat);
    makeGraph(y, VTTSDFValues, "Turb_diff_vt+", path, gFormat);
    makeGraph(y, WTTSDFValues, "Turb_diff_wt+", path, gFormat);
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
        channelIndexing.collapse(UVTSDPMean, true)
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
        channelIndexing.collapse(UVTSDP_homoMean, true)
    );

    scalarField turbDiss_T_homoValues
    (
        channelIndexing.collapse(turbDiss_T_homoMean)
    );
    scalarField UTTSDP_homoValues
    (
        channelIndexing.collapse(UTTSDP_homoMean)
    );
    scalarField VTTSDP_homoValues
    (
        channelIndexing.collapse(VTTSDP_homoMean, true)
    );
    scalarField WTTSDP_homoValues
    (
        channelIndexing.collapse(WTTSDP_homoMean)
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

    makeGraph(y, turbDiss_T_homoValues, "homo_Diss_kt+", path, gFormat);
    makeGraph(y, UTTSDP_homoValues, "homo_Diss_ut+", path, gFormat);
    makeGraph(y, VTTSDP_homoValues, "homo_Diss_vt+", path, gFormat);
    makeGraph(y, WTTSDP_homoValues, "homo_Diss_wt+", path, gFormat);
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
        channelIndexing.collapse(UVPVGCMean, true)
    );

    scalarField UTPVGCValues
    (
        channelIndexing.collapse(UTPVGCMean)
    );
    scalarField VTPVGCValues
    (
        channelIndexing.collapse(VTPVGCMean, true)
    );
    scalarField WTPVGCValues
    (
        channelIndexing.collapse(WTPVGCMean)
    );

    makeGraph(y, pressDiffValues, "vel_p_grad_k+", path, gFormat);
    makeGraph(y, UUPVGCValues, "vel_p_grad_uu+", path, gFormat);
    makeGraph(y, VVPVGCValues, "vel_p_grad_vv+", path, gFormat);
    makeGraph(y, WWPVGCValues, "vel_p_grad_ww+", path, gFormat);
    makeGraph(y, UVPVGCValues, "vel_p_grad_uv+", path, gFormat);

    makeGraph(y, UTPVGCValues, "vel_p_grad_ut+", path, gFormat);
    makeGraph(y, VTPVGCValues, "vel_p_grad_vt+", path, gFormat);
    makeGraph(y, WTPVGCValues, "vel_p_grad_wt+", path, gFormat);
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

    volScalarField tviscDiff_T_homo = fvc::laplacian(viscDiff_T_homoMean);
    volScalarField tUTMVD_homo    = fvc::div(UTMVD_homoMean);
    volScalarField tVTMVD_homo    = fvc::div(VTMVD_homoMean);
    volScalarField tWTMVD_homo    = fvc::div(WTMVD_homoMean);

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
        channelIndexing.collapse(tUVMVD, true)
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
        channelIndexing.collapse(tUVMVD_homo, true)
    );

    //T_homo
    scalarField viscDiff_T_homoValues
    (
        channelIndexing.collapse(tviscDiff_T_homo)
    );
    scalarField UTMVD_homoValues
    (
        channelIndexing.collapse(tUTMVD_homo)
    );
    scalarField VTMVD_homoValues
    (
        channelIndexing.collapse(tVTMVD_homo, true)
    );
    scalarField WTMVD_homoValues
    (
        channelIndexing.collapse(tWTMVD_homo)
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
    makeGraph(y, UVMVD_homoValues, "homo_Mole_diff_uv+", path, gFormat);

    makeGraph(y, viscDiff_T_homoValues, "homo_Mole_diff_kt+", path, gFormat);
    makeGraph(y, UTMVD_homoValues, "homo_Mole_diff_ut+", path, gFormat);
    makeGraph(y, VTMVD_homoValues, "homo_Mole_diff_vt+", path, gFormat);
    makeGraph(y, WTMVD_homoValues, "homo_Mole_diff_wt+", path, gFormat);
    // Turbulent stress production TSP
    volScalarField turbProd = - UPrime2Mean && fvc::grad(UMean);
    volScalarField UUTSP    = - 2 * fvc::grad(UMean.component(vector::X)) &  (vector(1,0,0) & UPrime2Mean);
    volScalarField VVTSP    = - 2 * fvc::grad(UMean.component(vector::Y)) &  (vector(0,1,0) & UPrime2Mean);
    volScalarField WWTSP    = - 2 * fvc::grad(UMean.component(vector::Z)) &  (vector(0,0,1) & UPrime2Mean);
    volScalarField UVTSP    = -   ((fvc::grad(UMean.component(vector::Y)) &  (vector(1,0,0) & UPrime2Mean))
                              +    (fvc::grad(UMean.component(vector::X)) &  (vector(0,1,0) & UPrime2Mean)));
    
    volScalarField turbProd_T = - UPrimeTPrimeMean & fvc::grad(TMean);
    volScalarField UTTSP      = - (UPrimeTPrimeMean & fvc::grad(UMean.component(vector::X)))
                                - ((vector(1,0,0) & UPrime2Mean) & fvc::grad(TMean));
    volScalarField VTTSP      = - (UPrimeTPrimeMean & fvc::grad(UMean.component(vector::Y)))
                                - ((vector(0,1,0) & UPrime2Mean) & fvc::grad(TMean));
    volScalarField WTTSP      = - (UPrimeTPrimeMean & fvc::grad(UMean.component(vector::X)))
                                - ((vector(0,0,1) & UPrime2Mean) & fvc::grad(TMean));


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
        channelIndexing.collapse(UVTSP, true)
    );

    scalarField turbProd_TValues
    (
        channelIndexing.collapse(turbProd_T)
    );
    scalarField UTTSPValues
    (
        channelIndexing.collapse(UTTSP)
    );
    scalarField VTTSPValues
    (
        channelIndexing.collapse(VTTSP, true)
    );
    scalarField WTTSPValues
    (
        channelIndexing.collapse(WTTSP)
    );

    makeGraph(y, turbProdValues, "Prod_k+", path, gFormat);
    makeGraph(y, UUTSPValues, "Prod_uu+", path, gFormat);
    makeGraph(y, VVTSPValues, "Prod_vv+", path, gFormat);
    makeGraph(y, WWTSPValues, "Prod_ww+", path, gFormat);
    makeGraph(y, UVTSPValues, "Prod_uv+", path, gFormat);

    makeGraph(y, turbProd_TValues, "Prod_kt+", path, gFormat);
    makeGraph(y, UTTSPValues, "Prod_ut+", path, gFormat);
    makeGraph(y, VTTSPValues, "Prod_vt+", path, gFormat);
    makeGraph(y, WTTSPValues, "Prod_wt+", path, gFormat);

