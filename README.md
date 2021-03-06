# DNS

DNS solvers and utilities compatible with OF6 with incompressible budget terms

Example: (testing cases will be released once ready)

<img src="https://github.com/WWIIWWIIWW/DNS/blob/main/pic/example_Channel.PNG" width="500">

## Author
[Kai Zhang, KTH, Royal Institute of Technology, Sweden](https://scholar.google.com/citations?user=lfUyemMAAAAJ&hl=en) - Google Scholar

Email: kaizhang@kth.se; kai.zhang.1@city.ac.uk

paper doi: https://doi.org/10.1016/j.ijheatmasstransfer.2021.121946

## Solver (correct me if any equations are wrong!)
DNSpimpleFOAM_withPassiveScalar: DNS solver based on pimpleFoam with added passive scalar transportation.

DNSpimpleFOAM_withoutPassiveScalar: DNS solver based on pimpleFoam

## utility (based on postChannel utility, assuming periodic in the x and z )
postDNSpimpleFOAM_withPassiveScalar: DNS postprocessing tool for solver DNSpimpleFOAM_withPassiveScalar

postDNSpimpleFOAM_withoutPassiveScalar: DNS postprocessing tool for solver DNSpimpleFOAM_withoutPassiveScalar 

## Instructions:
Transport equations:

<img src="https://github.com/WWIIWWIIWW/DNS/blob/main/pic/transportEq.PNG" width="500">

Solver: budgets.H:

<img src="https://github.com/WWIIWWIIWW/DNS/blob/main/pic/budgets1.PNG" width="500">

<img src="https://github.com/WWIIWWIIWW/DNS/blob/main/pic/budgets2.PNG" width="500">

## Reference
Andrea De Santis's pimpleTKEBudgetFoam@https://github.com/AndreaDesan

Kawamura, H., Abe, H. and Shingai, K., 2000. DNS of turbulence and heat transport in a channel flow with different Reynolds and Prandtl numbers and boundary conditions. Turbulence, Heat and Mass Transfer, 3, pp.15-32.
