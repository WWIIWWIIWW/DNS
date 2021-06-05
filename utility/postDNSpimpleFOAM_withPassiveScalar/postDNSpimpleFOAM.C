/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application:
    postDNSpimpleFOAM

Author:
Kai Zhang @ KTH Royal Institute of Technology, Sweden

Contact:
Kai.Zhang.1@city.ac.uk
kaizhang@kth.se

Description:
postChannel reformulated to post-processe budgets obtained from 'DNSpimpleFOAM solver with passive scalar' (OF6) @ https://github.com/WWIIWWIIWW

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "channelIndex.H"
#include "makeGraph.H"

#include "OSspecific.H"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    argList::noParallel();
    timeSelector::addOptions();

    #include "setRootCase.H"
    #include "createTime.H"

    // Get times list
    instantList timeDirs = timeSelector::select0(runTime, args);

    #include "createMesh.H"
    #include "readTransportProperties.H"

    const word& gFormat = runTime.graphFormat();

    // Setup channel indexing for averaging over channel down to a line

    IOdictionary channelDict
    (
        IOobject
        (
            "postChannelDict",
            mesh.time().constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );
    channelIndex channelIndexing(mesh, channelDict);


    // For each time step read all fields
    forAll(timeDirs, timeI)
    {
        runTime.setTime(timeDirs[timeI], timeI);
        Info<< "Collapsing fields for time " << runTime.timeName() << endl;

        #include "readFields.H"
        #include "collapseBudgets.H"

        // Average fields over channel down to a line
        #include "collapse.H"
        #include "readBudgetFields.H"
    }

    Info<< "\nEnd\n" << endl;

    return 0;
}


// ************************************************************************* //
