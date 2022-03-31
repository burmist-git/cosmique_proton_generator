simpath='/home/dpncguest/home2/work/POEMMA/geant4/cosmique_proton_generator/'

nEvents=1000000
statMultF=5

screenName='cmg01'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generatortest 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generatortest 0 $nEvents $simpath/data/cosmique_proton_generator_01screen_test.root 1231410 $statMultF; sleep 1
