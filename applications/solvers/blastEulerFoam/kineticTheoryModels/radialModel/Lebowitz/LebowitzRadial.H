/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2018 OpenFOAM Foundation
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

Class
    Foam::kineticTheoryModels::radialModels::Lebowitz

Description

    Reference:
    \verbatim
        Lebowitz, J. L. (1964).
        "Exact Solution of Generalized Percus-Yevick Equation for a Mixture of
        Hard Spheres",
        Physical Review 133(I4), A895-A899
    \endverbatim

SourceFiles
    LebowitzRadial.C

\*---------------------------------------------------------------------------*/

#ifndef Lebowitz_H
#define Lebowitz_H

#include "radialModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace kineticTheoryModels
{
namespace radialModels
{

/*---------------------------------------------------------------------------*\
                           Class Lebowitz Declaration
\*---------------------------------------------------------------------------*/

class Lebowitz
:
    public radialModel
{
    // Private data

        dimensionedScalar residualAlpha_;

public:

    //- Runtime type information
    TypeName("Lebowitz");


    // Constructors

        //- Construct from components
        Lebowitz
        (
            const dictionary& dict,
            const kineticTheorySystem& kt
        );


    //- Destructor
    virtual ~Lebowitz();


    // Member Functions

        virtual tmp<volScalarField> gs0
        (
            const phaseModel& phase1,
            const phaseModel& phase2
        ) const;

        virtual tmp<volScalarField> gs0prime
        (
            const phaseModel& phase1,
            const phaseModel& phase2
        ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace radialModels
} // End namespace kineticTheoryModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
