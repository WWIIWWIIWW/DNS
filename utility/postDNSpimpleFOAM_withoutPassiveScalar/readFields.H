    IOobject UMeanHeader
    (
        "UMean",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ
    );

    if (!UMeanHeader.typeHeaderOk<volVectorField>(true))
    {
        Info<< "    No UMean field" << endl;
        continue;
    }

    volVectorField UMean
    (
        UMeanHeader,
        mesh
    );

    volSymmTensorField UPrime2Mean
    (
        IOobject
        (
            "UPrime2Mean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );
    volScalarField Rxx(UPrime2Mean.component(symmTensor::XX));
    volScalarField Ryy(UPrime2Mean.component(symmTensor::YY));
    volScalarField Rzz(UPrime2Mean.component(symmTensor::ZZ));
    volScalarField Rxy(UPrime2Mean.component(symmTensor::XY));

    volScalarField pPrime2Mean
    (
        IOobject
        (
            "pPrime2Mean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

