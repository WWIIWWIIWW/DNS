    Info<< nl << "Reading transportProperties" << endl;

    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        )
    );
