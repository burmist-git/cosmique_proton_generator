simpath='/home/dpncguest/home2/work/POEMMA/geant4/cosmique_proton_generator/'

nEvents=1000000000
statMultF=20

screenName='cmg01'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator01 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator01 0 $nEvents $simpath/data/cosmique_proton_generator_01screen.root 1231410 $statMultF; sleep 1

screenName='cmg02'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator02 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator02 0 $nEvents $simpath/data/cosmique_proton_generator_02screen.root 2231220 $statMultF; sleep 1

screenName='cmg03'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator03 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator03 0 $nEvents $simpath/data/cosmique_proton_generator_03screen.root 3231230 $statMultF; sleep 1

screenName='cmg04'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator04 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator04 0 $nEvents $simpath/data/cosmique_proton_generator_04screen.root 4231240 $statMultF; sleep 1

screenName='cmg05'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator05 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator05 0 $nEvents $simpath/data/cosmique_proton_generator_05screen.root 5231250 $statMultF; sleep 1

screenName='cmg06'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator06 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator06 0 $nEvents $simpath/data/cosmique_proton_generator_06screen.root 6231260 $statMultF; sleep 1

screenName='cmg07'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator07 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator07 0 $nEvents $simpath/data/cosmique_proton_generator_07screen.root 7231270 $statMultF; sleep 1

screenName='cmg08'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator08 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator08 0 $nEvents $simpath/data/cosmique_proton_generator_08screen.root 8231280 $statMultF; sleep 1

screenName='cmg09'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator09 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator09 0 $nEvents $simpath/data/cosmique_proton_generator_09screen.root 9231290 $statMultF; sleep 1

screenName='cmg10'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator10 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator10 0 $nEvents $simpath/data/cosmique_proton_generator_10screen.root 1031210 $statMultF; sleep 1

screenName='cmg11'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator11 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator11 0 $nEvents $simpath/data/cosmique_proton_generator_11screen.root 1131211 $statMultF; sleep 1

screenName='cmg12'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator12 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator12 0 $nEvents $simpath/data/cosmique_proton_generator_12screen.root 1231212 $statMultF; sleep 1

screenName='cmg13'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator13 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator13 0 $nEvents $simpath/data/cosmique_proton_generator_13screen.root 1331213 $statMultF; sleep 1

screenName='cmg14'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator14 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator14 0 $nEvents $simpath/data/cosmique_proton_generator_14screen.root 1431214 $statMultF; sleep 1

screenName='cmg15'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator15 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator15 0 $nEvents $simpath/data/cosmique_proton_generator_15screen.root 1531215 $statMultF; sleep 1

screenName='cmg16'
cp $simpath/cosmique_proton_generator $simpath/cosmique_proton_generator16 
screen -S $screenName -L -d -m $simpath/cosmique_proton_generator.sh $simpath/cosmique_proton_generator16 0 $nEvents $simpath/data/cosmique_proton_generator_16screen.root 1631216 $statMultF; sleep 1
