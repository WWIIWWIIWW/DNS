# DNS
DNS solvers and utilities compatible with OF6 with incompressible budget terms
## Solver
DNSpimpleFOAM_withPassiveScalar: DNS solver based on pimpleFoam with added passive scalar transportation.

DNSpimpleFOAM_withoutPassiveScalar: DNS solver based on pimpleFoam

## utility (based on postChannel utility, assuming periodic in the x and z )
postDNSpimpleFOAM_withPassiveScalar: DNS postprocessing tool for solver DNSpimpleFOAM_withPassiveScalar

postDNSpimpleFOAM_withoutPassiveScalar: DNS postprocessing tool for solver DNSpimpleFOAM_withoutPassiveScalar 

## Instructions:
Solver: budgets.H:

## Reference
Andrea De Santis's pimpleTKEBudgetFoam@https://github.com/AndreaDesan

Kawamura, H., Abe, H. and Shingai, K., 2000. DNS of turbulence and heat transport in a channel flow with different Reynolds and Prandtl numbers and boundary conditions. Turbulence, Heat and Mass Transfer, 3, pp.15-32.
