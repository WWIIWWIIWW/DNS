    fileName path(UMean.rootPath()/UMean.caseName()/"graphs"/UMean.instance());
    mkDir(path);

    scalarField UMeanXvalues
    (
        channelIndexing.collapse(UMean.component(vector::X)())
    );

    scalarField UMeanYvalues
    (
        channelIndexing.collapse(UMean.component(vector::Y)())
    );

    scalarField UMeanZvalues
    (
        channelIndexing.collapse(UMean.component(vector::Z)())
    );

    scalarField RxxValues(channelIndexing.collapse(Rxx));
    scalarField RyyValues(channelIndexing.collapse(Ryy));
    scalarField RzzValues(channelIndexing.collapse(Rzz));
    scalarField RxyValues(channelIndexing.collapse(Rxy, true));

    scalarField pPrime2MeanValues(channelIndexing.collapse(pPrime2Mean));

    scalarField urmsValues(sqrt(mag(RxxValues)));
    scalarField vrmsValues(sqrt(mag(RyyValues)));
    scalarField wrmsValues(sqrt(mag(RzzValues)));
    scalarField uuValues((mag(RxxValues)));
    scalarField vvValues((mag(RyyValues)));
    scalarField wwValues((mag(RzzValues)));

    scalarField kValues
    (
        0.5*(sqr(urmsValues) + sqr(vrmsValues) + sqr(wrmsValues))
    );

    const scalarField& y = channelIndexing.y();

    makeGraph(y, UMeanXvalues, "U+", path, gFormat);
    makeGraph(y, uuValues, "uu+", path, gFormat);
    makeGraph(y, vvValues, "vv+", path, gFormat);
    makeGraph(y, wwValues, "ww+", path, gFormat);
    makeGraph(y, RxyValues, "uv+", path, gFormat);
    makeGraph(y, kValues, "k", path, gFormat);

    makeGraph(y, pPrime2MeanValues, "pPrime2Mean", path, gFormat);

