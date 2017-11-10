#include <emscripten/bind.h>
#include "${include_file}"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(${module_name})
{
% for c in classes:
    class_<${c.name}>("${c.name}")
    % for f in c.functions:
        % if not "hidden" in f.annotations:
        .function("${f.name}", &${c.name}::${f.name})
        % endif
    % endfor
    ;
% endfor
}
