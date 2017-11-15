python /home/pi/emsdk-portable/emscripten/1.37.1/tools/webidl_binder.py ./bindings/engineSim.idl glue
emcc ./libengineSim/libengineSim.a ./my_glue_wrapper.cpp -o ./libengineSim/engineSim.js -I /home/pi/myrts/spring-104.0.1/rts --post-js ./glue.js -std=c++14 -msse
rm glue.js
rm glue.cpp