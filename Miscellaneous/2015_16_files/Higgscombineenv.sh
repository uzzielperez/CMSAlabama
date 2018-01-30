#!/usr/bin/env bash

# build CMSSW env
source​/cvmfs/cms.cern.ch/cmsset_default.sh 
export​SCRAM_ARCH=s​lc6_amd64_gcc481 
cmsrel CMSSW_7_1_5 
cd​CMSSW_7_1_5/src
cmsenv


# retrieve HiggsCombine
git clone https://github.com/cms­analysis/HiggsAnalysis­CombinedLimit.git 
${CMSSW_BASE}/​src/HiggsAnalysis/CombinedLimit 
cd​HiggsAnalysis/CombinedLimit
git fetch origin
git checkout v5.0.2 
scramv1 b clean 
scramv1 b -j4

# get the macros
cd​$​{CMSSW_BASE}/​src
mkdir​macro
cd​macro
cp /nas2/cmsdas/dasuser18/MonoPhotonDM/CMSSW_7_1_5/src/monoPhoCard_template.txt . 
cp /nas2/cmsdas/dasuser18/MonoPhotonDM/CMSSW_7_1_5/src/limits/limits.C .
cp /nas2/cmsdas/dasuser18/MonoPhotonDM/CMSSW_7_1_5/src/limits/run.sh .

