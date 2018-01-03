working_dir=`pwd`
bindings_root=$working_dir/bindings/python-bindings-generator/

echo "Current working_dir: $working_dir"
echo "Bindings generator dir: $bindings_root"

#cd $bindings_root/src
#../build.sh
#cp -f ../target/engineSim.idl $working_dir
#cd $working_dir

python /home/pi/emsdk-portable/emscripten/1.37.1/tools/webidl_binder.py engineSim.idl glue
emcc ./libengineSim/libengineSim.a ./my_glue_wrapper.cpp -o ./libengineSim/engineSim.js -I /home/pi/rts/spring-104.0.1/rts --post-js ./glue.js -std=c++14 -msse
#emcc ./libengineSim/libengineSim. -o ./libengineSim/engineSim.js -I /home/pi/myrts/spring-104.0.1/rts --post-js ./glue.js -std=c++14 -msse
rm glue.js
rm glue.cpp
