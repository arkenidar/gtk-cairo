# source install--repeated-dll-setup.bash

wine cairo2d.exe &> wine-output.txt
python extract-dlls.py > script-out.bash
bash script-out.bash
