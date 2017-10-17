// TODO: Substitue CGlobalRNG with your actual class name
uint32_t CGlobalRNG::res_type(){}
uint64_t CGlobalRNG::val_type(){}
PCG32::res_type CGlobalRNG::min_res(){}
PCG32::res_type CGlobalRNG::max_res(){}
PCG32::val_type CGlobalRNG::def_val(){}
PCG32::val_type CGlobalRNG::def_seq(){}
PCG32::val_type CGlobalRNG::val(){}
PCG32::val_type CGlobalRNG::seq(){}
RNG::val_type CGlobalRNG::rng_val_type(){}
RNG::res_type CGlobalRNG::rng_res_type(){}
RNG CGlobalRNG::gen(){}
rng_val_type CGlobalRNG::initSeed(){}
rng_val_type CGlobalRNG::lastSeed(){}
CGlobalRNG<(PCG32,true)> CGlobalRNG::CGlobalSyncedRNG(){}
CGlobalRNG<(PCG32,false)> CGlobalRNG::CGlobalUnsyncedRNG(){}
