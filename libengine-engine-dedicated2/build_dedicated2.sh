working_dir=$(realpath .)
source_dir=/home/pi/rts/spring-104.0.1/rts
bindings_root=$working_dir/../bindings/python-bindings-generator/

echo "Current working_dir: $working_dir"
echo "Bindings generator dir: $bindings_root"

cd $bindings_root/src
../build.sh
cp -f ../target/engineSim.idl $working_dir
cp -f ../target/my_glue_wrapper.cpp $working_dir
cd $working_dir

python /home/pi/emsdk-portable/emscripten/1.37.1/tools/webidl_binder.py engineSim.idl glue
emcc $working_dir/libspring-dedicated2.a ./my_glue_wrapper.cpp -o $working_dir/index.html -I $source_dir --post-js ./glue.js -std=c++14 -msse --emit-symbol-map --tracing
mv index.js index.js.old
cat index.js.old | sed 's/abort(-1)/\/\/abort(-1)/' > index.js
rm index.js.old
#rm glue.js
#rm glue.cpp
