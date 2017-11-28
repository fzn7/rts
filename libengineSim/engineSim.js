// The Module object: Our interface to the outside world. We import
// and export values on it, and do the work to get that through
// closure compiler if necessary. There are various ways Module can be used:
// 1. Not defined. We create it here
// 2. A function parameter, function(Module) { ..generated code.. }
// 3. pre-run appended it, var Module = {}; ..generated code..
// 4. External script tag defines var Module.
// We need to do an eval in order to handle the closure compiler
// case, where this code here is minified but Module was defined
// elsewhere (e.g. case 4 above). We also need to check if Module
// already exists (e.g. case 3 above).
// Note that if you want to run closure, and also to use Module
// after the generated code, you will need to define   var Module = {};
// before the code. Then that object will be used in the code, and you
// can continue to use Module afterwards as well.
var Module;
if (!Module) Module = (typeof Module !== 'undefined' ? Module : null) || {};

// Sometimes an existing Module object exists with properties
// meant to overwrite the default module functionality. Here
// we collect those properties and reapply _after_ we configure
// the current environment's defaults to avoid having to be so
// defensive during initialization.
var moduleOverrides = {};
for (var key in Module) {
  if (Module.hasOwnProperty(key)) {
    moduleOverrides[key] = Module[key];
  }
}

// The environment setup code below is customized to use Module.
// *** Environment setup code ***
var ENVIRONMENT_IS_WEB = false;
var ENVIRONMENT_IS_WORKER = false;
var ENVIRONMENT_IS_NODE = false;
var ENVIRONMENT_IS_SHELL = false;

// Three configurations we can be running in:
// 1) We could be the application main() thread running in the main JS UI thread. (ENVIRONMENT_IS_WORKER == false and ENVIRONMENT_IS_PTHREAD == false)
// 2) We could be the application main() thread proxied to worker. (with Emscripten -s PROXY_TO_WORKER=1) (ENVIRONMENT_IS_WORKER == true, ENVIRONMENT_IS_PTHREAD == false)
// 3) We could be an application pthread running in a worker. (ENVIRONMENT_IS_WORKER == true and ENVIRONMENT_IS_PTHREAD == true)

if (Module['ENVIRONMENT']) {
  if (Module['ENVIRONMENT'] === 'WEB') {
    ENVIRONMENT_IS_WEB = true;
  } else if (Module['ENVIRONMENT'] === 'WORKER') {
    ENVIRONMENT_IS_WORKER = true;
  } else if (Module['ENVIRONMENT'] === 'NODE') {
    ENVIRONMENT_IS_NODE = true;
  } else if (Module['ENVIRONMENT'] === 'SHELL') {
    ENVIRONMENT_IS_SHELL = true;
  } else {
    throw new Error('The provided Module[\'ENVIRONMENT\'] value is not valid. It must be one of: WEB|WORKER|NODE|SHELL.');
  }
} else {
  ENVIRONMENT_IS_WEB = typeof window === 'object';
  ENVIRONMENT_IS_WORKER = typeof importScripts === 'function';
  ENVIRONMENT_IS_NODE = typeof process === 'object' && typeof require === 'function' && !ENVIRONMENT_IS_WEB && !ENVIRONMENT_IS_WORKER;
  ENVIRONMENT_IS_SHELL = !ENVIRONMENT_IS_WEB && !ENVIRONMENT_IS_NODE && !ENVIRONMENT_IS_WORKER;
}


if (ENVIRONMENT_IS_NODE) {
  // Expose functionality in the same simple way that the shells work
  // Note that we pollute the global namespace here, otherwise we break in node
  if (!Module['print']) Module['print'] = console.log;
  if (!Module['printErr']) Module['printErr'] = console.warn;

  var nodeFS;
  var nodePath;

  Module['read'] = function read(filename, binary) {
    if (!nodeFS) nodeFS = require('fs');
    if (!nodePath) nodePath = require('path');
    filename = nodePath['normalize'](filename);
    var ret = nodeFS['readFileSync'](filename);
    return binary ? ret : ret.toString();
  };

  Module['readBinary'] = function readBinary(filename) {
    var ret = Module['read'](filename, true);
    if (!ret.buffer) {
      ret = new Uint8Array(ret);
    }
    assert(ret.buffer);
    return ret;
  };

  Module['load'] = function load(f) {
    globalEval(read(f));
  };

  if (!Module['thisProgram']) {
    if (process['argv'].length > 1) {
      Module['thisProgram'] = process['argv'][1].replace(/\\/g, '/');
    } else {
      Module['thisProgram'] = 'unknown-program';
    }
  }

  Module['arguments'] = process['argv'].slice(2);

  if (typeof module !== 'undefined') {
    module['exports'] = Module;
  }

  process['on']('uncaughtException', function(ex) {
    // suppress ExitStatus exceptions from showing an error
    if (!(ex instanceof ExitStatus)) {
      throw ex;
    }
  });

  Module['inspect'] = function () { return '[Emscripten Module object]'; };
}
else if (ENVIRONMENT_IS_SHELL) {
  if (!Module['print']) Module['print'] = print;
  if (typeof printErr != 'undefined') Module['printErr'] = printErr; // not present in v8 or older sm

  if (typeof read != 'undefined') {
    Module['read'] = read;
  } else {
    Module['read'] = function read() { throw 'no read() available' };
  }

  Module['readBinary'] = function readBinary(f) {
    if (typeof readbuffer === 'function') {
      return new Uint8Array(readbuffer(f));
    }
    var data = read(f, 'binary');
    assert(typeof data === 'object');
    return data;
  };

  if (typeof scriptArgs != 'undefined') {
    Module['arguments'] = scriptArgs;
  } else if (typeof arguments != 'undefined') {
    Module['arguments'] = arguments;
  }

}
else if (ENVIRONMENT_IS_WEB || ENVIRONMENT_IS_WORKER) {
  Module['read'] = function read(url) {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', url, false);
    xhr.send(null);
    return xhr.responseText;
  };

  Module['readAsync'] = function readAsync(url, onload, onerror) {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', url, true);
    xhr.responseType = 'arraybuffer';
    xhr.onload = function xhr_onload() {
      if (xhr.status == 200 || (xhr.status == 0 && xhr.response)) { // file URLs can return 0
        onload(xhr.response);
      } else {
        onerror();
      }
    };
    xhr.onerror = onerror;
    xhr.send(null);
  };

  if (typeof arguments != 'undefined') {
    Module['arguments'] = arguments;
  }

  if (typeof console !== 'undefined') {
    if (!Module['print']) Module['print'] = function print(x) {
      console.log(x);
    };
    if (!Module['printErr']) Module['printErr'] = function printErr(x) {
      console.warn(x);
    };
  } else {
    // Probably a worker, and without console.log. We can do very little here...
    var TRY_USE_DUMP = false;
    if (!Module['print']) Module['print'] = (TRY_USE_DUMP && (typeof(dump) !== "undefined") ? (function(x) {
      dump(x);
    }) : (function(x) {
      // self.postMessage(x); // enable this if you want stdout to be sent as messages
    }));
  }

  if (ENVIRONMENT_IS_WORKER) {
    Module['load'] = importScripts;
  }

  if (typeof Module['setWindowTitle'] === 'undefined') {
    Module['setWindowTitle'] = function(title) { document.title = title };
  }
}
else {
  // Unreachable because SHELL is dependant on the others
  throw 'Unknown runtime environment. Where are we?';
}

function globalEval(x) {
  eval.call(null, x);
}
if (!Module['load'] && Module['read']) {
  Module['load'] = function load(f) {
    globalEval(Module['read'](f));
  };
}
if (!Module['print']) {
  Module['print'] = function(){};
}
if (!Module['printErr']) {
  Module['printErr'] = Module['print'];
}
if (!Module['arguments']) {
  Module['arguments'] = [];
}
if (!Module['thisProgram']) {
  Module['thisProgram'] = './this.program';
}

// *** Environment setup code ***

// Closure helpers
Module.print = Module['print'];
Module.printErr = Module['printErr'];

// Callbacks
Module['preRun'] = [];
Module['postRun'] = [];

// Merge back in the overrides
for (var key in moduleOverrides) {
  if (moduleOverrides.hasOwnProperty(key)) {
    Module[key] = moduleOverrides[key];
  }
}
// Free the object hierarchy contained in the overrides, this lets the GC
// reclaim data used e.g. in memoryInitializerRequest, which is a large typed array.
moduleOverrides = undefined;



// {{PREAMBLE_ADDITIONS}}

// === Preamble library stuff ===

// Documentation for the public APIs defined in this file must be updated in:
//    site/source/docs/api_reference/preamble.js.rst
// A prebuilt local version of the documentation is available at:
//    site/build/text/docs/api_reference/preamble.js.txt
// You can also build docs locally as HTML or other formats in site/
// An online HTML version (which may be of a different version of Emscripten)
//    is up at http://kripken.github.io/emscripten-site/docs/api_reference/preamble.js.html

//========================================
// Runtime code shared with compiler
//========================================

var Runtime = {
  setTempRet0: function (value) {
    tempRet0 = value;
  },
  getTempRet0: function () {
    return tempRet0;
  },
  stackSave: function () {
    return STACKTOP;
  },
  stackRestore: function (stackTop) {
    STACKTOP = stackTop;
  },
  getNativeTypeSize: function (type) {
    switch (type) {
      case 'i1': case 'i8': return 1;
      case 'i16': return 2;
      case 'i32': return 4;
      case 'i64': return 8;
      case 'float': return 4;
      case 'double': return 8;
      default: {
        if (type[type.length-1] === '*') {
          return Runtime.QUANTUM_SIZE; // A pointer
        } else if (type[0] === 'i') {
          var bits = parseInt(type.substr(1));
          assert(bits % 8 === 0);
          return bits/8;
        } else {
          return 0;
        }
      }
    }
  },
  getNativeFieldSize: function (type) {
    return Math.max(Runtime.getNativeTypeSize(type), Runtime.QUANTUM_SIZE);
  },
  STACK_ALIGN: 16,
  prepVararg: function (ptr, type) {
    if (type === 'double' || type === 'i64') {
      // move so the load is aligned
      if (ptr & 7) {
        assert((ptr & 7) === 4);
        ptr += 4;
      }
    } else {
      assert((ptr & 3) === 0);
    }
    return ptr;
  },
  getAlignSize: function (type, size, vararg) {
    // we align i64s and doubles on 64-bit boundaries, unlike x86
    if (!vararg && (type == 'i64' || type == 'double')) return 8;
    if (!type) return Math.min(size, 8); // align structures internally to 64 bits
    return Math.min(size || (type ? Runtime.getNativeFieldSize(type) : 0), Runtime.QUANTUM_SIZE);
  },
  dynCall: function (sig, ptr, args) {
    if (args && args.length) {
      assert(args.length == sig.length-1);
      assert(('dynCall_' + sig) in Module, 'bad function pointer type - no table for sig \'' + sig + '\'');
      return Module['dynCall_' + sig].apply(null, [ptr].concat(args));
    } else {
      assert(sig.length == 1);
      assert(('dynCall_' + sig) in Module, 'bad function pointer type - no table for sig \'' + sig + '\'');
      return Module['dynCall_' + sig].call(null, ptr);
    }
  },
  functionPointers: [],
  addFunction: function (func) {
    for (var i = 0; i < Runtime.functionPointers.length; i++) {
      if (!Runtime.functionPointers[i]) {
        Runtime.functionPointers[i] = func;
        return 2*(1 + i);
      }
    }
    throw 'Finished up all reserved function pointers. Use a higher value for RESERVED_FUNCTION_POINTERS.';
  },
  removeFunction: function (index) {
    Runtime.functionPointers[(index-2)/2] = null;
  },
  warnOnce: function (text) {
    if (!Runtime.warnOnce.shown) Runtime.warnOnce.shown = {};
    if (!Runtime.warnOnce.shown[text]) {
      Runtime.warnOnce.shown[text] = 1;
      Module.printErr(text);
    }
  },
  funcWrappers: {},
  getFuncWrapper: function (func, sig) {
    assert(sig);
    if (!Runtime.funcWrappers[sig]) {
      Runtime.funcWrappers[sig] = {};
    }
    var sigCache = Runtime.funcWrappers[sig];
    if (!sigCache[func]) {
      // optimize away arguments usage in common cases
      if (sig.length === 1) {
        sigCache[func] = function dynCall_wrapper() {
          return Runtime.dynCall(sig, func);
        };
      } else if (sig.length === 2) {
        sigCache[func] = function dynCall_wrapper(arg) {
          return Runtime.dynCall(sig, func, [arg]);
        };
      } else {
        // general case
        sigCache[func] = function dynCall_wrapper() {
          return Runtime.dynCall(sig, func, Array.prototype.slice.call(arguments));
        };
      }
    }
    return sigCache[func];
  },
  getCompilerSetting: function (name) {
    throw 'You must build with -s RETAIN_COMPILER_SETTINGS=1 for Runtime.getCompilerSetting or emscripten_get_compiler_setting to work';
  },
  stackAlloc: function (size) { var ret = STACKTOP;STACKTOP = (STACKTOP + size)|0;STACKTOP = (((STACKTOP)+15)&-16);(assert((((STACKTOP|0) < (STACK_MAX|0))|0))|0); return ret; },
  staticAlloc: function (size) { var ret = STATICTOP;STATICTOP = (STATICTOP + (assert(!staticSealed),size))|0;STATICTOP = (((STATICTOP)+15)&-16); return ret; },
  dynamicAlloc: function (size) { assert(DYNAMICTOP_PTR);var ret = HEAP32[DYNAMICTOP_PTR>>2];var end = (((ret + size + 15)|0) & -16);HEAP32[DYNAMICTOP_PTR>>2] = end;if (end >= TOTAL_MEMORY) {var success = enlargeMemory();if (!success) {HEAP32[DYNAMICTOP_PTR>>2] = ret;return 0;}}return ret;},
  alignMemory: function (size,quantum) { var ret = size = Math.ceil((size)/(quantum ? quantum : 16))*(quantum ? quantum : 16); return ret; },
  makeBigInt: function (low,high,unsigned) { var ret = (unsigned ? ((+((low>>>0)))+((+((high>>>0)))*4294967296.0)) : ((+((low>>>0)))+((+((high|0)))*4294967296.0))); return ret; },
  GLOBAL_BASE: 8,
  QUANTUM_SIZE: 4,
  __dummy__: 0
}



Module["Runtime"] = Runtime;



//========================================
// Runtime essentials
//========================================

var ABORT = 0; // whether we are quitting the application. no code should run after this. set in exit() and abort()
var EXITSTATUS = 0;

function assert(condition, text) {
  if (!condition) {
    abort('Assertion failed: ' + text);
  }
}

var globalScope = this;

// Returns the C function with a specified identifier (for C++, you need to do manual name mangling)
function getCFunc(ident) {
  var func = Module['_' + ident]; // closure exported function
  if (!func) {
    try { func = eval('_' + ident); } catch(e) {}
  }
  assert(func, 'Cannot call unknown function ' + ident + ' (perhaps LLVM optimizations or closure removed it?)');
  return func;
}

var cwrap, ccall;
(function(){
  var JSfuncs = {
    // Helpers for cwrap -- it can't refer to Runtime directly because it might
    // be renamed by closure, instead it calls JSfuncs['stackSave'].body to find
    // out what the minified function name is.
    'stackSave': function() {
      Runtime.stackSave()
    },
    'stackRestore': function() {
      Runtime.stackRestore()
    },
    // type conversion from js to c
    'arrayToC' : function(arr) {
      var ret = Runtime.stackAlloc(arr.length);
      writeArrayToMemory(arr, ret);
      return ret;
    },
    'stringToC' : function(str) {
      var ret = 0;
      if (str !== null && str !== undefined && str !== 0) { // null string
        // at most 4 bytes per UTF-8 code point, +1 for the trailing '\0'
        var len = (str.length << 2) + 1;
        ret = Runtime.stackAlloc(len);
        stringToUTF8(str, ret, len);
      }
      return ret;
    }
  };
  // For fast lookup of conversion functions
  var toC = {'string' : JSfuncs['stringToC'], 'array' : JSfuncs['arrayToC']};

  // C calling interface.
  ccall = function ccallFunc(ident, returnType, argTypes, args, opts) {
    var func = getCFunc(ident);
    var cArgs = [];
    var stack = 0;
    assert(returnType !== 'array', 'Return type should not be "array".');
    if (args) {
      for (var i = 0; i < args.length; i++) {
        var converter = toC[argTypes[i]];
        if (converter) {
          if (stack === 0) stack = Runtime.stackSave();
          cArgs[i] = converter(args[i]);
        } else {
          cArgs[i] = args[i];
        }
      }
    }
    var ret = func.apply(null, cArgs);
    if ((!opts || !opts.async) && typeof EmterpreterAsync === 'object') {
      assert(!EmterpreterAsync.state, 'cannot start async op with normal JS calling ccall');
    }
    if (opts && opts.async) assert(!returnType, 'async ccalls cannot return values');
    if (returnType === 'string') ret = Pointer_stringify(ret);
    if (stack !== 0) {
      if (opts && opts.async) {
        EmterpreterAsync.asyncFinalizers.push(function() {
          Runtime.stackRestore(stack);
        });
        return;
      }
      Runtime.stackRestore(stack);
    }
    return ret;
  }

  var sourceRegex = /^function\s*[a-zA-Z$_0-9]*\s*\(([^)]*)\)\s*{\s*([^*]*?)[\s;]*(?:return\s*(.*?)[;\s]*)?}$/;
  function parseJSFunc(jsfunc) {
    // Match the body and the return value of a javascript function source
    var parsed = jsfunc.toString().match(sourceRegex).slice(1);
    return {arguments : parsed[0], body : parsed[1], returnValue: parsed[2]}
  }

  // sources of useful functions. we create this lazily as it can trigger a source decompression on this entire file
  var JSsource = null;
  function ensureJSsource() {
    if (!JSsource) {
      JSsource = {};
      for (var fun in JSfuncs) {
        if (JSfuncs.hasOwnProperty(fun)) {
          // Elements of toCsource are arrays of three items:
          // the code, and the return value
          JSsource[fun] = parseJSFunc(JSfuncs[fun]);
        }
      }
    }
  }

  cwrap = function cwrap(ident, returnType, argTypes) {
    argTypes = argTypes || [];
    var cfunc = getCFunc(ident);
    // When the function takes numbers and returns a number, we can just return
    // the original function
    var numericArgs = argTypes.every(function(type){ return type === 'number'});
    var numericRet = (returnType !== 'string');
    if ( numericRet && numericArgs) {
      return cfunc;
    }
    // Creation of the arguments list (["$1","$2",...,"$nargs"])
    var argNames = argTypes.map(function(x,i){return '$'+i});
    var funcstr = "(function(" + argNames.join(',') + ") {";
    var nargs = argTypes.length;
    if (!numericArgs) {
      // Generate the code needed to convert the arguments from javascript
      // values to pointers
      ensureJSsource();
      funcstr += 'var stack = ' + JSsource['stackSave'].body + ';';
      for (var i = 0; i < nargs; i++) {
        var arg = argNames[i], type = argTypes[i];
        if (type === 'number') continue;
        var convertCode = JSsource[type + 'ToC']; // [code, return]
        funcstr += 'var ' + convertCode.arguments + ' = ' + arg + ';';
        funcstr += convertCode.body + ';';
        funcstr += arg + '=(' + convertCode.returnValue + ');';
      }
    }

    // When the code is compressed, the name of cfunc is not literally 'cfunc' anymore
    var cfuncname = parseJSFunc(function(){return cfunc}).returnValue;
    // Call the function
    funcstr += 'var ret = ' + cfuncname + '(' + argNames.join(',') + ');';
    if (!numericRet) { // Return type can only by 'string' or 'number'
      // Convert the result to a string
      var strgfy = parseJSFunc(function(){return Pointer_stringify}).returnValue;
      funcstr += 'ret = ' + strgfy + '(ret);';
    }
    funcstr += "if (typeof EmterpreterAsync === 'object') { assert(!EmterpreterAsync.state, 'cannot start async op with normal JS calling cwrap') }";
    if (!numericArgs) {
      // If we had a stack, restore it
      ensureJSsource();
      funcstr += JSsource['stackRestore'].body.replace('()', '(stack)') + ';';
    }
    funcstr += 'return ret})';
    return eval(funcstr);
  };
})();
Module["ccall"] = ccall;
Module["cwrap"] = cwrap;

function setValue(ptr, value, type, noSafe) {
  type = type || 'i8';
  if (type.charAt(type.length-1) === '*') type = 'i32'; // pointers are 32-bit
    switch(type) {
      case 'i1': HEAP8[((ptr)>>0)]=value; break;
      case 'i8': HEAP8[((ptr)>>0)]=value; break;
      case 'i16': HEAP16[((ptr)>>1)]=value; break;
      case 'i32': HEAP32[((ptr)>>2)]=value; break;
      case 'i64': (tempI64 = [value>>>0,(tempDouble=value,(+(Math_abs(tempDouble))) >= 1.0 ? (tempDouble > 0.0 ? ((Math_min((+(Math_floor((tempDouble)/4294967296.0))), 4294967295.0))|0)>>>0 : (~~((+(Math_ceil((tempDouble - +(((~~(tempDouble)))>>>0))/4294967296.0)))))>>>0) : 0)],HEAP32[((ptr)>>2)]=tempI64[0],HEAP32[(((ptr)+(4))>>2)]=tempI64[1]); break;
      case 'float': HEAPF32[((ptr)>>2)]=value; break;
      case 'double': HEAPF64[((ptr)>>3)]=value; break;
      default: abort('invalid type for setValue: ' + type);
    }
}
Module["setValue"] = setValue;


function getValue(ptr, type, noSafe) {
  type = type || 'i8';
  if (type.charAt(type.length-1) === '*') type = 'i32'; // pointers are 32-bit
    switch(type) {
      case 'i1': return HEAP8[((ptr)>>0)];
      case 'i8': return HEAP8[((ptr)>>0)];
      case 'i16': return HEAP16[((ptr)>>1)];
      case 'i32': return HEAP32[((ptr)>>2)];
      case 'i64': return HEAP32[((ptr)>>2)];
      case 'float': return HEAPF32[((ptr)>>2)];
      case 'double': return HEAPF64[((ptr)>>3)];
      default: abort('invalid type for setValue: ' + type);
    }
  return null;
}
Module["getValue"] = getValue;

var ALLOC_NORMAL = 0; // Tries to use _malloc()
var ALLOC_STACK = 1; // Lives for the duration of the current function call
var ALLOC_STATIC = 2; // Cannot be freed
var ALLOC_DYNAMIC = 3; // Cannot be freed except through sbrk
var ALLOC_NONE = 4; // Do not allocate
Module["ALLOC_NORMAL"] = ALLOC_NORMAL;
Module["ALLOC_STACK"] = ALLOC_STACK;
Module["ALLOC_STATIC"] = ALLOC_STATIC;
Module["ALLOC_DYNAMIC"] = ALLOC_DYNAMIC;
Module["ALLOC_NONE"] = ALLOC_NONE;

// allocate(): This is for internal use. You can use it yourself as well, but the interface
//             is a little tricky (see docs right below). The reason is that it is optimized
//             for multiple syntaxes to save space in generated code. So you should
//             normally not use allocate(), and instead allocate memory using _malloc(),
//             initialize it with setValue(), and so forth.
// @slab: An array of data, or a number. If a number, then the size of the block to allocate,
//        in *bytes* (note that this is sometimes confusing: the next parameter does not
//        affect this!)
// @types: Either an array of types, one for each byte (or 0 if no type at that position),
//         or a single type which is used for the entire block. This only matters if there
//         is initial data - if @slab is a number, then this does not matter at all and is
//         ignored.
// @allocator: How to allocate memory, see ALLOC_*
function allocate(slab, types, allocator, ptr) {
  var zeroinit, size;
  if (typeof slab === 'number') {
    zeroinit = true;
    size = slab;
  } else {
    zeroinit = false;
    size = slab.length;
  }

  var singleType = typeof types === 'string' ? types : null;

  var ret;
  if (allocator == ALLOC_NONE) {
    ret = ptr;
  } else {
    ret = [typeof _malloc === 'function' ? _malloc : Runtime.staticAlloc, Runtime.stackAlloc, Runtime.staticAlloc, Runtime.dynamicAlloc][allocator === undefined ? ALLOC_STATIC : allocator](Math.max(size, singleType ? 1 : types.length));
  }

  if (zeroinit) {
    var ptr = ret, stop;
    assert((ret & 3) == 0);
    stop = ret + (size & ~3);
    for (; ptr < stop; ptr += 4) {
      HEAP32[((ptr)>>2)]=0;
    }
    stop = ret + size;
    while (ptr < stop) {
      HEAP8[((ptr++)>>0)]=0;
    }
    return ret;
  }

  if (singleType === 'i8') {
    if (slab.subarray || slab.slice) {
      HEAPU8.set(slab, ret);
    } else {
      HEAPU8.set(new Uint8Array(slab), ret);
    }
    return ret;
  }

  var i = 0, type, typeSize, previousType;
  while (i < size) {
    var curr = slab[i];

    if (typeof curr === 'function') {
      curr = Runtime.getFunctionIndex(curr);
    }

    type = singleType || types[i];
    if (type === 0) {
      i++;
      continue;
    }
    assert(type, 'Must know what type to store in allocate!');

    if (type == 'i64') type = 'i32'; // special case: we have one i32 here, and one i32 later

    setValue(ret+i, curr, type);

    // no need to look up size unless type changes, so cache it
    if (previousType !== type) {
      typeSize = Runtime.getNativeTypeSize(type);
      previousType = type;
    }
    i += typeSize;
  }

  return ret;
}
Module["allocate"] = allocate;

// Allocate memory during any stage of startup - static memory early on, dynamic memory later, malloc when ready
function getMemory(size) {
  if (!staticSealed) return Runtime.staticAlloc(size);
  if (!runtimeInitialized) return Runtime.dynamicAlloc(size);
  return _malloc(size);
}
Module["getMemory"] = getMemory;

function Pointer_stringify(ptr, /* optional */ length) {
  if (length === 0 || !ptr) return '';
  // TODO: use TextDecoder
  // Find the length, and check for UTF while doing so
  var hasUtf = 0;
  var t;
  var i = 0;
  while (1) {
    assert(ptr + i < TOTAL_MEMORY);
    t = HEAPU8[(((ptr)+(i))>>0)];
    hasUtf |= t;
    if (t == 0 && !length) break;
    i++;
    if (length && i == length) break;
  }
  if (!length) length = i;

  var ret = '';

  if (hasUtf < 128) {
    var MAX_CHUNK = 1024; // split up into chunks, because .apply on a huge string can overflow the stack
    var curr;
    while (length > 0) {
      curr = String.fromCharCode.apply(String, HEAPU8.subarray(ptr, ptr + Math.min(length, MAX_CHUNK)));
      ret = ret ? ret + curr : curr;
      ptr += MAX_CHUNK;
      length -= MAX_CHUNK;
    }
    return ret;
  }
  return Module['UTF8ToString'](ptr);
}
Module["Pointer_stringify"] = Pointer_stringify;

// Given a pointer 'ptr' to a null-terminated ASCII-encoded string in the emscripten HEAP, returns
// a copy of that string as a Javascript String object.

function AsciiToString(ptr) {
  var str = '';
  while (1) {
    var ch = HEAP8[((ptr++)>>0)];
    if (!ch) return str;
    str += String.fromCharCode(ch);
  }
}
Module["AsciiToString"] = AsciiToString;

// Copies the given Javascript String object 'str' to the emscripten HEAP at address 'outPtr',
// null-terminated and encoded in ASCII form. The copy will require at most str.length+1 bytes of space in the HEAP.

function stringToAscii(str, outPtr) {
  return writeAsciiToMemory(str, outPtr, false);
}
Module["stringToAscii"] = stringToAscii;

// Given a pointer 'ptr' to a null-terminated UTF8-encoded string in the given array that contains uint8 values, returns
// a copy of that string as a Javascript String object.

var UTF8Decoder = typeof TextDecoder !== 'undefined' ? new TextDecoder('utf8') : undefined;
function UTF8ArrayToString(u8Array, idx) {
  var endPtr = idx;
  // TextDecoder needs to know the byte length in advance, it doesn't stop on null terminator by itself.
  // Also, use the length info to avoid running tiny strings through TextDecoder, since .subarray() allocates garbage.
  while (u8Array[endPtr]) ++endPtr;

  if (endPtr - idx > 16 && u8Array.subarray && UTF8Decoder) {
    return UTF8Decoder.decode(u8Array.subarray(idx, endPtr));
  } else {
    var u0, u1, u2, u3, u4, u5;

    var str = '';
    while (1) {
      // For UTF8 byte structure, see http://en.wikipedia.org/wiki/UTF-8#Description and https://www.ietf.org/rfc/rfc2279.txt and https://tools.ietf.org/html/rfc3629
      u0 = u8Array[idx++];
      if (!u0) return str;
      if (!(u0 & 0x80)) { str += String.fromCharCode(u0); continue; }
      u1 = u8Array[idx++] & 63;
      if ((u0 & 0xE0) == 0xC0) { str += String.fromCharCode(((u0 & 31) << 6) | u1); continue; }
      u2 = u8Array[idx++] & 63;
      if ((u0 & 0xF0) == 0xE0) {
        u0 = ((u0 & 15) << 12) | (u1 << 6) | u2;
      } else {
        u3 = u8Array[idx++] & 63;
        if ((u0 & 0xF8) == 0xF0) {
          u0 = ((u0 & 7) << 18) | (u1 << 12) | (u2 << 6) | u3;
        } else {
          u4 = u8Array[idx++] & 63;
          if ((u0 & 0xFC) == 0xF8) {
            u0 = ((u0 & 3) << 24) | (u1 << 18) | (u2 << 12) | (u3 << 6) | u4;
          } else {
            u5 = u8Array[idx++] & 63;
            u0 = ((u0 & 1) << 30) | (u1 << 24) | (u2 << 18) | (u3 << 12) | (u4 << 6) | u5;
          }
        }
      }
      if (u0 < 0x10000) {
        str += String.fromCharCode(u0);
      } else {
        var ch = u0 - 0x10000;
        str += String.fromCharCode(0xD800 | (ch >> 10), 0xDC00 | (ch & 0x3FF));
      }
    }
  }
}
Module["UTF8ArrayToString"] = UTF8ArrayToString;

// Given a pointer 'ptr' to a null-terminated UTF8-encoded string in the emscripten HEAP, returns
// a copy of that string as a Javascript String object.

function UTF8ToString(ptr) {
  return UTF8ArrayToString(HEAPU8,ptr);
}
Module["UTF8ToString"] = UTF8ToString;

// Copies the given Javascript String object 'str' to the given byte array at address 'outIdx',
// encoded in UTF8 form and null-terminated. The copy will require at most str.length*4+1 bytes of space in the HEAP.
// Use the function lengthBytesUTF8 to compute the exact number of bytes (excluding null terminator) that this function will write.
// Parameters:
//   str: the Javascript string to copy.
//   outU8Array: the array to copy to. Each index in this array is assumed to be one 8-byte element.
//   outIdx: The starting offset in the array to begin the copying.
//   maxBytesToWrite: The maximum number of bytes this function can write to the array. This count should include the null
//                    terminator, i.e. if maxBytesToWrite=1, only the null terminator will be written and nothing else.
//                    maxBytesToWrite=0 does not write any bytes to the output, not even the null terminator.
// Returns the number of bytes written, EXCLUDING the null terminator.

function stringToUTF8Array(str, outU8Array, outIdx, maxBytesToWrite) {
  if (!(maxBytesToWrite > 0)) // Parameter maxBytesToWrite is not optional. Negative values, 0, null, undefined and false each don't write out any bytes.
    return 0;

  var startIdx = outIdx;
  var endIdx = outIdx + maxBytesToWrite - 1; // -1 for string null terminator.
  for (var i = 0; i < str.length; ++i) {
    // Gotcha: charCodeAt returns a 16-bit word that is a UTF-16 encoded code unit, not a Unicode code point of the character! So decode UTF16->UTF32->UTF8.
    // See http://unicode.org/faq/utf_bom.html#utf16-3
    // For UTF8 byte structure, see http://en.wikipedia.org/wiki/UTF-8#Description and https://www.ietf.org/rfc/rfc2279.txt and https://tools.ietf.org/html/rfc3629
    var u = str.charCodeAt(i); // possibly a lead surrogate
    if (u >= 0xD800 && u <= 0xDFFF) u = 0x10000 + ((u & 0x3FF) << 10) | (str.charCodeAt(++i) & 0x3FF);
    if (u <= 0x7F) {
      if (outIdx >= endIdx) break;
      outU8Array[outIdx++] = u;
    } else if (u <= 0x7FF) {
      if (outIdx + 1 >= endIdx) break;
      outU8Array[outIdx++] = 0xC0 | (u >> 6);
      outU8Array[outIdx++] = 0x80 | (u & 63);
    } else if (u <= 0xFFFF) {
      if (outIdx + 2 >= endIdx) break;
      outU8Array[outIdx++] = 0xE0 | (u >> 12);
      outU8Array[outIdx++] = 0x80 | ((u >> 6) & 63);
      outU8Array[outIdx++] = 0x80 | (u & 63);
    } else if (u <= 0x1FFFFF) {
      if (outIdx + 3 >= endIdx) break;
      outU8Array[outIdx++] = 0xF0 | (u >> 18);
      outU8Array[outIdx++] = 0x80 | ((u >> 12) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 6) & 63);
      outU8Array[outIdx++] = 0x80 | (u & 63);
    } else if (u <= 0x3FFFFFF) {
      if (outIdx + 4 >= endIdx) break;
      outU8Array[outIdx++] = 0xF8 | (u >> 24);
      outU8Array[outIdx++] = 0x80 | ((u >> 18) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 12) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 6) & 63);
      outU8Array[outIdx++] = 0x80 | (u & 63);
    } else {
      if (outIdx + 5 >= endIdx) break;
      outU8Array[outIdx++] = 0xFC | (u >> 30);
      outU8Array[outIdx++] = 0x80 | ((u >> 24) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 18) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 12) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 6) & 63);
      outU8Array[outIdx++] = 0x80 | (u & 63);
    }
  }
  // Null-terminate the pointer to the buffer.
  outU8Array[outIdx] = 0;
  return outIdx - startIdx;
}
Module["stringToUTF8Array"] = stringToUTF8Array;

// Copies the given Javascript String object 'str' to the emscripten HEAP at address 'outPtr',
// null-terminated and encoded in UTF8 form. The copy will require at most str.length*4+1 bytes of space in the HEAP.
// Use the function lengthBytesUTF8 to compute the exact number of bytes (excluding null terminator) that this function will write.
// Returns the number of bytes written, EXCLUDING the null terminator.

function stringToUTF8(str, outPtr, maxBytesToWrite) {
  assert(typeof maxBytesToWrite == 'number', 'stringToUTF8(str, outPtr, maxBytesToWrite) is missing the third parameter that specifies the length of the output buffer!');
  return stringToUTF8Array(str, HEAPU8,outPtr, maxBytesToWrite);
}
Module["stringToUTF8"] = stringToUTF8;

// Returns the number of bytes the given Javascript string takes if encoded as a UTF8 byte array, EXCLUDING the null terminator byte.

function lengthBytesUTF8(str) {
  var len = 0;
  for (var i = 0; i < str.length; ++i) {
    // Gotcha: charCodeAt returns a 16-bit word that is a UTF-16 encoded code unit, not a Unicode code point of the character! So decode UTF16->UTF32->UTF8.
    // See http://unicode.org/faq/utf_bom.html#utf16-3
    var u = str.charCodeAt(i); // possibly a lead surrogate
    if (u >= 0xD800 && u <= 0xDFFF) u = 0x10000 + ((u & 0x3FF) << 10) | (str.charCodeAt(++i) & 0x3FF);
    if (u <= 0x7F) {
      ++len;
    } else if (u <= 0x7FF) {
      len += 2;
    } else if (u <= 0xFFFF) {
      len += 3;
    } else if (u <= 0x1FFFFF) {
      len += 4;
    } else if (u <= 0x3FFFFFF) {
      len += 5;
    } else {
      len += 6;
    }
  }
  return len;
}
Module["lengthBytesUTF8"] = lengthBytesUTF8;

// Given a pointer 'ptr' to a null-terminated UTF16LE-encoded string in the emscripten HEAP, returns
// a copy of that string as a Javascript String object.

var UTF16Decoder = typeof TextDecoder !== 'undefined' ? new TextDecoder('utf-16le') : undefined;
function UTF16ToString(ptr) {
  assert(ptr % 2 == 0, 'Pointer passed to UTF16ToString must be aligned to two bytes!');
  var endPtr = ptr;
  // TextDecoder needs to know the byte length in advance, it doesn't stop on null terminator by itself.
  // Also, use the length info to avoid running tiny strings through TextDecoder, since .subarray() allocates garbage.
  var idx = endPtr >> 1;
  while (HEAP16[idx]) ++idx;
  endPtr = idx << 1;

  if (endPtr - ptr > 32 && UTF16Decoder) {
    return UTF16Decoder.decode(HEAPU8.subarray(ptr, endPtr));
  } else {
    var i = 0;

    var str = '';
    while (1) {
      var codeUnit = HEAP16[(((ptr)+(i*2))>>1)];
      if (codeUnit == 0) return str;
      ++i;
      // fromCharCode constructs a character from a UTF-16 code unit, so we can pass the UTF16 string right through.
      str += String.fromCharCode(codeUnit);
    }
  }
}


// Copies the given Javascript String object 'str' to the emscripten HEAP at address 'outPtr',
// null-terminated and encoded in UTF16 form. The copy will require at most str.length*4+2 bytes of space in the HEAP.
// Use the function lengthBytesUTF16() to compute the exact number of bytes (excluding null terminator) that this function will write.
// Parameters:
//   str: the Javascript string to copy.
//   outPtr: Byte address in Emscripten HEAP where to write the string to.
//   maxBytesToWrite: The maximum number of bytes this function can write to the array. This count should include the null
//                    terminator, i.e. if maxBytesToWrite=2, only the null terminator will be written and nothing else.
//                    maxBytesToWrite<2 does not write any bytes to the output, not even the null terminator.
// Returns the number of bytes written, EXCLUDING the null terminator.

function stringToUTF16(str, outPtr, maxBytesToWrite) {
  assert(outPtr % 2 == 0, 'Pointer passed to stringToUTF16 must be aligned to two bytes!');
  assert(typeof maxBytesToWrite == 'number', 'stringToUTF16(str, outPtr, maxBytesToWrite) is missing the third parameter that specifies the length of the output buffer!');
  // Backwards compatibility: if max bytes is not specified, assume unsafe unbounded write is allowed.
  if (maxBytesToWrite === undefined) {
    maxBytesToWrite = 0x7FFFFFFF;
  }
  if (maxBytesToWrite < 2) return 0;
  maxBytesToWrite -= 2; // Null terminator.
  var startPtr = outPtr;
  var numCharsToWrite = (maxBytesToWrite < str.length*2) ? (maxBytesToWrite / 2) : str.length;
  for (var i = 0; i < numCharsToWrite; ++i) {
    // charCodeAt returns a UTF-16 encoded code unit, so it can be directly written to the HEAP.
    var codeUnit = str.charCodeAt(i); // possibly a lead surrogate
    HEAP16[((outPtr)>>1)]=codeUnit;
    outPtr += 2;
  }
  // Null-terminate the pointer to the HEAP.
  HEAP16[((outPtr)>>1)]=0;
  return outPtr - startPtr;
}


// Returns the number of bytes the given Javascript string takes if encoded as a UTF16 byte array, EXCLUDING the null terminator byte.

function lengthBytesUTF16(str) {
  return str.length*2;
}


function UTF32ToString(ptr) {
  assert(ptr % 4 == 0, 'Pointer passed to UTF32ToString must be aligned to four bytes!');
  var i = 0;

  var str = '';
  while (1) {
    var utf32 = HEAP32[(((ptr)+(i*4))>>2)];
    if (utf32 == 0)
      return str;
    ++i;
    // Gotcha: fromCharCode constructs a character from a UTF-16 encoded code (pair), not from a Unicode code point! So encode the code point to UTF-16 for constructing.
    // See http://unicode.org/faq/utf_bom.html#utf16-3
    if (utf32 >= 0x10000) {
      var ch = utf32 - 0x10000;
      str += String.fromCharCode(0xD800 | (ch >> 10), 0xDC00 | (ch & 0x3FF));
    } else {
      str += String.fromCharCode(utf32);
    }
  }
}


// Copies the given Javascript String object 'str' to the emscripten HEAP at address 'outPtr',
// null-terminated and encoded in UTF32 form. The copy will require at most str.length*4+4 bytes of space in the HEAP.
// Use the function lengthBytesUTF32() to compute the exact number of bytes (excluding null terminator) that this function will write.
// Parameters:
//   str: the Javascript string to copy.
//   outPtr: Byte address in Emscripten HEAP where to write the string to.
//   maxBytesToWrite: The maximum number of bytes this function can write to the array. This count should include the null
//                    terminator, i.e. if maxBytesToWrite=4, only the null terminator will be written and nothing else.
//                    maxBytesToWrite<4 does not write any bytes to the output, not even the null terminator.
// Returns the number of bytes written, EXCLUDING the null terminator.

function stringToUTF32(str, outPtr, maxBytesToWrite) {
  assert(outPtr % 4 == 0, 'Pointer passed to stringToUTF32 must be aligned to four bytes!');
  assert(typeof maxBytesToWrite == 'number', 'stringToUTF32(str, outPtr, maxBytesToWrite) is missing the third parameter that specifies the length of the output buffer!');
  // Backwards compatibility: if max bytes is not specified, assume unsafe unbounded write is allowed.
  if (maxBytesToWrite === undefined) {
    maxBytesToWrite = 0x7FFFFFFF;
  }
  if (maxBytesToWrite < 4) return 0;
  var startPtr = outPtr;
  var endPtr = startPtr + maxBytesToWrite - 4;
  for (var i = 0; i < str.length; ++i) {
    // Gotcha: charCodeAt returns a 16-bit word that is a UTF-16 encoded code unit, not a Unicode code point of the character! We must decode the string to UTF-32 to the heap.
    // See http://unicode.org/faq/utf_bom.html#utf16-3
    var codeUnit = str.charCodeAt(i); // possibly a lead surrogate
    if (codeUnit >= 0xD800 && codeUnit <= 0xDFFF) {
      var trailSurrogate = str.charCodeAt(++i);
      codeUnit = 0x10000 + ((codeUnit & 0x3FF) << 10) | (trailSurrogate & 0x3FF);
    }
    HEAP32[((outPtr)>>2)]=codeUnit;
    outPtr += 4;
    if (outPtr + 4 > endPtr) break;
  }
  // Null-terminate the pointer to the HEAP.
  HEAP32[((outPtr)>>2)]=0;
  return outPtr - startPtr;
}


// Returns the number of bytes the given Javascript string takes if encoded as a UTF16 byte array, EXCLUDING the null terminator byte.

function lengthBytesUTF32(str) {
  var len = 0;
  for (var i = 0; i < str.length; ++i) {
    // Gotcha: charCodeAt returns a 16-bit word that is a UTF-16 encoded code unit, not a Unicode code point of the character! We must decode the string to UTF-32 to the heap.
    // See http://unicode.org/faq/utf_bom.html#utf16-3
    var codeUnit = str.charCodeAt(i);
    if (codeUnit >= 0xD800 && codeUnit <= 0xDFFF) ++i; // possibly a lead surrogate, so skip over the tail surrogate.
    len += 4;
  }

  return len;
}


function demangle(func) {
  var hasLibcxxabi = !!Module['___cxa_demangle'];
  if (hasLibcxxabi) {
    try {
      var s = func.substr(1);
      var len = lengthBytesUTF8(s)+1;
      var buf = _malloc(len);
      stringToUTF8(s, buf, len);
      var status = _malloc(4);
      var ret = Module['___cxa_demangle'](buf, 0, 0, status);
      if (getValue(status, 'i32') === 0 && ret) {
        return Pointer_stringify(ret);
      }
      // otherwise, libcxxabi failed
    } catch(e) {
      // ignore problems here
    } finally {
      if (buf) _free(buf);
      if (status) _free(status);
      if (ret) _free(ret);
    }
    // failure when using libcxxabi, don't demangle
    return func;
  }
  Runtime.warnOnce('warning: build with  -s DEMANGLE_SUPPORT=1  to link in libcxxabi demangling');
  return func;
}

function demangleAll(text) {
  return text.replace(/__Z[\w\d_]+/g, function(x) { var y = demangle(x); return x === y ? x : (x + ' [' + y + ']') });
}

function jsStackTrace() {
  var err = new Error();
  if (!err.stack) {
    // IE10+ special cases: It does have callstack info, but it is only populated if an Error object is thrown,
    // so try that as a special-case.
    try {
      throw new Error(0);
    } catch(e) {
      err = e;
    }
    if (!err.stack) {
      return '(no stack trace available)';
    }
  }
  return err.stack.toString();
}

function stackTrace() {
  var js = jsStackTrace();
  if (Module['extraStackTrace']) js += '\n' + Module['extraStackTrace']();
  return demangleAll(js);
}
Module["stackTrace"] = stackTrace;

// Memory management

var PAGE_SIZE = 4096;

function alignMemoryPage(x) {
  if (x % 4096 > 0) {
    x += (4096 - (x % 4096));
  }
  return x;
}

var HEAP;
var buffer;
var HEAP8, HEAPU8, HEAP16, HEAPU16, HEAP32, HEAPU32, HEAPF32, HEAPF64;

function updateGlobalBuffer(buf) {
  Module['buffer'] = buffer = buf;
}

function updateGlobalBufferViews() {
  Module['HEAP8'] = HEAP8 = new Int8Array(buffer);
  Module['HEAP16'] = HEAP16 = new Int16Array(buffer);
  Module['HEAP32'] = HEAP32 = new Int32Array(buffer);
  Module['HEAPU8'] = HEAPU8 = new Uint8Array(buffer);
  Module['HEAPU16'] = HEAPU16 = new Uint16Array(buffer);
  Module['HEAPU32'] = HEAPU32 = new Uint32Array(buffer);
  Module['HEAPF32'] = HEAPF32 = new Float32Array(buffer);
  Module['HEAPF64'] = HEAPF64 = new Float64Array(buffer);
}

var STATIC_BASE, STATICTOP, staticSealed; // static area
var STACK_BASE, STACKTOP, STACK_MAX; // stack area
var DYNAMIC_BASE, DYNAMICTOP_PTR; // dynamic area handled by sbrk

  STATIC_BASE = STATICTOP = STACK_BASE = STACKTOP = STACK_MAX = DYNAMIC_BASE = DYNAMICTOP_PTR = 0;
  staticSealed = false;


// Initializes the stack cookie. Called at the startup of main and at the startup of each thread in pthreads mode.
function writeStackCookie() {
  assert((STACK_MAX & 3) == 0);
  HEAPU32[(STACK_MAX >> 2)-1] = 0x02135467;
  HEAPU32[(STACK_MAX >> 2)-2] = 0x89BACDFE;
}

function checkStackCookie() {
  if (HEAPU32[(STACK_MAX >> 2)-1] != 0x02135467 || HEAPU32[(STACK_MAX >> 2)-2] != 0x89BACDFE) {
    abort('Stack overflow! Stack cookie has been overwritten, expected hex dwords 0x89BACDFE and 0x02135467, but received 0x' + HEAPU32[(STACK_MAX >> 2)-2].toString(16) + ' ' + HEAPU32[(STACK_MAX >> 2)-1].toString(16));
  }
  // Also test the global address 0 for integrity. This check is not compatible with SAFE_SPLIT_MEMORY though, since that mode already tests all address 0 accesses on its own.
  if (HEAP32[0] !== 0x63736d65 /* 'emsc' */) throw 'Runtime error: The application has corrupted its heap memory area (address zero)!';
}

function abortStackOverflow(allocSize) {
  abort('Stack overflow! Attempted to allocate ' + allocSize + ' bytes on the stack, but stack has only ' + (STACK_MAX - asm.stackSave() + allocSize) + ' bytes available!');
}

function abortOnCannotGrowMemory() {
  abort('Cannot enlarge memory arrays. Either (1) compile with  -s TOTAL_MEMORY=X  with X higher than the current value ' + TOTAL_MEMORY + ', (2) compile with  -s ALLOW_MEMORY_GROWTH=1  which adjusts the size at runtime but prevents some optimizations, (3) set Module.TOTAL_MEMORY to a higher value before the program runs, or if you want malloc to return NULL (0) instead of this abort, compile with  -s ABORTING_MALLOC=0 ');
}


function enlargeMemory() {
  abortOnCannotGrowMemory();
}


var TOTAL_STACK = Module['TOTAL_STACK'] || 5242880;
var TOTAL_MEMORY = Module['TOTAL_MEMORY'] || 16777216;

var WASM_PAGE_SIZE = 64 * 1024;

var totalMemory = WASM_PAGE_SIZE;
while (totalMemory < TOTAL_MEMORY || totalMemory < 2*TOTAL_STACK) {
  if (totalMemory < 16*1024*1024) {
    totalMemory *= 2;
  } else {
    totalMemory += 16*1024*1024;
  }
}
if (totalMemory !== TOTAL_MEMORY) {
  Module.printErr('increasing TOTAL_MEMORY to ' + totalMemory + ' to be compliant with the asm.js spec (and given that TOTAL_STACK=' + TOTAL_STACK + ')');
  TOTAL_MEMORY = totalMemory;
}

// Initialize the runtime's memory
// check for full engine support (use string 'subarray' to avoid closure compiler confusion)
assert(typeof Int32Array !== 'undefined' && typeof Float64Array !== 'undefined' && !!(new Int32Array(1)['subarray']) && !!(new Int32Array(1)['set']),
       'JS engine does not provide full typed array support');



// Use a provided buffer, if there is one, or else allocate a new one
if (Module['buffer']) {
  buffer = Module['buffer'];
  assert(buffer.byteLength === TOTAL_MEMORY, 'provided buffer should be ' + TOTAL_MEMORY + ' bytes, but it is ' + buffer.byteLength);
} else {
  // Use a WebAssembly memory where available
  {
    buffer = new ArrayBuffer(TOTAL_MEMORY);
  }
  assert(buffer.byteLength === TOTAL_MEMORY);
}
updateGlobalBufferViews();


function getTotalMemory() {
  return TOTAL_MEMORY;
}

// Endianness check (note: assumes compiler arch was little-endian)
  HEAP32[0] = 0x63736d65; /* 'emsc' */
HEAP16[1] = 0x6373;
if (HEAPU8[2] !== 0x73 || HEAPU8[3] !== 0x63) throw 'Runtime error: expected the system to be little-endian!';

Module['HEAP'] = HEAP;
Module['buffer'] = buffer;
Module['HEAP8'] = HEAP8;
Module['HEAP16'] = HEAP16;
Module['HEAP32'] = HEAP32;
Module['HEAPU8'] = HEAPU8;
Module['HEAPU16'] = HEAPU16;
Module['HEAPU32'] = HEAPU32;
Module['HEAPF32'] = HEAPF32;
Module['HEAPF64'] = HEAPF64;

function callRuntimeCallbacks(callbacks) {
  while(callbacks.length > 0) {
    var callback = callbacks.shift();
    if (typeof callback == 'function') {
      callback();
      continue;
    }
    var func = callback.func;
    if (typeof func === 'number') {
      if (callback.arg === undefined) {
        Runtime.dynCall('v', func);
      } else {
        Runtime.dynCall('vi', func, [callback.arg]);
      }
    } else {
      func(callback.arg === undefined ? null : callback.arg);
    }
  }
}

var __ATPRERUN__  = []; // functions called before the runtime is initialized
var __ATINIT__    = []; // functions called during startup
var __ATMAIN__    = []; // functions called when main() is to be run
var __ATEXIT__    = []; // functions called during shutdown
var __ATPOSTRUN__ = []; // functions called after the runtime has exited

var runtimeInitialized = false;
var runtimeExited = false;


function preRun() {
  // compatibility - merge in anything from Module['preRun'] at this time
  if (Module['preRun']) {
    if (typeof Module['preRun'] == 'function') Module['preRun'] = [Module['preRun']];
    while (Module['preRun'].length) {
      addOnPreRun(Module['preRun'].shift());
    }
  }
  callRuntimeCallbacks(__ATPRERUN__);
}

function ensureInitRuntime() {
  checkStackCookie();
  if (runtimeInitialized) return;
  runtimeInitialized = true;
  callRuntimeCallbacks(__ATINIT__);
}

function preMain() {
  checkStackCookie();
  callRuntimeCallbacks(__ATMAIN__);
}

function exitRuntime() {
  checkStackCookie();
  callRuntimeCallbacks(__ATEXIT__);
  runtimeExited = true;
}

function postRun() {
  checkStackCookie();
  // compatibility - merge in anything from Module['postRun'] at this time
  if (Module['postRun']) {
    if (typeof Module['postRun'] == 'function') Module['postRun'] = [Module['postRun']];
    while (Module['postRun'].length) {
      addOnPostRun(Module['postRun'].shift());
    }
  }
  callRuntimeCallbacks(__ATPOSTRUN__);
}

function addOnPreRun(cb) {
  __ATPRERUN__.unshift(cb);
}
Module["addOnPreRun"] = addOnPreRun;

function addOnInit(cb) {
  __ATINIT__.unshift(cb);
}
Module["addOnInit"] = addOnInit;

function addOnPreMain(cb) {
  __ATMAIN__.unshift(cb);
}
Module["addOnPreMain"] = addOnPreMain;

function addOnExit(cb) {
  __ATEXIT__.unshift(cb);
}
Module["addOnExit"] = addOnExit;

function addOnPostRun(cb) {
  __ATPOSTRUN__.unshift(cb);
}
Module["addOnPostRun"] = addOnPostRun;

// Tools


function intArrayFromString(stringy, dontAddNull, length /* optional */) {
  var len = length > 0 ? length : lengthBytesUTF8(stringy)+1;
  var u8array = new Array(len);
  var numBytesWritten = stringToUTF8Array(stringy, u8array, 0, u8array.length);
  if (dontAddNull) u8array.length = numBytesWritten;
  return u8array;
}
Module["intArrayFromString"] = intArrayFromString;

function intArrayToString(array) {
  var ret = [];
  for (var i = 0; i < array.length; i++) {
    var chr = array[i];
    if (chr > 0xFF) {
      assert(false, 'Character code ' + chr + ' (' + String.fromCharCode(chr) + ')  at offset ' + i + ' not in 0x00-0xFF.');
      chr &= 0xFF;
    }
    ret.push(String.fromCharCode(chr));
  }
  return ret.join('');
}
Module["intArrayToString"] = intArrayToString;

// Deprecated: This function should not be called because it is unsafe and does not provide
// a maximum length limit of how many bytes it is allowed to write. Prefer calling the
// function stringToUTF8Array() instead, which takes in a maximum length that can be used
// to be secure from out of bounds writes.
function writeStringToMemory(string, buffer, dontAddNull) {
  Runtime.warnOnce('writeStringToMemory is deprecated and should not be called! Use stringToUTF8() instead!');

  var lastChar, end;
  if (dontAddNull) {
    // stringToUTF8Array always appends null. If we don't want to do that, remember the
    // character that existed at the location where the null will be placed, and restore
    // that after the write (below).
    end = buffer + lengthBytesUTF8(string);
    lastChar = HEAP8[end];
  }
  stringToUTF8(string, buffer, Infinity);
  if (dontAddNull) HEAP8[end] = lastChar; // Restore the value under the null character.
}
Module["writeStringToMemory"] = writeStringToMemory;

function writeArrayToMemory(array, buffer) {
  assert(array.length >= 0, 'writeArrayToMemory array must have a length (should be an array or typed array)')
  HEAP8.set(array, buffer);
}
Module["writeArrayToMemory"] = writeArrayToMemory;

function writeAsciiToMemory(str, buffer, dontAddNull) {
  for (var i = 0; i < str.length; ++i) {
    assert(str.charCodeAt(i) === str.charCodeAt(i)&0xff);
    HEAP8[((buffer++)>>0)]=str.charCodeAt(i);
  }
  // Null-terminate the pointer to the HEAP.
  if (!dontAddNull) HEAP8[((buffer)>>0)]=0;
}
Module["writeAsciiToMemory"] = writeAsciiToMemory;

function unSign(value, bits, ignore) {
  if (value >= 0) {
    return value;
  }
  return bits <= 32 ? 2*Math.abs(1 << (bits-1)) + value // Need some trickery, since if bits == 32, we are right at the limit of the bits JS uses in bitshifts
                    : Math.pow(2, bits)         + value;
}
function reSign(value, bits, ignore) {
  if (value <= 0) {
    return value;
  }
  var half = bits <= 32 ? Math.abs(1 << (bits-1)) // abs is needed if bits == 32
                        : Math.pow(2, bits-1);
  if (value >= half && (bits <= 32 || value > half)) { // for huge values, we can hit the precision limit and always get true here. so don't do that
                                                       // but, in general there is no perfect solution here. With 64-bit ints, we get rounding and errors
                                                       // TODO: In i64 mode 1, resign the two parts separately and safely
    value = -2*half + value; // Cannot bitshift half, as it may be at the limit of the bits JS uses in bitshifts
  }
  return value;
}


// check for imul support, and also for correctness ( https://bugs.webkit.org/show_bug.cgi?id=126345 )
if (!Math['imul'] || Math['imul'](0xffffffff, 5) !== -5) Math['imul'] = function imul(a, b) {
  var ah  = a >>> 16;
  var al = a & 0xffff;
  var bh  = b >>> 16;
  var bl = b & 0xffff;
  return (al*bl + ((ah*bl + al*bh) << 16))|0;
};
Math.imul = Math['imul'];


if (!Math['clz32']) Math['clz32'] = function(x) {
  x = x >>> 0;
  for (var i = 0; i < 32; i++) {
    if (x & (1 << (31 - i))) return i;
  }
  return 32;
};
Math.clz32 = Math['clz32']

if (!Math['trunc']) Math['trunc'] = function(x) {
  return x < 0 ? Math.ceil(x) : Math.floor(x);
};
Math.trunc = Math['trunc'];

var Math_abs = Math.abs;
var Math_cos = Math.cos;
var Math_sin = Math.sin;
var Math_tan = Math.tan;
var Math_acos = Math.acos;
var Math_asin = Math.asin;
var Math_atan = Math.atan;
var Math_atan2 = Math.atan2;
var Math_exp = Math.exp;
var Math_log = Math.log;
var Math_sqrt = Math.sqrt;
var Math_ceil = Math.ceil;
var Math_floor = Math.floor;
var Math_pow = Math.pow;
var Math_imul = Math.imul;
var Math_fround = Math.fround;
var Math_round = Math.round;
var Math_min = Math.min;
var Math_clz32 = Math.clz32;
var Math_trunc = Math.trunc;

// A counter of dependencies for calling run(). If we need to
// do asynchronous work before running, increment this and
// decrement it. Incrementing must happen in a place like
// PRE_RUN_ADDITIONS (used by emcc to add file preloading).
// Note that you can add dependencies in preRun, even though
// it happens right before run - run will be postponed until
// the dependencies are met.
var runDependencies = 0;
var runDependencyWatcher = null;
var dependenciesFulfilled = null; // overridden to take different actions when all run dependencies are fulfilled
var runDependencyTracking = {};

function getUniqueRunDependency(id) {
  var orig = id;
  while (1) {
    if (!runDependencyTracking[id]) return id;
    id = orig + Math.random();
  }
  return id;
}

function addRunDependency(id) {
  runDependencies++;
  if (Module['monitorRunDependencies']) {
    Module['monitorRunDependencies'](runDependencies);
  }
  if (id) {
    assert(!runDependencyTracking[id]);
    runDependencyTracking[id] = 1;
    if (runDependencyWatcher === null && typeof setInterval !== 'undefined') {
      // Check for missing dependencies every few seconds
      runDependencyWatcher = setInterval(function() {
        if (ABORT) {
          clearInterval(runDependencyWatcher);
          runDependencyWatcher = null;
          return;
        }
        var shown = false;
        for (var dep in runDependencyTracking) {
          if (!shown) {
            shown = true;
            Module.printErr('still waiting on run dependencies:');
          }
          Module.printErr('dependency: ' + dep);
        }
        if (shown) {
          Module.printErr('(end of list)');
        }
      }, 10000);
    }
  } else {
    Module.printErr('warning: run dependency added without ID');
  }
}
Module["addRunDependency"] = addRunDependency;

function removeRunDependency(id) {
  runDependencies--;
  if (Module['monitorRunDependencies']) {
    Module['monitorRunDependencies'](runDependencies);
  }
  if (id) {
    assert(runDependencyTracking[id]);
    delete runDependencyTracking[id];
  } else {
    Module.printErr('warning: run dependency removed without ID');
  }
  if (runDependencies == 0) {
    if (runDependencyWatcher !== null) {
      clearInterval(runDependencyWatcher);
      runDependencyWatcher = null;
    }
    if (dependenciesFulfilled) {
      var callback = dependenciesFulfilled;
      dependenciesFulfilled = null;
      callback(); // can add another dependenciesFulfilled
    }
  }
}
Module["removeRunDependency"] = removeRunDependency;

Module["preloadedImages"] = {}; // maps url to image data
Module["preloadedAudios"] = {}; // maps url to audio data



var memoryInitializer = null;



var /* show errors on likely calls to FS when it was not included */ FS = {
  error: function() {
    abort('Filesystem support (FS) was not included. The problem is that you are using files from JS, but files were not used from C/C++, so filesystem support was not auto-included. You can force-include filesystem support with  -s FORCE_FILESYSTEM=1');
  },
  init: function() { FS.error() },
  createDataFile: function() { FS.error() },
  createPreloadedFile: function() { FS.error() },
  createLazyFile: function() { FS.error() },
  open: function() { FS.error() },
  mkdev: function() { FS.error() },
  registerDevice: function() { FS.error() },
  analyzePath: function() { FS.error() },
  loadFilesFromDB: function() { FS.error() },

  ErrnoError: function ErrnoError() { FS.error() },
};
Module['FS_createDataFile'] = FS.createDataFile;
Module['FS_createPreloadedFile'] = FS.createPreloadedFile;


// === Body ===

var ASM_CONSTS = [];




STATIC_BASE = 8;

STATICTOP = STATIC_BASE + 5280;
  /* global initializers */  __ATINIT__.push({ func: function() { __GLOBAL__sub_I_my_glue_wrapper_cpp() } });
  

/* memory initializer */ allocate([96,1,0,0,179,11,0,0,136,1,0,0,19,12,0,0,32,0,0,0,0,0,0,0,136,1,0,0,192,11,0,0,48,0,0,0,0,0,0,0,96,1,0,0,225,11,0,0,136,1,0,0,238,11,0,0,16,0,0,0,0,0,0,0,136,1,0,0,75,13,0,0,32,0,0,0,0,0,0,0,136,1,0,0,39,13,0,0,72,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,3,0,0,0,144,16,0,0,0,4,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,104,0,0,0,224,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,3,0,0,0,152,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,170,11,0,0,0,0,0,0,16,0,0,0,6,0,0,0,7,0,0,0,8,0,0,0,9,0,0,0,10,0,0,0,11,0,0,0,12,0,0,0,13,0,0,0,0,0,0,0,56,0,0,0,6,0,0,0,14,0,0,0,8,0,0,0,9,0,0,0,10,0,0,0,15,0,0,0,16,0,0,0,17,0,0,0,17,0,10,0,17,17,17,0,0,0,0,5,0,0,0,0,0,0,9,0,0,0,0,11,0,0,0,0,0,0,0,0,17,0,15,10,17,17,17,3,10,7,0,1,19,9,11,11,0,0,9,6,11,0,0,11,0,6,17,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,17,0,10,10,17,17,17,0,10,0,0,2,0,9,11,0,0,0,9,0,11,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,12,0,0,0,0,9,12,0,0,0,0,0,12,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,4,13,0,0,0,0,9,14,0,0,0,0,0,14,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,15,0,0,0,0,9,16,0,0,0,0,0,16,0,0,16,0,0,18,0,0,0,18,18,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,0,0,0,18,18,18,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,10,0,0,0,0,9,11,0,0,0,0,0,11,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,12,0,0,0,0,9,12,0,0,0,0,0,12,0,0,12,0,0,48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,45,43,32,32,32,48,88,48,120,0,40,110,117,108,108,41,0,45,48,88,43,48,88,32,48,88,45,48,120,43,48,120,32,48,120,0,105,110,102,0,73,78,70,0,110,97,110,0,78,65,78,0,46,0,84,33,34,25,13,1,2,3,17,75,28,12,16,4,11,29,18,30,39,104,110,111,112,113,98,32,5,6,15,19,20,21,26,8,22,7,40,36,23,24,9,10,14,27,31,37,35,131,130,125,38,42,43,60,61,62,63,67,71,74,77,88,89,90,91,92,93,94,95,96,97,99,100,101,102,103,105,106,107,108,114,115,116,121,122,123,124,0,73,108,108,101,103,97,108,32,98,121,116,101,32,115,101,113,117,101,110,99,101,0,68,111,109,97,105,110,32,101,114,114,111,114,0,82,101,115,117,108,116,32,110,111,116,32,114,101,112,114,101,115,101,110,116,97,98,108,101,0,78,111,116,32,97,32,116,116,121,0,80,101,114,109,105,115,115,105,111,110,32,100,101,110,105,101,100,0,79,112,101,114,97,116,105,111,110,32,110,111,116,32,112,101,114,109,105,116,116,101,100,0,78,111,32,115,117,99,104,32,102,105,108,101,32,111,114,32,100,105,114,101,99,116,111,114,121,0,78,111,32,115,117,99,104,32,112,114,111,99,101,115,115,0,70,105,108,101,32,101,120,105,115,116,115,0,86,97,108,117,101,32,116,111,111,32,108,97,114,103,101,32,102,111,114,32,100,97,116,97,32,116,121,112,101,0,78,111,32,115,112,97,99,101,32,108,101,102,116,32,111,110,32,100,101,118,105,99,101,0,79,117,116,32,111,102,32,109,101,109,111,114,121,0,82,101,115,111,117,114,99,101,32,98,117,115,121,0,73,110,116,101,114,114,117,112,116,101,100,32,115,121,115,116,101,109,32,99,97,108,108,0,82,101,115,111,117,114,99,101,32,116,101,109,112,111,114,97,114,105,108,121,32,117,110,97,118,97,105,108,97,98,108,101,0,73,110,118,97,108,105,100,32,115,101,101,107,0,67,114,111,115,115,45,100,101,118,105,99,101,32,108,105,110,107,0,82,101,97,100,45,111,110,108,121,32,102,105,108,101,32,115,121,115,116,101,109,0,68,105,114,101,99,116,111,114,121,32,110,111,116,32,101,109,112,116,121,0,67,111,110,110,101,99,116,105,111,110,32,114,101,115,101,116,32,98,121,32,112,101,101,114,0,79,112,101,114,97,116,105,111,110,32,116,105,109,101,100,32,111,117,116,0,67,111,110,110,101,99,116,105,111,110,32,114,101,102,117,115,101,100,0,72,111,115,116,32,105,115,32,100,111,119,110,0,72,111,115,116,32,105,115,32,117,110,114,101,97,99,104,97,98,108,101,0,65,100,100,114,101,115,115,32,105,110,32,117,115,101,0,66,114,111,107,101,110,32,112,105,112,101,0,73,47,79,32,101,114,114,111,114,0,78,111,32,115,117,99,104,32,100,101,118,105,99,101,32,111,114,32,97,100,100,114,101,115,115,0,66,108,111,99,107,32,100,101,118,105,99,101,32,114,101,113,117,105,114,101,100,0,78,111,32,115,117,99,104,32,100,101,118,105,99,101,0,78,111,116,32,97,32,100,105,114,101,99,116,111,114,121,0,73,115,32,97,32,100,105,114,101,99,116,111,114,121,0,84,101,120,116,32,102,105,108,101,32,98,117,115,121,0,69,120,101,99,32,102,111,114,109,97,116,32,101,114,114,111,114,0,73,110,118,97,108,105,100,32,97,114,103,117,109,101,110,116,0,65,114,103,117,109,101,110,116,32,108,105,115,116,32,116,111,111,32,108,111,110,103,0,83,121,109,98,111,108,105,99,32,108,105,110,107,32,108,111,111,112,0,70,105,108,101,110,97,109,101,32,116,111,111,32,108,111,110,103,0,84,111,111,32,109,97,110,121,32,111,112,101,110,32,102,105,108,101,115,32,105,110,32,115,121,115,116,101,109,0,78,111,32,102,105,108,101,32,100,101,115,99,114,105,112,116,111,114,115,32,97,118,97,105,108,97,98,108,101,0,66,97,100,32,102,105,108,101,32,100,101,115,99,114,105,112,116,111,114,0,78,111,32,99,104,105,108,100,32,112,114,111,99,101,115,115,0,66,97,100,32,97,100,100,114,101,115,115,0,70,105,108,101,32,116,111,111,32,108,97,114,103,101,0,84,111,111,32,109,97,110,121,32,108,105,110,107,115,0,78,111,32,108,111,99,107,115,32,97,118,97,105,108,97,98,108,101,0,82,101,115,111,117,114,99,101,32,100,101,97,100,108,111,99,107,32,119,111,117,108,100,32,111,99,99,117,114,0,83,116,97,116,101,32,110,111,116,32,114,101,99,111,118,101,114,97,98,108,101,0,80,114,101,118,105,111,117,115,32,111,119,110,101,114,32,100,105,101,100,0,79,112,101,114,97,116,105,111,110,32,99,97,110,99,101,108,101,100,0,70,117,110,99,116,105,111,110,32,110,111,116,32,105,109,112,108,101,109,101,110,116,101,100,0,78,111,32,109,101,115,115,97,103,101,32,111,102,32,100,101,115,105,114,101,100,32,116,121,112,101,0,73,100,101,110,116,105,102,105,101,114,32,114,101,109,111,118,101,100,0,68,101,118,105,99,101,32,110,111,116,32,97,32,115,116,114,101,97,109,0,78,111,32,100,97,116,97,32,97,118,97,105,108,97,98,108,101,0,68,101,118,105,99,101,32,116,105,109,101,111,117,116,0,79,117,116,32,111,102,32,115,116,114,101,97,109,115,32,114,101,115,111,117,114,99,101,115,0,76,105,110,107,32,104,97,115,32,98,101,101,110,32,115,101,118,101,114,101,100,0,80,114,111,116,111,99,111,108,32,101,114,114,111,114,0,66,97,100,32,109,101,115,115,97,103,101,0,70,105,108,101,32,100,101,115,99,114,105,112,116,111,114,32,105,110,32,98,97,100,32,115,116,97,116,101,0,78,111,116,32,97,32,115,111,99,107,101,116,0,68,101,115,116,105,110,97,116,105,111,110,32,97,100,100,114,101,115,115,32,114,101,113,117,105,114,101,100,0,77,101,115,115,97,103,101,32,116,111,111,32,108,97,114,103,101,0,80,114,111,116,111,99,111,108,32,119,114,111,110,103,32,116,121,112,101,32,102,111,114,32,115,111,99,107,101,116,0,80,114,111,116,111,99,111,108,32,110,111,116,32,97,118,97,105,108,97,98,108,101,0,80,114,111,116,111,99,111,108,32,110,111,116,32,115,117,112,112,111,114,116,101,100,0,83,111,99,107,101,116,32,116,121,112,101,32,110,111,116,32,115,117,112,112,111,114,116,101,100,0,78,111,116,32,115,117,112,112,111,114,116,101,100,0,80,114,111,116,111,99,111,108,32,102,97,109,105,108,121,32,110,111,116,32,115,117,112,112,111,114,116,101,100,0,65,100,100,114,101,115,115,32,102,97,109,105,108,121,32,110,111,116,32,115,117,112,112,111,114,116,101,100,32,98,121,32,112,114,111,116,111,99,111,108,0,65,100,100,114,101,115,115,32,110,111,116,32,97,118,97,105,108,97,98,108,101,0,78,101,116,119,111,114,107,32,105,115,32,100,111,119,110,0,78,101,116,119,111,114,107,32,117,110,114,101,97,99,104,97,98,108,101,0,67,111,110,110,101,99,116,105,111,110,32,114,101,115,101,116,32,98,121,32,110,101,116,119,111,114,107,0,67,111,110,110,101,99,116,105,111,110,32,97,98,111,114,116,101,100,0,78,111,32,98,117,102,102,101,114,32,115,112,97,99,101,32,97,118,97,105,108,97,98,108,101,0,83,111,99,107,101,116,32,105,115,32,99,111,110,110,101,99,116,101,100,0,83,111,99,107,101,116,32,110,111,116,32,99,111,110,110,101,99,116,101,100,0,67,97,110,110,111,116,32,115,101,110,100,32,97,102,116,101,114,32,115,111,99,107,101,116,32,115,104,117,116,100,111,119,110,0,79,112,101,114,97,116,105,111,110,32,97,108,114,101,97,100,121,32,105,110,32,112,114,111,103,114,101,115,115,0,79,112,101,114,97,116,105,111,110,32,105,110,32,112,114,111,103,114,101,115,115,0,83,116,97,108,101,32,102,105,108,101,32,104,97,110,100,108,101,0,82,101,109,111,116,101,32,73,47,79,32,101,114,114,111,114,0,81,117,111,116,97,32,101,120,99,101,101,100,101,100,0,78,111,32,109,101,100,105,117,109,32,102,111,117,110,100,0,87,114,111,110,103,32,109,101,100,105,117,109,32,116,121,112,101,0,78,111,32,101,114,114,111,114,32,105,110,102,111,114,109,97,116,105,111,110,0,0,116,101,114,109,105,110,97,116,105,110,103,32,119,105,116,104,32,37,115,32,101,120,99,101,112,116,105,111,110,32,111,102,32,116,121,112,101,32,37,115,58,32,37,115,0,116,101,114,109,105,110,97,116,105,110,103,32,119,105,116,104,32,37,115,32,101,120,99,101,112,116,105,111,110,32,111,102,32,116,121,112,101,32,37,115,0,116,101,114,109,105,110,97,116,105,110,103,32,119,105,116,104,32,37,115,32,102,111,114,101,105,103,110,32,101,120,99,101,112,116,105,111,110,0,116,101,114,109,105,110,97,116,105,110,103,0,117,110,99,97,117,103,104,116,0,83,116,57,101,120,99,101,112,116,105,111,110,0,78,49,48,95,95,99,120,120,97,98,105,118,49,49,54,95,95,115,104,105,109,95,116,121,112,101,95,105,110,102,111,69,0,83,116,57,116,121,112,101,95,105,110,102,111,0,78,49,48,95,95,99,120,120,97,98,105,118,49,50,48,95,95,115,105,95,99,108,97,115,115,95,116,121,112,101,95,105,110,102,111,69,0,78,49,48,95,95,99,120,120,97,98,105,118,49,49,55,95,95,99,108,97,115,115,95,116,121,112,101,95,105,110,102,111,69,0,112,116,104,114,101,97,100,95,111,110,99,101,32,102,97,105,108,117,114,101,32,105,110,32,95,95,99,120,97,95,103,101,116,95,103,108,111,98,97,108,115,95,102,97,115,116,40,41,0,99,97,110,110,111,116,32,99,114,101,97,116,101,32,112,116,104,114,101,97,100,32,107,101,121,32,102,111,114,32,95,95,99,120,97,95,103,101,116,95,103,108,111,98,97,108,115,40,41,0,99,97,110,110,111,116,32,122,101,114,111,32,111,117,116,32,116,104,114,101,97,100,32,118,97,108,117,101,32,102,111,114,32,95,95,99,120,97,95,103,101,116,95,103,108,111,98,97,108,115,40,41,0,116,101,114,109,105,110,97,116,101,95,104,97,110,100,108,101,114,32,117,110,101,120,112,101,99,116,101,100,108,121,32,114,101,116,117,114,110,101,100,0,116,101,114,109,105,110,97,116,101,95,104,97,110,100,108,101,114,32,117,110,101,120,112,101,99,116,101,100,108,121,32,116,104,114,101,119,32,97,110,32,101,120,99,101,112,116,105,111,110,0,78,49,48,95,95,99,120,120,97,98,105,118,49,49,57,95,95,112,111,105,110,116,101,114,95,116,121,112,101,95,105,110,102,111,69,0,78,49,48,95,95,99,120,120,97,98,105,118,49,49,55,95,95,112,98,97,115,101,95,116,121,112,101,95,105,110,102,111,69,0], "i8", ALLOC_NONE, Runtime.GLOBAL_BASE);





/* no memory initializer */
var tempDoublePtr = STATICTOP; STATICTOP += 16;

assert(tempDoublePtr % 8 == 0);

function copyTempFloat(ptr) { // functions, because inlining this code increases code size too much

  HEAP8[tempDoublePtr] = HEAP8[ptr];

  HEAP8[tempDoublePtr+1] = HEAP8[ptr+1];

  HEAP8[tempDoublePtr+2] = HEAP8[ptr+2];

  HEAP8[tempDoublePtr+3] = HEAP8[ptr+3];

}

function copyTempDouble(ptr) {

  HEAP8[tempDoublePtr] = HEAP8[ptr];

  HEAP8[tempDoublePtr+1] = HEAP8[ptr+1];

  HEAP8[tempDoublePtr+2] = HEAP8[ptr+2];

  HEAP8[tempDoublePtr+3] = HEAP8[ptr+3];

  HEAP8[tempDoublePtr+4] = HEAP8[ptr+4];

  HEAP8[tempDoublePtr+5] = HEAP8[ptr+5];

  HEAP8[tempDoublePtr+6] = HEAP8[ptr+6];

  HEAP8[tempDoublePtr+7] = HEAP8[ptr+7];

}

// {{PRE_LIBRARY}}


   
  Module["_i64Subtract"] = _i64Subtract;

  function __ZN17CUnitScriptEngine4TickEi() {
  Module['printErr']('missing function: _ZN17CUnitScriptEngine4TickEi'); abort(-1);
  }

   
  Module["_i64Add"] = _i64Add;

  function __ZN18CExtractorBuilding26SetExtractionRangeAndDepthEff() {
  Module['printErr']('missing function: _ZN18CExtractorBuilding26SetExtractionRangeAndDepthEff'); abort(-1);
  }

  function __ZN13CGlobalSynced10ResetStateEv() {
  Module['printErr']('missing function: _ZN13CGlobalSynced10ResetStateEv'); abort(-1);
  }

  function __ZN7CCannon11UpdateRangeEf() {
  Module['printErr']('missing function: _ZN7CCannon11UpdateRangeEf'); abort(-1);
  }

  function __ZN18CExtractorBuilding15ResetExtractionEv() {
  Module['printErr']('missing function: _ZN18CExtractorBuilding15ResetExtractionEv'); abort(-1);
  }

  
  
  function _free() {
  }
  Module["_free"] = _free;function ___cxa_free_exception(ptr) {
      try {
        return _free(ptr);
      } catch(e) { // XXX FIXME
        Module.printErr('exception during cxa_free_exception: ' + e);
      }
    }
  
  var EXCEPTIONS={last:0,caught:[],infos:{},deAdjust:function (adjusted) {
        if (!adjusted || EXCEPTIONS.infos[adjusted]) return adjusted;
        for (var ptr in EXCEPTIONS.infos) {
          var info = EXCEPTIONS.infos[ptr];
          if (info.adjusted === adjusted) {
            return ptr;
          }
        }
        return adjusted;
      },addRef:function (ptr) {
        if (!ptr) return;
        var info = EXCEPTIONS.infos[ptr];
        info.refcount++;
      },decRef:function (ptr) {
        if (!ptr) return;
        var info = EXCEPTIONS.infos[ptr];
        assert(info.refcount > 0);
        info.refcount--;
        // A rethrown exception can reach refcount 0; it must not be discarded
        // Its next handler will clear the rethrown flag and addRef it, prior to
        // final decRef and destruction here
        if (info.refcount === 0 && !info.rethrown) {
          if (info.destructor) {
            Runtime.dynCall('vi', info.destructor, [ptr]);
          }
          delete EXCEPTIONS.infos[ptr];
          ___cxa_free_exception(ptr);
        }
      },clearRef:function (ptr) {
        if (!ptr) return;
        var info = EXCEPTIONS.infos[ptr];
        info.refcount = 0;
      }};function ___cxa_end_catch() {
      // Clear state flag.
      asm['setThrew'](0);
      // Call destructor if one is registered then clear it.
      var ptr = EXCEPTIONS.caught.pop();
      if (ptr) {
        EXCEPTIONS.decRef(EXCEPTIONS.deAdjust(ptr));
        EXCEPTIONS.last = 0; // XXX in decRef?
      }
    }

  function __ZNK7CCannon10GetRange2DEf() {
  Module['printErr']('missing function: _ZNK7CCannon10GetRange2DEf'); abort(-1);
  }

  function __ZN10CMobileCAI9NonMovingEv() {
  Module['printErr']('missing function: _ZN10CMobileCAI9NonMovingEv'); abort(-1);
  }

  function __ZN10CMobileCAI14StartSlowGuardEf() {
  Module['printErr']('missing function: _ZN10CMobileCAI14StartSlowGuardEf'); abort(-1);
  }

  function __ZN14DynDamageArrayD1Ev() {
  Module['printErr']('missing function: _ZN14DynDamageArrayD1Ev'); abort(-1);
  }

  function __ZN25CCustomExplosionGenerator18GetFlagsFromHeightEff() {
  Module['printErr']('missing function: _ZN25CCustomExplosionGenerator18GetFlagsFromHeightEff'); abort(-1);
  }

  function __ZN26CExplosionGeneratorHandlerD1Ev() {
  Module['printErr']('missing function: _ZN26CExplosionGeneratorHandlerD1Ev'); abort(-1);
  }

  function __ZN8CBuilder12StartRestoreE6float3f() {
  Module['printErr']('missing function: _ZN8CBuilder12StartRestoreE6float3f'); abort(-1);
  }

  
  var PTHREAD_SPECIFIC={};
  
  var PTHREAD_SPECIFIC_NEXT_KEY=1;
  
  var ERRNO_CODES={EPERM:1,ENOENT:2,ESRCH:3,EINTR:4,EIO:5,ENXIO:6,E2BIG:7,ENOEXEC:8,EBADF:9,ECHILD:10,EAGAIN:11,EWOULDBLOCK:11,ENOMEM:12,EACCES:13,EFAULT:14,ENOTBLK:15,EBUSY:16,EEXIST:17,EXDEV:18,ENODEV:19,ENOTDIR:20,EISDIR:21,EINVAL:22,ENFILE:23,EMFILE:24,ENOTTY:25,ETXTBSY:26,EFBIG:27,ENOSPC:28,ESPIPE:29,EROFS:30,EMLINK:31,EPIPE:32,EDOM:33,ERANGE:34,ENOMSG:42,EIDRM:43,ECHRNG:44,EL2NSYNC:45,EL3HLT:46,EL3RST:47,ELNRNG:48,EUNATCH:49,ENOCSI:50,EL2HLT:51,EDEADLK:35,ENOLCK:37,EBADE:52,EBADR:53,EXFULL:54,ENOANO:55,EBADRQC:56,EBADSLT:57,EDEADLOCK:35,EBFONT:59,ENOSTR:60,ENODATA:61,ETIME:62,ENOSR:63,ENONET:64,ENOPKG:65,EREMOTE:66,ENOLINK:67,EADV:68,ESRMNT:69,ECOMM:70,EPROTO:71,EMULTIHOP:72,EDOTDOT:73,EBADMSG:74,ENOTUNIQ:76,EBADFD:77,EREMCHG:78,ELIBACC:79,ELIBBAD:80,ELIBSCN:81,ELIBMAX:82,ELIBEXEC:83,ENOSYS:38,ENOTEMPTY:39,ENAMETOOLONG:36,ELOOP:40,EOPNOTSUPP:95,EPFNOSUPPORT:96,ECONNRESET:104,ENOBUFS:105,EAFNOSUPPORT:97,EPROTOTYPE:91,ENOTSOCK:88,ENOPROTOOPT:92,ESHUTDOWN:108,ECONNREFUSED:111,EADDRINUSE:98,ECONNABORTED:103,ENETUNREACH:101,ENETDOWN:100,ETIMEDOUT:110,EHOSTDOWN:112,EHOSTUNREACH:113,EINPROGRESS:115,EALREADY:114,EDESTADDRREQ:89,EMSGSIZE:90,EPROTONOSUPPORT:93,ESOCKTNOSUPPORT:94,EADDRNOTAVAIL:99,ENETRESET:102,EISCONN:106,ENOTCONN:107,ETOOMANYREFS:109,EUSERS:87,EDQUOT:122,ESTALE:116,ENOTSUP:95,ENOMEDIUM:123,EILSEQ:84,EOVERFLOW:75,ECANCELED:125,ENOTRECOVERABLE:131,EOWNERDEAD:130,ESTRPIPE:86};function _pthread_key_create(key, destructor) {
      if (key == 0) {
        return ERRNO_CODES.EINVAL;
      }
      HEAP32[((key)>>2)]=PTHREAD_SPECIFIC_NEXT_KEY;
      // values start at 0
      PTHREAD_SPECIFIC[PTHREAD_SPECIFIC_NEXT_KEY] = 0;
      PTHREAD_SPECIFIC_NEXT_KEY++;
      return 0;
    }

  function __ZN10CMobileCAI24StopMoveAndFinishCommandEv() {
  Module['printErr']('missing function: _ZN10CMobileCAI24StopMoveAndFinishCommandEv'); abort(-1);
  }

  function __ZN25CCustomExplosionGenerator25OutputProjectileClassInfoEv() {
  Module['printErr']('missing function: _ZN25CCustomExplosionGenerator25OutputProjectileClassInfoEv'); abort(-1);
  }

  function __ZN15CScriptMoveType13SetNoBlockingEb() {
  Module['printErr']('missing function: _ZN15CScriptMoveType13SetNoBlockingEb'); abort(-1);
  }

  
  var SYSCALLS={varargs:0,get:function (varargs) {
        SYSCALLS.varargs += 4;
        var ret = HEAP32[(((SYSCALLS.varargs)-(4))>>2)];
        return ret;
      },getStr:function () {
        var ret = Pointer_stringify(SYSCALLS.get());
        return ret;
      },get64:function () {
        var low = SYSCALLS.get(), high = SYSCALLS.get();
        if (low >= 0) assert(high === 0);
        else assert(high === -1);
        return low;
      },getZero:function () {
        assert(SYSCALLS.get() === 0);
      }};function ___syscall54(which, varargs) {SYSCALLS.varargs = varargs;
  try {
   // ioctl
      return 0;
    } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return -e.errno;
  }
  }

   
  Module["_bitshift64Lshr"] = _bitshift64Lshr;

   
  Module["_memset"] = _memset;

  function __ZN7CCannon10SlowUpdateEv() {
  Module['printErr']('missing function: _ZN7CCannon10SlowUpdateEv'); abort(-1);
  }

  function __ZN15CScriptMoveType12ForceUpdatesEv() {
  Module['printErr']('missing function: _ZN15CScriptMoveType12ForceUpdatesEv'); abort(-1);
  }

  function _pthread_cleanup_push(routine, arg) {
      __ATEXIT__.push(function() { Runtime.dynCall('vi', routine, [arg]) })
      _pthread_cleanup_push.level = __ATEXIT__.length;
    }

  function __ZN15CScriptMoveType10SetHeadingEs() {
  Module['printErr']('missing function: _ZN15CScriptMoveType10SetHeadingEs'); abort(-1);
  }

  function _pthread_cleanup_pop() {
      assert(_pthread_cleanup_push.level == __ATEXIT__.length, 'cannot pop if something else added meanwhile!');
      __ATEXIT__.pop();
      _pthread_cleanup_push.level = __ATEXIT__.length;
    }

  function ___cxa_find_matching_catch_3() {
          return ___cxa_find_matching_catch.apply(null, arguments);
        }

  function __ZN13CGlobalSyncedD1Ev() {
  Module['printErr']('missing function: _ZN13CGlobalSyncedD1Ev'); abort(-1);
  }

  function __ZN18CFeatureDefHandler22LoadFeatureDefsFromMapEv() {
  Module['printErr']('missing function: _ZN18CFeatureDefHandler22LoadFeatureDefsFromMapEv'); abort(-1);
  }

  function __ZN11CBuilderCAI10InitStaticEv() {
  Module['printErr']('missing function: _ZN11CBuilderCAI10InitStaticEv'); abort(-1);
  }

  
  function _emscripten_memcpy_big(dest, src, num) {
      HEAPU8.set(HEAPU8.subarray(src, src+num), dest);
      return dest;
    } 
  Module["_memcpy"] = _memcpy;

  function __ZNK6float36equalsERKS_S1_() {
  Module['printErr']('missing function: _ZNK6float36equalsERKS_S1_'); abort(-1);
  }

  function __ZN14CPathEstimator6UpdateEv() {
  Module['printErr']('missing function: _ZN14CPathEstimator6UpdateEv'); abort(-1);
  }

  
  function ___setErrNo(value) {
      if (Module['___errno_location']) HEAP32[((Module['___errno_location']())>>2)]=value;
      else Module.printErr('failed to set errno from JS');
      return value;
    } 
  Module["_sbrk"] = _sbrk;

  
  function __ZSt18uncaught_exceptionv() { // std::uncaught_exception()
      return !!__ZSt18uncaught_exceptionv.uncaught_exception;
    }function ___cxa_begin_catch(ptr) {
      var info = EXCEPTIONS.infos[ptr];
      if (info && !info.caught) {
        info.caught = true;
        __ZSt18uncaught_exceptionv.uncaught_exception--;
      }
      if (info) info.rethrown = false;
      EXCEPTIONS.caught.push(ptr);
      EXCEPTIONS.addRef(EXCEPTIONS.deAdjust(ptr));
      return ptr;
    }

  
  
  function ___resumeException(ptr) {
      if (!EXCEPTIONS.last) { EXCEPTIONS.last = ptr; }
      throw ptr;
    }function ___cxa_find_matching_catch() {
      var thrown = EXCEPTIONS.last;
      if (!thrown) {
        // just pass through the null ptr
        return ((asm["setTempRet0"](0),0)|0);
      }
      var info = EXCEPTIONS.infos[thrown];
      var throwntype = info.type;
      if (!throwntype) {
        // just pass through the thrown ptr
        return ((asm["setTempRet0"](0),thrown)|0);
      }
      var typeArray = Array.prototype.slice.call(arguments);
  
      var pointer = Module['___cxa_is_pointer_type'](throwntype);
      // can_catch receives a **, add indirection
      if (!___cxa_find_matching_catch.buffer) ___cxa_find_matching_catch.buffer = _malloc(4);
      HEAP32[((___cxa_find_matching_catch.buffer)>>2)]=thrown;
      thrown = ___cxa_find_matching_catch.buffer;
      // The different catch blocks are denoted by different types.
      // Due to inheritance, those types may not precisely match the
      // type of the thrown object. Find one which matches, and
      // return the type of the catch block which should be called.
      for (var i = 0; i < typeArray.length; i++) {
        if (typeArray[i] && Module['___cxa_can_catch'](typeArray[i], throwntype, thrown)) {
          thrown = HEAP32[((thrown)>>2)]; // undo indirection
          info.adjusted = thrown;
          return ((asm["setTempRet0"](typeArray[i]),thrown)|0);
        }
      }
      // Shouldn't happen unless we have bogus data in typeArray
      // or encounter a type for which emscripten doesn't have suitable
      // typeinfo defined. Best-efforts match just in case.
      thrown = HEAP32[((thrown)>>2)]; // undo indirection
      return ((asm["setTempRet0"](throwntype),thrown)|0);
    }function ___gxx_personality_v0() {
    }

  
  
  var cttz_i8 = allocate([8,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,6,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,7,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,6,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0], "i8", ALLOC_STATIC); 
  Module["_llvm_cttz_i32"] = _llvm_cttz_i32; 
  Module["___udivmoddi4"] = ___udivmoddi4; 
  Module["___uremdi3"] = ___uremdi3;

  function __ZN17CGeometricObjects11DeleteGroupEi() {
  Module['printErr']('missing function: _ZN17CGeometricObjects11DeleteGroupEi'); abort(-1);
  }

  function __ZN17CGeometricObjects8SetColorEiffff() {
  Module['printErr']('missing function: _ZN17CGeometricObjects8SetColorEiffff'); abort(-1);
  }

  function __ZN17CGeometricObjects10MarkSquareEi() {
  Module['printErr']('missing function: _ZN17CGeometricObjects10MarkSquareEi'); abort(-1);
  }

  function __ZN17CGeometricObjects6UpdateEv() {
  Module['printErr']('missing function: _ZN17CGeometricObjects6UpdateEv'); abort(-1);
  }

  function __ZN26CExplosionGeneratorHandler20ParseExplosionTablesEv() {
  Module['printErr']('missing function: _ZN26CExplosionGeneratorHandler20ParseExplosionTablesEv'); abort(-1);
  }

  function __ZN17CUnitScriptEngine10InitStaticEv() {
  Module['printErr']('missing function: _ZN17CUnitScriptEngine10InitStaticEv'); abort(-1);
  }

  function __ZN7CCannon4InitEv() {
  Module['printErr']('missing function: _ZN7CCannon4InitEv'); abort(-1);
  }

  function __ZN10CMobileCAI13StopSlowGuardEv() {
  Module['printErr']('missing function: _ZN10CMobileCAI13StopSlowGuardEv'); abort(-1);
  }

  function __ZN8CFactory9StopBuildEv() {
  Module['printErr']('missing function: _ZN8CFactory9StopBuildEv'); abort(-1);
  }

  function __ZN8CModInfo10ResetStateEv() {
  Module['printErr']('missing function: _ZN8CModInfo10ResetStateEv'); abort(-1);
  }

  function __ZN15CUnitDefHandler4InitEv() {
  Module['printErr']('missing function: _ZN15CUnitDefHandler4InitEv'); abort(-1);
  }

  function __ZN11CBuilderCAI8PostLoadEv() {
  Module['printErr']('missing function: _ZN11CBuilderCAI8PostLoadEv'); abort(-1);
  }

   
  Module["_bitshift64Shl"] = _bitshift64Shl;

  function _abort() {
      Module['abort']();
    }

  function _pthread_once(ptr, func) {
      if (!_pthread_once.seen) _pthread_once.seen = {};
      if (ptr in _pthread_once.seen) return;
      Runtime.dynCall('v', func);
      _pthread_once.seen[ptr] = 1;
    }

  function __ZN17CGeometricObjectsD1Ev() {
  Module['printErr']('missing function: _ZN17CGeometricObjectsD1Ev'); abort(-1);
  }

  function ___unlock() {}

  function _pthread_getspecific(key) {
      return PTHREAD_SPECIFIC[key] || 0;
    }

  function __ZNK20CResourceMapAnalyzer16GetAverageIncomeEv() {
  Module['printErr']('missing function: _ZNK20CResourceMapAnalyzer16GetAverageIncomeEv'); abort(-1);
  }

  function __ZN17CCollisionHandler10PrintStatsEv() {
  Module['printErr']('missing function: _ZN17CCollisionHandler10PrintStatsEv'); abort(-1);
  }

  function ___lock() {}

  function __ZN8CFactory18CreateNanoParticleEb() {
  Module['printErr']('missing function: _ZN8CFactory18CreateNanoParticleEb'); abort(-1);
  }

  function _pthread_setspecific(key, value) {
      if (!(key in PTHREAD_SPECIFIC)) {
        return ERRNO_CODES.EINVAL;
      }
      PTHREAD_SPECIFIC[key] = value;
      return 0;
    }

  function __ZN18CFeatureDefHandlerD1Ev() {
  Module['printErr']('missing function: _ZN18CFeatureDefHandlerD1Ev'); abort(-1);
  }

  function __ZN7CCannon15UpdateWantedDirEv() {
  Module['printErr']('missing function: _ZN7CCannon15UpdateWantedDirEv'); abort(-1);
  }

  function __ZN15CollisionVolume17SetBoundingRadiusEv() {
  Module['printErr']('missing function: _ZN15CollisionVolume17SetBoundingRadiusEv'); abort(-1);
  }

  function __ZN18CExtractorBuilding26ReCalculateMetalExtractionEv() {
  Module['printErr']('missing function: _ZN18CExtractorBuilding26ReCalculateMetalExtractionEv'); abort(-1);
  }

  function __ZN17CGeometricObjects9AddSplineE6float3S0_S0_S0_fiii() {
  Module['printErr']('missing function: _ZN17CGeometricObjects9AddSplineE6float3S0_S0_S0_fiii'); abort(-1);
  }

  function __ZN15CUnitDefHandler13ProcessDecoysEv() {
  Module['printErr']('missing function: _ZN15CUnitDefHandler13ProcessDecoysEv'); abort(-1);
  }

  function __ZN15CollisionVolume8PostLoadEv() {
  Module['printErr']('missing function: _ZN15CollisionVolume8PostLoadEv'); abort(-1);
  }

  function __ZN15CUnitDefHandler12ToggleNoCostEv() {
  Module['printErr']('missing function: _ZN15CUnitDefHandler12ToggleNoCostEv'); abort(-1);
  }

  function __ZN15CUnitDefHandler16AssignTechLevelsEv() {
  Module['printErr']('missing function: _ZN15CUnitDefHandler16AssignTechLevelsEv'); abort(-1);
  }

  function ___syscall6(which, varargs) {SYSCALLS.varargs = varargs;
  try {
   // close
      var stream = SYSCALLS.getStreamFromFD();
      FS.close(stream);
      return 0;
    } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return -e.errno;
  }
  }

   
  Module["___udivdi3"] = ___udivdi3;

  
   
  Module["___muldsi3"] = ___muldsi3; 
  Module["___muldi3"] = ___muldi3;

  function __ZN17CGeometricObjects7AddLineE6float3S0_fiii() {
  Module['printErr']('missing function: _ZN17CGeometricObjects7AddLineE6float3S0_fiii'); abort(-1);
  }

  function __ZN17CUnitScriptEngine10KillStaticEv() {
  Module['printErr']('missing function: _ZN17CUnitScriptEngine10KillStaticEv'); abort(-1);
  }

  function __ZN14CPathEstimator10MapChangedEjjjj() {
  Module['printErr']('missing function: _ZN14CPathEstimator10MapChangedEjjjj'); abort(-1);
  }

  function __ZN8CBuilder9StopBuildEb() {
  Module['printErr']('missing function: _ZN8CBuilder9StopBuildEb'); abort(-1);
  }

  function __ZNK7CCannon10GetRange2DEff() {
  Module['printErr']('missing function: _ZNK7CCannon10GetRange2DEff'); abort(-1);
  }

   
  Module["_pthread_self"] = _pthread_self;

  function ___syscall140(which, varargs) {SYSCALLS.varargs = varargs;
  try {
   // llseek
      var stream = SYSCALLS.getStreamFromFD(), offset_high = SYSCALLS.get(), offset_low = SYSCALLS.get(), result = SYSCALLS.get(), whence = SYSCALLS.get();
      var offset = offset_low;
      assert(offset_high === 0);
      FS.llseek(stream, offset, whence);
      HEAP32[((result)>>2)]=stream.position;
      if (stream.getdents && offset === 0 && whence === 0) stream.getdents = null; // reset readdir state
      return 0;
    } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return -e.errno;
  }
  }

  function ___syscall146(which, varargs) {SYSCALLS.varargs = varargs;
  try {
   // writev
      // hack to support printf in NO_FILESYSTEM
      var stream = SYSCALLS.get(), iov = SYSCALLS.get(), iovcnt = SYSCALLS.get();
      var ret = 0;
      if (!___syscall146.buffer) {
        ___syscall146.buffers = [null, [], []]; // 1 => stdout, 2 => stderr
        ___syscall146.printChar = function(stream, curr) {
          var buffer = ___syscall146.buffers[stream];
          assert(buffer);
          if (curr === 0 || curr === 10) {
            (stream === 1 ? Module['print'] : Module['printErr'])(UTF8ArrayToString(buffer, 0));
            buffer.length = 0;
          } else {
            buffer.push(curr);
          }
        };
      }
      for (var i = 0; i < iovcnt; i++) {
        var ptr = HEAP32[(((iov)+(i*8))>>2)];
        var len = HEAP32[(((iov)+(i*8 + 4))>>2)];
        for (var j = 0; j < len; j++) {
          ___syscall146.printChar(stream, HEAPU8[ptr+j]);
        }
        ret += len;
      }
      return ret;
    } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return -e.errno;
  }
  }

  function __ZN8CBuilder19ScriptStartBuildingE6float3b() {
  Module['printErr']('missing function: _ZN8CBuilder19ScriptStartBuildingE6float3b'); abort(-1);
  }

  function __ZN15CollisionVolume9InitShapeERK6float3S2_iii() {
  Module['printErr']('missing function: _ZN15CollisionVolume9InitShapeERK6float3S2_iii'); abort(-1);
  }
/* flush anything remaining in the buffer during shutdown */ __ATEXIT__.push(function() { var fflush = Module["_fflush"]; if (fflush) fflush(0); var printChar = ___syscall146.printChar; if (!printChar) return; var buffers = ___syscall146.buffers; if (buffers[1].length) printChar(1, 10); if (buffers[2].length) printChar(2, 10); });;
DYNAMICTOP_PTR = allocate(1, "i32", ALLOC_STATIC);

STACK_BASE = STACKTOP = Runtime.alignMemory(STATICTOP);

STACK_MAX = STACK_BASE + TOTAL_STACK;

DYNAMIC_BASE = Runtime.alignMemory(STACK_MAX);

HEAP32[DYNAMICTOP_PTR>>2] = DYNAMIC_BASE;

staticSealed = true; // seal the static portion of memory

assert(DYNAMIC_BASE < TOTAL_MEMORY, "TOTAL_MEMORY not big enough for stack");



function nullFunc_iiii(x) { Module["printErr"]("Invalid function pointer called with signature 'iiii'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_vid(x) { Module["printErr"]("Invalid function pointer called with signature 'vid'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_viiiii(x) { Module["printErr"]("Invalid function pointer called with signature 'viiiii'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_i(x) { Module["printErr"]("Invalid function pointer called with signature 'i'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_vi(x) { Module["printErr"]("Invalid function pointer called with signature 'vi'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_vii(x) { Module["printErr"]("Invalid function pointer called with signature 'vii'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_vidd(x) { Module["printErr"]("Invalid function pointer called with signature 'vidd'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_ii(x) { Module["printErr"]("Invalid function pointer called with signature 'ii'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_viidi(x) { Module["printErr"]("Invalid function pointer called with signature 'viidi'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_viidd(x) { Module["printErr"]("Invalid function pointer called with signature 'viidd'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_v(x) { Module["printErr"]("Invalid function pointer called with signature 'v'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_viid(x) { Module["printErr"]("Invalid function pointer called with signature 'viid'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_viiiiii(x) { Module["printErr"]("Invalid function pointer called with signature 'viiiiii'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_iii(x) { Module["printErr"]("Invalid function pointer called with signature 'iii'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_viiii(x) { Module["printErr"]("Invalid function pointer called with signature 'viiii'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function invoke_iiii(index,a1,a2,a3) {
  try {
    return Module["dynCall_iiii"](index,a1,a2,a3);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_vid(index,a1,a2) {
  try {
    Module["dynCall_vid"](index,a1,a2);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_viiiii(index,a1,a2,a3,a4,a5) {
  try {
    Module["dynCall_viiiii"](index,a1,a2,a3,a4,a5);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_i(index) {
  try {
    return Module["dynCall_i"](index);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_vi(index,a1) {
  try {
    Module["dynCall_vi"](index,a1);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_vii(index,a1,a2) {
  try {
    Module["dynCall_vii"](index,a1,a2);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_vidd(index,a1,a2,a3) {
  try {
    Module["dynCall_vidd"](index,a1,a2,a3);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_ii(index,a1) {
  try {
    return Module["dynCall_ii"](index,a1);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_viidi(index,a1,a2,a3,a4) {
  try {
    Module["dynCall_viidi"](index,a1,a2,a3,a4);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_viidd(index,a1,a2,a3,a4) {
  try {
    Module["dynCall_viidd"](index,a1,a2,a3,a4);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_v(index) {
  try {
    Module["dynCall_v"](index);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_viid(index,a1,a2,a3) {
  try {
    Module["dynCall_viid"](index,a1,a2,a3);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_viiiiii(index,a1,a2,a3,a4,a5,a6) {
  try {
    Module["dynCall_viiiiii"](index,a1,a2,a3,a4,a5,a6);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_iii(index,a1,a2) {
  try {
    return Module["dynCall_iii"](index,a1,a2);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

function invoke_viiii(index,a1,a2,a3,a4) {
  try {
    Module["dynCall_viiii"](index,a1,a2,a3,a4);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    asm["setThrew"](1, 0);
  }
}

Module.asmGlobalArg = { "Math": Math, "Int8Array": Int8Array, "Int16Array": Int16Array, "Int32Array": Int32Array, "Uint8Array": Uint8Array, "Uint16Array": Uint16Array, "Uint32Array": Uint32Array, "Float32Array": Float32Array, "Float64Array": Float64Array, "NaN": NaN, "Infinity": Infinity };

Module.asmLibraryArg = { "abort": abort, "assert": assert, "enlargeMemory": enlargeMemory, "getTotalMemory": getTotalMemory, "abortOnCannotGrowMemory": abortOnCannotGrowMemory, "abortStackOverflow": abortStackOverflow, "nullFunc_iiii": nullFunc_iiii, "nullFunc_vid": nullFunc_vid, "nullFunc_viiiii": nullFunc_viiiii, "nullFunc_i": nullFunc_i, "nullFunc_vi": nullFunc_vi, "nullFunc_vii": nullFunc_vii, "nullFunc_vidd": nullFunc_vidd, "nullFunc_ii": nullFunc_ii, "nullFunc_viidi": nullFunc_viidi, "nullFunc_viidd": nullFunc_viidd, "nullFunc_v": nullFunc_v, "nullFunc_viid": nullFunc_viid, "nullFunc_viiiiii": nullFunc_viiiiii, "nullFunc_iii": nullFunc_iii, "nullFunc_viiii": nullFunc_viiii, "invoke_iiii": invoke_iiii, "invoke_vid": invoke_vid, "invoke_viiiii": invoke_viiiii, "invoke_i": invoke_i, "invoke_vi": invoke_vi, "invoke_vii": invoke_vii, "invoke_vidd": invoke_vidd, "invoke_ii": invoke_ii, "invoke_viidi": invoke_viidi, "invoke_viidd": invoke_viidd, "invoke_v": invoke_v, "invoke_viid": invoke_viid, "invoke_viiiiii": invoke_viiiiii, "invoke_iii": invoke_iii, "invoke_viiii": invoke_viiii, "_pthread_cleanup_pop": _pthread_cleanup_pop, "__ZN17CUnitScriptEngine10KillStaticEv": __ZN17CUnitScriptEngine10KillStaticEv, "__ZN18CFeatureDefHandler22LoadFeatureDefsFromMapEv": __ZN18CFeatureDefHandler22LoadFeatureDefsFromMapEv, "__ZN17CUnitScriptEngine4TickEi": __ZN17CUnitScriptEngine4TickEi, "__ZN8CBuilder9StopBuildEb": __ZN8CBuilder9StopBuildEb, "__ZN8CFactory9StopBuildEv": __ZN8CFactory9StopBuildEv, "___syscall54": ___syscall54, "__ZN15CUnitDefHandler4InitEv": __ZN15CUnitDefHandler4InitEv, "__ZN10CMobileCAI14StartSlowGuardEf": __ZN10CMobileCAI14StartSlowGuardEf, "__ZN13CGlobalSynced10ResetStateEv": __ZN13CGlobalSynced10ResetStateEv, "__ZN18CExtractorBuilding26ReCalculateMetalExtractionEv": __ZN18CExtractorBuilding26ReCalculateMetalExtractionEv, "___syscall6": ___syscall6, "__ZN17CCollisionHandler10PrintStatsEv": __ZN17CCollisionHandler10PrintStatsEv, "__ZN18CFeatureDefHandlerD1Ev": __ZN18CFeatureDefHandlerD1Ev, "___gxx_personality_v0": ___gxx_personality_v0, "__ZN17CGeometricObjects11DeleteGroupEi": __ZN17CGeometricObjects11DeleteGroupEi, "___unlock": ___unlock, "__ZN15CScriptMoveType10SetHeadingEs": __ZN15CScriptMoveType10SetHeadingEs, "__ZNK7CCannon10GetRange2DEf": __ZNK7CCannon10GetRange2DEf, "___cxa_free_exception": ___cxa_free_exception, "__ZSt18uncaught_exceptionv": __ZSt18uncaught_exceptionv, "__ZN15CScriptMoveType13SetNoBlockingEb": __ZN15CScriptMoveType13SetNoBlockingEb, "__ZN17CGeometricObjectsD1Ev": __ZN17CGeometricObjectsD1Ev, "__ZN15CUnitDefHandler12ToggleNoCostEv": __ZN15CUnitDefHandler12ToggleNoCostEv, "__ZNK20CResourceMapAnalyzer16GetAverageIncomeEv": __ZNK20CResourceMapAnalyzer16GetAverageIncomeEv, "__ZN8CModInfo10ResetStateEv": __ZN8CModInfo10ResetStateEv, "__ZN14CPathEstimator10MapChangedEjjjj": __ZN14CPathEstimator10MapChangedEjjjj, "__ZN18CExtractorBuilding26SetExtractionRangeAndDepthEff": __ZN18CExtractorBuilding26SetExtractionRangeAndDepthEff, "__ZNK7CCannon10GetRange2DEff": __ZNK7CCannon10GetRange2DEff, "___cxa_begin_catch": ___cxa_begin_catch, "_emscripten_memcpy_big": _emscripten_memcpy_big, "___cxa_end_catch": ___cxa_end_catch, "__ZN11CBuilderCAI10InitStaticEv": __ZN11CBuilderCAI10InitStaticEv, "___resumeException": ___resumeException, "___cxa_find_matching_catch_3": ___cxa_find_matching_catch_3, "___syscall140": ___syscall140, "__ZN17CGeometricObjects7AddLineE6float3S0_fiii": __ZN17CGeometricObjects7AddLineE6float3S0_fiii, "__ZN7CCannon15UpdateWantedDirEv": __ZN7CCannon15UpdateWantedDirEv, "___setErrNo": ___setErrNo, "_pthread_getspecific": _pthread_getspecific, "__ZN7CCannon10SlowUpdateEv": __ZN7CCannon10SlowUpdateEv, "__ZN17CGeometricObjects9AddSplineE6float3S0_S0_S0_fiii": __ZN17CGeometricObjects9AddSplineE6float3S0_S0_S0_fiii, "__ZN14CPathEstimator6UpdateEv": __ZN14CPathEstimator6UpdateEv, "__ZN17CGeometricObjects10MarkSquareEi": __ZN17CGeometricObjects10MarkSquareEi, "__ZNK6float36equalsERKS_S1_": __ZNK6float36equalsERKS_S1_, "__ZN8CFactory18CreateNanoParticleEb": __ZN8CFactory18CreateNanoParticleEb, "__ZN17CUnitScriptEngine10InitStaticEv": __ZN17CUnitScriptEngine10InitStaticEv, "__ZN13CGlobalSyncedD1Ev": __ZN13CGlobalSyncedD1Ev, "_pthread_once": _pthread_once, "__ZN17CGeometricObjects8SetColorEiffff": __ZN17CGeometricObjects8SetColorEiffff, "__ZN26CExplosionGeneratorHandlerD1Ev": __ZN26CExplosionGeneratorHandlerD1Ev, "__ZN7CCannon4InitEv": __ZN7CCannon4InitEv, "__ZN8CBuilder12StartRestoreE6float3f": __ZN8CBuilder12StartRestoreE6float3f, "_pthread_key_create": _pthread_key_create, "__ZN11CBuilderCAI8PostLoadEv": __ZN11CBuilderCAI8PostLoadEv, "__ZN15CollisionVolume9InitShapeERK6float3S2_iii": __ZN15CollisionVolume9InitShapeERK6float3S2_iii, "__ZN10CMobileCAI13StopSlowGuardEv": __ZN10CMobileCAI13StopSlowGuardEv, "__ZN15CScriptMoveType12ForceUpdatesEv": __ZN15CScriptMoveType12ForceUpdatesEv, "__ZN15CollisionVolume8PostLoadEv": __ZN15CollisionVolume8PostLoadEv, "__ZN18CExtractorBuilding15ResetExtractionEv": __ZN18CExtractorBuilding15ResetExtractionEv, "__ZN15CUnitDefHandler16AssignTechLevelsEv": __ZN15CUnitDefHandler16AssignTechLevelsEv, "__ZN10CMobileCAI9NonMovingEv": __ZN10CMobileCAI9NonMovingEv, "_pthread_setspecific": _pthread_setspecific, "__ZN25CCustomExplosionGenerator25OutputProjectileClassInfoEv": __ZN25CCustomExplosionGenerator25OutputProjectileClassInfoEv, "__ZN26CExplosionGeneratorHandler20ParseExplosionTablesEv": __ZN26CExplosionGeneratorHandler20ParseExplosionTablesEv, "___lock": ___lock, "__ZN17CGeometricObjects6UpdateEv": __ZN17CGeometricObjects6UpdateEv, "_abort": _abort, "_pthread_cleanup_push": _pthread_cleanup_push, "__ZN14DynDamageArrayD1Ev": __ZN14DynDamageArrayD1Ev, "__ZN25CCustomExplosionGenerator18GetFlagsFromHeightEff": __ZN25CCustomExplosionGenerator18GetFlagsFromHeightEff, "__ZN8CBuilder19ScriptStartBuildingE6float3b": __ZN8CBuilder19ScriptStartBuildingE6float3b, "__ZN10CMobileCAI24StopMoveAndFinishCommandEv": __ZN10CMobileCAI24StopMoveAndFinishCommandEv, "__ZN15CUnitDefHandler13ProcessDecoysEv": __ZN15CUnitDefHandler13ProcessDecoysEv, "__ZN15CollisionVolume17SetBoundingRadiusEv": __ZN15CollisionVolume17SetBoundingRadiusEv, "___cxa_find_matching_catch": ___cxa_find_matching_catch, "___syscall146": ___syscall146, "__ZN7CCannon11UpdateRangeEf": __ZN7CCannon11UpdateRangeEf, "STACKTOP": STACKTOP, "STACK_MAX": STACK_MAX, "DYNAMICTOP_PTR": DYNAMICTOP_PTR, "tempDoublePtr": tempDoublePtr, "ABORT": ABORT, "cttz_i8": cttz_i8 };
// EMSCRIPTEN_START_ASM
var asm = (function(global, env, buffer) {
  'almost asm';
  
  
  var HEAP8 = new global.Int8Array(buffer);
  var HEAP16 = new global.Int16Array(buffer);
  var HEAP32 = new global.Int32Array(buffer);
  var HEAPU8 = new global.Uint8Array(buffer);
  var HEAPU16 = new global.Uint16Array(buffer);
  var HEAPU32 = new global.Uint32Array(buffer);
  var HEAPF32 = new global.Float32Array(buffer);
  var HEAPF64 = new global.Float64Array(buffer);


  var STACKTOP=env.STACKTOP|0;
  var STACK_MAX=env.STACK_MAX|0;
  var DYNAMICTOP_PTR=env.DYNAMICTOP_PTR|0;
  var tempDoublePtr=env.tempDoublePtr|0;
  var ABORT=env.ABORT|0;
  var cttz_i8=env.cttz_i8|0;

  var __THREW__ = 0;
  var threwValue = 0;
  var setjmpId = 0;
  var undef = 0;
  var nan = global.NaN, inf = global.Infinity;
  var tempInt = 0, tempBigInt = 0, tempBigIntP = 0, tempBigIntS = 0, tempBigIntR = 0.0, tempBigIntI = 0, tempBigIntD = 0, tempValue = 0, tempDouble = 0.0;
  var tempRet0 = 0;

  var Math_floor=global.Math.floor;
  var Math_abs=global.Math.abs;
  var Math_sqrt=global.Math.sqrt;
  var Math_pow=global.Math.pow;
  var Math_cos=global.Math.cos;
  var Math_sin=global.Math.sin;
  var Math_tan=global.Math.tan;
  var Math_acos=global.Math.acos;
  var Math_asin=global.Math.asin;
  var Math_atan=global.Math.atan;
  var Math_atan2=global.Math.atan2;
  var Math_exp=global.Math.exp;
  var Math_log=global.Math.log;
  var Math_ceil=global.Math.ceil;
  var Math_imul=global.Math.imul;
  var Math_min=global.Math.min;
  var Math_max=global.Math.max;
  var Math_clz32=global.Math.clz32;
  var abort=env.abort;
  var assert=env.assert;
  var enlargeMemory=env.enlargeMemory;
  var getTotalMemory=env.getTotalMemory;
  var abortOnCannotGrowMemory=env.abortOnCannotGrowMemory;
  var abortStackOverflow=env.abortStackOverflow;
  var nullFunc_iiii=env.nullFunc_iiii;
  var nullFunc_vid=env.nullFunc_vid;
  var nullFunc_viiiii=env.nullFunc_viiiii;
  var nullFunc_i=env.nullFunc_i;
  var nullFunc_vi=env.nullFunc_vi;
  var nullFunc_vii=env.nullFunc_vii;
  var nullFunc_vidd=env.nullFunc_vidd;
  var nullFunc_ii=env.nullFunc_ii;
  var nullFunc_viidi=env.nullFunc_viidi;
  var nullFunc_viidd=env.nullFunc_viidd;
  var nullFunc_v=env.nullFunc_v;
  var nullFunc_viid=env.nullFunc_viid;
  var nullFunc_viiiiii=env.nullFunc_viiiiii;
  var nullFunc_iii=env.nullFunc_iii;
  var nullFunc_viiii=env.nullFunc_viiii;
  var invoke_iiii=env.invoke_iiii;
  var invoke_vid=env.invoke_vid;
  var invoke_viiiii=env.invoke_viiiii;
  var invoke_i=env.invoke_i;
  var invoke_vi=env.invoke_vi;
  var invoke_vii=env.invoke_vii;
  var invoke_vidd=env.invoke_vidd;
  var invoke_ii=env.invoke_ii;
  var invoke_viidi=env.invoke_viidi;
  var invoke_viidd=env.invoke_viidd;
  var invoke_v=env.invoke_v;
  var invoke_viid=env.invoke_viid;
  var invoke_viiiiii=env.invoke_viiiiii;
  var invoke_iii=env.invoke_iii;
  var invoke_viiii=env.invoke_viiii;
  var _pthread_cleanup_pop=env._pthread_cleanup_pop;
  var __ZN17CUnitScriptEngine10KillStaticEv=env.__ZN17CUnitScriptEngine10KillStaticEv;
  var __ZN18CFeatureDefHandler22LoadFeatureDefsFromMapEv=env.__ZN18CFeatureDefHandler22LoadFeatureDefsFromMapEv;
  var __ZN17CUnitScriptEngine4TickEi=env.__ZN17CUnitScriptEngine4TickEi;
  var __ZN8CBuilder9StopBuildEb=env.__ZN8CBuilder9StopBuildEb;
  var __ZN8CFactory9StopBuildEv=env.__ZN8CFactory9StopBuildEv;
  var ___syscall54=env.___syscall54;
  var __ZN15CUnitDefHandler4InitEv=env.__ZN15CUnitDefHandler4InitEv;
  var __ZN10CMobileCAI14StartSlowGuardEf=env.__ZN10CMobileCAI14StartSlowGuardEf;
  var __ZN13CGlobalSynced10ResetStateEv=env.__ZN13CGlobalSynced10ResetStateEv;
  var __ZN18CExtractorBuilding26ReCalculateMetalExtractionEv=env.__ZN18CExtractorBuilding26ReCalculateMetalExtractionEv;
  var ___syscall6=env.___syscall6;
  var __ZN17CCollisionHandler10PrintStatsEv=env.__ZN17CCollisionHandler10PrintStatsEv;
  var __ZN18CFeatureDefHandlerD1Ev=env.__ZN18CFeatureDefHandlerD1Ev;
  var ___gxx_personality_v0=env.___gxx_personality_v0;
  var __ZN17CGeometricObjects11DeleteGroupEi=env.__ZN17CGeometricObjects11DeleteGroupEi;
  var ___unlock=env.___unlock;
  var __ZN15CScriptMoveType10SetHeadingEs=env.__ZN15CScriptMoveType10SetHeadingEs;
  var __ZNK7CCannon10GetRange2DEf=env.__ZNK7CCannon10GetRange2DEf;
  var ___cxa_free_exception=env.___cxa_free_exception;
  var __ZSt18uncaught_exceptionv=env.__ZSt18uncaught_exceptionv;
  var __ZN15CScriptMoveType13SetNoBlockingEb=env.__ZN15CScriptMoveType13SetNoBlockingEb;
  var __ZN17CGeometricObjectsD1Ev=env.__ZN17CGeometricObjectsD1Ev;
  var __ZN15CUnitDefHandler12ToggleNoCostEv=env.__ZN15CUnitDefHandler12ToggleNoCostEv;
  var __ZNK20CResourceMapAnalyzer16GetAverageIncomeEv=env.__ZNK20CResourceMapAnalyzer16GetAverageIncomeEv;
  var __ZN8CModInfo10ResetStateEv=env.__ZN8CModInfo10ResetStateEv;
  var __ZN14CPathEstimator10MapChangedEjjjj=env.__ZN14CPathEstimator10MapChangedEjjjj;
  var __ZN18CExtractorBuilding26SetExtractionRangeAndDepthEff=env.__ZN18CExtractorBuilding26SetExtractionRangeAndDepthEff;
  var __ZNK7CCannon10GetRange2DEff=env.__ZNK7CCannon10GetRange2DEff;
  var ___cxa_begin_catch=env.___cxa_begin_catch;
  var _emscripten_memcpy_big=env._emscripten_memcpy_big;
  var ___cxa_end_catch=env.___cxa_end_catch;
  var __ZN11CBuilderCAI10InitStaticEv=env.__ZN11CBuilderCAI10InitStaticEv;
  var ___resumeException=env.___resumeException;
  var ___cxa_find_matching_catch_3=env.___cxa_find_matching_catch_3;
  var ___syscall140=env.___syscall140;
  var __ZN17CGeometricObjects7AddLineE6float3S0_fiii=env.__ZN17CGeometricObjects7AddLineE6float3S0_fiii;
  var __ZN7CCannon15UpdateWantedDirEv=env.__ZN7CCannon15UpdateWantedDirEv;
  var ___setErrNo=env.___setErrNo;
  var _pthread_getspecific=env._pthread_getspecific;
  var __ZN7CCannon10SlowUpdateEv=env.__ZN7CCannon10SlowUpdateEv;
  var __ZN17CGeometricObjects9AddSplineE6float3S0_S0_S0_fiii=env.__ZN17CGeometricObjects9AddSplineE6float3S0_S0_S0_fiii;
  var __ZN14CPathEstimator6UpdateEv=env.__ZN14CPathEstimator6UpdateEv;
  var __ZN17CGeometricObjects10MarkSquareEi=env.__ZN17CGeometricObjects10MarkSquareEi;
  var __ZNK6float36equalsERKS_S1_=env.__ZNK6float36equalsERKS_S1_;
  var __ZN8CFactory18CreateNanoParticleEb=env.__ZN8CFactory18CreateNanoParticleEb;
  var __ZN17CUnitScriptEngine10InitStaticEv=env.__ZN17CUnitScriptEngine10InitStaticEv;
  var __ZN13CGlobalSyncedD1Ev=env.__ZN13CGlobalSyncedD1Ev;
  var _pthread_once=env._pthread_once;
  var __ZN17CGeometricObjects8SetColorEiffff=env.__ZN17CGeometricObjects8SetColorEiffff;
  var __ZN26CExplosionGeneratorHandlerD1Ev=env.__ZN26CExplosionGeneratorHandlerD1Ev;
  var __ZN7CCannon4InitEv=env.__ZN7CCannon4InitEv;
  var __ZN8CBuilder12StartRestoreE6float3f=env.__ZN8CBuilder12StartRestoreE6float3f;
  var _pthread_key_create=env._pthread_key_create;
  var __ZN11CBuilderCAI8PostLoadEv=env.__ZN11CBuilderCAI8PostLoadEv;
  var __ZN15CollisionVolume9InitShapeERK6float3S2_iii=env.__ZN15CollisionVolume9InitShapeERK6float3S2_iii;
  var __ZN10CMobileCAI13StopSlowGuardEv=env.__ZN10CMobileCAI13StopSlowGuardEv;
  var __ZN15CScriptMoveType12ForceUpdatesEv=env.__ZN15CScriptMoveType12ForceUpdatesEv;
  var __ZN15CollisionVolume8PostLoadEv=env.__ZN15CollisionVolume8PostLoadEv;
  var __ZN18CExtractorBuilding15ResetExtractionEv=env.__ZN18CExtractorBuilding15ResetExtractionEv;
  var __ZN15CUnitDefHandler16AssignTechLevelsEv=env.__ZN15CUnitDefHandler16AssignTechLevelsEv;
  var __ZN10CMobileCAI9NonMovingEv=env.__ZN10CMobileCAI9NonMovingEv;
  var _pthread_setspecific=env._pthread_setspecific;
  var __ZN25CCustomExplosionGenerator25OutputProjectileClassInfoEv=env.__ZN25CCustomExplosionGenerator25OutputProjectileClassInfoEv;
  var __ZN26CExplosionGeneratorHandler20ParseExplosionTablesEv=env.__ZN26CExplosionGeneratorHandler20ParseExplosionTablesEv;
  var ___lock=env.___lock;
  var __ZN17CGeometricObjects6UpdateEv=env.__ZN17CGeometricObjects6UpdateEv;
  var _abort=env._abort;
  var _pthread_cleanup_push=env._pthread_cleanup_push;
  var __ZN14DynDamageArrayD1Ev=env.__ZN14DynDamageArrayD1Ev;
  var __ZN25CCustomExplosionGenerator18GetFlagsFromHeightEff=env.__ZN25CCustomExplosionGenerator18GetFlagsFromHeightEff;
  var __ZN8CBuilder19ScriptStartBuildingE6float3b=env.__ZN8CBuilder19ScriptStartBuildingE6float3b;
  var __ZN10CMobileCAI24StopMoveAndFinishCommandEv=env.__ZN10CMobileCAI24StopMoveAndFinishCommandEv;
  var __ZN15CUnitDefHandler13ProcessDecoysEv=env.__ZN15CUnitDefHandler13ProcessDecoysEv;
  var __ZN15CollisionVolume17SetBoundingRadiusEv=env.__ZN15CollisionVolume17SetBoundingRadiusEv;
  var ___cxa_find_matching_catch=env.___cxa_find_matching_catch;
  var ___syscall146=env.___syscall146;
  var __ZN7CCannon11UpdateRangeEf=env.__ZN7CCannon11UpdateRangeEf;
  var tempFloat = 0.0;

// EMSCRIPTEN_START_FUNCS

function stackAlloc(size) {
  size = size|0;
  var ret = 0;
  ret = STACKTOP;
  STACKTOP = (STACKTOP + size)|0;
  STACKTOP = (STACKTOP + 15)&-16;
  if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(size|0);

  return ret|0;
}
function stackSave() {
  return STACKTOP|0;
}
function stackRestore(top) {
  top = top|0;
  STACKTOP = top;
}
function establishStackSpace(stackBase, stackMax) {
  stackBase = stackBase|0;
  stackMax = stackMax|0;
  STACKTOP = stackBase;
  STACK_MAX = stackMax;
}

function setThrew(threw, value) {
  threw = threw|0;
  value = value|0;
  if ((__THREW__|0) == 0) {
    __THREW__ = threw;
    threwValue = value;
  }
}

function setTempRet0(value) {
  value = value|0;
  tempRet0 = value;
}
function getTempRet0() {
  return tempRet0|0;
}

function ___cxx_global_var_init() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN6float3C2Efff(3456,0.0,1.0,0.0);
 return;
}
function __ZN6float3C2Efff($0,$1,$2,$3) {
 $0 = $0|0;
 $1 = +$1;
 $2 = +$2;
 $3 = +$3;
 var $10 = 0, $11 = 0.0, $12 = 0, $13 = 0.0, $4 = 0, $5 = 0.0, $6 = 0.0, $7 = 0.0, $8 = 0, $9 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $4 = $0;
 $5 = $1;
 $6 = $2;
 $7 = $3;
 $8 = $4;
 $9 = $5;
 HEAPF32[$8>>2] = $9;
 $10 = ((($8)) + 4|0);
 $11 = $6;
 HEAPF32[$10>>2] = $11;
 $12 = ((($8)) + 8|0);
 $13 = $7;
 HEAPF32[$12>>2] = $13;
 STACKTOP = sp;return;
}
function ___cxx_global_var_init_1() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN6float3C2Efff(3468,0.0,0.0,1.0);
 return;
}
function ___cxx_global_var_init_2() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN6float3C2Efff(3480,1.0,0.0,0.0);
 return;
}
function ___cxx_global_var_init_3() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN6float3C2Efff(3492,0.0,0.0,0.0);
 return;
}
function ___cxx_global_var_init_4() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN6float3C2Efff(3504,1.0,1.0,1.0);
 return;
}
function ___cxx_global_var_init_5() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN6float3C2Efff(3516,1.0,1.0,0.0);
 return;
}
function ___cxx_global_var_init_6() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN6float3C2Efff(3528,1.0,0.0,1.0);
 return;
}
function ___cxx_global_var_init_7() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN6float3C2Efff(3540,0.0,1.0,1.0);
 return;
}
function ___cxx_global_var_init_8() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN6float3C2Efff(3552,-1.0,1.0,1.0);
 return;
}
function ___cxx_global_var_init_9() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN6float3C2Efff(3564,1.0E+4,1.0E+4,1.0E+4);
 return;
}
function ___cxx_global_var_init_10() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN6float3C2Efff(3576,-1.0E+4,-1.0E+4,-1.0E+4);
 return;
}
function ___cxx_global_var_init_11() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN11spring_timeC2IiEET_(3440,0);
 return;
}
function __ZN11spring_timeC2IiEET_($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $10 = 0, $11 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (__ZN12spring_clockL13FromMilliSecsIiEExT_($5)|0);
 $7 = tempRet0;
 $8 = $4;
 $9 = $8;
 HEAP32[$9>>2] = $6;
 $10 = (($8) + 4)|0;
 $11 = $10;
 HEAP32[$11>>2] = $7;
 STACKTOP = sp;return;
}
function ___cxx_global_var_init_12() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZN11spring_timeC2IiEET_(3448,0);
 return;
}
function ___cxx_global_var_init_13() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZL18GetPathDir2PathOptv(3588);
 return;
}
function __ZL18GetPathDir2PathOptv($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 64|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(64|0);
 $15 = $0;
 $16 = 0;
 $17 = $15;
 $18 = $16;
 $19 = (($17) + ($18<<2)|0);
 HEAP32[$19>>2] = 1;
 $1 = $0;
 $2 = 4;
 $20 = $1;
 $21 = $2;
 $22 = (($20) + ($21<<2)|0);
 HEAP32[$22>>2] = 2;
 $3 = $0;
 $4 = 2;
 $23 = $3;
 $24 = $4;
 $25 = (($23) + ($24<<2)|0);
 HEAP32[$25>>2] = 4;
 $5 = $0;
 $6 = 6;
 $26 = $5;
 $27 = $6;
 $28 = (($26) + ($27<<2)|0);
 HEAP32[$28>>2] = 8;
 $7 = $0;
 $8 = 1;
 $29 = $7;
 $30 = $8;
 $31 = (($29) + ($30<<2)|0);
 HEAP32[$31>>2] = 5;
 $9 = $0;
 $10 = 3;
 $32 = $9;
 $33 = $10;
 $34 = (($32) + ($33<<2)|0);
 HEAP32[$34>>2] = 6;
 $11 = $0;
 $12 = 5;
 $35 = $11;
 $36 = $12;
 $37 = (($35) + ($36<<2)|0);
 HEAP32[$37>>2] = 10;
 $13 = $0;
 $14 = 7;
 $38 = $13;
 $39 = $14;
 $40 = (($38) + ($39<<2)|0);
 HEAP32[$40>>2] = 9;
 STACKTOP = sp;return;
}
function ___cxx_global_var_init_14() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZL18GetPathOpt2PathDirv(3620);
 return;
}
function __ZL18GetPathOpt2PathDirv($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 112|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(112|0);
 $26 = sp;
 HEAP32[$26>>2] = 0;
 $24 = $0;
 $25 = $26;
 $27 = $24;
 $28 = $25;
 $21 = $27;
 $22 = 15;
 $23 = $28;
 $29 = $21;
 $30 = $22;
 $20 = $30;
 $31 = $20;
 $32 = $23;
 $17 = $29;
 $18 = $31;
 $19 = $32;
 while(1) {
  $33 = $18;
  $34 = ($33>>>0)>(0);
  if (!($34)) {
   break;
  }
  $35 = $19;
  $36 = HEAP32[$35>>2]|0;
  $37 = $17;
  HEAP32[$37>>2] = $36;
  $38 = $17;
  $39 = ((($38)) + 4|0);
  $17 = $39;
  $40 = $18;
  $41 = (($40) + -1)|0;
  $18 = $41;
 }
 $1 = $0;
 $2 = 1;
 $42 = $1;
 $43 = $2;
 $44 = (($42) + ($43<<2)|0);
 HEAP32[$44>>2] = 0;
 $3 = $0;
 $4 = 2;
 $45 = $3;
 $46 = $4;
 $47 = (($45) + ($46<<2)|0);
 HEAP32[$47>>2] = 4;
 $5 = $0;
 $6 = 4;
 $48 = $5;
 $49 = $6;
 $50 = (($48) + ($49<<2)|0);
 HEAP32[$50>>2] = 2;
 $7 = $0;
 $8 = 8;
 $51 = $7;
 $52 = $8;
 $53 = (($51) + ($52<<2)|0);
 HEAP32[$53>>2] = 6;
 $9 = $0;
 $10 = 5;
 $54 = $9;
 $55 = $10;
 $56 = (($54) + ($55<<2)|0);
 HEAP32[$56>>2] = 1;
 $11 = $0;
 $12 = 6;
 $57 = $11;
 $58 = $12;
 $59 = (($57) + ($58<<2)|0);
 HEAP32[$59>>2] = 3;
 $13 = $0;
 $14 = 10;
 $60 = $13;
 $61 = $14;
 $62 = (($60) + ($61<<2)|0);
 HEAP32[$62>>2] = 5;
 $15 = $0;
 $16 = 9;
 $63 = $15;
 $64 = $16;
 $65 = (($63) + ($64<<2)|0);
 HEAP32[$65>>2] = 7;
 STACKTOP = sp;return;
}
function _emscripten_bind_CLosMap___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZN7CLosMapD2Ev($2);
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function __ZN7CLosMapD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 16|0);
 __ZNSt3__26vectorItNS_9allocatorItEEED2Ev($3);
 STACKTOP = sp;return;
}
function _emscripten_bind_CUnitDefHandler_Init_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN15CUnitDefHandler4InitEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CUnitDefHandler_ProcessDecoys_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN15CUnitDefHandler13ProcessDecoysEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CUnitDefHandler_AssignTechLevels_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN15CUnitDefHandler16AssignTechLevelsEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CUnitDefHandler_ToggleNoCost_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZN15CUnitDefHandler12ToggleNoCostEv(($2|0))|0);
 STACKTOP = sp;return ($3|0);
}
function _emscripten_bind_CUnitDefHandler_IsValidUnitDefID_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (__ZNK15CUnitDefHandler16IsValidUnitDefIDEi($4,$5)|0);
 STACKTOP = sp;return ($6|0);
}
function __ZNK15CUnitDefHandler16IsValidUnitDefIDEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $3 = $0;
 $4 = $1;
 $5 = $3;
 $6 = $4;
 $7 = ($6|0)>(0);
 if (!($7)) {
  $19 = 0;
  STACKTOP = sp;return ($19|0);
 }
 $8 = $4;
 $9 = ((($5)) + 56|0);
 $2 = $9;
 $10 = $2;
 $11 = ((($10)) + 4|0);
 $12 = HEAP32[$11>>2]|0;
 $13 = HEAP32[$10>>2]|0;
 $14 = $12;
 $15 = $13;
 $16 = (($14) - ($15))|0;
 $17 = (($16|0) / 1232)&-1;
 $18 = ($8|0)<($17|0);
 $19 = $18;
 STACKTOP = sp;return ($19|0);
}
function _emscripten_bind_CUnitDefHandler___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZN15CUnitDefHandlerD2Ev($2);
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function __ZN15CUnitDefHandlerD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 96|0);
 __ZN6emilib7HashMapINSt3__212basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_N6spring11synced_hashIS7_EENS_14HashMapEqualToIS7_EEED2Ev($3);
 $4 = ((($2)) + 68|0);
 __ZN6emilib7HashMapINSt3__212basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiN6spring11synced_hashIS7_EENS_14HashMapEqualToIS7_EEED2Ev($4);
 $5 = ((($2)) + 56|0);
 __ZNSt3__26vectorI7UnitDefNS_9allocatorIS1_EEED2Ev($5);
 $6 = ((($2)) + 28|0);
 __ZN6emilib7HashSetIiN6spring11synced_hashIiEENS_14HashSetEqualToIiEEED2Ev($6);
 __ZN6emilib7HashMapIiNS_7HashSetIiN6spring11synced_hashIiEENS_14HashSetEqualToIiEEEES4_NS_14HashMapEqualToIiEEED2Ev($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CWeaponDefHandler___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZN17CWeaponDefHandlerD2Ev($2);
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function __ZN17CWeaponDefHandlerD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 12|0);
 __ZN6emilib7HashMapINSt3__212basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiN6spring11synced_hashIS7_EENS_14HashMapEqualToIS7_EEED2Ev($3);
 __ZNSt3__26vectorI9WeaponDefNS_9allocatorIS1_EEED2Ev($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CGeometricObjects_AddSpline_8($0,$1,$2,$3,$4,$5,$6,$7,$8) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 $4 = $4|0;
 $5 = +$5;
 $6 = $6|0;
 $7 = $7|0;
 $8 = $8|0;
 var $$byval_copy = 0, $$byval_copy1 = 0, $$byval_copy2 = 0, $$byval_copy3 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0.0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0.0, $25 = 0;
 var $26 = 0.0, $27 = 0, $28 = 0.0, $29 = 0, $30 = 0.0, $31 = 0.0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 144|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(144|0);
 $$byval_copy3 = sp + 120|0;
 $$byval_copy2 = sp + 108|0;
 $$byval_copy1 = sp + 96|0;
 $$byval_copy = sp + 84|0;
 $18 = sp + 36|0;
 $19 = sp + 24|0;
 $20 = sp + 12|0;
 $21 = sp;
 $9 = $0;
 $10 = $1;
 $11 = $2;
 $12 = $3;
 $13 = $4;
 $14 = $5;
 $15 = $6;
 $16 = $7;
 $17 = $8;
 $22 = $9;
 $23 = $10;
 $24 = (+($23|0));
 __ZN6float3C2Efff($18,$24,0.0,0.0);
 $25 = $11;
 $26 = (+($25|0));
 __ZN6float3C2Efff($19,$26,0.0,0.0);
 $27 = $12;
 $28 = (+($27|0));
 __ZN6float3C2Efff($20,$28,0.0,0.0);
 $29 = $13;
 $30 = (+($29|0));
 __ZN6float3C2Efff($21,$30,0.0,0.0);
 $31 = $14;
 $32 = $15;
 $33 = $16;
 $34 = $17;
 ;HEAP32[$$byval_copy>>2]=HEAP32[$18>>2]|0;HEAP32[$$byval_copy+4>>2]=HEAP32[$18+4>>2]|0;HEAP32[$$byval_copy+8>>2]=HEAP32[$18+8>>2]|0;
 ;HEAP32[$$byval_copy1>>2]=HEAP32[$19>>2]|0;HEAP32[$$byval_copy1+4>>2]=HEAP32[$19+4>>2]|0;HEAP32[$$byval_copy1+8>>2]=HEAP32[$19+8>>2]|0;
 ;HEAP32[$$byval_copy2>>2]=HEAP32[$20>>2]|0;HEAP32[$$byval_copy2+4>>2]=HEAP32[$20+4>>2]|0;HEAP32[$$byval_copy2+8>>2]=HEAP32[$20+8>>2]|0;
 ;HEAP32[$$byval_copy3>>2]=HEAP32[$21>>2]|0;HEAP32[$$byval_copy3+4>>2]=HEAP32[$21+4>>2]|0;HEAP32[$$byval_copy3+8>>2]=HEAP32[$21+8>>2]|0;
 $35 = (__ZN17CGeometricObjects9AddSplineE6float3S0_S0_S0_fiii(($22|0),($$byval_copy|0),($$byval_copy1|0),($$byval_copy2|0),($$byval_copy3|0),(+$31),($32|0),($33|0),($34|0))|0);
 STACKTOP = sp;return ($35|0);
}
function _emscripten_bind_CGeometricObjects_DeleteGroup_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN17CGeometricObjects11DeleteGroupEi(($4|0),($5|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CGeometricObjects_SetColor_5($0,$1,$2,$3,$4,$5) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = +$2;
 $3 = +$3;
 $4 = +$4;
 $5 = +$5;
 var $10 = 0.0, $11 = 0.0, $12 = 0, $13 = 0, $14 = 0.0, $15 = 0.0, $16 = 0.0, $17 = 0.0, $6 = 0, $7 = 0, $8 = 0.0, $9 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(32|0);
 $6 = $0;
 $7 = $1;
 $8 = $2;
 $9 = $3;
 $10 = $4;
 $11 = $5;
 $12 = $6;
 $13 = $7;
 $14 = $8;
 $15 = $9;
 $16 = $10;
 $17 = $11;
 __ZN17CGeometricObjects8SetColorEiffff(($12|0),($13|0),(+$14),(+$15),(+$16),(+$17));
 STACKTOP = sp;return;
}
function _emscripten_bind_CGeometricObjects_AddLine_6($0,$1,$2,$3,$4,$5,$6) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = +$3;
 $4 = $4|0;
 $5 = $5|0;
 $6 = $6|0;
 var $$byval_copy = 0, $$byval_copy1 = 0, $10 = 0.0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0.0, $19 = 0, $20 = 0.0, $21 = 0.0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $7 = 0, $8 = 0;
 var $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 80|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(80|0);
 $$byval_copy1 = sp + 64|0;
 $$byval_copy = sp + 52|0;
 $14 = sp + 12|0;
 $15 = sp;
 $7 = $0;
 $8 = $1;
 $9 = $2;
 $10 = $3;
 $11 = $4;
 $12 = $5;
 $13 = $6;
 $16 = $7;
 $17 = $8;
 $18 = (+($17|0));
 __ZN6float3C2Efff($14,$18,0.0,0.0);
 $19 = $9;
 $20 = (+($19|0));
 __ZN6float3C2Efff($15,$20,0.0,0.0);
 $21 = $10;
 $22 = $11;
 $23 = $12;
 $24 = $13;
 ;HEAP32[$$byval_copy>>2]=HEAP32[$14>>2]|0;HEAP32[$$byval_copy+4>>2]=HEAP32[$14+4>>2]|0;HEAP32[$$byval_copy+8>>2]=HEAP32[$14+8>>2]|0;
 ;HEAP32[$$byval_copy1>>2]=HEAP32[$15>>2]|0;HEAP32[$$byval_copy1+4>>2]=HEAP32[$15+4>>2]|0;HEAP32[$$byval_copy1+8>>2]=HEAP32[$15+8>>2]|0;
 $25 = (__ZN17CGeometricObjects7AddLineE6float3S0_fiii(($16|0),($$byval_copy|0),($$byval_copy1|0),(+$21),($22|0),($23|0),($24|0))|0);
 STACKTOP = sp;return ($25|0);
}
function _emscripten_bind_CGeometricObjects_Update_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN17CGeometricObjects6UpdateEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CGeometricObjects_MarkSquare_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN17CGeometricObjects10MarkSquareEi(($4|0),($5|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CGeometricObjects___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 __ZN17CGeometricObjectsD1Ev(($2|0));
 __ZdlPv($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CExplosionCreator___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CRectangularSearchConstraint_WithinConstraints_2($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $10 = 0, $11 = 0, $12 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $6 = $3;
 $7 = HEAP32[$6>>2]|0;
 $8 = ((($7)) + 12|0);
 $9 = HEAP32[$8>>2]|0;
 $10 = $4;
 $11 = $5;
 $12 = (FUNCTION_TABLE_iiii[$9 & 15]($6,$10,$11)|0);
 STACKTOP = sp;return ($12|0);
}
function _emscripten_bind_CRectangularSearchConstraint___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 4|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CollisionQuery_InsideHit_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK14CollisionQuery9InsideHitEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK14CollisionQuery9InsideHitEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ($3|0)==(2);
 STACKTOP = sp;return ($4|0);
}
function _emscripten_bind_CollisionQuery_IngressHit_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK14CollisionQuery10IngressHitEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK14CollisionQuery10IngressHitEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ($3|0)==(1);
 STACKTOP = sp;return ($4|0);
}
function _emscripten_bind_CollisionQuery_EgressHit_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK14CollisionQuery9EgressHitEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK14CollisionQuery9EgressHitEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 4|0);
 $4 = HEAP32[$3>>2]|0;
 $5 = ($4|0)==(1);
 STACKTOP = sp;return ($5|0);
}
function _emscripten_bind_CollisionQuery_AnyHit_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK14CollisionQuery6AnyHitEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK14CollisionQuery6AnyHitEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ($3|0)!=(0);
 if ($4) {
  $8 = 1;
  STACKTOP = sp;return ($8|0);
 }
 $5 = ((($2)) + 4|0);
 $6 = HEAP32[$5>>2]|0;
 $7 = ($6|0)!=(0);
 $8 = $7;
 STACKTOP = sp;return ($8|0);
}
function _emscripten_bind_CollisionQuery___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_VoidPtr___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CCircularSearchConstraint_WithinConstraints_2($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $10 = 0, $11 = 0, $12 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $6 = $3;
 $7 = HEAP32[$6>>2]|0;
 $8 = ((($7)) + 12|0);
 $9 = HEAP32[$8>>2]|0;
 $10 = $4;
 $11 = $5;
 $12 = (FUNCTION_TABLE_iiii[$9 & 15]($6,$10,$11)|0);
 STACKTOP = sp;return ($12|0);
}
function _emscripten_bind_CCircularSearchConstraint___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 4|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CUnitLoader___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CCobUnitScriptNames___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CUnitScriptEngine_Tick_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN17CUnitScriptEngine4TickEi(($4|0),($5|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CUnitScriptEngine_InitStatic_0($0) {
 $0 = $0|0;
 var $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 __ZN17CUnitScriptEngine10InitStaticEv();
 STACKTOP = sp;return;
}
function _emscripten_bind_CUnitScriptEngine_KillStatic_0($0) {
 $0 = $0|0;
 var $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 __ZN17CUnitScriptEngine10KillStaticEv();
 STACKTOP = sp;return;
}
function _emscripten_bind_CUnitScriptEngine___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZN17CUnitScriptEngineD2Ev($2);
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function __ZN17CUnitScriptEngineD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__26vectorIP11CUnitScriptNS_9allocatorIS2_EEED2Ev($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CBuilder_Update_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 100|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CBuilder_SlowUpdate_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 92|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CBuilder_StopBuild_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = $3;
 $7 = $6&1;
 __ZN8CBuilder9StopBuildEb(($5|0),($7|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CBuilder_StartRestore_2($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = +$2;
 var $$byval_copy = 0, $10 = 0.0, $3 = 0, $4 = 0, $5 = 0.0, $6 = 0, $7 = 0, $8 = 0, $9 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 48|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(48|0);
 $$byval_copy = sp + 24|0;
 $6 = sp;
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $7 = $3;
 $8 = $4;
 $9 = (+($8|0));
 __ZN6float3C2Efff($6,$9,0.0,0.0);
 $10 = $5;
 ;HEAP32[$$byval_copy>>2]=HEAP32[$6>>2]|0;HEAP32[$$byval_copy+4>>2]=HEAP32[$6+4>>2]|0;HEAP32[$$byval_copy+8>>2]=HEAP32[$6+8>>2]|0;
 __ZN8CBuilder12StartRestoreE6float3f(($7|0),($$byval_copy|0),(+$10));
 STACKTOP = sp;return;
}
function _emscripten_bind_CBuilder_ScriptStartBuilding_2($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $$byval_copy = 0, $10 = 0.0, $11 = 0, $12 = 0, $13 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 48|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(48|0);
 $$byval_copy = sp + 20|0;
 $6 = sp;
 $3 = $0;
 $4 = $1;
 $7 = $2&1;
 $5 = $7;
 $8 = $3;
 $9 = $4;
 $10 = (+($9|0));
 __ZN6float3C2Efff($6,$10,0.0,0.0);
 $11 = $5;
 $12 = $11&1;
 ;HEAP32[$$byval_copy>>2]=HEAP32[$6>>2]|0;HEAP32[$$byval_copy+4>>2]=HEAP32[$6+4>>2]|0;HEAP32[$$byval_copy+8>>2]=HEAP32[$6+8>>2]|0;
 $13 = (__ZN8CBuilder19ScriptStartBuildingE6float3b(($8|0),($$byval_copy|0),($12|0))|0);
 STACKTOP = sp;return ($13|0);
}
function _emscripten_bind_CBuilder___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CAirCAI_SlowUpdate_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 32|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CAirCAI_FinishCommand_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 40|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CAirCAI___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CollisionVolume_PostLoad_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN15CollisionVolume8PostLoadEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CollisionVolume_InitSphere_1($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN15CollisionVolume10InitSphereEf($4,$5);
 STACKTOP = sp;return;
}
function __ZN15CollisionVolume10InitSphereEf($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0, $6 = 0, $7 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(32|0);
 $4 = sp + 12|0;
 $5 = sp;
 $2 = $0;
 $3 = $1;
 $6 = $2;
 $7 = $3;
 __ZNK6float3mlEf($5,3504,$7);
 __ZNK6float3mlEf($4,$5,2.0);
 __ZN15CollisionVolume9InitShapeERK6float3S2_iii(($6|0),($4|0),(3492|0),3,1,2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CollisionVolume_SetBoundingRadius_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN15CollisionVolume17SetBoundingRadiusEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CollisionVolume_GetVolumeType_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK15CollisionVolume13GetVolumeTypeEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK15CollisionVolume13GetVolumeTypeEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 68|0);
 $4 = HEAP32[$3>>2]|0;
 STACKTOP = sp;return ($4|0);
}
function _emscripten_bind_CollisionVolume_SetVolumeType_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN15CollisionVolume13SetVolumeTypeEi($4,$5);
 STACKTOP = sp;return;
}
function __ZN15CollisionVolume13SetVolumeTypeEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = ((($4)) + 68|0);
 HEAP32[$6>>2] = $5;
 STACKTOP = sp;return;
}
function _emscripten_bind_CollisionVolume_SetIgnoreHits_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = $3;
 $7 = $6&1;
 __ZN15CollisionVolume13SetIgnoreHitsEb($5,$7);
 STACKTOP = sp;return;
}
function __ZN15CollisionVolume13SetIgnoreHitsEb($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = $3;
 $7 = $6&1;
 $8 = ((($5)) + 84|0);
 $9 = $7&1;
 HEAP8[$8>>0] = $9;
 STACKTOP = sp;return;
}
function _emscripten_bind_CollisionVolume_SetUseContHitTest_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = $3;
 $7 = $6&1;
 __ZN15CollisionVolume17SetUseContHitTestEb($5,$7);
 STACKTOP = sp;return;
}
function __ZN15CollisionVolume17SetUseContHitTestEb($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = $3;
 $7 = $6&1;
 $8 = ((($5)) + 85|0);
 $9 = $7&1;
 HEAP8[$8>>0] = $9;
 STACKTOP = sp;return;
}
function _emscripten_bind_CollisionVolume_SetDefaultToPieceTree_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = $3;
 $7 = $6&1;
 __ZN15CollisionVolume21SetDefaultToPieceTreeEb($5,$7);
 STACKTOP = sp;return;
}
function __ZN15CollisionVolume21SetDefaultToPieceTreeEb($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = $3;
 $7 = $6&1;
 $8 = ((($5)) + 87|0);
 $9 = $7&1;
 HEAP8[$8>>0] = $9;
 STACKTOP = sp;return;
}
function _emscripten_bind_CollisionVolume_SetDefaultToFootPrint_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = $3;
 $7 = $6&1;
 __ZN15CollisionVolume21SetDefaultToFootPrintEb($5,$7);
 STACKTOP = sp;return;
}
function __ZN15CollisionVolume21SetDefaultToFootPrintEb($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = $3;
 $7 = $6&1;
 $8 = ((($5)) + 86|0);
 $9 = $7&1;
 HEAP8[$8>>0] = $9;
 STACKTOP = sp;return;
}
function _emscripten_bind_CollisionVolume_GetPrimaryAxis_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK15CollisionVolume14GetPrimaryAxisEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK15CollisionVolume14GetPrimaryAxisEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 72|0);
 $4 = HEAP32[$3>>2]|0;
 STACKTOP = sp;return ($4|0);
}
function _emscripten_bind_CollisionVolume_GetSecondaryAxis_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (__ZNK15CollisionVolume16GetSecondaryAxisEi($4,$5)|0);
 STACKTOP = sp;return ($6|0);
}
function __ZNK15CollisionVolume16GetSecondaryAxisEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (($5) + 1)|0;
 $7 = ((($4)) + 72|0);
 $8 = (($7) + ($6<<2)|0);
 $9 = HEAP32[$8>>2]|0;
 STACKTOP = sp;return ($9|0);
}
function _emscripten_bind_CollisionVolume_GetBoundingRadius_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (+__ZNK15CollisionVolume17GetBoundingRadiusEv($2));
 STACKTOP = sp;return (+$3);
}
function __ZNK15CollisionVolume17GetBoundingRadiusEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 60|0);
 $4 = +HEAPF32[$3>>2];
 STACKTOP = sp;return (+$4);
}
function _emscripten_bind_CollisionVolume_GetBoundingRadiusSq_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (+__ZNK15CollisionVolume19GetBoundingRadiusSqEv($2));
 STACKTOP = sp;return (+$3);
}
function __ZNK15CollisionVolume19GetBoundingRadiusSqEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 64|0);
 $4 = +HEAPF32[$3>>2];
 STACKTOP = sp;return (+$4);
}
function _emscripten_bind_CollisionVolume_GetOffset_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (+__ZNK15CollisionVolume9GetOffsetEi($4,$5));
 STACKTOP = sp;return (+$6);
}
function __ZNK15CollisionVolume9GetOffsetEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = ((($4)) + 48|0);
 $6 = $3;
 $7 = (__ZNK6float3ixEi($5,$6)|0);
 $8 = +HEAPF32[$7>>2];
 STACKTOP = sp;return (+$8);
}
function _emscripten_bind_CollisionVolume_GetScale_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (+__ZNK15CollisionVolume8GetScaleEi($4,$5));
 STACKTOP = sp;return (+$6);
}
function __ZNK15CollisionVolume8GetScaleEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (__ZNK6float3ixEi($4,$5)|0);
 $7 = +HEAPF32[$6>>2];
 STACKTOP = sp;return (+$7);
}
function _emscripten_bind_CollisionVolume_GetHScale_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (+__ZNK15CollisionVolume9GetHScaleEi($4,$5));
 STACKTOP = sp;return (+$6);
}
function __ZNK15CollisionVolume9GetHScaleEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = ((($4)) + 12|0);
 $6 = $3;
 $7 = (__ZNK6float3ixEi($5,$6)|0);
 $8 = +HEAPF32[$7>>2];
 STACKTOP = sp;return (+$8);
}
function _emscripten_bind_CollisionVolume_GetHScaleSq_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (+__ZNK15CollisionVolume11GetHScaleSqEi($4,$5));
 STACKTOP = sp;return (+$6);
}
function __ZNK15CollisionVolume11GetHScaleSqEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = ((($4)) + 24|0);
 $6 = $3;
 $7 = (__ZNK6float3ixEi($5,$6)|0);
 $8 = +HEAPF32[$7>>2];
 STACKTOP = sp;return (+$8);
}
function _emscripten_bind_CollisionVolume_IgnoreHits_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK15CollisionVolume10IgnoreHitsEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK15CollisionVolume10IgnoreHitsEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 84|0);
 $4 = HEAP8[$3>>0]|0;
 $5 = $4&1;
 STACKTOP = sp;return ($5|0);
}
function _emscripten_bind_CollisionVolume_UseContHitTest_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK15CollisionVolume14UseContHitTestEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK15CollisionVolume14UseContHitTestEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 85|0);
 $4 = HEAP8[$3>>0]|0;
 $5 = $4&1;
 STACKTOP = sp;return ($5|0);
}
function _emscripten_bind_CollisionVolume_DefaultToSphere_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK15CollisionVolume15DefaultToSphereEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK15CollisionVolume15DefaultToSphereEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK6float36equalsERKS_S1_(($2|0),(3504|0),(3492|0))|0);
 STACKTOP = sp;return ($3|0);
}
function _emscripten_bind_CollisionVolume_DefaultToFootPrint_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK15CollisionVolume18DefaultToFootPrintEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK15CollisionVolume18DefaultToFootPrintEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 86|0);
 $4 = HEAP8[$3>>0]|0;
 $5 = $4&1;
 STACKTOP = sp;return ($5|0);
}
function _emscripten_bind_CollisionVolume_DefaultToPieceTree_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK15CollisionVolume18DefaultToPieceTreeEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK15CollisionVolume18DefaultToPieceTreeEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 87|0);
 $4 = HEAP8[$3>>0]|0;
 $5 = $4&1;
 STACKTOP = sp;return ($5|0);
}
function _emscripten_bind_CollisionVolume___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CFactory_StopBuild_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN8CFactory9StopBuildEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CFactory_Update_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 100|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CFactory_CreateNanoParticle_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = $3;
 $7 = $6&1;
 __ZN8CFactory18CreateNanoParticleEb(($5|0),($7|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CFactory___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CFactoryCAI_SlowUpdate_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 32|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CFactoryCAI___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CCollisionHandler_PrintStats_0($0) {
 $0 = $0|0;
 var $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 __ZN17CCollisionHandler10PrintStatsEv();
 STACKTOP = sp;return;
}
function _emscripten_bind_CCollisionHandler___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CommonDefHandler___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScriptNames___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CStarburstProjectile___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_ClassAliasList_Clear_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN14ClassAliasList5ClearEv($2);
 STACKTOP = sp;return;
}
function __ZN14ClassAliasList5ClearEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN6emilib7HashMapINSt3__212basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_N6spring11synced_hashIS7_EENS_14HashMapEqualToIS7_EEE5clearEv($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_ClassAliasList___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZN14ClassAliasListD2Ev($2);
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function __ZN14ClassAliasListD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN6emilib7HashMapINSt3__212basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_N6spring11synced_hashIS7_EENS_14HashMapEqualToIS7_EEED2Ev($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CScriptMoveType_Update_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 84|0);
 $5 = HEAP32[$4>>2]|0;
 $6 = (FUNCTION_TABLE_ii[$5 & 1]($2)|0);
 STACKTOP = sp;return ($6|0);
}
function _emscripten_bind_CScriptMoveType_ForceUpdates_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN15CScriptMoveType12ForceUpdatesEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CScriptMoveType_SetHeading_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN15CScriptMoveType10SetHeadingEs(($4|0),($5|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CScriptMoveType_SetNoBlocking_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = $3;
 $7 = $6&1;
 __ZN15CScriptMoveType13SetNoBlockingEb(($5|0),($7|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CScriptMoveType_StartMoving_2($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = +$2;
 var $$byval_copy = 0, $10 = 0, $11 = 0, $12 = 0.0, $13 = 0.0, $3 = 0, $4 = 0, $5 = 0.0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 48|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(48|0);
 $$byval_copy = sp + 24|0;
 $6 = sp;
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $7 = $3;
 $8 = HEAP32[$7>>2]|0;
 $9 = ((($8)) + 28|0);
 $10 = HEAP32[$9>>2]|0;
 $11 = $4;
 $12 = (+($11|0));
 __ZN6float3C2Efff($6,$12,0.0,0.0);
 $13 = $5;
 ;HEAP32[$$byval_copy>>2]=HEAP32[$6>>2]|0;HEAP32[$$byval_copy+4>>2]=HEAP32[$6+4>>2]|0;HEAP32[$$byval_copy+8>>2]=HEAP32[$6+8>>2]|0;
 FUNCTION_TABLE_viid[$10 & 0]($7,$$byval_copy,$13);
 STACKTOP = sp;return;
}
function _emscripten_bind_CScriptMoveType_KeepPointingTo_3($0,$1,$2,$3) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = +$2;
 $3 = $3|0;
 var $$byval_copy = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0.0, $16 = 0.0, $17 = 0, $18 = 0, $4 = 0, $5 = 0, $6 = 0.0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 48|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(48|0);
 $$byval_copy = sp + 24|0;
 $8 = sp;
 $4 = $0;
 $5 = $1;
 $6 = $2;
 $9 = $3&1;
 $7 = $9;
 $10 = $4;
 $11 = HEAP32[$10>>2]|0;
 $12 = ((($11)) + 36|0);
 $13 = HEAP32[$12>>2]|0;
 $14 = $5;
 $15 = (+($14|0));
 __ZN6float3C2Efff($8,$15,0.0,0.0);
 $16 = $6;
 $17 = $7;
 $18 = $17&1;
 ;HEAP32[$$byval_copy>>2]=HEAP32[$8>>2]|0;HEAP32[$$byval_copy+4>>2]=HEAP32[$8+4>>2]|0;HEAP32[$$byval_copy+8>>2]=HEAP32[$8+8>>2]|0;
 FUNCTION_TABLE_viidi[$13 & 0]($10,$$byval_copy,$16,$18);
 STACKTOP = sp;return;
}
function _emscripten_bind_CScriptMoveType_StopMoving_3($0,$1,$2,$3) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $4 = $0;
 $8 = $1&1;
 $5 = $8;
 $9 = $2&1;
 $6 = $9;
 $10 = $3&1;
 $7 = $10;
 $11 = $4;
 $12 = HEAP32[$11>>2]|0;
 $13 = ((($12)) + 44|0);
 $14 = HEAP32[$13>>2]|0;
 $15 = $5;
 $16 = $15&1;
 $17 = $6;
 $18 = $17&1;
 $19 = $7;
 $20 = $19&1;
 FUNCTION_TABLE_viiii[$14 & 31]($11,$16,$18,$20);
 STACKTOP = sp;return;
}
function _emscripten_bind_CScriptMoveType_SetMaxSpeed_1($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 68|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 FUNCTION_TABLE_vid[$7 & 0]($4,$8);
 STACKTOP = sp;return;
}
function _emscripten_bind_CScriptMoveType_SetWantedMaxSpeed_1($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 72|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 FUNCTION_TABLE_vid[$7 & 0]($4,$8);
 STACKTOP = sp;return;
}
function _emscripten_bind_CScriptMoveType_LeaveTransport_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 52|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CScriptMoveType___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CFeatureDefHandler_LoadFeatureDefsFromMap_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN18CFeatureDefHandler22LoadFeatureDefsFromMapEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CFeatureDefHandler___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 __ZN18CFeatureDefHandlerD1Ev(($2|0));
 __ZdlPv($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CBuilding___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CUnitScriptFactory___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CLosHandler_IncreaseAllyTeamRadarErrorSize_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN11CLosHandler30IncreaseAllyTeamRadarErrorSizeEi($4,$5);
 STACKTOP = sp;return;
}
function __ZN11CLosHandler30IncreaseAllyTeamRadarErrorSizeEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0.0, $16 = 0.0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0.0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $4 = $0;
 $5 = $1;
 $6 = $4;
 $7 = ((($6)) + 2116|0);
 $8 = +HEAPF32[$7>>2];
 $9 = ((($6)) + 2120|0);
 $10 = $5;
 $2 = $9;
 $3 = $10;
 $11 = $2;
 $12 = $3;
 $13 = HEAP32[$11>>2]|0;
 $14 = (($13) + ($12<<2)|0);
 $15 = +HEAPF32[$14>>2];
 $16 = $15 * $8;
 HEAPF32[$14>>2] = $16;
 STACKTOP = sp;return;
}
function _emscripten_bind_CLosHandler_DecreaseAllyTeamRadarErrorSize_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN11CLosHandler30DecreaseAllyTeamRadarErrorSizeEi($4,$5);
 STACKTOP = sp;return;
}
function __ZN11CLosHandler30DecreaseAllyTeamRadarErrorSizeEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0.0, $16 = 0.0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0.0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $4 = $0;
 $5 = $1;
 $6 = $4;
 $7 = ((($6)) + 2116|0);
 $8 = +HEAPF32[$7>>2];
 $9 = ((($6)) + 2120|0);
 $10 = $5;
 $2 = $9;
 $3 = $10;
 $11 = $2;
 $12 = $3;
 $13 = HEAP32[$11>>2]|0;
 $14 = (($13) + ($12<<2)|0);
 $15 = +HEAPF32[$14>>2];
 $16 = $15 / $8;
 HEAPF32[$14>>2] = $16;
 STACKTOP = sp;return;
}
function _emscripten_bind_CLosHandler_SetAllyTeamRadarErrorSize_2($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = +$2;
 var $3 = 0, $4 = 0, $5 = 0.0, $6 = 0, $7 = 0, $8 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $6 = $3;
 $7 = $4;
 $8 = $5;
 __ZN11CLosHandler25SetAllyTeamRadarErrorSizeEif($6,$7,$8);
 STACKTOP = sp;return;
}
function __ZN11CLosHandler25SetAllyTeamRadarErrorSizeEif($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = +$2;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0.0, $8 = 0, $9 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(32|0);
 $5 = $0;
 $6 = $1;
 $7 = $2;
 $8 = $5;
 $9 = $7;
 $10 = ((($8)) + 2120|0);
 $11 = $6;
 $3 = $10;
 $4 = $11;
 $12 = $3;
 $13 = $4;
 $14 = HEAP32[$12>>2]|0;
 $15 = (($14) + ($13<<2)|0);
 HEAPF32[$15>>2] = $9;
 STACKTOP = sp;return;
}
function _emscripten_bind_CLosHandler_GetAllyTeamRadarErrorSize_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (+__ZNK11CLosHandler25GetAllyTeamRadarErrorSizeEi($4,$5));
 STACKTOP = sp;return (+$6);
}
function __ZNK11CLosHandler25GetAllyTeamRadarErrorSizeEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0.0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $4 = $0;
 $5 = $1;
 $6 = $4;
 $7 = ((($6)) + 2120|0);
 $8 = $5;
 $2 = $7;
 $3 = $8;
 $9 = $2;
 $10 = $3;
 $11 = HEAP32[$9>>2]|0;
 $12 = (($11) + ($10<<2)|0);
 $13 = +HEAPF32[$12>>2];
 STACKTOP = sp;return (+$13);
}
function _emscripten_bind_CLosHandler_SetBaseRadarErrorSize_1($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN11CLosHandler21SetBaseRadarErrorSizeEf($4,$5);
 STACKTOP = sp;return;
}
function __ZN11CLosHandler21SetBaseRadarErrorSizeEf($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0.0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = ((($4)) + 2112|0);
 HEAPF32[$6>>2] = $5;
 STACKTOP = sp;return;
}
function _emscripten_bind_CLosHandler_SetBaseRadarErrorMult_1($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN11CLosHandler21SetBaseRadarErrorMultEf($4,$5);
 STACKTOP = sp;return;
}
function __ZN11CLosHandler21SetBaseRadarErrorMultEf($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0.0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = ((($4)) + 2116|0);
 HEAPF32[$6>>2] = $5;
 STACKTOP = sp;return;
}
function _emscripten_bind_CLosHandler_GetBaseRadarErrorSize_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (+__ZNK11CLosHandler21GetBaseRadarErrorSizeEv($2));
 STACKTOP = sp;return (+$3);
}
function __ZNK11CLosHandler21GetBaseRadarErrorSizeEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 2112|0);
 $4 = +HEAPF32[$3>>2];
 STACKTOP = sp;return (+$4);
}
function _emscripten_bind_CLosHandler_GetBaseRadarErrorMult_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (+__ZNK11CLosHandler21GetBaseRadarErrorMultEv($2));
 STACKTOP = sp;return (+$3);
}
function __ZNK11CLosHandler21GetBaseRadarErrorMultEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 2116|0);
 $4 = +HEAPF32[$3>>2];
 STACKTOP = sp;return (+$4);
}
function _emscripten_bind_CLosHandler_GetFullRead_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 8|0);
 $5 = HEAP32[$4>>2]|0;
 $6 = (FUNCTION_TABLE_ii[$5 & 1]($2)|0);
 STACKTOP = sp;return ($6|0);
}
function _emscripten_bind_CLosHandler_GetReadAllyTeam_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 4|0);
 $5 = HEAP32[$4>>2]|0;
 $6 = (FUNCTION_TABLE_ii[$5 & 1]($2)|0);
 STACKTOP = sp;return ($6|0);
}
function _emscripten_bind_CLosHandler_Update_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 336|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLosHandler___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 16|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CPathEstimator_MapChanged_4($0,$1,$2,$3,$4) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 $4 = $4|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(32|0);
 $5 = $0;
 $6 = $1;
 $7 = $2;
 $8 = $3;
 $9 = $4;
 $10 = $5;
 $11 = $6;
 $12 = $7;
 $13 = $8;
 $14 = $9;
 __ZN14CPathEstimator10MapChangedEjjjj(($10|0),($11|0),($12|0),($13|0),($14|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CPathEstimator_Update_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN14CPathEstimator6UpdateEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CPathEstimator_GetPathChecksum_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK14CPathEstimator15GetPathChecksumEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK14CPathEstimator15GetPathChecksumEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 1310940|0);
 $4 = HEAP32[$3>>2]|0;
 STACKTOP = sp;return ($4|0);
}
function _emscripten_bind_CPathEstimator___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 4|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CCannon_Init_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN7CCannon4InitEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CCannon_UpdateRange_1($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN7CCannon11UpdateRangeEf(($4|0),(+$5));
 STACKTOP = sp;return;
}
function _emscripten_bind_CCannon_UpdateWantedDir_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN7CCannon15UpdateWantedDirEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CCannon_SlowUpdate_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN7CCannon10SlowUpdateEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CCannon_GetRange2D_1($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0.0, $6 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (+__ZNK7CCannon10GetRange2DEf(($4|0),(+$5)));
 STACKTOP = sp;return (+$6);
}
function _emscripten_bind_CCannon_GetRange2D_2($0,$1,$2) {
 $0 = $0|0;
 $1 = +$1;
 $2 = +$2;
 var $3 = 0, $4 = 0.0, $5 = 0.0, $6 = 0, $7 = 0.0, $8 = 0.0, $9 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $6 = $3;
 $7 = $4;
 $8 = $5;
 $9 = (+__ZNK7CCannon10GetRange2DEff(($6|0),(+$7),(+$8)));
 STACKTOP = sp;return (+$9);
}
function _emscripten_bind_CCannon___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CWeaponLoader___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CCustomExplosionGenerator_OutputProjectileClassInfo_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = (__ZN25CCustomExplosionGenerator25OutputProjectileClassInfoEv()|0);
 STACKTOP = sp;return ($2|0);
}
function _emscripten_bind_CCustomExplosionGenerator_GetFlagsFromHeight_2($0,$1,$2) {
 $0 = $0|0;
 $1 = +$1;
 $2 = +$2;
 var $3 = 0, $4 = 0.0, $5 = 0.0, $6 = 0.0, $7 = 0.0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $6 = $4;
 $7 = $5;
 $8 = (__ZN25CCustomExplosionGenerator18GetFlagsFromHeightEff((+$6),(+$7))|0);
 STACKTOP = sp;return ($8|0);
}
function _emscripten_bind_CCustomExplosionGenerator___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CResourceMapAnalyzer_GetAverageIncome_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (+__ZNK20CResourceMapAnalyzer16GetAverageIncomeEv(($2|0)));
 STACKTOP = sp;return (+$3);
}
function _emscripten_bind_CResourceMapAnalyzer___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZN20CResourceMapAnalyzerD2Ev($2);
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function __ZN20CResourceMapAnalyzerD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 136|0);
 __ZNSt3__26vectorI6float3NS_9allocatorIS1_EEED2Ev($3);
 $4 = ((($2)) + 124|0);
 __ZNSt3__26vectorIiNS_9allocatorIiEEED2Ev($4);
 $5 = ((($2)) + 112|0);
 __ZNSt3__26vectorIhNS_9allocatorIhEEED2Ev($5);
 $6 = ((($2)) + 100|0);
 __ZNSt3__26vectorIhNS_9allocatorIhEEED2Ev($6);
 $7 = ((($2)) + 88|0);
 __ZNSt3__26vectorIhNS_9allocatorIhEEED2Ev($7);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_HasFunction_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (__ZNK14CLuaUnitScript11HasFunctionEi($4,$5)|0);
 STACKTOP = sp;return ($6|0);
}
function __ZNK14CLuaUnitScript11HasFunctionEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $4 = $0;
 $5 = $1;
 $6 = $4;
 $7 = ((($6)) + 72|0);
 $8 = $5;
 $2 = $7;
 $3 = $8;
 $9 = $2;
 $10 = $3;
 $11 = HEAP32[$9>>2]|0;
 $12 = (($11) + ($10<<2)|0);
 $13 = HEAP32[$12>>2]|0;
 $14 = ($13|0)>=(0);
 STACKTOP = sp;return ($14|0);
}
function _emscripten_bind_CLuaUnitScript_HasBlockShot_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 16|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 $9 = (FUNCTION_TABLE_iii[$7 & 0]($4,$8)|0);
 STACKTOP = sp;return ($9|0);
}
function _emscripten_bind_CLuaUnitScript_HasTargetWeight_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 20|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 $9 = (FUNCTION_TABLE_iii[$7 & 0]($4,$8)|0);
 STACKTOP = sp;return ($9|0);
}
function _emscripten_bind_CLuaUnitScript_RawCall_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 24|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 FUNCTION_TABLE_vii[$7 & 31]($4,$8);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_Create_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 28|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_Killed_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 32|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_WindChanged_2($0,$1,$2) {
 $0 = $0|0;
 $1 = +$1;
 $2 = +$2;
 var $10 = 0.0, $11 = 0.0, $3 = 0, $4 = 0.0, $5 = 0.0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $6 = $3;
 $7 = HEAP32[$6>>2]|0;
 $8 = ((($7)) + 36|0);
 $9 = HEAP32[$8>>2]|0;
 $10 = $4;
 $11 = $5;
 FUNCTION_TABLE_vidd[$9 & 0]($6,$10,$11);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_ExtractionRateChanged_1($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 40|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 FUNCTION_TABLE_vid[$7 & 0]($4,$8);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_SetSFXOccupy_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 60|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 FUNCTION_TABLE_vii[$7 & 31]($4,$8);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_StartBuilding_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 128|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_StartBuilding_2($0,$1,$2) {
 $0 = $0|0;
 $1 = +$1;
 $2 = +$2;
 var $10 = 0.0, $11 = 0.0, $3 = 0, $4 = 0.0, $5 = 0.0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $6 = $3;
 $7 = HEAP32[$6>>2]|0;
 $8 = ((($7)) + 84|0);
 $9 = HEAP32[$8>>2]|0;
 $10 = $4;
 $11 = $5;
 FUNCTION_TABLE_vidd[$9 & 0]($6,$10,$11);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_QueryNanoPiece_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 88|0);
 $5 = HEAP32[$4>>2]|0;
 $6 = (FUNCTION_TABLE_ii[$5 & 1]($2)|0);
 STACKTOP = sp;return ($6|0);
}
function _emscripten_bind_CLuaUnitScript_QueryBuildInfo_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 92|0);
 $5 = HEAP32[$4>>2]|0;
 $6 = (FUNCTION_TABLE_ii[$5 & 1]($2)|0);
 STACKTOP = sp;return ($6|0);
}
function _emscripten_bind_CLuaUnitScript_Destroy_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 96|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_StartMoving_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $10 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = HEAP32[$5>>2]|0;
 $7 = ((($6)) + 100|0);
 $8 = HEAP32[$7>>2]|0;
 $9 = $3;
 $10 = $9&1;
 FUNCTION_TABLE_vii[$8 & 31]($5,$10);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_StopMoving_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 104|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_StartUnload_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 120|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_EndTransport_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 124|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_StopBuilding_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 132|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_Falling_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 136|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_Landed_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 140|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_Activate_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 144|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_Deactivate_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 148|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_MoveRate_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 152|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 FUNCTION_TABLE_vii[$7 & 31]($4,$8);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_FireWeapon_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 156|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 FUNCTION_TABLE_vii[$7 & 31]($4,$8);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_EndBurst_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 160|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 FUNCTION_TABLE_vii[$7 & 31]($4,$8);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_QueryWeapon_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 164|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 $9 = (FUNCTION_TABLE_iii[$7 & 0]($4,$8)|0);
 STACKTOP = sp;return ($9|0);
}
function _emscripten_bind_CLuaUnitScript_AimWeapon_3($0,$1,$2,$3) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = +$2;
 $3 = +$3;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0.0, $14 = 0.0, $4 = 0, $5 = 0, $6 = 0.0, $7 = 0.0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $4 = $0;
 $5 = $1;
 $6 = $2;
 $7 = $3;
 $8 = $4;
 $9 = HEAP32[$8>>2]|0;
 $10 = ((($9)) + 168|0);
 $11 = HEAP32[$10>>2]|0;
 $12 = $5;
 $13 = $6;
 $14 = $7;
 FUNCTION_TABLE_viidd[$11 & 0]($8,$12,$13,$14);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript_AimFromWeapon_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 176|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 $9 = (FUNCTION_TABLE_iii[$7 & 0]($4,$8)|0);
 STACKTOP = sp;return ($9|0);
}
function _emscripten_bind_CLuaUnitScript_Shot_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = HEAP32[$4>>2]|0;
 $6 = ((($5)) + 180|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = $3;
 FUNCTION_TABLE_vii[$7 & 31]($4,$8);
 STACKTOP = sp;return;
}
function _emscripten_bind_CLuaUnitScript___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 12|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CMobileCAI_StopMove_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 52|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CMobileCAI_StopMoveAndFinishCommand_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN10CMobileCAI24StopMoveAndFinishCommandEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CMobileCAI_SlowUpdate_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 32|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CMobileCAI_NonMoving_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN10CMobileCAI9NonMovingEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CMobileCAI_FinishCommand_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 40|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CMobileCAI_CanSetMaxSpeed_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 48|0);
 $5 = HEAP32[$4>>2]|0;
 $6 = (FUNCTION_TABLE_ii[$5 & 1]($2)|0);
 STACKTOP = sp;return ($6|0);
}
function _emscripten_bind_CMobileCAI_StopSlowGuard_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN10CMobileCAI13StopSlowGuardEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CMobileCAI_StartSlowGuard_1($0,$1) {
 $0 = $0|0;
 $1 = +$1;
 var $2 = 0, $3 = 0.0, $4 = 0, $5 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 __ZN10CMobileCAI14StartSlowGuardEf(($4|0),(+$5));
 STACKTOP = sp;return;
}
function _emscripten_bind_CMobileCAI_Execute_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 80|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CMobileCAI_GetCancelDistance_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZN10CMobileCAI17GetCancelDistanceEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZN10CMobileCAI17GetCancelDistanceEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 324|0);
 $4 = HEAP32[$3>>2]|0;
 STACKTOP = sp;return ($4|0);
}
function _emscripten_bind_CMobileCAI___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CExtractorBuilding_ResetExtraction_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN18CExtractorBuilding15ResetExtractionEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CExtractorBuilding_SetExtractionRangeAndDepth_2($0,$1,$2) {
 $0 = $0|0;
 $1 = +$1;
 $2 = +$2;
 var $3 = 0, $4 = 0.0, $5 = 0.0, $6 = 0, $7 = 0.0, $8 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $6 = $3;
 $7 = $4;
 $8 = $5;
 __ZN18CExtractorBuilding26SetExtractionRangeAndDepthEff(($6|0),(+$7),(+$8));
 STACKTOP = sp;return;
}
function _emscripten_bind_CExtractorBuilding_ReCalculateMetalExtraction_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN18CExtractorBuilding26ReCalculateMetalExtractionEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CExtractorBuilding_GetExtractionRange_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (+__ZNK18CExtractorBuilding18GetExtractionRangeEv($2));
 STACKTOP = sp;return (+$3);
}
function __ZNK18CExtractorBuilding18GetExtractionRangeEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 3256|0);
 $4 = +HEAPF32[$3>>2];
 STACKTOP = sp;return (+$4);
}
function _emscripten_bind_CExtractorBuilding_GetExtractionDepth_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (+__ZNK18CExtractorBuilding18GetExtractionDepthEv($2));
 STACKTOP = sp;return (+$3);
}
function __ZNK18CExtractorBuilding18GetExtractionDepthEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 3260|0);
 $4 = +HEAPF32[$3>>2];
 STACKTOP = sp;return (+$4);
}
function _emscripten_bind_CExtractorBuilding_FinishedBuilding_1($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $10 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $4 = $1&1;
 $3 = $4;
 $5 = $2;
 $6 = HEAP32[$5>>2]|0;
 $7 = ((($6)) + 108|0);
 $8 = HEAP32[$7>>2]|0;
 $9 = $3;
 $10 = $9&1;
 FUNCTION_TABLE_vii[$8 & 31]($5,$10);
 STACKTOP = sp;return;
}
function _emscripten_bind_CExtractorBuilding___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CModInfo_ResetState_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN8CModInfo10ResetStateEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CModInfo___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZN8CModInfoD2Ev($2);
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function __ZN8CModInfoD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 72|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($3);
 $4 = ((($2)) + 60|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($4);
 $5 = ((($2)) + 48|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($5);
 $6 = ((($2)) + 36|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($6);
 $7 = ((($2)) + 24|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($7);
 $8 = ((($2)) + 12|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($8);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CCommandQueue_empty_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK13CCommandQueue5emptyEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK13CCommandQueue5emptyEv($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(32|0);
 $5 = $0;
 $6 = $5;
 $4 = $6;
 $7 = $4;
 $3 = $7;
 $8 = $3;
 $9 = ((($8)) + 20|0);
 $2 = $9;
 $10 = $2;
 $1 = $10;
 $11 = $1;
 $12 = HEAP32[$11>>2]|0;
 $13 = ($12|0)==(0);
 STACKTOP = sp;return ($13|0);
}
function _emscripten_bind_CCommandQueue_pop_back_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN13CCommandQueue8pop_backEv($2);
 STACKTOP = sp;return;
}
function __ZN13CCommandQueue8pop_backEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__25dequeI7CommandNS_9allocatorIS1_EEE8pop_backEv($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CCommandQueue_pop_front_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN13CCommandQueue9pop_frontEv($2);
 STACKTOP = sp;return;
}
function __ZN13CCommandQueue9pop_frontEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__25dequeI7CommandNS_9allocatorIS1_EEE9pop_frontEv($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CCommandQueue_clear_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN13CCommandQueue5clearEv($2);
 STACKTOP = sp;return;
}
function __ZN13CCommandQueue5clearEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $2;
 $1 = $3;
 $4 = $1;
 __ZNSt3__212__deque_baseI7CommandNS_9allocatorIS1_EEE5clearEv($4);
 STACKTOP = sp;return;
}
function _emscripten_bind_CCommandQueue___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZN13CCommandQueueD2Ev($2);
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function __ZN13CCommandQueueD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__25dequeI7CommandNS_9allocatorIS1_EEED2Ev($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CBuilderCAI_InitStatic_0($0) {
 $0 = $0|0;
 var $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 __ZN11CBuilderCAI10InitStaticEv();
 STACKTOP = sp;return;
}
function _emscripten_bind_CBuilderCAI_PostLoad_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN11CBuilderCAI8PostLoadEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CBuilderCAI_SlowUpdate_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 32|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CBuilderCAI_FinishCommand_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ((($3)) + 40|0);
 $5 = HEAP32[$4>>2]|0;
 FUNCTION_TABLE_vi[$5 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CBuilderCAI___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 $4 = HEAP32[$2>>2]|0;
 $5 = ((($4)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 FUNCTION_TABLE_vi[$6 & 31]($2);
 STACKTOP = sp;return;
}
function _emscripten_bind_CMoveMath___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CGlobalSynced_ResetState_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN13CGlobalSynced10ResetStateEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CGlobalSynced_GetLuaSimFrame_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZN13CGlobalSynced14GetLuaSimFrameEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZN13CGlobalSynced14GetLuaSimFrameEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ($3|0)>(0);
 if ($4) {
  $5 = HEAP32[$2>>2]|0;
  $6 = $5;
 } else {
  $6 = 0;
 }
 STACKTOP = sp;return ($6|0);
}
function _emscripten_bind_CGlobalSynced_GetTempNum_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZN13CGlobalSynced10GetTempNumEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZN13CGlobalSynced10GetTempNumEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 20|0);
 $4 = HEAP32[$3>>2]|0;
 $5 = (($4) + 1)|0;
 HEAP32[$3>>2] = $5;
 STACKTOP = sp;return ($4|0);
}
function _emscripten_bind_CGlobalSynced_PreSimFrame_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = (__ZNK13CGlobalSynced11PreSimFrameEv($2)|0);
 STACKTOP = sp;return ($3|0);
}
function __ZNK13CGlobalSynced11PreSimFrameEv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = HEAP32[$2>>2]|0;
 $4 = ($3|0)==(-1);
 STACKTOP = sp;return ($4|0);
}
function _emscripten_bind_CGlobalSynced___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if (!($3)) {
  __ZN13CGlobalSyncedD1Ev(($2|0));
  __ZdlPv($2);
 }
 STACKTOP = sp;return;
}
function _emscripten_bind_CExplosionGeneratorHandler_ParseExplosionTables_0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZN26CExplosionGeneratorHandler20ParseExplosionTablesEv(($2|0));
 STACKTOP = sp;return;
}
function _emscripten_bind_CExplosionGeneratorHandler___destroy___0($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)==(0|0);
 if ($3) {
  STACKTOP = sp;return;
 }
 __ZN26CExplosionGeneratorHandlerD1Ev(($2|0));
 __ZdlPv($2);
 STACKTOP = sp;return;
}
function __ZNSt3__26vectorItNS_9allocatorItEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__213__vector_baseItNS_9allocatorItEEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__213__vector_baseItNS_9allocatorItEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 128|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(128|0);
 $19 = sp;
 $22 = sp + 116|0;
 $30 = $0;
 $31 = $30;
 $32 = HEAP32[$31>>2]|0;
 $33 = ($32|0)!=(0|0);
 if (!($33)) {
  STACKTOP = sp;return;
 }
 $29 = $31;
 $34 = $29;
 $35 = HEAP32[$34>>2]|0;
 $27 = $34;
 $28 = $35;
 $36 = $27;
 while(1) {
  $37 = $28;
  $38 = ((($36)) + 4|0);
  $39 = HEAP32[$38>>2]|0;
  $40 = ($37|0)!=($39|0);
  if (!($40)) {
   break;
  }
  $26 = $36;
  $41 = $26;
  $42 = ((($41)) + 8|0);
  $25 = $42;
  $43 = $25;
  $24 = $43;
  $44 = $24;
  $45 = ((($36)) + 4|0);
  $46 = HEAP32[$45>>2]|0;
  $47 = ((($46)) + -2|0);
  HEAP32[$45>>2] = $47;
  $23 = $47;
  $48 = $23;
  $20 = $44;
  $21 = $48;
  $49 = $20;
  $50 = $21;
  ;HEAP8[$19>>0]=HEAP8[$22>>0]|0;
  $17 = $49;
  $18 = $50;
  $51 = $17;
  $52 = $18;
  $15 = $51;
  $16 = $52;
 }
 $7 = $31;
 $53 = $7;
 $54 = ((($53)) + 8|0);
 $6 = $54;
 $55 = $6;
 $5 = $55;
 $56 = $5;
 $57 = HEAP32[$31>>2]|0;
 $4 = $31;
 $58 = $4;
 $3 = $58;
 $59 = $3;
 $60 = ((($59)) + 8|0);
 $2 = $60;
 $61 = $2;
 $1 = $61;
 $62 = $1;
 $63 = HEAP32[$62>>2]|0;
 $64 = HEAP32[$58>>2]|0;
 $65 = $63;
 $66 = $64;
 $67 = (($65) - ($66))|0;
 $68 = (($67|0) / 2)&-1;
 $12 = $56;
 $13 = $57;
 $14 = $68;
 $69 = $12;
 $70 = $13;
 $71 = $14;
 $9 = $69;
 $10 = $70;
 $11 = $71;
 $72 = $10;
 $8 = $72;
 $73 = $8;
 __ZdlPv($73);
 STACKTOP = sp;return;
}
function ___clang_call_terminate($0) {
 $0 = $0|0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 (___cxa_begin_catch(($0|0))|0);
 __ZSt9terminatev();
 // unreachable;
}
function __ZN6emilib7HashMapINSt3__212basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_N6spring11synced_hashIS7_EENS_14HashMapEqualToIS7_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $3 = $1;
 $2 = 0;
 while(1) {
  $4 = $2;
  $5 = ((($3)) + 12|0);
  $6 = HEAP32[$5>>2]|0;
  $7 = ($4>>>0)<($6>>>0);
  if (!($7)) {
   break;
  }
  $8 = $2;
  $9 = ((($3)) + 4|0);
  $10 = HEAP32[$9>>2]|0;
  $11 = (($10) + ($8)|0);
  $12 = HEAP8[$11>>0]|0;
  $13 = ($12<<24>>24)==(2);
  if ($13) {
   $14 = $2;
   $15 = ((($3)) + 8|0);
   $16 = HEAP32[$15>>2]|0;
   $17 = (($16) + (($14*24)|0)|0);
   __ZNSt3__24pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_ED2Ev($17);
  }
  $18 = $2;
  $19 = (($18) + 1)|0;
  $2 = $19;
 }
 $20 = ((($3)) + 4|0);
 $21 = HEAP32[$20>>2]|0;
 __THREW__ = 0;
 invoke_vi(18,($21|0));
 $22 = __THREW__; __THREW__ = 0;
 $23 = $22&1;
 if ($23) {
  $28 = ___cxa_find_matching_catch_3(0|0)|0;
  $29 = tempRet0;
  ___clang_call_terminate($28);
  // unreachable;
 }
 $24 = ((($3)) + 8|0);
 $25 = HEAP32[$24>>2]|0;
 __THREW__ = 0;
 invoke_vi(18,($25|0));
 $26 = __THREW__; __THREW__ = 0;
 $27 = $26&1;
 if ($27) {
  $28 = ___cxa_find_matching_catch_3(0|0)|0;
  $29 = tempRet0;
  ___clang_call_terminate($28);
  // unreachable;
 } else {
  STACKTOP = sp;return;
 }
}
function __ZN6emilib7HashMapINSt3__212basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiN6spring11synced_hashIS7_EENS_14HashMapEqualToIS7_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $3 = $1;
 $2 = 0;
 while(1) {
  $4 = $2;
  $5 = ((($3)) + 12|0);
  $6 = HEAP32[$5>>2]|0;
  $7 = ($4>>>0)<($6>>>0);
  if (!($7)) {
   break;
  }
  $8 = $2;
  $9 = ((($3)) + 4|0);
  $10 = HEAP32[$9>>2]|0;
  $11 = (($10) + ($8)|0);
  $12 = HEAP8[$11>>0]|0;
  $13 = ($12<<24>>24)==(2);
  if ($13) {
   $14 = $2;
   $15 = ((($3)) + 8|0);
   $16 = HEAP32[$15>>2]|0;
   $17 = (($16) + ($14<<4)|0);
   __ZNSt3__24pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEiED2Ev($17);
  }
  $18 = $2;
  $19 = (($18) + 1)|0;
  $2 = $19;
 }
 $20 = ((($3)) + 4|0);
 $21 = HEAP32[$20>>2]|0;
 __THREW__ = 0;
 invoke_vi(18,($21|0));
 $22 = __THREW__; __THREW__ = 0;
 $23 = $22&1;
 if ($23) {
  $28 = ___cxa_find_matching_catch_3(0|0)|0;
  $29 = tempRet0;
  ___clang_call_terminate($28);
  // unreachable;
 }
 $24 = ((($3)) + 8|0);
 $25 = HEAP32[$24>>2]|0;
 __THREW__ = 0;
 invoke_vi(18,($25|0));
 $26 = __THREW__; __THREW__ = 0;
 $27 = $26&1;
 if ($27) {
  $28 = ___cxa_find_matching_catch_3(0|0)|0;
  $29 = tempRet0;
  ___clang_call_terminate($28);
  // unreachable;
 } else {
  STACKTOP = sp;return;
 }
}
function __ZNSt3__26vectorI7UnitDefNS_9allocatorIS1_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__213__vector_baseI7UnitDefNS_9allocatorIS1_EEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZN6emilib7HashSetIiN6spring11synced_hashIiEENS_14HashSetEqualToIiEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $3 = 0, $4 = 0;
 var $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $3 = $1;
 $2 = 0;
 while(1) {
  $4 = $2;
  $5 = ((($3)) + 12|0);
  $6 = HEAP32[$5>>2]|0;
  $7 = ($4>>>0)<($6>>>0);
  if (!($7)) {
   break;
  }
  $8 = $2;
  $9 = ((($3)) + 4|0);
  $10 = HEAP32[$9>>2]|0;
  $11 = (($10) + ($8)|0);
  $12 = HEAP8[$11>>0]|0;
  $13 = ($12<<24>>24)==(2);
  if ($13) {
  }
  $14 = $2;
  $15 = (($14) + 1)|0;
  $2 = $15;
 }
 $16 = ((($3)) + 4|0);
 $17 = HEAP32[$16>>2]|0;
 __THREW__ = 0;
 invoke_vi(18,($17|0));
 $18 = __THREW__; __THREW__ = 0;
 $19 = $18&1;
 if ($19) {
  $24 = ___cxa_find_matching_catch_3(0|0)|0;
  $25 = tempRet0;
  ___clang_call_terminate($24);
  // unreachable;
 }
 $20 = ((($3)) + 8|0);
 $21 = HEAP32[$20>>2]|0;
 __THREW__ = 0;
 invoke_vi(18,($21|0));
 $22 = __THREW__; __THREW__ = 0;
 $23 = $22&1;
 if ($23) {
  $24 = ___cxa_find_matching_catch_3(0|0)|0;
  $25 = tempRet0;
  ___clang_call_terminate($24);
  // unreachable;
 } else {
  STACKTOP = sp;return;
 }
}
function __ZN6emilib7HashMapIiNS_7HashSetIiN6spring11synced_hashIiEENS_14HashSetEqualToIiEEEES4_NS_14HashMapEqualToIiEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $3 = $1;
 $2 = 0;
 while(1) {
  $4 = $2;
  $5 = ((($3)) + 12|0);
  $6 = HEAP32[$5>>2]|0;
  $7 = ($4>>>0)<($6>>>0);
  if (!($7)) {
   break;
  }
  $8 = $2;
  $9 = ((($3)) + 4|0);
  $10 = HEAP32[$9>>2]|0;
  $11 = (($10) + ($8)|0);
  $12 = HEAP8[$11>>0]|0;
  $13 = ($12<<24>>24)==(2);
  if ($13) {
   $14 = $2;
   $15 = ((($3)) + 8|0);
   $16 = HEAP32[$15>>2]|0;
   $17 = (($16) + ($14<<5)|0);
   __ZNSt3__24pairIiN6emilib7HashSetIiN6spring11synced_hashIiEENS1_14HashSetEqualToIiEEEEED2Ev($17);
  }
  $18 = $2;
  $19 = (($18) + 1)|0;
  $2 = $19;
 }
 $20 = ((($3)) + 4|0);
 $21 = HEAP32[$20>>2]|0;
 __THREW__ = 0;
 invoke_vi(18,($21|0));
 $22 = __THREW__; __THREW__ = 0;
 $23 = $22&1;
 if ($23) {
  $28 = ___cxa_find_matching_catch_3(0|0)|0;
  $29 = tempRet0;
  ___clang_call_terminate($28);
  // unreachable;
 }
 $24 = ((($3)) + 8|0);
 $25 = HEAP32[$24>>2]|0;
 __THREW__ = 0;
 invoke_vi(18,($25|0));
 $26 = __THREW__; __THREW__ = 0;
 $27 = $26&1;
 if ($27) {
  $28 = ___cxa_find_matching_catch_3(0|0)|0;
  $29 = tempRet0;
  ___clang_call_terminate($28);
  // unreachable;
 } else {
  STACKTOP = sp;return;
 }
}
function __ZNSt3__24pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_ED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 12|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($3);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__24pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEiED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__213__vector_baseI7UnitDefNS_9allocatorIS1_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 128|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(128|0);
 $19 = sp;
 $22 = sp + 116|0;
 $30 = $0;
 $31 = $30;
 $32 = HEAP32[$31>>2]|0;
 $33 = ($32|0)!=(0|0);
 if (!($33)) {
  STACKTOP = sp;return;
 }
 $29 = $31;
 $34 = $29;
 $35 = HEAP32[$34>>2]|0;
 $27 = $34;
 $28 = $35;
 $36 = $27;
 while(1) {
  $37 = $28;
  $38 = ((($36)) + 4|0);
  $39 = HEAP32[$38>>2]|0;
  $40 = ($37|0)!=($39|0);
  if (!($40)) {
   break;
  }
  $26 = $36;
  $41 = $26;
  $42 = ((($41)) + 8|0);
  $25 = $42;
  $43 = $25;
  $24 = $43;
  $44 = $24;
  $45 = ((($36)) + 4|0);
  $46 = HEAP32[$45>>2]|0;
  $47 = ((($46)) + -1232|0);
  HEAP32[$45>>2] = $47;
  $23 = $47;
  $48 = $23;
  $20 = $44;
  $21 = $48;
  $49 = $20;
  $50 = $21;
  ;HEAP8[$19>>0]=HEAP8[$22>>0]|0;
  $17 = $49;
  $18 = $50;
  $51 = $17;
  $52 = $18;
  $15 = $51;
  $16 = $52;
  $53 = $16;
  $54 = HEAP32[$53>>2]|0;
  $55 = HEAP32[$54>>2]|0;
  FUNCTION_TABLE_vi[$55 & 31]($53);
 }
 $14 = $31;
 $56 = $14;
 $57 = ((($56)) + 8|0);
 $13 = $57;
 $58 = $13;
 $12 = $58;
 $59 = $12;
 $60 = HEAP32[$31>>2]|0;
 $4 = $31;
 $61 = $4;
 $3 = $61;
 $62 = $3;
 $63 = ((($62)) + 8|0);
 $2 = $63;
 $64 = $2;
 $1 = $64;
 $65 = $1;
 $66 = HEAP32[$65>>2]|0;
 $67 = HEAP32[$61>>2]|0;
 $68 = $66;
 $69 = $67;
 $70 = (($68) - ($69))|0;
 $71 = (($70|0) / 1232)&-1;
 $9 = $59;
 $10 = $60;
 $11 = $71;
 $72 = $9;
 $73 = $10;
 $74 = $11;
 $6 = $72;
 $7 = $73;
 $8 = $74;
 $75 = $7;
 $5 = $75;
 $76 = $5;
 __ZdlPv($76);
 STACKTOP = sp;return;
}
function __ZNSt3__24pairIiN6emilib7HashSetIiN6spring11synced_hashIiEENS1_14HashSetEqualToIiEEEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 4|0);
 __ZN6emilib7HashSetIiN6spring11synced_hashIiEENS_14HashSetEqualToIiEEED2Ev($3);
 STACKTOP = sp;return;
}
function __ZNSt3__26vectorI9WeaponDefNS_9allocatorIS1_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__213__vector_baseI9WeaponDefNS_9allocatorIS1_EEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__213__vector_baseI9WeaponDefNS_9allocatorIS1_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 128|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(128|0);
 $19 = sp;
 $22 = sp + 116|0;
 $30 = $0;
 $31 = $30;
 $32 = HEAP32[$31>>2]|0;
 $33 = ($32|0)!=(0|0);
 if (!($33)) {
  STACKTOP = sp;return;
 }
 $29 = $31;
 $34 = $29;
 $35 = HEAP32[$34>>2]|0;
 $27 = $34;
 $28 = $35;
 $36 = $27;
 while(1) {
  $37 = $28;
  $38 = ((($36)) + 4|0);
  $39 = HEAP32[$38>>2]|0;
  $40 = ($37|0)!=($39|0);
  if (!($40)) {
   break;
  }
  $26 = $36;
  $41 = $26;
  $42 = ((($41)) + 8|0);
  $25 = $42;
  $43 = $25;
  $24 = $43;
  $44 = $24;
  $45 = ((($36)) + 4|0);
  $46 = HEAP32[$45>>2]|0;
  $47 = ((($46)) + -748|0);
  HEAP32[$45>>2] = $47;
  $23 = $47;
  $48 = $23;
  $20 = $44;
  $21 = $48;
  $49 = $20;
  $50 = $21;
  ;HEAP8[$19>>0]=HEAP8[$22>>0]|0;
  $17 = $49;
  $18 = $50;
  $51 = $17;
  $52 = $18;
  $15 = $51;
  $16 = $52;
  $53 = $16;
  __ZN9WeaponDefD2Ev($53);
 }
 $14 = $31;
 $54 = $14;
 $55 = ((($54)) + 8|0);
 $13 = $55;
 $56 = $13;
 $12 = $56;
 $57 = $12;
 $58 = HEAP32[$31>>2]|0;
 $4 = $31;
 $59 = $4;
 $3 = $59;
 $60 = $3;
 $61 = ((($60)) + 8|0);
 $2 = $61;
 $62 = $2;
 $1 = $62;
 $63 = $1;
 $64 = HEAP32[$63>>2]|0;
 $65 = HEAP32[$59>>2]|0;
 $66 = $64;
 $67 = $65;
 $68 = (($66) - ($67))|0;
 $69 = (($68|0) / 748)&-1;
 $9 = $57;
 $10 = $58;
 $11 = $69;
 $70 = $9;
 $71 = $10;
 $72 = $11;
 $6 = $70;
 $7 = $71;
 $8 = $72;
 $73 = $7;
 $5 = $73;
 $74 = $5;
 __ZdlPv($74);
 STACKTOP = sp;return;
}
function __ZN9WeaponDefD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 548|0);
 __ZN9WeaponDef7VisualsD2Ev($3);
 $4 = ((($2)) + 520|0);
 __ZN6emilib7HashMapINSt3__212basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_N6spring11synced_hashIS7_EENS_14HashMapEqualToIS7_EEED2Ev($4);
 $5 = ((($2)) + 460|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($5);
 $6 = ((($2)) + 112|0);
 __ZN14DynDamageArrayD1Ev(($6|0));
 $7 = ((($2)) + 60|0);
 __ZN11GuiSoundSetD2Ev($7);
 $8 = ((($2)) + 48|0);
 __ZN11GuiSoundSetD2Ev($8);
 $9 = ((($2)) + 24|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($9);
 $10 = ((($2)) + 12|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($10);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZN9WeaponDef7VisualsD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 112|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($3);
 $4 = ((($2)) + 100|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($4);
 $5 = ((($2)) + 88|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($5);
 $6 = ((($2)) + 40|0);
 $7 = ((($6)) + 48|0);
 $9 = $7;
 while(1) {
  $8 = ((($9)) + -12|0);
  __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($8);
  $10 = ($8|0)==($6|0);
  if ($10) {
   break;
  } else {
   $9 = $8;
  }
 }
 $11 = ((($2)) + 28|0);
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($11);
 STACKTOP = sp;return;
}
function __ZN11GuiSoundSetD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__26vectorIN11GuiSoundSet4DataENS_9allocatorIS2_EEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__26vectorIN11GuiSoundSet4DataENS_9allocatorIS2_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__213__vector_baseIN11GuiSoundSet4DataENS_9allocatorIS2_EEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__213__vector_baseIN11GuiSoundSet4DataENS_9allocatorIS2_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 128|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(128|0);
 $19 = sp;
 $22 = sp + 116|0;
 $30 = $0;
 $31 = $30;
 $32 = HEAP32[$31>>2]|0;
 $33 = ($32|0)!=(0|0);
 if (!($33)) {
  STACKTOP = sp;return;
 }
 $29 = $31;
 $34 = $29;
 $35 = HEAP32[$34>>2]|0;
 $27 = $34;
 $28 = $35;
 $36 = $27;
 while(1) {
  $37 = $28;
  $38 = ((($36)) + 4|0);
  $39 = HEAP32[$38>>2]|0;
  $40 = ($37|0)!=($39|0);
  if (!($40)) {
   break;
  }
  $26 = $36;
  $41 = $26;
  $42 = ((($41)) + 8|0);
  $25 = $42;
  $43 = $25;
  $24 = $43;
  $44 = $24;
  $45 = ((($36)) + 4|0);
  $46 = HEAP32[$45>>2]|0;
  $47 = ((($46)) + -20|0);
  HEAP32[$45>>2] = $47;
  $23 = $47;
  $48 = $23;
  $20 = $44;
  $21 = $48;
  $49 = $20;
  $50 = $21;
  ;HEAP8[$19>>0]=HEAP8[$22>>0]|0;
  $17 = $49;
  $18 = $50;
  $51 = $17;
  $52 = $18;
  $15 = $51;
  $16 = $52;
  $53 = $16;
  __ZN11GuiSoundSet4DataD2Ev($53);
 }
 $14 = $31;
 $54 = $14;
 $55 = ((($54)) + 8|0);
 $13 = $55;
 $56 = $13;
 $12 = $56;
 $57 = $12;
 $58 = HEAP32[$31>>2]|0;
 $4 = $31;
 $59 = $4;
 $3 = $59;
 $60 = $3;
 $61 = ((($60)) + 8|0);
 $2 = $61;
 $62 = $2;
 $1 = $62;
 $63 = $1;
 $64 = HEAP32[$63>>2]|0;
 $65 = HEAP32[$59>>2]|0;
 $66 = $64;
 $67 = $65;
 $68 = (($66) - ($67))|0;
 $69 = (($68|0) / 20)&-1;
 $9 = $57;
 $10 = $58;
 $11 = $69;
 $70 = $9;
 $71 = $10;
 $72 = $11;
 $6 = $70;
 $7 = $71;
 $8 = $72;
 $73 = $7;
 $5 = $73;
 $74 = $5;
 __ZdlPv($74);
 STACKTOP = sp;return;
}
function __ZN11GuiSoundSet4DataD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__26vectorIP11CUnitScriptNS_9allocatorIS2_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__213__vector_baseIP11CUnitScriptNS_9allocatorIS2_EEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__213__vector_baseIP11CUnitScriptNS_9allocatorIS2_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 128|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(128|0);
 $19 = sp;
 $22 = sp + 116|0;
 $30 = $0;
 $31 = $30;
 $32 = HEAP32[$31>>2]|0;
 $33 = ($32|0)!=(0|0);
 if (!($33)) {
  STACKTOP = sp;return;
 }
 $29 = $31;
 $34 = $29;
 $35 = HEAP32[$34>>2]|0;
 $27 = $34;
 $28 = $35;
 $36 = $27;
 while(1) {
  $37 = $28;
  $38 = ((($36)) + 4|0);
  $39 = HEAP32[$38>>2]|0;
  $40 = ($37|0)!=($39|0);
  if (!($40)) {
   break;
  }
  $26 = $36;
  $41 = $26;
  $42 = ((($41)) + 8|0);
  $25 = $42;
  $43 = $25;
  $24 = $43;
  $44 = $24;
  $45 = ((($36)) + 4|0);
  $46 = HEAP32[$45>>2]|0;
  $47 = ((($46)) + -4|0);
  HEAP32[$45>>2] = $47;
  $23 = $47;
  $48 = $23;
  $20 = $44;
  $21 = $48;
  $49 = $20;
  $50 = $21;
  ;HEAP8[$19>>0]=HEAP8[$22>>0]|0;
  $17 = $49;
  $18 = $50;
  $51 = $17;
  $52 = $18;
  $15 = $51;
  $16 = $52;
 }
 $7 = $31;
 $53 = $7;
 $54 = ((($53)) + 8|0);
 $6 = $54;
 $55 = $6;
 $5 = $55;
 $56 = $5;
 $57 = HEAP32[$31>>2]|0;
 $4 = $31;
 $58 = $4;
 $3 = $58;
 $59 = $3;
 $60 = ((($59)) + 8|0);
 $2 = $60;
 $61 = $2;
 $1 = $61;
 $62 = $1;
 $63 = HEAP32[$62>>2]|0;
 $64 = HEAP32[$58>>2]|0;
 $65 = $63;
 $66 = $64;
 $67 = (($65) - ($66))|0;
 $68 = (($67|0) / 4)&-1;
 $12 = $56;
 $13 = $57;
 $14 = $68;
 $69 = $12;
 $70 = $13;
 $71 = $14;
 $9 = $69;
 $10 = $70;
 $11 = $71;
 $72 = $10;
 $8 = $72;
 $73 = $8;
 __ZdlPv($73);
 STACKTOP = sp;return;
}
function __ZNK6float3mlEf($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = +$2;
 var $10 = 0.0, $11 = 0.0, $12 = 0.0, $13 = 0, $14 = 0.0, $15 = 0.0, $16 = 0.0, $3 = 0, $4 = 0.0, $5 = 0, $6 = 0.0, $7 = 0.0, $8 = 0.0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = +HEAPF32[$5>>2];
 $7 = $4;
 $8 = $6 * $7;
 $9 = ((($5)) + 4|0);
 $10 = +HEAPF32[$9>>2];
 $11 = $4;
 $12 = $10 * $11;
 $13 = ((($5)) + 8|0);
 $14 = +HEAPF32[$13>>2];
 $15 = $4;
 $16 = $14 * $15;
 __ZN6float3C2Efff($0,$8,$12,$16);
 STACKTOP = sp;return;
}
function __ZNK6float3ixEi($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $3;
 $6 = (($4) + ($5<<2)|0);
 STACKTOP = sp;return ($6|0);
}
function __ZN6emilib7HashMapINSt3__212basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_N6spring11synced_hashIS7_EENS_14HashMapEqualToIS7_EEE5clearEv($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $3 = 0, $4 = 0;
 var $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $3 = $1;
 $2 = 0;
 while(1) {
  $4 = $2;
  $5 = ((($3)) + 12|0);
  $6 = HEAP32[$5>>2]|0;
  $7 = ($4>>>0)<($6>>>0);
  if (!($7)) {
   break;
  }
  $8 = $2;
  $9 = ((($3)) + 4|0);
  $10 = HEAP32[$9>>2]|0;
  $11 = (($10) + ($8)|0);
  $12 = HEAP8[$11>>0]|0;
  $13 = ($12<<24>>24)==(2);
  if ($13) {
   $14 = $2;
   $15 = ((($3)) + 4|0);
   $16 = HEAP32[$15>>2]|0;
   $17 = (($16) + ($14)|0);
   HEAP8[$17>>0] = 0;
   $18 = $2;
   $19 = ((($3)) + 8|0);
   $20 = HEAP32[$19>>2]|0;
   $21 = (($20) + (($18*24)|0)|0);
   __ZNSt3__24pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_ED2Ev($21);
  }
  $22 = $2;
  $23 = (($22) + 1)|0;
  $2 = $23;
 }
 $24 = ((($3)) + 16|0);
 HEAP32[$24>>2] = 0;
 $25 = ((($3)) + 20|0);
 HEAP32[$25>>2] = -1;
 STACKTOP = sp;return;
}
function __ZNSt3__26vectorI6float3NS_9allocatorIS1_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__213__vector_baseI6float3NS_9allocatorIS1_EEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__26vectorIiNS_9allocatorIiEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__213__vector_baseIiNS_9allocatorIiEEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__26vectorIhNS_9allocatorIhEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__213__vector_baseIhNS_9allocatorIhEEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__213__vector_baseI6float3NS_9allocatorIS1_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 128|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(128|0);
 $19 = sp;
 $22 = sp + 116|0;
 $30 = $0;
 $31 = $30;
 $32 = HEAP32[$31>>2]|0;
 $33 = ($32|0)!=(0|0);
 if (!($33)) {
  STACKTOP = sp;return;
 }
 $29 = $31;
 $34 = $29;
 $35 = HEAP32[$34>>2]|0;
 $27 = $34;
 $28 = $35;
 $36 = $27;
 while(1) {
  $37 = $28;
  $38 = ((($36)) + 4|0);
  $39 = HEAP32[$38>>2]|0;
  $40 = ($37|0)!=($39|0);
  if (!($40)) {
   break;
  }
  $26 = $36;
  $41 = $26;
  $42 = ((($41)) + 8|0);
  $25 = $42;
  $43 = $25;
  $24 = $43;
  $44 = $24;
  $45 = ((($36)) + 4|0);
  $46 = HEAP32[$45>>2]|0;
  $47 = ((($46)) + -12|0);
  HEAP32[$45>>2] = $47;
  $23 = $47;
  $48 = $23;
  $20 = $44;
  $21 = $48;
  $49 = $20;
  $50 = $21;
  ;HEAP8[$19>>0]=HEAP8[$22>>0]|0;
  $17 = $49;
  $18 = $50;
  $51 = $17;
  $52 = $18;
  $15 = $51;
  $16 = $52;
 }
 $7 = $31;
 $53 = $7;
 $54 = ((($53)) + 8|0);
 $6 = $54;
 $55 = $6;
 $5 = $55;
 $56 = $5;
 $57 = HEAP32[$31>>2]|0;
 $4 = $31;
 $58 = $4;
 $3 = $58;
 $59 = $3;
 $60 = ((($59)) + 8|0);
 $2 = $60;
 $61 = $2;
 $1 = $61;
 $62 = $1;
 $63 = HEAP32[$62>>2]|0;
 $64 = HEAP32[$58>>2]|0;
 $65 = $63;
 $66 = $64;
 $67 = (($65) - ($66))|0;
 $68 = (($67|0) / 12)&-1;
 $12 = $56;
 $13 = $57;
 $14 = $68;
 $69 = $12;
 $70 = $13;
 $71 = $14;
 $9 = $69;
 $10 = $70;
 $11 = $71;
 $72 = $10;
 $8 = $72;
 $73 = $8;
 __ZdlPv($73);
 STACKTOP = sp;return;
}
function __ZNSt3__213__vector_baseIiNS_9allocatorIiEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 128|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(128|0);
 $19 = sp;
 $22 = sp + 116|0;
 $30 = $0;
 $31 = $30;
 $32 = HEAP32[$31>>2]|0;
 $33 = ($32|0)!=(0|0);
 if (!($33)) {
  STACKTOP = sp;return;
 }
 $29 = $31;
 $34 = $29;
 $35 = HEAP32[$34>>2]|0;
 $27 = $34;
 $28 = $35;
 $36 = $27;
 while(1) {
  $37 = $28;
  $38 = ((($36)) + 4|0);
  $39 = HEAP32[$38>>2]|0;
  $40 = ($37|0)!=($39|0);
  if (!($40)) {
   break;
  }
  $26 = $36;
  $41 = $26;
  $42 = ((($41)) + 8|0);
  $25 = $42;
  $43 = $25;
  $24 = $43;
  $44 = $24;
  $45 = ((($36)) + 4|0);
  $46 = HEAP32[$45>>2]|0;
  $47 = ((($46)) + -4|0);
  HEAP32[$45>>2] = $47;
  $23 = $47;
  $48 = $23;
  $20 = $44;
  $21 = $48;
  $49 = $20;
  $50 = $21;
  ;HEAP8[$19>>0]=HEAP8[$22>>0]|0;
  $17 = $49;
  $18 = $50;
  $51 = $17;
  $52 = $18;
  $15 = $51;
  $16 = $52;
 }
 $7 = $31;
 $53 = $7;
 $54 = ((($53)) + 8|0);
 $6 = $54;
 $55 = $6;
 $5 = $55;
 $56 = $5;
 $57 = HEAP32[$31>>2]|0;
 $4 = $31;
 $58 = $4;
 $3 = $58;
 $59 = $3;
 $60 = ((($59)) + 8|0);
 $2 = $60;
 $61 = $2;
 $1 = $61;
 $62 = $1;
 $63 = HEAP32[$62>>2]|0;
 $64 = HEAP32[$58>>2]|0;
 $65 = $63;
 $66 = $64;
 $67 = (($65) - ($66))|0;
 $68 = (($67|0) / 4)&-1;
 $12 = $56;
 $13 = $57;
 $14 = $68;
 $69 = $12;
 $70 = $13;
 $71 = $14;
 $9 = $69;
 $10 = $70;
 $11 = $71;
 $72 = $10;
 $8 = $72;
 $73 = $8;
 __ZdlPv($73);
 STACKTOP = sp;return;
}
function __ZNSt3__213__vector_baseIhNS_9allocatorIhEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 128|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(128|0);
 $19 = sp;
 $22 = sp + 116|0;
 $30 = $0;
 $31 = $30;
 $32 = HEAP32[$31>>2]|0;
 $33 = ($32|0)!=(0|0);
 if (!($33)) {
  STACKTOP = sp;return;
 }
 $29 = $31;
 $34 = $29;
 $35 = HEAP32[$34>>2]|0;
 $27 = $34;
 $28 = $35;
 $36 = $27;
 while(1) {
  $37 = $28;
  $38 = ((($36)) + 4|0);
  $39 = HEAP32[$38>>2]|0;
  $40 = ($37|0)!=($39|0);
  if (!($40)) {
   break;
  }
  $26 = $36;
  $41 = $26;
  $42 = ((($41)) + 8|0);
  $25 = $42;
  $43 = $25;
  $24 = $43;
  $44 = $24;
  $45 = ((($36)) + 4|0);
  $46 = HEAP32[$45>>2]|0;
  $47 = ((($46)) + -1|0);
  HEAP32[$45>>2] = $47;
  $23 = $47;
  $48 = $23;
  $20 = $44;
  $21 = $48;
  $49 = $20;
  $50 = $21;
  ;HEAP8[$19>>0]=HEAP8[$22>>0]|0;
  $17 = $49;
  $18 = $50;
  $51 = $17;
  $52 = $18;
  $15 = $51;
  $16 = $52;
 }
 $7 = $31;
 $53 = $7;
 $54 = ((($53)) + 8|0);
 $6 = $54;
 $55 = $6;
 $5 = $55;
 $56 = $5;
 $57 = HEAP32[$31>>2]|0;
 $4 = $31;
 $58 = $4;
 $3 = $58;
 $59 = $3;
 $60 = ((($59)) + 8|0);
 $2 = $60;
 $61 = $2;
 $1 = $61;
 $62 = $1;
 $63 = HEAP32[$62>>2]|0;
 $64 = HEAP32[$58>>2]|0;
 $65 = $63;
 $66 = $64;
 $67 = (($65) - ($66))|0;
 $12 = $56;
 $13 = $57;
 $14 = $67;
 $68 = $12;
 $69 = $13;
 $70 = $14;
 $9 = $68;
 $10 = $69;
 $11 = $70;
 $71 = $10;
 $8 = $71;
 $72 = $8;
 __ZdlPv($72);
 STACKTOP = sp;return;
}
function __ZNSt3__25dequeI7CommandNS_9allocatorIS1_EEE8pop_backEv($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0;
 var $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0, $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0;
 var $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0, $14 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $15 = 0, $150 = 0, $151 = 0, $152 = 0;
 var $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0, $158 = 0, $159 = 0, $16 = 0, $160 = 0, $161 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0;
 var $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0;
 var $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0;
 var $62 = 0, $63 = 0, $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0;
 var $80 = 0, $81 = 0, $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0;
 var $99 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 224|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(224|0);
 $7 = sp + 16|0;
 $10 = sp + 222|0;
 $36 = sp + 8|0;
 $39 = sp + 221|0;
 $46 = sp;
 $49 = sp + 220|0;
 $54 = $0;
 $57 = $54;
 $53 = $57;
 $58 = $53;
 $59 = ((($58)) + 20|0);
 $52 = $59;
 $60 = $52;
 $51 = $60;
 $61 = $51;
 $55 = $61;
 $24 = $57;
 $62 = $24;
 $63 = ((($62)) + 20|0);
 $23 = $63;
 $64 = $23;
 $22 = $64;
 $65 = $22;
 $66 = HEAP32[$65>>2]|0;
 $67 = ((($57)) + 16|0);
 $68 = HEAP32[$67>>2]|0;
 $69 = (($66) + ($68))|0;
 $70 = (($69) - 1)|0;
 $56 = $70;
 $71 = $55;
 $2 = $57;
 $72 = $2;
 $73 = ((($72)) + 4|0);
 $74 = HEAP32[$73>>2]|0;
 $75 = $56;
 $76 = (($75>>>0) / 113)&-1;
 $77 = (($74) + ($76<<2)|0);
 $78 = HEAP32[$77>>2]|0;
 $79 = $56;
 $80 = (($79>>>0) % 113)&-1;
 $81 = (($78) + (($80*36)|0)|0);
 $1 = $81;
 $82 = $1;
 $8 = $71;
 $9 = $82;
 $83 = $8;
 $84 = $9;
 ;HEAP8[$7>>0]=HEAP8[$10>>0]|0;
 $5 = $83;
 $6 = $84;
 $85 = $5;
 $86 = $6;
 $3 = $85;
 $4 = $86;
 $87 = $4;
 __ZN7CommandD2Ev($87);
 $13 = $57;
 $88 = $13;
 $89 = ((($88)) + 20|0);
 $12 = $89;
 $90 = $12;
 $11 = $90;
 $91 = $11;
 $92 = HEAP32[$91>>2]|0;
 $93 = (($92) + -1)|0;
 HEAP32[$91>>2] = $93;
 $20 = $57;
 $94 = $20;
 $19 = $94;
 $95 = $19;
 $18 = $95;
 $96 = $18;
 $97 = ((($96)) + 8|0);
 $98 = HEAP32[$97>>2]|0;
 $99 = ((($96)) + 4|0);
 $100 = HEAP32[$99>>2]|0;
 $101 = $98;
 $102 = $100;
 $103 = (($101) - ($102))|0;
 $104 = (($103|0) / 4)&-1;
 $105 = ($104|0)==(0);
 if ($105) {
  $126 = 0;
 } else {
  $17 = $95;
  $106 = $17;
  $107 = ((($106)) + 8|0);
  $108 = HEAP32[$107>>2]|0;
  $109 = ((($106)) + 4|0);
  $110 = HEAP32[$109>>2]|0;
  $111 = $108;
  $112 = $110;
  $113 = (($111) - ($112))|0;
  $114 = (($113|0) / 4)&-1;
  $115 = ($114*113)|0;
  $116 = (($115) - 1)|0;
  $126 = $116;
 }
 $117 = ((($94)) + 16|0);
 $118 = HEAP32[$117>>2]|0;
 $16 = $94;
 $119 = $16;
 $120 = ((($119)) + 20|0);
 $15 = $120;
 $121 = $15;
 $14 = $121;
 $122 = $14;
 $123 = HEAP32[$122>>2]|0;
 $124 = (($118) + ($123))|0;
 $125 = (($126) - ($124))|0;
 $127 = ($125>>>0)>=(226);
 if (!($127)) {
  STACKTOP = sp;return;
 }
 $128 = $55;
 $21 = $57;
 $129 = $21;
 $130 = ((($129)) + 8|0);
 $131 = HEAP32[$130>>2]|0;
 $132 = ((($131)) + -4|0);
 $133 = HEAP32[$132>>2]|0;
 $29 = $128;
 $30 = $133;
 $31 = 113;
 $134 = $29;
 $135 = $30;
 $136 = $31;
 $26 = $134;
 $27 = $135;
 $28 = $136;
 $137 = $27;
 $25 = $137;
 $138 = $25;
 __ZdlPv($138);
 $50 = $57;
 $139 = $50;
 $140 = ((($139)) + 8|0);
 $141 = HEAP32[$140>>2]|0;
 $142 = ((($141)) + -4|0);
 $47 = $139;
 $48 = $142;
 $143 = $47;
 $144 = $48;
 ;HEAP8[$46>>0]=HEAP8[$49>>0]|0;
 $44 = $143;
 $45 = $144;
 $145 = $44;
 while(1) {
  $146 = $45;
  $147 = ((($145)) + 8|0);
  $148 = HEAP32[$147>>2]|0;
  $149 = ($146|0)!=($148|0);
  if (!($149)) {
   break;
  }
  $43 = $145;
  $150 = $43;
  $151 = ((($150)) + 12|0);
  $42 = $151;
  $152 = $42;
  $41 = $152;
  $153 = $41;
  $154 = ((($145)) + 8|0);
  $155 = HEAP32[$154>>2]|0;
  $156 = ((($155)) + -4|0);
  HEAP32[$154>>2] = $156;
  $40 = $156;
  $157 = $40;
  $37 = $153;
  $38 = $157;
  $158 = $37;
  $159 = $38;
  ;HEAP8[$36>>0]=HEAP8[$39>>0]|0;
  $34 = $158;
  $35 = $159;
  $160 = $34;
  $161 = $35;
  $32 = $160;
  $33 = $161;
 }
 STACKTOP = sp;return;
}
function __ZN7CommandD2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ((($2)) + 20|0);
 __ZN11safe_vectorIfED2Ev($3);
 STACKTOP = sp;return;
}
function __ZN11safe_vectorIfED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__26vectorIfNS_9allocatorIfEEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__26vectorIfNS_9allocatorIfEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__213__vector_baseIfNS_9allocatorIfEEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__213__vector_baseIfNS_9allocatorIfEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 128|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(128|0);
 $19 = sp;
 $22 = sp + 116|0;
 $30 = $0;
 $31 = $30;
 $32 = HEAP32[$31>>2]|0;
 $33 = ($32|0)!=(0|0);
 if (!($33)) {
  STACKTOP = sp;return;
 }
 $29 = $31;
 $34 = $29;
 $35 = HEAP32[$34>>2]|0;
 $27 = $34;
 $28 = $35;
 $36 = $27;
 while(1) {
  $37 = $28;
  $38 = ((($36)) + 4|0);
  $39 = HEAP32[$38>>2]|0;
  $40 = ($37|0)!=($39|0);
  if (!($40)) {
   break;
  }
  $26 = $36;
  $41 = $26;
  $42 = ((($41)) + 8|0);
  $25 = $42;
  $43 = $25;
  $24 = $43;
  $44 = $24;
  $45 = ((($36)) + 4|0);
  $46 = HEAP32[$45>>2]|0;
  $47 = ((($46)) + -4|0);
  HEAP32[$45>>2] = $47;
  $23 = $47;
  $48 = $23;
  $20 = $44;
  $21 = $48;
  $49 = $20;
  $50 = $21;
  ;HEAP8[$19>>0]=HEAP8[$22>>0]|0;
  $17 = $49;
  $18 = $50;
  $51 = $17;
  $52 = $18;
  $15 = $51;
  $16 = $52;
 }
 $7 = $31;
 $53 = $7;
 $54 = ((($53)) + 8|0);
 $6 = $54;
 $55 = $6;
 $5 = $55;
 $56 = $5;
 $57 = HEAP32[$31>>2]|0;
 $4 = $31;
 $58 = $4;
 $3 = $58;
 $59 = $3;
 $60 = ((($59)) + 8|0);
 $2 = $60;
 $61 = $2;
 $1 = $61;
 $62 = $1;
 $63 = HEAP32[$62>>2]|0;
 $64 = HEAP32[$58>>2]|0;
 $65 = $63;
 $66 = $64;
 $67 = (($65) - ($66))|0;
 $68 = (($67|0) / 4)&-1;
 $12 = $56;
 $13 = $57;
 $14 = $68;
 $69 = $12;
 $70 = $13;
 $71 = $14;
 $9 = $69;
 $10 = $70;
 $11 = $71;
 $72 = $10;
 $8 = $72;
 $73 = $8;
 __ZdlPv($73);
 STACKTOP = sp;return;
}
function __ZNSt3__25dequeI7CommandNS_9allocatorIS1_EEE9pop_frontEv($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $81 = 0;
 var $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 144|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(144|0);
 $6 = sp + 8|0;
 $9 = sp + 129|0;
 $24 = sp;
 $27 = sp + 128|0;
 $32 = $0;
 $34 = $32;
 $31 = $34;
 $35 = $31;
 $36 = ((($35)) + 20|0);
 $30 = $36;
 $37 = $30;
 $29 = $37;
 $38 = $29;
 $33 = $38;
 $39 = $33;
 $14 = $34;
 $40 = $14;
 $41 = ((($40)) + 4|0);
 $42 = HEAP32[$41>>2]|0;
 $43 = ((($34)) + 16|0);
 $44 = HEAP32[$43>>2]|0;
 $45 = (($44>>>0) / 113)&-1;
 $46 = (($42) + ($45<<2)|0);
 $47 = HEAP32[$46>>2]|0;
 $48 = ((($34)) + 16|0);
 $49 = HEAP32[$48>>2]|0;
 $50 = (($49>>>0) % 113)&-1;
 $51 = (($47) + (($50*36)|0)|0);
 $1 = $51;
 $52 = $1;
 $7 = $39;
 $8 = $52;
 $53 = $7;
 $54 = $8;
 ;HEAP8[$6>>0]=HEAP8[$9>>0]|0;
 $4 = $53;
 $5 = $54;
 $55 = $4;
 $56 = $5;
 $2 = $55;
 $3 = $56;
 $57 = $3;
 __ZN7CommandD2Ev($57);
 $12 = $34;
 $58 = $12;
 $59 = ((($58)) + 20|0);
 $11 = $59;
 $60 = $11;
 $10 = $60;
 $61 = $10;
 $62 = HEAP32[$61>>2]|0;
 $63 = (($62) + -1)|0;
 HEAP32[$61>>2] = $63;
 $64 = ((($34)) + 16|0);
 $65 = HEAP32[$64>>2]|0;
 $66 = (($65) + 1)|0;
 HEAP32[$64>>2] = $66;
 $67 = ($66>>>0)>=(226);
 if (!($67)) {
  STACKTOP = sp;return;
 }
 $68 = $33;
 $13 = $34;
 $69 = $13;
 $70 = ((($69)) + 4|0);
 $71 = HEAP32[$70>>2]|0;
 $72 = HEAP32[$71>>2]|0;
 $19 = $68;
 $20 = $72;
 $21 = 113;
 $73 = $19;
 $74 = $20;
 $75 = $21;
 $16 = $73;
 $17 = $74;
 $18 = $75;
 $76 = $17;
 $15 = $76;
 $77 = $15;
 __ZdlPv($77);
 $28 = $34;
 $78 = $28;
 $79 = ((($78)) + 4|0);
 $80 = HEAP32[$79>>2]|0;
 $81 = ((($80)) + 4|0);
 $25 = $78;
 $26 = $81;
 $82 = $25;
 $83 = $26;
 ;HEAP8[$24>>0]=HEAP8[$27>>0]|0;
 $22 = $82;
 $23 = $83;
 $84 = $22;
 $85 = $23;
 $86 = ((($84)) + 4|0);
 HEAP32[$86>>2] = $85;
 $87 = ((($34)) + 16|0);
 $88 = HEAP32[$87>>2]|0;
 $89 = (($88) - 113)|0;
 HEAP32[$87>>2] = $89;
 STACKTOP = sp;return;
}
function __ZNSt3__212__deque_baseI7CommandNS_9allocatorIS1_EEE5clearEv($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0;
 var $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0;
 var $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0;
 var $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0;
 var $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0, $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0;
 var $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $81 = 0, $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0;
 var $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0, $99 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 192|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(192|0);
 $6 = sp + 8|0;
 $9 = sp + 177|0;
 $26 = sp;
 $29 = sp + 176|0;
 $41 = sp + 24|0;
 $42 = sp + 16|0;
 $39 = $0;
 $43 = $39;
 $38 = $43;
 $44 = $38;
 $45 = ((($44)) + 20|0);
 $37 = $45;
 $46 = $37;
 $36 = $46;
 $47 = $36;
 $40 = $47;
 __ZNSt3__212__deque_baseI7CommandNS_9allocatorIS1_EEE5beginEv($41,$43);
 __ZNSt3__212__deque_baseI7CommandNS_9allocatorIS1_EEE3endEv($42,$43);
 while(1) {
  $34 = $41;
  $35 = $42;
  $48 = $34;
  $49 = $35;
  $32 = $48;
  $33 = $49;
  $50 = $32;
  $51 = ((($50)) + 4|0);
  $52 = HEAP32[$51>>2]|0;
  $53 = $33;
  $54 = ((($53)) + 4|0);
  $55 = HEAP32[$54>>2]|0;
  $56 = ($52|0)==($55|0);
  $57 = $56 ^ 1;
  if (!($57)) {
   break;
  }
  $58 = $40;
  $16 = $41;
  $59 = $16;
  $60 = ((($59)) + 4|0);
  $61 = HEAP32[$60>>2]|0;
  $1 = $61;
  $62 = $1;
  $7 = $58;
  $8 = $62;
  $63 = $7;
  $64 = $8;
  ;HEAP8[$6>>0]=HEAP8[$9>>0]|0;
  $4 = $63;
  $5 = $64;
  $65 = $4;
  $66 = $5;
  $2 = $65;
  $3 = $66;
  $67 = $3;
  __ZN7CommandD2Ev($67);
  $10 = $41;
  $68 = $10;
  $69 = ((($68)) + 4|0);
  $70 = HEAP32[$69>>2]|0;
  $71 = ((($70)) + 36|0);
  HEAP32[$69>>2] = $71;
  $72 = HEAP32[$68>>2]|0;
  $73 = HEAP32[$72>>2]|0;
  $74 = $71;
  $75 = $73;
  $76 = (($74) - ($75))|0;
  $77 = (($76|0) / 36)&-1;
  $78 = ($77|0)==(113);
  if (!($78)) {
   continue;
  }
  $79 = HEAP32[$68>>2]|0;
  $80 = ((($79)) + 4|0);
  HEAP32[$68>>2] = $80;
  $81 = HEAP32[$68>>2]|0;
  $82 = HEAP32[$81>>2]|0;
  $83 = ((($68)) + 4|0);
  HEAP32[$83>>2] = $82;
 }
 $13 = $43;
 $84 = $13;
 $85 = ((($84)) + 20|0);
 $12 = $85;
 $86 = $12;
 $11 = $86;
 $87 = $11;
 HEAP32[$87>>2] = 0;
 while(1) {
  $14 = $43;
  $88 = $14;
  $89 = ((($88)) + 8|0);
  $90 = HEAP32[$89>>2]|0;
  $91 = ((($88)) + 4|0);
  $92 = HEAP32[$91>>2]|0;
  $93 = $90;
  $94 = $92;
  $95 = (($93) - ($94))|0;
  $96 = (($95|0) / 4)&-1;
  $97 = ($96>>>0)>(2);
  if (!($97)) {
   break;
  }
  $98 = $40;
  $15 = $43;
  $99 = $15;
  $100 = ((($99)) + 4|0);
  $101 = HEAP32[$100>>2]|0;
  $102 = HEAP32[$101>>2]|0;
  $21 = $98;
  $22 = $102;
  $23 = 113;
  $103 = $21;
  $104 = $22;
  $105 = $23;
  $18 = $103;
  $19 = $104;
  $20 = $105;
  $106 = $19;
  $17 = $106;
  $107 = $17;
  __ZdlPv($107);
  $30 = $43;
  $108 = $30;
  $109 = ((($108)) + 4|0);
  $110 = HEAP32[$109>>2]|0;
  $111 = ((($110)) + 4|0);
  $27 = $108;
  $28 = $111;
  $112 = $27;
  $113 = $28;
  ;HEAP8[$26>>0]=HEAP8[$29>>0]|0;
  $24 = $112;
  $25 = $113;
  $114 = $24;
  $115 = $25;
  $116 = ((($114)) + 4|0);
  HEAP32[$116>>2] = $115;
 }
 $31 = $43;
 $117 = $31;
 $118 = ((($117)) + 8|0);
 $119 = HEAP32[$118>>2]|0;
 $120 = ((($117)) + 4|0);
 $121 = HEAP32[$120>>2]|0;
 $122 = $119;
 $123 = $121;
 $124 = (($122) - ($123))|0;
 $125 = (($124|0) / 4)&-1;
 switch ($125|0) {
 case 1:  {
  $126 = ((($43)) + 16|0);
  HEAP32[$126>>2] = 56;
  STACKTOP = sp;return;
  break;
 }
 case 2:  {
  $127 = ((($43)) + 16|0);
  HEAP32[$127>>2] = 113;
  STACKTOP = sp;return;
  break;
 }
 default: {
  STACKTOP = sp;return;
 }
 }
}
function __ZNSt3__212__deque_baseI7CommandNS_9allocatorIS1_EEE5beginEv($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0;
 var $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(32|0);
 $7 = $1;
 $9 = $7;
 $6 = $9;
 $10 = $6;
 $11 = ((($10)) + 4|0);
 $12 = HEAP32[$11>>2]|0;
 $13 = ((($9)) + 16|0);
 $14 = HEAP32[$13>>2]|0;
 $15 = (($14>>>0) / 113)&-1;
 $16 = (($12) + ($15<<2)|0);
 $8 = $16;
 $17 = $8;
 $5 = $9;
 $18 = $5;
 $19 = ((($18)) + 8|0);
 $20 = HEAP32[$19>>2]|0;
 $21 = ((($18)) + 4|0);
 $22 = HEAP32[$21>>2]|0;
 $23 = ($20|0)==($22|0);
 if ($23) {
  $30 = 0;
 } else {
  $24 = $8;
  $25 = HEAP32[$24>>2]|0;
  $26 = ((($9)) + 16|0);
  $27 = HEAP32[$26>>2]|0;
  $28 = (($27>>>0) % 113)&-1;
  $29 = (($25) + (($28*36)|0)|0);
  $30 = $29;
 }
 $2 = $0;
 $3 = $17;
 $4 = $30;
 $31 = $2;
 $32 = $3;
 HEAP32[$31>>2] = $32;
 $33 = ((($31)) + 4|0);
 $34 = $4;
 HEAP32[$33>>2] = $34;
 STACKTOP = sp;return;
}
function __ZNSt3__212__deque_baseI7CommandNS_9allocatorIS1_EEE3endEv($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0;
 var $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $5 = 0, $6 = 0;
 var $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 48|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(48|0);
 $10 = $1;
 $13 = $10;
 $9 = $13;
 $14 = $9;
 $15 = ((($14)) + 20|0);
 $8 = $15;
 $16 = $8;
 $7 = $16;
 $17 = $7;
 $18 = HEAP32[$17>>2]|0;
 $19 = ((($13)) + 16|0);
 $20 = HEAP32[$19>>2]|0;
 $21 = (($18) + ($20))|0;
 $11 = $21;
 $6 = $13;
 $22 = $6;
 $23 = ((($22)) + 4|0);
 $24 = HEAP32[$23>>2]|0;
 $25 = $11;
 $26 = (($25>>>0) / 113)&-1;
 $27 = (($24) + ($26<<2)|0);
 $12 = $27;
 $28 = $12;
 $2 = $13;
 $29 = $2;
 $30 = ((($29)) + 8|0);
 $31 = HEAP32[$30>>2]|0;
 $32 = ((($29)) + 4|0);
 $33 = HEAP32[$32>>2]|0;
 $34 = ($31|0)==($33|0);
 if ($34) {
  $40 = 0;
  $3 = $0;
  $4 = $28;
  $5 = $40;
  $41 = $3;
  $42 = $4;
  HEAP32[$41>>2] = $42;
  $43 = ((($41)) + 4|0);
  $44 = $5;
  HEAP32[$43>>2] = $44;
  STACKTOP = sp;return;
 }
 $35 = $12;
 $36 = HEAP32[$35>>2]|0;
 $37 = $11;
 $38 = (($37>>>0) % 113)&-1;
 $39 = (($36) + (($38*36)|0)|0);
 $40 = $39;
 $3 = $0;
 $4 = $28;
 $5 = $40;
 $41 = $3;
 $42 = $4;
 HEAP32[$41>>2] = $42;
 $43 = ((($41)) + 4|0);
 $44 = $5;
 HEAP32[$43>>2] = $44;
 STACKTOP = sp;return;
}
function __ZNSt3__25dequeI7CommandNS_9allocatorIS1_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 __ZNSt3__212__deque_baseI7CommandNS_9allocatorIS1_EEED2Ev($2);
 STACKTOP = sp;return;
}
function __ZNSt3__212__deque_baseI7CommandNS_9allocatorIS1_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 64|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(64|0);
 $13 = $0;
 $16 = $13;
 __ZNSt3__212__deque_baseI7CommandNS_9allocatorIS1_EEE5clearEv($16);
 $12 = $16;
 $17 = $12;
 $18 = ((($17)) + 4|0);
 $19 = HEAP32[$18>>2]|0;
 $14 = $19;
 $11 = $16;
 $20 = $11;
 $21 = ((($20)) + 8|0);
 $22 = HEAP32[$21>>2]|0;
 $15 = $22;
 while(1) {
  $23 = $14;
  $24 = $15;
  $25 = ($23|0)!=($24|0);
  if (!($25)) {
   break;
  }
  $10 = $16;
  $26 = $10;
  $27 = ((($26)) + 20|0);
  $9 = $27;
  $28 = $9;
  $8 = $28;
  $29 = $8;
  $30 = $14;
  $31 = HEAP32[$30>>2]|0;
  $5 = $29;
  $6 = $31;
  $7 = 113;
  $32 = $5;
  $33 = $6;
  $34 = $7;
  $2 = $32;
  $3 = $33;
  $4 = $34;
  $35 = $3;
  $1 = $35;
  $36 = $1;
  __ZdlPv($36);
  $37 = $14;
  $38 = ((($37)) + 4|0);
  $14 = $38;
 }
 __ZNSt3__214__split_bufferIP7CommandNS_9allocatorIS2_EEED2Ev($16);
 STACKTOP = sp;return;
}
function __ZNSt3__214__split_bufferIP7CommandNS_9allocatorIS2_EEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $9 = 0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 144|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(144|0);
 $19 = sp + 8|0;
 $22 = sp + 133|0;
 $29 = sp;
 $32 = sp + 132|0;
 $34 = $0;
 $35 = $34;
 $33 = $35;
 $36 = $33;
 $37 = ((($36)) + 4|0);
 $38 = HEAP32[$37>>2]|0;
 $30 = $36;
 $31 = $38;
 $39 = $30;
 $40 = $31;
 ;HEAP8[$29>>0]=HEAP8[$32>>0]|0;
 $27 = $39;
 $28 = $40;
 $41 = $27;
 while(1) {
  $42 = $28;
  $43 = ((($41)) + 8|0);
  $44 = HEAP32[$43>>2]|0;
  $45 = ($42|0)!=($44|0);
  if (!($45)) {
   break;
  }
  $26 = $41;
  $46 = $26;
  $47 = ((($46)) + 12|0);
  $25 = $47;
  $48 = $25;
  $24 = $48;
  $49 = $24;
  $50 = ((($41)) + 8|0);
  $51 = HEAP32[$50>>2]|0;
  $52 = ((($51)) + -4|0);
  HEAP32[$50>>2] = $52;
  $23 = $52;
  $53 = $23;
  $20 = $49;
  $21 = $53;
  $54 = $20;
  $55 = $21;
  ;HEAP8[$19>>0]=HEAP8[$22>>0]|0;
  $17 = $54;
  $18 = $55;
  $56 = $17;
  $57 = $18;
  $15 = $56;
  $16 = $57;
 }
 $58 = HEAP32[$35>>2]|0;
 $59 = ($58|0)!=(0|0);
 if (!($59)) {
  STACKTOP = sp;return;
 }
 $14 = $35;
 $60 = $14;
 $61 = ((($60)) + 12|0);
 $13 = $61;
 $62 = $13;
 $12 = $62;
 $63 = $12;
 $64 = HEAP32[$35>>2]|0;
 $4 = $35;
 $65 = $4;
 $3 = $65;
 $66 = $3;
 $67 = ((($66)) + 12|0);
 $2 = $67;
 $68 = $2;
 $1 = $68;
 $69 = $1;
 $70 = HEAP32[$69>>2]|0;
 $71 = HEAP32[$65>>2]|0;
 $72 = $70;
 $73 = $71;
 $74 = (($72) - ($73))|0;
 $75 = (($74|0) / 4)&-1;
 $9 = $63;
 $10 = $64;
 $11 = $75;
 $76 = $9;
 $77 = $10;
 $78 = $11;
 $6 = $76;
 $7 = $77;
 $8 = $78;
 $79 = $7;
 $5 = $79;
 $80 = $5;
 __ZdlPv($80);
 STACKTOP = sp;return;
}
function __ZN12spring_clockL13FromMilliSecsIiEExT_($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = $0;
 $2 = $1;
 $3 = ($2|0)<(0);
 $4 = $3 << 31 >> 31;
 $5 = (___muldi3(($2|0),($4|0),1000000,0)|0);
 $6 = tempRet0;
 tempRet0 = ($6);
 STACKTOP = sp;return ($5|0);
}
function __GLOBAL__sub_I_my_glue_wrapper_cpp() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 ___cxx_global_var_init();
 ___cxx_global_var_init_1();
 ___cxx_global_var_init_2();
 ___cxx_global_var_init_3();
 ___cxx_global_var_init_4();
 ___cxx_global_var_init_5();
 ___cxx_global_var_init_6();
 ___cxx_global_var_init_7();
 ___cxx_global_var_init_8();
 ___cxx_global_var_init_9();
 ___cxx_global_var_init_10();
 ___cxx_global_var_init_11();
 ___cxx_global_var_init_12();
 ___cxx_global_var_init_13();
 ___cxx_global_var_init_14();
 return;
}
function ___stdio_close($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $vararg_buffer = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $vararg_buffer = sp;
 $1 = ((($0)) + 60|0);
 $2 = HEAP32[$1>>2]|0;
 HEAP32[$vararg_buffer>>2] = $2;
 $3 = (___syscall6(6,($vararg_buffer|0))|0);
 $4 = (___syscall_ret($3)|0);
 STACKTOP = sp;return ($4|0);
}
function ___stdout_write($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $vararg_buffer = 0, $vararg_ptr1 = 0, $vararg_ptr2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 80|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(80|0);
 $vararg_buffer = sp;
 $3 = sp + 12|0;
 $4 = ((($0)) + 36|0);
 HEAP32[$4>>2] = 4;
 $5 = HEAP32[$0>>2]|0;
 $6 = $5 & 64;
 $7 = ($6|0)==(0);
 if ($7) {
  $8 = ((($0)) + 60|0);
  $9 = HEAP32[$8>>2]|0;
  HEAP32[$vararg_buffer>>2] = $9;
  $vararg_ptr1 = ((($vararg_buffer)) + 4|0);
  HEAP32[$vararg_ptr1>>2] = 21505;
  $vararg_ptr2 = ((($vararg_buffer)) + 8|0);
  HEAP32[$vararg_ptr2>>2] = $3;
  $10 = (___syscall54(54,($vararg_buffer|0))|0);
  $11 = ($10|0)==(0);
  if (!($11)) {
   $12 = ((($0)) + 75|0);
   HEAP8[$12>>0] = -1;
  }
 }
 $13 = (___stdio_write($0,$1,$2)|0);
 STACKTOP = sp;return ($13|0);
}
function ___stdio_seek($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $$pre = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $vararg_buffer = 0, $vararg_ptr1 = 0, $vararg_ptr2 = 0, $vararg_ptr3 = 0, $vararg_ptr4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(32|0);
 $vararg_buffer = sp;
 $3 = sp + 20|0;
 $4 = ((($0)) + 60|0);
 $5 = HEAP32[$4>>2]|0;
 HEAP32[$vararg_buffer>>2] = $5;
 $vararg_ptr1 = ((($vararg_buffer)) + 4|0);
 HEAP32[$vararg_ptr1>>2] = 0;
 $vararg_ptr2 = ((($vararg_buffer)) + 8|0);
 HEAP32[$vararg_ptr2>>2] = $1;
 $vararg_ptr3 = ((($vararg_buffer)) + 12|0);
 HEAP32[$vararg_ptr3>>2] = $3;
 $vararg_ptr4 = ((($vararg_buffer)) + 16|0);
 HEAP32[$vararg_ptr4>>2] = $2;
 $6 = (___syscall140(140,($vararg_buffer|0))|0);
 $7 = (___syscall_ret($6)|0);
 $8 = ($7|0)<(0);
 if ($8) {
  HEAP32[$3>>2] = -1;
  $9 = -1;
 } else {
  $$pre = HEAP32[$3>>2]|0;
  $9 = $$pre;
 }
 STACKTOP = sp;return ($9|0);
}
function ___syscall_ret($0) {
 $0 = $0|0;
 var $$0 = 0, $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = ($0>>>0)>(4294963200);
 if ($1) {
  $2 = (0 - ($0))|0;
  $3 = (___errno_location()|0);
  HEAP32[$3>>2] = $2;
  $$0 = -1;
 } else {
  $$0 = $0;
 }
 return ($$0|0);
}
function ___errno_location() {
 var $$0 = 0, $0 = 0, $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $0 = HEAP32[920]|0;
 $1 = ($0|0)==(0|0);
 if ($1) {
  $$0 = 3724;
 } else {
  $2 = (_pthread_self()|0);
  $3 = ((($2)) + 64|0);
  $4 = HEAP32[$3>>2]|0;
  $$0 = $4;
 }
 return ($$0|0);
}
function ___stdio_write($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $$0 = 0, $$056 = 0, $$058 = 0, $$059 = 0, $$061 = 0, $$1 = 0, $$157 = 0, $$160 = 0, $$phi$trans$insert = 0, $$pre = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0;
 var $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0;
 var $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $6 = 0, $7 = 0, $8 = 0;
 var $9 = 0, $vararg_buffer = 0, $vararg_buffer3 = 0, $vararg_ptr1 = 0, $vararg_ptr2 = 0, $vararg_ptr6 = 0, $vararg_ptr7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 48|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(48|0);
 $vararg_buffer3 = sp + 16|0;
 $vararg_buffer = sp;
 $3 = sp + 32|0;
 $4 = ((($0)) + 28|0);
 $5 = HEAP32[$4>>2]|0;
 HEAP32[$3>>2] = $5;
 $6 = ((($3)) + 4|0);
 $7 = ((($0)) + 20|0);
 $8 = HEAP32[$7>>2]|0;
 $9 = (($8) - ($5))|0;
 HEAP32[$6>>2] = $9;
 $10 = ((($3)) + 8|0);
 HEAP32[$10>>2] = $1;
 $11 = ((($3)) + 12|0);
 HEAP32[$11>>2] = $2;
 $12 = (($9) + ($2))|0;
 $13 = ((($0)) + 60|0);
 $14 = ((($0)) + 44|0);
 $$056 = 2;$$058 = $12;$$059 = $3;
 while(1) {
  $15 = HEAP32[920]|0;
  $16 = ($15|0)==(0|0);
  if ($16) {
   $20 = HEAP32[$13>>2]|0;
   HEAP32[$vararg_buffer3>>2] = $20;
   $vararg_ptr6 = ((($vararg_buffer3)) + 4|0);
   HEAP32[$vararg_ptr6>>2] = $$059;
   $vararg_ptr7 = ((($vararg_buffer3)) + 8|0);
   HEAP32[$vararg_ptr7>>2] = $$056;
   $21 = (___syscall146(146,($vararg_buffer3|0))|0);
   $22 = (___syscall_ret($21)|0);
   $$0 = $22;
  } else {
   _pthread_cleanup_push((19|0),($0|0));
   $17 = HEAP32[$13>>2]|0;
   HEAP32[$vararg_buffer>>2] = $17;
   $vararg_ptr1 = ((($vararg_buffer)) + 4|0);
   HEAP32[$vararg_ptr1>>2] = $$059;
   $vararg_ptr2 = ((($vararg_buffer)) + 8|0);
   HEAP32[$vararg_ptr2>>2] = $$056;
   $18 = (___syscall146(146,($vararg_buffer|0))|0);
   $19 = (___syscall_ret($18)|0);
   _pthread_cleanup_pop(0);
   $$0 = $19;
  }
  $23 = ($$058|0)==($$0|0);
  if ($23) {
   label = 6;
   break;
  }
  $30 = ($$0|0)<(0);
  if ($30) {
   label = 8;
   break;
  }
  $38 = (($$058) - ($$0))|0;
  $39 = ((($$059)) + 4|0);
  $40 = HEAP32[$39>>2]|0;
  $41 = ($$0>>>0)>($40>>>0);
  if ($41) {
   $42 = HEAP32[$14>>2]|0;
   HEAP32[$4>>2] = $42;
   HEAP32[$7>>2] = $42;
   $43 = (($$0) - ($40))|0;
   $44 = ((($$059)) + 8|0);
   $45 = (($$056) + -1)|0;
   $$phi$trans$insert = ((($$059)) + 12|0);
   $$pre = HEAP32[$$phi$trans$insert>>2]|0;
   $$1 = $43;$$157 = $45;$$160 = $44;$53 = $$pre;
  } else {
   $46 = ($$056|0)==(2);
   if ($46) {
    $47 = HEAP32[$4>>2]|0;
    $48 = (($47) + ($$0)|0);
    HEAP32[$4>>2] = $48;
    $$1 = $$0;$$157 = 2;$$160 = $$059;$53 = $40;
   } else {
    $$1 = $$0;$$157 = $$056;$$160 = $$059;$53 = $40;
   }
  }
  $49 = HEAP32[$$160>>2]|0;
  $50 = (($49) + ($$1)|0);
  HEAP32[$$160>>2] = $50;
  $51 = ((($$160)) + 4|0);
  $52 = (($53) - ($$1))|0;
  HEAP32[$51>>2] = $52;
  $$056 = $$157;$$058 = $38;$$059 = $$160;
 }
 if ((label|0) == 6) {
  $24 = HEAP32[$14>>2]|0;
  $25 = ((($0)) + 48|0);
  $26 = HEAP32[$25>>2]|0;
  $27 = (($24) + ($26)|0);
  $28 = ((($0)) + 16|0);
  HEAP32[$28>>2] = $27;
  $29 = $24;
  HEAP32[$4>>2] = $29;
  HEAP32[$7>>2] = $29;
  $$061 = $2;
 }
 else if ((label|0) == 8) {
  $31 = ((($0)) + 16|0);
  HEAP32[$31>>2] = 0;
  HEAP32[$4>>2] = 0;
  HEAP32[$7>>2] = 0;
  $32 = HEAP32[$0>>2]|0;
  $33 = $32 | 32;
  HEAP32[$0>>2] = $33;
  $34 = ($$056|0)==(2);
  if ($34) {
   $$061 = 0;
  } else {
   $35 = ((($$059)) + 4|0);
   $36 = HEAP32[$35>>2]|0;
   $37 = (($2) - ($36))|0;
   $$061 = $37;
  }
 }
 STACKTOP = sp;return ($$061|0);
}
function _cleanup($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = ((($0)) + 68|0);
 $2 = HEAP32[$1>>2]|0;
 $3 = ($2|0)==(0);
 if ($3) {
  ___unlockfile($0);
 }
 return;
}
function ___unlockfile($0) {
 $0 = $0|0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 return;
}
function _vfprintf($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $$ = 0, $$0 = 0, $$1 = 0, $$1$ = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0;
 var $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $5 = 0, $6 = 0, $7 = 0;
 var $8 = 0, $9 = 0, $vacopy_currentptr = 0, dest = 0, label = 0, sp = 0, stop = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 224|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(224|0);
 $3 = sp + 120|0;
 $4 = sp + 80|0;
 $5 = sp;
 $6 = sp + 136|0;
 dest=$4; stop=dest+40|0; do { HEAP32[dest>>2]=0|0; dest=dest+4|0; } while ((dest|0) < (stop|0));
 $vacopy_currentptr = HEAP32[$2>>2]|0;
 HEAP32[$3>>2] = $vacopy_currentptr;
 $7 = (_printf_core(0,$1,$3,$5,$4)|0);
 $8 = ($7|0)<(0);
 if ($8) {
  $$0 = -1;
 } else {
  $9 = ((($0)) + 76|0);
  $10 = HEAP32[$9>>2]|0;
  $11 = ($10|0)>(-1);
  if ($11) {
   $12 = (___lockfile($0)|0);
   $39 = $12;
  } else {
   $39 = 0;
  }
  $13 = HEAP32[$0>>2]|0;
  $14 = $13 & 32;
  $15 = ((($0)) + 74|0);
  $16 = HEAP8[$15>>0]|0;
  $17 = ($16<<24>>24)<(1);
  if ($17) {
   $18 = $13 & -33;
   HEAP32[$0>>2] = $18;
  }
  $19 = ((($0)) + 48|0);
  $20 = HEAP32[$19>>2]|0;
  $21 = ($20|0)==(0);
  if ($21) {
   $23 = ((($0)) + 44|0);
   $24 = HEAP32[$23>>2]|0;
   HEAP32[$23>>2] = $6;
   $25 = ((($0)) + 28|0);
   HEAP32[$25>>2] = $6;
   $26 = ((($0)) + 20|0);
   HEAP32[$26>>2] = $6;
   HEAP32[$19>>2] = 80;
   $27 = ((($6)) + 80|0);
   $28 = ((($0)) + 16|0);
   HEAP32[$28>>2] = $27;
   $29 = (_printf_core($0,$1,$3,$5,$4)|0);
   $30 = ($24|0)==(0|0);
   if ($30) {
    $$1 = $29;
   } else {
    $31 = ((($0)) + 36|0);
    $32 = HEAP32[$31>>2]|0;
    (FUNCTION_TABLE_iiii[$32 & 15]($0,0,0)|0);
    $33 = HEAP32[$26>>2]|0;
    $34 = ($33|0)==(0|0);
    $$ = $34 ? -1 : $29;
    HEAP32[$23>>2] = $24;
    HEAP32[$19>>2] = 0;
    HEAP32[$28>>2] = 0;
    HEAP32[$25>>2] = 0;
    HEAP32[$26>>2] = 0;
    $$1 = $$;
   }
  } else {
   $22 = (_printf_core($0,$1,$3,$5,$4)|0);
   $$1 = $22;
  }
  $35 = HEAP32[$0>>2]|0;
  $36 = $35 & 32;
  $37 = ($36|0)==(0);
  $$1$ = $37 ? $$1 : -1;
  $38 = $35 | $14;
  HEAP32[$0>>2] = $38;
  $40 = ($39|0)==(0);
  if (!($40)) {
   ___unlockfile($0);
  }
  $$0 = $$1$;
 }
 STACKTOP = sp;return ($$0|0);
}
function _printf_core($0,$1,$2,$3,$4) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 $4 = $4|0;
 var $$ = 0, $$$0259 = 0, $$$0262 = 0, $$$0269 = 0, $$$3484$i = 0, $$$3484705$i = 0, $$$3484706$i = 0, $$$3501$i = 0, $$$4266 = 0, $$$4502$i = 0, $$$5 = 0, $$$i = 0, $$0 = 0, $$0$i = 0, $$0$lcssa$i300 = 0, $$0228 = 0, $$0229396 = 0, $$0232 = 0, $$0235 = 0, $$0237 = 0;
 var $$0240$lcssa = 0, $$0240$lcssa460 = 0, $$0240395 = 0, $$0243 = 0, $$0247 = 0, $$0249$lcssa = 0, $$0249383 = 0, $$0252 = 0, $$0253 = 0, $$0254 = 0, $$0254$ = 0, $$0259 = 0, $$0262342 = 0, $$0262390 = 0, $$0269 = 0, $$0269$phi = 0, $$0321 = 0, $$0463$lcssa$i = 0, $$0463594$i = 0, $$0464603$i = 0;
 var $$0466$i = 0.0, $$0470$i = 0, $$0471$i = 0.0, $$0479$i = 0, $$0487652$i = 0, $$0488$i = 0, $$0488663$i = 0, $$0488665$i = 0, $$0496$$9$i = 0, $$0497664$i = 0, $$0498$i = 0, $$05$lcssa$i = 0, $$0509592$i = 0.0, $$0510$i = 0, $$0511$i = 0, $$0514647$i = 0, $$0520$i = 0, $$0522$$i = 0, $$0522$i = 0, $$0524$i = 0;
 var $$0526$i = 0, $$0528$i = 0, $$0528639$i = 0, $$0528641$i = 0, $$0531646$i = 0, $$056$i = 0, $$06$i = 0, $$06$i290 = 0, $$06$i298 = 0, $$1 = 0, $$1230407 = 0, $$1233 = 0, $$1236 = 0, $$1238 = 0, $$1241406 = 0, $$1244394 = 0, $$1248 = 0, $$1250 = 0, $$1255 = 0, $$1260 = 0;
 var $$1263 = 0, $$1263$ = 0, $$1270 = 0, $$1322 = 0, $$1465$i = 0, $$1467$i = 0.0, $$1469$i = 0.0, $$1472$i = 0.0, $$1480$i = 0, $$1482$lcssa$i = 0, $$1482671$i = 0, $$1489651$i = 0, $$1499$lcssa$i = 0, $$1499670$i = 0, $$1508593$i = 0, $$1512$lcssa$i = 0, $$1512617$i = 0, $$1515$i = 0, $$1521$i = 0, $$1525$i = 0;
 var $$1527$i = 0, $$1529624$i = 0, $$1532$lcssa$i = 0, $$1532640$i = 0, $$1607$i = 0, $$2 = 0, $$2$i = 0, $$2234 = 0, $$2239 = 0, $$2242381 = 0, $$2245 = 0, $$2251 = 0, $$2256 = 0, $$2256$ = 0, $$2261 = 0, $$2271 = 0, $$2323$lcssa = 0, $$2323382 = 0, $$2473$i = 0.0, $$2476$$545$i = 0;
 var $$2476$$547$i = 0, $$2476$i = 0, $$2483$ph$i = 0, $$2490$lcssa$i = 0, $$2490632$i = 0, $$2500$i = 0, $$2513$i = 0, $$2516628$i = 0, $$2530$i = 0, $$2533627$i = 0, $$3$i = 0.0, $$3257 = 0, $$3265 = 0, $$3272 = 0, $$331 = 0, $$332 = 0, $$333 = 0, $$3379 = 0, $$3477$i = 0, $$3484$lcssa$i = 0;
 var $$3484658$i = 0, $$3501$lcssa$i = 0, $$3501657$i = 0, $$3534623$i = 0, $$4$i = 0.0, $$4258458 = 0, $$4266 = 0, $$4325 = 0, $$4478$lcssa$i = 0, $$4478600$i = 0, $$4492$i = 0, $$4502$i = 0, $$4518$i = 0, $$5 = 0, $$5$lcssa$i = 0, $$537$i = 0, $$538$$i = 0, $$538$i = 0, $$541$i = 0.0, $$544$i = 0;
 var $$546$i = 0, $$5486$lcssa$i = 0, $$5486633$i = 0, $$5493606$i = 0, $$5519$ph$i = 0, $$553$i = 0, $$554$i = 0, $$557$i = 0.0, $$5611$i = 0, $$6 = 0, $$6$i = 0, $$6268 = 0, $$6494599$i = 0, $$7 = 0, $$7495610$i = 0, $$7505$$i = 0, $$7505$i = 0, $$7505$ph$i = 0, $$8$i = 0, $$9$ph$i = 0;
 var $$lcssa683$i = 0, $$neg$i = 0, $$neg572$i = 0, $$pn$i = 0, $$pr = 0, $$pr$i = 0, $$pr571$i = 0, $$pre = 0, $$pre$i = 0, $$pre$phi704$iZ2D = 0, $$pre452 = 0, $$pre453 = 0, $$pre454 = 0, $$pre697$i = 0, $$pre700$i = 0, $$pre703$i = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0;
 var $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0, $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0;
 var $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0, $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0, $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0;
 var $14 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $15 = 0, $150 = 0, $151 = 0, $152 = 0, $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0;
 var $158 = 0, $159 = 0, $16 = 0, $160 = 0, $161 = 0, $162 = 0, $163 = 0, $164 = 0, $165 = 0, $166 = 0, $167 = 0, $168 = 0, $169 = 0, $17 = 0, $170 = 0, $171 = 0, $172 = 0, $173 = 0, $174 = 0, $175 = 0;
 var $176 = 0, $177 = 0, $178 = 0, $179 = 0, $18 = 0, $180 = 0, $181 = 0, $182 = 0, $183 = 0, $184 = 0, $185 = 0, $186 = 0, $187 = 0, $188 = 0, $189 = 0, $19 = 0, $190 = 0, $191 = 0, $192 = 0, $193 = 0;
 var $194 = 0, $195 = 0, $196 = 0, $197 = 0, $198 = 0, $199 = 0, $20 = 0, $200 = 0, $201 = 0, $202 = 0, $203 = 0, $204 = 0, $205 = 0, $206 = 0, $207 = 0, $208 = 0, $209 = 0, $21 = 0, $210 = 0, $211 = 0;
 var $212 = 0, $213 = 0, $214 = 0, $215 = 0, $216 = 0, $217 = 0, $218 = 0, $219 = 0, $22 = 0, $220 = 0, $221 = 0, $222 = 0, $223 = 0, $224 = 0, $225 = 0, $226 = 0, $227 = 0, $228 = 0, $229 = 0, $23 = 0;
 var $230 = 0, $231 = 0, $232 = 0, $233 = 0, $234 = 0, $235 = 0, $236 = 0, $237 = 0, $238 = 0, $239 = 0, $24 = 0, $240 = 0, $241 = 0, $242 = 0, $243 = 0, $244 = 0, $245 = 0, $246 = 0, $247 = 0, $248 = 0;
 var $249 = 0, $25 = 0, $250 = 0, $251 = 0, $252 = 0, $253 = 0, $254 = 0, $255 = 0, $256 = 0, $257 = 0, $258 = 0, $259 = 0, $26 = 0, $260 = 0, $261 = 0, $262 = 0, $263 = 0, $264 = 0, $265 = 0, $266 = 0;
 var $267 = 0, $268 = 0, $269 = 0, $27 = 0, $270 = 0, $271 = 0, $272 = 0, $273 = 0, $274 = 0, $275 = 0, $276 = 0, $277 = 0, $278 = 0, $279 = 0, $28 = 0, $280 = 0, $281 = 0, $282 = 0, $283 = 0, $284 = 0;
 var $285 = 0, $286 = 0, $287 = 0, $288 = 0, $289 = 0, $29 = 0, $290 = 0, $291 = 0, $292 = 0, $293 = 0, $294 = 0, $295 = 0, $296 = 0, $297 = 0, $298 = 0, $299 = 0, $30 = 0, $300 = 0, $301 = 0, $302 = 0;
 var $303 = 0, $304 = 0, $305 = 0, $306 = 0, $307 = 0, $308 = 0, $309 = 0, $31 = 0, $310 = 0, $311 = 0, $312 = 0, $313 = 0, $314 = 0, $315 = 0, $316 = 0, $317 = 0, $318 = 0, $319 = 0, $32 = 0, $320 = 0;
 var $321 = 0, $322 = 0, $323 = 0, $324 = 0, $325 = 0, $326 = 0, $327 = 0, $328 = 0, $329 = 0, $33 = 0, $330 = 0, $331 = 0, $332 = 0, $333 = 0, $334 = 0, $335 = 0, $336 = 0, $337 = 0, $338 = 0, $339 = 0;
 var $34 = 0, $340 = 0, $341 = 0, $342 = 0, $343 = 0, $344 = 0, $345 = 0, $346 = 0, $347 = 0, $348 = 0, $349 = 0, $35 = 0, $350 = 0, $351 = 0, $352 = 0, $353 = 0, $354 = 0, $355 = 0, $356 = 0, $357 = 0;
 var $358 = 0, $359 = 0, $36 = 0, $360 = 0, $361 = 0, $362 = 0, $363 = 0, $364 = 0, $365 = 0, $366 = 0, $367 = 0, $368 = 0, $369 = 0, $37 = 0, $370 = 0, $371 = 0.0, $372 = 0, $373 = 0, $374 = 0, $375 = 0.0;
 var $376 = 0, $377 = 0, $378 = 0, $379 = 0, $38 = 0, $380 = 0, $381 = 0, $382 = 0, $383 = 0, $384 = 0, $385 = 0, $386 = 0, $387 = 0, $388 = 0, $389 = 0, $39 = 0, $390 = 0, $391 = 0, $392 = 0, $393 = 0;
 var $394 = 0, $395 = 0, $396 = 0, $397 = 0, $398 = 0, $399 = 0, $40 = 0, $400 = 0, $401 = 0, $402 = 0, $403 = 0.0, $404 = 0.0, $405 = 0, $406 = 0, $407 = 0, $408 = 0, $409 = 0, $41 = 0, $410 = 0, $411 = 0;
 var $412 = 0, $413 = 0, $414 = 0, $415 = 0, $416 = 0, $417 = 0, $418 = 0, $419 = 0.0, $42 = 0, $420 = 0, $421 = 0, $422 = 0, $423 = 0.0, $424 = 0.0, $425 = 0.0, $426 = 0.0, $427 = 0.0, $428 = 0.0, $429 = 0, $43 = 0;
 var $430 = 0, $431 = 0, $432 = 0, $433 = 0, $434 = 0, $435 = 0, $436 = 0, $437 = 0, $438 = 0, $439 = 0, $44 = 0, $440 = 0, $441 = 0, $442 = 0, $443 = 0, $444 = 0, $445 = 0, $446 = 0, $447 = 0, $448 = 0;
 var $449 = 0, $45 = 0, $450 = 0, $451 = 0, $452 = 0, $453 = 0, $454 = 0.0, $455 = 0.0, $456 = 0.0, $457 = 0, $458 = 0, $459 = 0, $46 = 0, $460 = 0, $461 = 0, $462 = 0, $463 = 0, $464 = 0, $465 = 0, $466 = 0;
 var $467 = 0, $468 = 0, $469 = 0, $47 = 0, $470 = 0, $471 = 0, $472 = 0, $473 = 0, $474 = 0, $475 = 0, $476 = 0, $477 = 0, $478 = 0, $479 = 0, $48 = 0, $480 = 0, $481 = 0, $482 = 0, $483 = 0, $484 = 0;
 var $485 = 0, $486 = 0, $487 = 0.0, $488 = 0, $489 = 0, $49 = 0, $490 = 0, $491 = 0, $492 = 0, $493 = 0.0, $494 = 0.0, $495 = 0.0, $496 = 0, $497 = 0, $498 = 0, $499 = 0, $5 = 0, $50 = 0, $500 = 0, $501 = 0;
 var $502 = 0, $503 = 0, $504 = 0, $505 = 0, $506 = 0, $507 = 0, $508 = 0, $509 = 0, $51 = 0, $510 = 0, $511 = 0, $512 = 0, $513 = 0, $514 = 0, $515 = 0, $516 = 0, $517 = 0, $518 = 0, $519 = 0, $52 = 0;
 var $520 = 0, $521 = 0, $522 = 0, $523 = 0, $524 = 0, $525 = 0, $526 = 0, $527 = 0, $528 = 0, $529 = 0, $53 = 0, $530 = 0, $531 = 0, $532 = 0, $533 = 0, $534 = 0, $535 = 0, $536 = 0, $537 = 0, $538 = 0;
 var $539 = 0, $54 = 0, $540 = 0, $541 = 0, $542 = 0, $543 = 0, $544 = 0, $545 = 0, $546 = 0, $547 = 0, $548 = 0, $549 = 0, $55 = 0, $550 = 0, $551 = 0, $552 = 0, $553 = 0, $554 = 0, $555 = 0, $556 = 0;
 var $557 = 0, $558 = 0, $559 = 0, $56 = 0, $560 = 0, $561 = 0, $562 = 0, $563 = 0, $564 = 0, $565 = 0, $566 = 0, $567 = 0, $568 = 0, $569 = 0, $57 = 0, $570 = 0, $571 = 0, $572 = 0, $573 = 0, $574 = 0;
 var $575 = 0, $576 = 0, $577 = 0, $578 = 0, $579 = 0, $58 = 0, $580 = 0, $581 = 0, $582 = 0, $583 = 0, $584 = 0, $585 = 0, $586 = 0, $587 = 0, $588 = 0, $589 = 0, $59 = 0, $590 = 0, $591 = 0, $592 = 0;
 var $593 = 0, $594 = 0, $595 = 0, $596 = 0, $597 = 0, $598 = 0, $599 = 0, $6 = 0, $60 = 0, $600 = 0, $601 = 0, $602 = 0, $603 = 0, $604 = 0, $605 = 0.0, $606 = 0.0, $607 = 0, $608 = 0.0, $609 = 0, $61 = 0;
 var $610 = 0, $611 = 0, $612 = 0, $613 = 0, $614 = 0, $615 = 0, $616 = 0, $617 = 0, $618 = 0, $619 = 0, $62 = 0, $620 = 0, $621 = 0, $622 = 0, $623 = 0, $624 = 0, $625 = 0, $626 = 0, $627 = 0, $628 = 0;
 var $629 = 0, $63 = 0, $630 = 0, $631 = 0, $632 = 0, $633 = 0, $634 = 0, $635 = 0, $636 = 0, $637 = 0, $638 = 0, $639 = 0, $64 = 0, $640 = 0, $641 = 0, $642 = 0, $643 = 0, $644 = 0, $645 = 0, $646 = 0;
 var $647 = 0, $648 = 0, $649 = 0, $65 = 0, $650 = 0, $651 = 0, $652 = 0, $653 = 0, $654 = 0, $655 = 0, $656 = 0, $657 = 0, $658 = 0, $659 = 0, $66 = 0, $660 = 0, $661 = 0, $662 = 0, $663 = 0, $664 = 0;
 var $665 = 0, $666 = 0, $667 = 0, $668 = 0, $669 = 0, $67 = 0, $670 = 0, $671 = 0, $672 = 0, $673 = 0, $674 = 0, $675 = 0, $676 = 0, $677 = 0, $678 = 0, $679 = 0, $68 = 0, $680 = 0, $681 = 0, $682 = 0;
 var $683 = 0, $684 = 0, $685 = 0, $686 = 0, $687 = 0, $688 = 0, $689 = 0, $69 = 0, $690 = 0, $691 = 0, $692 = 0, $693 = 0, $694 = 0, $695 = 0, $696 = 0, $697 = 0, $698 = 0, $699 = 0, $7 = 0, $70 = 0;
 var $700 = 0, $701 = 0, $702 = 0, $703 = 0, $704 = 0, $705 = 0, $706 = 0, $707 = 0, $708 = 0, $709 = 0, $71 = 0, $710 = 0, $711 = 0, $712 = 0, $713 = 0, $714 = 0, $715 = 0, $716 = 0, $717 = 0, $718 = 0;
 var $719 = 0, $72 = 0, $720 = 0, $721 = 0, $722 = 0, $723 = 0, $724 = 0, $725 = 0, $726 = 0, $727 = 0, $728 = 0, $729 = 0, $73 = 0, $730 = 0, $731 = 0, $732 = 0, $733 = 0, $734 = 0, $735 = 0, $736 = 0;
 var $737 = 0, $738 = 0, $739 = 0, $74 = 0, $740 = 0, $741 = 0, $742 = 0, $743 = 0, $744 = 0, $745 = 0, $746 = 0, $747 = 0, $748 = 0, $749 = 0, $75 = 0, $750 = 0, $751 = 0, $752 = 0, $753 = 0, $754 = 0;
 var $755 = 0, $756 = 0, $757 = 0, $758 = 0, $759 = 0, $76 = 0, $760 = 0, $761 = 0, $762 = 0, $763 = 0, $764 = 0, $765 = 0, $766 = 0, $767 = 0, $768 = 0, $769 = 0, $77 = 0, $770 = 0, $771 = 0, $772 = 0;
 var $773 = 0, $774 = 0, $775 = 0, $776 = 0, $777 = 0, $778 = 0, $779 = 0, $78 = 0, $780 = 0, $781 = 0, $782 = 0, $783 = 0, $784 = 0, $785 = 0, $786 = 0, $787 = 0, $788 = 0, $789 = 0, $79 = 0, $790 = 0;
 var $791 = 0, $792 = 0, $793 = 0, $794 = 0, $795 = 0, $796 = 0, $797 = 0, $798 = 0, $799 = 0, $8 = 0, $80 = 0, $800 = 0, $801 = 0, $802 = 0, $803 = 0, $804 = 0, $805 = 0, $806 = 0, $807 = 0, $808 = 0;
 var $809 = 0, $81 = 0, $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0;
 var $99 = 0, $arglist_current = 0, $arglist_current2 = 0, $arglist_next = 0, $arglist_next3 = 0, $exitcond$i = 0, $expanded = 0, $expanded10 = 0, $expanded11 = 0, $expanded13 = 0, $expanded14 = 0, $expanded15 = 0, $expanded4 = 0, $expanded6 = 0, $expanded7 = 0, $expanded8 = 0, $isdigit = 0, $isdigit$i = 0, $isdigit$i292 = 0, $isdigit275 = 0;
 var $isdigit277 = 0, $isdigit5$i = 0, $isdigit5$i288 = 0, $isdigittmp = 0, $isdigittmp$ = 0, $isdigittmp$i = 0, $isdigittmp$i291 = 0, $isdigittmp274 = 0, $isdigittmp276 = 0, $isdigittmp4$i = 0, $isdigittmp4$i287 = 0, $isdigittmp7$i = 0, $isdigittmp7$i289 = 0, $notlhs$i = 0, $notrhs$i = 0, $or$cond = 0, $or$cond$i = 0, $or$cond280 = 0, $or$cond282 = 0, $or$cond285 = 0;
 var $or$cond3$not$i = 0, $or$cond412 = 0, $or$cond540$i = 0, $or$cond543$i = 0, $or$cond552$i = 0, $or$cond6$i = 0, $scevgep694$i = 0, $scevgep694695$i = 0, $storemerge = 0, $storemerge273345 = 0, $storemerge273389 = 0, $storemerge278 = 0, $sum = 0, $trunc = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 624|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(624|0);
 $5 = sp + 24|0;
 $6 = sp + 16|0;
 $7 = sp + 588|0;
 $8 = sp + 576|0;
 $9 = sp;
 $10 = sp + 536|0;
 $11 = sp + 8|0;
 $12 = sp + 528|0;
 $13 = ($0|0)!=(0|0);
 $14 = ((($10)) + 40|0);
 $15 = $14;
 $16 = ((($10)) + 39|0);
 $17 = ((($11)) + 4|0);
 $18 = $7;
 $19 = (0 - ($18))|0;
 $20 = ((($8)) + 12|0);
 $21 = ((($8)) + 11|0);
 $22 = $20;
 $23 = (($22) - ($18))|0;
 $24 = (-2 - ($18))|0;
 $25 = (($22) + 2)|0;
 $26 = ((($5)) + 288|0);
 $27 = ((($7)) + 9|0);
 $28 = $27;
 $29 = ((($7)) + 8|0);
 $$0243 = 0;$$0247 = 0;$$0269 = 0;$$0321 = $1;
 L1: while(1) {
  $30 = ($$0247|0)>(-1);
  do {
   if ($30) {
    $31 = (2147483647 - ($$0247))|0;
    $32 = ($$0243|0)>($31|0);
    if ($32) {
     $33 = (___errno_location()|0);
     HEAP32[$33>>2] = 75;
     $$1248 = -1;
     break;
    } else {
     $34 = (($$0243) + ($$0247))|0;
     $$1248 = $34;
     break;
    }
   } else {
    $$1248 = $$0247;
   }
  } while(0);
  $35 = HEAP8[$$0321>>0]|0;
  $36 = ($35<<24>>24)==(0);
  if ($36) {
   label = 243;
   break;
  } else {
   $$1322 = $$0321;$37 = $35;
  }
  L9: while(1) {
   switch ($37<<24>>24) {
   case 37:  {
    $$0249383 = $$1322;$$2323382 = $$1322;
    label = 9;
    break L9;
    break;
   }
   case 0:  {
    $$0249$lcssa = $$1322;$$2323$lcssa = $$1322;
    break L9;
    break;
   }
   default: {
   }
   }
   $38 = ((($$1322)) + 1|0);
   $$pre = HEAP8[$38>>0]|0;
   $$1322 = $38;$37 = $$pre;
  }
  L12: do {
   if ((label|0) == 9) {
    while(1) {
     label = 0;
     $39 = ((($$2323382)) + 1|0);
     $40 = HEAP8[$39>>0]|0;
     $41 = ($40<<24>>24)==(37);
     if (!($41)) {
      $$0249$lcssa = $$0249383;$$2323$lcssa = $$2323382;
      break L12;
     }
     $42 = ((($$0249383)) + 1|0);
     $43 = ((($$2323382)) + 2|0);
     $44 = HEAP8[$43>>0]|0;
     $45 = ($44<<24>>24)==(37);
     if ($45) {
      $$0249383 = $42;$$2323382 = $43;
      label = 9;
     } else {
      $$0249$lcssa = $42;$$2323$lcssa = $43;
      break;
     }
    }
   }
  } while(0);
  $46 = $$0249$lcssa;
  $47 = $$0321;
  $48 = (($46) - ($47))|0;
  if ($13) {
   $49 = HEAP32[$0>>2]|0;
   $50 = $49 & 32;
   $51 = ($50|0)==(0);
   if ($51) {
    (___fwritex($$0321,$48,$0)|0);
   }
  }
  $52 = ($48|0)==(0);
  if (!($52)) {
   $$0269$phi = $$0269;$$0243 = $48;$$0247 = $$1248;$$0321 = $$2323$lcssa;$$0269 = $$0269$phi;
   continue;
  }
  $53 = ((($$2323$lcssa)) + 1|0);
  $54 = HEAP8[$53>>0]|0;
  $55 = $54 << 24 >> 24;
  $isdigittmp = (($55) + -48)|0;
  $isdigit = ($isdigittmp>>>0)<(10);
  if ($isdigit) {
   $56 = ((($$2323$lcssa)) + 2|0);
   $57 = HEAP8[$56>>0]|0;
   $58 = ($57<<24>>24)==(36);
   $59 = ((($$2323$lcssa)) + 3|0);
   $$331 = $58 ? $59 : $53;
   $$$0269 = $58 ? 1 : $$0269;
   $isdigittmp$ = $58 ? $isdigittmp : -1;
   $$pre452 = HEAP8[$$331>>0]|0;
   $$0253 = $isdigittmp$;$$1270 = $$$0269;$61 = $$pre452;$storemerge = $$331;
  } else {
   $$0253 = -1;$$1270 = $$0269;$61 = $54;$storemerge = $53;
  }
  $60 = $61 << 24 >> 24;
  $62 = (($60) + -32)|0;
  $63 = ($62>>>0)<(32);
  L25: do {
   if ($63) {
    $$0262390 = 0;$65 = $62;$69 = $61;$storemerge273389 = $storemerge;
    while(1) {
     $64 = 1 << $65;
     $66 = $64 & 75913;
     $67 = ($66|0)==(0);
     if ($67) {
      $$0262342 = $$0262390;$78 = $69;$storemerge273345 = $storemerge273389;
      break L25;
     }
     $68 = $69 << 24 >> 24;
     $70 = (($68) + -32)|0;
     $71 = 1 << $70;
     $72 = $71 | $$0262390;
     $73 = ((($storemerge273389)) + 1|0);
     $74 = HEAP8[$73>>0]|0;
     $75 = $74 << 24 >> 24;
     $76 = (($75) + -32)|0;
     $77 = ($76>>>0)<(32);
     if ($77) {
      $$0262390 = $72;$65 = $76;$69 = $74;$storemerge273389 = $73;
     } else {
      $$0262342 = $72;$78 = $74;$storemerge273345 = $73;
      break;
     }
    }
   } else {
    $$0262342 = 0;$78 = $61;$storemerge273345 = $storemerge;
   }
  } while(0);
  $79 = ($78<<24>>24)==(42);
  do {
   if ($79) {
    $80 = ((($storemerge273345)) + 1|0);
    $81 = HEAP8[$80>>0]|0;
    $82 = $81 << 24 >> 24;
    $isdigittmp276 = (($82) + -48)|0;
    $isdigit277 = ($isdigittmp276>>>0)<(10);
    if ($isdigit277) {
     $83 = ((($storemerge273345)) + 2|0);
     $84 = HEAP8[$83>>0]|0;
     $85 = ($84<<24>>24)==(36);
     if ($85) {
      $86 = (($4) + ($isdigittmp276<<2)|0);
      HEAP32[$86>>2] = 10;
      $87 = HEAP8[$80>>0]|0;
      $88 = $87 << 24 >> 24;
      $89 = (($88) + -48)|0;
      $90 = (($3) + ($89<<3)|0);
      $91 = $90;
      $92 = $91;
      $93 = HEAP32[$92>>2]|0;
      $94 = (($91) + 4)|0;
      $95 = $94;
      $96 = HEAP32[$95>>2]|0;
      $97 = ((($storemerge273345)) + 3|0);
      $$0259 = $93;$$2271 = 1;$storemerge278 = $97;
     } else {
      label = 24;
     }
    } else {
     label = 24;
    }
    if ((label|0) == 24) {
     label = 0;
     $98 = ($$1270|0)==(0);
     if (!($98)) {
      $$0 = -1;
      break L1;
     }
     if (!($13)) {
      $$1260 = 0;$$1263 = $$0262342;$$3272 = 0;$$4325 = $80;$$pr = $81;
      break;
     }
     $arglist_current = HEAP32[$2>>2]|0;
     $99 = $arglist_current;
     $100 = ((0) + 4|0);
     $expanded4 = $100;
     $expanded = (($expanded4) - 1)|0;
     $101 = (($99) + ($expanded))|0;
     $102 = ((0) + 4|0);
     $expanded8 = $102;
     $expanded7 = (($expanded8) - 1)|0;
     $expanded6 = $expanded7 ^ -1;
     $103 = $101 & $expanded6;
     $104 = $103;
     $105 = HEAP32[$104>>2]|0;
     $arglist_next = ((($104)) + 4|0);
     HEAP32[$2>>2] = $arglist_next;
     $$0259 = $105;$$2271 = 0;$storemerge278 = $80;
    }
    $106 = ($$0259|0)<(0);
    $107 = $$0262342 | 8192;
    $108 = (0 - ($$0259))|0;
    $$$0262 = $106 ? $107 : $$0262342;
    $$$0259 = $106 ? $108 : $$0259;
    $$pre453 = HEAP8[$storemerge278>>0]|0;
    $$1260 = $$$0259;$$1263 = $$$0262;$$3272 = $$2271;$$4325 = $storemerge278;$$pr = $$pre453;
   } else {
    $109 = $78 << 24 >> 24;
    $isdigittmp4$i = (($109) + -48)|0;
    $isdigit5$i = ($isdigittmp4$i>>>0)<(10);
    if ($isdigit5$i) {
     $$06$i = 0;$113 = $storemerge273345;$isdigittmp7$i = $isdigittmp4$i;
     while(1) {
      $110 = ($$06$i*10)|0;
      $111 = (($110) + ($isdigittmp7$i))|0;
      $112 = ((($113)) + 1|0);
      $114 = HEAP8[$112>>0]|0;
      $115 = $114 << 24 >> 24;
      $isdigittmp$i = (($115) + -48)|0;
      $isdigit$i = ($isdigittmp$i>>>0)<(10);
      if ($isdigit$i) {
       $$06$i = $111;$113 = $112;$isdigittmp7$i = $isdigittmp$i;
      } else {
       break;
      }
     }
     $116 = ($111|0)<(0);
     if ($116) {
      $$0 = -1;
      break L1;
     } else {
      $$1260 = $111;$$1263 = $$0262342;$$3272 = $$1270;$$4325 = $112;$$pr = $114;
     }
    } else {
     $$1260 = 0;$$1263 = $$0262342;$$3272 = $$1270;$$4325 = $storemerge273345;$$pr = $78;
    }
   }
  } while(0);
  $117 = ($$pr<<24>>24)==(46);
  L45: do {
   if ($117) {
    $118 = ((($$4325)) + 1|0);
    $119 = HEAP8[$118>>0]|0;
    $120 = ($119<<24>>24)==(42);
    if (!($120)) {
     $147 = $119 << 24 >> 24;
     $isdigittmp4$i287 = (($147) + -48)|0;
     $isdigit5$i288 = ($isdigittmp4$i287>>>0)<(10);
     if ($isdigit5$i288) {
      $$06$i290 = 0;$151 = $118;$isdigittmp7$i289 = $isdigittmp4$i287;
     } else {
      $$0254 = 0;$$6 = $118;
      break;
     }
     while(1) {
      $148 = ($$06$i290*10)|0;
      $149 = (($148) + ($isdigittmp7$i289))|0;
      $150 = ((($151)) + 1|0);
      $152 = HEAP8[$150>>0]|0;
      $153 = $152 << 24 >> 24;
      $isdigittmp$i291 = (($153) + -48)|0;
      $isdigit$i292 = ($isdigittmp$i291>>>0)<(10);
      if ($isdigit$i292) {
       $$06$i290 = $149;$151 = $150;$isdigittmp7$i289 = $isdigittmp$i291;
      } else {
       $$0254 = $149;$$6 = $150;
       break L45;
      }
     }
    }
    $121 = ((($$4325)) + 2|0);
    $122 = HEAP8[$121>>0]|0;
    $123 = $122 << 24 >> 24;
    $isdigittmp274 = (($123) + -48)|0;
    $isdigit275 = ($isdigittmp274>>>0)<(10);
    if ($isdigit275) {
     $124 = ((($$4325)) + 3|0);
     $125 = HEAP8[$124>>0]|0;
     $126 = ($125<<24>>24)==(36);
     if ($126) {
      $127 = (($4) + ($isdigittmp274<<2)|0);
      HEAP32[$127>>2] = 10;
      $128 = HEAP8[$121>>0]|0;
      $129 = $128 << 24 >> 24;
      $130 = (($129) + -48)|0;
      $131 = (($3) + ($130<<3)|0);
      $132 = $131;
      $133 = $132;
      $134 = HEAP32[$133>>2]|0;
      $135 = (($132) + 4)|0;
      $136 = $135;
      $137 = HEAP32[$136>>2]|0;
      $138 = ((($$4325)) + 4|0);
      $$0254 = $134;$$6 = $138;
      break;
     }
    }
    $139 = ($$3272|0)==(0);
    if (!($139)) {
     $$0 = -1;
     break L1;
    }
    if ($13) {
     $arglist_current2 = HEAP32[$2>>2]|0;
     $140 = $arglist_current2;
     $141 = ((0) + 4|0);
     $expanded11 = $141;
     $expanded10 = (($expanded11) - 1)|0;
     $142 = (($140) + ($expanded10))|0;
     $143 = ((0) + 4|0);
     $expanded15 = $143;
     $expanded14 = (($expanded15) - 1)|0;
     $expanded13 = $expanded14 ^ -1;
     $144 = $142 & $expanded13;
     $145 = $144;
     $146 = HEAP32[$145>>2]|0;
     $arglist_next3 = ((($145)) + 4|0);
     HEAP32[$2>>2] = $arglist_next3;
     $$0254 = $146;$$6 = $121;
    } else {
     $$0254 = 0;$$6 = $121;
    }
   } else {
    $$0254 = -1;$$6 = $$4325;
   }
  } while(0);
  $$0252 = 0;$$7 = $$6;
  while(1) {
   $154 = HEAP8[$$7>>0]|0;
   $155 = $154 << 24 >> 24;
   $156 = (($155) + -65)|0;
   $157 = ($156>>>0)>(57);
   if ($157) {
    $$0 = -1;
    break L1;
   }
   $158 = ((($$7)) + 1|0);
   $159 = ((424 + (($$0252*58)|0)|0) + ($156)|0);
   $160 = HEAP8[$159>>0]|0;
   $161 = $160&255;
   $162 = (($161) + -1)|0;
   $163 = ($162>>>0)<(8);
   if ($163) {
    $$0252 = $161;$$7 = $158;
   } else {
    break;
   }
  }
  $164 = ($160<<24>>24)==(0);
  if ($164) {
   $$0 = -1;
   break;
  }
  $165 = ($160<<24>>24)==(19);
  $166 = ($$0253|0)>(-1);
  do {
   if ($165) {
    if ($166) {
     $$0 = -1;
     break L1;
    } else {
     label = 51;
    }
   } else {
    if ($166) {
     $167 = (($4) + ($$0253<<2)|0);
     HEAP32[$167>>2] = $161;
     $168 = (($3) + ($$0253<<3)|0);
     $169 = $168;
     $170 = $169;
     $171 = HEAP32[$170>>2]|0;
     $172 = (($169) + 4)|0;
     $173 = $172;
     $174 = HEAP32[$173>>2]|0;
     $175 = $9;
     $176 = $175;
     HEAP32[$176>>2] = $171;
     $177 = (($175) + 4)|0;
     $178 = $177;
     HEAP32[$178>>2] = $174;
     label = 51;
     break;
    }
    if (!($13)) {
     $$0 = 0;
     break L1;
    }
    _pop_arg($9,$161,$2);
   }
  } while(0);
  if ((label|0) == 51) {
   label = 0;
   if (!($13)) {
    $$0243 = 0;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
    continue;
   }
  }
  $179 = HEAP8[$$7>>0]|0;
  $180 = $179 << 24 >> 24;
  $181 = ($$0252|0)!=(0);
  $182 = $180 & 15;
  $183 = ($182|0)==(3);
  $or$cond280 = $181 & $183;
  $184 = $180 & -33;
  $$0235 = $or$cond280 ? $184 : $180;
  $185 = $$1263 & 8192;
  $186 = ($185|0)==(0);
  $187 = $$1263 & -65537;
  $$1263$ = $186 ? $$1263 : $187;
  L74: do {
   switch ($$0235|0) {
   case 110:  {
    $trunc = $$0252&255;
    switch ($trunc<<24>>24) {
    case 0:  {
     $194 = HEAP32[$9>>2]|0;
     HEAP32[$194>>2] = $$1248;
     $$0243 = 0;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
     continue L1;
     break;
    }
    case 1:  {
     $195 = HEAP32[$9>>2]|0;
     HEAP32[$195>>2] = $$1248;
     $$0243 = 0;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
     continue L1;
     break;
    }
    case 2:  {
     $196 = ($$1248|0)<(0);
     $197 = $196 << 31 >> 31;
     $198 = HEAP32[$9>>2]|0;
     $199 = $198;
     $200 = $199;
     HEAP32[$200>>2] = $$1248;
     $201 = (($199) + 4)|0;
     $202 = $201;
     HEAP32[$202>>2] = $197;
     $$0243 = 0;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
     continue L1;
     break;
    }
    case 3:  {
     $203 = $$1248&65535;
     $204 = HEAP32[$9>>2]|0;
     HEAP16[$204>>1] = $203;
     $$0243 = 0;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
     continue L1;
     break;
    }
    case 4:  {
     $205 = $$1248&255;
     $206 = HEAP32[$9>>2]|0;
     HEAP8[$206>>0] = $205;
     $$0243 = 0;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
     continue L1;
     break;
    }
    case 6:  {
     $207 = HEAP32[$9>>2]|0;
     HEAP32[$207>>2] = $$1248;
     $$0243 = 0;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
     continue L1;
     break;
    }
    case 7:  {
     $208 = ($$1248|0)<(0);
     $209 = $208 << 31 >> 31;
     $210 = HEAP32[$9>>2]|0;
     $211 = $210;
     $212 = $211;
     HEAP32[$212>>2] = $$1248;
     $213 = (($211) + 4)|0;
     $214 = $213;
     HEAP32[$214>>2] = $209;
     $$0243 = 0;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
     continue L1;
     break;
    }
    default: {
     $$0243 = 0;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
     continue L1;
    }
    }
    break;
   }
   case 112:  {
    $215 = ($$0254>>>0)>(8);
    $216 = $215 ? $$0254 : 8;
    $217 = $$1263$ | 8;
    $$1236 = 120;$$1255 = $216;$$3265 = $217;
    label = 63;
    break;
   }
   case 88: case 120:  {
    $$1236 = $$0235;$$1255 = $$0254;$$3265 = $$1263$;
    label = 63;
    break;
   }
   case 111:  {
    $257 = $9;
    $258 = $257;
    $259 = HEAP32[$258>>2]|0;
    $260 = (($257) + 4)|0;
    $261 = $260;
    $262 = HEAP32[$261>>2]|0;
    $263 = ($259|0)==(0);
    $264 = ($262|0)==(0);
    $265 = $263 & $264;
    if ($265) {
     $$0$lcssa$i300 = $14;
    } else {
     $$06$i298 = $14;$267 = $259;$271 = $262;
     while(1) {
      $266 = $267 & 7;
      $268 = $266 | 48;
      $269 = $268&255;
      $270 = ((($$06$i298)) + -1|0);
      HEAP8[$270>>0] = $269;
      $272 = (_bitshift64Lshr(($267|0),($271|0),3)|0);
      $273 = tempRet0;
      $274 = ($272|0)==(0);
      $275 = ($273|0)==(0);
      $276 = $274 & $275;
      if ($276) {
       $$0$lcssa$i300 = $270;
       break;
      } else {
       $$06$i298 = $270;$267 = $272;$271 = $273;
      }
     }
    }
    $277 = $$1263$ & 8;
    $278 = ($277|0)==(0);
    if ($278) {
     $$0228 = $$0$lcssa$i300;$$1233 = 0;$$1238 = 904;$$2256 = $$0254;$$4266 = $$1263$;
     label = 76;
    } else {
     $279 = $$0$lcssa$i300;
     $280 = (($15) - ($279))|0;
     $281 = ($$0254|0)>($280|0);
     $282 = (($280) + 1)|0;
     $$0254$ = $281 ? $$0254 : $282;
     $$0228 = $$0$lcssa$i300;$$1233 = 0;$$1238 = 904;$$2256 = $$0254$;$$4266 = $$1263$;
     label = 76;
    }
    break;
   }
   case 105: case 100:  {
    $283 = $9;
    $284 = $283;
    $285 = HEAP32[$284>>2]|0;
    $286 = (($283) + 4)|0;
    $287 = $286;
    $288 = HEAP32[$287>>2]|0;
    $289 = ($288|0)<(0);
    if ($289) {
     $290 = (_i64Subtract(0,0,($285|0),($288|0))|0);
     $291 = tempRet0;
     $292 = $9;
     $293 = $292;
     HEAP32[$293>>2] = $290;
     $294 = (($292) + 4)|0;
     $295 = $294;
     HEAP32[$295>>2] = $291;
     $$0232 = 1;$$0237 = 904;$300 = $290;$301 = $291;
     label = 75;
     break L74;
    }
    $296 = $$1263$ & 2048;
    $297 = ($296|0)==(0);
    if ($297) {
     $298 = $$1263$ & 1;
     $299 = ($298|0)==(0);
     $$ = $299 ? 904 : (906);
     $$0232 = $298;$$0237 = $$;$300 = $285;$301 = $288;
     label = 75;
    } else {
     $$0232 = 1;$$0237 = (905);$300 = $285;$301 = $288;
     label = 75;
    }
    break;
   }
   case 117:  {
    $188 = $9;
    $189 = $188;
    $190 = HEAP32[$189>>2]|0;
    $191 = (($188) + 4)|0;
    $192 = $191;
    $193 = HEAP32[$192>>2]|0;
    $$0232 = 0;$$0237 = 904;$300 = $190;$301 = $193;
    label = 75;
    break;
   }
   case 99:  {
    $321 = $9;
    $322 = $321;
    $323 = HEAP32[$322>>2]|0;
    $324 = (($321) + 4)|0;
    $325 = $324;
    $326 = HEAP32[$325>>2]|0;
    $327 = $323&255;
    HEAP8[$16>>0] = $327;
    $$2 = $16;$$2234 = 0;$$2239 = 904;$$2251 = $14;$$5 = 1;$$6268 = $187;
    break;
   }
   case 109:  {
    $328 = (___errno_location()|0);
    $329 = HEAP32[$328>>2]|0;
    $330 = (_strerror($329)|0);
    $$1 = $330;
    label = 81;
    break;
   }
   case 115:  {
    $331 = HEAP32[$9>>2]|0;
    $332 = ($331|0)!=(0|0);
    $333 = $332 ? $331 : 914;
    $$1 = $333;
    label = 81;
    break;
   }
   case 67:  {
    $340 = $9;
    $341 = $340;
    $342 = HEAP32[$341>>2]|0;
    $343 = (($340) + 4)|0;
    $344 = $343;
    $345 = HEAP32[$344>>2]|0;
    HEAP32[$11>>2] = $342;
    HEAP32[$17>>2] = 0;
    HEAP32[$9>>2] = $11;
    $$4258458 = -1;$809 = $11;
    label = 85;
    break;
   }
   case 83:  {
    $$pre454 = HEAP32[$9>>2]|0;
    $346 = ($$0254|0)==(0);
    if ($346) {
     _pad($0,32,$$1260,0,$$1263$);
     $$0240$lcssa460 = 0;
     label = 96;
    } else {
     $$4258458 = $$0254;$809 = $$pre454;
     label = 85;
    }
    break;
   }
   case 65: case 71: case 70: case 69: case 97: case 103: case 102: case 101:  {
    $371 = +HEAPF64[$9>>3];
    HEAP32[$6>>2] = 0;
    HEAPF64[tempDoublePtr>>3] = $371;$372 = HEAP32[tempDoublePtr>>2]|0;
    $373 = HEAP32[tempDoublePtr+4>>2]|0;
    $374 = ($373|0)<(0);
    if ($374) {
     $375 = -$371;
     $$0471$i = $375;$$0520$i = 1;$$0522$i = 921;
    } else {
     $376 = $$1263$ & 2048;
     $377 = ($376|0)==(0);
     $378 = $$1263$ & 1;
     if ($377) {
      $379 = ($378|0)==(0);
      $$$i = $379 ? (922) : (927);
      $$0471$i = $371;$$0520$i = $378;$$0522$i = $$$i;
     } else {
      $$0471$i = $371;$$0520$i = 1;$$0522$i = (924);
     }
    }
    HEAPF64[tempDoublePtr>>3] = $$0471$i;$380 = HEAP32[tempDoublePtr>>2]|0;
    $381 = HEAP32[tempDoublePtr+4>>2]|0;
    $382 = $381 & 2146435072;
    $383 = ($382>>>0)<(2146435072);
    $384 = (0)<(0);
    $385 = ($382|0)==(2146435072);
    $386 = $385 & $384;
    $387 = $383 | $386;
    do {
     if ($387) {
      $403 = (+_frexpl($$0471$i,$6));
      $404 = $403 * 2.0;
      $405 = $404 != 0.0;
      if ($405) {
       $406 = HEAP32[$6>>2]|0;
       $407 = (($406) + -1)|0;
       HEAP32[$6>>2] = $407;
      }
      $408 = $$0235 | 32;
      $409 = ($408|0)==(97);
      if ($409) {
       $410 = $$0235 & 32;
       $411 = ($410|0)==(0);
       $412 = ((($$0522$i)) + 9|0);
       $$0522$$i = $411 ? $$0522$i : $412;
       $413 = $$0520$i | 2;
       $414 = ($$0254>>>0)>(11);
       $415 = (12 - ($$0254))|0;
       $416 = ($415|0)==(0);
       $417 = $414 | $416;
       do {
        if ($417) {
         $$1472$i = $404;
        } else {
         $$0509592$i = 8.0;$$1508593$i = $415;
         while(1) {
          $418 = (($$1508593$i) + -1)|0;
          $419 = $$0509592$i * 16.0;
          $420 = ($418|0)==(0);
          if ($420) {
           break;
          } else {
           $$0509592$i = $419;$$1508593$i = $418;
          }
         }
         $421 = HEAP8[$$0522$$i>>0]|0;
         $422 = ($421<<24>>24)==(45);
         if ($422) {
          $423 = -$404;
          $424 = $423 - $419;
          $425 = $419 + $424;
          $426 = -$425;
          $$1472$i = $426;
          break;
         } else {
          $427 = $404 + $419;
          $428 = $427 - $419;
          $$1472$i = $428;
          break;
         }
        }
       } while(0);
       $429 = HEAP32[$6>>2]|0;
       $430 = ($429|0)<(0);
       $431 = (0 - ($429))|0;
       $432 = $430 ? $431 : $429;
       $433 = ($432|0)<(0);
       $434 = $433 << 31 >> 31;
       $435 = (_fmt_u($432,$434,$20)|0);
       $436 = ($435|0)==($20|0);
       if ($436) {
        HEAP8[$21>>0] = 48;
        $$0511$i = $21;
       } else {
        $$0511$i = $435;
       }
       $437 = $429 >> 31;
       $438 = $437 & 2;
       $439 = (($438) + 43)|0;
       $440 = $439&255;
       $441 = ((($$0511$i)) + -1|0);
       HEAP8[$441>>0] = $440;
       $442 = (($$0235) + 15)|0;
       $443 = $442&255;
       $444 = ((($$0511$i)) + -2|0);
       HEAP8[$444>>0] = $443;
       $notrhs$i = ($$0254|0)<(1);
       $445 = $$1263$ & 8;
       $446 = ($445|0)==(0);
       $$0524$i = $7;$$2473$i = $$1472$i;
       while(1) {
        $447 = (~~(($$2473$i)));
        $448 = (888 + ($447)|0);
        $449 = HEAP8[$448>>0]|0;
        $450 = $449&255;
        $451 = $450 | $410;
        $452 = $451&255;
        $453 = ((($$0524$i)) + 1|0);
        HEAP8[$$0524$i>>0] = $452;
        $454 = (+($447|0));
        $455 = $$2473$i - $454;
        $456 = $455 * 16.0;
        $457 = $453;
        $458 = (($457) - ($18))|0;
        $459 = ($458|0)==(1);
        do {
         if ($459) {
          $notlhs$i = $456 == 0.0;
          $or$cond3$not$i = $notrhs$i & $notlhs$i;
          $or$cond$i = $446 & $or$cond3$not$i;
          if ($or$cond$i) {
           $$1525$i = $453;
           break;
          }
          $460 = ((($$0524$i)) + 2|0);
          HEAP8[$453>>0] = 46;
          $$1525$i = $460;
         } else {
          $$1525$i = $453;
         }
        } while(0);
        $461 = $456 != 0.0;
        if ($461) {
         $$0524$i = $$1525$i;$$2473$i = $456;
        } else {
         break;
        }
       }
       $462 = ($$0254|0)!=(0);
       $$pre700$i = $$1525$i;
       $463 = (($24) + ($$pre700$i))|0;
       $464 = ($463|0)<($$0254|0);
       $or$cond412 = $462 & $464;
       $465 = $444;
       $466 = (($25) + ($$0254))|0;
       $467 = (($466) - ($465))|0;
       $468 = (($23) - ($465))|0;
       $469 = (($468) + ($$pre700$i))|0;
       $$0526$i = $or$cond412 ? $467 : $469;
       $470 = (($$0526$i) + ($413))|0;
       _pad($0,32,$$1260,$470,$$1263$);
       $471 = HEAP32[$0>>2]|0;
       $472 = $471 & 32;
       $473 = ($472|0)==(0);
       if ($473) {
        (___fwritex($$0522$$i,$413,$0)|0);
       }
       $474 = $$1263$ ^ 65536;
       _pad($0,48,$$1260,$470,$474);
       $475 = (($$pre700$i) - ($18))|0;
       $476 = HEAP32[$0>>2]|0;
       $477 = $476 & 32;
       $478 = ($477|0)==(0);
       if ($478) {
        (___fwritex($7,$475,$0)|0);
       }
       $479 = (($22) - ($465))|0;
       $sum = (($475) + ($479))|0;
       $480 = (($$0526$i) - ($sum))|0;
       _pad($0,48,$480,0,0);
       $481 = HEAP32[$0>>2]|0;
       $482 = $481 & 32;
       $483 = ($482|0)==(0);
       if ($483) {
        (___fwritex($444,$479,$0)|0);
       }
       $484 = $$1263$ ^ 8192;
       _pad($0,32,$$1260,$470,$484);
       $485 = ($470|0)<($$1260|0);
       $$537$i = $485 ? $$1260 : $470;
       $$0470$i = $$537$i;
       break;
      }
      $486 = ($$0254|0)<(0);
      $$538$i = $486 ? 6 : $$0254;
      if ($405) {
       $487 = $404 * 268435456.0;
       $488 = HEAP32[$6>>2]|0;
       $489 = (($488) + -28)|0;
       HEAP32[$6>>2] = $489;
       $$3$i = $487;$$pr$i = $489;
      } else {
       $$pre697$i = HEAP32[$6>>2]|0;
       $$3$i = $404;$$pr$i = $$pre697$i;
      }
      $490 = ($$pr$i|0)<(0);
      $$554$i = $490 ? $5 : $26;
      $$0498$i = $$554$i;$$4$i = $$3$i;
      while(1) {
       $491 = (~~(($$4$i))>>>0);
       HEAP32[$$0498$i>>2] = $491;
       $492 = ((($$0498$i)) + 4|0);
       $493 = (+($491>>>0));
       $494 = $$4$i - $493;
       $495 = $494 * 1.0E+9;
       $496 = $495 != 0.0;
       if ($496) {
        $$0498$i = $492;$$4$i = $495;
       } else {
        break;
       }
      }
      $497 = ($$pr$i|0)>(0);
      if ($497) {
       $$1482671$i = $$554$i;$$1499670$i = $492;$498 = $$pr$i;
       while(1) {
        $499 = ($498|0)>(29);
        $500 = $499 ? 29 : $498;
        $$0488663$i = ((($$1499670$i)) + -4|0);
        $501 = ($$0488663$i>>>0)<($$1482671$i>>>0);
        do {
         if ($501) {
          $$2483$ph$i = $$1482671$i;
         } else {
          $$0488665$i = $$0488663$i;$$0497664$i = 0;
          while(1) {
           $502 = HEAP32[$$0488665$i>>2]|0;
           $503 = (_bitshift64Shl(($502|0),0,($500|0))|0);
           $504 = tempRet0;
           $505 = (_i64Add(($503|0),($504|0),($$0497664$i|0),0)|0);
           $506 = tempRet0;
           $507 = (___uremdi3(($505|0),($506|0),1000000000,0)|0);
           $508 = tempRet0;
           HEAP32[$$0488665$i>>2] = $507;
           $509 = (___udivdi3(($505|0),($506|0),1000000000,0)|0);
           $510 = tempRet0;
           $$0488$i = ((($$0488665$i)) + -4|0);
           $511 = ($$0488$i>>>0)<($$1482671$i>>>0);
           if ($511) {
            break;
           } else {
            $$0488665$i = $$0488$i;$$0497664$i = $509;
           }
          }
          $512 = ($509|0)==(0);
          if ($512) {
           $$2483$ph$i = $$1482671$i;
           break;
          }
          $513 = ((($$1482671$i)) + -4|0);
          HEAP32[$513>>2] = $509;
          $$2483$ph$i = $513;
         }
        } while(0);
        $$2500$i = $$1499670$i;
        while(1) {
         $514 = ($$2500$i>>>0)>($$2483$ph$i>>>0);
         if (!($514)) {
          break;
         }
         $515 = ((($$2500$i)) + -4|0);
         $516 = HEAP32[$515>>2]|0;
         $517 = ($516|0)==(0);
         if ($517) {
          $$2500$i = $515;
         } else {
          break;
         }
        }
        $518 = HEAP32[$6>>2]|0;
        $519 = (($518) - ($500))|0;
        HEAP32[$6>>2] = $519;
        $520 = ($519|0)>(0);
        if ($520) {
         $$1482671$i = $$2483$ph$i;$$1499670$i = $$2500$i;$498 = $519;
        } else {
         $$1482$lcssa$i = $$2483$ph$i;$$1499$lcssa$i = $$2500$i;$$pr571$i = $519;
         break;
        }
       }
      } else {
       $$1482$lcssa$i = $$554$i;$$1499$lcssa$i = $492;$$pr571$i = $$pr$i;
      }
      $521 = ($$pr571$i|0)<(0);
      if ($521) {
       $522 = (($$538$i) + 25)|0;
       $523 = (($522|0) / 9)&-1;
       $524 = (($523) + 1)|0;
       $525 = ($408|0)==(102);
       $$3484658$i = $$1482$lcssa$i;$$3501657$i = $$1499$lcssa$i;$527 = $$pr571$i;
       while(1) {
        $526 = (0 - ($527))|0;
        $528 = ($526|0)>(9);
        $529 = $528 ? 9 : $526;
        $530 = ($$3484658$i>>>0)<($$3501657$i>>>0);
        do {
         if ($530) {
          $534 = 1 << $529;
          $535 = (($534) + -1)|0;
          $536 = 1000000000 >>> $529;
          $$0487652$i = 0;$$1489651$i = $$3484658$i;
          while(1) {
           $537 = HEAP32[$$1489651$i>>2]|0;
           $538 = $537 & $535;
           $539 = $537 >>> $529;
           $540 = (($539) + ($$0487652$i))|0;
           HEAP32[$$1489651$i>>2] = $540;
           $541 = Math_imul($538, $536)|0;
           $542 = ((($$1489651$i)) + 4|0);
           $543 = ($542>>>0)<($$3501657$i>>>0);
           if ($543) {
            $$0487652$i = $541;$$1489651$i = $542;
           } else {
            break;
           }
          }
          $544 = HEAP32[$$3484658$i>>2]|0;
          $545 = ($544|0)==(0);
          $546 = ((($$3484658$i)) + 4|0);
          $$$3484$i = $545 ? $546 : $$3484658$i;
          $547 = ($541|0)==(0);
          if ($547) {
           $$$3484706$i = $$$3484$i;$$4502$i = $$3501657$i;
           break;
          }
          $548 = ((($$3501657$i)) + 4|0);
          HEAP32[$$3501657$i>>2] = $541;
          $$$3484706$i = $$$3484$i;$$4502$i = $548;
         } else {
          $531 = HEAP32[$$3484658$i>>2]|0;
          $532 = ($531|0)==(0);
          $533 = ((($$3484658$i)) + 4|0);
          $$$3484705$i = $532 ? $533 : $$3484658$i;
          $$$3484706$i = $$$3484705$i;$$4502$i = $$3501657$i;
         }
        } while(0);
        $549 = $525 ? $$554$i : $$$3484706$i;
        $550 = $$4502$i;
        $551 = $549;
        $552 = (($550) - ($551))|0;
        $553 = $552 >> 2;
        $554 = ($553|0)>($524|0);
        $555 = (($549) + ($524<<2)|0);
        $$$4502$i = $554 ? $555 : $$4502$i;
        $556 = HEAP32[$6>>2]|0;
        $557 = (($556) + ($529))|0;
        HEAP32[$6>>2] = $557;
        $558 = ($557|0)<(0);
        if ($558) {
         $$3484658$i = $$$3484706$i;$$3501657$i = $$$4502$i;$527 = $557;
        } else {
         $$3484$lcssa$i = $$$3484706$i;$$3501$lcssa$i = $$$4502$i;
         break;
        }
       }
      } else {
       $$3484$lcssa$i = $$1482$lcssa$i;$$3501$lcssa$i = $$1499$lcssa$i;
      }
      $559 = ($$3484$lcssa$i>>>0)<($$3501$lcssa$i>>>0);
      $560 = $$554$i;
      do {
       if ($559) {
        $561 = $$3484$lcssa$i;
        $562 = (($560) - ($561))|0;
        $563 = $562 >> 2;
        $564 = ($563*9)|0;
        $565 = HEAP32[$$3484$lcssa$i>>2]|0;
        $566 = ($565>>>0)<(10);
        if ($566) {
         $$1515$i = $564;
         break;
        } else {
         $$0514647$i = $564;$$0531646$i = 10;
        }
        while(1) {
         $567 = ($$0531646$i*10)|0;
         $568 = (($$0514647$i) + 1)|0;
         $569 = ($565>>>0)<($567>>>0);
         if ($569) {
          $$1515$i = $568;
          break;
         } else {
          $$0514647$i = $568;$$0531646$i = $567;
         }
        }
       } else {
        $$1515$i = 0;
       }
      } while(0);
      $570 = ($408|0)!=(102);
      $571 = $570 ? $$1515$i : 0;
      $572 = (($$538$i) - ($571))|0;
      $573 = ($408|0)==(103);
      $574 = ($$538$i|0)!=(0);
      $575 = $574 & $573;
      $$neg$i = $575 << 31 >> 31;
      $576 = (($572) + ($$neg$i))|0;
      $577 = $$3501$lcssa$i;
      $578 = (($577) - ($560))|0;
      $579 = $578 >> 2;
      $580 = ($579*9)|0;
      $581 = (($580) + -9)|0;
      $582 = ($576|0)<($581|0);
      if ($582) {
       $583 = ((($$554$i)) + 4|0);
       $584 = (($576) + 9216)|0;
       $585 = (($584|0) / 9)&-1;
       $586 = (($585) + -1024)|0;
       $587 = (($583) + ($586<<2)|0);
       $588 = (($584|0) % 9)&-1;
       $$0528639$i = (($588) + 1)|0;
       $589 = ($$0528639$i|0)<(9);
       if ($589) {
        $$0528641$i = $$0528639$i;$$1532640$i = 10;
        while(1) {
         $590 = ($$1532640$i*10)|0;
         $$0528$i = (($$0528641$i) + 1)|0;
         $exitcond$i = ($$0528$i|0)==(9);
         if ($exitcond$i) {
          $$1532$lcssa$i = $590;
          break;
         } else {
          $$0528641$i = $$0528$i;$$1532640$i = $590;
         }
        }
       } else {
        $$1532$lcssa$i = 10;
       }
       $591 = HEAP32[$587>>2]|0;
       $592 = (($591>>>0) % ($$1532$lcssa$i>>>0))&-1;
       $593 = ($592|0)==(0);
       $594 = ((($587)) + 4|0);
       $595 = ($594|0)==($$3501$lcssa$i|0);
       $or$cond540$i = $595 & $593;
       do {
        if ($or$cond540$i) {
         $$4492$i = $587;$$4518$i = $$1515$i;$$8$i = $$3484$lcssa$i;
        } else {
         $596 = (($591>>>0) / ($$1532$lcssa$i>>>0))&-1;
         $597 = $596 & 1;
         $598 = ($597|0)==(0);
         $$541$i = $598 ? 9007199254740992.0 : 9007199254740994.0;
         $599 = (($$1532$lcssa$i|0) / 2)&-1;
         $600 = ($592>>>0)<($599>>>0);
         if ($600) {
          $$0466$i = 0.5;
         } else {
          $601 = ($592|0)==($599|0);
          $or$cond543$i = $595 & $601;
          $$557$i = $or$cond543$i ? 1.0 : 1.5;
          $$0466$i = $$557$i;
         }
         $602 = ($$0520$i|0)==(0);
         do {
          if ($602) {
           $$1467$i = $$0466$i;$$1469$i = $$541$i;
          } else {
           $603 = HEAP8[$$0522$i>>0]|0;
           $604 = ($603<<24>>24)==(45);
           if (!($604)) {
            $$1467$i = $$0466$i;$$1469$i = $$541$i;
            break;
           }
           $605 = -$$541$i;
           $606 = -$$0466$i;
           $$1467$i = $606;$$1469$i = $605;
          }
         } while(0);
         $607 = (($591) - ($592))|0;
         HEAP32[$587>>2] = $607;
         $608 = $$1469$i + $$1467$i;
         $609 = $608 != $$1469$i;
         if (!($609)) {
          $$4492$i = $587;$$4518$i = $$1515$i;$$8$i = $$3484$lcssa$i;
          break;
         }
         $610 = (($607) + ($$1532$lcssa$i))|0;
         HEAP32[$587>>2] = $610;
         $611 = ($610>>>0)>(999999999);
         if ($611) {
          $$2490632$i = $587;$$5486633$i = $$3484$lcssa$i;
          while(1) {
           $612 = ((($$2490632$i)) + -4|0);
           HEAP32[$$2490632$i>>2] = 0;
           $613 = ($612>>>0)<($$5486633$i>>>0);
           if ($613) {
            $614 = ((($$5486633$i)) + -4|0);
            HEAP32[$614>>2] = 0;
            $$6$i = $614;
           } else {
            $$6$i = $$5486633$i;
           }
           $615 = HEAP32[$612>>2]|0;
           $616 = (($615) + 1)|0;
           HEAP32[$612>>2] = $616;
           $617 = ($616>>>0)>(999999999);
           if ($617) {
            $$2490632$i = $612;$$5486633$i = $$6$i;
           } else {
            $$2490$lcssa$i = $612;$$5486$lcssa$i = $$6$i;
            break;
           }
          }
         } else {
          $$2490$lcssa$i = $587;$$5486$lcssa$i = $$3484$lcssa$i;
         }
         $618 = $$5486$lcssa$i;
         $619 = (($560) - ($618))|0;
         $620 = $619 >> 2;
         $621 = ($620*9)|0;
         $622 = HEAP32[$$5486$lcssa$i>>2]|0;
         $623 = ($622>>>0)<(10);
         if ($623) {
          $$4492$i = $$2490$lcssa$i;$$4518$i = $621;$$8$i = $$5486$lcssa$i;
          break;
         } else {
          $$2516628$i = $621;$$2533627$i = 10;
         }
         while(1) {
          $624 = ($$2533627$i*10)|0;
          $625 = (($$2516628$i) + 1)|0;
          $626 = ($622>>>0)<($624>>>0);
          if ($626) {
           $$4492$i = $$2490$lcssa$i;$$4518$i = $625;$$8$i = $$5486$lcssa$i;
           break;
          } else {
           $$2516628$i = $625;$$2533627$i = $624;
          }
         }
        }
       } while(0);
       $627 = ((($$4492$i)) + 4|0);
       $628 = ($$3501$lcssa$i>>>0)>($627>>>0);
       $$$3501$i = $628 ? $627 : $$3501$lcssa$i;
       $$5519$ph$i = $$4518$i;$$7505$ph$i = $$$3501$i;$$9$ph$i = $$8$i;
      } else {
       $$5519$ph$i = $$1515$i;$$7505$ph$i = $$3501$lcssa$i;$$9$ph$i = $$3484$lcssa$i;
      }
      $629 = (0 - ($$5519$ph$i))|0;
      $$7505$i = $$7505$ph$i;
      while(1) {
       $630 = ($$7505$i>>>0)>($$9$ph$i>>>0);
       if (!($630)) {
        $$lcssa683$i = 0;
        break;
       }
       $631 = ((($$7505$i)) + -4|0);
       $632 = HEAP32[$631>>2]|0;
       $633 = ($632|0)==(0);
       if ($633) {
        $$7505$i = $631;
       } else {
        $$lcssa683$i = 1;
        break;
       }
      }
      do {
       if ($573) {
        $634 = $574&1;
        $635 = $634 ^ 1;
        $$538$$i = (($635) + ($$538$i))|0;
        $636 = ($$538$$i|0)>($$5519$ph$i|0);
        $637 = ($$5519$ph$i|0)>(-5);
        $or$cond6$i = $636 & $637;
        if ($or$cond6$i) {
         $638 = (($$0235) + -1)|0;
         $$neg572$i = (($$538$$i) + -1)|0;
         $639 = (($$neg572$i) - ($$5519$ph$i))|0;
         $$0479$i = $638;$$2476$i = $639;
        } else {
         $640 = (($$0235) + -2)|0;
         $641 = (($$538$$i) + -1)|0;
         $$0479$i = $640;$$2476$i = $641;
        }
        $642 = $$1263$ & 8;
        $643 = ($642|0)==(0);
        if (!($643)) {
         $$1480$i = $$0479$i;$$3477$i = $$2476$i;$$pre$phi704$iZ2D = $642;
         break;
        }
        do {
         if ($$lcssa683$i) {
          $644 = ((($$7505$i)) + -4|0);
          $645 = HEAP32[$644>>2]|0;
          $646 = ($645|0)==(0);
          if ($646) {
           $$2530$i = 9;
           break;
          }
          $647 = (($645>>>0) % 10)&-1;
          $648 = ($647|0)==(0);
          if ($648) {
           $$1529624$i = 0;$$3534623$i = 10;
          } else {
           $$2530$i = 0;
           break;
          }
          while(1) {
           $649 = ($$3534623$i*10)|0;
           $650 = (($$1529624$i) + 1)|0;
           $651 = (($645>>>0) % ($649>>>0))&-1;
           $652 = ($651|0)==(0);
           if ($652) {
            $$1529624$i = $650;$$3534623$i = $649;
           } else {
            $$2530$i = $650;
            break;
           }
          }
         } else {
          $$2530$i = 9;
         }
        } while(0);
        $653 = $$0479$i | 32;
        $654 = ($653|0)==(102);
        $655 = $$7505$i;
        $656 = (($655) - ($560))|0;
        $657 = $656 >> 2;
        $658 = ($657*9)|0;
        $659 = (($658) + -9)|0;
        if ($654) {
         $660 = (($659) - ($$2530$i))|0;
         $661 = ($660|0)<(0);
         $$544$i = $661 ? 0 : $660;
         $662 = ($$2476$i|0)<($$544$i|0);
         $$2476$$545$i = $662 ? $$2476$i : $$544$i;
         $$1480$i = $$0479$i;$$3477$i = $$2476$$545$i;$$pre$phi704$iZ2D = 0;
         break;
        } else {
         $663 = (($659) + ($$5519$ph$i))|0;
         $664 = (($663) - ($$2530$i))|0;
         $665 = ($664|0)<(0);
         $$546$i = $665 ? 0 : $664;
         $666 = ($$2476$i|0)<($$546$i|0);
         $$2476$$547$i = $666 ? $$2476$i : $$546$i;
         $$1480$i = $$0479$i;$$3477$i = $$2476$$547$i;$$pre$phi704$iZ2D = 0;
         break;
        }
       } else {
        $$pre703$i = $$1263$ & 8;
        $$1480$i = $$0235;$$3477$i = $$538$i;$$pre$phi704$iZ2D = $$pre703$i;
       }
      } while(0);
      $667 = $$3477$i | $$pre$phi704$iZ2D;
      $668 = ($667|0)!=(0);
      $669 = $668&1;
      $670 = $$1480$i | 32;
      $671 = ($670|0)==(102);
      if ($671) {
       $672 = ($$5519$ph$i|0)>(0);
       $673 = $672 ? $$5519$ph$i : 0;
       $$2513$i = 0;$$pn$i = $673;
      } else {
       $674 = ($$5519$ph$i|0)<(0);
       $675 = $674 ? $629 : $$5519$ph$i;
       $676 = ($675|0)<(0);
       $677 = $676 << 31 >> 31;
       $678 = (_fmt_u($675,$677,$20)|0);
       $679 = $678;
       $680 = (($22) - ($679))|0;
       $681 = ($680|0)<(2);
       if ($681) {
        $$1512617$i = $678;
        while(1) {
         $682 = ((($$1512617$i)) + -1|0);
         HEAP8[$682>>0] = 48;
         $683 = $682;
         $684 = (($22) - ($683))|0;
         $685 = ($684|0)<(2);
         if ($685) {
          $$1512617$i = $682;
         } else {
          $$1512$lcssa$i = $682;
          break;
         }
        }
       } else {
        $$1512$lcssa$i = $678;
       }
       $686 = $$5519$ph$i >> 31;
       $687 = $686 & 2;
       $688 = (($687) + 43)|0;
       $689 = $688&255;
       $690 = ((($$1512$lcssa$i)) + -1|0);
       HEAP8[$690>>0] = $689;
       $691 = $$1480$i&255;
       $692 = ((($$1512$lcssa$i)) + -2|0);
       HEAP8[$692>>0] = $691;
       $693 = $692;
       $694 = (($22) - ($693))|0;
       $$2513$i = $692;$$pn$i = $694;
      }
      $695 = (($$0520$i) + 1)|0;
      $696 = (($695) + ($$3477$i))|0;
      $$1527$i = (($696) + ($669))|0;
      $697 = (($$1527$i) + ($$pn$i))|0;
      _pad($0,32,$$1260,$697,$$1263$);
      $698 = HEAP32[$0>>2]|0;
      $699 = $698 & 32;
      $700 = ($699|0)==(0);
      if ($700) {
       (___fwritex($$0522$i,$$0520$i,$0)|0);
      }
      $701 = $$1263$ ^ 65536;
      _pad($0,48,$$1260,$697,$701);
      do {
       if ($671) {
        $702 = ($$9$ph$i>>>0)>($$554$i>>>0);
        $$0496$$9$i = $702 ? $$554$i : $$9$ph$i;
        $$5493606$i = $$0496$$9$i;
        while(1) {
         $703 = HEAP32[$$5493606$i>>2]|0;
         $704 = (_fmt_u($703,0,$27)|0);
         $705 = ($$5493606$i|0)==($$0496$$9$i|0);
         do {
          if ($705) {
           $711 = ($704|0)==($27|0);
           if (!($711)) {
            $$1465$i = $704;
            break;
           }
           HEAP8[$29>>0] = 48;
           $$1465$i = $29;
          } else {
           $706 = ($704>>>0)>($7>>>0);
           if (!($706)) {
            $$1465$i = $704;
            break;
           }
           $707 = $704;
           $708 = (($707) - ($18))|0;
           _memset(($7|0),48,($708|0))|0;
           $$0464603$i = $704;
           while(1) {
            $709 = ((($$0464603$i)) + -1|0);
            $710 = ($709>>>0)>($7>>>0);
            if ($710) {
             $$0464603$i = $709;
            } else {
             $$1465$i = $709;
             break;
            }
           }
          }
         } while(0);
         $712 = HEAP32[$0>>2]|0;
         $713 = $712 & 32;
         $714 = ($713|0)==(0);
         if ($714) {
          $715 = $$1465$i;
          $716 = (($28) - ($715))|0;
          (___fwritex($$1465$i,$716,$0)|0);
         }
         $717 = ((($$5493606$i)) + 4|0);
         $718 = ($717>>>0)>($$554$i>>>0);
         if ($718) {
          break;
         } else {
          $$5493606$i = $717;
         }
        }
        $719 = ($667|0)==(0);
        do {
         if (!($719)) {
          $720 = HEAP32[$0>>2]|0;
          $721 = $720 & 32;
          $722 = ($721|0)==(0);
          if (!($722)) {
           break;
          }
          (___fwritex(956,1,$0)|0);
         }
        } while(0);
        $723 = ($717>>>0)<($$7505$i>>>0);
        $724 = ($$3477$i|0)>(0);
        $725 = $724 & $723;
        if ($725) {
         $$4478600$i = $$3477$i;$$6494599$i = $717;
         while(1) {
          $726 = HEAP32[$$6494599$i>>2]|0;
          $727 = (_fmt_u($726,0,$27)|0);
          $728 = ($727>>>0)>($7>>>0);
          if ($728) {
           $729 = $727;
           $730 = (($729) - ($18))|0;
           _memset(($7|0),48,($730|0))|0;
           $$0463594$i = $727;
           while(1) {
            $731 = ((($$0463594$i)) + -1|0);
            $732 = ($731>>>0)>($7>>>0);
            if ($732) {
             $$0463594$i = $731;
            } else {
             $$0463$lcssa$i = $731;
             break;
            }
           }
          } else {
           $$0463$lcssa$i = $727;
          }
          $733 = HEAP32[$0>>2]|0;
          $734 = $733 & 32;
          $735 = ($734|0)==(0);
          if ($735) {
           $736 = ($$4478600$i|0)>(9);
           $737 = $736 ? 9 : $$4478600$i;
           (___fwritex($$0463$lcssa$i,$737,$0)|0);
          }
          $738 = ((($$6494599$i)) + 4|0);
          $739 = (($$4478600$i) + -9)|0;
          $740 = ($738>>>0)<($$7505$i>>>0);
          $741 = ($$4478600$i|0)>(9);
          $742 = $741 & $740;
          if ($742) {
           $$4478600$i = $739;$$6494599$i = $738;
          } else {
           $$4478$lcssa$i = $739;
           break;
          }
         }
        } else {
         $$4478$lcssa$i = $$3477$i;
        }
        $743 = (($$4478$lcssa$i) + 9)|0;
        _pad($0,48,$743,9,0);
       } else {
        $744 = ((($$9$ph$i)) + 4|0);
        $$7505$$i = $$lcssa683$i ? $$7505$i : $744;
        $745 = ($$3477$i|0)>(-1);
        if ($745) {
         $746 = ($$pre$phi704$iZ2D|0)==(0);
         $$5611$i = $$3477$i;$$7495610$i = $$9$ph$i;
         while(1) {
          $747 = HEAP32[$$7495610$i>>2]|0;
          $748 = (_fmt_u($747,0,$27)|0);
          $749 = ($748|0)==($27|0);
          if ($749) {
           HEAP8[$29>>0] = 48;
           $$0$i = $29;
          } else {
           $$0$i = $748;
          }
          $750 = ($$7495610$i|0)==($$9$ph$i|0);
          do {
           if ($750) {
            $754 = ((($$0$i)) + 1|0);
            $755 = HEAP32[$0>>2]|0;
            $756 = $755 & 32;
            $757 = ($756|0)==(0);
            if ($757) {
             (___fwritex($$0$i,1,$0)|0);
            }
            $758 = ($$5611$i|0)<(1);
            $or$cond552$i = $746 & $758;
            if ($or$cond552$i) {
             $$2$i = $754;
             break;
            }
            $759 = HEAP32[$0>>2]|0;
            $760 = $759 & 32;
            $761 = ($760|0)==(0);
            if (!($761)) {
             $$2$i = $754;
             break;
            }
            (___fwritex(956,1,$0)|0);
            $$2$i = $754;
           } else {
            $751 = ($$0$i>>>0)>($7>>>0);
            if (!($751)) {
             $$2$i = $$0$i;
             break;
            }
            $scevgep694$i = (($$0$i) + ($19)|0);
            $scevgep694695$i = $scevgep694$i;
            _memset(($7|0),48,($scevgep694695$i|0))|0;
            $$1607$i = $$0$i;
            while(1) {
             $752 = ((($$1607$i)) + -1|0);
             $753 = ($752>>>0)>($7>>>0);
             if ($753) {
              $$1607$i = $752;
             } else {
              $$2$i = $752;
              break;
             }
            }
           }
          } while(0);
          $762 = $$2$i;
          $763 = (($28) - ($762))|0;
          $764 = HEAP32[$0>>2]|0;
          $765 = $764 & 32;
          $766 = ($765|0)==(0);
          if ($766) {
           $767 = ($$5611$i|0)>($763|0);
           $768 = $767 ? $763 : $$5611$i;
           (___fwritex($$2$i,$768,$0)|0);
          }
          $769 = (($$5611$i) - ($763))|0;
          $770 = ((($$7495610$i)) + 4|0);
          $771 = ($770>>>0)<($$7505$$i>>>0);
          $772 = ($769|0)>(-1);
          $773 = $771 & $772;
          if ($773) {
           $$5611$i = $769;$$7495610$i = $770;
          } else {
           $$5$lcssa$i = $769;
           break;
          }
         }
        } else {
         $$5$lcssa$i = $$3477$i;
        }
        $774 = (($$5$lcssa$i) + 18)|0;
        _pad($0,48,$774,18,0);
        $775 = HEAP32[$0>>2]|0;
        $776 = $775 & 32;
        $777 = ($776|0)==(0);
        if (!($777)) {
         break;
        }
        $778 = $$2513$i;
        $779 = (($22) - ($778))|0;
        (___fwritex($$2513$i,$779,$0)|0);
       }
      } while(0);
      $780 = $$1263$ ^ 8192;
      _pad($0,32,$$1260,$697,$780);
      $781 = ($697|0)<($$1260|0);
      $$553$i = $781 ? $$1260 : $697;
      $$0470$i = $$553$i;
     } else {
      $388 = $$0235 & 32;
      $389 = ($388|0)!=(0);
      $390 = $389 ? 940 : 944;
      $391 = ($$0471$i != $$0471$i) | (0.0 != 0.0);
      $392 = $389 ? 948 : 952;
      $$1521$i = $391 ? 0 : $$0520$i;
      $$0510$i = $391 ? $392 : $390;
      $393 = (($$1521$i) + 3)|0;
      _pad($0,32,$$1260,$393,$187);
      $394 = HEAP32[$0>>2]|0;
      $395 = $394 & 32;
      $396 = ($395|0)==(0);
      if ($396) {
       (___fwritex($$0522$i,$$1521$i,$0)|0);
       $$pre$i = HEAP32[$0>>2]|0;
       $398 = $$pre$i;
      } else {
       $398 = $394;
      }
      $397 = $398 & 32;
      $399 = ($397|0)==(0);
      if ($399) {
       (___fwritex($$0510$i,3,$0)|0);
      }
      $400 = $$1263$ ^ 8192;
      _pad($0,32,$$1260,$393,$400);
      $401 = ($393|0)<($$1260|0);
      $402 = $401 ? $$1260 : $393;
      $$0470$i = $402;
     }
    } while(0);
    $$0243 = $$0470$i;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
    continue L1;
    break;
   }
   default: {
    $$2 = $$0321;$$2234 = 0;$$2239 = 904;$$2251 = $14;$$5 = $$0254;$$6268 = $$1263$;
   }
   }
  } while(0);
  L310: do {
   if ((label|0) == 63) {
    label = 0;
    $218 = $9;
    $219 = $218;
    $220 = HEAP32[$219>>2]|0;
    $221 = (($218) + 4)|0;
    $222 = $221;
    $223 = HEAP32[$222>>2]|0;
    $224 = $$1236 & 32;
    $225 = ($220|0)==(0);
    $226 = ($223|0)==(0);
    $227 = $225 & $226;
    if ($227) {
     $$05$lcssa$i = $14;$248 = 0;$250 = 0;
    } else {
     $$056$i = $14;$229 = $220;$236 = $223;
     while(1) {
      $228 = $229 & 15;
      $230 = (888 + ($228)|0);
      $231 = HEAP8[$230>>0]|0;
      $232 = $231&255;
      $233 = $232 | $224;
      $234 = $233&255;
      $235 = ((($$056$i)) + -1|0);
      HEAP8[$235>>0] = $234;
      $237 = (_bitshift64Lshr(($229|0),($236|0),4)|0);
      $238 = tempRet0;
      $239 = ($237|0)==(0);
      $240 = ($238|0)==(0);
      $241 = $239 & $240;
      if ($241) {
       break;
      } else {
       $$056$i = $235;$229 = $237;$236 = $238;
      }
     }
     $242 = $9;
     $243 = $242;
     $244 = HEAP32[$243>>2]|0;
     $245 = (($242) + 4)|0;
     $246 = $245;
     $247 = HEAP32[$246>>2]|0;
     $$05$lcssa$i = $235;$248 = $244;$250 = $247;
    }
    $249 = ($248|0)==(0);
    $251 = ($250|0)==(0);
    $252 = $249 & $251;
    $253 = $$3265 & 8;
    $254 = ($253|0)==(0);
    $or$cond282 = $254 | $252;
    $255 = $$1236 >> 4;
    $256 = (904 + ($255)|0);
    $$332 = $or$cond282 ? 904 : $256;
    $$333 = $or$cond282 ? 0 : 2;
    $$0228 = $$05$lcssa$i;$$1233 = $$333;$$1238 = $$332;$$2256 = $$1255;$$4266 = $$3265;
    label = 76;
   }
   else if ((label|0) == 75) {
    label = 0;
    $302 = (_fmt_u($300,$301,$14)|0);
    $$0228 = $302;$$1233 = $$0232;$$1238 = $$0237;$$2256 = $$0254;$$4266 = $$1263$;
    label = 76;
   }
   else if ((label|0) == 81) {
    label = 0;
    $334 = (_memchr($$1,0,$$0254)|0);
    $335 = ($334|0)==(0|0);
    $336 = $334;
    $337 = $$1;
    $338 = (($336) - ($337))|0;
    $339 = (($$1) + ($$0254)|0);
    $$3257 = $335 ? $$0254 : $338;
    $$1250 = $335 ? $339 : $334;
    $$2 = $$1;$$2234 = 0;$$2239 = 904;$$2251 = $$1250;$$5 = $$3257;$$6268 = $187;
   }
   else if ((label|0) == 85) {
    label = 0;
    $$0229396 = $809;$$0240395 = 0;$$1244394 = 0;
    while(1) {
     $347 = HEAP32[$$0229396>>2]|0;
     $348 = ($347|0)==(0);
     if ($348) {
      $$0240$lcssa = $$0240395;$$2245 = $$1244394;
      break;
     }
     $349 = (_wctomb($12,$347)|0);
     $350 = ($349|0)<(0);
     $351 = (($$4258458) - ($$0240395))|0;
     $352 = ($349>>>0)>($351>>>0);
     $or$cond285 = $350 | $352;
     if ($or$cond285) {
      $$0240$lcssa = $$0240395;$$2245 = $349;
      break;
     }
     $353 = ((($$0229396)) + 4|0);
     $354 = (($349) + ($$0240395))|0;
     $355 = ($$4258458>>>0)>($354>>>0);
     if ($355) {
      $$0229396 = $353;$$0240395 = $354;$$1244394 = $349;
     } else {
      $$0240$lcssa = $354;$$2245 = $349;
      break;
     }
    }
    $356 = ($$2245|0)<(0);
    if ($356) {
     $$0 = -1;
     break L1;
    }
    _pad($0,32,$$1260,$$0240$lcssa,$$1263$);
    $357 = ($$0240$lcssa|0)==(0);
    if ($357) {
     $$0240$lcssa460 = 0;
     label = 96;
    } else {
     $$1230407 = $809;$$1241406 = 0;
     while(1) {
      $358 = HEAP32[$$1230407>>2]|0;
      $359 = ($358|0)==(0);
      if ($359) {
       $$0240$lcssa460 = $$0240$lcssa;
       label = 96;
       break L310;
      }
      $360 = ((($$1230407)) + 4|0);
      $361 = (_wctomb($12,$358)|0);
      $362 = (($361) + ($$1241406))|0;
      $363 = ($362|0)>($$0240$lcssa|0);
      if ($363) {
       $$0240$lcssa460 = $$0240$lcssa;
       label = 96;
       break L310;
      }
      $364 = HEAP32[$0>>2]|0;
      $365 = $364 & 32;
      $366 = ($365|0)==(0);
      if ($366) {
       (___fwritex($12,$361,$0)|0);
      }
      $367 = ($362>>>0)<($$0240$lcssa>>>0);
      if ($367) {
       $$1230407 = $360;$$1241406 = $362;
      } else {
       $$0240$lcssa460 = $$0240$lcssa;
       label = 96;
       break;
      }
     }
    }
   }
  } while(0);
  if ((label|0) == 96) {
   label = 0;
   $368 = $$1263$ ^ 8192;
   _pad($0,32,$$1260,$$0240$lcssa460,$368);
   $369 = ($$1260|0)>($$0240$lcssa460|0);
   $370 = $369 ? $$1260 : $$0240$lcssa460;
   $$0243 = $370;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
   continue;
  }
  if ((label|0) == 76) {
   label = 0;
   $303 = ($$2256|0)>(-1);
   $304 = $$4266 & -65537;
   $$$4266 = $303 ? $304 : $$4266;
   $305 = $9;
   $306 = $305;
   $307 = HEAP32[$306>>2]|0;
   $308 = (($305) + 4)|0;
   $309 = $308;
   $310 = HEAP32[$309>>2]|0;
   $311 = ($307|0)!=(0);
   $312 = ($310|0)!=(0);
   $313 = $311 | $312;
   $314 = ($$2256|0)!=(0);
   $or$cond = $314 | $313;
   if ($or$cond) {
    $315 = $$0228;
    $316 = (($15) - ($315))|0;
    $317 = $313&1;
    $318 = $317 ^ 1;
    $319 = (($318) + ($316))|0;
    $320 = ($$2256|0)>($319|0);
    $$2256$ = $320 ? $$2256 : $319;
    $$2 = $$0228;$$2234 = $$1233;$$2239 = $$1238;$$2251 = $14;$$5 = $$2256$;$$6268 = $$$4266;
   } else {
    $$2 = $14;$$2234 = $$1233;$$2239 = $$1238;$$2251 = $14;$$5 = 0;$$6268 = $$$4266;
   }
  }
  $782 = $$2251;
  $783 = $$2;
  $784 = (($782) - ($783))|0;
  $785 = ($$5|0)<($784|0);
  $$$5 = $785 ? $784 : $$5;
  $786 = (($$$5) + ($$2234))|0;
  $787 = ($$1260|0)<($786|0);
  $$2261 = $787 ? $786 : $$1260;
  _pad($0,32,$$2261,$786,$$6268);
  $788 = HEAP32[$0>>2]|0;
  $789 = $788 & 32;
  $790 = ($789|0)==(0);
  if ($790) {
   (___fwritex($$2239,$$2234,$0)|0);
  }
  $791 = $$6268 ^ 65536;
  _pad($0,48,$$2261,$786,$791);
  _pad($0,48,$$$5,$784,0);
  $792 = HEAP32[$0>>2]|0;
  $793 = $792 & 32;
  $794 = ($793|0)==(0);
  if ($794) {
   (___fwritex($$2,$784,$0)|0);
  }
  $795 = $$6268 ^ 8192;
  _pad($0,32,$$2261,$786,$795);
  $$0243 = $$2261;$$0247 = $$1248;$$0269 = $$3272;$$0321 = $158;
 }
 L345: do {
  if ((label|0) == 243) {
   $796 = ($0|0)==(0|0);
   if ($796) {
    $797 = ($$0269|0)==(0);
    if ($797) {
     $$0 = 0;
    } else {
     $$2242381 = 1;
     while(1) {
      $798 = (($4) + ($$2242381<<2)|0);
      $799 = HEAP32[$798>>2]|0;
      $800 = ($799|0)==(0);
      if ($800) {
       $$3379 = $$2242381;
       break;
      }
      $801 = (($3) + ($$2242381<<3)|0);
      _pop_arg($801,$799,$2);
      $802 = (($$2242381) + 1)|0;
      $803 = ($802|0)<(10);
      if ($803) {
       $$2242381 = $802;
      } else {
       $$0 = 1;
       break L345;
      }
     }
     while(1) {
      $806 = (($4) + ($$3379<<2)|0);
      $807 = HEAP32[$806>>2]|0;
      $808 = ($807|0)==(0);
      $804 = (($$3379) + 1)|0;
      if (!($808)) {
       $$0 = -1;
       break L345;
      }
      $805 = ($804|0)<(10);
      if ($805) {
       $$3379 = $804;
      } else {
       $$0 = 1;
       break;
      }
     }
    }
   } else {
    $$0 = $$1248;
   }
  }
 } while(0);
 STACKTOP = sp;return ($$0|0);
}
function ___lockfile($0) {
 $0 = $0|0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 return 0;
}
function ___fwritex($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $$0 = 0, $$032 = 0, $$033 = 0, $$034 = 0, $$1 = 0, $$pre = 0, $$pre38 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0;
 var $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 $3 = ((($2)) + 16|0);
 $4 = HEAP32[$3>>2]|0;
 $5 = ($4|0)==(0|0);
 if ($5) {
  $7 = (___towrite($2)|0);
  $8 = ($7|0)==(0);
  if ($8) {
   $$pre = HEAP32[$3>>2]|0;
   $12 = $$pre;
   label = 5;
  } else {
   $$032 = 0;
  }
 } else {
  $6 = $4;
  $12 = $6;
  label = 5;
 }
 L5: do {
  if ((label|0) == 5) {
   $9 = ((($2)) + 20|0);
   $10 = HEAP32[$9>>2]|0;
   $11 = (($12) - ($10))|0;
   $13 = ($11>>>0)<($1>>>0);
   $14 = $10;
   if ($13) {
    $15 = ((($2)) + 36|0);
    $16 = HEAP32[$15>>2]|0;
    $17 = (FUNCTION_TABLE_iiii[$16 & 15]($2,$0,$1)|0);
    $$032 = $17;
    break;
   }
   $18 = ((($2)) + 75|0);
   $19 = HEAP8[$18>>0]|0;
   $20 = ($19<<24>>24)>(-1);
   L10: do {
    if ($20) {
     $$0 = $1;
     while(1) {
      $21 = ($$0|0)==(0);
      if ($21) {
       $$033 = $1;$$034 = $0;$$1 = 0;$32 = $14;
       break L10;
      }
      $22 = (($$0) + -1)|0;
      $23 = (($0) + ($22)|0);
      $24 = HEAP8[$23>>0]|0;
      $25 = ($24<<24>>24)==(10);
      if ($25) {
       break;
      } else {
       $$0 = $22;
      }
     }
     $26 = ((($2)) + 36|0);
     $27 = HEAP32[$26>>2]|0;
     $28 = (FUNCTION_TABLE_iiii[$27 & 15]($2,$0,$$0)|0);
     $29 = ($28>>>0)<($$0>>>0);
     if ($29) {
      $$032 = $$0;
      break L5;
     }
     $30 = (($0) + ($$0)|0);
     $31 = (($1) - ($$0))|0;
     $$pre38 = HEAP32[$9>>2]|0;
     $$033 = $31;$$034 = $30;$$1 = $$0;$32 = $$pre38;
    } else {
     $$033 = $1;$$034 = $0;$$1 = 0;$32 = $14;
    }
   } while(0);
   _memcpy(($32|0),($$034|0),($$033|0))|0;
   $33 = HEAP32[$9>>2]|0;
   $34 = (($33) + ($$033)|0);
   HEAP32[$9>>2] = $34;
   $35 = (($$1) + ($$033))|0;
   $$032 = $35;
  }
 } while(0);
 return ($$032|0);
}
function _pop_arg($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $$mask = 0, $$mask31 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0.0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0;
 var $116 = 0.0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0;
 var $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0;
 var $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0, $64 = 0, $65 = 0, $66 = 0;
 var $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $81 = 0, $82 = 0, $83 = 0, $84 = 0;
 var $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0, $99 = 0, $arglist_current = 0, $arglist_current11 = 0, $arglist_current14 = 0, $arglist_current17 = 0;
 var $arglist_current2 = 0, $arglist_current20 = 0, $arglist_current23 = 0, $arglist_current26 = 0, $arglist_current5 = 0, $arglist_current8 = 0, $arglist_next = 0, $arglist_next12 = 0, $arglist_next15 = 0, $arglist_next18 = 0, $arglist_next21 = 0, $arglist_next24 = 0, $arglist_next27 = 0, $arglist_next3 = 0, $arglist_next6 = 0, $arglist_next9 = 0, $expanded = 0, $expanded28 = 0, $expanded30 = 0, $expanded31 = 0;
 var $expanded32 = 0, $expanded34 = 0, $expanded35 = 0, $expanded37 = 0, $expanded38 = 0, $expanded39 = 0, $expanded41 = 0, $expanded42 = 0, $expanded44 = 0, $expanded45 = 0, $expanded46 = 0, $expanded48 = 0, $expanded49 = 0, $expanded51 = 0, $expanded52 = 0, $expanded53 = 0, $expanded55 = 0, $expanded56 = 0, $expanded58 = 0, $expanded59 = 0;
 var $expanded60 = 0, $expanded62 = 0, $expanded63 = 0, $expanded65 = 0, $expanded66 = 0, $expanded67 = 0, $expanded69 = 0, $expanded70 = 0, $expanded72 = 0, $expanded73 = 0, $expanded74 = 0, $expanded76 = 0, $expanded77 = 0, $expanded79 = 0, $expanded80 = 0, $expanded81 = 0, $expanded83 = 0, $expanded84 = 0, $expanded86 = 0, $expanded87 = 0;
 var $expanded88 = 0, $expanded90 = 0, $expanded91 = 0, $expanded93 = 0, $expanded94 = 0, $expanded95 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $3 = ($1>>>0)>(20);
 L1: do {
  if (!($3)) {
   do {
    switch ($1|0) {
    case 9:  {
     $arglist_current = HEAP32[$2>>2]|0;
     $4 = $arglist_current;
     $5 = ((0) + 4|0);
     $expanded28 = $5;
     $expanded = (($expanded28) - 1)|0;
     $6 = (($4) + ($expanded))|0;
     $7 = ((0) + 4|0);
     $expanded32 = $7;
     $expanded31 = (($expanded32) - 1)|0;
     $expanded30 = $expanded31 ^ -1;
     $8 = $6 & $expanded30;
     $9 = $8;
     $10 = HEAP32[$9>>2]|0;
     $arglist_next = ((($9)) + 4|0);
     HEAP32[$2>>2] = $arglist_next;
     HEAP32[$0>>2] = $10;
     break L1;
     break;
    }
    case 10:  {
     $arglist_current2 = HEAP32[$2>>2]|0;
     $11 = $arglist_current2;
     $12 = ((0) + 4|0);
     $expanded35 = $12;
     $expanded34 = (($expanded35) - 1)|0;
     $13 = (($11) + ($expanded34))|0;
     $14 = ((0) + 4|0);
     $expanded39 = $14;
     $expanded38 = (($expanded39) - 1)|0;
     $expanded37 = $expanded38 ^ -1;
     $15 = $13 & $expanded37;
     $16 = $15;
     $17 = HEAP32[$16>>2]|0;
     $arglist_next3 = ((($16)) + 4|0);
     HEAP32[$2>>2] = $arglist_next3;
     $18 = ($17|0)<(0);
     $19 = $18 << 31 >> 31;
     $20 = $0;
     $21 = $20;
     HEAP32[$21>>2] = $17;
     $22 = (($20) + 4)|0;
     $23 = $22;
     HEAP32[$23>>2] = $19;
     break L1;
     break;
    }
    case 11:  {
     $arglist_current5 = HEAP32[$2>>2]|0;
     $24 = $arglist_current5;
     $25 = ((0) + 4|0);
     $expanded42 = $25;
     $expanded41 = (($expanded42) - 1)|0;
     $26 = (($24) + ($expanded41))|0;
     $27 = ((0) + 4|0);
     $expanded46 = $27;
     $expanded45 = (($expanded46) - 1)|0;
     $expanded44 = $expanded45 ^ -1;
     $28 = $26 & $expanded44;
     $29 = $28;
     $30 = HEAP32[$29>>2]|0;
     $arglist_next6 = ((($29)) + 4|0);
     HEAP32[$2>>2] = $arglist_next6;
     $31 = $0;
     $32 = $31;
     HEAP32[$32>>2] = $30;
     $33 = (($31) + 4)|0;
     $34 = $33;
     HEAP32[$34>>2] = 0;
     break L1;
     break;
    }
    case 12:  {
     $arglist_current8 = HEAP32[$2>>2]|0;
     $35 = $arglist_current8;
     $36 = ((0) + 8|0);
     $expanded49 = $36;
     $expanded48 = (($expanded49) - 1)|0;
     $37 = (($35) + ($expanded48))|0;
     $38 = ((0) + 8|0);
     $expanded53 = $38;
     $expanded52 = (($expanded53) - 1)|0;
     $expanded51 = $expanded52 ^ -1;
     $39 = $37 & $expanded51;
     $40 = $39;
     $41 = $40;
     $42 = $41;
     $43 = HEAP32[$42>>2]|0;
     $44 = (($41) + 4)|0;
     $45 = $44;
     $46 = HEAP32[$45>>2]|0;
     $arglist_next9 = ((($40)) + 8|0);
     HEAP32[$2>>2] = $arglist_next9;
     $47 = $0;
     $48 = $47;
     HEAP32[$48>>2] = $43;
     $49 = (($47) + 4)|0;
     $50 = $49;
     HEAP32[$50>>2] = $46;
     break L1;
     break;
    }
    case 13:  {
     $arglist_current11 = HEAP32[$2>>2]|0;
     $51 = $arglist_current11;
     $52 = ((0) + 4|0);
     $expanded56 = $52;
     $expanded55 = (($expanded56) - 1)|0;
     $53 = (($51) + ($expanded55))|0;
     $54 = ((0) + 4|0);
     $expanded60 = $54;
     $expanded59 = (($expanded60) - 1)|0;
     $expanded58 = $expanded59 ^ -1;
     $55 = $53 & $expanded58;
     $56 = $55;
     $57 = HEAP32[$56>>2]|0;
     $arglist_next12 = ((($56)) + 4|0);
     HEAP32[$2>>2] = $arglist_next12;
     $58 = $57&65535;
     $59 = $58 << 16 >> 16;
     $60 = ($59|0)<(0);
     $61 = $60 << 31 >> 31;
     $62 = $0;
     $63 = $62;
     HEAP32[$63>>2] = $59;
     $64 = (($62) + 4)|0;
     $65 = $64;
     HEAP32[$65>>2] = $61;
     break L1;
     break;
    }
    case 14:  {
     $arglist_current14 = HEAP32[$2>>2]|0;
     $66 = $arglist_current14;
     $67 = ((0) + 4|0);
     $expanded63 = $67;
     $expanded62 = (($expanded63) - 1)|0;
     $68 = (($66) + ($expanded62))|0;
     $69 = ((0) + 4|0);
     $expanded67 = $69;
     $expanded66 = (($expanded67) - 1)|0;
     $expanded65 = $expanded66 ^ -1;
     $70 = $68 & $expanded65;
     $71 = $70;
     $72 = HEAP32[$71>>2]|0;
     $arglist_next15 = ((($71)) + 4|0);
     HEAP32[$2>>2] = $arglist_next15;
     $$mask31 = $72 & 65535;
     $73 = $0;
     $74 = $73;
     HEAP32[$74>>2] = $$mask31;
     $75 = (($73) + 4)|0;
     $76 = $75;
     HEAP32[$76>>2] = 0;
     break L1;
     break;
    }
    case 15:  {
     $arglist_current17 = HEAP32[$2>>2]|0;
     $77 = $arglist_current17;
     $78 = ((0) + 4|0);
     $expanded70 = $78;
     $expanded69 = (($expanded70) - 1)|0;
     $79 = (($77) + ($expanded69))|0;
     $80 = ((0) + 4|0);
     $expanded74 = $80;
     $expanded73 = (($expanded74) - 1)|0;
     $expanded72 = $expanded73 ^ -1;
     $81 = $79 & $expanded72;
     $82 = $81;
     $83 = HEAP32[$82>>2]|0;
     $arglist_next18 = ((($82)) + 4|0);
     HEAP32[$2>>2] = $arglist_next18;
     $84 = $83&255;
     $85 = $84 << 24 >> 24;
     $86 = ($85|0)<(0);
     $87 = $86 << 31 >> 31;
     $88 = $0;
     $89 = $88;
     HEAP32[$89>>2] = $85;
     $90 = (($88) + 4)|0;
     $91 = $90;
     HEAP32[$91>>2] = $87;
     break L1;
     break;
    }
    case 16:  {
     $arglist_current20 = HEAP32[$2>>2]|0;
     $92 = $arglist_current20;
     $93 = ((0) + 4|0);
     $expanded77 = $93;
     $expanded76 = (($expanded77) - 1)|0;
     $94 = (($92) + ($expanded76))|0;
     $95 = ((0) + 4|0);
     $expanded81 = $95;
     $expanded80 = (($expanded81) - 1)|0;
     $expanded79 = $expanded80 ^ -1;
     $96 = $94 & $expanded79;
     $97 = $96;
     $98 = HEAP32[$97>>2]|0;
     $arglist_next21 = ((($97)) + 4|0);
     HEAP32[$2>>2] = $arglist_next21;
     $$mask = $98 & 255;
     $99 = $0;
     $100 = $99;
     HEAP32[$100>>2] = $$mask;
     $101 = (($99) + 4)|0;
     $102 = $101;
     HEAP32[$102>>2] = 0;
     break L1;
     break;
    }
    case 17:  {
     $arglist_current23 = HEAP32[$2>>2]|0;
     $103 = $arglist_current23;
     $104 = ((0) + 8|0);
     $expanded84 = $104;
     $expanded83 = (($expanded84) - 1)|0;
     $105 = (($103) + ($expanded83))|0;
     $106 = ((0) + 8|0);
     $expanded88 = $106;
     $expanded87 = (($expanded88) - 1)|0;
     $expanded86 = $expanded87 ^ -1;
     $107 = $105 & $expanded86;
     $108 = $107;
     $109 = +HEAPF64[$108>>3];
     $arglist_next24 = ((($108)) + 8|0);
     HEAP32[$2>>2] = $arglist_next24;
     HEAPF64[$0>>3] = $109;
     break L1;
     break;
    }
    case 18:  {
     $arglist_current26 = HEAP32[$2>>2]|0;
     $110 = $arglist_current26;
     $111 = ((0) + 8|0);
     $expanded91 = $111;
     $expanded90 = (($expanded91) - 1)|0;
     $112 = (($110) + ($expanded90))|0;
     $113 = ((0) + 8|0);
     $expanded95 = $113;
     $expanded94 = (($expanded95) - 1)|0;
     $expanded93 = $expanded94 ^ -1;
     $114 = $112 & $expanded93;
     $115 = $114;
     $116 = +HEAPF64[$115>>3];
     $arglist_next27 = ((($115)) + 8|0);
     HEAP32[$2>>2] = $arglist_next27;
     HEAPF64[$0>>3] = $116;
     break L1;
     break;
    }
    default: {
     break L1;
    }
    }
   } while(0);
  }
 } while(0);
 return;
}
function _fmt_u($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $$010$lcssa$off0 = 0, $$012 = 0, $$09$lcssa = 0, $$0914 = 0, $$1$lcssa = 0, $$111 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0;
 var $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $3 = ($1>>>0)>(0);
 $4 = ($0>>>0)>(4294967295);
 $5 = ($1|0)==(0);
 $6 = $5 & $4;
 $7 = $3 | $6;
 if ($7) {
  $$0914 = $2;$8 = $0;$9 = $1;
  while(1) {
   $10 = (___uremdi3(($8|0),($9|0),10,0)|0);
   $11 = tempRet0;
   $12 = $10 | 48;
   $13 = $12&255;
   $14 = ((($$0914)) + -1|0);
   HEAP8[$14>>0] = $13;
   $15 = (___udivdi3(($8|0),($9|0),10,0)|0);
   $16 = tempRet0;
   $17 = ($9>>>0)>(9);
   $18 = ($8>>>0)>(4294967295);
   $19 = ($9|0)==(9);
   $20 = $19 & $18;
   $21 = $17 | $20;
   if ($21) {
    $$0914 = $14;$8 = $15;$9 = $16;
   } else {
    break;
   }
  }
  $$010$lcssa$off0 = $15;$$09$lcssa = $14;
 } else {
  $$010$lcssa$off0 = $0;$$09$lcssa = $2;
 }
 $22 = ($$010$lcssa$off0|0)==(0);
 if ($22) {
  $$1$lcssa = $$09$lcssa;
 } else {
  $$012 = $$010$lcssa$off0;$$111 = $$09$lcssa;
  while(1) {
   $23 = (($$012>>>0) % 10)&-1;
   $24 = $23 | 48;
   $25 = $24&255;
   $26 = ((($$111)) + -1|0);
   HEAP8[$26>>0] = $25;
   $27 = (($$012>>>0) / 10)&-1;
   $28 = ($$012>>>0)<(10);
   if ($28) {
    $$1$lcssa = $26;
    break;
   } else {
    $$012 = $27;$$111 = $26;
   }
  }
 }
 return ($$1$lcssa|0);
}
function _strerror($0) {
 $0 = $0|0;
 var $$011$lcssa = 0, $$01113 = 0, $$015 = 0, $$112 = 0, $$114 = 0, $1 = 0, $10 = 0, $11 = 0, $12 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $$015 = 0;
 while(1) {
  $2 = (958 + ($$015)|0);
  $3 = HEAP8[$2>>0]|0;
  $4 = $3&255;
  $5 = ($4|0)==($0|0);
  if ($5) {
   label = 2;
   break;
  }
  $6 = (($$015) + 1)|0;
  $7 = ($6|0)==(87);
  if ($7) {
   $$01113 = 1046;$$114 = 87;
   label = 5;
   break;
  } else {
   $$015 = $6;
  }
 }
 if ((label|0) == 2) {
  $1 = ($$015|0)==(0);
  if ($1) {
   $$011$lcssa = 1046;
  } else {
   $$01113 = 1046;$$114 = $$015;
   label = 5;
  }
 }
 if ((label|0) == 5) {
  while(1) {
   label = 0;
   $$112 = $$01113;
   while(1) {
    $8 = HEAP8[$$112>>0]|0;
    $9 = ($8<<24>>24)==(0);
    $10 = ((($$112)) + 1|0);
    if ($9) {
     break;
    } else {
     $$112 = $10;
    }
   }
   $11 = (($$114) + -1)|0;
   $12 = ($11|0)==(0);
   if ($12) {
    $$011$lcssa = $10;
    break;
   } else {
    $$01113 = $10;$$114 = $11;
    label = 5;
   }
  }
 }
 return ($$011$lcssa|0);
}
function _memchr($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $$0$lcssa = 0, $$035$lcssa = 0, $$035$lcssa65 = 0, $$03555 = 0, $$036$lcssa = 0, $$036$lcssa64 = 0, $$03654 = 0, $$046 = 0, $$137$lcssa = 0, $$13745 = 0, $$140 = 0, $$2 = 0, $$23839 = 0, $$3 = 0, $$lcssa = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0;
 var $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0;
 var $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, $or$cond53 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $3 = $1 & 255;
 $4 = $0;
 $5 = $4 & 3;
 $6 = ($5|0)!=(0);
 $7 = ($2|0)!=(0);
 $or$cond53 = $7 & $6;
 L1: do {
  if ($or$cond53) {
   $8 = $1&255;
   $$03555 = $0;$$03654 = $2;
   while(1) {
    $9 = HEAP8[$$03555>>0]|0;
    $10 = ($9<<24>>24)==($8<<24>>24);
    if ($10) {
     $$035$lcssa65 = $$03555;$$036$lcssa64 = $$03654;
     label = 6;
     break L1;
    }
    $11 = ((($$03555)) + 1|0);
    $12 = (($$03654) + -1)|0;
    $13 = $11;
    $14 = $13 & 3;
    $15 = ($14|0)!=(0);
    $16 = ($12|0)!=(0);
    $or$cond = $16 & $15;
    if ($or$cond) {
     $$03555 = $11;$$03654 = $12;
    } else {
     $$035$lcssa = $11;$$036$lcssa = $12;$$lcssa = $16;
     label = 5;
     break;
    }
   }
  } else {
   $$035$lcssa = $0;$$036$lcssa = $2;$$lcssa = $7;
   label = 5;
  }
 } while(0);
 if ((label|0) == 5) {
  if ($$lcssa) {
   $$035$lcssa65 = $$035$lcssa;$$036$lcssa64 = $$036$lcssa;
   label = 6;
  } else {
   $$2 = $$035$lcssa;$$3 = 0;
  }
 }
 L8: do {
  if ((label|0) == 6) {
   $17 = HEAP8[$$035$lcssa65>>0]|0;
   $18 = $1&255;
   $19 = ($17<<24>>24)==($18<<24>>24);
   if ($19) {
    $$2 = $$035$lcssa65;$$3 = $$036$lcssa64;
   } else {
    $20 = Math_imul($3, 16843009)|0;
    $21 = ($$036$lcssa64>>>0)>(3);
    L11: do {
     if ($21) {
      $$046 = $$035$lcssa65;$$13745 = $$036$lcssa64;
      while(1) {
       $22 = HEAP32[$$046>>2]|0;
       $23 = $22 ^ $20;
       $24 = (($23) + -16843009)|0;
       $25 = $23 & -2139062144;
       $26 = $25 ^ -2139062144;
       $27 = $26 & $24;
       $28 = ($27|0)==(0);
       if (!($28)) {
        break;
       }
       $29 = ((($$046)) + 4|0);
       $30 = (($$13745) + -4)|0;
       $31 = ($30>>>0)>(3);
       if ($31) {
        $$046 = $29;$$13745 = $30;
       } else {
        $$0$lcssa = $29;$$137$lcssa = $30;
        label = 11;
        break L11;
       }
      }
      $$140 = $$046;$$23839 = $$13745;
     } else {
      $$0$lcssa = $$035$lcssa65;$$137$lcssa = $$036$lcssa64;
      label = 11;
     }
    } while(0);
    if ((label|0) == 11) {
     $32 = ($$137$lcssa|0)==(0);
     if ($32) {
      $$2 = $$0$lcssa;$$3 = 0;
      break;
     } else {
      $$140 = $$0$lcssa;$$23839 = $$137$lcssa;
     }
    }
    while(1) {
     $33 = HEAP8[$$140>>0]|0;
     $34 = ($33<<24>>24)==($18<<24>>24);
     if ($34) {
      $$2 = $$140;$$3 = $$23839;
      break L8;
     }
     $35 = ((($$140)) + 1|0);
     $36 = (($$23839) + -1)|0;
     $37 = ($36|0)==(0);
     if ($37) {
      $$2 = $35;$$3 = 0;
      break;
     } else {
      $$140 = $35;$$23839 = $36;
     }
    }
   }
  }
 } while(0);
 $38 = ($$3|0)!=(0);
 $39 = $38 ? $$2 : 0;
 return ($39|0);
}
function _pad($0,$1,$2,$3,$4) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 $4 = $4|0;
 var $$0$lcssa16 = 0, $$012 = 0, $$pre = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $5 = 0, $6 = 0;
 var $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 256|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(256|0);
 $5 = sp;
 $6 = $4 & 73728;
 $7 = ($6|0)==(0);
 $8 = ($2|0)>($3|0);
 $or$cond = $8 & $7;
 do {
  if ($or$cond) {
   $9 = (($2) - ($3))|0;
   $10 = ($9>>>0)>(256);
   $11 = $10 ? 256 : $9;
   _memset(($5|0),($1|0),($11|0))|0;
   $12 = ($9>>>0)>(255);
   $13 = HEAP32[$0>>2]|0;
   $14 = $13 & 32;
   $15 = ($14|0)==(0);
   if ($12) {
    $16 = (($2) - ($3))|0;
    $$012 = $9;$23 = $13;$24 = $15;
    while(1) {
     if ($24) {
      (___fwritex($5,256,$0)|0);
      $$pre = HEAP32[$0>>2]|0;
      $20 = $$pre;
     } else {
      $20 = $23;
     }
     $17 = (($$012) + -256)|0;
     $18 = ($17>>>0)>(255);
     $19 = $20 & 32;
     $21 = ($19|0)==(0);
     if ($18) {
      $$012 = $17;$23 = $20;$24 = $21;
     } else {
      break;
     }
    }
    $22 = $16 & 255;
    if ($21) {
     $$0$lcssa16 = $22;
    } else {
     break;
    }
   } else {
    if ($15) {
     $$0$lcssa16 = $9;
    } else {
     break;
    }
   }
   (___fwritex($5,$$0$lcssa16,$0)|0);
  }
 } while(0);
 STACKTOP = sp;return;
}
function _wctomb($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $$0 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = ($0|0)==(0|0);
 if ($2) {
  $$0 = 0;
 } else {
  $3 = (_wcrtomb($0,$1,0)|0);
  $$0 = $3;
 }
 return ($$0|0);
}
function _frexpl($0,$1) {
 $0 = +$0;
 $1 = $1|0;
 var $2 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = (+_frexp($0,$1));
 return (+$2);
}
function _frexp($0,$1) {
 $0 = +$0;
 $1 = $1|0;
 var $$0 = 0.0, $$016 = 0.0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0.0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0.0, $9 = 0.0, $storemerge = 0, $trunc$clear = 0, label = 0;
 var sp = 0;
 sp = STACKTOP;
 HEAPF64[tempDoublePtr>>3] = $0;$2 = HEAP32[tempDoublePtr>>2]|0;
 $3 = HEAP32[tempDoublePtr+4>>2]|0;
 $4 = (_bitshift64Lshr(($2|0),($3|0),52)|0);
 $5 = tempRet0;
 $6 = $4&65535;
 $trunc$clear = $6 & 2047;
 switch ($trunc$clear<<16>>16) {
 case 0:  {
  $7 = $0 != 0.0;
  if ($7) {
   $8 = $0 * 1.8446744073709552E+19;
   $9 = (+_frexp($8,$1));
   $10 = HEAP32[$1>>2]|0;
   $11 = (($10) + -64)|0;
   $$016 = $9;$storemerge = $11;
  } else {
   $$016 = $0;$storemerge = 0;
  }
  HEAP32[$1>>2] = $storemerge;
  $$0 = $$016;
  break;
 }
 case 2047:  {
  $$0 = $0;
  break;
 }
 default: {
  $12 = $4 & 2047;
  $13 = (($12) + -1022)|0;
  HEAP32[$1>>2] = $13;
  $14 = $3 & -2146435073;
  $15 = $14 | 1071644672;
  HEAP32[tempDoublePtr>>2] = $2;HEAP32[tempDoublePtr+4>>2] = $15;$16 = +HEAPF64[tempDoublePtr>>3];
  $$0 = $16;
 }
 }
 return (+$$0);
}
function _wcrtomb($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $$0 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0;
 var $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0;
 var $47 = 0, $48 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $3 = ($0|0)==(0|0);
 do {
  if ($3) {
   $$0 = 1;
  } else {
   $4 = ($1>>>0)<(128);
   if ($4) {
    $5 = $1&255;
    HEAP8[$0>>0] = $5;
    $$0 = 1;
    break;
   }
   $6 = ($1>>>0)<(2048);
   if ($6) {
    $7 = $1 >>> 6;
    $8 = $7 | 192;
    $9 = $8&255;
    $10 = ((($0)) + 1|0);
    HEAP8[$0>>0] = $9;
    $11 = $1 & 63;
    $12 = $11 | 128;
    $13 = $12&255;
    HEAP8[$10>>0] = $13;
    $$0 = 2;
    break;
   }
   $14 = ($1>>>0)<(55296);
   $15 = $1 & -8192;
   $16 = ($15|0)==(57344);
   $or$cond = $14 | $16;
   if ($or$cond) {
    $17 = $1 >>> 12;
    $18 = $17 | 224;
    $19 = $18&255;
    $20 = ((($0)) + 1|0);
    HEAP8[$0>>0] = $19;
    $21 = $1 >>> 6;
    $22 = $21 & 63;
    $23 = $22 | 128;
    $24 = $23&255;
    $25 = ((($0)) + 2|0);
    HEAP8[$20>>0] = $24;
    $26 = $1 & 63;
    $27 = $26 | 128;
    $28 = $27&255;
    HEAP8[$25>>0] = $28;
    $$0 = 3;
    break;
   }
   $29 = (($1) + -65536)|0;
   $30 = ($29>>>0)<(1048576);
   if ($30) {
    $31 = $1 >>> 18;
    $32 = $31 | 240;
    $33 = $32&255;
    $34 = ((($0)) + 1|0);
    HEAP8[$0>>0] = $33;
    $35 = $1 >>> 12;
    $36 = $35 & 63;
    $37 = $36 | 128;
    $38 = $37&255;
    $39 = ((($0)) + 2|0);
    HEAP8[$34>>0] = $38;
    $40 = $1 >>> 6;
    $41 = $40 & 63;
    $42 = $41 | 128;
    $43 = $42&255;
    $44 = ((($0)) + 3|0);
    HEAP8[$39>>0] = $43;
    $45 = $1 & 63;
    $46 = $45 | 128;
    $47 = $46&255;
    HEAP8[$44>>0] = $47;
    $$0 = 4;
    break;
   } else {
    $48 = (___errno_location()|0);
    HEAP32[$48>>2] = 84;
    $$0 = -1;
    break;
   }
  }
 } while(0);
 return ($$0|0);
}
function ___towrite($0) {
 $0 = $0|0;
 var $$0 = 0, $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0;
 var $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = ((($0)) + 74|0);
 $2 = HEAP8[$1>>0]|0;
 $3 = $2 << 24 >> 24;
 $4 = (($3) + 255)|0;
 $5 = $4 | $3;
 $6 = $5&255;
 HEAP8[$1>>0] = $6;
 $7 = HEAP32[$0>>2]|0;
 $8 = $7 & 8;
 $9 = ($8|0)==(0);
 if ($9) {
  $11 = ((($0)) + 8|0);
  HEAP32[$11>>2] = 0;
  $12 = ((($0)) + 4|0);
  HEAP32[$12>>2] = 0;
  $13 = ((($0)) + 44|0);
  $14 = HEAP32[$13>>2]|0;
  $15 = ((($0)) + 28|0);
  HEAP32[$15>>2] = $14;
  $16 = ((($0)) + 20|0);
  HEAP32[$16>>2] = $14;
  $17 = $14;
  $18 = ((($0)) + 48|0);
  $19 = HEAP32[$18>>2]|0;
  $20 = (($17) + ($19)|0);
  $21 = ((($0)) + 16|0);
  HEAP32[$21>>2] = $20;
  $$0 = 0;
 } else {
  $10 = $7 | 32;
  HEAP32[$0>>2] = $10;
  $$0 = -1;
 }
 return ($$0|0);
}
function ___overflow($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $$0 = 0, $$pre = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $3 = 0, $4 = 0;
 var $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $2 = sp;
 $3 = $1&255;
 HEAP8[$2>>0] = $3;
 $4 = ((($0)) + 16|0);
 $5 = HEAP32[$4>>2]|0;
 $6 = ($5|0)==(0|0);
 if ($6) {
  $7 = (___towrite($0)|0);
  $8 = ($7|0)==(0);
  if ($8) {
   $$pre = HEAP32[$4>>2]|0;
   $12 = $$pre;
   label = 4;
  } else {
   $$0 = -1;
  }
 } else {
  $12 = $5;
  label = 4;
 }
 do {
  if ((label|0) == 4) {
   $9 = ((($0)) + 20|0);
   $10 = HEAP32[$9>>2]|0;
   $11 = ($10>>>0)<($12>>>0);
   if ($11) {
    $13 = $1 & 255;
    $14 = ((($0)) + 75|0);
    $15 = HEAP8[$14>>0]|0;
    $16 = $15 << 24 >> 24;
    $17 = ($13|0)==($16|0);
    if (!($17)) {
     $18 = ((($10)) + 1|0);
     HEAP32[$9>>2] = $18;
     HEAP8[$10>>0] = $3;
     $$0 = $13;
     break;
    }
   }
   $19 = ((($0)) + 36|0);
   $20 = HEAP32[$19>>2]|0;
   $21 = (FUNCTION_TABLE_iiii[$20 & 15]($0,$2,1)|0);
   $22 = ($21|0)==(1);
   if ($22) {
    $23 = HEAP8[$2>>0]|0;
    $24 = $23&255;
    $$0 = $24;
   } else {
    $$0 = -1;
   }
  }
 } while(0);
 STACKTOP = sp;return ($$0|0);
}
function _fflush($0) {
 $0 = $0|0;
 var $$0 = 0, $$023 = 0, $$02325 = 0, $$02327 = 0, $$024$lcssa = 0, $$02426 = 0, $$1 = 0, $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0;
 var $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $phitmp = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = ($0|0)==(0|0);
 do {
  if ($1) {
   $8 = HEAP32[54]|0;
   $9 = ($8|0)==(0|0);
   if ($9) {
    $28 = 0;
   } else {
    $10 = HEAP32[54]|0;
    $11 = (_fflush($10)|0);
    $28 = $11;
   }
   ___lock(((3708)|0));
   $$02325 = HEAP32[(3704)>>2]|0;
   $12 = ($$02325|0)==(0|0);
   if ($12) {
    $$024$lcssa = $28;
   } else {
    $$02327 = $$02325;$$02426 = $28;
    while(1) {
     $13 = ((($$02327)) + 76|0);
     $14 = HEAP32[$13>>2]|0;
     $15 = ($14|0)>(-1);
     if ($15) {
      $16 = (___lockfile($$02327)|0);
      $24 = $16;
     } else {
      $24 = 0;
     }
     $17 = ((($$02327)) + 20|0);
     $18 = HEAP32[$17>>2]|0;
     $19 = ((($$02327)) + 28|0);
     $20 = HEAP32[$19>>2]|0;
     $21 = ($18>>>0)>($20>>>0);
     if ($21) {
      $22 = (___fflush_unlocked($$02327)|0);
      $23 = $22 | $$02426;
      $$1 = $23;
     } else {
      $$1 = $$02426;
     }
     $25 = ($24|0)==(0);
     if (!($25)) {
      ___unlockfile($$02327);
     }
     $26 = ((($$02327)) + 56|0);
     $$023 = HEAP32[$26>>2]|0;
     $27 = ($$023|0)==(0|0);
     if ($27) {
      $$024$lcssa = $$1;
      break;
     } else {
      $$02327 = $$023;$$02426 = $$1;
     }
    }
   }
   ___unlock(((3708)|0));
   $$0 = $$024$lcssa;
  } else {
   $2 = ((($0)) + 76|0);
   $3 = HEAP32[$2>>2]|0;
   $4 = ($3|0)>(-1);
   if (!($4)) {
    $5 = (___fflush_unlocked($0)|0);
    $$0 = $5;
    break;
   }
   $6 = (___lockfile($0)|0);
   $phitmp = ($6|0)==(0);
   $7 = (___fflush_unlocked($0)|0);
   if ($phitmp) {
    $$0 = $7;
   } else {
    ___unlockfile($0);
    $$0 = $7;
   }
  }
 } while(0);
 return ($$0|0);
}
function ___fflush_unlocked($0) {
 $0 = $0|0;
 var $$0 = 0, $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0;
 var $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = ((($0)) + 20|0);
 $2 = HEAP32[$1>>2]|0;
 $3 = ((($0)) + 28|0);
 $4 = HEAP32[$3>>2]|0;
 $5 = ($2>>>0)>($4>>>0);
 if ($5) {
  $6 = ((($0)) + 36|0);
  $7 = HEAP32[$6>>2]|0;
  (FUNCTION_TABLE_iiii[$7 & 15]($0,0,0)|0);
  $8 = HEAP32[$1>>2]|0;
  $9 = ($8|0)==(0|0);
  if ($9) {
   $$0 = -1;
  } else {
   label = 3;
  }
 } else {
  label = 3;
 }
 if ((label|0) == 3) {
  $10 = ((($0)) + 4|0);
  $11 = HEAP32[$10>>2]|0;
  $12 = ((($0)) + 8|0);
  $13 = HEAP32[$12>>2]|0;
  $14 = ($11>>>0)<($13>>>0);
  if ($14) {
   $15 = ((($0)) + 40|0);
   $16 = HEAP32[$15>>2]|0;
   $17 = $11;
   $18 = $13;
   $19 = (($17) - ($18))|0;
   (FUNCTION_TABLE_iiii[$16 & 15]($0,$19,1)|0);
  }
  $20 = ((($0)) + 16|0);
  HEAP32[$20>>2] = 0;
  HEAP32[$3>>2] = 0;
  HEAP32[$1>>2] = 0;
  HEAP32[$12>>2] = 0;
  HEAP32[$10>>2] = 0;
  $$0 = 0;
 }
 return ($$0|0);
}
function _fputc($0,$1) {
 $0 = $0|0;
 $1 = $1|0;
 var $$0 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0;
 var $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = ((($1)) + 76|0);
 $3 = HEAP32[$2>>2]|0;
 $4 = ($3|0)<(0);
 if ($4) {
  label = 3;
 } else {
  $5 = (___lockfile($1)|0);
  $6 = ($5|0)==(0);
  if ($6) {
   label = 3;
  } else {
   $20 = ((($1)) + 75|0);
   $21 = HEAP8[$20>>0]|0;
   $22 = $21 << 24 >> 24;
   $23 = ($22|0)==($0|0);
   if ($23) {
    label = 10;
   } else {
    $24 = ((($1)) + 20|0);
    $25 = HEAP32[$24>>2]|0;
    $26 = ((($1)) + 16|0);
    $27 = HEAP32[$26>>2]|0;
    $28 = ($25>>>0)<($27>>>0);
    if ($28) {
     $29 = $0&255;
     $30 = ((($25)) + 1|0);
     HEAP32[$24>>2] = $30;
     HEAP8[$25>>0] = $29;
     $31 = $0 & 255;
     $33 = $31;
    } else {
     label = 10;
    }
   }
   if ((label|0) == 10) {
    $32 = (___overflow($1,$0)|0);
    $33 = $32;
   }
   ___unlockfile($1);
   $$0 = $33;
  }
 }
 do {
  if ((label|0) == 3) {
   $7 = ((($1)) + 75|0);
   $8 = HEAP8[$7>>0]|0;
   $9 = $8 << 24 >> 24;
   $10 = ($9|0)==($0|0);
   if (!($10)) {
    $11 = ((($1)) + 20|0);
    $12 = HEAP32[$11>>2]|0;
    $13 = ((($1)) + 16|0);
    $14 = HEAP32[$13>>2]|0;
    $15 = ($12>>>0)<($14>>>0);
    if ($15) {
     $16 = $0&255;
     $17 = ((($12)) + 1|0);
     HEAP32[$11>>2] = $17;
     HEAP8[$12>>0] = $16;
     $18 = $0 & 255;
     $$0 = $18;
     break;
    }
   }
   $19 = (___overflow($1,$0)|0);
   $$0 = $19;
  }
 } while(0);
 return ($$0|0);
}
function _malloc($0) {
 $0 = $0|0;
 var $$$0190$i = 0, $$$0191$i = 0, $$$4349$i = 0, $$$i = 0, $$0 = 0, $$0$i$i = 0, $$0$i$i$i = 0, $$0$i17$i = 0, $$0$i18$i = 0, $$01$i$i = 0, $$0187$i = 0, $$0189$i = 0, $$0190$i = 0, $$0191$i = 0, $$0197 = 0, $$0199 = 0, $$0206$i$i = 0, $$0207$i$i = 0, $$0211$i$i = 0, $$0212$i$i = 0;
 var $$024370$i = 0, $$0286$i$i = 0, $$0287$i$i = 0, $$0288$i$i = 0, $$0294$i$i = 0, $$0295$i$i = 0, $$0340$i = 0, $$0342$i = 0, $$0343$i = 0, $$0345$i = 0, $$0351$i = 0, $$0356$i = 0, $$0357$$i = 0, $$0357$i = 0, $$0359$i = 0, $$0360$i = 0, $$0366$i = 0, $$1194$i = 0, $$1196$i = 0, $$124469$i = 0;
 var $$1290$i$i = 0, $$1292$i$i = 0, $$1341$i = 0, $$1346$i = 0, $$1361$i = 0, $$1368$i = 0, $$1372$i = 0, $$2247$ph$i = 0, $$2253$ph$i = 0, $$2353$i = 0, $$3$i = 0, $$3$i$i = 0, $$3$i201 = 0, $$3348$i = 0, $$3370$i = 0, $$4$lcssa$i = 0, $$413$i = 0, $$4349$lcssa$i = 0, $$434912$i = 0, $$4355$$4$i = 0;
 var $$4355$ph$i = 0, $$435511$i = 0, $$5256$i = 0, $$723947$i = 0, $$748$i = 0, $$not$i = 0, $$pre = 0, $$pre$i = 0, $$pre$i$i = 0, $$pre$i19$i = 0, $$pre$i205 = 0, $$pre$i208 = 0, $$pre$phi$i$iZ2D = 0, $$pre$phi$i20$iZ2D = 0, $$pre$phi$i206Z2D = 0, $$pre$phi$iZ2D = 0, $$pre$phi10$i$iZ2D = 0, $$pre$phiZ2D = 0, $$pre9$i$i = 0, $1 = 0;
 var $10 = 0, $100 = 0, $1000 = 0, $1001 = 0, $1002 = 0, $1003 = 0, $1004 = 0, $1005 = 0, $1006 = 0, $1007 = 0, $1008 = 0, $1009 = 0, $101 = 0, $1010 = 0, $1011 = 0, $1012 = 0, $1013 = 0, $1014 = 0, $1015 = 0, $1016 = 0;
 var $1017 = 0, $1018 = 0, $1019 = 0, $102 = 0, $1020 = 0, $1021 = 0, $1022 = 0, $1023 = 0, $1024 = 0, $1025 = 0, $1026 = 0, $1027 = 0, $1028 = 0, $1029 = 0, $103 = 0, $1030 = 0, $1031 = 0, $1032 = 0, $1033 = 0, $1034 = 0;
 var $1035 = 0, $1036 = 0, $1037 = 0, $1038 = 0, $1039 = 0, $104 = 0, $1040 = 0, $1041 = 0, $1042 = 0, $1043 = 0, $1044 = 0, $1045 = 0, $1046 = 0, $1047 = 0, $1048 = 0, $1049 = 0, $105 = 0, $1050 = 0, $1051 = 0, $1052 = 0;
 var $1053 = 0, $1054 = 0, $1055 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0, $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0;
 var $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0, $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0, $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0;
 var $14 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $15 = 0, $150 = 0, $151 = 0, $152 = 0, $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0;
 var $158 = 0, $159 = 0, $16 = 0, $160 = 0, $161 = 0, $162 = 0, $163 = 0, $164 = 0, $165 = 0, $166 = 0, $167 = 0, $168 = 0, $169 = 0, $17 = 0, $170 = 0, $171 = 0, $172 = 0, $173 = 0, $174 = 0, $175 = 0;
 var $176 = 0, $177 = 0, $178 = 0, $179 = 0, $18 = 0, $180 = 0, $181 = 0, $182 = 0, $183 = 0, $184 = 0, $185 = 0, $186 = 0, $187 = 0, $188 = 0, $189 = 0, $19 = 0, $190 = 0, $191 = 0, $192 = 0, $193 = 0;
 var $194 = 0, $195 = 0, $196 = 0, $197 = 0, $198 = 0, $199 = 0, $2 = 0, $20 = 0, $200 = 0, $201 = 0, $202 = 0, $203 = 0, $204 = 0, $205 = 0, $206 = 0, $207 = 0, $208 = 0, $209 = 0, $21 = 0, $210 = 0;
 var $211 = 0, $212 = 0, $213 = 0, $214 = 0, $215 = 0, $216 = 0, $217 = 0, $218 = 0, $219 = 0, $22 = 0, $220 = 0, $221 = 0, $222 = 0, $223 = 0, $224 = 0, $225 = 0, $226 = 0, $227 = 0, $228 = 0, $229 = 0;
 var $23 = 0, $230 = 0, $231 = 0, $232 = 0, $233 = 0, $234 = 0, $235 = 0, $236 = 0, $237 = 0, $238 = 0, $239 = 0, $24 = 0, $240 = 0, $241 = 0, $242 = 0, $243 = 0, $244 = 0, $245 = 0, $246 = 0, $247 = 0;
 var $248 = 0, $249 = 0, $25 = 0, $250 = 0, $251 = 0, $252 = 0, $253 = 0, $254 = 0, $255 = 0, $256 = 0, $257 = 0, $258 = 0, $259 = 0, $26 = 0, $260 = 0, $261 = 0, $262 = 0, $263 = 0, $264 = 0, $265 = 0;
 var $266 = 0, $267 = 0, $268 = 0, $269 = 0, $27 = 0, $270 = 0, $271 = 0, $272 = 0, $273 = 0, $274 = 0, $275 = 0, $276 = 0, $277 = 0, $278 = 0, $279 = 0, $28 = 0, $280 = 0, $281 = 0, $282 = 0, $283 = 0;
 var $284 = 0, $285 = 0, $286 = 0, $287 = 0, $288 = 0, $289 = 0, $29 = 0, $290 = 0, $291 = 0, $292 = 0, $293 = 0, $294 = 0, $295 = 0, $296 = 0, $297 = 0, $298 = 0, $299 = 0, $3 = 0, $30 = 0, $300 = 0;
 var $301 = 0, $302 = 0, $303 = 0, $304 = 0, $305 = 0, $306 = 0, $307 = 0, $308 = 0, $309 = 0, $31 = 0, $310 = 0, $311 = 0, $312 = 0, $313 = 0, $314 = 0, $315 = 0, $316 = 0, $317 = 0, $318 = 0, $319 = 0;
 var $32 = 0, $320 = 0, $321 = 0, $322 = 0, $323 = 0, $324 = 0, $325 = 0, $326 = 0, $327 = 0, $328 = 0, $329 = 0, $33 = 0, $330 = 0, $331 = 0, $332 = 0, $333 = 0, $334 = 0, $335 = 0, $336 = 0, $337 = 0;
 var $338 = 0, $339 = 0, $34 = 0, $340 = 0, $341 = 0, $342 = 0, $343 = 0, $344 = 0, $345 = 0, $346 = 0, $347 = 0, $348 = 0, $349 = 0, $35 = 0, $350 = 0, $351 = 0, $352 = 0, $353 = 0, $354 = 0, $355 = 0;
 var $356 = 0, $357 = 0, $358 = 0, $359 = 0, $36 = 0, $360 = 0, $361 = 0, $362 = 0, $363 = 0, $364 = 0, $365 = 0, $366 = 0, $367 = 0, $368 = 0, $369 = 0, $37 = 0, $370 = 0, $371 = 0, $372 = 0, $373 = 0;
 var $374 = 0, $375 = 0, $376 = 0, $377 = 0, $378 = 0, $379 = 0, $38 = 0, $380 = 0, $381 = 0, $382 = 0, $383 = 0, $384 = 0, $385 = 0, $386 = 0, $387 = 0, $388 = 0, $389 = 0, $39 = 0, $390 = 0, $391 = 0;
 var $392 = 0, $393 = 0, $394 = 0, $395 = 0, $396 = 0, $397 = 0, $398 = 0, $399 = 0, $4 = 0, $40 = 0, $400 = 0, $401 = 0, $402 = 0, $403 = 0, $404 = 0, $405 = 0, $406 = 0, $407 = 0, $408 = 0, $409 = 0;
 var $41 = 0, $410 = 0, $411 = 0, $412 = 0, $413 = 0, $414 = 0, $415 = 0, $416 = 0, $417 = 0, $418 = 0, $419 = 0, $42 = 0, $420 = 0, $421 = 0, $422 = 0, $423 = 0, $424 = 0, $425 = 0, $426 = 0, $427 = 0;
 var $428 = 0, $429 = 0, $43 = 0, $430 = 0, $431 = 0, $432 = 0, $433 = 0, $434 = 0, $435 = 0, $436 = 0, $437 = 0, $438 = 0, $439 = 0, $44 = 0, $440 = 0, $441 = 0, $442 = 0, $443 = 0, $444 = 0, $445 = 0;
 var $446 = 0, $447 = 0, $448 = 0, $449 = 0, $45 = 0, $450 = 0, $451 = 0, $452 = 0, $453 = 0, $454 = 0, $455 = 0, $456 = 0, $457 = 0, $458 = 0, $459 = 0, $46 = 0, $460 = 0, $461 = 0, $462 = 0, $463 = 0;
 var $464 = 0, $465 = 0, $466 = 0, $467 = 0, $468 = 0, $469 = 0, $47 = 0, $470 = 0, $471 = 0, $472 = 0, $473 = 0, $474 = 0, $475 = 0, $476 = 0, $477 = 0, $478 = 0, $479 = 0, $48 = 0, $480 = 0, $481 = 0;
 var $482 = 0, $483 = 0, $484 = 0, $485 = 0, $486 = 0, $487 = 0, $488 = 0, $489 = 0, $49 = 0, $490 = 0, $491 = 0, $492 = 0, $493 = 0, $494 = 0, $495 = 0, $496 = 0, $497 = 0, $498 = 0, $499 = 0, $5 = 0;
 var $50 = 0, $500 = 0, $501 = 0, $502 = 0, $503 = 0, $504 = 0, $505 = 0, $506 = 0, $507 = 0, $508 = 0, $509 = 0, $51 = 0, $510 = 0, $511 = 0, $512 = 0, $513 = 0, $514 = 0, $515 = 0, $516 = 0, $517 = 0;
 var $518 = 0, $519 = 0, $52 = 0, $520 = 0, $521 = 0, $522 = 0, $523 = 0, $524 = 0, $525 = 0, $526 = 0, $527 = 0, $528 = 0, $529 = 0, $53 = 0, $530 = 0, $531 = 0, $532 = 0, $533 = 0, $534 = 0, $535 = 0;
 var $536 = 0, $537 = 0, $538 = 0, $539 = 0, $54 = 0, $540 = 0, $541 = 0, $542 = 0, $543 = 0, $544 = 0, $545 = 0, $546 = 0, $547 = 0, $548 = 0, $549 = 0, $55 = 0, $550 = 0, $551 = 0, $552 = 0, $553 = 0;
 var $554 = 0, $555 = 0, $556 = 0, $557 = 0, $558 = 0, $559 = 0, $56 = 0, $560 = 0, $561 = 0, $562 = 0, $563 = 0, $564 = 0, $565 = 0, $566 = 0, $567 = 0, $568 = 0, $569 = 0, $57 = 0, $570 = 0, $571 = 0;
 var $572 = 0, $573 = 0, $574 = 0, $575 = 0, $576 = 0, $577 = 0, $578 = 0, $579 = 0, $58 = 0, $580 = 0, $581 = 0, $582 = 0, $583 = 0, $584 = 0, $585 = 0, $586 = 0, $587 = 0, $588 = 0, $589 = 0, $59 = 0;
 var $590 = 0, $591 = 0, $592 = 0, $593 = 0, $594 = 0, $595 = 0, $596 = 0, $597 = 0, $598 = 0, $599 = 0, $6 = 0, $60 = 0, $600 = 0, $601 = 0, $602 = 0, $603 = 0, $604 = 0, $605 = 0, $606 = 0, $607 = 0;
 var $608 = 0, $609 = 0, $61 = 0, $610 = 0, $611 = 0, $612 = 0, $613 = 0, $614 = 0, $615 = 0, $616 = 0, $617 = 0, $618 = 0, $619 = 0, $62 = 0, $620 = 0, $621 = 0, $622 = 0, $623 = 0, $624 = 0, $625 = 0;
 var $626 = 0, $627 = 0, $628 = 0, $629 = 0, $63 = 0, $630 = 0, $631 = 0, $632 = 0, $633 = 0, $634 = 0, $635 = 0, $636 = 0, $637 = 0, $638 = 0, $639 = 0, $64 = 0, $640 = 0, $641 = 0, $642 = 0, $643 = 0;
 var $644 = 0, $645 = 0, $646 = 0, $647 = 0, $648 = 0, $649 = 0, $65 = 0, $650 = 0, $651 = 0, $652 = 0, $653 = 0, $654 = 0, $655 = 0, $656 = 0, $657 = 0, $658 = 0, $659 = 0, $66 = 0, $660 = 0, $661 = 0;
 var $662 = 0, $663 = 0, $664 = 0, $665 = 0, $666 = 0, $667 = 0, $668 = 0, $669 = 0, $67 = 0, $670 = 0, $671 = 0, $672 = 0, $673 = 0, $674 = 0, $675 = 0, $676 = 0, $677 = 0, $678 = 0, $679 = 0, $68 = 0;
 var $680 = 0, $681 = 0, $682 = 0, $683 = 0, $684 = 0, $685 = 0, $686 = 0, $687 = 0, $688 = 0, $689 = 0, $69 = 0, $690 = 0, $691 = 0, $692 = 0, $693 = 0, $694 = 0, $695 = 0, $696 = 0, $697 = 0, $698 = 0;
 var $699 = 0, $7 = 0, $70 = 0, $700 = 0, $701 = 0, $702 = 0, $703 = 0, $704 = 0, $705 = 0, $706 = 0, $707 = 0, $708 = 0, $709 = 0, $71 = 0, $710 = 0, $711 = 0, $712 = 0, $713 = 0, $714 = 0, $715 = 0;
 var $716 = 0, $717 = 0, $718 = 0, $719 = 0, $72 = 0, $720 = 0, $721 = 0, $722 = 0, $723 = 0, $724 = 0, $725 = 0, $726 = 0, $727 = 0, $728 = 0, $729 = 0, $73 = 0, $730 = 0, $731 = 0, $732 = 0, $733 = 0;
 var $734 = 0, $735 = 0, $736 = 0, $737 = 0, $738 = 0, $739 = 0, $74 = 0, $740 = 0, $741 = 0, $742 = 0, $743 = 0, $744 = 0, $745 = 0, $746 = 0, $747 = 0, $748 = 0, $749 = 0, $75 = 0, $750 = 0, $751 = 0;
 var $752 = 0, $753 = 0, $754 = 0, $755 = 0, $756 = 0, $757 = 0, $758 = 0, $759 = 0, $76 = 0, $760 = 0, $761 = 0, $762 = 0, $763 = 0, $764 = 0, $765 = 0, $766 = 0, $767 = 0, $768 = 0, $769 = 0, $77 = 0;
 var $770 = 0, $771 = 0, $772 = 0, $773 = 0, $774 = 0, $775 = 0, $776 = 0, $777 = 0, $778 = 0, $779 = 0, $78 = 0, $780 = 0, $781 = 0, $782 = 0, $783 = 0, $784 = 0, $785 = 0, $786 = 0, $787 = 0, $788 = 0;
 var $789 = 0, $79 = 0, $790 = 0, $791 = 0, $792 = 0, $793 = 0, $794 = 0, $795 = 0, $796 = 0, $797 = 0, $798 = 0, $799 = 0, $8 = 0, $80 = 0, $800 = 0, $801 = 0, $802 = 0, $803 = 0, $804 = 0, $805 = 0;
 var $806 = 0, $807 = 0, $808 = 0, $809 = 0, $81 = 0, $810 = 0, $811 = 0, $812 = 0, $813 = 0, $814 = 0, $815 = 0, $816 = 0, $817 = 0, $818 = 0, $819 = 0, $82 = 0, $820 = 0, $821 = 0, $822 = 0, $823 = 0;
 var $824 = 0, $825 = 0, $826 = 0, $827 = 0, $828 = 0, $829 = 0, $83 = 0, $830 = 0, $831 = 0, $832 = 0, $833 = 0, $834 = 0, $835 = 0, $836 = 0, $837 = 0, $838 = 0, $839 = 0, $84 = 0, $840 = 0, $841 = 0;
 var $842 = 0, $843 = 0, $844 = 0, $845 = 0, $846 = 0, $847 = 0, $848 = 0, $849 = 0, $85 = 0, $850 = 0, $851 = 0, $852 = 0, $853 = 0, $854 = 0, $855 = 0, $856 = 0, $857 = 0, $858 = 0, $859 = 0, $86 = 0;
 var $860 = 0, $861 = 0, $862 = 0, $863 = 0, $864 = 0, $865 = 0, $866 = 0, $867 = 0, $868 = 0, $869 = 0, $87 = 0, $870 = 0, $871 = 0, $872 = 0, $873 = 0, $874 = 0, $875 = 0, $876 = 0, $877 = 0, $878 = 0;
 var $879 = 0, $88 = 0, $880 = 0, $881 = 0, $882 = 0, $883 = 0, $884 = 0, $885 = 0, $886 = 0, $887 = 0, $888 = 0, $889 = 0, $89 = 0, $890 = 0, $891 = 0, $892 = 0, $893 = 0, $894 = 0, $895 = 0, $896 = 0;
 var $897 = 0, $898 = 0, $899 = 0, $9 = 0, $90 = 0, $900 = 0, $901 = 0, $902 = 0, $903 = 0, $904 = 0, $905 = 0, $906 = 0, $907 = 0, $908 = 0, $909 = 0, $91 = 0, $910 = 0, $911 = 0, $912 = 0, $913 = 0;
 var $914 = 0, $915 = 0, $916 = 0, $917 = 0, $918 = 0, $919 = 0, $92 = 0, $920 = 0, $921 = 0, $922 = 0, $923 = 0, $924 = 0, $925 = 0, $926 = 0, $927 = 0, $928 = 0, $929 = 0, $93 = 0, $930 = 0, $931 = 0;
 var $932 = 0, $933 = 0, $934 = 0, $935 = 0, $936 = 0, $937 = 0, $938 = 0, $939 = 0, $94 = 0, $940 = 0, $941 = 0, $942 = 0, $943 = 0, $944 = 0, $945 = 0, $946 = 0, $947 = 0, $948 = 0, $949 = 0, $95 = 0;
 var $950 = 0, $951 = 0, $952 = 0, $953 = 0, $954 = 0, $955 = 0, $956 = 0, $957 = 0, $958 = 0, $959 = 0, $96 = 0, $960 = 0, $961 = 0, $962 = 0, $963 = 0, $964 = 0, $965 = 0, $966 = 0, $967 = 0, $968 = 0;
 var $969 = 0, $97 = 0, $970 = 0, $971 = 0, $972 = 0, $973 = 0, $974 = 0, $975 = 0, $976 = 0, $977 = 0, $978 = 0, $979 = 0, $98 = 0, $980 = 0, $981 = 0, $982 = 0, $983 = 0, $984 = 0, $985 = 0, $986 = 0;
 var $987 = 0, $988 = 0, $989 = 0, $99 = 0, $990 = 0, $991 = 0, $992 = 0, $993 = 0, $994 = 0, $995 = 0, $996 = 0, $997 = 0, $998 = 0, $999 = 0, $cond$i = 0, $cond$i$i = 0, $cond$i204 = 0, $exitcond$i$i = 0, $not$$i$i = 0, $not$$i22$i = 0;
 var $not$7$i = 0, $or$cond$i = 0, $or$cond$i211 = 0, $or$cond1$i = 0, $or$cond1$i210 = 0, $or$cond10$i = 0, $or$cond11$i = 0, $or$cond12$i = 0, $or$cond2$i = 0, $or$cond5$i = 0, $or$cond50$i = 0, $or$cond7$i = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = sp;
 $2 = ($0>>>0)<(245);
 do {
  if ($2) {
   $3 = ($0>>>0)<(11);
   $4 = (($0) + 11)|0;
   $5 = $4 & -8;
   $6 = $3 ? 16 : $5;
   $7 = $6 >>> 3;
   $8 = HEAP32[932]|0;
   $9 = $8 >>> $7;
   $10 = $9 & 3;
   $11 = ($10|0)==(0);
   if (!($11)) {
    $12 = $9 & 1;
    $13 = $12 ^ 1;
    $14 = (($13) + ($7))|0;
    $15 = $14 << 1;
    $16 = (3768 + ($15<<2)|0);
    $17 = ((($16)) + 8|0);
    $18 = HEAP32[$17>>2]|0;
    $19 = ((($18)) + 8|0);
    $20 = HEAP32[$19>>2]|0;
    $21 = ($16|0)==($20|0);
    do {
     if ($21) {
      $22 = 1 << $14;
      $23 = $22 ^ -1;
      $24 = $8 & $23;
      HEAP32[932] = $24;
     } else {
      $25 = HEAP32[(3744)>>2]|0;
      $26 = ($20>>>0)<($25>>>0);
      if ($26) {
       _abort();
       // unreachable;
      }
      $27 = ((($20)) + 12|0);
      $28 = HEAP32[$27>>2]|0;
      $29 = ($28|0)==($18|0);
      if ($29) {
       HEAP32[$27>>2] = $16;
       HEAP32[$17>>2] = $20;
       break;
      } else {
       _abort();
       // unreachable;
      }
     }
    } while(0);
    $30 = $14 << 3;
    $31 = $30 | 3;
    $32 = ((($18)) + 4|0);
    HEAP32[$32>>2] = $31;
    $33 = (($18) + ($30)|0);
    $34 = ((($33)) + 4|0);
    $35 = HEAP32[$34>>2]|0;
    $36 = $35 | 1;
    HEAP32[$34>>2] = $36;
    $$0 = $19;
    STACKTOP = sp;return ($$0|0);
   }
   $37 = HEAP32[(3736)>>2]|0;
   $38 = ($6>>>0)>($37>>>0);
   if ($38) {
    $39 = ($9|0)==(0);
    if (!($39)) {
     $40 = $9 << $7;
     $41 = 2 << $7;
     $42 = (0 - ($41))|0;
     $43 = $41 | $42;
     $44 = $40 & $43;
     $45 = (0 - ($44))|0;
     $46 = $44 & $45;
     $47 = (($46) + -1)|0;
     $48 = $47 >>> 12;
     $49 = $48 & 16;
     $50 = $47 >>> $49;
     $51 = $50 >>> 5;
     $52 = $51 & 8;
     $53 = $52 | $49;
     $54 = $50 >>> $52;
     $55 = $54 >>> 2;
     $56 = $55 & 4;
     $57 = $53 | $56;
     $58 = $54 >>> $56;
     $59 = $58 >>> 1;
     $60 = $59 & 2;
     $61 = $57 | $60;
     $62 = $58 >>> $60;
     $63 = $62 >>> 1;
     $64 = $63 & 1;
     $65 = $61 | $64;
     $66 = $62 >>> $64;
     $67 = (($65) + ($66))|0;
     $68 = $67 << 1;
     $69 = (3768 + ($68<<2)|0);
     $70 = ((($69)) + 8|0);
     $71 = HEAP32[$70>>2]|0;
     $72 = ((($71)) + 8|0);
     $73 = HEAP32[$72>>2]|0;
     $74 = ($69|0)==($73|0);
     do {
      if ($74) {
       $75 = 1 << $67;
       $76 = $75 ^ -1;
       $77 = $8 & $76;
       HEAP32[932] = $77;
       $98 = $77;
      } else {
       $78 = HEAP32[(3744)>>2]|0;
       $79 = ($73>>>0)<($78>>>0);
       if ($79) {
        _abort();
        // unreachable;
       }
       $80 = ((($73)) + 12|0);
       $81 = HEAP32[$80>>2]|0;
       $82 = ($81|0)==($71|0);
       if ($82) {
        HEAP32[$80>>2] = $69;
        HEAP32[$70>>2] = $73;
        $98 = $8;
        break;
       } else {
        _abort();
        // unreachable;
       }
      }
     } while(0);
     $83 = $67 << 3;
     $84 = (($83) - ($6))|0;
     $85 = $6 | 3;
     $86 = ((($71)) + 4|0);
     HEAP32[$86>>2] = $85;
     $87 = (($71) + ($6)|0);
     $88 = $84 | 1;
     $89 = ((($87)) + 4|0);
     HEAP32[$89>>2] = $88;
     $90 = (($87) + ($84)|0);
     HEAP32[$90>>2] = $84;
     $91 = ($37|0)==(0);
     if (!($91)) {
      $92 = HEAP32[(3748)>>2]|0;
      $93 = $37 >>> 3;
      $94 = $93 << 1;
      $95 = (3768 + ($94<<2)|0);
      $96 = 1 << $93;
      $97 = $98 & $96;
      $99 = ($97|0)==(0);
      if ($99) {
       $100 = $98 | $96;
       HEAP32[932] = $100;
       $$pre = ((($95)) + 8|0);
       $$0199 = $95;$$pre$phiZ2D = $$pre;
      } else {
       $101 = ((($95)) + 8|0);
       $102 = HEAP32[$101>>2]|0;
       $103 = HEAP32[(3744)>>2]|0;
       $104 = ($102>>>0)<($103>>>0);
       if ($104) {
        _abort();
        // unreachable;
       } else {
        $$0199 = $102;$$pre$phiZ2D = $101;
       }
      }
      HEAP32[$$pre$phiZ2D>>2] = $92;
      $105 = ((($$0199)) + 12|0);
      HEAP32[$105>>2] = $92;
      $106 = ((($92)) + 8|0);
      HEAP32[$106>>2] = $$0199;
      $107 = ((($92)) + 12|0);
      HEAP32[$107>>2] = $95;
     }
     HEAP32[(3736)>>2] = $84;
     HEAP32[(3748)>>2] = $87;
     $$0 = $72;
     STACKTOP = sp;return ($$0|0);
    }
    $108 = HEAP32[(3732)>>2]|0;
    $109 = ($108|0)==(0);
    if ($109) {
     $$0197 = $6;
    } else {
     $110 = (0 - ($108))|0;
     $111 = $108 & $110;
     $112 = (($111) + -1)|0;
     $113 = $112 >>> 12;
     $114 = $113 & 16;
     $115 = $112 >>> $114;
     $116 = $115 >>> 5;
     $117 = $116 & 8;
     $118 = $117 | $114;
     $119 = $115 >>> $117;
     $120 = $119 >>> 2;
     $121 = $120 & 4;
     $122 = $118 | $121;
     $123 = $119 >>> $121;
     $124 = $123 >>> 1;
     $125 = $124 & 2;
     $126 = $122 | $125;
     $127 = $123 >>> $125;
     $128 = $127 >>> 1;
     $129 = $128 & 1;
     $130 = $126 | $129;
     $131 = $127 >>> $129;
     $132 = (($130) + ($131))|0;
     $133 = (4032 + ($132<<2)|0);
     $134 = HEAP32[$133>>2]|0;
     $135 = ((($134)) + 4|0);
     $136 = HEAP32[$135>>2]|0;
     $137 = $136 & -8;
     $138 = (($137) - ($6))|0;
     $$0189$i = $134;$$0190$i = $134;$$0191$i = $138;
     while(1) {
      $139 = ((($$0189$i)) + 16|0);
      $140 = HEAP32[$139>>2]|0;
      $141 = ($140|0)==(0|0);
      if ($141) {
       $142 = ((($$0189$i)) + 20|0);
       $143 = HEAP32[$142>>2]|0;
       $144 = ($143|0)==(0|0);
       if ($144) {
        break;
       } else {
        $146 = $143;
       }
      } else {
       $146 = $140;
      }
      $145 = ((($146)) + 4|0);
      $147 = HEAP32[$145>>2]|0;
      $148 = $147 & -8;
      $149 = (($148) - ($6))|0;
      $150 = ($149>>>0)<($$0191$i>>>0);
      $$$0191$i = $150 ? $149 : $$0191$i;
      $$$0190$i = $150 ? $146 : $$0190$i;
      $$0189$i = $146;$$0190$i = $$$0190$i;$$0191$i = $$$0191$i;
     }
     $151 = HEAP32[(3744)>>2]|0;
     $152 = ($$0190$i>>>0)<($151>>>0);
     if ($152) {
      _abort();
      // unreachable;
     }
     $153 = (($$0190$i) + ($6)|0);
     $154 = ($$0190$i>>>0)<($153>>>0);
     if (!($154)) {
      _abort();
      // unreachable;
     }
     $155 = ((($$0190$i)) + 24|0);
     $156 = HEAP32[$155>>2]|0;
     $157 = ((($$0190$i)) + 12|0);
     $158 = HEAP32[$157>>2]|0;
     $159 = ($158|0)==($$0190$i|0);
     do {
      if ($159) {
       $169 = ((($$0190$i)) + 20|0);
       $170 = HEAP32[$169>>2]|0;
       $171 = ($170|0)==(0|0);
       if ($171) {
        $172 = ((($$0190$i)) + 16|0);
        $173 = HEAP32[$172>>2]|0;
        $174 = ($173|0)==(0|0);
        if ($174) {
         $$3$i = 0;
         break;
        } else {
         $$1194$i = $173;$$1196$i = $172;
        }
       } else {
        $$1194$i = $170;$$1196$i = $169;
       }
       while(1) {
        $175 = ((($$1194$i)) + 20|0);
        $176 = HEAP32[$175>>2]|0;
        $177 = ($176|0)==(0|0);
        if (!($177)) {
         $$1194$i = $176;$$1196$i = $175;
         continue;
        }
        $178 = ((($$1194$i)) + 16|0);
        $179 = HEAP32[$178>>2]|0;
        $180 = ($179|0)==(0|0);
        if ($180) {
         break;
        } else {
         $$1194$i = $179;$$1196$i = $178;
        }
       }
       $181 = ($$1196$i>>>0)<($151>>>0);
       if ($181) {
        _abort();
        // unreachable;
       } else {
        HEAP32[$$1196$i>>2] = 0;
        $$3$i = $$1194$i;
        break;
       }
      } else {
       $160 = ((($$0190$i)) + 8|0);
       $161 = HEAP32[$160>>2]|0;
       $162 = ($161>>>0)<($151>>>0);
       if ($162) {
        _abort();
        // unreachable;
       }
       $163 = ((($161)) + 12|0);
       $164 = HEAP32[$163>>2]|0;
       $165 = ($164|0)==($$0190$i|0);
       if (!($165)) {
        _abort();
        // unreachable;
       }
       $166 = ((($158)) + 8|0);
       $167 = HEAP32[$166>>2]|0;
       $168 = ($167|0)==($$0190$i|0);
       if ($168) {
        HEAP32[$163>>2] = $158;
        HEAP32[$166>>2] = $161;
        $$3$i = $158;
        break;
       } else {
        _abort();
        // unreachable;
       }
      }
     } while(0);
     $182 = ($156|0)==(0|0);
     do {
      if (!($182)) {
       $183 = ((($$0190$i)) + 28|0);
       $184 = HEAP32[$183>>2]|0;
       $185 = (4032 + ($184<<2)|0);
       $186 = HEAP32[$185>>2]|0;
       $187 = ($$0190$i|0)==($186|0);
       if ($187) {
        HEAP32[$185>>2] = $$3$i;
        $cond$i = ($$3$i|0)==(0|0);
        if ($cond$i) {
         $188 = 1 << $184;
         $189 = $188 ^ -1;
         $190 = $108 & $189;
         HEAP32[(3732)>>2] = $190;
         break;
        }
       } else {
        $191 = HEAP32[(3744)>>2]|0;
        $192 = ($156>>>0)<($191>>>0);
        if ($192) {
         _abort();
         // unreachable;
        }
        $193 = ((($156)) + 16|0);
        $194 = HEAP32[$193>>2]|0;
        $195 = ($194|0)==($$0190$i|0);
        if ($195) {
         HEAP32[$193>>2] = $$3$i;
        } else {
         $196 = ((($156)) + 20|0);
         HEAP32[$196>>2] = $$3$i;
        }
        $197 = ($$3$i|0)==(0|0);
        if ($197) {
         break;
        }
       }
       $198 = HEAP32[(3744)>>2]|0;
       $199 = ($$3$i>>>0)<($198>>>0);
       if ($199) {
        _abort();
        // unreachable;
       }
       $200 = ((($$3$i)) + 24|0);
       HEAP32[$200>>2] = $156;
       $201 = ((($$0190$i)) + 16|0);
       $202 = HEAP32[$201>>2]|0;
       $203 = ($202|0)==(0|0);
       do {
        if (!($203)) {
         $204 = ($202>>>0)<($198>>>0);
         if ($204) {
          _abort();
          // unreachable;
         } else {
          $205 = ((($$3$i)) + 16|0);
          HEAP32[$205>>2] = $202;
          $206 = ((($202)) + 24|0);
          HEAP32[$206>>2] = $$3$i;
          break;
         }
        }
       } while(0);
       $207 = ((($$0190$i)) + 20|0);
       $208 = HEAP32[$207>>2]|0;
       $209 = ($208|0)==(0|0);
       if (!($209)) {
        $210 = HEAP32[(3744)>>2]|0;
        $211 = ($208>>>0)<($210>>>0);
        if ($211) {
         _abort();
         // unreachable;
        } else {
         $212 = ((($$3$i)) + 20|0);
         HEAP32[$212>>2] = $208;
         $213 = ((($208)) + 24|0);
         HEAP32[$213>>2] = $$3$i;
         break;
        }
       }
      }
     } while(0);
     $214 = ($$0191$i>>>0)<(16);
     if ($214) {
      $215 = (($$0191$i) + ($6))|0;
      $216 = $215 | 3;
      $217 = ((($$0190$i)) + 4|0);
      HEAP32[$217>>2] = $216;
      $218 = (($$0190$i) + ($215)|0);
      $219 = ((($218)) + 4|0);
      $220 = HEAP32[$219>>2]|0;
      $221 = $220 | 1;
      HEAP32[$219>>2] = $221;
     } else {
      $222 = $6 | 3;
      $223 = ((($$0190$i)) + 4|0);
      HEAP32[$223>>2] = $222;
      $224 = $$0191$i | 1;
      $225 = ((($153)) + 4|0);
      HEAP32[$225>>2] = $224;
      $226 = (($153) + ($$0191$i)|0);
      HEAP32[$226>>2] = $$0191$i;
      $227 = ($37|0)==(0);
      if (!($227)) {
       $228 = HEAP32[(3748)>>2]|0;
       $229 = $37 >>> 3;
       $230 = $229 << 1;
       $231 = (3768 + ($230<<2)|0);
       $232 = 1 << $229;
       $233 = $8 & $232;
       $234 = ($233|0)==(0);
       if ($234) {
        $235 = $8 | $232;
        HEAP32[932] = $235;
        $$pre$i = ((($231)) + 8|0);
        $$0187$i = $231;$$pre$phi$iZ2D = $$pre$i;
       } else {
        $236 = ((($231)) + 8|0);
        $237 = HEAP32[$236>>2]|0;
        $238 = HEAP32[(3744)>>2]|0;
        $239 = ($237>>>0)<($238>>>0);
        if ($239) {
         _abort();
         // unreachable;
        } else {
         $$0187$i = $237;$$pre$phi$iZ2D = $236;
        }
       }
       HEAP32[$$pre$phi$iZ2D>>2] = $228;
       $240 = ((($$0187$i)) + 12|0);
       HEAP32[$240>>2] = $228;
       $241 = ((($228)) + 8|0);
       HEAP32[$241>>2] = $$0187$i;
       $242 = ((($228)) + 12|0);
       HEAP32[$242>>2] = $231;
      }
      HEAP32[(3736)>>2] = $$0191$i;
      HEAP32[(3748)>>2] = $153;
     }
     $243 = ((($$0190$i)) + 8|0);
     $$0 = $243;
     STACKTOP = sp;return ($$0|0);
    }
   } else {
    $$0197 = $6;
   }
  } else {
   $244 = ($0>>>0)>(4294967231);
   if ($244) {
    $$0197 = -1;
   } else {
    $245 = (($0) + 11)|0;
    $246 = $245 & -8;
    $247 = HEAP32[(3732)>>2]|0;
    $248 = ($247|0)==(0);
    if ($248) {
     $$0197 = $246;
    } else {
     $249 = (0 - ($246))|0;
     $250 = $245 >>> 8;
     $251 = ($250|0)==(0);
     if ($251) {
      $$0356$i = 0;
     } else {
      $252 = ($246>>>0)>(16777215);
      if ($252) {
       $$0356$i = 31;
      } else {
       $253 = (($250) + 1048320)|0;
       $254 = $253 >>> 16;
       $255 = $254 & 8;
       $256 = $250 << $255;
       $257 = (($256) + 520192)|0;
       $258 = $257 >>> 16;
       $259 = $258 & 4;
       $260 = $259 | $255;
       $261 = $256 << $259;
       $262 = (($261) + 245760)|0;
       $263 = $262 >>> 16;
       $264 = $263 & 2;
       $265 = $260 | $264;
       $266 = (14 - ($265))|0;
       $267 = $261 << $264;
       $268 = $267 >>> 15;
       $269 = (($266) + ($268))|0;
       $270 = $269 << 1;
       $271 = (($269) + 7)|0;
       $272 = $246 >>> $271;
       $273 = $272 & 1;
       $274 = $273 | $270;
       $$0356$i = $274;
      }
     }
     $275 = (4032 + ($$0356$i<<2)|0);
     $276 = HEAP32[$275>>2]|0;
     $277 = ($276|0)==(0|0);
     L123: do {
      if ($277) {
       $$2353$i = 0;$$3$i201 = 0;$$3348$i = $249;
       label = 86;
      } else {
       $278 = ($$0356$i|0)==(31);
       $279 = $$0356$i >>> 1;
       $280 = (25 - ($279))|0;
       $281 = $278 ? 0 : $280;
       $282 = $246 << $281;
       $$0340$i = 0;$$0345$i = $249;$$0351$i = $276;$$0357$i = $282;$$0360$i = 0;
       while(1) {
        $283 = ((($$0351$i)) + 4|0);
        $284 = HEAP32[$283>>2]|0;
        $285 = $284 & -8;
        $286 = (($285) - ($246))|0;
        $287 = ($286>>>0)<($$0345$i>>>0);
        if ($287) {
         $288 = ($286|0)==(0);
         if ($288) {
          $$413$i = $$0351$i;$$434912$i = 0;$$435511$i = $$0351$i;
          label = 90;
          break L123;
         } else {
          $$1341$i = $$0351$i;$$1346$i = $286;
         }
        } else {
         $$1341$i = $$0340$i;$$1346$i = $$0345$i;
        }
        $289 = ((($$0351$i)) + 20|0);
        $290 = HEAP32[$289>>2]|0;
        $291 = $$0357$i >>> 31;
        $292 = (((($$0351$i)) + 16|0) + ($291<<2)|0);
        $293 = HEAP32[$292>>2]|0;
        $294 = ($290|0)==(0|0);
        $295 = ($290|0)==($293|0);
        $or$cond1$i = $294 | $295;
        $$1361$i = $or$cond1$i ? $$0360$i : $290;
        $296 = ($293|0)==(0|0);
        $297 = $296&1;
        $298 = $297 ^ 1;
        $$0357$$i = $$0357$i << $298;
        if ($296) {
         $$2353$i = $$1361$i;$$3$i201 = $$1341$i;$$3348$i = $$1346$i;
         label = 86;
         break;
        } else {
         $$0340$i = $$1341$i;$$0345$i = $$1346$i;$$0351$i = $293;$$0357$i = $$0357$$i;$$0360$i = $$1361$i;
        }
       }
      }
     } while(0);
     if ((label|0) == 86) {
      $299 = ($$2353$i|0)==(0|0);
      $300 = ($$3$i201|0)==(0|0);
      $or$cond$i = $299 & $300;
      if ($or$cond$i) {
       $301 = 2 << $$0356$i;
       $302 = (0 - ($301))|0;
       $303 = $301 | $302;
       $304 = $247 & $303;
       $305 = ($304|0)==(0);
       if ($305) {
        $$0197 = $246;
        break;
       }
       $306 = (0 - ($304))|0;
       $307 = $304 & $306;
       $308 = (($307) + -1)|0;
       $309 = $308 >>> 12;
       $310 = $309 & 16;
       $311 = $308 >>> $310;
       $312 = $311 >>> 5;
       $313 = $312 & 8;
       $314 = $313 | $310;
       $315 = $311 >>> $313;
       $316 = $315 >>> 2;
       $317 = $316 & 4;
       $318 = $314 | $317;
       $319 = $315 >>> $317;
       $320 = $319 >>> 1;
       $321 = $320 & 2;
       $322 = $318 | $321;
       $323 = $319 >>> $321;
       $324 = $323 >>> 1;
       $325 = $324 & 1;
       $326 = $322 | $325;
       $327 = $323 >>> $325;
       $328 = (($326) + ($327))|0;
       $329 = (4032 + ($328<<2)|0);
       $330 = HEAP32[$329>>2]|0;
       $$4355$ph$i = $330;
      } else {
       $$4355$ph$i = $$2353$i;
      }
      $331 = ($$4355$ph$i|0)==(0|0);
      if ($331) {
       $$4$lcssa$i = $$3$i201;$$4349$lcssa$i = $$3348$i;
      } else {
       $$413$i = $$3$i201;$$434912$i = $$3348$i;$$435511$i = $$4355$ph$i;
       label = 90;
      }
     }
     if ((label|0) == 90) {
      while(1) {
       label = 0;
       $332 = ((($$435511$i)) + 4|0);
       $333 = HEAP32[$332>>2]|0;
       $334 = $333 & -8;
       $335 = (($334) - ($246))|0;
       $336 = ($335>>>0)<($$434912$i>>>0);
       $$$4349$i = $336 ? $335 : $$434912$i;
       $$4355$$4$i = $336 ? $$435511$i : $$413$i;
       $337 = ((($$435511$i)) + 16|0);
       $338 = HEAP32[$337>>2]|0;
       $339 = ($338|0)==(0|0);
       if (!($339)) {
        $$413$i = $$4355$$4$i;$$434912$i = $$$4349$i;$$435511$i = $338;
        label = 90;
        continue;
       }
       $340 = ((($$435511$i)) + 20|0);
       $341 = HEAP32[$340>>2]|0;
       $342 = ($341|0)==(0|0);
       if ($342) {
        $$4$lcssa$i = $$4355$$4$i;$$4349$lcssa$i = $$$4349$i;
        break;
       } else {
        $$413$i = $$4355$$4$i;$$434912$i = $$$4349$i;$$435511$i = $341;
        label = 90;
       }
      }
     }
     $343 = ($$4$lcssa$i|0)==(0|0);
     if ($343) {
      $$0197 = $246;
     } else {
      $344 = HEAP32[(3736)>>2]|0;
      $345 = (($344) - ($246))|0;
      $346 = ($$4349$lcssa$i>>>0)<($345>>>0);
      if ($346) {
       $347 = HEAP32[(3744)>>2]|0;
       $348 = ($$4$lcssa$i>>>0)<($347>>>0);
       if ($348) {
        _abort();
        // unreachable;
       }
       $349 = (($$4$lcssa$i) + ($246)|0);
       $350 = ($$4$lcssa$i>>>0)<($349>>>0);
       if (!($350)) {
        _abort();
        // unreachable;
       }
       $351 = ((($$4$lcssa$i)) + 24|0);
       $352 = HEAP32[$351>>2]|0;
       $353 = ((($$4$lcssa$i)) + 12|0);
       $354 = HEAP32[$353>>2]|0;
       $355 = ($354|0)==($$4$lcssa$i|0);
       do {
        if ($355) {
         $365 = ((($$4$lcssa$i)) + 20|0);
         $366 = HEAP32[$365>>2]|0;
         $367 = ($366|0)==(0|0);
         if ($367) {
          $368 = ((($$4$lcssa$i)) + 16|0);
          $369 = HEAP32[$368>>2]|0;
          $370 = ($369|0)==(0|0);
          if ($370) {
           $$3370$i = 0;
           break;
          } else {
           $$1368$i = $369;$$1372$i = $368;
          }
         } else {
          $$1368$i = $366;$$1372$i = $365;
         }
         while(1) {
          $371 = ((($$1368$i)) + 20|0);
          $372 = HEAP32[$371>>2]|0;
          $373 = ($372|0)==(0|0);
          if (!($373)) {
           $$1368$i = $372;$$1372$i = $371;
           continue;
          }
          $374 = ((($$1368$i)) + 16|0);
          $375 = HEAP32[$374>>2]|0;
          $376 = ($375|0)==(0|0);
          if ($376) {
           break;
          } else {
           $$1368$i = $375;$$1372$i = $374;
          }
         }
         $377 = ($$1372$i>>>0)<($347>>>0);
         if ($377) {
          _abort();
          // unreachable;
         } else {
          HEAP32[$$1372$i>>2] = 0;
          $$3370$i = $$1368$i;
          break;
         }
        } else {
         $356 = ((($$4$lcssa$i)) + 8|0);
         $357 = HEAP32[$356>>2]|0;
         $358 = ($357>>>0)<($347>>>0);
         if ($358) {
          _abort();
          // unreachable;
         }
         $359 = ((($357)) + 12|0);
         $360 = HEAP32[$359>>2]|0;
         $361 = ($360|0)==($$4$lcssa$i|0);
         if (!($361)) {
          _abort();
          // unreachable;
         }
         $362 = ((($354)) + 8|0);
         $363 = HEAP32[$362>>2]|0;
         $364 = ($363|0)==($$4$lcssa$i|0);
         if ($364) {
          HEAP32[$359>>2] = $354;
          HEAP32[$362>>2] = $357;
          $$3370$i = $354;
          break;
         } else {
          _abort();
          // unreachable;
         }
        }
       } while(0);
       $378 = ($352|0)==(0|0);
       do {
        if ($378) {
         $470 = $247;
        } else {
         $379 = ((($$4$lcssa$i)) + 28|0);
         $380 = HEAP32[$379>>2]|0;
         $381 = (4032 + ($380<<2)|0);
         $382 = HEAP32[$381>>2]|0;
         $383 = ($$4$lcssa$i|0)==($382|0);
         if ($383) {
          HEAP32[$381>>2] = $$3370$i;
          $cond$i204 = ($$3370$i|0)==(0|0);
          if ($cond$i204) {
           $384 = 1 << $380;
           $385 = $384 ^ -1;
           $386 = $247 & $385;
           HEAP32[(3732)>>2] = $386;
           $470 = $386;
           break;
          }
         } else {
          $387 = HEAP32[(3744)>>2]|0;
          $388 = ($352>>>0)<($387>>>0);
          if ($388) {
           _abort();
           // unreachable;
          }
          $389 = ((($352)) + 16|0);
          $390 = HEAP32[$389>>2]|0;
          $391 = ($390|0)==($$4$lcssa$i|0);
          if ($391) {
           HEAP32[$389>>2] = $$3370$i;
          } else {
           $392 = ((($352)) + 20|0);
           HEAP32[$392>>2] = $$3370$i;
          }
          $393 = ($$3370$i|0)==(0|0);
          if ($393) {
           $470 = $247;
           break;
          }
         }
         $394 = HEAP32[(3744)>>2]|0;
         $395 = ($$3370$i>>>0)<($394>>>0);
         if ($395) {
          _abort();
          // unreachable;
         }
         $396 = ((($$3370$i)) + 24|0);
         HEAP32[$396>>2] = $352;
         $397 = ((($$4$lcssa$i)) + 16|0);
         $398 = HEAP32[$397>>2]|0;
         $399 = ($398|0)==(0|0);
         do {
          if (!($399)) {
           $400 = ($398>>>0)<($394>>>0);
           if ($400) {
            _abort();
            // unreachable;
           } else {
            $401 = ((($$3370$i)) + 16|0);
            HEAP32[$401>>2] = $398;
            $402 = ((($398)) + 24|0);
            HEAP32[$402>>2] = $$3370$i;
            break;
           }
          }
         } while(0);
         $403 = ((($$4$lcssa$i)) + 20|0);
         $404 = HEAP32[$403>>2]|0;
         $405 = ($404|0)==(0|0);
         if ($405) {
          $470 = $247;
         } else {
          $406 = HEAP32[(3744)>>2]|0;
          $407 = ($404>>>0)<($406>>>0);
          if ($407) {
           _abort();
           // unreachable;
          } else {
           $408 = ((($$3370$i)) + 20|0);
           HEAP32[$408>>2] = $404;
           $409 = ((($404)) + 24|0);
           HEAP32[$409>>2] = $$3370$i;
           $470 = $247;
           break;
          }
         }
        }
       } while(0);
       $410 = ($$4349$lcssa$i>>>0)<(16);
       do {
        if ($410) {
         $411 = (($$4349$lcssa$i) + ($246))|0;
         $412 = $411 | 3;
         $413 = ((($$4$lcssa$i)) + 4|0);
         HEAP32[$413>>2] = $412;
         $414 = (($$4$lcssa$i) + ($411)|0);
         $415 = ((($414)) + 4|0);
         $416 = HEAP32[$415>>2]|0;
         $417 = $416 | 1;
         HEAP32[$415>>2] = $417;
        } else {
         $418 = $246 | 3;
         $419 = ((($$4$lcssa$i)) + 4|0);
         HEAP32[$419>>2] = $418;
         $420 = $$4349$lcssa$i | 1;
         $421 = ((($349)) + 4|0);
         HEAP32[$421>>2] = $420;
         $422 = (($349) + ($$4349$lcssa$i)|0);
         HEAP32[$422>>2] = $$4349$lcssa$i;
         $423 = $$4349$lcssa$i >>> 3;
         $424 = ($$4349$lcssa$i>>>0)<(256);
         if ($424) {
          $425 = $423 << 1;
          $426 = (3768 + ($425<<2)|0);
          $427 = HEAP32[932]|0;
          $428 = 1 << $423;
          $429 = $427 & $428;
          $430 = ($429|0)==(0);
          if ($430) {
           $431 = $427 | $428;
           HEAP32[932] = $431;
           $$pre$i205 = ((($426)) + 8|0);
           $$0366$i = $426;$$pre$phi$i206Z2D = $$pre$i205;
          } else {
           $432 = ((($426)) + 8|0);
           $433 = HEAP32[$432>>2]|0;
           $434 = HEAP32[(3744)>>2]|0;
           $435 = ($433>>>0)<($434>>>0);
           if ($435) {
            _abort();
            // unreachable;
           } else {
            $$0366$i = $433;$$pre$phi$i206Z2D = $432;
           }
          }
          HEAP32[$$pre$phi$i206Z2D>>2] = $349;
          $436 = ((($$0366$i)) + 12|0);
          HEAP32[$436>>2] = $349;
          $437 = ((($349)) + 8|0);
          HEAP32[$437>>2] = $$0366$i;
          $438 = ((($349)) + 12|0);
          HEAP32[$438>>2] = $426;
          break;
         }
         $439 = $$4349$lcssa$i >>> 8;
         $440 = ($439|0)==(0);
         if ($440) {
          $$0359$i = 0;
         } else {
          $441 = ($$4349$lcssa$i>>>0)>(16777215);
          if ($441) {
           $$0359$i = 31;
          } else {
           $442 = (($439) + 1048320)|0;
           $443 = $442 >>> 16;
           $444 = $443 & 8;
           $445 = $439 << $444;
           $446 = (($445) + 520192)|0;
           $447 = $446 >>> 16;
           $448 = $447 & 4;
           $449 = $448 | $444;
           $450 = $445 << $448;
           $451 = (($450) + 245760)|0;
           $452 = $451 >>> 16;
           $453 = $452 & 2;
           $454 = $449 | $453;
           $455 = (14 - ($454))|0;
           $456 = $450 << $453;
           $457 = $456 >>> 15;
           $458 = (($455) + ($457))|0;
           $459 = $458 << 1;
           $460 = (($458) + 7)|0;
           $461 = $$4349$lcssa$i >>> $460;
           $462 = $461 & 1;
           $463 = $462 | $459;
           $$0359$i = $463;
          }
         }
         $464 = (4032 + ($$0359$i<<2)|0);
         $465 = ((($349)) + 28|0);
         HEAP32[$465>>2] = $$0359$i;
         $466 = ((($349)) + 16|0);
         $467 = ((($466)) + 4|0);
         HEAP32[$467>>2] = 0;
         HEAP32[$466>>2] = 0;
         $468 = 1 << $$0359$i;
         $469 = $470 & $468;
         $471 = ($469|0)==(0);
         if ($471) {
          $472 = $470 | $468;
          HEAP32[(3732)>>2] = $472;
          HEAP32[$464>>2] = $349;
          $473 = ((($349)) + 24|0);
          HEAP32[$473>>2] = $464;
          $474 = ((($349)) + 12|0);
          HEAP32[$474>>2] = $349;
          $475 = ((($349)) + 8|0);
          HEAP32[$475>>2] = $349;
          break;
         }
         $476 = HEAP32[$464>>2]|0;
         $477 = ($$0359$i|0)==(31);
         $478 = $$0359$i >>> 1;
         $479 = (25 - ($478))|0;
         $480 = $477 ? 0 : $479;
         $481 = $$4349$lcssa$i << $480;
         $$0342$i = $481;$$0343$i = $476;
         while(1) {
          $482 = ((($$0343$i)) + 4|0);
          $483 = HEAP32[$482>>2]|0;
          $484 = $483 & -8;
          $485 = ($484|0)==($$4349$lcssa$i|0);
          if ($485) {
           label = 148;
           break;
          }
          $486 = $$0342$i >>> 31;
          $487 = (((($$0343$i)) + 16|0) + ($486<<2)|0);
          $488 = $$0342$i << 1;
          $489 = HEAP32[$487>>2]|0;
          $490 = ($489|0)==(0|0);
          if ($490) {
           label = 145;
           break;
          } else {
           $$0342$i = $488;$$0343$i = $489;
          }
         }
         if ((label|0) == 145) {
          $491 = HEAP32[(3744)>>2]|0;
          $492 = ($487>>>0)<($491>>>0);
          if ($492) {
           _abort();
           // unreachable;
          } else {
           HEAP32[$487>>2] = $349;
           $493 = ((($349)) + 24|0);
           HEAP32[$493>>2] = $$0343$i;
           $494 = ((($349)) + 12|0);
           HEAP32[$494>>2] = $349;
           $495 = ((($349)) + 8|0);
           HEAP32[$495>>2] = $349;
           break;
          }
         }
         else if ((label|0) == 148) {
          $496 = ((($$0343$i)) + 8|0);
          $497 = HEAP32[$496>>2]|0;
          $498 = HEAP32[(3744)>>2]|0;
          $499 = ($497>>>0)>=($498>>>0);
          $not$7$i = ($$0343$i>>>0)>=($498>>>0);
          $500 = $499 & $not$7$i;
          if ($500) {
           $501 = ((($497)) + 12|0);
           HEAP32[$501>>2] = $349;
           HEAP32[$496>>2] = $349;
           $502 = ((($349)) + 8|0);
           HEAP32[$502>>2] = $497;
           $503 = ((($349)) + 12|0);
           HEAP32[$503>>2] = $$0343$i;
           $504 = ((($349)) + 24|0);
           HEAP32[$504>>2] = 0;
           break;
          } else {
           _abort();
           // unreachable;
          }
         }
        }
       } while(0);
       $505 = ((($$4$lcssa$i)) + 8|0);
       $$0 = $505;
       STACKTOP = sp;return ($$0|0);
      } else {
       $$0197 = $246;
      }
     }
    }
   }
  }
 } while(0);
 $506 = HEAP32[(3736)>>2]|0;
 $507 = ($506>>>0)<($$0197>>>0);
 if (!($507)) {
  $508 = (($506) - ($$0197))|0;
  $509 = HEAP32[(3748)>>2]|0;
  $510 = ($508>>>0)>(15);
  if ($510) {
   $511 = (($509) + ($$0197)|0);
   HEAP32[(3748)>>2] = $511;
   HEAP32[(3736)>>2] = $508;
   $512 = $508 | 1;
   $513 = ((($511)) + 4|0);
   HEAP32[$513>>2] = $512;
   $514 = (($511) + ($508)|0);
   HEAP32[$514>>2] = $508;
   $515 = $$0197 | 3;
   $516 = ((($509)) + 4|0);
   HEAP32[$516>>2] = $515;
  } else {
   HEAP32[(3736)>>2] = 0;
   HEAP32[(3748)>>2] = 0;
   $517 = $506 | 3;
   $518 = ((($509)) + 4|0);
   HEAP32[$518>>2] = $517;
   $519 = (($509) + ($506)|0);
   $520 = ((($519)) + 4|0);
   $521 = HEAP32[$520>>2]|0;
   $522 = $521 | 1;
   HEAP32[$520>>2] = $522;
  }
  $523 = ((($509)) + 8|0);
  $$0 = $523;
  STACKTOP = sp;return ($$0|0);
 }
 $524 = HEAP32[(3740)>>2]|0;
 $525 = ($524>>>0)>($$0197>>>0);
 if ($525) {
  $526 = (($524) - ($$0197))|0;
  HEAP32[(3740)>>2] = $526;
  $527 = HEAP32[(3752)>>2]|0;
  $528 = (($527) + ($$0197)|0);
  HEAP32[(3752)>>2] = $528;
  $529 = $526 | 1;
  $530 = ((($528)) + 4|0);
  HEAP32[$530>>2] = $529;
  $531 = $$0197 | 3;
  $532 = ((($527)) + 4|0);
  HEAP32[$532>>2] = $531;
  $533 = ((($527)) + 8|0);
  $$0 = $533;
  STACKTOP = sp;return ($$0|0);
 }
 $534 = HEAP32[1050]|0;
 $535 = ($534|0)==(0);
 if ($535) {
  HEAP32[(4208)>>2] = 4096;
  HEAP32[(4204)>>2] = 4096;
  HEAP32[(4212)>>2] = -1;
  HEAP32[(4216)>>2] = -1;
  HEAP32[(4220)>>2] = 0;
  HEAP32[(4172)>>2] = 0;
  $536 = $1;
  $537 = $536 & -16;
  $538 = $537 ^ 1431655768;
  HEAP32[$1>>2] = $538;
  HEAP32[1050] = $538;
  $542 = 4096;
 } else {
  $$pre$i208 = HEAP32[(4208)>>2]|0;
  $542 = $$pre$i208;
 }
 $539 = (($$0197) + 48)|0;
 $540 = (($$0197) + 47)|0;
 $541 = (($542) + ($540))|0;
 $543 = (0 - ($542))|0;
 $544 = $541 & $543;
 $545 = ($544>>>0)>($$0197>>>0);
 if (!($545)) {
  $$0 = 0;
  STACKTOP = sp;return ($$0|0);
 }
 $546 = HEAP32[(4168)>>2]|0;
 $547 = ($546|0)==(0);
 if (!($547)) {
  $548 = HEAP32[(4160)>>2]|0;
  $549 = (($548) + ($544))|0;
  $550 = ($549>>>0)<=($548>>>0);
  $551 = ($549>>>0)>($546>>>0);
  $or$cond1$i210 = $550 | $551;
  if ($or$cond1$i210) {
   $$0 = 0;
   STACKTOP = sp;return ($$0|0);
  }
 }
 $552 = HEAP32[(4172)>>2]|0;
 $553 = $552 & 4;
 $554 = ($553|0)==(0);
 L255: do {
  if ($554) {
   $555 = HEAP32[(3752)>>2]|0;
   $556 = ($555|0)==(0|0);
   L257: do {
    if ($556) {
     label = 172;
    } else {
     $$0$i17$i = (4176);
     while(1) {
      $557 = HEAP32[$$0$i17$i>>2]|0;
      $558 = ($557>>>0)>($555>>>0);
      if (!($558)) {
       $559 = ((($$0$i17$i)) + 4|0);
       $560 = HEAP32[$559>>2]|0;
       $561 = (($557) + ($560)|0);
       $562 = ($561>>>0)>($555>>>0);
       if ($562) {
        break;
       }
      }
      $563 = ((($$0$i17$i)) + 8|0);
      $564 = HEAP32[$563>>2]|0;
      $565 = ($564|0)==(0|0);
      if ($565) {
       label = 172;
       break L257;
      } else {
       $$0$i17$i = $564;
      }
     }
     $588 = (($541) - ($524))|0;
     $589 = $588 & $543;
     $590 = ($589>>>0)<(2147483647);
     if ($590) {
      $591 = (_sbrk(($589|0))|0);
      $592 = HEAP32[$$0$i17$i>>2]|0;
      $593 = HEAP32[$559>>2]|0;
      $594 = (($592) + ($593)|0);
      $595 = ($591|0)==($594|0);
      if ($595) {
       $596 = ($591|0)==((-1)|0);
       if (!($596)) {
        $$723947$i = $589;$$748$i = $591;
        label = 190;
        break L255;
       }
      } else {
       $$2247$ph$i = $591;$$2253$ph$i = $589;
       label = 180;
      }
     }
    }
   } while(0);
   do {
    if ((label|0) == 172) {
     $566 = (_sbrk(0)|0);
     $567 = ($566|0)==((-1)|0);
     if (!($567)) {
      $568 = $566;
      $569 = HEAP32[(4204)>>2]|0;
      $570 = (($569) + -1)|0;
      $571 = $570 & $568;
      $572 = ($571|0)==(0);
      $573 = (($570) + ($568))|0;
      $574 = (0 - ($569))|0;
      $575 = $573 & $574;
      $576 = (($575) - ($568))|0;
      $577 = $572 ? 0 : $576;
      $$$i = (($577) + ($544))|0;
      $578 = HEAP32[(4160)>>2]|0;
      $579 = (($$$i) + ($578))|0;
      $580 = ($$$i>>>0)>($$0197>>>0);
      $581 = ($$$i>>>0)<(2147483647);
      $or$cond$i211 = $580 & $581;
      if ($or$cond$i211) {
       $582 = HEAP32[(4168)>>2]|0;
       $583 = ($582|0)==(0);
       if (!($583)) {
        $584 = ($579>>>0)<=($578>>>0);
        $585 = ($579>>>0)>($582>>>0);
        $or$cond2$i = $584 | $585;
        if ($or$cond2$i) {
         break;
        }
       }
       $586 = (_sbrk(($$$i|0))|0);
       $587 = ($586|0)==($566|0);
       if ($587) {
        $$723947$i = $$$i;$$748$i = $566;
        label = 190;
        break L255;
       } else {
        $$2247$ph$i = $586;$$2253$ph$i = $$$i;
        label = 180;
       }
      }
     }
    }
   } while(0);
   L274: do {
    if ((label|0) == 180) {
     $597 = (0 - ($$2253$ph$i))|0;
     $598 = ($$2247$ph$i|0)!=((-1)|0);
     $599 = ($$2253$ph$i>>>0)<(2147483647);
     $or$cond7$i = $599 & $598;
     $600 = ($539>>>0)>($$2253$ph$i>>>0);
     $or$cond10$i = $600 & $or$cond7$i;
     do {
      if ($or$cond10$i) {
       $601 = HEAP32[(4208)>>2]|0;
       $602 = (($540) - ($$2253$ph$i))|0;
       $603 = (($602) + ($601))|0;
       $604 = (0 - ($601))|0;
       $605 = $603 & $604;
       $606 = ($605>>>0)<(2147483647);
       if ($606) {
        $607 = (_sbrk(($605|0))|0);
        $608 = ($607|0)==((-1)|0);
        if ($608) {
         (_sbrk(($597|0))|0);
         break L274;
        } else {
         $609 = (($605) + ($$2253$ph$i))|0;
         $$5256$i = $609;
         break;
        }
       } else {
        $$5256$i = $$2253$ph$i;
       }
      } else {
       $$5256$i = $$2253$ph$i;
      }
     } while(0);
     $610 = ($$2247$ph$i|0)==((-1)|0);
     if (!($610)) {
      $$723947$i = $$5256$i;$$748$i = $$2247$ph$i;
      label = 190;
      break L255;
     }
    }
   } while(0);
   $611 = HEAP32[(4172)>>2]|0;
   $612 = $611 | 4;
   HEAP32[(4172)>>2] = $612;
   label = 187;
  } else {
   label = 187;
  }
 } while(0);
 if ((label|0) == 187) {
  $613 = ($544>>>0)<(2147483647);
  if ($613) {
   $614 = (_sbrk(($544|0))|0);
   $615 = (_sbrk(0)|0);
   $616 = ($614|0)!=((-1)|0);
   $617 = ($615|0)!=((-1)|0);
   $or$cond5$i = $616 & $617;
   $618 = ($614>>>0)<($615>>>0);
   $or$cond11$i = $618 & $or$cond5$i;
   if ($or$cond11$i) {
    $619 = $615;
    $620 = $614;
    $621 = (($619) - ($620))|0;
    $622 = (($$0197) + 40)|0;
    $$not$i = ($621>>>0)>($622>>>0);
    if ($$not$i) {
     $$723947$i = $621;$$748$i = $614;
     label = 190;
    }
   }
  }
 }
 if ((label|0) == 190) {
  $623 = HEAP32[(4160)>>2]|0;
  $624 = (($623) + ($$723947$i))|0;
  HEAP32[(4160)>>2] = $624;
  $625 = HEAP32[(4164)>>2]|0;
  $626 = ($624>>>0)>($625>>>0);
  if ($626) {
   HEAP32[(4164)>>2] = $624;
  }
  $627 = HEAP32[(3752)>>2]|0;
  $628 = ($627|0)==(0|0);
  do {
   if ($628) {
    $629 = HEAP32[(3744)>>2]|0;
    $630 = ($629|0)==(0|0);
    $631 = ($$748$i>>>0)<($629>>>0);
    $or$cond12$i = $630 | $631;
    if ($or$cond12$i) {
     HEAP32[(3744)>>2] = $$748$i;
    }
    HEAP32[(4176)>>2] = $$748$i;
    HEAP32[(4180)>>2] = $$723947$i;
    HEAP32[(4188)>>2] = 0;
    $632 = HEAP32[1050]|0;
    HEAP32[(3764)>>2] = $632;
    HEAP32[(3760)>>2] = -1;
    $$01$i$i = 0;
    while(1) {
     $633 = $$01$i$i << 1;
     $634 = (3768 + ($633<<2)|0);
     $635 = ((($634)) + 12|0);
     HEAP32[$635>>2] = $634;
     $636 = ((($634)) + 8|0);
     HEAP32[$636>>2] = $634;
     $637 = (($$01$i$i) + 1)|0;
     $exitcond$i$i = ($637|0)==(32);
     if ($exitcond$i$i) {
      break;
     } else {
      $$01$i$i = $637;
     }
    }
    $638 = (($$723947$i) + -40)|0;
    $639 = ((($$748$i)) + 8|0);
    $640 = $639;
    $641 = $640 & 7;
    $642 = ($641|0)==(0);
    $643 = (0 - ($640))|0;
    $644 = $643 & 7;
    $645 = $642 ? 0 : $644;
    $646 = (($$748$i) + ($645)|0);
    $647 = (($638) - ($645))|0;
    HEAP32[(3752)>>2] = $646;
    HEAP32[(3740)>>2] = $647;
    $648 = $647 | 1;
    $649 = ((($646)) + 4|0);
    HEAP32[$649>>2] = $648;
    $650 = (($646) + ($647)|0);
    $651 = ((($650)) + 4|0);
    HEAP32[$651>>2] = 40;
    $652 = HEAP32[(4216)>>2]|0;
    HEAP32[(3756)>>2] = $652;
   } else {
    $$024370$i = (4176);
    while(1) {
     $653 = HEAP32[$$024370$i>>2]|0;
     $654 = ((($$024370$i)) + 4|0);
     $655 = HEAP32[$654>>2]|0;
     $656 = (($653) + ($655)|0);
     $657 = ($$748$i|0)==($656|0);
     if ($657) {
      label = 200;
      break;
     }
     $658 = ((($$024370$i)) + 8|0);
     $659 = HEAP32[$658>>2]|0;
     $660 = ($659|0)==(0|0);
     if ($660) {
      break;
     } else {
      $$024370$i = $659;
     }
    }
    if ((label|0) == 200) {
     $661 = ((($$024370$i)) + 12|0);
     $662 = HEAP32[$661>>2]|0;
     $663 = $662 & 8;
     $664 = ($663|0)==(0);
     if ($664) {
      $665 = ($627>>>0)>=($653>>>0);
      $666 = ($627>>>0)<($$748$i>>>0);
      $or$cond50$i = $666 & $665;
      if ($or$cond50$i) {
       $667 = (($655) + ($$723947$i))|0;
       HEAP32[$654>>2] = $667;
       $668 = HEAP32[(3740)>>2]|0;
       $669 = ((($627)) + 8|0);
       $670 = $669;
       $671 = $670 & 7;
       $672 = ($671|0)==(0);
       $673 = (0 - ($670))|0;
       $674 = $673 & 7;
       $675 = $672 ? 0 : $674;
       $676 = (($627) + ($675)|0);
       $677 = (($$723947$i) - ($675))|0;
       $678 = (($677) + ($668))|0;
       HEAP32[(3752)>>2] = $676;
       HEAP32[(3740)>>2] = $678;
       $679 = $678 | 1;
       $680 = ((($676)) + 4|0);
       HEAP32[$680>>2] = $679;
       $681 = (($676) + ($678)|0);
       $682 = ((($681)) + 4|0);
       HEAP32[$682>>2] = 40;
       $683 = HEAP32[(4216)>>2]|0;
       HEAP32[(3756)>>2] = $683;
       break;
      }
     }
    }
    $684 = HEAP32[(3744)>>2]|0;
    $685 = ($$748$i>>>0)<($684>>>0);
    if ($685) {
     HEAP32[(3744)>>2] = $$748$i;
     $749 = $$748$i;
    } else {
     $749 = $684;
    }
    $686 = (($$748$i) + ($$723947$i)|0);
    $$124469$i = (4176);
    while(1) {
     $687 = HEAP32[$$124469$i>>2]|0;
     $688 = ($687|0)==($686|0);
     if ($688) {
      label = 208;
      break;
     }
     $689 = ((($$124469$i)) + 8|0);
     $690 = HEAP32[$689>>2]|0;
     $691 = ($690|0)==(0|0);
     if ($691) {
      $$0$i$i$i = (4176);
      break;
     } else {
      $$124469$i = $690;
     }
    }
    if ((label|0) == 208) {
     $692 = ((($$124469$i)) + 12|0);
     $693 = HEAP32[$692>>2]|0;
     $694 = $693 & 8;
     $695 = ($694|0)==(0);
     if ($695) {
      HEAP32[$$124469$i>>2] = $$748$i;
      $696 = ((($$124469$i)) + 4|0);
      $697 = HEAP32[$696>>2]|0;
      $698 = (($697) + ($$723947$i))|0;
      HEAP32[$696>>2] = $698;
      $699 = ((($$748$i)) + 8|0);
      $700 = $699;
      $701 = $700 & 7;
      $702 = ($701|0)==(0);
      $703 = (0 - ($700))|0;
      $704 = $703 & 7;
      $705 = $702 ? 0 : $704;
      $706 = (($$748$i) + ($705)|0);
      $707 = ((($686)) + 8|0);
      $708 = $707;
      $709 = $708 & 7;
      $710 = ($709|0)==(0);
      $711 = (0 - ($708))|0;
      $712 = $711 & 7;
      $713 = $710 ? 0 : $712;
      $714 = (($686) + ($713)|0);
      $715 = $714;
      $716 = $706;
      $717 = (($715) - ($716))|0;
      $718 = (($706) + ($$0197)|0);
      $719 = (($717) - ($$0197))|0;
      $720 = $$0197 | 3;
      $721 = ((($706)) + 4|0);
      HEAP32[$721>>2] = $720;
      $722 = ($714|0)==($627|0);
      do {
       if ($722) {
        $723 = HEAP32[(3740)>>2]|0;
        $724 = (($723) + ($719))|0;
        HEAP32[(3740)>>2] = $724;
        HEAP32[(3752)>>2] = $718;
        $725 = $724 | 1;
        $726 = ((($718)) + 4|0);
        HEAP32[$726>>2] = $725;
       } else {
        $727 = HEAP32[(3748)>>2]|0;
        $728 = ($714|0)==($727|0);
        if ($728) {
         $729 = HEAP32[(3736)>>2]|0;
         $730 = (($729) + ($719))|0;
         HEAP32[(3736)>>2] = $730;
         HEAP32[(3748)>>2] = $718;
         $731 = $730 | 1;
         $732 = ((($718)) + 4|0);
         HEAP32[$732>>2] = $731;
         $733 = (($718) + ($730)|0);
         HEAP32[$733>>2] = $730;
         break;
        }
        $734 = ((($714)) + 4|0);
        $735 = HEAP32[$734>>2]|0;
        $736 = $735 & 3;
        $737 = ($736|0)==(1);
        if ($737) {
         $738 = $735 & -8;
         $739 = $735 >>> 3;
         $740 = ($735>>>0)<(256);
         L326: do {
          if ($740) {
           $741 = ((($714)) + 8|0);
           $742 = HEAP32[$741>>2]|0;
           $743 = ((($714)) + 12|0);
           $744 = HEAP32[$743>>2]|0;
           $745 = $739 << 1;
           $746 = (3768 + ($745<<2)|0);
           $747 = ($742|0)==($746|0);
           do {
            if (!($747)) {
             $748 = ($742>>>0)<($749>>>0);
             if ($748) {
              _abort();
              // unreachable;
             }
             $750 = ((($742)) + 12|0);
             $751 = HEAP32[$750>>2]|0;
             $752 = ($751|0)==($714|0);
             if ($752) {
              break;
             }
             _abort();
             // unreachable;
            }
           } while(0);
           $753 = ($744|0)==($742|0);
           if ($753) {
            $754 = 1 << $739;
            $755 = $754 ^ -1;
            $756 = HEAP32[932]|0;
            $757 = $756 & $755;
            HEAP32[932] = $757;
            break;
           }
           $758 = ($744|0)==($746|0);
           do {
            if ($758) {
             $$pre9$i$i = ((($744)) + 8|0);
             $$pre$phi10$i$iZ2D = $$pre9$i$i;
            } else {
             $759 = ($744>>>0)<($749>>>0);
             if ($759) {
              _abort();
              // unreachable;
             }
             $760 = ((($744)) + 8|0);
             $761 = HEAP32[$760>>2]|0;
             $762 = ($761|0)==($714|0);
             if ($762) {
              $$pre$phi10$i$iZ2D = $760;
              break;
             }
             _abort();
             // unreachable;
            }
           } while(0);
           $763 = ((($742)) + 12|0);
           HEAP32[$763>>2] = $744;
           HEAP32[$$pre$phi10$i$iZ2D>>2] = $742;
          } else {
           $764 = ((($714)) + 24|0);
           $765 = HEAP32[$764>>2]|0;
           $766 = ((($714)) + 12|0);
           $767 = HEAP32[$766>>2]|0;
           $768 = ($767|0)==($714|0);
           do {
            if ($768) {
             $778 = ((($714)) + 16|0);
             $779 = ((($778)) + 4|0);
             $780 = HEAP32[$779>>2]|0;
             $781 = ($780|0)==(0|0);
             if ($781) {
              $782 = HEAP32[$778>>2]|0;
              $783 = ($782|0)==(0|0);
              if ($783) {
               $$3$i$i = 0;
               break;
              } else {
               $$1290$i$i = $782;$$1292$i$i = $778;
              }
             } else {
              $$1290$i$i = $780;$$1292$i$i = $779;
             }
             while(1) {
              $784 = ((($$1290$i$i)) + 20|0);
              $785 = HEAP32[$784>>2]|0;
              $786 = ($785|0)==(0|0);
              if (!($786)) {
               $$1290$i$i = $785;$$1292$i$i = $784;
               continue;
              }
              $787 = ((($$1290$i$i)) + 16|0);
              $788 = HEAP32[$787>>2]|0;
              $789 = ($788|0)==(0|0);
              if ($789) {
               break;
              } else {
               $$1290$i$i = $788;$$1292$i$i = $787;
              }
             }
             $790 = ($$1292$i$i>>>0)<($749>>>0);
             if ($790) {
              _abort();
              // unreachable;
             } else {
              HEAP32[$$1292$i$i>>2] = 0;
              $$3$i$i = $$1290$i$i;
              break;
             }
            } else {
             $769 = ((($714)) + 8|0);
             $770 = HEAP32[$769>>2]|0;
             $771 = ($770>>>0)<($749>>>0);
             if ($771) {
              _abort();
              // unreachable;
             }
             $772 = ((($770)) + 12|0);
             $773 = HEAP32[$772>>2]|0;
             $774 = ($773|0)==($714|0);
             if (!($774)) {
              _abort();
              // unreachable;
             }
             $775 = ((($767)) + 8|0);
             $776 = HEAP32[$775>>2]|0;
             $777 = ($776|0)==($714|0);
             if ($777) {
              HEAP32[$772>>2] = $767;
              HEAP32[$775>>2] = $770;
              $$3$i$i = $767;
              break;
             } else {
              _abort();
              // unreachable;
             }
            }
           } while(0);
           $791 = ($765|0)==(0|0);
           if ($791) {
            break;
           }
           $792 = ((($714)) + 28|0);
           $793 = HEAP32[$792>>2]|0;
           $794 = (4032 + ($793<<2)|0);
           $795 = HEAP32[$794>>2]|0;
           $796 = ($714|0)==($795|0);
           do {
            if ($796) {
             HEAP32[$794>>2] = $$3$i$i;
             $cond$i$i = ($$3$i$i|0)==(0|0);
             if (!($cond$i$i)) {
              break;
             }
             $797 = 1 << $793;
             $798 = $797 ^ -1;
             $799 = HEAP32[(3732)>>2]|0;
             $800 = $799 & $798;
             HEAP32[(3732)>>2] = $800;
             break L326;
            } else {
             $801 = HEAP32[(3744)>>2]|0;
             $802 = ($765>>>0)<($801>>>0);
             if ($802) {
              _abort();
              // unreachable;
             }
             $803 = ((($765)) + 16|0);
             $804 = HEAP32[$803>>2]|0;
             $805 = ($804|0)==($714|0);
             if ($805) {
              HEAP32[$803>>2] = $$3$i$i;
             } else {
              $806 = ((($765)) + 20|0);
              HEAP32[$806>>2] = $$3$i$i;
             }
             $807 = ($$3$i$i|0)==(0|0);
             if ($807) {
              break L326;
             }
            }
           } while(0);
           $808 = HEAP32[(3744)>>2]|0;
           $809 = ($$3$i$i>>>0)<($808>>>0);
           if ($809) {
            _abort();
            // unreachable;
           }
           $810 = ((($$3$i$i)) + 24|0);
           HEAP32[$810>>2] = $765;
           $811 = ((($714)) + 16|0);
           $812 = HEAP32[$811>>2]|0;
           $813 = ($812|0)==(0|0);
           do {
            if (!($813)) {
             $814 = ($812>>>0)<($808>>>0);
             if ($814) {
              _abort();
              // unreachable;
             } else {
              $815 = ((($$3$i$i)) + 16|0);
              HEAP32[$815>>2] = $812;
              $816 = ((($812)) + 24|0);
              HEAP32[$816>>2] = $$3$i$i;
              break;
             }
            }
           } while(0);
           $817 = ((($811)) + 4|0);
           $818 = HEAP32[$817>>2]|0;
           $819 = ($818|0)==(0|0);
           if ($819) {
            break;
           }
           $820 = HEAP32[(3744)>>2]|0;
           $821 = ($818>>>0)<($820>>>0);
           if ($821) {
            _abort();
            // unreachable;
           } else {
            $822 = ((($$3$i$i)) + 20|0);
            HEAP32[$822>>2] = $818;
            $823 = ((($818)) + 24|0);
            HEAP32[$823>>2] = $$3$i$i;
            break;
           }
          }
         } while(0);
         $824 = (($714) + ($738)|0);
         $825 = (($738) + ($719))|0;
         $$0$i18$i = $824;$$0286$i$i = $825;
        } else {
         $$0$i18$i = $714;$$0286$i$i = $719;
        }
        $826 = ((($$0$i18$i)) + 4|0);
        $827 = HEAP32[$826>>2]|0;
        $828 = $827 & -2;
        HEAP32[$826>>2] = $828;
        $829 = $$0286$i$i | 1;
        $830 = ((($718)) + 4|0);
        HEAP32[$830>>2] = $829;
        $831 = (($718) + ($$0286$i$i)|0);
        HEAP32[$831>>2] = $$0286$i$i;
        $832 = $$0286$i$i >>> 3;
        $833 = ($$0286$i$i>>>0)<(256);
        if ($833) {
         $834 = $832 << 1;
         $835 = (3768 + ($834<<2)|0);
         $836 = HEAP32[932]|0;
         $837 = 1 << $832;
         $838 = $836 & $837;
         $839 = ($838|0)==(0);
         do {
          if ($839) {
           $840 = $836 | $837;
           HEAP32[932] = $840;
           $$pre$i19$i = ((($835)) + 8|0);
           $$0294$i$i = $835;$$pre$phi$i20$iZ2D = $$pre$i19$i;
          } else {
           $841 = ((($835)) + 8|0);
           $842 = HEAP32[$841>>2]|0;
           $843 = HEAP32[(3744)>>2]|0;
           $844 = ($842>>>0)<($843>>>0);
           if (!($844)) {
            $$0294$i$i = $842;$$pre$phi$i20$iZ2D = $841;
            break;
           }
           _abort();
           // unreachable;
          }
         } while(0);
         HEAP32[$$pre$phi$i20$iZ2D>>2] = $718;
         $845 = ((($$0294$i$i)) + 12|0);
         HEAP32[$845>>2] = $718;
         $846 = ((($718)) + 8|0);
         HEAP32[$846>>2] = $$0294$i$i;
         $847 = ((($718)) + 12|0);
         HEAP32[$847>>2] = $835;
         break;
        }
        $848 = $$0286$i$i >>> 8;
        $849 = ($848|0)==(0);
        do {
         if ($849) {
          $$0295$i$i = 0;
         } else {
          $850 = ($$0286$i$i>>>0)>(16777215);
          if ($850) {
           $$0295$i$i = 31;
           break;
          }
          $851 = (($848) + 1048320)|0;
          $852 = $851 >>> 16;
          $853 = $852 & 8;
          $854 = $848 << $853;
          $855 = (($854) + 520192)|0;
          $856 = $855 >>> 16;
          $857 = $856 & 4;
          $858 = $857 | $853;
          $859 = $854 << $857;
          $860 = (($859) + 245760)|0;
          $861 = $860 >>> 16;
          $862 = $861 & 2;
          $863 = $858 | $862;
          $864 = (14 - ($863))|0;
          $865 = $859 << $862;
          $866 = $865 >>> 15;
          $867 = (($864) + ($866))|0;
          $868 = $867 << 1;
          $869 = (($867) + 7)|0;
          $870 = $$0286$i$i >>> $869;
          $871 = $870 & 1;
          $872 = $871 | $868;
          $$0295$i$i = $872;
         }
        } while(0);
        $873 = (4032 + ($$0295$i$i<<2)|0);
        $874 = ((($718)) + 28|0);
        HEAP32[$874>>2] = $$0295$i$i;
        $875 = ((($718)) + 16|0);
        $876 = ((($875)) + 4|0);
        HEAP32[$876>>2] = 0;
        HEAP32[$875>>2] = 0;
        $877 = HEAP32[(3732)>>2]|0;
        $878 = 1 << $$0295$i$i;
        $879 = $877 & $878;
        $880 = ($879|0)==(0);
        if ($880) {
         $881 = $877 | $878;
         HEAP32[(3732)>>2] = $881;
         HEAP32[$873>>2] = $718;
         $882 = ((($718)) + 24|0);
         HEAP32[$882>>2] = $873;
         $883 = ((($718)) + 12|0);
         HEAP32[$883>>2] = $718;
         $884 = ((($718)) + 8|0);
         HEAP32[$884>>2] = $718;
         break;
        }
        $885 = HEAP32[$873>>2]|0;
        $886 = ($$0295$i$i|0)==(31);
        $887 = $$0295$i$i >>> 1;
        $888 = (25 - ($887))|0;
        $889 = $886 ? 0 : $888;
        $890 = $$0286$i$i << $889;
        $$0287$i$i = $890;$$0288$i$i = $885;
        while(1) {
         $891 = ((($$0288$i$i)) + 4|0);
         $892 = HEAP32[$891>>2]|0;
         $893 = $892 & -8;
         $894 = ($893|0)==($$0286$i$i|0);
         if ($894) {
          label = 278;
          break;
         }
         $895 = $$0287$i$i >>> 31;
         $896 = (((($$0288$i$i)) + 16|0) + ($895<<2)|0);
         $897 = $$0287$i$i << 1;
         $898 = HEAP32[$896>>2]|0;
         $899 = ($898|0)==(0|0);
         if ($899) {
          label = 275;
          break;
         } else {
          $$0287$i$i = $897;$$0288$i$i = $898;
         }
        }
        if ((label|0) == 275) {
         $900 = HEAP32[(3744)>>2]|0;
         $901 = ($896>>>0)<($900>>>0);
         if ($901) {
          _abort();
          // unreachable;
         } else {
          HEAP32[$896>>2] = $718;
          $902 = ((($718)) + 24|0);
          HEAP32[$902>>2] = $$0288$i$i;
          $903 = ((($718)) + 12|0);
          HEAP32[$903>>2] = $718;
          $904 = ((($718)) + 8|0);
          HEAP32[$904>>2] = $718;
          break;
         }
        }
        else if ((label|0) == 278) {
         $905 = ((($$0288$i$i)) + 8|0);
         $906 = HEAP32[$905>>2]|0;
         $907 = HEAP32[(3744)>>2]|0;
         $908 = ($906>>>0)>=($907>>>0);
         $not$$i22$i = ($$0288$i$i>>>0)>=($907>>>0);
         $909 = $908 & $not$$i22$i;
         if ($909) {
          $910 = ((($906)) + 12|0);
          HEAP32[$910>>2] = $718;
          HEAP32[$905>>2] = $718;
          $911 = ((($718)) + 8|0);
          HEAP32[$911>>2] = $906;
          $912 = ((($718)) + 12|0);
          HEAP32[$912>>2] = $$0288$i$i;
          $913 = ((($718)) + 24|0);
          HEAP32[$913>>2] = 0;
          break;
         } else {
          _abort();
          // unreachable;
         }
        }
       }
      } while(0);
      $1044 = ((($706)) + 8|0);
      $$0 = $1044;
      STACKTOP = sp;return ($$0|0);
     } else {
      $$0$i$i$i = (4176);
     }
    }
    while(1) {
     $914 = HEAP32[$$0$i$i$i>>2]|0;
     $915 = ($914>>>0)>($627>>>0);
     if (!($915)) {
      $916 = ((($$0$i$i$i)) + 4|0);
      $917 = HEAP32[$916>>2]|0;
      $918 = (($914) + ($917)|0);
      $919 = ($918>>>0)>($627>>>0);
      if ($919) {
       break;
      }
     }
     $920 = ((($$0$i$i$i)) + 8|0);
     $921 = HEAP32[$920>>2]|0;
     $$0$i$i$i = $921;
    }
    $922 = ((($918)) + -47|0);
    $923 = ((($922)) + 8|0);
    $924 = $923;
    $925 = $924 & 7;
    $926 = ($925|0)==(0);
    $927 = (0 - ($924))|0;
    $928 = $927 & 7;
    $929 = $926 ? 0 : $928;
    $930 = (($922) + ($929)|0);
    $931 = ((($627)) + 16|0);
    $932 = ($930>>>0)<($931>>>0);
    $933 = $932 ? $627 : $930;
    $934 = ((($933)) + 8|0);
    $935 = ((($933)) + 24|0);
    $936 = (($$723947$i) + -40)|0;
    $937 = ((($$748$i)) + 8|0);
    $938 = $937;
    $939 = $938 & 7;
    $940 = ($939|0)==(0);
    $941 = (0 - ($938))|0;
    $942 = $941 & 7;
    $943 = $940 ? 0 : $942;
    $944 = (($$748$i) + ($943)|0);
    $945 = (($936) - ($943))|0;
    HEAP32[(3752)>>2] = $944;
    HEAP32[(3740)>>2] = $945;
    $946 = $945 | 1;
    $947 = ((($944)) + 4|0);
    HEAP32[$947>>2] = $946;
    $948 = (($944) + ($945)|0);
    $949 = ((($948)) + 4|0);
    HEAP32[$949>>2] = 40;
    $950 = HEAP32[(4216)>>2]|0;
    HEAP32[(3756)>>2] = $950;
    $951 = ((($933)) + 4|0);
    HEAP32[$951>>2] = 27;
    ;HEAP32[$934>>2]=HEAP32[(4176)>>2]|0;HEAP32[$934+4>>2]=HEAP32[(4176)+4>>2]|0;HEAP32[$934+8>>2]=HEAP32[(4176)+8>>2]|0;HEAP32[$934+12>>2]=HEAP32[(4176)+12>>2]|0;
    HEAP32[(4176)>>2] = $$748$i;
    HEAP32[(4180)>>2] = $$723947$i;
    HEAP32[(4188)>>2] = 0;
    HEAP32[(4184)>>2] = $934;
    $$0$i$i = $935;
    while(1) {
     $952 = ((($$0$i$i)) + 4|0);
     HEAP32[$952>>2] = 7;
     $953 = ((($952)) + 4|0);
     $954 = ($953>>>0)<($918>>>0);
     if ($954) {
      $$0$i$i = $952;
     } else {
      break;
     }
    }
    $955 = ($933|0)==($627|0);
    if (!($955)) {
     $956 = $933;
     $957 = $627;
     $958 = (($956) - ($957))|0;
     $959 = HEAP32[$951>>2]|0;
     $960 = $959 & -2;
     HEAP32[$951>>2] = $960;
     $961 = $958 | 1;
     $962 = ((($627)) + 4|0);
     HEAP32[$962>>2] = $961;
     HEAP32[$933>>2] = $958;
     $963 = $958 >>> 3;
     $964 = ($958>>>0)<(256);
     if ($964) {
      $965 = $963 << 1;
      $966 = (3768 + ($965<<2)|0);
      $967 = HEAP32[932]|0;
      $968 = 1 << $963;
      $969 = $967 & $968;
      $970 = ($969|0)==(0);
      if ($970) {
       $971 = $967 | $968;
       HEAP32[932] = $971;
       $$pre$i$i = ((($966)) + 8|0);
       $$0211$i$i = $966;$$pre$phi$i$iZ2D = $$pre$i$i;
      } else {
       $972 = ((($966)) + 8|0);
       $973 = HEAP32[$972>>2]|0;
       $974 = HEAP32[(3744)>>2]|0;
       $975 = ($973>>>0)<($974>>>0);
       if ($975) {
        _abort();
        // unreachable;
       } else {
        $$0211$i$i = $973;$$pre$phi$i$iZ2D = $972;
       }
      }
      HEAP32[$$pre$phi$i$iZ2D>>2] = $627;
      $976 = ((($$0211$i$i)) + 12|0);
      HEAP32[$976>>2] = $627;
      $977 = ((($627)) + 8|0);
      HEAP32[$977>>2] = $$0211$i$i;
      $978 = ((($627)) + 12|0);
      HEAP32[$978>>2] = $966;
      break;
     }
     $979 = $958 >>> 8;
     $980 = ($979|0)==(0);
     if ($980) {
      $$0212$i$i = 0;
     } else {
      $981 = ($958>>>0)>(16777215);
      if ($981) {
       $$0212$i$i = 31;
      } else {
       $982 = (($979) + 1048320)|0;
       $983 = $982 >>> 16;
       $984 = $983 & 8;
       $985 = $979 << $984;
       $986 = (($985) + 520192)|0;
       $987 = $986 >>> 16;
       $988 = $987 & 4;
       $989 = $988 | $984;
       $990 = $985 << $988;
       $991 = (($990) + 245760)|0;
       $992 = $991 >>> 16;
       $993 = $992 & 2;
       $994 = $989 | $993;
       $995 = (14 - ($994))|0;
       $996 = $990 << $993;
       $997 = $996 >>> 15;
       $998 = (($995) + ($997))|0;
       $999 = $998 << 1;
       $1000 = (($998) + 7)|0;
       $1001 = $958 >>> $1000;
       $1002 = $1001 & 1;
       $1003 = $1002 | $999;
       $$0212$i$i = $1003;
      }
     }
     $1004 = (4032 + ($$0212$i$i<<2)|0);
     $1005 = ((($627)) + 28|0);
     HEAP32[$1005>>2] = $$0212$i$i;
     $1006 = ((($627)) + 20|0);
     HEAP32[$1006>>2] = 0;
     HEAP32[$931>>2] = 0;
     $1007 = HEAP32[(3732)>>2]|0;
     $1008 = 1 << $$0212$i$i;
     $1009 = $1007 & $1008;
     $1010 = ($1009|0)==(0);
     if ($1010) {
      $1011 = $1007 | $1008;
      HEAP32[(3732)>>2] = $1011;
      HEAP32[$1004>>2] = $627;
      $1012 = ((($627)) + 24|0);
      HEAP32[$1012>>2] = $1004;
      $1013 = ((($627)) + 12|0);
      HEAP32[$1013>>2] = $627;
      $1014 = ((($627)) + 8|0);
      HEAP32[$1014>>2] = $627;
      break;
     }
     $1015 = HEAP32[$1004>>2]|0;
     $1016 = ($$0212$i$i|0)==(31);
     $1017 = $$0212$i$i >>> 1;
     $1018 = (25 - ($1017))|0;
     $1019 = $1016 ? 0 : $1018;
     $1020 = $958 << $1019;
     $$0206$i$i = $1020;$$0207$i$i = $1015;
     while(1) {
      $1021 = ((($$0207$i$i)) + 4|0);
      $1022 = HEAP32[$1021>>2]|0;
      $1023 = $1022 & -8;
      $1024 = ($1023|0)==($958|0);
      if ($1024) {
       label = 304;
       break;
      }
      $1025 = $$0206$i$i >>> 31;
      $1026 = (((($$0207$i$i)) + 16|0) + ($1025<<2)|0);
      $1027 = $$0206$i$i << 1;
      $1028 = HEAP32[$1026>>2]|0;
      $1029 = ($1028|0)==(0|0);
      if ($1029) {
       label = 301;
       break;
      } else {
       $$0206$i$i = $1027;$$0207$i$i = $1028;
      }
     }
     if ((label|0) == 301) {
      $1030 = HEAP32[(3744)>>2]|0;
      $1031 = ($1026>>>0)<($1030>>>0);
      if ($1031) {
       _abort();
       // unreachable;
      } else {
       HEAP32[$1026>>2] = $627;
       $1032 = ((($627)) + 24|0);
       HEAP32[$1032>>2] = $$0207$i$i;
       $1033 = ((($627)) + 12|0);
       HEAP32[$1033>>2] = $627;
       $1034 = ((($627)) + 8|0);
       HEAP32[$1034>>2] = $627;
       break;
      }
     }
     else if ((label|0) == 304) {
      $1035 = ((($$0207$i$i)) + 8|0);
      $1036 = HEAP32[$1035>>2]|0;
      $1037 = HEAP32[(3744)>>2]|0;
      $1038 = ($1036>>>0)>=($1037>>>0);
      $not$$i$i = ($$0207$i$i>>>0)>=($1037>>>0);
      $1039 = $1038 & $not$$i$i;
      if ($1039) {
       $1040 = ((($1036)) + 12|0);
       HEAP32[$1040>>2] = $627;
       HEAP32[$1035>>2] = $627;
       $1041 = ((($627)) + 8|0);
       HEAP32[$1041>>2] = $1036;
       $1042 = ((($627)) + 12|0);
       HEAP32[$1042>>2] = $$0207$i$i;
       $1043 = ((($627)) + 24|0);
       HEAP32[$1043>>2] = 0;
       break;
      } else {
       _abort();
       // unreachable;
      }
     }
    }
   }
  } while(0);
  $1045 = HEAP32[(3740)>>2]|0;
  $1046 = ($1045>>>0)>($$0197>>>0);
  if ($1046) {
   $1047 = (($1045) - ($$0197))|0;
   HEAP32[(3740)>>2] = $1047;
   $1048 = HEAP32[(3752)>>2]|0;
   $1049 = (($1048) + ($$0197)|0);
   HEAP32[(3752)>>2] = $1049;
   $1050 = $1047 | 1;
   $1051 = ((($1049)) + 4|0);
   HEAP32[$1051>>2] = $1050;
   $1052 = $$0197 | 3;
   $1053 = ((($1048)) + 4|0);
   HEAP32[$1053>>2] = $1052;
   $1054 = ((($1048)) + 8|0);
   $$0 = $1054;
   STACKTOP = sp;return ($$0|0);
  }
 }
 $1055 = (___errno_location()|0);
 HEAP32[$1055>>2] = 12;
 $$0 = 0;
 STACKTOP = sp;return ($$0|0);
}
function _free($0) {
 $0 = $0|0;
 var $$0211$i = 0, $$0211$in$i = 0, $$0381 = 0, $$0382 = 0, $$0394 = 0, $$0401 = 0, $$1 = 0, $$1380 = 0, $$1385 = 0, $$1388 = 0, $$1396 = 0, $$1400 = 0, $$2 = 0, $$3 = 0, $$3398 = 0, $$pre = 0, $$pre$phi439Z2D = 0, $$pre$phi441Z2D = 0, $$pre$phiZ2D = 0, $$pre438 = 0;
 var $$pre440 = 0, $1 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0;
 var $116 = 0, $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0, $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0;
 var $134 = 0, $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0, $14 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $15 = 0, $150 = 0, $151 = 0;
 var $152 = 0, $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0, $158 = 0, $159 = 0, $16 = 0, $160 = 0, $161 = 0, $162 = 0, $163 = 0, $164 = 0, $165 = 0, $166 = 0, $167 = 0, $168 = 0, $169 = 0, $17 = 0;
 var $170 = 0, $171 = 0, $172 = 0, $173 = 0, $174 = 0, $175 = 0, $176 = 0, $177 = 0, $178 = 0, $179 = 0, $18 = 0, $180 = 0, $181 = 0, $182 = 0, $183 = 0, $184 = 0, $185 = 0, $186 = 0, $187 = 0, $188 = 0;
 var $189 = 0, $19 = 0, $190 = 0, $191 = 0, $192 = 0, $193 = 0, $194 = 0, $195 = 0, $196 = 0, $197 = 0, $198 = 0, $199 = 0, $2 = 0, $20 = 0, $200 = 0, $201 = 0, $202 = 0, $203 = 0, $204 = 0, $205 = 0;
 var $206 = 0, $207 = 0, $208 = 0, $209 = 0, $21 = 0, $210 = 0, $211 = 0, $212 = 0, $213 = 0, $214 = 0, $215 = 0, $216 = 0, $217 = 0, $218 = 0, $219 = 0, $22 = 0, $220 = 0, $221 = 0, $222 = 0, $223 = 0;
 var $224 = 0, $225 = 0, $226 = 0, $227 = 0, $228 = 0, $229 = 0, $23 = 0, $230 = 0, $231 = 0, $232 = 0, $233 = 0, $234 = 0, $235 = 0, $236 = 0, $237 = 0, $238 = 0, $239 = 0, $24 = 0, $240 = 0, $241 = 0;
 var $242 = 0, $243 = 0, $244 = 0, $245 = 0, $246 = 0, $247 = 0, $248 = 0, $249 = 0, $25 = 0, $250 = 0, $251 = 0, $252 = 0, $253 = 0, $254 = 0, $255 = 0, $256 = 0, $257 = 0, $258 = 0, $259 = 0, $26 = 0;
 var $260 = 0, $261 = 0, $262 = 0, $263 = 0, $264 = 0, $265 = 0, $266 = 0, $267 = 0, $268 = 0, $269 = 0, $27 = 0, $270 = 0, $271 = 0, $272 = 0, $273 = 0, $274 = 0, $275 = 0, $276 = 0, $277 = 0, $278 = 0;
 var $279 = 0, $28 = 0, $280 = 0, $281 = 0, $282 = 0, $283 = 0, $284 = 0, $285 = 0, $286 = 0, $287 = 0, $288 = 0, $289 = 0, $29 = 0, $290 = 0, $291 = 0, $292 = 0, $293 = 0, $294 = 0, $295 = 0, $296 = 0;
 var $297 = 0, $298 = 0, $299 = 0, $3 = 0, $30 = 0, $300 = 0, $301 = 0, $302 = 0, $303 = 0, $304 = 0, $305 = 0, $306 = 0, $307 = 0, $308 = 0, $309 = 0, $31 = 0, $310 = 0, $311 = 0, $312 = 0, $313 = 0;
 var $314 = 0, $315 = 0, $316 = 0, $317 = 0, $318 = 0, $319 = 0, $32 = 0, $320 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0;
 var $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0;
 var $62 = 0, $63 = 0, $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0;
 var $80 = 0, $81 = 0, $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0;
 var $99 = 0, $cond418 = 0, $cond419 = 0, $not$ = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = ($0|0)==(0|0);
 if ($1) {
  return;
 }
 $2 = ((($0)) + -8|0);
 $3 = HEAP32[(3744)>>2]|0;
 $4 = ($2>>>0)<($3>>>0);
 if ($4) {
  _abort();
  // unreachable;
 }
 $5 = ((($0)) + -4|0);
 $6 = HEAP32[$5>>2]|0;
 $7 = $6 & 3;
 $8 = ($7|0)==(1);
 if ($8) {
  _abort();
  // unreachable;
 }
 $9 = $6 & -8;
 $10 = (($2) + ($9)|0);
 $11 = $6 & 1;
 $12 = ($11|0)==(0);
 do {
  if ($12) {
   $13 = HEAP32[$2>>2]|0;
   $14 = ($7|0)==(0);
   if ($14) {
    return;
   }
   $15 = (0 - ($13))|0;
   $16 = (($2) + ($15)|0);
   $17 = (($13) + ($9))|0;
   $18 = ($16>>>0)<($3>>>0);
   if ($18) {
    _abort();
    // unreachable;
   }
   $19 = HEAP32[(3748)>>2]|0;
   $20 = ($16|0)==($19|0);
   if ($20) {
    $105 = ((($10)) + 4|0);
    $106 = HEAP32[$105>>2]|0;
    $107 = $106 & 3;
    $108 = ($107|0)==(3);
    if (!($108)) {
     $$1 = $16;$$1380 = $17;
     break;
    }
    HEAP32[(3736)>>2] = $17;
    $109 = $106 & -2;
    HEAP32[$105>>2] = $109;
    $110 = $17 | 1;
    $111 = ((($16)) + 4|0);
    HEAP32[$111>>2] = $110;
    $112 = (($16) + ($17)|0);
    HEAP32[$112>>2] = $17;
    return;
   }
   $21 = $13 >>> 3;
   $22 = ($13>>>0)<(256);
   if ($22) {
    $23 = ((($16)) + 8|0);
    $24 = HEAP32[$23>>2]|0;
    $25 = ((($16)) + 12|0);
    $26 = HEAP32[$25>>2]|0;
    $27 = $21 << 1;
    $28 = (3768 + ($27<<2)|0);
    $29 = ($24|0)==($28|0);
    if (!($29)) {
     $30 = ($24>>>0)<($3>>>0);
     if ($30) {
      _abort();
      // unreachable;
     }
     $31 = ((($24)) + 12|0);
     $32 = HEAP32[$31>>2]|0;
     $33 = ($32|0)==($16|0);
     if (!($33)) {
      _abort();
      // unreachable;
     }
    }
    $34 = ($26|0)==($24|0);
    if ($34) {
     $35 = 1 << $21;
     $36 = $35 ^ -1;
     $37 = HEAP32[932]|0;
     $38 = $37 & $36;
     HEAP32[932] = $38;
     $$1 = $16;$$1380 = $17;
     break;
    }
    $39 = ($26|0)==($28|0);
    if ($39) {
     $$pre440 = ((($26)) + 8|0);
     $$pre$phi441Z2D = $$pre440;
    } else {
     $40 = ($26>>>0)<($3>>>0);
     if ($40) {
      _abort();
      // unreachable;
     }
     $41 = ((($26)) + 8|0);
     $42 = HEAP32[$41>>2]|0;
     $43 = ($42|0)==($16|0);
     if ($43) {
      $$pre$phi441Z2D = $41;
     } else {
      _abort();
      // unreachable;
     }
    }
    $44 = ((($24)) + 12|0);
    HEAP32[$44>>2] = $26;
    HEAP32[$$pre$phi441Z2D>>2] = $24;
    $$1 = $16;$$1380 = $17;
    break;
   }
   $45 = ((($16)) + 24|0);
   $46 = HEAP32[$45>>2]|0;
   $47 = ((($16)) + 12|0);
   $48 = HEAP32[$47>>2]|0;
   $49 = ($48|0)==($16|0);
   do {
    if ($49) {
     $59 = ((($16)) + 16|0);
     $60 = ((($59)) + 4|0);
     $61 = HEAP32[$60>>2]|0;
     $62 = ($61|0)==(0|0);
     if ($62) {
      $63 = HEAP32[$59>>2]|0;
      $64 = ($63|0)==(0|0);
      if ($64) {
       $$3 = 0;
       break;
      } else {
       $$1385 = $63;$$1388 = $59;
      }
     } else {
      $$1385 = $61;$$1388 = $60;
     }
     while(1) {
      $65 = ((($$1385)) + 20|0);
      $66 = HEAP32[$65>>2]|0;
      $67 = ($66|0)==(0|0);
      if (!($67)) {
       $$1385 = $66;$$1388 = $65;
       continue;
      }
      $68 = ((($$1385)) + 16|0);
      $69 = HEAP32[$68>>2]|0;
      $70 = ($69|0)==(0|0);
      if ($70) {
       break;
      } else {
       $$1385 = $69;$$1388 = $68;
      }
     }
     $71 = ($$1388>>>0)<($3>>>0);
     if ($71) {
      _abort();
      // unreachable;
     } else {
      HEAP32[$$1388>>2] = 0;
      $$3 = $$1385;
      break;
     }
    } else {
     $50 = ((($16)) + 8|0);
     $51 = HEAP32[$50>>2]|0;
     $52 = ($51>>>0)<($3>>>0);
     if ($52) {
      _abort();
      // unreachable;
     }
     $53 = ((($51)) + 12|0);
     $54 = HEAP32[$53>>2]|0;
     $55 = ($54|0)==($16|0);
     if (!($55)) {
      _abort();
      // unreachable;
     }
     $56 = ((($48)) + 8|0);
     $57 = HEAP32[$56>>2]|0;
     $58 = ($57|0)==($16|0);
     if ($58) {
      HEAP32[$53>>2] = $48;
      HEAP32[$56>>2] = $51;
      $$3 = $48;
      break;
     } else {
      _abort();
      // unreachable;
     }
    }
   } while(0);
   $72 = ($46|0)==(0|0);
   if ($72) {
    $$1 = $16;$$1380 = $17;
   } else {
    $73 = ((($16)) + 28|0);
    $74 = HEAP32[$73>>2]|0;
    $75 = (4032 + ($74<<2)|0);
    $76 = HEAP32[$75>>2]|0;
    $77 = ($16|0)==($76|0);
    if ($77) {
     HEAP32[$75>>2] = $$3;
     $cond418 = ($$3|0)==(0|0);
     if ($cond418) {
      $78 = 1 << $74;
      $79 = $78 ^ -1;
      $80 = HEAP32[(3732)>>2]|0;
      $81 = $80 & $79;
      HEAP32[(3732)>>2] = $81;
      $$1 = $16;$$1380 = $17;
      break;
     }
    } else {
     $82 = HEAP32[(3744)>>2]|0;
     $83 = ($46>>>0)<($82>>>0);
     if ($83) {
      _abort();
      // unreachable;
     }
     $84 = ((($46)) + 16|0);
     $85 = HEAP32[$84>>2]|0;
     $86 = ($85|0)==($16|0);
     if ($86) {
      HEAP32[$84>>2] = $$3;
     } else {
      $87 = ((($46)) + 20|0);
      HEAP32[$87>>2] = $$3;
     }
     $88 = ($$3|0)==(0|0);
     if ($88) {
      $$1 = $16;$$1380 = $17;
      break;
     }
    }
    $89 = HEAP32[(3744)>>2]|0;
    $90 = ($$3>>>0)<($89>>>0);
    if ($90) {
     _abort();
     // unreachable;
    }
    $91 = ((($$3)) + 24|0);
    HEAP32[$91>>2] = $46;
    $92 = ((($16)) + 16|0);
    $93 = HEAP32[$92>>2]|0;
    $94 = ($93|0)==(0|0);
    do {
     if (!($94)) {
      $95 = ($93>>>0)<($89>>>0);
      if ($95) {
       _abort();
       // unreachable;
      } else {
       $96 = ((($$3)) + 16|0);
       HEAP32[$96>>2] = $93;
       $97 = ((($93)) + 24|0);
       HEAP32[$97>>2] = $$3;
       break;
      }
     }
    } while(0);
    $98 = ((($92)) + 4|0);
    $99 = HEAP32[$98>>2]|0;
    $100 = ($99|0)==(0|0);
    if ($100) {
     $$1 = $16;$$1380 = $17;
    } else {
     $101 = HEAP32[(3744)>>2]|0;
     $102 = ($99>>>0)<($101>>>0);
     if ($102) {
      _abort();
      // unreachable;
     } else {
      $103 = ((($$3)) + 20|0);
      HEAP32[$103>>2] = $99;
      $104 = ((($99)) + 24|0);
      HEAP32[$104>>2] = $$3;
      $$1 = $16;$$1380 = $17;
      break;
     }
    }
   }
  } else {
   $$1 = $2;$$1380 = $9;
  }
 } while(0);
 $113 = ($$1>>>0)<($10>>>0);
 if (!($113)) {
  _abort();
  // unreachable;
 }
 $114 = ((($10)) + 4|0);
 $115 = HEAP32[$114>>2]|0;
 $116 = $115 & 1;
 $117 = ($116|0)==(0);
 if ($117) {
  _abort();
  // unreachable;
 }
 $118 = $115 & 2;
 $119 = ($118|0)==(0);
 if ($119) {
  $120 = HEAP32[(3752)>>2]|0;
  $121 = ($10|0)==($120|0);
  if ($121) {
   $122 = HEAP32[(3740)>>2]|0;
   $123 = (($122) + ($$1380))|0;
   HEAP32[(3740)>>2] = $123;
   HEAP32[(3752)>>2] = $$1;
   $124 = $123 | 1;
   $125 = ((($$1)) + 4|0);
   HEAP32[$125>>2] = $124;
   $126 = HEAP32[(3748)>>2]|0;
   $127 = ($$1|0)==($126|0);
   if (!($127)) {
    return;
   }
   HEAP32[(3748)>>2] = 0;
   HEAP32[(3736)>>2] = 0;
   return;
  }
  $128 = HEAP32[(3748)>>2]|0;
  $129 = ($10|0)==($128|0);
  if ($129) {
   $130 = HEAP32[(3736)>>2]|0;
   $131 = (($130) + ($$1380))|0;
   HEAP32[(3736)>>2] = $131;
   HEAP32[(3748)>>2] = $$1;
   $132 = $131 | 1;
   $133 = ((($$1)) + 4|0);
   HEAP32[$133>>2] = $132;
   $134 = (($$1) + ($131)|0);
   HEAP32[$134>>2] = $131;
   return;
  }
  $135 = $115 & -8;
  $136 = (($135) + ($$1380))|0;
  $137 = $115 >>> 3;
  $138 = ($115>>>0)<(256);
  do {
   if ($138) {
    $139 = ((($10)) + 8|0);
    $140 = HEAP32[$139>>2]|0;
    $141 = ((($10)) + 12|0);
    $142 = HEAP32[$141>>2]|0;
    $143 = $137 << 1;
    $144 = (3768 + ($143<<2)|0);
    $145 = ($140|0)==($144|0);
    if (!($145)) {
     $146 = HEAP32[(3744)>>2]|0;
     $147 = ($140>>>0)<($146>>>0);
     if ($147) {
      _abort();
      // unreachable;
     }
     $148 = ((($140)) + 12|0);
     $149 = HEAP32[$148>>2]|0;
     $150 = ($149|0)==($10|0);
     if (!($150)) {
      _abort();
      // unreachable;
     }
    }
    $151 = ($142|0)==($140|0);
    if ($151) {
     $152 = 1 << $137;
     $153 = $152 ^ -1;
     $154 = HEAP32[932]|0;
     $155 = $154 & $153;
     HEAP32[932] = $155;
     break;
    }
    $156 = ($142|0)==($144|0);
    if ($156) {
     $$pre438 = ((($142)) + 8|0);
     $$pre$phi439Z2D = $$pre438;
    } else {
     $157 = HEAP32[(3744)>>2]|0;
     $158 = ($142>>>0)<($157>>>0);
     if ($158) {
      _abort();
      // unreachable;
     }
     $159 = ((($142)) + 8|0);
     $160 = HEAP32[$159>>2]|0;
     $161 = ($160|0)==($10|0);
     if ($161) {
      $$pre$phi439Z2D = $159;
     } else {
      _abort();
      // unreachable;
     }
    }
    $162 = ((($140)) + 12|0);
    HEAP32[$162>>2] = $142;
    HEAP32[$$pre$phi439Z2D>>2] = $140;
   } else {
    $163 = ((($10)) + 24|0);
    $164 = HEAP32[$163>>2]|0;
    $165 = ((($10)) + 12|0);
    $166 = HEAP32[$165>>2]|0;
    $167 = ($166|0)==($10|0);
    do {
     if ($167) {
      $178 = ((($10)) + 16|0);
      $179 = ((($178)) + 4|0);
      $180 = HEAP32[$179>>2]|0;
      $181 = ($180|0)==(0|0);
      if ($181) {
       $182 = HEAP32[$178>>2]|0;
       $183 = ($182|0)==(0|0);
       if ($183) {
        $$3398 = 0;
        break;
       } else {
        $$1396 = $182;$$1400 = $178;
       }
      } else {
       $$1396 = $180;$$1400 = $179;
      }
      while(1) {
       $184 = ((($$1396)) + 20|0);
       $185 = HEAP32[$184>>2]|0;
       $186 = ($185|0)==(0|0);
       if (!($186)) {
        $$1396 = $185;$$1400 = $184;
        continue;
       }
       $187 = ((($$1396)) + 16|0);
       $188 = HEAP32[$187>>2]|0;
       $189 = ($188|0)==(0|0);
       if ($189) {
        break;
       } else {
        $$1396 = $188;$$1400 = $187;
       }
      }
      $190 = HEAP32[(3744)>>2]|0;
      $191 = ($$1400>>>0)<($190>>>0);
      if ($191) {
       _abort();
       // unreachable;
      } else {
       HEAP32[$$1400>>2] = 0;
       $$3398 = $$1396;
       break;
      }
     } else {
      $168 = ((($10)) + 8|0);
      $169 = HEAP32[$168>>2]|0;
      $170 = HEAP32[(3744)>>2]|0;
      $171 = ($169>>>0)<($170>>>0);
      if ($171) {
       _abort();
       // unreachable;
      }
      $172 = ((($169)) + 12|0);
      $173 = HEAP32[$172>>2]|0;
      $174 = ($173|0)==($10|0);
      if (!($174)) {
       _abort();
       // unreachable;
      }
      $175 = ((($166)) + 8|0);
      $176 = HEAP32[$175>>2]|0;
      $177 = ($176|0)==($10|0);
      if ($177) {
       HEAP32[$172>>2] = $166;
       HEAP32[$175>>2] = $169;
       $$3398 = $166;
       break;
      } else {
       _abort();
       // unreachable;
      }
     }
    } while(0);
    $192 = ($164|0)==(0|0);
    if (!($192)) {
     $193 = ((($10)) + 28|0);
     $194 = HEAP32[$193>>2]|0;
     $195 = (4032 + ($194<<2)|0);
     $196 = HEAP32[$195>>2]|0;
     $197 = ($10|0)==($196|0);
     if ($197) {
      HEAP32[$195>>2] = $$3398;
      $cond419 = ($$3398|0)==(0|0);
      if ($cond419) {
       $198 = 1 << $194;
       $199 = $198 ^ -1;
       $200 = HEAP32[(3732)>>2]|0;
       $201 = $200 & $199;
       HEAP32[(3732)>>2] = $201;
       break;
      }
     } else {
      $202 = HEAP32[(3744)>>2]|0;
      $203 = ($164>>>0)<($202>>>0);
      if ($203) {
       _abort();
       // unreachable;
      }
      $204 = ((($164)) + 16|0);
      $205 = HEAP32[$204>>2]|0;
      $206 = ($205|0)==($10|0);
      if ($206) {
       HEAP32[$204>>2] = $$3398;
      } else {
       $207 = ((($164)) + 20|0);
       HEAP32[$207>>2] = $$3398;
      }
      $208 = ($$3398|0)==(0|0);
      if ($208) {
       break;
      }
     }
     $209 = HEAP32[(3744)>>2]|0;
     $210 = ($$3398>>>0)<($209>>>0);
     if ($210) {
      _abort();
      // unreachable;
     }
     $211 = ((($$3398)) + 24|0);
     HEAP32[$211>>2] = $164;
     $212 = ((($10)) + 16|0);
     $213 = HEAP32[$212>>2]|0;
     $214 = ($213|0)==(0|0);
     do {
      if (!($214)) {
       $215 = ($213>>>0)<($209>>>0);
       if ($215) {
        _abort();
        // unreachable;
       } else {
        $216 = ((($$3398)) + 16|0);
        HEAP32[$216>>2] = $213;
        $217 = ((($213)) + 24|0);
        HEAP32[$217>>2] = $$3398;
        break;
       }
      }
     } while(0);
     $218 = ((($212)) + 4|0);
     $219 = HEAP32[$218>>2]|0;
     $220 = ($219|0)==(0|0);
     if (!($220)) {
      $221 = HEAP32[(3744)>>2]|0;
      $222 = ($219>>>0)<($221>>>0);
      if ($222) {
       _abort();
       // unreachable;
      } else {
       $223 = ((($$3398)) + 20|0);
       HEAP32[$223>>2] = $219;
       $224 = ((($219)) + 24|0);
       HEAP32[$224>>2] = $$3398;
       break;
      }
     }
    }
   }
  } while(0);
  $225 = $136 | 1;
  $226 = ((($$1)) + 4|0);
  HEAP32[$226>>2] = $225;
  $227 = (($$1) + ($136)|0);
  HEAP32[$227>>2] = $136;
  $228 = HEAP32[(3748)>>2]|0;
  $229 = ($$1|0)==($228|0);
  if ($229) {
   HEAP32[(3736)>>2] = $136;
   return;
  } else {
   $$2 = $136;
  }
 } else {
  $230 = $115 & -2;
  HEAP32[$114>>2] = $230;
  $231 = $$1380 | 1;
  $232 = ((($$1)) + 4|0);
  HEAP32[$232>>2] = $231;
  $233 = (($$1) + ($$1380)|0);
  HEAP32[$233>>2] = $$1380;
  $$2 = $$1380;
 }
 $234 = $$2 >>> 3;
 $235 = ($$2>>>0)<(256);
 if ($235) {
  $236 = $234 << 1;
  $237 = (3768 + ($236<<2)|0);
  $238 = HEAP32[932]|0;
  $239 = 1 << $234;
  $240 = $238 & $239;
  $241 = ($240|0)==(0);
  if ($241) {
   $242 = $238 | $239;
   HEAP32[932] = $242;
   $$pre = ((($237)) + 8|0);
   $$0401 = $237;$$pre$phiZ2D = $$pre;
  } else {
   $243 = ((($237)) + 8|0);
   $244 = HEAP32[$243>>2]|0;
   $245 = HEAP32[(3744)>>2]|0;
   $246 = ($244>>>0)<($245>>>0);
   if ($246) {
    _abort();
    // unreachable;
   } else {
    $$0401 = $244;$$pre$phiZ2D = $243;
   }
  }
  HEAP32[$$pre$phiZ2D>>2] = $$1;
  $247 = ((($$0401)) + 12|0);
  HEAP32[$247>>2] = $$1;
  $248 = ((($$1)) + 8|0);
  HEAP32[$248>>2] = $$0401;
  $249 = ((($$1)) + 12|0);
  HEAP32[$249>>2] = $237;
  return;
 }
 $250 = $$2 >>> 8;
 $251 = ($250|0)==(0);
 if ($251) {
  $$0394 = 0;
 } else {
  $252 = ($$2>>>0)>(16777215);
  if ($252) {
   $$0394 = 31;
  } else {
   $253 = (($250) + 1048320)|0;
   $254 = $253 >>> 16;
   $255 = $254 & 8;
   $256 = $250 << $255;
   $257 = (($256) + 520192)|0;
   $258 = $257 >>> 16;
   $259 = $258 & 4;
   $260 = $259 | $255;
   $261 = $256 << $259;
   $262 = (($261) + 245760)|0;
   $263 = $262 >>> 16;
   $264 = $263 & 2;
   $265 = $260 | $264;
   $266 = (14 - ($265))|0;
   $267 = $261 << $264;
   $268 = $267 >>> 15;
   $269 = (($266) + ($268))|0;
   $270 = $269 << 1;
   $271 = (($269) + 7)|0;
   $272 = $$2 >>> $271;
   $273 = $272 & 1;
   $274 = $273 | $270;
   $$0394 = $274;
  }
 }
 $275 = (4032 + ($$0394<<2)|0);
 $276 = ((($$1)) + 28|0);
 HEAP32[$276>>2] = $$0394;
 $277 = ((($$1)) + 16|0);
 $278 = ((($$1)) + 20|0);
 HEAP32[$278>>2] = 0;
 HEAP32[$277>>2] = 0;
 $279 = HEAP32[(3732)>>2]|0;
 $280 = 1 << $$0394;
 $281 = $279 & $280;
 $282 = ($281|0)==(0);
 do {
  if ($282) {
   $283 = $279 | $280;
   HEAP32[(3732)>>2] = $283;
   HEAP32[$275>>2] = $$1;
   $284 = ((($$1)) + 24|0);
   HEAP32[$284>>2] = $275;
   $285 = ((($$1)) + 12|0);
   HEAP32[$285>>2] = $$1;
   $286 = ((($$1)) + 8|0);
   HEAP32[$286>>2] = $$1;
  } else {
   $287 = HEAP32[$275>>2]|0;
   $288 = ($$0394|0)==(31);
   $289 = $$0394 >>> 1;
   $290 = (25 - ($289))|0;
   $291 = $288 ? 0 : $290;
   $292 = $$2 << $291;
   $$0381 = $292;$$0382 = $287;
   while(1) {
    $293 = ((($$0382)) + 4|0);
    $294 = HEAP32[$293>>2]|0;
    $295 = $294 & -8;
    $296 = ($295|0)==($$2|0);
    if ($296) {
     label = 130;
     break;
    }
    $297 = $$0381 >>> 31;
    $298 = (((($$0382)) + 16|0) + ($297<<2)|0);
    $299 = $$0381 << 1;
    $300 = HEAP32[$298>>2]|0;
    $301 = ($300|0)==(0|0);
    if ($301) {
     label = 127;
     break;
    } else {
     $$0381 = $299;$$0382 = $300;
    }
   }
   if ((label|0) == 127) {
    $302 = HEAP32[(3744)>>2]|0;
    $303 = ($298>>>0)<($302>>>0);
    if ($303) {
     _abort();
     // unreachable;
    } else {
     HEAP32[$298>>2] = $$1;
     $304 = ((($$1)) + 24|0);
     HEAP32[$304>>2] = $$0382;
     $305 = ((($$1)) + 12|0);
     HEAP32[$305>>2] = $$1;
     $306 = ((($$1)) + 8|0);
     HEAP32[$306>>2] = $$1;
     break;
    }
   }
   else if ((label|0) == 130) {
    $307 = ((($$0382)) + 8|0);
    $308 = HEAP32[$307>>2]|0;
    $309 = HEAP32[(3744)>>2]|0;
    $310 = ($308>>>0)>=($309>>>0);
    $not$ = ($$0382>>>0)>=($309>>>0);
    $311 = $310 & $not$;
    if ($311) {
     $312 = ((($308)) + 12|0);
     HEAP32[$312>>2] = $$1;
     HEAP32[$307>>2] = $$1;
     $313 = ((($$1)) + 8|0);
     HEAP32[$313>>2] = $308;
     $314 = ((($$1)) + 12|0);
     HEAP32[$314>>2] = $$0382;
     $315 = ((($$1)) + 24|0);
     HEAP32[$315>>2] = 0;
     break;
    } else {
     _abort();
     // unreachable;
    }
   }
  }
 } while(0);
 $316 = HEAP32[(3760)>>2]|0;
 $317 = (($316) + -1)|0;
 HEAP32[(3760)>>2] = $317;
 $318 = ($317|0)==(0);
 if ($318) {
  $$0211$in$i = (4184);
 } else {
  return;
 }
 while(1) {
  $$0211$i = HEAP32[$$0211$in$i>>2]|0;
  $319 = ($$0211$i|0)==(0|0);
  $320 = ((($$0211$i)) + 8|0);
  if ($319) {
   break;
  } else {
   $$0211$in$i = $320;
  }
 }
 HEAP32[(3760)>>2] = -1;
 return;
}
function __ZdlPv($0) {
 $0 = $0|0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 _free($0);
 return;
}
function __ZNSt3__212basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = ((($0)) + 11|0);
 $2 = HEAP8[$1>>0]|0;
 $3 = ($2<<24>>24)<(0);
 if ($3) {
  $4 = HEAP32[$0>>2]|0;
  __ZdlPv($4);
 }
 return;
}
function __ZL25default_terminate_handlerv() {
 var $0 = 0, $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0;
 var $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $vararg_buffer = 0, $vararg_buffer10 = 0;
 var $vararg_buffer3 = 0, $vararg_buffer7 = 0, $vararg_ptr1 = 0, $vararg_ptr2 = 0, $vararg_ptr6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 48|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(48|0);
 $vararg_buffer10 = sp + 32|0;
 $vararg_buffer7 = sp + 24|0;
 $vararg_buffer3 = sp + 16|0;
 $vararg_buffer = sp;
 $0 = sp + 36|0;
 $1 = (___cxa_get_globals_fast()|0);
 $2 = ($1|0)==(0|0);
 if (!($2)) {
  $3 = HEAP32[$1>>2]|0;
  $4 = ($3|0)==(0|0);
  if (!($4)) {
   $5 = ((($3)) + 80|0);
   $6 = ((($3)) + 48|0);
   $7 = $6;
   $8 = $7;
   $9 = HEAP32[$8>>2]|0;
   $10 = (($7) + 4)|0;
   $11 = $10;
   $12 = HEAP32[$11>>2]|0;
   $13 = $9 & -256;
   $14 = ($13|0)==(1126902528);
   $15 = ($12|0)==(1129074247);
   $16 = $14 & $15;
   if (!($16)) {
    $37 = HEAP32[85]|0;
    HEAP32[$vararg_buffer7>>2] = $37;
    _abort_message(2936,$vararg_buffer7);
    // unreachable;
   }
   $17 = ($9|0)==(1126902529);
   $18 = ($12|0)==(1129074247);
   $19 = $17 & $18;
   if ($19) {
    $20 = ((($3)) + 44|0);
    $21 = HEAP32[$20>>2]|0;
    $22 = $21;
   } else {
    $22 = $5;
   }
   HEAP32[$0>>2] = $22;
   $23 = HEAP32[$3>>2]|0;
   $24 = ((($23)) + 4|0);
   $25 = HEAP32[$24>>2]|0;
   $26 = HEAP32[2]|0;
   $27 = ((($26)) + 16|0);
   $28 = HEAP32[$27>>2]|0;
   $29 = (FUNCTION_TABLE_iiii[$28 & 15](8,$23,$0)|0);
   if ($29) {
    $30 = HEAP32[$0>>2]|0;
    $31 = HEAP32[85]|0;
    $32 = HEAP32[$30>>2]|0;
    $33 = ((($32)) + 8|0);
    $34 = HEAP32[$33>>2]|0;
    $35 = (FUNCTION_TABLE_ii[$34 & 1]($30)|0);
    HEAP32[$vararg_buffer>>2] = $31;
    $vararg_ptr1 = ((($vararg_buffer)) + 4|0);
    HEAP32[$vararg_ptr1>>2] = $25;
    $vararg_ptr2 = ((($vararg_buffer)) + 8|0);
    HEAP32[$vararg_ptr2>>2] = $35;
    _abort_message(2850,$vararg_buffer);
    // unreachable;
   } else {
    $36 = HEAP32[85]|0;
    HEAP32[$vararg_buffer3>>2] = $36;
    $vararg_ptr6 = ((($vararg_buffer3)) + 4|0);
    HEAP32[$vararg_ptr6>>2] = $25;
    _abort_message(2895,$vararg_buffer3);
    // unreachable;
   }
  }
 }
 _abort_message(2974,$vararg_buffer10);
 // unreachable;
}
function ___cxa_get_globals_fast() {
 var $0 = 0, $1 = 0, $2 = 0, $3 = 0, $vararg_buffer = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $vararg_buffer = sp;
 $0 = (_pthread_once((4224|0),(20|0))|0);
 $1 = ($0|0)==(0);
 if ($1) {
  $2 = HEAP32[1057]|0;
  $3 = (_pthread_getspecific(($2|0))|0);
  STACKTOP = sp;return ($3|0);
 } else {
  _abort_message(3125,$vararg_buffer);
  // unreachable;
 }
 return (0)|0;
}
function _abort_message($0,$varargs) {
 $0 = $0|0;
 $varargs = $varargs|0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $1 = sp;
 HEAP32[$1>>2] = $varargs;
 $2 = HEAP32[55]|0;
 (_vfprintf($2,$0,$1)|0);
 (_fputc(10,$2)|0);
 _abort();
 // unreachable;
}
function __ZN10__cxxabiv116__shim_type_infoD2Ev($0) {
 $0 = $0|0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 return;
}
function __ZN10__cxxabiv117__class_type_infoD0Ev($0) {
 $0 = $0|0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZdlPv($0);
 return;
}
function __ZNK10__cxxabiv116__shim_type_info5noop1Ev($0) {
 $0 = $0|0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 return;
}
function __ZNK10__cxxabiv116__shim_type_info5noop2Ev($0) {
 $0 = $0|0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 return;
}
function __ZNK10__cxxabiv117__class_type_info9can_catchEPKNS_16__shim_type_infoERPv($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $$0 = 0, $$2 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0;
 var dest = 0, label = 0, sp = 0, stop = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 64|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(64|0);
 $3 = sp;
 $4 = ($0|0)==($1|0);
 if ($4) {
  $$2 = 1;
 } else {
  $5 = ($1|0)==(0|0);
  if ($5) {
   $$2 = 0;
  } else {
   $6 = (___dynamic_cast($1,32,16,0)|0);
   $7 = ($6|0)==(0|0);
   if ($7) {
    $$2 = 0;
   } else {
    $8 = ((($3)) + 4|0);
    dest=$8; stop=dest+52|0; do { HEAP32[dest>>2]=0|0; dest=dest+4|0; } while ((dest|0) < (stop|0));
    HEAP32[$3>>2] = $6;
    $9 = ((($3)) + 8|0);
    HEAP32[$9>>2] = $0;
    $10 = ((($3)) + 12|0);
    HEAP32[$10>>2] = -1;
    $11 = ((($3)) + 48|0);
    HEAP32[$11>>2] = 1;
    $12 = HEAP32[$6>>2]|0;
    $13 = ((($12)) + 28|0);
    $14 = HEAP32[$13>>2]|0;
    $15 = HEAP32[$2>>2]|0;
    FUNCTION_TABLE_viiii[$14 & 31]($6,$3,$15,1);
    $16 = ((($3)) + 24|0);
    $17 = HEAP32[$16>>2]|0;
    $18 = ($17|0)==(1);
    if ($18) {
     $19 = ((($3)) + 16|0);
     $20 = HEAP32[$19>>2]|0;
     HEAP32[$2>>2] = $20;
     $$0 = 1;
    } else {
     $$0 = 0;
    }
    $$2 = $$0;
   }
  }
 }
 STACKTOP = sp;return ($$2|0);
}
function __ZNK10__cxxabiv117__class_type_info16search_above_dstEPNS_19__dynamic_cast_infoEPKvS4_ib($0,$1,$2,$3,$4,$5) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 $4 = $4|0;
 $5 = $5|0;
 var $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $6 = ((($1)) + 8|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = ($0|0)==($7|0);
 if ($8) {
  __ZNK10__cxxabiv117__class_type_info29process_static_type_above_dstEPNS_19__dynamic_cast_infoEPKvS4_i(0,$1,$2,$3,$4);
 }
 return;
}
function __ZNK10__cxxabiv117__class_type_info16search_below_dstEPNS_19__dynamic_cast_infoEPKvib($0,$1,$2,$3,$4) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 $4 = $4|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0;
 var $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $5 = ((($1)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 $7 = ($0|0)==($6|0);
 do {
  if ($7) {
   $8 = ((($1)) + 4|0);
   $9 = HEAP32[$8>>2]|0;
   $10 = ($9|0)==($2|0);
   if ($10) {
    $11 = ((($1)) + 28|0);
    $12 = HEAP32[$11>>2]|0;
    $13 = ($12|0)==(1);
    if (!($13)) {
     HEAP32[$11>>2] = $3;
    }
   }
  } else {
   $14 = HEAP32[$1>>2]|0;
   $15 = ($0|0)==($14|0);
   if ($15) {
    $16 = ((($1)) + 16|0);
    $17 = HEAP32[$16>>2]|0;
    $18 = ($17|0)==($2|0);
    if (!($18)) {
     $19 = ((($1)) + 20|0);
     $20 = HEAP32[$19>>2]|0;
     $21 = ($20|0)==($2|0);
     if (!($21)) {
      $24 = ((($1)) + 32|0);
      HEAP32[$24>>2] = $3;
      HEAP32[$19>>2] = $2;
      $25 = ((($1)) + 40|0);
      $26 = HEAP32[$25>>2]|0;
      $27 = (($26) + 1)|0;
      HEAP32[$25>>2] = $27;
      $28 = ((($1)) + 36|0);
      $29 = HEAP32[$28>>2]|0;
      $30 = ($29|0)==(1);
      if ($30) {
       $31 = ((($1)) + 24|0);
       $32 = HEAP32[$31>>2]|0;
       $33 = ($32|0)==(2);
       if ($33) {
        $34 = ((($1)) + 54|0);
        HEAP8[$34>>0] = 1;
       }
      }
      $35 = ((($1)) + 44|0);
      HEAP32[$35>>2] = 4;
      break;
     }
    }
    $22 = ($3|0)==(1);
    if ($22) {
     $23 = ((($1)) + 32|0);
     HEAP32[$23>>2] = 1;
    }
   }
  }
 } while(0);
 return;
}
function __ZNK10__cxxabiv117__class_type_info27has_unambiguous_public_baseEPNS_19__dynamic_cast_infoEPvi($0,$1,$2,$3) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 var $4 = 0, $5 = 0, $6 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $4 = ((($1)) + 8|0);
 $5 = HEAP32[$4>>2]|0;
 $6 = ($0|0)==($5|0);
 if ($6) {
  __ZNK10__cxxabiv117__class_type_info24process_found_base_classEPNS_19__dynamic_cast_infoEPvi(0,$1,$2,$3);
 }
 return;
}
function __ZNK10__cxxabiv117__class_type_info24process_found_base_classEPNS_19__dynamic_cast_infoEPvi($0,$1,$2,$3) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $4 = ((($1)) + 16|0);
 $5 = HEAP32[$4>>2]|0;
 $6 = ($5|0)==(0|0);
 do {
  if ($6) {
   HEAP32[$4>>2] = $2;
   $7 = ((($1)) + 24|0);
   HEAP32[$7>>2] = $3;
   $8 = ((($1)) + 36|0);
   HEAP32[$8>>2] = 1;
  } else {
   $9 = ($5|0)==($2|0);
   if (!($9)) {
    $13 = ((($1)) + 36|0);
    $14 = HEAP32[$13>>2]|0;
    $15 = (($14) + 1)|0;
    HEAP32[$13>>2] = $15;
    $16 = ((($1)) + 24|0);
    HEAP32[$16>>2] = 2;
    $17 = ((($1)) + 54|0);
    HEAP8[$17>>0] = 1;
    break;
   }
   $10 = ((($1)) + 24|0);
   $11 = HEAP32[$10>>2]|0;
   $12 = ($11|0)==(2);
   if ($12) {
    HEAP32[$10>>2] = $3;
   }
  }
 } while(0);
 return;
}
function __ZNK10__cxxabiv117__class_type_info29process_static_type_above_dstEPNS_19__dynamic_cast_infoEPKvS4_i($0,$1,$2,$3,$4) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 $4 = $4|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0;
 var $30 = 0, $31 = 0, $32 = 0, $33 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, $or$cond22 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $5 = ((($1)) + 53|0);
 HEAP8[$5>>0] = 1;
 $6 = ((($1)) + 4|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = ($7|0)==($3|0);
 do {
  if ($8) {
   $9 = ((($1)) + 52|0);
   HEAP8[$9>>0] = 1;
   $10 = ((($1)) + 16|0);
   $11 = HEAP32[$10>>2]|0;
   $12 = ($11|0)==(0|0);
   if ($12) {
    HEAP32[$10>>2] = $2;
    $13 = ((($1)) + 24|0);
    HEAP32[$13>>2] = $4;
    $14 = ((($1)) + 36|0);
    HEAP32[$14>>2] = 1;
    $15 = ((($1)) + 48|0);
    $16 = HEAP32[$15>>2]|0;
    $17 = ($16|0)==(1);
    $18 = ($4|0)==(1);
    $or$cond = $17 & $18;
    if (!($or$cond)) {
     break;
    }
    $19 = ((($1)) + 54|0);
    HEAP8[$19>>0] = 1;
    break;
   }
   $20 = ($11|0)==($2|0);
   if (!($20)) {
    $30 = ((($1)) + 36|0);
    $31 = HEAP32[$30>>2]|0;
    $32 = (($31) + 1)|0;
    HEAP32[$30>>2] = $32;
    $33 = ((($1)) + 54|0);
    HEAP8[$33>>0] = 1;
    break;
   }
   $21 = ((($1)) + 24|0);
   $22 = HEAP32[$21>>2]|0;
   $23 = ($22|0)==(2);
   if ($23) {
    HEAP32[$21>>2] = $4;
    $27 = $4;
   } else {
    $27 = $22;
   }
   $24 = ((($1)) + 48|0);
   $25 = HEAP32[$24>>2]|0;
   $26 = ($25|0)==(1);
   $28 = ($27|0)==(1);
   $or$cond22 = $26 & $28;
   if ($or$cond22) {
    $29 = ((($1)) + 54|0);
    HEAP8[$29>>0] = 1;
   }
  }
 } while(0);
 return;
}
function ___dynamic_cast($0,$1,$2,$3) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 var $$ = 0, $$0 = 0, $$33 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0;
 var $27 = 0, $28 = 0, $29 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0;
 var $46 = 0, $47 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, $or$cond28 = 0, $or$cond30 = 0, $or$cond32 = 0, dest = 0, label = 0, sp = 0, stop = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 64|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(64|0);
 $4 = sp;
 $5 = HEAP32[$0>>2]|0;
 $6 = ((($5)) + -8|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = (($0) + ($7)|0);
 $9 = ((($5)) + -4|0);
 $10 = HEAP32[$9>>2]|0;
 HEAP32[$4>>2] = $2;
 $11 = ((($4)) + 4|0);
 HEAP32[$11>>2] = $0;
 $12 = ((($4)) + 8|0);
 HEAP32[$12>>2] = $1;
 $13 = ((($4)) + 12|0);
 HEAP32[$13>>2] = $3;
 $14 = ((($4)) + 16|0);
 $15 = ((($4)) + 20|0);
 $16 = ((($4)) + 24|0);
 $17 = ((($4)) + 28|0);
 $18 = ((($4)) + 32|0);
 $19 = ((($4)) + 40|0);
 $20 = ($10|0)==($2|0);
 dest=$14; stop=dest+36|0; do { HEAP32[dest>>2]=0|0; dest=dest+4|0; } while ((dest|0) < (stop|0));HEAP16[$14+36>>1]=0|0;HEAP8[$14+38>>0]=0|0;
 L1: do {
  if ($20) {
   $21 = ((($4)) + 48|0);
   HEAP32[$21>>2] = 1;
   $22 = HEAP32[$2>>2]|0;
   $23 = ((($22)) + 20|0);
   $24 = HEAP32[$23>>2]|0;
   FUNCTION_TABLE_viiiiii[$24 & 15]($2,$4,$8,$8,1,0);
   $25 = HEAP32[$16>>2]|0;
   $26 = ($25|0)==(1);
   $$ = $26 ? $8 : 0;
   $$0 = $$;
  } else {
   $27 = ((($4)) + 36|0);
   $28 = HEAP32[$10>>2]|0;
   $29 = ((($28)) + 24|0);
   $30 = HEAP32[$29>>2]|0;
   FUNCTION_TABLE_viiiii[$30 & 31]($10,$4,$8,1,0);
   $31 = HEAP32[$27>>2]|0;
   switch ($31|0) {
   case 0:  {
    $32 = HEAP32[$19>>2]|0;
    $33 = ($32|0)==(1);
    $34 = HEAP32[$17>>2]|0;
    $35 = ($34|0)==(1);
    $or$cond = $33 & $35;
    $36 = HEAP32[$18>>2]|0;
    $37 = ($36|0)==(1);
    $or$cond28 = $or$cond & $37;
    $38 = HEAP32[$15>>2]|0;
    $$33 = $or$cond28 ? $38 : 0;
    $$0 = $$33;
    break L1;
    break;
   }
   case 1:  {
    break;
   }
   default: {
    $$0 = 0;
    break L1;
   }
   }
   $39 = HEAP32[$16>>2]|0;
   $40 = ($39|0)==(1);
   if (!($40)) {
    $41 = HEAP32[$19>>2]|0;
    $42 = ($41|0)==(0);
    $43 = HEAP32[$17>>2]|0;
    $44 = ($43|0)==(1);
    $or$cond30 = $42 & $44;
    $45 = HEAP32[$18>>2]|0;
    $46 = ($45|0)==(1);
    $or$cond32 = $or$cond30 & $46;
    if (!($or$cond32)) {
     $$0 = 0;
     break;
    }
   }
   $47 = HEAP32[$14>>2]|0;
   $$0 = $47;
  }
 } while(0);
 STACKTOP = sp;return ($$0|0);
}
function __ZN10__cxxabiv120__si_class_type_infoD0Ev($0) {
 $0 = $0|0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 __ZdlPv($0);
 return;
}
function __ZNK10__cxxabiv120__si_class_type_info16search_above_dstEPNS_19__dynamic_cast_infoEPKvS4_ib($0,$1,$2,$3,$4,$5) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 $4 = $4|0;
 $5 = $5|0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $6 = ((($1)) + 8|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = ($0|0)==($7|0);
 if ($8) {
  __ZNK10__cxxabiv117__class_type_info29process_static_type_above_dstEPNS_19__dynamic_cast_infoEPKvS4_i(0,$1,$2,$3,$4);
 } else {
  $9 = ((($0)) + 8|0);
  $10 = HEAP32[$9>>2]|0;
  $11 = HEAP32[$10>>2]|0;
  $12 = ((($11)) + 20|0);
  $13 = HEAP32[$12>>2]|0;
  FUNCTION_TABLE_viiiiii[$13 & 15]($10,$1,$2,$3,$4,$5);
 }
 return;
}
function __ZNK10__cxxabiv120__si_class_type_info16search_below_dstEPNS_19__dynamic_cast_infoEPKvib($0,$1,$2,$3,$4) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 $4 = $4|0;
 var $$037$off039 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0;
 var $29 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0;
 var $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $not$ = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $5 = ((($1)) + 8|0);
 $6 = HEAP32[$5>>2]|0;
 $7 = ($0|0)==($6|0);
 do {
  if ($7) {
   $8 = ((($1)) + 4|0);
   $9 = HEAP32[$8>>2]|0;
   $10 = ($9|0)==($2|0);
   if ($10) {
    $11 = ((($1)) + 28|0);
    $12 = HEAP32[$11>>2]|0;
    $13 = ($12|0)==(1);
    if (!($13)) {
     HEAP32[$11>>2] = $3;
    }
   }
  } else {
   $14 = HEAP32[$1>>2]|0;
   $15 = ($0|0)==($14|0);
   if (!($15)) {
    $49 = ((($0)) + 8|0);
    $50 = HEAP32[$49>>2]|0;
    $51 = HEAP32[$50>>2]|0;
    $52 = ((($51)) + 24|0);
    $53 = HEAP32[$52>>2]|0;
    FUNCTION_TABLE_viiiii[$53 & 31]($50,$1,$2,$3,$4);
    break;
   }
   $16 = ((($1)) + 16|0);
   $17 = HEAP32[$16>>2]|0;
   $18 = ($17|0)==($2|0);
   if (!($18)) {
    $19 = ((($1)) + 20|0);
    $20 = HEAP32[$19>>2]|0;
    $21 = ($20|0)==($2|0);
    if (!($21)) {
     $24 = ((($1)) + 32|0);
     HEAP32[$24>>2] = $3;
     $25 = ((($1)) + 44|0);
     $26 = HEAP32[$25>>2]|0;
     $27 = ($26|0)==(4);
     if ($27) {
      break;
     }
     $28 = ((($1)) + 52|0);
     HEAP8[$28>>0] = 0;
     $29 = ((($1)) + 53|0);
     HEAP8[$29>>0] = 0;
     $30 = ((($0)) + 8|0);
     $31 = HEAP32[$30>>2]|0;
     $32 = HEAP32[$31>>2]|0;
     $33 = ((($32)) + 20|0);
     $34 = HEAP32[$33>>2]|0;
     FUNCTION_TABLE_viiiiii[$34 & 15]($31,$1,$2,$2,1,$4);
     $35 = HEAP8[$29>>0]|0;
     $36 = ($35<<24>>24)==(0);
     if ($36) {
      $$037$off039 = 0;
      label = 13;
     } else {
      $37 = HEAP8[$28>>0]|0;
      $not$ = ($37<<24>>24)==(0);
      if ($not$) {
       $$037$off039 = 1;
       label = 13;
      } else {
       label = 17;
      }
     }
     do {
      if ((label|0) == 13) {
       HEAP32[$19>>2] = $2;
       $38 = ((($1)) + 40|0);
       $39 = HEAP32[$38>>2]|0;
       $40 = (($39) + 1)|0;
       HEAP32[$38>>2] = $40;
       $41 = ((($1)) + 36|0);
       $42 = HEAP32[$41>>2]|0;
       $43 = ($42|0)==(1);
       if ($43) {
        $44 = ((($1)) + 24|0);
        $45 = HEAP32[$44>>2]|0;
        $46 = ($45|0)==(2);
        if ($46) {
         $47 = ((($1)) + 54|0);
         HEAP8[$47>>0] = 1;
         if ($$037$off039) {
          label = 17;
          break;
         } else {
          $48 = 4;
          break;
         }
        }
       }
       if ($$037$off039) {
        label = 17;
       } else {
        $48 = 4;
       }
      }
     } while(0);
     if ((label|0) == 17) {
      $48 = 3;
     }
     HEAP32[$25>>2] = $48;
     break;
    }
   }
   $22 = ($3|0)==(1);
   if ($22) {
    $23 = ((($1)) + 32|0);
    HEAP32[$23>>2] = 1;
   }
  }
 } while(0);
 return;
}
function __ZNK10__cxxabiv120__si_class_type_info27has_unambiguous_public_baseEPNS_19__dynamic_cast_infoEPvi($0,$1,$2,$3) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 $3 = $3|0;
 var $10 = 0, $11 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $4 = ((($1)) + 8|0);
 $5 = HEAP32[$4>>2]|0;
 $6 = ($0|0)==($5|0);
 if ($6) {
  __ZNK10__cxxabiv117__class_type_info24process_found_base_classEPNS_19__dynamic_cast_infoEPvi(0,$1,$2,$3);
 } else {
  $7 = ((($0)) + 8|0);
  $8 = HEAP32[$7>>2]|0;
  $9 = HEAP32[$8>>2]|0;
  $10 = ((($9)) + 28|0);
  $11 = HEAP32[$10>>2]|0;
  FUNCTION_TABLE_viiii[$11 & 31]($8,$1,$2,$3);
 }
 return;
}
function __ZNSt9type_infoD2Ev($0) {
 $0 = $0|0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 return;
}
function __ZN10__cxxabiv112_GLOBAL__N_110construct_Ev() {
 var $0 = 0, $1 = 0, $vararg_buffer = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $vararg_buffer = sp;
 $0 = (_pthread_key_create((4228|0),(21|0))|0);
 $1 = ($0|0)==(0);
 if ($1) {
  STACKTOP = sp;return;
 } else {
  _abort_message(3174,$vararg_buffer);
  // unreachable;
 }
}
function __ZN10__cxxabiv112_GLOBAL__N_19destruct_EPv($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $vararg_buffer = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $vararg_buffer = sp;
 _free($0);
 $1 = HEAP32[1057]|0;
 $2 = (_pthread_setspecific(($1|0),(0|0))|0);
 $3 = ($2|0)==(0);
 if ($3) {
  STACKTOP = sp;return;
 } else {
  _abort_message(3224,$vararg_buffer);
  // unreachable;
 }
}
function __ZSt9terminatev() {
 var $0 = 0, $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0;
 var $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 __THREW__ = 0;
 $0 = (invoke_i(22)|0);
 $1 = __THREW__; __THREW__ = 0;
 $2 = $1&1;
 if ($2) {
  $20 = ___cxa_find_matching_catch_3(0|0)|0;
  $21 = tempRet0;
  ___clang_call_terminate($20);
  // unreachable;
 }
 $3 = ($0|0)==(0|0);
 if (!($3)) {
  $4 = HEAP32[$0>>2]|0;
  $5 = ($4|0)==(0|0);
  if (!($5)) {
   $6 = ((($4)) + 48|0);
   $7 = $6;
   $8 = $7;
   $9 = HEAP32[$8>>2]|0;
   $10 = (($7) + 4)|0;
   $11 = $10;
   $12 = HEAP32[$11>>2]|0;
   $13 = $9 & -256;
   $14 = ($13|0)==(1126902528);
   $15 = ($12|0)==(1129074247);
   $16 = $14 & $15;
   if ($16) {
    $17 = ((($4)) + 12|0);
    $18 = HEAP32[$17>>2]|0;
    __ZSt11__terminatePFvvE($18);
    // unreachable;
   }
  }
 }
 $19 = (__ZSt13get_terminatev()|0);
 __ZSt11__terminatePFvvE($19);
 // unreachable;
}
function __ZSt11__terminatePFvvE($0) {
 $0 = $0|0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $vararg_buffer = 0, $vararg_buffer1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $vararg_buffer1 = sp + 8|0;
 $vararg_buffer = sp;
 __THREW__ = 0;
 invoke_v($0|0);
 $1 = __THREW__; __THREW__ = 0;
 $2 = $1&1;
 if (!($2)) {
  __THREW__ = 0;
  invoke_vii(23,(3277|0),($vararg_buffer|0));
  $3 = __THREW__; __THREW__ = 0;
 }
 $4 = ___cxa_find_matching_catch_3(0|0)|0;
 $5 = tempRet0;
 (___cxa_begin_catch(($4|0))|0);
 __THREW__ = 0;
 invoke_vii(23,(3317|0),($vararg_buffer1|0));
 $6 = __THREW__; __THREW__ = 0;
 $7 = ___cxa_find_matching_catch_3(0|0)|0;
 $8 = tempRet0;
 __THREW__ = 0;
 invoke_v(24);
 $9 = __THREW__; __THREW__ = 0;
 $10 = $9&1;
 if ($10) {
  $11 = ___cxa_find_matching_catch_3(0|0)|0;
  $12 = tempRet0;
  ___clang_call_terminate($11);
  // unreachable;
 } else {
  ___clang_call_terminate($7);
  // unreachable;
 }
}
function __ZSt13get_terminatev() {
 var $0 = 0, $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $0 = HEAP32[84]|0;HEAP32[84] = (($0+0)|0);
 $1 = $0;
 return ($1|0);
}
function ___cxa_can_catch($0,$1,$2) {
 $0 = $0|0;
 $1 = $1|0;
 $2 = $2|0;
 var $10 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16|0; if ((STACKTOP|0) >= (STACK_MAX|0)) abortStackOverflow(16|0);
 $3 = sp;
 $4 = HEAP32[$2>>2]|0;
 HEAP32[$3>>2] = $4;
 $5 = HEAP32[$0>>2]|0;
 $6 = ((($5)) + 16|0);
 $7 = HEAP32[$6>>2]|0;
 $8 = (FUNCTION_TABLE_iiii[$7 & 15]($0,$1,$3)|0);
 $9 = $8&1;
 if ($8) {
  $10 = HEAP32[$3>>2]|0;
  HEAP32[$2>>2] = $10;
 }
 STACKTOP = sp;return ($9|0);
}
function ___cxa_is_pointer_type($0) {
 $0 = $0|0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $phitmp = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = ($0|0)==(0|0);
 if ($1) {
  $4 = 0;
 } else {
  $2 = (___dynamic_cast($0,32,88,0)|0);
  $phitmp = ($2|0)!=(0|0);
  $4 = $phitmp;
 }
 $3 = $4&1;
 return ($3|0);
}
function runPostSets() {
}
function _i64Subtract(a, b, c, d) {
    a = a|0; b = b|0; c = c|0; d = d|0;
    var l = 0, h = 0;
    l = (a - c)>>>0;
    h = (b - d)>>>0;
    h = (b - d - (((c>>>0) > (a>>>0))|0))>>>0; // Borrow one from high word to low word on underflow.
    return ((tempRet0 = h,l|0)|0);
}
function _i64Add(a, b, c, d) {
    /*
      x = a + b*2^32
      y = c + d*2^32
      result = l + h*2^32
    */
    a = a|0; b = b|0; c = c|0; d = d|0;
    var l = 0, h = 0;
    l = (a + c)>>>0;
    h = (b + d + (((l>>>0) < (a>>>0))|0))>>>0; // Add carry from low word to high word on overflow.
    return ((tempRet0 = h,l|0)|0);
}
function _bitshift64Lshr(low, high, bits) {
    low = low|0; high = high|0; bits = bits|0;
    var ander = 0;
    if ((bits|0) < 32) {
      ander = ((1 << bits) - 1)|0;
      tempRet0 = high >>> bits;
      return (low >>> bits) | ((high&ander) << (32 - bits));
    }
    tempRet0 = 0;
    return (high >>> (bits - 32))|0;
}
function _memset(ptr, value, num) {
    ptr = ptr|0; value = value|0; num = num|0;
    var stop = 0, value4 = 0, stop4 = 0, unaligned = 0;
    stop = (ptr + num)|0;
    if ((num|0) >= 20) {
      // This is unaligned, but quite large, so work hard to get to aligned settings
      value = value & 0xff;
      unaligned = ptr & 3;
      value4 = value | (value << 8) | (value << 16) | (value << 24);
      stop4 = stop & ~3;
      if (unaligned) {
        unaligned = (ptr + 4 - unaligned)|0;
        while ((ptr|0) < (unaligned|0)) { // no need to check for stop, since we have large num
          HEAP8[((ptr)>>0)]=value;
          ptr = (ptr+1)|0;
        }
      }
      while ((ptr|0) < (stop4|0)) {
        HEAP32[((ptr)>>2)]=value4;
        ptr = (ptr+4)|0;
      }
    }
    while ((ptr|0) < (stop|0)) {
      HEAP8[((ptr)>>0)]=value;
      ptr = (ptr+1)|0;
    }
    return (ptr-num)|0;
}
function _memcpy(dest, src, num) {
    dest = dest|0; src = src|0; num = num|0;
    var ret = 0;
    if ((num|0) >= 4096) return _emscripten_memcpy_big(dest|0, src|0, num|0)|0;
    ret = dest|0;
    if ((dest&3) == (src&3)) {
      while (dest & 3) {
        if ((num|0) == 0) return ret|0;
        HEAP8[((dest)>>0)]=((HEAP8[((src)>>0)])|0);
        dest = (dest+1)|0;
        src = (src+1)|0;
        num = (num-1)|0;
      }
      while ((num|0) >= 4) {
        HEAP32[((dest)>>2)]=((HEAP32[((src)>>2)])|0);
        dest = (dest+4)|0;
        src = (src+4)|0;
        num = (num-4)|0;
      }
    }
    while ((num|0) > 0) {
      HEAP8[((dest)>>0)]=((HEAP8[((src)>>0)])|0);
      dest = (dest+1)|0;
      src = (src+1)|0;
      num = (num-1)|0;
    }
    return ret|0;
}
function _sbrk(increment) {
    increment = increment|0;
    var oldDynamicTop = 0;
    var oldDynamicTopOnChange = 0;
    var newDynamicTop = 0;
    var totalMemory = 0;
    increment = ((increment + 15) & -16)|0;
    oldDynamicTop = HEAP32[DYNAMICTOP_PTR>>2]|0;
    newDynamicTop = oldDynamicTop + increment | 0;

    if (((increment|0) > 0 & (newDynamicTop|0) < (oldDynamicTop|0)) // Detect and fail if we would wrap around signed 32-bit int.
      | (newDynamicTop|0) < 0) { // Also underflow, sbrk() should be able to be used to subtract.
      abortOnCannotGrowMemory()|0;
      ___setErrNo(12);
      return -1;
    }

    HEAP32[DYNAMICTOP_PTR>>2] = newDynamicTop;
    totalMemory = getTotalMemory()|0;
    if ((newDynamicTop|0) > (totalMemory|0)) {
      if ((enlargeMemory()|0) == 0) {
        ___setErrNo(12);
        HEAP32[DYNAMICTOP_PTR>>2] = oldDynamicTop;
        return -1;
      }
    }
    return oldDynamicTop|0;
}
function _llvm_cttz_i32(x) {
    x = x|0;
    var ret = 0;
    ret = ((HEAP8[(((cttz_i8)+(x & 0xff))>>0)])|0);
    if ((ret|0) < 8) return ret|0;
    ret = ((HEAP8[(((cttz_i8)+((x >> 8)&0xff))>>0)])|0);
    if ((ret|0) < 8) return (ret + 8)|0;
    ret = ((HEAP8[(((cttz_i8)+((x >> 16)&0xff))>>0)])|0);
    if ((ret|0) < 8) return (ret + 16)|0;
    return (((HEAP8[(((cttz_i8)+(x >>> 24))>>0)])|0) + 24)|0;
}
function ___udivmoddi4($a$0, $a$1, $b$0, $b$1, $rem) {
    $a$0 = $a$0 | 0;
    $a$1 = $a$1 | 0;
    $b$0 = $b$0 | 0;
    $b$1 = $b$1 | 0;
    $rem = $rem | 0;
    var $n_sroa_0_0_extract_trunc = 0, $n_sroa_1_4_extract_shift$0 = 0, $n_sroa_1_4_extract_trunc = 0, $d_sroa_0_0_extract_trunc = 0, $d_sroa_1_4_extract_shift$0 = 0, $d_sroa_1_4_extract_trunc = 0, $4 = 0, $17 = 0, $37 = 0, $49 = 0, $51 = 0, $57 = 0, $58 = 0, $66 = 0, $78 = 0, $86 = 0, $88 = 0, $89 = 0, $91 = 0, $92 = 0, $95 = 0, $105 = 0, $117 = 0, $119 = 0, $125 = 0, $126 = 0, $130 = 0, $q_sroa_1_1_ph = 0, $q_sroa_0_1_ph = 0, $r_sroa_1_1_ph = 0, $r_sroa_0_1_ph = 0, $sr_1_ph = 0, $d_sroa_0_0_insert_insert99$0 = 0, $d_sroa_0_0_insert_insert99$1 = 0, $137$0 = 0, $137$1 = 0, $carry_0203 = 0, $sr_1202 = 0, $r_sroa_0_1201 = 0, $r_sroa_1_1200 = 0, $q_sroa_0_1199 = 0, $q_sroa_1_1198 = 0, $147 = 0, $149 = 0, $r_sroa_0_0_insert_insert42$0 = 0, $r_sroa_0_0_insert_insert42$1 = 0, $150$1 = 0, $151$0 = 0, $152 = 0, $154$0 = 0, $r_sroa_0_0_extract_trunc = 0, $r_sroa_1_4_extract_trunc = 0, $155 = 0, $carry_0_lcssa$0 = 0, $carry_0_lcssa$1 = 0, $r_sroa_0_1_lcssa = 0, $r_sroa_1_1_lcssa = 0, $q_sroa_0_1_lcssa = 0, $q_sroa_1_1_lcssa = 0, $q_sroa_0_0_insert_ext75$0 = 0, $q_sroa_0_0_insert_ext75$1 = 0, $q_sroa_0_0_insert_insert77$1 = 0, $_0$0 = 0, $_0$1 = 0;
    $n_sroa_0_0_extract_trunc = $a$0;
    $n_sroa_1_4_extract_shift$0 = $a$1;
    $n_sroa_1_4_extract_trunc = $n_sroa_1_4_extract_shift$0;
    $d_sroa_0_0_extract_trunc = $b$0;
    $d_sroa_1_4_extract_shift$0 = $b$1;
    $d_sroa_1_4_extract_trunc = $d_sroa_1_4_extract_shift$0;
    if (($n_sroa_1_4_extract_trunc | 0) == 0) {
      $4 = ($rem | 0) != 0;
      if (($d_sroa_1_4_extract_trunc | 0) == 0) {
        if ($4) {
          HEAP32[$rem >> 2] = ($n_sroa_0_0_extract_trunc >>> 0) % ($d_sroa_0_0_extract_trunc >>> 0);
          HEAP32[$rem + 4 >> 2] = 0;
        }
        $_0$1 = 0;
        $_0$0 = ($n_sroa_0_0_extract_trunc >>> 0) / ($d_sroa_0_0_extract_trunc >>> 0) >>> 0;
        return (tempRet0 = $_0$1, $_0$0) | 0;
      } else {
        if (!$4) {
          $_0$1 = 0;
          $_0$0 = 0;
          return (tempRet0 = $_0$1, $_0$0) | 0;
        }
        HEAP32[$rem >> 2] = $a$0 & -1;
        HEAP32[$rem + 4 >> 2] = $a$1 & 0;
        $_0$1 = 0;
        $_0$0 = 0;
        return (tempRet0 = $_0$1, $_0$0) | 0;
      }
    }
    $17 = ($d_sroa_1_4_extract_trunc | 0) == 0;
    do {
      if (($d_sroa_0_0_extract_trunc | 0) == 0) {
        if ($17) {
          if (($rem | 0) != 0) {
            HEAP32[$rem >> 2] = ($n_sroa_1_4_extract_trunc >>> 0) % ($d_sroa_0_0_extract_trunc >>> 0);
            HEAP32[$rem + 4 >> 2] = 0;
          }
          $_0$1 = 0;
          $_0$0 = ($n_sroa_1_4_extract_trunc >>> 0) / ($d_sroa_0_0_extract_trunc >>> 0) >>> 0;
          return (tempRet0 = $_0$1, $_0$0) | 0;
        }
        if (($n_sroa_0_0_extract_trunc | 0) == 0) {
          if (($rem | 0) != 0) {
            HEAP32[$rem >> 2] = 0;
            HEAP32[$rem + 4 >> 2] = ($n_sroa_1_4_extract_trunc >>> 0) % ($d_sroa_1_4_extract_trunc >>> 0);
          }
          $_0$1 = 0;
          $_0$0 = ($n_sroa_1_4_extract_trunc >>> 0) / ($d_sroa_1_4_extract_trunc >>> 0) >>> 0;
          return (tempRet0 = $_0$1, $_0$0) | 0;
        }
        $37 = $d_sroa_1_4_extract_trunc - 1 | 0;
        if (($37 & $d_sroa_1_4_extract_trunc | 0) == 0) {
          if (($rem | 0) != 0) {
            HEAP32[$rem >> 2] = 0 | $a$0 & -1;
            HEAP32[$rem + 4 >> 2] = $37 & $n_sroa_1_4_extract_trunc | $a$1 & 0;
          }
          $_0$1 = 0;
          $_0$0 = $n_sroa_1_4_extract_trunc >>> ((_llvm_cttz_i32($d_sroa_1_4_extract_trunc | 0) | 0) >>> 0);
          return (tempRet0 = $_0$1, $_0$0) | 0;
        }
        $49 = Math_clz32($d_sroa_1_4_extract_trunc | 0) | 0;
        $51 = $49 - (Math_clz32($n_sroa_1_4_extract_trunc | 0) | 0) | 0;
        if ($51 >>> 0 <= 30) {
          $57 = $51 + 1 | 0;
          $58 = 31 - $51 | 0;
          $sr_1_ph = $57;
          $r_sroa_0_1_ph = $n_sroa_1_4_extract_trunc << $58 | $n_sroa_0_0_extract_trunc >>> ($57 >>> 0);
          $r_sroa_1_1_ph = $n_sroa_1_4_extract_trunc >>> ($57 >>> 0);
          $q_sroa_0_1_ph = 0;
          $q_sroa_1_1_ph = $n_sroa_0_0_extract_trunc << $58;
          break;
        }
        if (($rem | 0) == 0) {
          $_0$1 = 0;
          $_0$0 = 0;
          return (tempRet0 = $_0$1, $_0$0) | 0;
        }
        HEAP32[$rem >> 2] = 0 | $a$0 & -1;
        HEAP32[$rem + 4 >> 2] = $n_sroa_1_4_extract_shift$0 | $a$1 & 0;
        $_0$1 = 0;
        $_0$0 = 0;
        return (tempRet0 = $_0$1, $_0$0) | 0;
      } else {
        if (!$17) {
          $117 = Math_clz32($d_sroa_1_4_extract_trunc | 0) | 0;
          $119 = $117 - (Math_clz32($n_sroa_1_4_extract_trunc | 0) | 0) | 0;
          if ($119 >>> 0 <= 31) {
            $125 = $119 + 1 | 0;
            $126 = 31 - $119 | 0;
            $130 = $119 - 31 >> 31;
            $sr_1_ph = $125;
            $r_sroa_0_1_ph = $n_sroa_0_0_extract_trunc >>> ($125 >>> 0) & $130 | $n_sroa_1_4_extract_trunc << $126;
            $r_sroa_1_1_ph = $n_sroa_1_4_extract_trunc >>> ($125 >>> 0) & $130;
            $q_sroa_0_1_ph = 0;
            $q_sroa_1_1_ph = $n_sroa_0_0_extract_trunc << $126;
            break;
          }
          if (($rem | 0) == 0) {
            $_0$1 = 0;
            $_0$0 = 0;
            return (tempRet0 = $_0$1, $_0$0) | 0;
          }
          HEAP32[$rem >> 2] = 0 | $a$0 & -1;
          HEAP32[$rem + 4 >> 2] = $n_sroa_1_4_extract_shift$0 | $a$1 & 0;
          $_0$1 = 0;
          $_0$0 = 0;
          return (tempRet0 = $_0$1, $_0$0) | 0;
        }
        $66 = $d_sroa_0_0_extract_trunc - 1 | 0;
        if (($66 & $d_sroa_0_0_extract_trunc | 0) != 0) {
          $86 = (Math_clz32($d_sroa_0_0_extract_trunc | 0) | 0) + 33 | 0;
          $88 = $86 - (Math_clz32($n_sroa_1_4_extract_trunc | 0) | 0) | 0;
          $89 = 64 - $88 | 0;
          $91 = 32 - $88 | 0;
          $92 = $91 >> 31;
          $95 = $88 - 32 | 0;
          $105 = $95 >> 31;
          $sr_1_ph = $88;
          $r_sroa_0_1_ph = $91 - 1 >> 31 & $n_sroa_1_4_extract_trunc >>> ($95 >>> 0) | ($n_sroa_1_4_extract_trunc << $91 | $n_sroa_0_0_extract_trunc >>> ($88 >>> 0)) & $105;
          $r_sroa_1_1_ph = $105 & $n_sroa_1_4_extract_trunc >>> ($88 >>> 0);
          $q_sroa_0_1_ph = $n_sroa_0_0_extract_trunc << $89 & $92;
          $q_sroa_1_1_ph = ($n_sroa_1_4_extract_trunc << $89 | $n_sroa_0_0_extract_trunc >>> ($95 >>> 0)) & $92 | $n_sroa_0_0_extract_trunc << $91 & $88 - 33 >> 31;
          break;
        }
        if (($rem | 0) != 0) {
          HEAP32[$rem >> 2] = $66 & $n_sroa_0_0_extract_trunc;
          HEAP32[$rem + 4 >> 2] = 0;
        }
        if (($d_sroa_0_0_extract_trunc | 0) == 1) {
          $_0$1 = $n_sroa_1_4_extract_shift$0 | $a$1 & 0;
          $_0$0 = 0 | $a$0 & -1;
          return (tempRet0 = $_0$1, $_0$0) | 0;
        } else {
          $78 = _llvm_cttz_i32($d_sroa_0_0_extract_trunc | 0) | 0;
          $_0$1 = 0 | $n_sroa_1_4_extract_trunc >>> ($78 >>> 0);
          $_0$0 = $n_sroa_1_4_extract_trunc << 32 - $78 | $n_sroa_0_0_extract_trunc >>> ($78 >>> 0) | 0;
          return (tempRet0 = $_0$1, $_0$0) | 0;
        }
      }
    } while (0);
    if (($sr_1_ph | 0) == 0) {
      $q_sroa_1_1_lcssa = $q_sroa_1_1_ph;
      $q_sroa_0_1_lcssa = $q_sroa_0_1_ph;
      $r_sroa_1_1_lcssa = $r_sroa_1_1_ph;
      $r_sroa_0_1_lcssa = $r_sroa_0_1_ph;
      $carry_0_lcssa$1 = 0;
      $carry_0_lcssa$0 = 0;
    } else {
      $d_sroa_0_0_insert_insert99$0 = 0 | $b$0 & -1;
      $d_sroa_0_0_insert_insert99$1 = $d_sroa_1_4_extract_shift$0 | $b$1 & 0;
      $137$0 = _i64Add($d_sroa_0_0_insert_insert99$0 | 0, $d_sroa_0_0_insert_insert99$1 | 0, -1, -1) | 0;
      $137$1 = tempRet0;
      $q_sroa_1_1198 = $q_sroa_1_1_ph;
      $q_sroa_0_1199 = $q_sroa_0_1_ph;
      $r_sroa_1_1200 = $r_sroa_1_1_ph;
      $r_sroa_0_1201 = $r_sroa_0_1_ph;
      $sr_1202 = $sr_1_ph;
      $carry_0203 = 0;
      while (1) {
        $147 = $q_sroa_0_1199 >>> 31 | $q_sroa_1_1198 << 1;
        $149 = $carry_0203 | $q_sroa_0_1199 << 1;
        $r_sroa_0_0_insert_insert42$0 = 0 | ($r_sroa_0_1201 << 1 | $q_sroa_1_1198 >>> 31);
        $r_sroa_0_0_insert_insert42$1 = $r_sroa_0_1201 >>> 31 | $r_sroa_1_1200 << 1 | 0;
        _i64Subtract($137$0 | 0, $137$1 | 0, $r_sroa_0_0_insert_insert42$0 | 0, $r_sroa_0_0_insert_insert42$1 | 0) | 0;
        $150$1 = tempRet0;
        $151$0 = $150$1 >> 31 | (($150$1 | 0) < 0 ? -1 : 0) << 1;
        $152 = $151$0 & 1;
        $154$0 = _i64Subtract($r_sroa_0_0_insert_insert42$0 | 0, $r_sroa_0_0_insert_insert42$1 | 0, $151$0 & $d_sroa_0_0_insert_insert99$0 | 0, ((($150$1 | 0) < 0 ? -1 : 0) >> 31 | (($150$1 | 0) < 0 ? -1 : 0) << 1) & $d_sroa_0_0_insert_insert99$1 | 0) | 0;
        $r_sroa_0_0_extract_trunc = $154$0;
        $r_sroa_1_4_extract_trunc = tempRet0;
        $155 = $sr_1202 - 1 | 0;
        if (($155 | 0) == 0) {
          break;
        } else {
          $q_sroa_1_1198 = $147;
          $q_sroa_0_1199 = $149;
          $r_sroa_1_1200 = $r_sroa_1_4_extract_trunc;
          $r_sroa_0_1201 = $r_sroa_0_0_extract_trunc;
          $sr_1202 = $155;
          $carry_0203 = $152;
        }
      }
      $q_sroa_1_1_lcssa = $147;
      $q_sroa_0_1_lcssa = $149;
      $r_sroa_1_1_lcssa = $r_sroa_1_4_extract_trunc;
      $r_sroa_0_1_lcssa = $r_sroa_0_0_extract_trunc;
      $carry_0_lcssa$1 = 0;
      $carry_0_lcssa$0 = $152;
    }
    $q_sroa_0_0_insert_ext75$0 = $q_sroa_0_1_lcssa;
    $q_sroa_0_0_insert_ext75$1 = 0;
    $q_sroa_0_0_insert_insert77$1 = $q_sroa_1_1_lcssa | $q_sroa_0_0_insert_ext75$1;
    if (($rem | 0) != 0) {
      HEAP32[$rem >> 2] = 0 | $r_sroa_0_1_lcssa;
      HEAP32[$rem + 4 >> 2] = $r_sroa_1_1_lcssa | 0;
    }
    $_0$1 = (0 | $q_sroa_0_0_insert_ext75$0) >>> 31 | $q_sroa_0_0_insert_insert77$1 << 1 | ($q_sroa_0_0_insert_ext75$1 << 1 | $q_sroa_0_0_insert_ext75$0 >>> 31) & 0 | $carry_0_lcssa$1;
    $_0$0 = ($q_sroa_0_0_insert_ext75$0 << 1 | 0 >>> 31) & -2 | $carry_0_lcssa$0;
    return (tempRet0 = $_0$1, $_0$0) | 0;
}
function ___uremdi3($a$0, $a$1, $b$0, $b$1) {
    $a$0 = $a$0 | 0;
    $a$1 = $a$1 | 0;
    $b$0 = $b$0 | 0;
    $b$1 = $b$1 | 0;
    var $rem = 0, __stackBase__ = 0;
    __stackBase__ = STACKTOP;
    STACKTOP = STACKTOP + 16 | 0;
    $rem = __stackBase__ | 0;
    ___udivmoddi4($a$0, $a$1, $b$0, $b$1, $rem) | 0;
    STACKTOP = __stackBase__;
    return (tempRet0 = HEAP32[$rem + 4 >> 2] | 0, HEAP32[$rem >> 2] | 0) | 0;
}
function _bitshift64Shl(low, high, bits) {
    low = low|0; high = high|0; bits = bits|0;
    var ander = 0;
    if ((bits|0) < 32) {
      ander = ((1 << bits) - 1)|0;
      tempRet0 = (high << bits) | ((low&(ander << (32 - bits))) >>> (32 - bits));
      return low << bits;
    }
    tempRet0 = low << (bits - 32);
    return 0;
}
function ___udivdi3($a$0, $a$1, $b$0, $b$1) {
    $a$0 = $a$0 | 0;
    $a$1 = $a$1 | 0;
    $b$0 = $b$0 | 0;
    $b$1 = $b$1 | 0;
    var $1$0 = 0;
    $1$0 = ___udivmoddi4($a$0, $a$1, $b$0, $b$1, 0) | 0;
    return $1$0 | 0;
}
function ___muldsi3($a, $b) {
    $a = $a | 0;
    $b = $b | 0;
    var $1 = 0, $2 = 0, $3 = 0, $6 = 0, $8 = 0, $11 = 0, $12 = 0;
    $1 = $a & 65535;
    $2 = $b & 65535;
    $3 = Math_imul($2, $1) | 0;
    $6 = $a >>> 16;
    $8 = ($3 >>> 16) + (Math_imul($2, $6) | 0) | 0;
    $11 = $b >>> 16;
    $12 = Math_imul($11, $1) | 0;
    return (tempRet0 = (($8 >>> 16) + (Math_imul($11, $6) | 0) | 0) + ((($8 & 65535) + $12 | 0) >>> 16) | 0, 0 | ($8 + $12 << 16 | $3 & 65535)) | 0;
}
function ___muldi3($a$0, $a$1, $b$0, $b$1) {
    $a$0 = $a$0 | 0;
    $a$1 = $a$1 | 0;
    $b$0 = $b$0 | 0;
    $b$1 = $b$1 | 0;
    var $x_sroa_0_0_extract_trunc = 0, $y_sroa_0_0_extract_trunc = 0, $1$0 = 0, $1$1 = 0, $2 = 0;
    $x_sroa_0_0_extract_trunc = $a$0;
    $y_sroa_0_0_extract_trunc = $b$0;
    $1$0 = ___muldsi3($x_sroa_0_0_extract_trunc, $y_sroa_0_0_extract_trunc) | 0;
    $1$1 = tempRet0;
    $2 = Math_imul($a$1, $y_sroa_0_0_extract_trunc) | 0;
    return (tempRet0 = ((Math_imul($b$1, $x_sroa_0_0_extract_trunc) | 0) + $2 | 0) + $1$1 | $1$1 & 0, 0 | $1$0 & -1) | 0;
}
function _pthread_self() {
    return 0;
}

  
function dynCall_iiii(index,a1,a2,a3) {
  index = index|0;
  a1=a1|0; a2=a2|0; a3=a3|0;
  return FUNCTION_TABLE_iiii[index&15](a1|0,a2|0,a3|0)|0;
}


function dynCall_vid(index,a1,a2) {
  index = index|0;
  a1=a1|0; a2=+a2;
  FUNCTION_TABLE_vid[index&0](a1|0,+a2);
}


function dynCall_viiiii(index,a1,a2,a3,a4,a5) {
  index = index|0;
  a1=a1|0; a2=a2|0; a3=a3|0; a4=a4|0; a5=a5|0;
  FUNCTION_TABLE_viiiii[index&31](a1|0,a2|0,a3|0,a4|0,a5|0);
}


function dynCall_i(index) {
  index = index|0;
  
  return FUNCTION_TABLE_i[index&31]()|0;
}


function dynCall_vi(index,a1) {
  index = index|0;
  a1=a1|0;
  FUNCTION_TABLE_vi[index&31](a1|0);
}


function dynCall_vii(index,a1,a2) {
  index = index|0;
  a1=a1|0; a2=a2|0;
  FUNCTION_TABLE_vii[index&31](a1|0,a2|0);
}


function dynCall_vidd(index,a1,a2,a3) {
  index = index|0;
  a1=a1|0; a2=+a2; a3=+a3;
  FUNCTION_TABLE_vidd[index&0](a1|0,+a2,+a3);
}


function dynCall_ii(index,a1) {
  index = index|0;
  a1=a1|0;
  return FUNCTION_TABLE_ii[index&1](a1|0)|0;
}


function dynCall_viidi(index,a1,a2,a3,a4) {
  index = index|0;
  a1=a1|0; a2=a2|0; a3=+a3; a4=a4|0;
  FUNCTION_TABLE_viidi[index&0](a1|0,a2|0,+a3,a4|0);
}


function dynCall_viidd(index,a1,a2,a3,a4) {
  index = index|0;
  a1=a1|0; a2=a2|0; a3=+a3; a4=+a4;
  FUNCTION_TABLE_viidd[index&0](a1|0,a2|0,+a3,+a4);
}


function dynCall_v(index) {
  index = index|0;
  
  FUNCTION_TABLE_v[index&31]();
}


function dynCall_viid(index,a1,a2,a3) {
  index = index|0;
  a1=a1|0; a2=a2|0; a3=+a3;
  FUNCTION_TABLE_viid[index&0](a1|0,a2|0,+a3);
}


function dynCall_viiiiii(index,a1,a2,a3,a4,a5,a6) {
  index = index|0;
  a1=a1|0; a2=a2|0; a3=a3|0; a4=a4|0; a5=a5|0; a6=a6|0;
  FUNCTION_TABLE_viiiiii[index&15](a1|0,a2|0,a3|0,a4|0,a5|0,a6|0);
}


function dynCall_iii(index,a1,a2) {
  index = index|0;
  a1=a1|0; a2=a2|0;
  return FUNCTION_TABLE_iii[index&0](a1|0,a2|0)|0;
}


function dynCall_viiii(index,a1,a2,a3,a4) {
  index = index|0;
  a1=a1|0; a2=a2|0; a3=a3|0; a4=a4|0;
  FUNCTION_TABLE_viiii[index&31](a1|0,a2|0,a3|0,a4|0);
}

function b0(p0,p1,p2) {
 p0 = p0|0;p1 = p1|0;p2 = p2|0; nullFunc_iiii(0);return 0;
}
function b1(p0,p1) {
 p0 = p0|0;p1 = +p1; nullFunc_vid(1);
}
function b2(p0,p1,p2,p3,p4) {
 p0 = p0|0;p1 = p1|0;p2 = p2|0;p3 = p3|0;p4 = p4|0; nullFunc_viiiii(2);
}
function b3() {
 ; nullFunc_i(3);return 0;
}
function b4(p0) {
 p0 = p0|0; nullFunc_vi(4);
}
function b5(p0,p1) {
 p0 = p0|0;p1 = p1|0; nullFunc_vii(5);
}
function b6(p0,p1,p2) {
 p0 = p0|0;p1 = +p1;p2 = +p2; nullFunc_vidd(6);
}
function b7(p0) {
 p0 = p0|0; nullFunc_ii(7);return 0;
}
function b8(p0,p1,p2,p3) {
 p0 = p0|0;p1 = p1|0;p2 = +p2;p3 = p3|0; nullFunc_viidi(8);
}
function b9(p0,p1,p2,p3) {
 p0 = p0|0;p1 = p1|0;p2 = +p2;p3 = +p3; nullFunc_viidd(9);
}
function b10() {
 ; nullFunc_v(10);
}
function ___cxa_end_catch__wrapper() {
 ; ___cxa_end_catch();
}
function b11(p0,p1,p2) {
 p0 = p0|0;p1 = p1|0;p2 = +p2; nullFunc_viid(11);
}
function b12(p0,p1,p2,p3,p4,p5) {
 p0 = p0|0;p1 = p1|0;p2 = p2|0;p3 = p3|0;p4 = p4|0;p5 = p5|0; nullFunc_viiiiii(12);
}
function b13(p0,p1) {
 p0 = p0|0;p1 = p1|0; nullFunc_iii(13);return 0;
}
function b14(p0,p1,p2,p3) {
 p0 = p0|0;p1 = p1|0;p2 = p2|0;p3 = p3|0; nullFunc_viiii(14);
}

// EMSCRIPTEN_END_FUNCS
var FUNCTION_TABLE_iiii = [b0,b0,___stdout_write,___stdio_seek,___stdio_write,b0,b0,b0,b0,b0,__ZNK10__cxxabiv117__class_type_info9can_catchEPKNS_16__shim_type_infoERPv,b0,b0,b0,b0,b0];
var FUNCTION_TABLE_vid = [b1];
var FUNCTION_TABLE_viiiii = [b2,b2,b2,b2,b2,b2,b2,b2,b2,b2,b2,b2,__ZNK10__cxxabiv117__class_type_info16search_below_dstEPNS_19__dynamic_cast_infoEPKvib,b2,b2,b2,__ZNK10__cxxabiv120__si_class_type_info16search_below_dstEPNS_19__dynamic_cast_infoEPKvib,b2,b2,b2,b2,b2,b2,b2,b2,b2,b2,b2,b2
,b2,b2,b2];
var FUNCTION_TABLE_i = [b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,___cxa_get_globals_fast,b3,b3,b3,b3,b3,b3
,b3,b3,b3];
var FUNCTION_TABLE_vi = [b4,b4,b4,b4,b4,b4,__ZN10__cxxabiv116__shim_type_infoD2Ev,__ZN10__cxxabiv117__class_type_infoD0Ev,__ZNK10__cxxabiv116__shim_type_info5noop1Ev,__ZNK10__cxxabiv116__shim_type_info5noop2Ev,b4,b4,b4,b4,__ZN10__cxxabiv120__si_class_type_infoD0Ev,b4,b4,b4,_free,_cleanup,b4,__ZN10__cxxabiv112_GLOBAL__N_19destruct_EPv,b4,b4,b4,b4,b4,b4,b4
,b4,b4,b4];
var FUNCTION_TABLE_vii = [b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,b5,_abort_message,b5,b5,b5,b5,b5
,b5,b5,b5];
var FUNCTION_TABLE_vidd = [b6];
var FUNCTION_TABLE_ii = [b7,___stdio_close];
var FUNCTION_TABLE_viidi = [b8];
var FUNCTION_TABLE_viidd = [b9];
var FUNCTION_TABLE_v = [b10,b10,b10,b10,b10,__ZL25default_terminate_handlerv,b10,b10,b10,b10,b10,b10,b10,b10,b10,b10,b10,b10,b10,b10,__ZN10__cxxabiv112_GLOBAL__N_110construct_Ev,b10,b10,b10,___cxa_end_catch__wrapper,b10,b10,b10,b10
,b10,b10,b10];
var FUNCTION_TABLE_viid = [b11];
var FUNCTION_TABLE_viiiiii = [b12,b12,b12,b12,b12,b12,b12,b12,b12,b12,b12,__ZNK10__cxxabiv117__class_type_info16search_above_dstEPNS_19__dynamic_cast_infoEPKvS4_ib,b12,b12,b12,__ZNK10__cxxabiv120__si_class_type_info16search_above_dstEPNS_19__dynamic_cast_infoEPKvS4_ib];
var FUNCTION_TABLE_iii = [b13];
var FUNCTION_TABLE_viiii = [b14,b14,b14,b14,b14,b14,b14,b14,b14,b14,b14,b14,b14,__ZNK10__cxxabiv117__class_type_info27has_unambiguous_public_baseEPNS_19__dynamic_cast_infoEPvi,b14,b14,b14,__ZNK10__cxxabiv120__si_class_type_info27has_unambiguous_public_baseEPNS_19__dynamic_cast_infoEPvi,b14,b14,b14,b14,b14,b14,b14,b14,b14,b14,b14
,b14,b14,b14];

  return { _emscripten_bind_CLuaUnitScript_Activate_0: _emscripten_bind_CLuaUnitScript_Activate_0, _emscripten_bind_CCannon_UpdateWantedDir_0: _emscripten_bind_CCannon_UpdateWantedDir_0, _emscripten_bind_CGeometricObjects_SetColor_5: _emscripten_bind_CGeometricObjects_SetColor_5, _emscripten_bind_CGlobalSynced___destroy___0: _emscripten_bind_CGlobalSynced___destroy___0, _emscripten_bind_CFactoryCAI_SlowUpdate_0: _emscripten_bind_CFactoryCAI_SlowUpdate_0, _emscripten_bind_CBuilder_SlowUpdate_0: _emscripten_bind_CBuilder_SlowUpdate_0, _emscripten_bind_CExplosionGeneratorHandler___destroy___0: _emscripten_bind_CExplosionGeneratorHandler___destroy___0, _llvm_cttz_i32: _llvm_cttz_i32, _emscripten_bind_CLosHandler_GetAllyTeamRadarErrorSize_1: _emscripten_bind_CLosHandler_GetAllyTeamRadarErrorSize_1, _emscripten_bind_CGeometricObjects_AddSpline_8: _emscripten_bind_CGeometricObjects_AddSpline_8, _emscripten_bind_CModInfo_ResetState_0: _emscripten_bind_CModInfo_ResetState_0, _emscripten_bind_CCommandQueue_clear_0: _emscripten_bind_CCommandQueue_clear_0, _bitshift64Lshr: _bitshift64Lshr, _emscripten_bind_CWeaponLoader___destroy___0: _emscripten_bind_CWeaponLoader___destroy___0, _emscripten_bind_CStarburstProjectile___destroy___0: _emscripten_bind_CStarburstProjectile___destroy___0, _emscripten_bind_CUnitDefHandler_IsValidUnitDefID_1: _emscripten_bind_CUnitDefHandler_IsValidUnitDefID_1, _emscripten_bind_CPathEstimator_Update_0: _emscripten_bind_CPathEstimator_Update_0, _emscripten_bind_CUnitDefHandler_ProcessDecoys_0: _emscripten_bind_CUnitDefHandler_ProcessDecoys_0, _emscripten_bind_CCircularSearchConstraint___destroy___0: _emscripten_bind_CCircularSearchConstraint___destroy___0, _emscripten_bind_CBuilderCAI_FinishCommand_0: _emscripten_bind_CBuilderCAI_FinishCommand_0, _emscripten_bind_CLuaUnitScript_Deactivate_0: _emscripten_bind_CLuaUnitScript_Deactivate_0, _emscripten_bind_CMoveMath___destroy___0: _emscripten_bind_CMoveMath___destroy___0, _emscripten_bind_CScriptMoveType___destroy___0: _emscripten_bind_CScriptMoveType___destroy___0, _sbrk: _sbrk, _emscripten_bind_CMobileCAI_StopSlowGuard_0: _emscripten_bind_CMobileCAI_StopSlowGuard_0, _emscripten_bind_CollisionVolume_SetDefaultToPieceTree_1: _emscripten_bind_CollisionVolume_SetDefaultToPieceTree_1, _emscripten_bind_CWeaponDefHandler___destroy___0: _emscripten_bind_CWeaponDefHandler___destroy___0, _emscripten_bind_CLuaUnitScript_MoveRate_1: _emscripten_bind_CLuaUnitScript_MoveRate_1, _emscripten_bind_CMobileCAI_Execute_0: _emscripten_bind_CMobileCAI_Execute_0, _emscripten_bind_CLuaUnitScript_Destroy_0: _emscripten_bind_CLuaUnitScript_Destroy_0, _emscripten_bind_CBuilderCAI___destroy___0: _emscripten_bind_CBuilderCAI___destroy___0, _emscripten_bind_CCannon___destroy___0: _emscripten_bind_CCannon___destroy___0, _emscripten_bind_CLuaUnitScript_Killed_0: _emscripten_bind_CLuaUnitScript_Killed_0, _emscripten_bind_CBuilder_Update_0: _emscripten_bind_CBuilder_Update_0, ___cxa_can_catch: ___cxa_can_catch, _emscripten_bind_CMobileCAI_NonMoving_0: _emscripten_bind_CMobileCAI_NonMoving_0, _emscripten_bind_CollisionVolume_DefaultToPieceTree_0: _emscripten_bind_CollisionVolume_DefaultToPieceTree_0, _emscripten_bind_CUnitDefHandler_AssignTechLevels_0: _emscripten_bind_CUnitDefHandler_AssignTechLevels_0, _emscripten_bind_CBuilder_StopBuild_1: _emscripten_bind_CBuilder_StopBuild_1, _free: _free, _emscripten_bind_CollisionVolume_GetHScale_1: _emscripten_bind_CollisionVolume_GetHScale_1, _emscripten_bind_CLuaUnitScript_Falling_0: _emscripten_bind_CLuaUnitScript_Falling_0, _emscripten_bind_CExplosionGeneratorHandler_ParseExplosionTables_0: _emscripten_bind_CExplosionGeneratorHandler_ParseExplosionTables_0, _emscripten_bind_CScriptMoveType_Update_0: _emscripten_bind_CScriptMoveType_Update_0, _emscripten_bind_CGeometricObjects___destroy___0: _emscripten_bind_CGeometricObjects___destroy___0, ___uremdi3: ___uremdi3, _emscripten_bind_CResourceMapAnalyzer_GetAverageIncome_0: _emscripten_bind_CResourceMapAnalyzer_GetAverageIncome_0, _emscripten_bind_CollisionQuery_AnyHit_0: _emscripten_bind_CollisionQuery_AnyHit_0, _emscripten_bind_CPathEstimator___destroy___0: _emscripten_bind_CPathEstimator___destroy___0, _emscripten_bind_CUnitScriptEngine_InitStatic_0: _emscripten_bind_CUnitScriptEngine_InitStatic_0, _emscripten_bind_CUnitScriptEngine_KillStatic_0: _emscripten_bind_CUnitScriptEngine_KillStatic_0, _emscripten_bind_CBuilder_StartRestore_2: _emscripten_bind_CBuilder_StartRestore_2, _emscripten_bind_CollisionQuery_InsideHit_0: _emscripten_bind_CollisionQuery_InsideHit_0, _emscripten_bind_CollisionVolume_GetHScaleSq_1: _emscripten_bind_CollisionVolume_GetHScaleSq_1, _emscripten_bind_CBuilding___destroy___0: _emscripten_bind_CBuilding___destroy___0, _emscripten_bind_CUnitScriptEngine_Tick_1: _emscripten_bind_CUnitScriptEngine_Tick_1, _emscripten_bind_CGeometricObjects_MarkSquare_1: _emscripten_bind_CGeometricObjects_MarkSquare_1, _emscripten_bind_CFactory___destroy___0: _emscripten_bind_CFactory___destroy___0, _emscripten_bind_CCannon_Init_0: _emscripten_bind_CCannon_Init_0, _emscripten_bind_CLuaUnitScript_ExtractionRateChanged_1: _emscripten_bind_CLuaUnitScript_ExtractionRateChanged_1, _emscripten_bind_CCannon_UpdateRange_1: _emscripten_bind_CCannon_UpdateRange_1, _emscripten_bind_CFactory_Update_0: _emscripten_bind_CFactory_Update_0, _emscripten_bind_CLosHandler_SetBaseRadarErrorSize_1: _emscripten_bind_CLosHandler_SetBaseRadarErrorSize_1, _emscripten_bind_CRectangularSearchConstraint_WithinConstraints_2: _emscripten_bind_CRectangularSearchConstraint_WithinConstraints_2, _emscripten_bind_CExtractorBuilding_ResetExtraction_0: _emscripten_bind_CExtractorBuilding_ResetExtraction_0, _emscripten_bind_CLuaUnitScript_WindChanged_2: _emscripten_bind_CLuaUnitScript_WindChanged_2, _emscripten_bind_CMobileCAI_CanSetMaxSpeed_0: _emscripten_bind_CMobileCAI_CanSetMaxSpeed_0, _emscripten_bind_CAirCAI_SlowUpdate_0: _emscripten_bind_CAirCAI_SlowUpdate_0, ___cxa_is_pointer_type: ___cxa_is_pointer_type, _emscripten_bind_CLosHandler_GetFullRead_0: _emscripten_bind_CLosHandler_GetFullRead_0, _emscripten_bind_CCannon_SlowUpdate_0: _emscripten_bind_CCannon_SlowUpdate_0, _emscripten_bind_CGlobalSynced_PreSimFrame_0: _emscripten_bind_CGlobalSynced_PreSimFrame_0, _emscripten_bind_CMobileCAI_GetCancelDistance_0: _emscripten_bind_CMobileCAI_GetCancelDistance_0, _emscripten_bind_CScriptMoveType_SetHeading_1: _emscripten_bind_CScriptMoveType_SetHeading_1, _emscripten_bind_CLosHandler_GetBaseRadarErrorMult_0: _emscripten_bind_CLosHandler_GetBaseRadarErrorMult_0, _emscripten_bind_CLosMap___destroy___0: _emscripten_bind_CLosMap___destroy___0, _emscripten_bind_CLuaUnitScript_StopBuilding_0: _emscripten_bind_CLuaUnitScript_StopBuilding_0, _emscripten_bind_CPathEstimator_GetPathChecksum_0: _emscripten_bind_CPathEstimator_GetPathChecksum_0, _emscripten_bind_CUnitDefHandler_Init_0: _emscripten_bind_CUnitDefHandler_Init_0, _emscripten_bind_CScriptMoveType_ForceUpdates_0: _emscripten_bind_CScriptMoveType_ForceUpdates_0, _emscripten_bind_CBuilder_ScriptStartBuilding_2: _emscripten_bind_CBuilder_ScriptStartBuilding_2, _pthread_self: _pthread_self, _emscripten_bind_CFactory_CreateNanoParticle_1: _emscripten_bind_CFactory_CreateNanoParticle_1, _emscripten_bind_CCustomExplosionGenerator_GetFlagsFromHeight_2: _emscripten_bind_CCustomExplosionGenerator_GetFlagsFromHeight_2, _emscripten_bind_CLosHandler_SetBaseRadarErrorMult_1: _emscripten_bind_CLosHandler_SetBaseRadarErrorMult_1, _emscripten_bind_ClassAliasList_Clear_0: _emscripten_bind_ClassAliasList_Clear_0, _emscripten_bind_CLosHandler_DecreaseAllyTeamRadarErrorSize_1: _emscripten_bind_CLosHandler_DecreaseAllyTeamRadarErrorSize_1, _emscripten_bind_CFactory_StopBuild_0: _emscripten_bind_CFactory_StopBuild_0, _emscripten_bind_CLuaUnitScript_FireWeapon_1: _emscripten_bind_CLuaUnitScript_FireWeapon_1, _emscripten_bind_CExtractorBuilding_GetExtractionDepth_0: _emscripten_bind_CExtractorBuilding_GetExtractionDepth_0, _emscripten_bind_CLuaUnitScript_QueryNanoPiece_0: _emscripten_bind_CLuaUnitScript_QueryNanoPiece_0, _emscripten_bind_CMobileCAI___destroy___0: _emscripten_bind_CMobileCAI___destroy___0, _emscripten_bind_CUnitScriptFactory___destroy___0: _emscripten_bind_CUnitScriptFactory___destroy___0, _malloc: _malloc, _emscripten_bind_CollisionQuery___destroy___0: _emscripten_bind_CollisionQuery___destroy___0, _emscripten_bind_CGeometricObjects_Update_0: _emscripten_bind_CGeometricObjects_Update_0, _emscripten_bind_CMobileCAI_StopMove_0: _emscripten_bind_CMobileCAI_StopMove_0, _emscripten_bind_CMobileCAI_SlowUpdate_0: _emscripten_bind_CMobileCAI_SlowUpdate_0, _emscripten_bind_CExplosionCreator___destroy___0: _emscripten_bind_CExplosionCreator___destroy___0, _emscripten_bind_CUnitLoader___destroy___0: _emscripten_bind_CUnitLoader___destroy___0, _emscripten_bind_CLosHandler___destroy___0: _emscripten_bind_CLosHandler___destroy___0, _emscripten_bind_CLuaUnitScript_QueryBuildInfo_0: _emscripten_bind_CLuaUnitScript_QueryBuildInfo_0, _emscripten_bind_CollisionVolume_SetDefaultToFootPrint_1: _emscripten_bind_CollisionVolume_SetDefaultToFootPrint_1, _emscripten_bind_CollisionVolume_SetVolumeType_1: _emscripten_bind_CollisionVolume_SetVolumeType_1, _emscripten_bind_CollisionVolume_SetUseContHitTest_1: _emscripten_bind_CollisionVolume_SetUseContHitTest_1, _emscripten_bind_CCommandQueue___destroy___0: _emscripten_bind_CCommandQueue___destroy___0, _emscripten_bind_CCollisionHandler_PrintStats_0: _emscripten_bind_CCollisionHandler_PrintStats_0, _emscripten_bind_CExtractorBuilding_ReCalculateMetalExtraction_0: _emscripten_bind_CExtractorBuilding_ReCalculateMetalExtraction_0, _emscripten_bind_CollisionVolume_GetPrimaryAxis_0: _emscripten_bind_CollisionVolume_GetPrimaryAxis_0, _emscripten_bind_CUnitDefHandler_ToggleNoCost_0: _emscripten_bind_CUnitDefHandler_ToggleNoCost_0, _emscripten_bind_CBuilderCAI_SlowUpdate_0: _emscripten_bind_CBuilderCAI_SlowUpdate_0, _emscripten_bind_CLosHandler_GetReadAllyTeam_0: _emscripten_bind_CLosHandler_GetReadAllyTeam_0, _emscripten_bind_CLosHandler_SetAllyTeamRadarErrorSize_2: _emscripten_bind_CLosHandler_SetAllyTeamRadarErrorSize_2, _emscripten_bind_CLuaUnitScript_RawCall_1: _emscripten_bind_CLuaUnitScript_RawCall_1, _emscripten_bind_CollisionQuery_EgressHit_0: _emscripten_bind_CollisionQuery_EgressHit_0, _emscripten_bind_VoidPtr___destroy___0: _emscripten_bind_VoidPtr___destroy___0, _memset: _memset, _emscripten_bind_CScriptMoveType_KeepPointingTo_3: _emscripten_bind_CScriptMoveType_KeepPointingTo_3, _emscripten_bind_CLuaUnitScript_StartMoving_1: _emscripten_bind_CLuaUnitScript_StartMoving_1, _emscripten_bind_CGlobalSynced_GetLuaSimFrame_0: _emscripten_bind_CGlobalSynced_GetLuaSimFrame_0, _emscripten_bind_CLuaUnitScript_AimWeapon_3: _emscripten_bind_CLuaUnitScript_AimWeapon_3, _emscripten_bind_CollisionVolume_GetBoundingRadius_0: _emscripten_bind_CollisionVolume_GetBoundingRadius_0, _emscripten_bind_CollisionVolume_GetBoundingRadiusSq_0: _emscripten_bind_CollisionVolume_GetBoundingRadiusSq_0, _emscripten_bind_CollisionVolume_PostLoad_0: _emscripten_bind_CollisionVolume_PostLoad_0, _emscripten_bind_CScriptMoveType_StopMoving_3: _emscripten_bind_CScriptMoveType_StopMoving_3, _emscripten_bind_CUnitDefHandler___destroy___0: _emscripten_bind_CUnitDefHandler___destroy___0, _emscripten_bind_CAirCAI_FinishCommand_0: _emscripten_bind_CAirCAI_FinishCommand_0, _emscripten_bind_CollisionVolume_SetIgnoreHits_1: _emscripten_bind_CollisionVolume_SetIgnoreHits_1, _emscripten_bind_CUnitScriptEngine___destroy___0: _emscripten_bind_CUnitScriptEngine___destroy___0, _emscripten_bind_CBuilderCAI_InitStatic_0: _emscripten_bind_CBuilderCAI_InitStatic_0, _emscripten_bind_CExtractorBuilding_GetExtractionRange_0: _emscripten_bind_CExtractorBuilding_GetExtractionRange_0, ___udivdi3: ___udivdi3, _emscripten_bind_CLuaUnitScript_HasFunction_1: _emscripten_bind_CLuaUnitScript_HasFunction_1, _emscripten_bind_CLuaUnitScript_AimFromWeapon_1: _emscripten_bind_CLuaUnitScript_AimFromWeapon_1, _emscripten_bind_CLuaUnitScript_Shot_1: _emscripten_bind_CLuaUnitScript_Shot_1, ___muldsi3: ___muldsi3, _emscripten_bind_CCommandQueue_empty_0: _emscripten_bind_CCommandQueue_empty_0, _emscripten_bind_CScriptMoveType_StartMoving_2: _emscripten_bind_CScriptMoveType_StartMoving_2, _emscripten_bind_CollisionVolume_GetSecondaryAxis_1: _emscripten_bind_CollisionVolume_GetSecondaryAxis_1, _emscripten_bind_CCustomExplosionGenerator___destroy___0: _emscripten_bind_CCustomExplosionGenerator___destroy___0, _emscripten_bind_CLosHandler_IncreaseAllyTeamRadarErrorSize_1: _emscripten_bind_CLosHandler_IncreaseAllyTeamRadarErrorSize_1, _emscripten_bind_CollisionVolume_GetOffset_1: _emscripten_bind_CollisionVolume_GetOffset_1, _memcpy: _memcpy, _emscripten_bind_CLuaUnitScript_EndBurst_1: _emscripten_bind_CLuaUnitScript_EndBurst_1, _emscripten_bind_CExtractorBuilding_FinishedBuilding_1: _emscripten_bind_CExtractorBuilding_FinishedBuilding_1, _emscripten_bind_CLuaUnitScript_EndTransport_0: _emscripten_bind_CLuaUnitScript_EndTransport_0, _emscripten_bind_CLuaUnitScript_SetSFXOccupy_1: _emscripten_bind_CLuaUnitScript_SetSFXOccupy_1, _emscripten_bind_CCommandQueue_pop_back_0: _emscripten_bind_CCommandQueue_pop_back_0, _emscripten_bind_CFactoryCAI___destroy___0: _emscripten_bind_CFactoryCAI___destroy___0, _emscripten_bind_CCustomExplosionGenerator_OutputProjectileClassInfo_0: _emscripten_bind_CCustomExplosionGenerator_OutputProjectileClassInfo_0, _emscripten_bind_CBuilderCAI_PostLoad_0: _emscripten_bind_CBuilderCAI_PostLoad_0, _i64Subtract: _i64Subtract, _emscripten_bind_CLuaUnitScript_StartBuilding_2: _emscripten_bind_CLuaUnitScript_StartBuilding_2, _emscripten_bind_CFeatureDefHandler_LoadFeatureDefsFromMap_0: _emscripten_bind_CFeatureDefHandler_LoadFeatureDefsFromMap_0, _emscripten_bind_CFeatureDefHandler___destroy___0: _emscripten_bind_CFeatureDefHandler___destroy___0, _emscripten_bind_CCircularSearchConstraint_WithinConstraints_2: _emscripten_bind_CCircularSearchConstraint_WithinConstraints_2, _emscripten_bind_CScriptMoveType_SetWantedMaxSpeed_1: _emscripten_bind_CScriptMoveType_SetWantedMaxSpeed_1, _emscripten_bind_CollisionVolume_SetBoundingRadius_0: _emscripten_bind_CollisionVolume_SetBoundingRadius_0, ___udivmoddi4: ___udivmoddi4, _emscripten_bind_CollisionVolume_GetVolumeType_0: _emscripten_bind_CollisionVolume_GetVolumeType_0, _fflush: _fflush, _emscripten_bind_CollisionVolume___destroy___0: _emscripten_bind_CollisionVolume___destroy___0, _emscripten_bind_CRectangularSearchConstraint___destroy___0: _emscripten_bind_CRectangularSearchConstraint___destroy___0, _emscripten_bind_CExtractorBuilding___destroy___0: _emscripten_bind_CExtractorBuilding___destroy___0, _emscripten_bind_CGlobalSynced_GetTempNum_0: _emscripten_bind_CGlobalSynced_GetTempNum_0, _emscripten_bind_CLuaUnitScript_Landed_0: _emscripten_bind_CLuaUnitScript_Landed_0, _emscripten_bind_CScriptMoveType_SetNoBlocking_1: _emscripten_bind_CScriptMoveType_SetNoBlocking_1, _emscripten_bind_CollisionVolume_IgnoreHits_0: _emscripten_bind_CollisionVolume_IgnoreHits_0, ___muldi3: ___muldi3, _emscripten_bind_CExtractorBuilding_SetExtractionRangeAndDepth_2: _emscripten_bind_CExtractorBuilding_SetExtractionRangeAndDepth_2, _emscripten_bind_CLuaUnitScript_StopMoving_0: _emscripten_bind_CLuaUnitScript_StopMoving_0, _emscripten_bind_CLuaUnitScript_Create_0: _emscripten_bind_CLuaUnitScript_Create_0, _bitshift64Shl: _bitshift64Shl, _emscripten_bind_CollisionVolume_DefaultToFootPrint_0: _emscripten_bind_CollisionVolume_DefaultToFootPrint_0, _emscripten_bind_CollisionVolume_DefaultToSphere_0: _emscripten_bind_CollisionVolume_DefaultToSphere_0, _emscripten_bind_CMobileCAI_FinishCommand_0: _emscripten_bind_CMobileCAI_FinishCommand_0, _emscripten_bind_CMobileCAI_StopMoveAndFinishCommand_0: _emscripten_bind_CMobileCAI_StopMoveAndFinishCommand_0, _emscripten_bind_CCollisionHandler___destroy___0: _emscripten_bind_CCollisionHandler___destroy___0, _i64Add: _i64Add, _emscripten_bind_CGeometricObjects_DeleteGroup_1: _emscripten_bind_CGeometricObjects_DeleteGroup_1, _emscripten_bind_CollisionQuery_IngressHit_0: _emscripten_bind_CollisionQuery_IngressHit_0, _emscripten_bind_CLosHandler_GetBaseRadarErrorSize_0: _emscripten_bind_CLosHandler_GetBaseRadarErrorSize_0, _emscripten_bind_CModInfo___destroy___0: _emscripten_bind_CModInfo___destroy___0, _emscripten_bind_CBuilder___destroy___0: _emscripten_bind_CBuilder___destroy___0, _emscripten_bind_CLuaUnitScript_HasTargetWeight_1: _emscripten_bind_CLuaUnitScript_HasTargetWeight_1, _emscripten_bind_CLuaUnitScript_StartUnload_0: _emscripten_bind_CLuaUnitScript_StartUnload_0, _emscripten_bind_CResourceMapAnalyzer___destroy___0: _emscripten_bind_CResourceMapAnalyzer___destroy___0, _emscripten_bind_CGeometricObjects_AddLine_6: _emscripten_bind_CGeometricObjects_AddLine_6, _emscripten_bind_CollisionVolume_GetScale_1: _emscripten_bind_CollisionVolume_GetScale_1, _emscripten_bind_CAirCAI___destroy___0: _emscripten_bind_CAirCAI___destroy___0, _emscripten_bind_CollisionVolume_UseContHitTest_0: _emscripten_bind_CollisionVolume_UseContHitTest_0, ___errno_location: ___errno_location, _emscripten_bind_CScriptMoveType_SetMaxSpeed_1: _emscripten_bind_CScriptMoveType_SetMaxSpeed_1, _emscripten_bind_CCommandQueue_pop_front_0: _emscripten_bind_CCommandQueue_pop_front_0, _emscripten_bind_CGlobalSynced_ResetState_0: _emscripten_bind_CGlobalSynced_ResetState_0, _emscripten_bind_CLuaUnitScript___destroy___0: _emscripten_bind_CLuaUnitScript___destroy___0, _emscripten_bind_CommonDefHandler___destroy___0: _emscripten_bind_CommonDefHandler___destroy___0, _emscripten_bind_ClassAliasList___destroy___0: _emscripten_bind_ClassAliasList___destroy___0, _emscripten_bind_CLuaUnitScript_QueryWeapon_1: _emscripten_bind_CLuaUnitScript_QueryWeapon_1, _emscripten_bind_CCobUnitScriptNames___destroy___0: _emscripten_bind_CCobUnitScriptNames___destroy___0, _emscripten_bind_CLuaUnitScriptNames___destroy___0: _emscripten_bind_CLuaUnitScriptNames___destroy___0, _emscripten_bind_CLuaUnitScript_HasBlockShot_1: _emscripten_bind_CLuaUnitScript_HasBlockShot_1, _emscripten_bind_CLuaUnitScript_StartBuilding_0: _emscripten_bind_CLuaUnitScript_StartBuilding_0, _emscripten_bind_CollisionVolume_InitSphere_1: _emscripten_bind_CollisionVolume_InitSphere_1, _emscripten_bind_CLosHandler_Update_0: _emscripten_bind_CLosHandler_Update_0, _emscripten_bind_CPathEstimator_MapChanged_4: _emscripten_bind_CPathEstimator_MapChanged_4, _emscripten_bind_CScriptMoveType_LeaveTransport_0: _emscripten_bind_CScriptMoveType_LeaveTransport_0, _emscripten_bind_CMobileCAI_StartSlowGuard_1: _emscripten_bind_CMobileCAI_StartSlowGuard_1, _emscripten_bind_CCannon_GetRange2D_2: _emscripten_bind_CCannon_GetRange2D_2, _emscripten_bind_CCannon_GetRange2D_1: _emscripten_bind_CCannon_GetRange2D_1, __GLOBAL__sub_I_my_glue_wrapper_cpp: __GLOBAL__sub_I_my_glue_wrapper_cpp, runPostSets: runPostSets, stackAlloc: stackAlloc, stackSave: stackSave, stackRestore: stackRestore, establishStackSpace: establishStackSpace, setThrew: setThrew, setTempRet0: setTempRet0, getTempRet0: getTempRet0, dynCall_iiii: dynCall_iiii, dynCall_vid: dynCall_vid, dynCall_viiiii: dynCall_viiiii, dynCall_i: dynCall_i, dynCall_vi: dynCall_vi, dynCall_vii: dynCall_vii, dynCall_vidd: dynCall_vidd, dynCall_ii: dynCall_ii, dynCall_viidi: dynCall_viidi, dynCall_viidd: dynCall_viidd, dynCall_v: dynCall_v, dynCall_viid: dynCall_viid, dynCall_viiiiii: dynCall_viiiiii, dynCall_iii: dynCall_iii, dynCall_viiii: dynCall_viiii };
})
// EMSCRIPTEN_END_ASM
(Module.asmGlobalArg, Module.asmLibraryArg, buffer);

var real__emscripten_bind_CCannon_SlowUpdate_0 = asm["_emscripten_bind_CCannon_SlowUpdate_0"]; asm["_emscripten_bind_CCannon_SlowUpdate_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCannon_SlowUpdate_0.apply(null, arguments);
};

var real__emscripten_bind_CWeaponLoader___destroy___0 = asm["_emscripten_bind_CWeaponLoader___destroy___0"]; asm["_emscripten_bind_CWeaponLoader___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CWeaponLoader___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CGeometricObjects_SetColor_5 = asm["_emscripten_bind_CGeometricObjects_SetColor_5"]; asm["_emscripten_bind_CGeometricObjects_SetColor_5"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGeometricObjects_SetColor_5.apply(null, arguments);
};

var real__emscripten_bind_CGlobalSynced___destroy___0 = asm["_emscripten_bind_CGlobalSynced___destroy___0"]; asm["_emscripten_bind_CGlobalSynced___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGlobalSynced___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CFactoryCAI_SlowUpdate_0 = asm["_emscripten_bind_CFactoryCAI_SlowUpdate_0"]; asm["_emscripten_bind_CFactoryCAI_SlowUpdate_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CFactoryCAI_SlowUpdate_0.apply(null, arguments);
};

var real__emscripten_bind_CBuilder_SlowUpdate_0 = asm["_emscripten_bind_CBuilder_SlowUpdate_0"]; asm["_emscripten_bind_CBuilder_SlowUpdate_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilder_SlowUpdate_0.apply(null, arguments);
};

var real__emscripten_bind_CExplosionGeneratorHandler___destroy___0 = asm["_emscripten_bind_CExplosionGeneratorHandler___destroy___0"]; asm["_emscripten_bind_CExplosionGeneratorHandler___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CExplosionGeneratorHandler___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler_GetAllyTeamRadarErrorSize_1 = asm["_emscripten_bind_CLosHandler_GetAllyTeamRadarErrorSize_1"]; asm["_emscripten_bind_CLosHandler_GetAllyTeamRadarErrorSize_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler_GetAllyTeamRadarErrorSize_1.apply(null, arguments);
};

var real__emscripten_bind_CGeometricObjects_AddSpline_8 = asm["_emscripten_bind_CGeometricObjects_AddSpline_8"]; asm["_emscripten_bind_CGeometricObjects_AddSpline_8"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGeometricObjects_AddSpline_8.apply(null, arguments);
};

var real__emscripten_bind_CModInfo_ResetState_0 = asm["_emscripten_bind_CModInfo_ResetState_0"]; asm["_emscripten_bind_CModInfo_ResetState_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CModInfo_ResetState_0.apply(null, arguments);
};

var real__emscripten_bind_CCommandQueue_clear_0 = asm["_emscripten_bind_CCommandQueue_clear_0"]; asm["_emscripten_bind_CCommandQueue_clear_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCommandQueue_clear_0.apply(null, arguments);
};

var real__bitshift64Lshr = asm["_bitshift64Lshr"]; asm["_bitshift64Lshr"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__bitshift64Lshr.apply(null, arguments);
};

var real__emscripten_bind_CBuilderCAI_SlowUpdate_0 = asm["_emscripten_bind_CBuilderCAI_SlowUpdate_0"]; asm["_emscripten_bind_CBuilderCAI_SlowUpdate_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilderCAI_SlowUpdate_0.apply(null, arguments);
};

var real__emscripten_bind_CStarburstProjectile___destroy___0 = asm["_emscripten_bind_CStarburstProjectile___destroy___0"]; asm["_emscripten_bind_CStarburstProjectile___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CStarburstProjectile___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CUnitDefHandler_IsValidUnitDefID_1 = asm["_emscripten_bind_CUnitDefHandler_IsValidUnitDefID_1"]; asm["_emscripten_bind_CUnitDefHandler_IsValidUnitDefID_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitDefHandler_IsValidUnitDefID_1.apply(null, arguments);
};

var real__emscripten_bind_CPathEstimator_Update_0 = asm["_emscripten_bind_CPathEstimator_Update_0"]; asm["_emscripten_bind_CPathEstimator_Update_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CPathEstimator_Update_0.apply(null, arguments);
};

var real__emscripten_bind_CUnitDefHandler_ProcessDecoys_0 = asm["_emscripten_bind_CUnitDefHandler_ProcessDecoys_0"]; asm["_emscripten_bind_CUnitDefHandler_ProcessDecoys_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitDefHandler_ProcessDecoys_0.apply(null, arguments);
};

var real__emscripten_bind_CCircularSearchConstraint___destroy___0 = asm["_emscripten_bind_CCircularSearchConstraint___destroy___0"]; asm["_emscripten_bind_CCircularSearchConstraint___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCircularSearchConstraint___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CBuilderCAI_FinishCommand_0 = asm["_emscripten_bind_CBuilderCAI_FinishCommand_0"]; asm["_emscripten_bind_CBuilderCAI_FinishCommand_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilderCAI_FinishCommand_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_Deactivate_0 = asm["_emscripten_bind_CLuaUnitScript_Deactivate_0"]; asm["_emscripten_bind_CLuaUnitScript_Deactivate_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_Deactivate_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_HasFunction_1 = asm["_emscripten_bind_CLuaUnitScript_HasFunction_1"]; asm["_emscripten_bind_CLuaUnitScript_HasFunction_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_HasFunction_1.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_GetHScale_1 = asm["_emscripten_bind_CollisionVolume_GetHScale_1"]; asm["_emscripten_bind_CollisionVolume_GetHScale_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_GetHScale_1.apply(null, arguments);
};

var real__sbrk = asm["_sbrk"]; asm["_sbrk"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__sbrk.apply(null, arguments);
};

var real__emscripten_bind_CMobileCAI_StopSlowGuard_0 = asm["_emscripten_bind_CMobileCAI_StopSlowGuard_0"]; asm["_emscripten_bind_CMobileCAI_StopSlowGuard_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMobileCAI_StopSlowGuard_0.apply(null, arguments);
};

var real__emscripten_bind_CWeaponDefHandler___destroy___0 = asm["_emscripten_bind_CWeaponDefHandler___destroy___0"]; asm["_emscripten_bind_CWeaponDefHandler___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CWeaponDefHandler___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_StopBuilding_0 = asm["_emscripten_bind_CLuaUnitScript_StopBuilding_0"]; asm["_emscripten_bind_CLuaUnitScript_StopBuilding_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_StopBuilding_0.apply(null, arguments);
};

var real__emscripten_bind_CMobileCAI_Execute_0 = asm["_emscripten_bind_CMobileCAI_Execute_0"]; asm["_emscripten_bind_CMobileCAI_Execute_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMobileCAI_Execute_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_Destroy_0 = asm["_emscripten_bind_CLuaUnitScript_Destroy_0"]; asm["_emscripten_bind_CLuaUnitScript_Destroy_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_Destroy_0.apply(null, arguments);
};

var real__emscripten_bind_CBuilderCAI___destroy___0 = asm["_emscripten_bind_CBuilderCAI___destroy___0"]; asm["_emscripten_bind_CBuilderCAI___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilderCAI___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CCannon___destroy___0 = asm["_emscripten_bind_CCannon___destroy___0"]; asm["_emscripten_bind_CCannon___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCannon___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_Killed_0 = asm["_emscripten_bind_CLuaUnitScript_Killed_0"]; asm["_emscripten_bind_CLuaUnitScript_Killed_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_Killed_0.apply(null, arguments);
};

var real__emscripten_bind_CBuilder_Update_0 = asm["_emscripten_bind_CBuilder_Update_0"]; asm["_emscripten_bind_CBuilder_Update_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilder_Update_0.apply(null, arguments);
};

var real____cxa_can_catch = asm["___cxa_can_catch"]; asm["___cxa_can_catch"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real____cxa_can_catch.apply(null, arguments);
};

var real__emscripten_bind_CMobileCAI_NonMoving_0 = asm["_emscripten_bind_CMobileCAI_NonMoving_0"]; asm["_emscripten_bind_CMobileCAI_NonMoving_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMobileCAI_NonMoving_0.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_DefaultToPieceTree_0 = asm["_emscripten_bind_CollisionVolume_DefaultToPieceTree_0"]; asm["_emscripten_bind_CollisionVolume_DefaultToPieceTree_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_DefaultToPieceTree_0.apply(null, arguments);
};

var real__emscripten_bind_CUnitDefHandler_AssignTechLevels_0 = asm["_emscripten_bind_CUnitDefHandler_AssignTechLevels_0"]; asm["_emscripten_bind_CUnitDefHandler_AssignTechLevels_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitDefHandler_AssignTechLevels_0.apply(null, arguments);
};

var real__emscripten_bind_CBuilder_StopBuild_1 = asm["_emscripten_bind_CBuilder_StopBuild_1"]; asm["_emscripten_bind_CBuilder_StopBuild_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilder_StopBuild_1.apply(null, arguments);
};

var real__free = asm["_free"]; asm["_free"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__free.apply(null, arguments);
};

var real__emscripten_bind_CScriptMoveType___destroy___0 = asm["_emscripten_bind_CScriptMoveType___destroy___0"]; asm["_emscripten_bind_CScriptMoveType___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CScriptMoveType___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_Falling_0 = asm["_emscripten_bind_CLuaUnitScript_Falling_0"]; asm["_emscripten_bind_CLuaUnitScript_Falling_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_Falling_0.apply(null, arguments);
};

var real__emscripten_bind_CExplosionGeneratorHandler_ParseExplosionTables_0 = asm["_emscripten_bind_CExplosionGeneratorHandler_ParseExplosionTables_0"]; asm["_emscripten_bind_CExplosionGeneratorHandler_ParseExplosionTables_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CExplosionGeneratorHandler_ParseExplosionTables_0.apply(null, arguments);
};

var real__emscripten_bind_CScriptMoveType_Update_0 = asm["_emscripten_bind_CScriptMoveType_Update_0"]; asm["_emscripten_bind_CScriptMoveType_Update_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CScriptMoveType_Update_0.apply(null, arguments);
};

var real__emscripten_bind_CGeometricObjects___destroy___0 = asm["_emscripten_bind_CGeometricObjects___destroy___0"]; asm["_emscripten_bind_CGeometricObjects___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGeometricObjects___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_DefaultToFootPrint_0 = asm["_emscripten_bind_CollisionVolume_DefaultToFootPrint_0"]; asm["_emscripten_bind_CollisionVolume_DefaultToFootPrint_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_DefaultToFootPrint_0.apply(null, arguments);
};

var real__emscripten_bind_CResourceMapAnalyzer_GetAverageIncome_0 = asm["_emscripten_bind_CResourceMapAnalyzer_GetAverageIncome_0"]; asm["_emscripten_bind_CResourceMapAnalyzer_GetAverageIncome_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CResourceMapAnalyzer_GetAverageIncome_0.apply(null, arguments);
};

var real__emscripten_bind_CollisionQuery_AnyHit_0 = asm["_emscripten_bind_CollisionQuery_AnyHit_0"]; asm["_emscripten_bind_CollisionQuery_AnyHit_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionQuery_AnyHit_0.apply(null, arguments);
};

var real__emscripten_bind_CPathEstimator___destroy___0 = asm["_emscripten_bind_CPathEstimator___destroy___0"]; asm["_emscripten_bind_CPathEstimator___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CPathEstimator___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CUnitScriptEngine_InitStatic_0 = asm["_emscripten_bind_CUnitScriptEngine_InitStatic_0"]; asm["_emscripten_bind_CUnitScriptEngine_InitStatic_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitScriptEngine_InitStatic_0.apply(null, arguments);
};

var real__emscripten_bind_CUnitScriptEngine_KillStatic_0 = asm["_emscripten_bind_CUnitScriptEngine_KillStatic_0"]; asm["_emscripten_bind_CUnitScriptEngine_KillStatic_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitScriptEngine_KillStatic_0.apply(null, arguments);
};

var real__emscripten_bind_CBuilder_StartRestore_2 = asm["_emscripten_bind_CBuilder_StartRestore_2"]; asm["_emscripten_bind_CBuilder_StartRestore_2"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilder_StartRestore_2.apply(null, arguments);
};

var real__emscripten_bind_CollisionQuery_InsideHit_0 = asm["_emscripten_bind_CollisionQuery_InsideHit_0"]; asm["_emscripten_bind_CollisionQuery_InsideHit_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionQuery_InsideHit_0.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_GetHScaleSq_1 = asm["_emscripten_bind_CollisionVolume_GetHScaleSq_1"]; asm["_emscripten_bind_CollisionVolume_GetHScaleSq_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_GetHScaleSq_1.apply(null, arguments);
};

var real__emscripten_bind_CBuilding___destroy___0 = asm["_emscripten_bind_CBuilding___destroy___0"]; asm["_emscripten_bind_CBuilding___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilding___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CUnitScriptEngine_Tick_1 = asm["_emscripten_bind_CUnitScriptEngine_Tick_1"]; asm["_emscripten_bind_CUnitScriptEngine_Tick_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitScriptEngine_Tick_1.apply(null, arguments);
};

var real__emscripten_bind_CGeometricObjects_MarkSquare_1 = asm["_emscripten_bind_CGeometricObjects_MarkSquare_1"]; asm["_emscripten_bind_CGeometricObjects_MarkSquare_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGeometricObjects_MarkSquare_1.apply(null, arguments);
};

var real__emscripten_bind_CFactory___destroy___0 = asm["_emscripten_bind_CFactory___destroy___0"]; asm["_emscripten_bind_CFactory___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CFactory___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CCannon_Init_0 = asm["_emscripten_bind_CCannon_Init_0"]; asm["_emscripten_bind_CCannon_Init_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCannon_Init_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_ExtractionRateChanged_1 = asm["_emscripten_bind_CLuaUnitScript_ExtractionRateChanged_1"]; asm["_emscripten_bind_CLuaUnitScript_ExtractionRateChanged_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_ExtractionRateChanged_1.apply(null, arguments);
};

var real__emscripten_bind_CCannon_UpdateRange_1 = asm["_emscripten_bind_CCannon_UpdateRange_1"]; asm["_emscripten_bind_CCannon_UpdateRange_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCannon_UpdateRange_1.apply(null, arguments);
};

var real__emscripten_bind_CFactory_Update_0 = asm["_emscripten_bind_CFactory_Update_0"]; asm["_emscripten_bind_CFactory_Update_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CFactory_Update_0.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler_SetBaseRadarErrorSize_1 = asm["_emscripten_bind_CLosHandler_SetBaseRadarErrorSize_1"]; asm["_emscripten_bind_CLosHandler_SetBaseRadarErrorSize_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler_SetBaseRadarErrorSize_1.apply(null, arguments);
};

var real__emscripten_bind_CRectangularSearchConstraint_WithinConstraints_2 = asm["_emscripten_bind_CRectangularSearchConstraint_WithinConstraints_2"]; asm["_emscripten_bind_CRectangularSearchConstraint_WithinConstraints_2"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CRectangularSearchConstraint_WithinConstraints_2.apply(null, arguments);
};

var real__emscripten_bind_CExtractorBuilding_ResetExtraction_0 = asm["_emscripten_bind_CExtractorBuilding_ResetExtraction_0"]; asm["_emscripten_bind_CExtractorBuilding_ResetExtraction_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CExtractorBuilding_ResetExtraction_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_WindChanged_2 = asm["_emscripten_bind_CLuaUnitScript_WindChanged_2"]; asm["_emscripten_bind_CLuaUnitScript_WindChanged_2"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_WindChanged_2.apply(null, arguments);
};

var real__emscripten_bind_CMobileCAI_CanSetMaxSpeed_0 = asm["_emscripten_bind_CMobileCAI_CanSetMaxSpeed_0"]; asm["_emscripten_bind_CMobileCAI_CanSetMaxSpeed_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMobileCAI_CanSetMaxSpeed_0.apply(null, arguments);
};

var real__emscripten_bind_CUnitDefHandler_ToggleNoCost_0 = asm["_emscripten_bind_CUnitDefHandler_ToggleNoCost_0"]; asm["_emscripten_bind_CUnitDefHandler_ToggleNoCost_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitDefHandler_ToggleNoCost_0.apply(null, arguments);
};

var real__emscripten_bind_CAirCAI_SlowUpdate_0 = asm["_emscripten_bind_CAirCAI_SlowUpdate_0"]; asm["_emscripten_bind_CAirCAI_SlowUpdate_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CAirCAI_SlowUpdate_0.apply(null, arguments);
};

var real____cxa_is_pointer_type = asm["___cxa_is_pointer_type"]; asm["___cxa_is_pointer_type"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real____cxa_is_pointer_type.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler_GetFullRead_0 = asm["_emscripten_bind_CLosHandler_GetFullRead_0"]; asm["_emscripten_bind_CLosHandler_GetFullRead_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler_GetFullRead_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_Activate_0 = asm["_emscripten_bind_CLuaUnitScript_Activate_0"]; asm["_emscripten_bind_CLuaUnitScript_Activate_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_Activate_0.apply(null, arguments);
};

var real__llvm_cttz_i32 = asm["_llvm_cttz_i32"]; asm["_llvm_cttz_i32"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__llvm_cttz_i32.apply(null, arguments);
};

var real__emscripten_bind_CScriptMoveType_SetHeading_1 = asm["_emscripten_bind_CScriptMoveType_SetHeading_1"]; asm["_emscripten_bind_CScriptMoveType_SetHeading_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CScriptMoveType_SetHeading_1.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler_GetBaseRadarErrorMult_0 = asm["_emscripten_bind_CLosHandler_GetBaseRadarErrorMult_0"]; asm["_emscripten_bind_CLosHandler_GetBaseRadarErrorMult_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler_GetBaseRadarErrorMult_0.apply(null, arguments);
};

var real__emscripten_bind_CLosMap___destroy___0 = asm["_emscripten_bind_CLosMap___destroy___0"]; asm["_emscripten_bind_CLosMap___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosMap___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_MoveRate_1 = asm["_emscripten_bind_CLuaUnitScript_MoveRate_1"]; asm["_emscripten_bind_CLuaUnitScript_MoveRate_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_MoveRate_1.apply(null, arguments);
};

var real__emscripten_bind_CCannon_UpdateWantedDir_0 = asm["_emscripten_bind_CCannon_UpdateWantedDir_0"]; asm["_emscripten_bind_CCannon_UpdateWantedDir_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCannon_UpdateWantedDir_0.apply(null, arguments);
};

var real__emscripten_bind_CUnitDefHandler_Init_0 = asm["_emscripten_bind_CUnitDefHandler_Init_0"]; asm["_emscripten_bind_CUnitDefHandler_Init_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitDefHandler_Init_0.apply(null, arguments);
};

var real__emscripten_bind_CScriptMoveType_ForceUpdates_0 = asm["_emscripten_bind_CScriptMoveType_ForceUpdates_0"]; asm["_emscripten_bind_CScriptMoveType_ForceUpdates_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CScriptMoveType_ForceUpdates_0.apply(null, arguments);
};

var real__emscripten_bind_CBuilder_ScriptStartBuilding_2 = asm["_emscripten_bind_CBuilder_ScriptStartBuilding_2"]; asm["_emscripten_bind_CBuilder_ScriptStartBuilding_2"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilder_ScriptStartBuilding_2.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler_GetBaseRadarErrorSize_0 = asm["_emscripten_bind_CLosHandler_GetBaseRadarErrorSize_0"]; asm["_emscripten_bind_CLosHandler_GetBaseRadarErrorSize_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler_GetBaseRadarErrorSize_0.apply(null, arguments);
};

var real__emscripten_bind_CFactory_CreateNanoParticle_1 = asm["_emscripten_bind_CFactory_CreateNanoParticle_1"]; asm["_emscripten_bind_CFactory_CreateNanoParticle_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CFactory_CreateNanoParticle_1.apply(null, arguments);
};

var real__emscripten_bind_CCustomExplosionGenerator_GetFlagsFromHeight_2 = asm["_emscripten_bind_CCustomExplosionGenerator_GetFlagsFromHeight_2"]; asm["_emscripten_bind_CCustomExplosionGenerator_GetFlagsFromHeight_2"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCustomExplosionGenerator_GetFlagsFromHeight_2.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler_SetBaseRadarErrorMult_1 = asm["_emscripten_bind_CLosHandler_SetBaseRadarErrorMult_1"]; asm["_emscripten_bind_CLosHandler_SetBaseRadarErrorMult_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler_SetBaseRadarErrorMult_1.apply(null, arguments);
};

var real__emscripten_bind_ClassAliasList_Clear_0 = asm["_emscripten_bind_ClassAliasList_Clear_0"]; asm["_emscripten_bind_ClassAliasList_Clear_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_ClassAliasList_Clear_0.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler_DecreaseAllyTeamRadarErrorSize_1 = asm["_emscripten_bind_CLosHandler_DecreaseAllyTeamRadarErrorSize_1"]; asm["_emscripten_bind_CLosHandler_DecreaseAllyTeamRadarErrorSize_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler_DecreaseAllyTeamRadarErrorSize_1.apply(null, arguments);
};

var real__emscripten_bind_CFactory_StopBuild_0 = asm["_emscripten_bind_CFactory_StopBuild_0"]; asm["_emscripten_bind_CFactory_StopBuild_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CFactory_StopBuild_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_FireWeapon_1 = asm["_emscripten_bind_CLuaUnitScript_FireWeapon_1"]; asm["_emscripten_bind_CLuaUnitScript_FireWeapon_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_FireWeapon_1.apply(null, arguments);
};

var real__emscripten_bind_CAirCAI___destroy___0 = asm["_emscripten_bind_CAirCAI___destroy___0"]; asm["_emscripten_bind_CAirCAI___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CAirCAI___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_HasBlockShot_1 = asm["_emscripten_bind_CLuaUnitScript_HasBlockShot_1"]; asm["_emscripten_bind_CLuaUnitScript_HasBlockShot_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_HasBlockShot_1.apply(null, arguments);
};

var real__emscripten_bind_CScriptMoveType_LeaveTransport_0 = asm["_emscripten_bind_CScriptMoveType_LeaveTransport_0"]; asm["_emscripten_bind_CScriptMoveType_LeaveTransport_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CScriptMoveType_LeaveTransport_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_HasTargetWeight_1 = asm["_emscripten_bind_CLuaUnitScript_HasTargetWeight_1"]; asm["_emscripten_bind_CLuaUnitScript_HasTargetWeight_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_HasTargetWeight_1.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_EndTransport_0 = asm["_emscripten_bind_CLuaUnitScript_EndTransport_0"]; asm["_emscripten_bind_CLuaUnitScript_EndTransport_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_EndTransport_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_QueryNanoPiece_0 = asm["_emscripten_bind_CLuaUnitScript_QueryNanoPiece_0"]; asm["_emscripten_bind_CLuaUnitScript_QueryNanoPiece_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_QueryNanoPiece_0.apply(null, arguments);
};

var real__emscripten_bind_CMobileCAI___destroy___0 = asm["_emscripten_bind_CMobileCAI___destroy___0"]; asm["_emscripten_bind_CMobileCAI___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMobileCAI___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CUnitScriptFactory___destroy___0 = asm["_emscripten_bind_CUnitScriptFactory___destroy___0"]; asm["_emscripten_bind_CUnitScriptFactory___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitScriptFactory___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CollisionQuery___destroy___0 = asm["_emscripten_bind_CollisionQuery___destroy___0"]; asm["_emscripten_bind_CollisionQuery___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionQuery___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CGeometricObjects_Update_0 = asm["_emscripten_bind_CGeometricObjects_Update_0"]; asm["_emscripten_bind_CGeometricObjects_Update_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGeometricObjects_Update_0.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_InitSphere_1 = asm["_emscripten_bind_CollisionVolume_InitSphere_1"]; asm["_emscripten_bind_CollisionVolume_InitSphere_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_InitSphere_1.apply(null, arguments);
};

var real__emscripten_bind_CMobileCAI_StopMove_0 = asm["_emscripten_bind_CMobileCAI_StopMove_0"]; asm["_emscripten_bind_CMobileCAI_StopMove_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMobileCAI_StopMove_0.apply(null, arguments);
};

var real__emscripten_bind_CMobileCAI_SlowUpdate_0 = asm["_emscripten_bind_CMobileCAI_SlowUpdate_0"]; asm["_emscripten_bind_CMobileCAI_SlowUpdate_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMobileCAI_SlowUpdate_0.apply(null, arguments);
};

var real__emscripten_bind_CExplosionCreator___destroy___0 = asm["_emscripten_bind_CExplosionCreator___destroy___0"]; asm["_emscripten_bind_CExplosionCreator___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CExplosionCreator___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CUnitLoader___destroy___0 = asm["_emscripten_bind_CUnitLoader___destroy___0"]; asm["_emscripten_bind_CUnitLoader___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitLoader___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler___destroy___0 = asm["_emscripten_bind_CLosHandler___destroy___0"]; asm["_emscripten_bind_CLosHandler___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_QueryBuildInfo_0 = asm["_emscripten_bind_CLuaUnitScript_QueryBuildInfo_0"]; asm["_emscripten_bind_CLuaUnitScript_QueryBuildInfo_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_QueryBuildInfo_0.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_SetDefaultToFootPrint_1 = asm["_emscripten_bind_CollisionVolume_SetDefaultToFootPrint_1"]; asm["_emscripten_bind_CollisionVolume_SetDefaultToFootPrint_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_SetDefaultToFootPrint_1.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_SetVolumeType_1 = asm["_emscripten_bind_CollisionVolume_SetVolumeType_1"]; asm["_emscripten_bind_CollisionVolume_SetVolumeType_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_SetVolumeType_1.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_SetUseContHitTest_1 = asm["_emscripten_bind_CollisionVolume_SetUseContHitTest_1"]; asm["_emscripten_bind_CollisionVolume_SetUseContHitTest_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_SetUseContHitTest_1.apply(null, arguments);
};

var real__emscripten_bind_CCollisionHandler_PrintStats_0 = asm["_emscripten_bind_CCollisionHandler_PrintStats_0"]; asm["_emscripten_bind_CCollisionHandler_PrintStats_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCollisionHandler_PrintStats_0.apply(null, arguments);
};

var real__emscripten_bind_CExtractorBuilding_ReCalculateMetalExtraction_0 = asm["_emscripten_bind_CExtractorBuilding_ReCalculateMetalExtraction_0"]; asm["_emscripten_bind_CExtractorBuilding_ReCalculateMetalExtraction_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CExtractorBuilding_ReCalculateMetalExtraction_0.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_GetPrimaryAxis_0 = asm["_emscripten_bind_CollisionVolume_GetPrimaryAxis_0"]; asm["_emscripten_bind_CollisionVolume_GetPrimaryAxis_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_GetPrimaryAxis_0.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_SetDefaultToPieceTree_1 = asm["_emscripten_bind_CollisionVolume_SetDefaultToPieceTree_1"]; asm["_emscripten_bind_CollisionVolume_SetDefaultToPieceTree_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_SetDefaultToPieceTree_1.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler_GetReadAllyTeam_0 = asm["_emscripten_bind_CLosHandler_GetReadAllyTeam_0"]; asm["_emscripten_bind_CLosHandler_GetReadAllyTeam_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler_GetReadAllyTeam_0.apply(null, arguments);
};

var real___GLOBAL__sub_I_my_glue_wrapper_cpp = asm["__GLOBAL__sub_I_my_glue_wrapper_cpp"]; asm["__GLOBAL__sub_I_my_glue_wrapper_cpp"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real___GLOBAL__sub_I_my_glue_wrapper_cpp.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler_SetAllyTeamRadarErrorSize_2 = asm["_emscripten_bind_CLosHandler_SetAllyTeamRadarErrorSize_2"]; asm["_emscripten_bind_CLosHandler_SetAllyTeamRadarErrorSize_2"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler_SetAllyTeamRadarErrorSize_2.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_RawCall_1 = asm["_emscripten_bind_CLuaUnitScript_RawCall_1"]; asm["_emscripten_bind_CLuaUnitScript_RawCall_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_RawCall_1.apply(null, arguments);
};

var real__emscripten_bind_CollisionQuery_EgressHit_0 = asm["_emscripten_bind_CollisionQuery_EgressHit_0"]; asm["_emscripten_bind_CollisionQuery_EgressHit_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionQuery_EgressHit_0.apply(null, arguments);
};

var real__emscripten_bind_VoidPtr___destroy___0 = asm["_emscripten_bind_VoidPtr___destroy___0"]; asm["_emscripten_bind_VoidPtr___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_VoidPtr___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CScriptMoveType_KeepPointingTo_3 = asm["_emscripten_bind_CScriptMoveType_KeepPointingTo_3"]; asm["_emscripten_bind_CScriptMoveType_KeepPointingTo_3"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CScriptMoveType_KeepPointingTo_3.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_StartMoving_1 = asm["_emscripten_bind_CLuaUnitScript_StartMoving_1"]; asm["_emscripten_bind_CLuaUnitScript_StartMoving_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_StartMoving_1.apply(null, arguments);
};

var real__emscripten_bind_CGlobalSynced_GetLuaSimFrame_0 = asm["_emscripten_bind_CGlobalSynced_GetLuaSimFrame_0"]; asm["_emscripten_bind_CGlobalSynced_GetLuaSimFrame_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGlobalSynced_GetLuaSimFrame_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_AimWeapon_3 = asm["_emscripten_bind_CLuaUnitScript_AimWeapon_3"]; asm["_emscripten_bind_CLuaUnitScript_AimWeapon_3"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_AimWeapon_3.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_GetBoundingRadius_0 = asm["_emscripten_bind_CollisionVolume_GetBoundingRadius_0"]; asm["_emscripten_bind_CollisionVolume_GetBoundingRadius_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_GetBoundingRadius_0.apply(null, arguments);
};

var real__emscripten_bind_CExtractorBuilding_FinishedBuilding_1 = asm["_emscripten_bind_CExtractorBuilding_FinishedBuilding_1"]; asm["_emscripten_bind_CExtractorBuilding_FinishedBuilding_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CExtractorBuilding_FinishedBuilding_1.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_GetBoundingRadiusSq_0 = asm["_emscripten_bind_CollisionVolume_GetBoundingRadiusSq_0"]; asm["_emscripten_bind_CollisionVolume_GetBoundingRadiusSq_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_GetBoundingRadiusSq_0.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_PostLoad_0 = asm["_emscripten_bind_CollisionVolume_PostLoad_0"]; asm["_emscripten_bind_CollisionVolume_PostLoad_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_PostLoad_0.apply(null, arguments);
};

var real__emscripten_bind_CScriptMoveType_StopMoving_3 = asm["_emscripten_bind_CScriptMoveType_StopMoving_3"]; asm["_emscripten_bind_CScriptMoveType_StopMoving_3"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CScriptMoveType_StopMoving_3.apply(null, arguments);
};

var real__emscripten_bind_CUnitDefHandler___destroy___0 = asm["_emscripten_bind_CUnitDefHandler___destroy___0"]; asm["_emscripten_bind_CUnitDefHandler___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitDefHandler___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CAirCAI_FinishCommand_0 = asm["_emscripten_bind_CAirCAI_FinishCommand_0"]; asm["_emscripten_bind_CAirCAI_FinishCommand_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CAirCAI_FinishCommand_0.apply(null, arguments);
};

var real__emscripten_bind_CGlobalSynced_PreSimFrame_0 = asm["_emscripten_bind_CGlobalSynced_PreSimFrame_0"]; asm["_emscripten_bind_CGlobalSynced_PreSimFrame_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGlobalSynced_PreSimFrame_0.apply(null, arguments);
};

var real__emscripten_bind_CUnitScriptEngine___destroy___0 = asm["_emscripten_bind_CUnitScriptEngine___destroy___0"]; asm["_emscripten_bind_CUnitScriptEngine___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CUnitScriptEngine___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CExtractorBuilding_GetExtractionRange_0 = asm["_emscripten_bind_CExtractorBuilding_GetExtractionRange_0"]; asm["_emscripten_bind_CExtractorBuilding_GetExtractionRange_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CExtractorBuilding_GetExtractionRange_0.apply(null, arguments);
};

var real__emscripten_bind_CMoveMath___destroy___0 = asm["_emscripten_bind_CMoveMath___destroy___0"]; asm["_emscripten_bind_CMoveMath___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMoveMath___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_AimFromWeapon_1 = asm["_emscripten_bind_CLuaUnitScript_AimFromWeapon_1"]; asm["_emscripten_bind_CLuaUnitScript_AimFromWeapon_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_AimFromWeapon_1.apply(null, arguments);
};

var real__emscripten_bind_CCommandQueue___destroy___0 = asm["_emscripten_bind_CCommandQueue___destroy___0"]; asm["_emscripten_bind_CCommandQueue___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCommandQueue___destroy___0.apply(null, arguments);
};

var real____muldsi3 = asm["___muldsi3"]; asm["___muldsi3"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real____muldsi3.apply(null, arguments);
};

var real__emscripten_bind_CCommandQueue_empty_0 = asm["_emscripten_bind_CCommandQueue_empty_0"]; asm["_emscripten_bind_CCommandQueue_empty_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCommandQueue_empty_0.apply(null, arguments);
};

var real__emscripten_bind_CScriptMoveType_StartMoving_2 = asm["_emscripten_bind_CScriptMoveType_StartMoving_2"]; asm["_emscripten_bind_CScriptMoveType_StartMoving_2"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CScriptMoveType_StartMoving_2.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_GetSecondaryAxis_1 = asm["_emscripten_bind_CollisionVolume_GetSecondaryAxis_1"]; asm["_emscripten_bind_CollisionVolume_GetSecondaryAxis_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_GetSecondaryAxis_1.apply(null, arguments);
};

var real__emscripten_bind_CCustomExplosionGenerator___destroy___0 = asm["_emscripten_bind_CCustomExplosionGenerator___destroy___0"]; asm["_emscripten_bind_CCustomExplosionGenerator___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCustomExplosionGenerator___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler_IncreaseAllyTeamRadarErrorSize_1 = asm["_emscripten_bind_CLosHandler_IncreaseAllyTeamRadarErrorSize_1"]; asm["_emscripten_bind_CLosHandler_IncreaseAllyTeamRadarErrorSize_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler_IncreaseAllyTeamRadarErrorSize_1.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_GetOffset_1 = asm["_emscripten_bind_CollisionVolume_GetOffset_1"]; asm["_emscripten_bind_CollisionVolume_GetOffset_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_GetOffset_1.apply(null, arguments);
};

var real__emscripten_bind_CFeatureDefHandler_LoadFeatureDefsFromMap_0 = asm["_emscripten_bind_CFeatureDefHandler_LoadFeatureDefsFromMap_0"]; asm["_emscripten_bind_CFeatureDefHandler_LoadFeatureDefsFromMap_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CFeatureDefHandler_LoadFeatureDefsFromMap_0.apply(null, arguments);
};

var real__emscripten_bind_CLosHandler_Update_0 = asm["_emscripten_bind_CLosHandler_Update_0"]; asm["_emscripten_bind_CLosHandler_Update_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLosHandler_Update_0.apply(null, arguments);
};

var real__malloc = asm["_malloc"]; asm["_malloc"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__malloc.apply(null, arguments);
};

var real__emscripten_bind_CMobileCAI_GetCancelDistance_0 = asm["_emscripten_bind_CMobileCAI_GetCancelDistance_0"]; asm["_emscripten_bind_CMobileCAI_GetCancelDistance_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMobileCAI_GetCancelDistance_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_SetSFXOccupy_1 = asm["_emscripten_bind_CLuaUnitScript_SetSFXOccupy_1"]; asm["_emscripten_bind_CLuaUnitScript_SetSFXOccupy_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_SetSFXOccupy_1.apply(null, arguments);
};

var real__emscripten_bind_CCommandQueue_pop_back_0 = asm["_emscripten_bind_CCommandQueue_pop_back_0"]; asm["_emscripten_bind_CCommandQueue_pop_back_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCommandQueue_pop_back_0.apply(null, arguments);
};

var real__emscripten_bind_CFactoryCAI___destroy___0 = asm["_emscripten_bind_CFactoryCAI___destroy___0"]; asm["_emscripten_bind_CFactoryCAI___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CFactoryCAI___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CCobUnitScriptNames___destroy___0 = asm["_emscripten_bind_CCobUnitScriptNames___destroy___0"]; asm["_emscripten_bind_CCobUnitScriptNames___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCobUnitScriptNames___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CBuilderCAI_PostLoad_0 = asm["_emscripten_bind_CBuilderCAI_PostLoad_0"]; asm["_emscripten_bind_CBuilderCAI_PostLoad_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilderCAI_PostLoad_0.apply(null, arguments);
};

var real__emscripten_bind_CommonDefHandler___destroy___0 = asm["_emscripten_bind_CommonDefHandler___destroy___0"]; asm["_emscripten_bind_CommonDefHandler___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CommonDefHandler___destroy___0.apply(null, arguments);
};

var real__i64Subtract = asm["_i64Subtract"]; asm["_i64Subtract"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__i64Subtract.apply(null, arguments);
};

var real____udivdi3 = asm["___udivdi3"]; asm["___udivdi3"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real____udivdi3.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_EndBurst_1 = asm["_emscripten_bind_CLuaUnitScript_EndBurst_1"]; asm["_emscripten_bind_CLuaUnitScript_EndBurst_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_EndBurst_1.apply(null, arguments);
};

var real__emscripten_bind_CFeatureDefHandler___destroy___0 = asm["_emscripten_bind_CFeatureDefHandler___destroy___0"]; asm["_emscripten_bind_CFeatureDefHandler___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CFeatureDefHandler___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CCircularSearchConstraint_WithinConstraints_2 = asm["_emscripten_bind_CCircularSearchConstraint_WithinConstraints_2"]; asm["_emscripten_bind_CCircularSearchConstraint_WithinConstraints_2"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCircularSearchConstraint_WithinConstraints_2.apply(null, arguments);
};

var real__emscripten_bind_CScriptMoveType_SetWantedMaxSpeed_1 = asm["_emscripten_bind_CScriptMoveType_SetWantedMaxSpeed_1"]; asm["_emscripten_bind_CScriptMoveType_SetWantedMaxSpeed_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CScriptMoveType_SetWantedMaxSpeed_1.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_SetBoundingRadius_0 = asm["_emscripten_bind_CollisionVolume_SetBoundingRadius_0"]; asm["_emscripten_bind_CollisionVolume_SetBoundingRadius_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_SetBoundingRadius_0.apply(null, arguments);
};

var real____udivmoddi4 = asm["___udivmoddi4"]; asm["___udivmoddi4"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real____udivmoddi4.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_GetVolumeType_0 = asm["_emscripten_bind_CollisionVolume_GetVolumeType_0"]; asm["_emscripten_bind_CollisionVolume_GetVolumeType_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_GetVolumeType_0.apply(null, arguments);
};

var real__emscripten_bind_CGeometricObjects_DeleteGroup_1 = asm["_emscripten_bind_CGeometricObjects_DeleteGroup_1"]; asm["_emscripten_bind_CGeometricObjects_DeleteGroup_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGeometricObjects_DeleteGroup_1.apply(null, arguments);
};

var real__fflush = asm["_fflush"]; asm["_fflush"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__fflush.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume___destroy___0 = asm["_emscripten_bind_CollisionVolume___destroy___0"]; asm["_emscripten_bind_CollisionVolume___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CRectangularSearchConstraint___destroy___0 = asm["_emscripten_bind_CRectangularSearchConstraint___destroy___0"]; asm["_emscripten_bind_CRectangularSearchConstraint___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CRectangularSearchConstraint___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CExtractorBuilding___destroy___0 = asm["_emscripten_bind_CExtractorBuilding___destroy___0"]; asm["_emscripten_bind_CExtractorBuilding___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CExtractorBuilding___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CGlobalSynced_GetTempNum_0 = asm["_emscripten_bind_CGlobalSynced_GetTempNum_0"]; asm["_emscripten_bind_CGlobalSynced_GetTempNum_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGlobalSynced_GetTempNum_0.apply(null, arguments);
};

var real__emscripten_bind_CScriptMoveType_SetNoBlocking_1 = asm["_emscripten_bind_CScriptMoveType_SetNoBlocking_1"]; asm["_emscripten_bind_CScriptMoveType_SetNoBlocking_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CScriptMoveType_SetNoBlocking_1.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_IgnoreHits_0 = asm["_emscripten_bind_CollisionVolume_IgnoreHits_0"]; asm["_emscripten_bind_CollisionVolume_IgnoreHits_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_IgnoreHits_0.apply(null, arguments);
};

var real____muldi3 = asm["___muldi3"]; asm["___muldi3"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real____muldi3.apply(null, arguments);
};

var real__emscripten_bind_CExtractorBuilding_SetExtractionRangeAndDepth_2 = asm["_emscripten_bind_CExtractorBuilding_SetExtractionRangeAndDepth_2"]; asm["_emscripten_bind_CExtractorBuilding_SetExtractionRangeAndDepth_2"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CExtractorBuilding_SetExtractionRangeAndDepth_2.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_StopMoving_0 = asm["_emscripten_bind_CLuaUnitScript_StopMoving_0"]; asm["_emscripten_bind_CLuaUnitScript_StopMoving_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_StopMoving_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_Create_0 = asm["_emscripten_bind_CLuaUnitScript_Create_0"]; asm["_emscripten_bind_CLuaUnitScript_Create_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_Create_0.apply(null, arguments);
};

var real__bitshift64Shl = asm["_bitshift64Shl"]; asm["_bitshift64Shl"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__bitshift64Shl.apply(null, arguments);
};

var real____uremdi3 = asm["___uremdi3"]; asm["___uremdi3"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real____uremdi3.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_DefaultToSphere_0 = asm["_emscripten_bind_CollisionVolume_DefaultToSphere_0"]; asm["_emscripten_bind_CollisionVolume_DefaultToSphere_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_DefaultToSphere_0.apply(null, arguments);
};

var real__emscripten_bind_CMobileCAI_FinishCommand_0 = asm["_emscripten_bind_CMobileCAI_FinishCommand_0"]; asm["_emscripten_bind_CMobileCAI_FinishCommand_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMobileCAI_FinishCommand_0.apply(null, arguments);
};

var real__emscripten_bind_CMobileCAI_StopMoveAndFinishCommand_0 = asm["_emscripten_bind_CMobileCAI_StopMoveAndFinishCommand_0"]; asm["_emscripten_bind_CMobileCAI_StopMoveAndFinishCommand_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMobileCAI_StopMoveAndFinishCommand_0.apply(null, arguments);
};

var real__emscripten_bind_CCollisionHandler___destroy___0 = asm["_emscripten_bind_CCollisionHandler___destroy___0"]; asm["_emscripten_bind_CCollisionHandler___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCollisionHandler___destroy___0.apply(null, arguments);
};

var real__i64Add = asm["_i64Add"]; asm["_i64Add"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__i64Add.apply(null, arguments);
};

var real__emscripten_bind_CPathEstimator_GetPathChecksum_0 = asm["_emscripten_bind_CPathEstimator_GetPathChecksum_0"]; asm["_emscripten_bind_CPathEstimator_GetPathChecksum_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CPathEstimator_GetPathChecksum_0.apply(null, arguments);
};

var real__emscripten_bind_CollisionQuery_IngressHit_0 = asm["_emscripten_bind_CollisionQuery_IngressHit_0"]; asm["_emscripten_bind_CollisionQuery_IngressHit_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionQuery_IngressHit_0.apply(null, arguments);
};

var real__pthread_self = asm["_pthread_self"]; asm["_pthread_self"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__pthread_self.apply(null, arguments);
};

var real__emscripten_bind_CModInfo___destroy___0 = asm["_emscripten_bind_CModInfo___destroy___0"]; asm["_emscripten_bind_CModInfo___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CModInfo___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CBuilder___destroy___0 = asm["_emscripten_bind_CBuilder___destroy___0"]; asm["_emscripten_bind_CBuilder___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilder___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CExtractorBuilding_GetExtractionDepth_0 = asm["_emscripten_bind_CExtractorBuilding_GetExtractionDepth_0"]; asm["_emscripten_bind_CExtractorBuilding_GetExtractionDepth_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CExtractorBuilding_GetExtractionDepth_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_StartUnload_0 = asm["_emscripten_bind_CLuaUnitScript_StartUnload_0"]; asm["_emscripten_bind_CLuaUnitScript_StartUnload_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_StartUnload_0.apply(null, arguments);
};

var real__emscripten_bind_CResourceMapAnalyzer___destroy___0 = asm["_emscripten_bind_CResourceMapAnalyzer___destroy___0"]; asm["_emscripten_bind_CResourceMapAnalyzer___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CResourceMapAnalyzer___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CGeometricObjects_AddLine_6 = asm["_emscripten_bind_CGeometricObjects_AddLine_6"]; asm["_emscripten_bind_CGeometricObjects_AddLine_6"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGeometricObjects_AddLine_6.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_GetScale_1 = asm["_emscripten_bind_CollisionVolume_GetScale_1"]; asm["_emscripten_bind_CollisionVolume_GetScale_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_GetScale_1.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_Landed_0 = asm["_emscripten_bind_CLuaUnitScript_Landed_0"]; asm["_emscripten_bind_CLuaUnitScript_Landed_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_Landed_0.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_UseContHitTest_0 = asm["_emscripten_bind_CollisionVolume_UseContHitTest_0"]; asm["_emscripten_bind_CollisionVolume_UseContHitTest_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_UseContHitTest_0.apply(null, arguments);
};

var real____errno_location = asm["___errno_location"]; asm["___errno_location"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real____errno_location.apply(null, arguments);
};

var real__emscripten_bind_CScriptMoveType_SetMaxSpeed_1 = asm["_emscripten_bind_CScriptMoveType_SetMaxSpeed_1"]; asm["_emscripten_bind_CScriptMoveType_SetMaxSpeed_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CScriptMoveType_SetMaxSpeed_1.apply(null, arguments);
};

var real__emscripten_bind_CCommandQueue_pop_front_0 = asm["_emscripten_bind_CCommandQueue_pop_front_0"]; asm["_emscripten_bind_CCommandQueue_pop_front_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCommandQueue_pop_front_0.apply(null, arguments);
};

var real__emscripten_bind_CGlobalSynced_ResetState_0 = asm["_emscripten_bind_CGlobalSynced_ResetState_0"]; asm["_emscripten_bind_CGlobalSynced_ResetState_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CGlobalSynced_ResetState_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript___destroy___0 = asm["_emscripten_bind_CLuaUnitScript___destroy___0"]; asm["_emscripten_bind_CLuaUnitScript___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_Shot_1 = asm["_emscripten_bind_CLuaUnitScript_Shot_1"]; asm["_emscripten_bind_CLuaUnitScript_Shot_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_Shot_1.apply(null, arguments);
};

var real__emscripten_bind_ClassAliasList___destroy___0 = asm["_emscripten_bind_ClassAliasList___destroy___0"]; asm["_emscripten_bind_ClassAliasList___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_ClassAliasList___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CCannon_GetRange2D_2 = asm["_emscripten_bind_CCannon_GetRange2D_2"]; asm["_emscripten_bind_CCannon_GetRange2D_2"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCannon_GetRange2D_2.apply(null, arguments);
};

var real__emscripten_bind_CCustomExplosionGenerator_OutputProjectileClassInfo_0 = asm["_emscripten_bind_CCustomExplosionGenerator_OutputProjectileClassInfo_0"]; asm["_emscripten_bind_CCustomExplosionGenerator_OutputProjectileClassInfo_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCustomExplosionGenerator_OutputProjectileClassInfo_0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScriptNames___destroy___0 = asm["_emscripten_bind_CLuaUnitScriptNames___destroy___0"]; asm["_emscripten_bind_CLuaUnitScriptNames___destroy___0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScriptNames___destroy___0.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_StartBuilding_2 = asm["_emscripten_bind_CLuaUnitScript_StartBuilding_2"]; asm["_emscripten_bind_CLuaUnitScript_StartBuilding_2"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_StartBuilding_2.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_StartBuilding_0 = asm["_emscripten_bind_CLuaUnitScript_StartBuilding_0"]; asm["_emscripten_bind_CLuaUnitScript_StartBuilding_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_StartBuilding_0.apply(null, arguments);
};

var real__emscripten_bind_CollisionVolume_SetIgnoreHits_1 = asm["_emscripten_bind_CollisionVolume_SetIgnoreHits_1"]; asm["_emscripten_bind_CollisionVolume_SetIgnoreHits_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CollisionVolume_SetIgnoreHits_1.apply(null, arguments);
};

var real__emscripten_bind_CPathEstimator_MapChanged_4 = asm["_emscripten_bind_CPathEstimator_MapChanged_4"]; asm["_emscripten_bind_CPathEstimator_MapChanged_4"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CPathEstimator_MapChanged_4.apply(null, arguments);
};

var real__emscripten_bind_CBuilderCAI_InitStatic_0 = asm["_emscripten_bind_CBuilderCAI_InitStatic_0"]; asm["_emscripten_bind_CBuilderCAI_InitStatic_0"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CBuilderCAI_InitStatic_0.apply(null, arguments);
};

var real__emscripten_bind_CMobileCAI_StartSlowGuard_1 = asm["_emscripten_bind_CMobileCAI_StartSlowGuard_1"]; asm["_emscripten_bind_CMobileCAI_StartSlowGuard_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CMobileCAI_StartSlowGuard_1.apply(null, arguments);
};

var real__emscripten_bind_CLuaUnitScript_QueryWeapon_1 = asm["_emscripten_bind_CLuaUnitScript_QueryWeapon_1"]; asm["_emscripten_bind_CLuaUnitScript_QueryWeapon_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CLuaUnitScript_QueryWeapon_1.apply(null, arguments);
};

var real__emscripten_bind_CCannon_GetRange2D_1 = asm["_emscripten_bind_CCannon_GetRange2D_1"]; asm["_emscripten_bind_CCannon_GetRange2D_1"] = function() {
assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
return real__emscripten_bind_CCannon_GetRange2D_1.apply(null, arguments);
};
var _emscripten_bind_CCannon_SlowUpdate_0 = Module["_emscripten_bind_CCannon_SlowUpdate_0"] = asm["_emscripten_bind_CCannon_SlowUpdate_0"];
var _emscripten_bind_CWeaponLoader___destroy___0 = Module["_emscripten_bind_CWeaponLoader___destroy___0"] = asm["_emscripten_bind_CWeaponLoader___destroy___0"];
var _emscripten_bind_CGeometricObjects_SetColor_5 = Module["_emscripten_bind_CGeometricObjects_SetColor_5"] = asm["_emscripten_bind_CGeometricObjects_SetColor_5"];
var _emscripten_bind_CGlobalSynced___destroy___0 = Module["_emscripten_bind_CGlobalSynced___destroy___0"] = asm["_emscripten_bind_CGlobalSynced___destroy___0"];
var _emscripten_bind_CFactoryCAI_SlowUpdate_0 = Module["_emscripten_bind_CFactoryCAI_SlowUpdate_0"] = asm["_emscripten_bind_CFactoryCAI_SlowUpdate_0"];
var _emscripten_bind_CBuilder_SlowUpdate_0 = Module["_emscripten_bind_CBuilder_SlowUpdate_0"] = asm["_emscripten_bind_CBuilder_SlowUpdate_0"];
var _emscripten_bind_CExplosionGeneratorHandler___destroy___0 = Module["_emscripten_bind_CExplosionGeneratorHandler___destroy___0"] = asm["_emscripten_bind_CExplosionGeneratorHandler___destroy___0"];
var _emscripten_bind_CLosHandler_GetAllyTeamRadarErrorSize_1 = Module["_emscripten_bind_CLosHandler_GetAllyTeamRadarErrorSize_1"] = asm["_emscripten_bind_CLosHandler_GetAllyTeamRadarErrorSize_1"];
var _emscripten_bind_CGeometricObjects_AddSpline_8 = Module["_emscripten_bind_CGeometricObjects_AddSpline_8"] = asm["_emscripten_bind_CGeometricObjects_AddSpline_8"];
var _emscripten_bind_CModInfo_ResetState_0 = Module["_emscripten_bind_CModInfo_ResetState_0"] = asm["_emscripten_bind_CModInfo_ResetState_0"];
var _emscripten_bind_CCommandQueue_clear_0 = Module["_emscripten_bind_CCommandQueue_clear_0"] = asm["_emscripten_bind_CCommandQueue_clear_0"];
var _bitshift64Lshr = Module["_bitshift64Lshr"] = asm["_bitshift64Lshr"];
var _emscripten_bind_CBuilderCAI_SlowUpdate_0 = Module["_emscripten_bind_CBuilderCAI_SlowUpdate_0"] = asm["_emscripten_bind_CBuilderCAI_SlowUpdate_0"];
var _emscripten_bind_CStarburstProjectile___destroy___0 = Module["_emscripten_bind_CStarburstProjectile___destroy___0"] = asm["_emscripten_bind_CStarburstProjectile___destroy___0"];
var _emscripten_bind_CUnitDefHandler_IsValidUnitDefID_1 = Module["_emscripten_bind_CUnitDefHandler_IsValidUnitDefID_1"] = asm["_emscripten_bind_CUnitDefHandler_IsValidUnitDefID_1"];
var _emscripten_bind_CPathEstimator_Update_0 = Module["_emscripten_bind_CPathEstimator_Update_0"] = asm["_emscripten_bind_CPathEstimator_Update_0"];
var _emscripten_bind_CUnitDefHandler_ProcessDecoys_0 = Module["_emscripten_bind_CUnitDefHandler_ProcessDecoys_0"] = asm["_emscripten_bind_CUnitDefHandler_ProcessDecoys_0"];
var _emscripten_bind_CCircularSearchConstraint___destroy___0 = Module["_emscripten_bind_CCircularSearchConstraint___destroy___0"] = asm["_emscripten_bind_CCircularSearchConstraint___destroy___0"];
var _emscripten_bind_CBuilderCAI_FinishCommand_0 = Module["_emscripten_bind_CBuilderCAI_FinishCommand_0"] = asm["_emscripten_bind_CBuilderCAI_FinishCommand_0"];
var _emscripten_bind_CLuaUnitScript_Deactivate_0 = Module["_emscripten_bind_CLuaUnitScript_Deactivate_0"] = asm["_emscripten_bind_CLuaUnitScript_Deactivate_0"];
var _emscripten_bind_CLuaUnitScript_HasFunction_1 = Module["_emscripten_bind_CLuaUnitScript_HasFunction_1"] = asm["_emscripten_bind_CLuaUnitScript_HasFunction_1"];
var _emscripten_bind_CollisionVolume_GetHScale_1 = Module["_emscripten_bind_CollisionVolume_GetHScale_1"] = asm["_emscripten_bind_CollisionVolume_GetHScale_1"];
var _sbrk = Module["_sbrk"] = asm["_sbrk"];
var _emscripten_bind_CMobileCAI_StopSlowGuard_0 = Module["_emscripten_bind_CMobileCAI_StopSlowGuard_0"] = asm["_emscripten_bind_CMobileCAI_StopSlowGuard_0"];
var _emscripten_bind_CWeaponDefHandler___destroy___0 = Module["_emscripten_bind_CWeaponDefHandler___destroy___0"] = asm["_emscripten_bind_CWeaponDefHandler___destroy___0"];
var _emscripten_bind_CLuaUnitScript_StopBuilding_0 = Module["_emscripten_bind_CLuaUnitScript_StopBuilding_0"] = asm["_emscripten_bind_CLuaUnitScript_StopBuilding_0"];
var _emscripten_bind_CMobileCAI_Execute_0 = Module["_emscripten_bind_CMobileCAI_Execute_0"] = asm["_emscripten_bind_CMobileCAI_Execute_0"];
var _emscripten_bind_CLuaUnitScript_Destroy_0 = Module["_emscripten_bind_CLuaUnitScript_Destroy_0"] = asm["_emscripten_bind_CLuaUnitScript_Destroy_0"];
var _emscripten_bind_CBuilderCAI___destroy___0 = Module["_emscripten_bind_CBuilderCAI___destroy___0"] = asm["_emscripten_bind_CBuilderCAI___destroy___0"];
var _emscripten_bind_CCannon___destroy___0 = Module["_emscripten_bind_CCannon___destroy___0"] = asm["_emscripten_bind_CCannon___destroy___0"];
var _emscripten_bind_CLuaUnitScript_Killed_0 = Module["_emscripten_bind_CLuaUnitScript_Killed_0"] = asm["_emscripten_bind_CLuaUnitScript_Killed_0"];
var _emscripten_bind_CBuilder_Update_0 = Module["_emscripten_bind_CBuilder_Update_0"] = asm["_emscripten_bind_CBuilder_Update_0"];
var ___cxa_can_catch = Module["___cxa_can_catch"] = asm["___cxa_can_catch"];
var _emscripten_bind_CMobileCAI_NonMoving_0 = Module["_emscripten_bind_CMobileCAI_NonMoving_0"] = asm["_emscripten_bind_CMobileCAI_NonMoving_0"];
var _emscripten_bind_CollisionVolume_DefaultToPieceTree_0 = Module["_emscripten_bind_CollisionVolume_DefaultToPieceTree_0"] = asm["_emscripten_bind_CollisionVolume_DefaultToPieceTree_0"];
var _emscripten_bind_CUnitDefHandler_AssignTechLevels_0 = Module["_emscripten_bind_CUnitDefHandler_AssignTechLevels_0"] = asm["_emscripten_bind_CUnitDefHandler_AssignTechLevels_0"];
var _emscripten_bind_CBuilder_StopBuild_1 = Module["_emscripten_bind_CBuilder_StopBuild_1"] = asm["_emscripten_bind_CBuilder_StopBuild_1"];
var _free = Module["_free"] = asm["_free"];
var _emscripten_bind_CScriptMoveType___destroy___0 = Module["_emscripten_bind_CScriptMoveType___destroy___0"] = asm["_emscripten_bind_CScriptMoveType___destroy___0"];
var _emscripten_bind_CLuaUnitScript_Falling_0 = Module["_emscripten_bind_CLuaUnitScript_Falling_0"] = asm["_emscripten_bind_CLuaUnitScript_Falling_0"];
var _emscripten_bind_CExplosionGeneratorHandler_ParseExplosionTables_0 = Module["_emscripten_bind_CExplosionGeneratorHandler_ParseExplosionTables_0"] = asm["_emscripten_bind_CExplosionGeneratorHandler_ParseExplosionTables_0"];
var _emscripten_bind_CScriptMoveType_Update_0 = Module["_emscripten_bind_CScriptMoveType_Update_0"] = asm["_emscripten_bind_CScriptMoveType_Update_0"];
var _emscripten_bind_CGeometricObjects___destroy___0 = Module["_emscripten_bind_CGeometricObjects___destroy___0"] = asm["_emscripten_bind_CGeometricObjects___destroy___0"];
var runPostSets = Module["runPostSets"] = asm["runPostSets"];
var _emscripten_bind_CollisionVolume_DefaultToFootPrint_0 = Module["_emscripten_bind_CollisionVolume_DefaultToFootPrint_0"] = asm["_emscripten_bind_CollisionVolume_DefaultToFootPrint_0"];
var _emscripten_bind_CResourceMapAnalyzer_GetAverageIncome_0 = Module["_emscripten_bind_CResourceMapAnalyzer_GetAverageIncome_0"] = asm["_emscripten_bind_CResourceMapAnalyzer_GetAverageIncome_0"];
var _emscripten_bind_CollisionQuery_AnyHit_0 = Module["_emscripten_bind_CollisionQuery_AnyHit_0"] = asm["_emscripten_bind_CollisionQuery_AnyHit_0"];
var _emscripten_bind_CPathEstimator___destroy___0 = Module["_emscripten_bind_CPathEstimator___destroy___0"] = asm["_emscripten_bind_CPathEstimator___destroy___0"];
var _emscripten_bind_CUnitScriptEngine_InitStatic_0 = Module["_emscripten_bind_CUnitScriptEngine_InitStatic_0"] = asm["_emscripten_bind_CUnitScriptEngine_InitStatic_0"];
var _emscripten_bind_CUnitScriptEngine_KillStatic_0 = Module["_emscripten_bind_CUnitScriptEngine_KillStatic_0"] = asm["_emscripten_bind_CUnitScriptEngine_KillStatic_0"];
var _emscripten_bind_CBuilder_StartRestore_2 = Module["_emscripten_bind_CBuilder_StartRestore_2"] = asm["_emscripten_bind_CBuilder_StartRestore_2"];
var _emscripten_bind_CollisionQuery_InsideHit_0 = Module["_emscripten_bind_CollisionQuery_InsideHit_0"] = asm["_emscripten_bind_CollisionQuery_InsideHit_0"];
var _emscripten_bind_CollisionVolume_GetHScaleSq_1 = Module["_emscripten_bind_CollisionVolume_GetHScaleSq_1"] = asm["_emscripten_bind_CollisionVolume_GetHScaleSq_1"];
var _emscripten_bind_CBuilding___destroy___0 = Module["_emscripten_bind_CBuilding___destroy___0"] = asm["_emscripten_bind_CBuilding___destroy___0"];
var _emscripten_bind_CUnitScriptEngine_Tick_1 = Module["_emscripten_bind_CUnitScriptEngine_Tick_1"] = asm["_emscripten_bind_CUnitScriptEngine_Tick_1"];
var _emscripten_bind_CGeometricObjects_MarkSquare_1 = Module["_emscripten_bind_CGeometricObjects_MarkSquare_1"] = asm["_emscripten_bind_CGeometricObjects_MarkSquare_1"];
var _emscripten_bind_CFactory___destroy___0 = Module["_emscripten_bind_CFactory___destroy___0"] = asm["_emscripten_bind_CFactory___destroy___0"];
var _emscripten_bind_CCannon_Init_0 = Module["_emscripten_bind_CCannon_Init_0"] = asm["_emscripten_bind_CCannon_Init_0"];
var _emscripten_bind_CLuaUnitScript_ExtractionRateChanged_1 = Module["_emscripten_bind_CLuaUnitScript_ExtractionRateChanged_1"] = asm["_emscripten_bind_CLuaUnitScript_ExtractionRateChanged_1"];
var _emscripten_bind_CCannon_UpdateRange_1 = Module["_emscripten_bind_CCannon_UpdateRange_1"] = asm["_emscripten_bind_CCannon_UpdateRange_1"];
var _emscripten_bind_CFactory_Update_0 = Module["_emscripten_bind_CFactory_Update_0"] = asm["_emscripten_bind_CFactory_Update_0"];
var _emscripten_bind_CLosHandler_SetBaseRadarErrorSize_1 = Module["_emscripten_bind_CLosHandler_SetBaseRadarErrorSize_1"] = asm["_emscripten_bind_CLosHandler_SetBaseRadarErrorSize_1"];
var _emscripten_bind_CRectangularSearchConstraint_WithinConstraints_2 = Module["_emscripten_bind_CRectangularSearchConstraint_WithinConstraints_2"] = asm["_emscripten_bind_CRectangularSearchConstraint_WithinConstraints_2"];
var _emscripten_bind_CExtractorBuilding_ResetExtraction_0 = Module["_emscripten_bind_CExtractorBuilding_ResetExtraction_0"] = asm["_emscripten_bind_CExtractorBuilding_ResetExtraction_0"];
var _emscripten_bind_CLuaUnitScript_WindChanged_2 = Module["_emscripten_bind_CLuaUnitScript_WindChanged_2"] = asm["_emscripten_bind_CLuaUnitScript_WindChanged_2"];
var _emscripten_bind_CMobileCAI_CanSetMaxSpeed_0 = Module["_emscripten_bind_CMobileCAI_CanSetMaxSpeed_0"] = asm["_emscripten_bind_CMobileCAI_CanSetMaxSpeed_0"];
var _emscripten_bind_CUnitDefHandler_ToggleNoCost_0 = Module["_emscripten_bind_CUnitDefHandler_ToggleNoCost_0"] = asm["_emscripten_bind_CUnitDefHandler_ToggleNoCost_0"];
var _emscripten_bind_CAirCAI_SlowUpdate_0 = Module["_emscripten_bind_CAirCAI_SlowUpdate_0"] = asm["_emscripten_bind_CAirCAI_SlowUpdate_0"];
var ___cxa_is_pointer_type = Module["___cxa_is_pointer_type"] = asm["___cxa_is_pointer_type"];
var _emscripten_bind_CLosHandler_GetFullRead_0 = Module["_emscripten_bind_CLosHandler_GetFullRead_0"] = asm["_emscripten_bind_CLosHandler_GetFullRead_0"];
var _emscripten_bind_CLuaUnitScript_Activate_0 = Module["_emscripten_bind_CLuaUnitScript_Activate_0"] = asm["_emscripten_bind_CLuaUnitScript_Activate_0"];
var _llvm_cttz_i32 = Module["_llvm_cttz_i32"] = asm["_llvm_cttz_i32"];
var _emscripten_bind_CScriptMoveType_SetHeading_1 = Module["_emscripten_bind_CScriptMoveType_SetHeading_1"] = asm["_emscripten_bind_CScriptMoveType_SetHeading_1"];
var _emscripten_bind_CLosHandler_GetBaseRadarErrorMult_0 = Module["_emscripten_bind_CLosHandler_GetBaseRadarErrorMult_0"] = asm["_emscripten_bind_CLosHandler_GetBaseRadarErrorMult_0"];
var _emscripten_bind_CLosMap___destroy___0 = Module["_emscripten_bind_CLosMap___destroy___0"] = asm["_emscripten_bind_CLosMap___destroy___0"];
var _emscripten_bind_CLuaUnitScript_MoveRate_1 = Module["_emscripten_bind_CLuaUnitScript_MoveRate_1"] = asm["_emscripten_bind_CLuaUnitScript_MoveRate_1"];
var _emscripten_bind_CCannon_UpdateWantedDir_0 = Module["_emscripten_bind_CCannon_UpdateWantedDir_0"] = asm["_emscripten_bind_CCannon_UpdateWantedDir_0"];
var _emscripten_bind_CUnitDefHandler_Init_0 = Module["_emscripten_bind_CUnitDefHandler_Init_0"] = asm["_emscripten_bind_CUnitDefHandler_Init_0"];
var _emscripten_bind_CScriptMoveType_ForceUpdates_0 = Module["_emscripten_bind_CScriptMoveType_ForceUpdates_0"] = asm["_emscripten_bind_CScriptMoveType_ForceUpdates_0"];
var _emscripten_bind_CBuilder_ScriptStartBuilding_2 = Module["_emscripten_bind_CBuilder_ScriptStartBuilding_2"] = asm["_emscripten_bind_CBuilder_ScriptStartBuilding_2"];
var _emscripten_bind_CLosHandler_GetBaseRadarErrorSize_0 = Module["_emscripten_bind_CLosHandler_GetBaseRadarErrorSize_0"] = asm["_emscripten_bind_CLosHandler_GetBaseRadarErrorSize_0"];
var _emscripten_bind_CFactory_CreateNanoParticle_1 = Module["_emscripten_bind_CFactory_CreateNanoParticle_1"] = asm["_emscripten_bind_CFactory_CreateNanoParticle_1"];
var _emscripten_bind_CCustomExplosionGenerator_GetFlagsFromHeight_2 = Module["_emscripten_bind_CCustomExplosionGenerator_GetFlagsFromHeight_2"] = asm["_emscripten_bind_CCustomExplosionGenerator_GetFlagsFromHeight_2"];
var _emscripten_bind_CLosHandler_SetBaseRadarErrorMult_1 = Module["_emscripten_bind_CLosHandler_SetBaseRadarErrorMult_1"] = asm["_emscripten_bind_CLosHandler_SetBaseRadarErrorMult_1"];
var _emscripten_bind_ClassAliasList_Clear_0 = Module["_emscripten_bind_ClassAliasList_Clear_0"] = asm["_emscripten_bind_ClassAliasList_Clear_0"];
var _emscripten_bind_CLosHandler_DecreaseAllyTeamRadarErrorSize_1 = Module["_emscripten_bind_CLosHandler_DecreaseAllyTeamRadarErrorSize_1"] = asm["_emscripten_bind_CLosHandler_DecreaseAllyTeamRadarErrorSize_1"];
var _emscripten_bind_CFactory_StopBuild_0 = Module["_emscripten_bind_CFactory_StopBuild_0"] = asm["_emscripten_bind_CFactory_StopBuild_0"];
var _emscripten_bind_CLuaUnitScript_FireWeapon_1 = Module["_emscripten_bind_CLuaUnitScript_FireWeapon_1"] = asm["_emscripten_bind_CLuaUnitScript_FireWeapon_1"];
var _emscripten_bind_CAirCAI___destroy___0 = Module["_emscripten_bind_CAirCAI___destroy___0"] = asm["_emscripten_bind_CAirCAI___destroy___0"];
var _emscripten_bind_CLuaUnitScript_HasBlockShot_1 = Module["_emscripten_bind_CLuaUnitScript_HasBlockShot_1"] = asm["_emscripten_bind_CLuaUnitScript_HasBlockShot_1"];
var _emscripten_bind_CScriptMoveType_LeaveTransport_0 = Module["_emscripten_bind_CScriptMoveType_LeaveTransport_0"] = asm["_emscripten_bind_CScriptMoveType_LeaveTransport_0"];
var _emscripten_bind_CLuaUnitScript_HasTargetWeight_1 = Module["_emscripten_bind_CLuaUnitScript_HasTargetWeight_1"] = asm["_emscripten_bind_CLuaUnitScript_HasTargetWeight_1"];
var _emscripten_bind_CLuaUnitScript_EndTransport_0 = Module["_emscripten_bind_CLuaUnitScript_EndTransport_0"] = asm["_emscripten_bind_CLuaUnitScript_EndTransport_0"];
var _emscripten_bind_CLuaUnitScript_QueryNanoPiece_0 = Module["_emscripten_bind_CLuaUnitScript_QueryNanoPiece_0"] = asm["_emscripten_bind_CLuaUnitScript_QueryNanoPiece_0"];
var _emscripten_bind_CMobileCAI___destroy___0 = Module["_emscripten_bind_CMobileCAI___destroy___0"] = asm["_emscripten_bind_CMobileCAI___destroy___0"];
var _emscripten_bind_CUnitScriptFactory___destroy___0 = Module["_emscripten_bind_CUnitScriptFactory___destroy___0"] = asm["_emscripten_bind_CUnitScriptFactory___destroy___0"];
var _emscripten_bind_CollisionQuery___destroy___0 = Module["_emscripten_bind_CollisionQuery___destroy___0"] = asm["_emscripten_bind_CollisionQuery___destroy___0"];
var _emscripten_bind_CGeometricObjects_Update_0 = Module["_emscripten_bind_CGeometricObjects_Update_0"] = asm["_emscripten_bind_CGeometricObjects_Update_0"];
var _emscripten_bind_CollisionVolume_InitSphere_1 = Module["_emscripten_bind_CollisionVolume_InitSphere_1"] = asm["_emscripten_bind_CollisionVolume_InitSphere_1"];
var _emscripten_bind_CMobileCAI_StopMove_0 = Module["_emscripten_bind_CMobileCAI_StopMove_0"] = asm["_emscripten_bind_CMobileCAI_StopMove_0"];
var _emscripten_bind_CMobileCAI_SlowUpdate_0 = Module["_emscripten_bind_CMobileCAI_SlowUpdate_0"] = asm["_emscripten_bind_CMobileCAI_SlowUpdate_0"];
var _emscripten_bind_CExplosionCreator___destroy___0 = Module["_emscripten_bind_CExplosionCreator___destroy___0"] = asm["_emscripten_bind_CExplosionCreator___destroy___0"];
var _emscripten_bind_CUnitLoader___destroy___0 = Module["_emscripten_bind_CUnitLoader___destroy___0"] = asm["_emscripten_bind_CUnitLoader___destroy___0"];
var _emscripten_bind_CLosHandler___destroy___0 = Module["_emscripten_bind_CLosHandler___destroy___0"] = asm["_emscripten_bind_CLosHandler___destroy___0"];
var _emscripten_bind_CLuaUnitScript_QueryBuildInfo_0 = Module["_emscripten_bind_CLuaUnitScript_QueryBuildInfo_0"] = asm["_emscripten_bind_CLuaUnitScript_QueryBuildInfo_0"];
var _emscripten_bind_CollisionVolume_SetDefaultToFootPrint_1 = Module["_emscripten_bind_CollisionVolume_SetDefaultToFootPrint_1"] = asm["_emscripten_bind_CollisionVolume_SetDefaultToFootPrint_1"];
var _emscripten_bind_CollisionVolume_SetVolumeType_1 = Module["_emscripten_bind_CollisionVolume_SetVolumeType_1"] = asm["_emscripten_bind_CollisionVolume_SetVolumeType_1"];
var _emscripten_bind_CollisionVolume_SetUseContHitTest_1 = Module["_emscripten_bind_CollisionVolume_SetUseContHitTest_1"] = asm["_emscripten_bind_CollisionVolume_SetUseContHitTest_1"];
var _emscripten_bind_CCollisionHandler_PrintStats_0 = Module["_emscripten_bind_CCollisionHandler_PrintStats_0"] = asm["_emscripten_bind_CCollisionHandler_PrintStats_0"];
var _emscripten_bind_CExtractorBuilding_ReCalculateMetalExtraction_0 = Module["_emscripten_bind_CExtractorBuilding_ReCalculateMetalExtraction_0"] = asm["_emscripten_bind_CExtractorBuilding_ReCalculateMetalExtraction_0"];
var _emscripten_bind_CollisionVolume_GetPrimaryAxis_0 = Module["_emscripten_bind_CollisionVolume_GetPrimaryAxis_0"] = asm["_emscripten_bind_CollisionVolume_GetPrimaryAxis_0"];
var _emscripten_bind_CollisionVolume_SetDefaultToPieceTree_1 = Module["_emscripten_bind_CollisionVolume_SetDefaultToPieceTree_1"] = asm["_emscripten_bind_CollisionVolume_SetDefaultToPieceTree_1"];
var _emscripten_bind_CLosHandler_GetReadAllyTeam_0 = Module["_emscripten_bind_CLosHandler_GetReadAllyTeam_0"] = asm["_emscripten_bind_CLosHandler_GetReadAllyTeam_0"];
var __GLOBAL__sub_I_my_glue_wrapper_cpp = Module["__GLOBAL__sub_I_my_glue_wrapper_cpp"] = asm["__GLOBAL__sub_I_my_glue_wrapper_cpp"];
var _emscripten_bind_CLosHandler_SetAllyTeamRadarErrorSize_2 = Module["_emscripten_bind_CLosHandler_SetAllyTeamRadarErrorSize_2"] = asm["_emscripten_bind_CLosHandler_SetAllyTeamRadarErrorSize_2"];
var _emscripten_bind_CLuaUnitScript_RawCall_1 = Module["_emscripten_bind_CLuaUnitScript_RawCall_1"] = asm["_emscripten_bind_CLuaUnitScript_RawCall_1"];
var _emscripten_bind_CollisionQuery_EgressHit_0 = Module["_emscripten_bind_CollisionQuery_EgressHit_0"] = asm["_emscripten_bind_CollisionQuery_EgressHit_0"];
var _emscripten_bind_VoidPtr___destroy___0 = Module["_emscripten_bind_VoidPtr___destroy___0"] = asm["_emscripten_bind_VoidPtr___destroy___0"];
var _memset = Module["_memset"] = asm["_memset"];
var _emscripten_bind_CScriptMoveType_KeepPointingTo_3 = Module["_emscripten_bind_CScriptMoveType_KeepPointingTo_3"] = asm["_emscripten_bind_CScriptMoveType_KeepPointingTo_3"];
var _emscripten_bind_CLuaUnitScript_StartMoving_1 = Module["_emscripten_bind_CLuaUnitScript_StartMoving_1"] = asm["_emscripten_bind_CLuaUnitScript_StartMoving_1"];
var _emscripten_bind_CGlobalSynced_GetLuaSimFrame_0 = Module["_emscripten_bind_CGlobalSynced_GetLuaSimFrame_0"] = asm["_emscripten_bind_CGlobalSynced_GetLuaSimFrame_0"];
var _emscripten_bind_CLuaUnitScript_AimWeapon_3 = Module["_emscripten_bind_CLuaUnitScript_AimWeapon_3"] = asm["_emscripten_bind_CLuaUnitScript_AimWeapon_3"];
var _emscripten_bind_CollisionVolume_GetBoundingRadius_0 = Module["_emscripten_bind_CollisionVolume_GetBoundingRadius_0"] = asm["_emscripten_bind_CollisionVolume_GetBoundingRadius_0"];
var _emscripten_bind_CExtractorBuilding_FinishedBuilding_1 = Module["_emscripten_bind_CExtractorBuilding_FinishedBuilding_1"] = asm["_emscripten_bind_CExtractorBuilding_FinishedBuilding_1"];
var _emscripten_bind_CollisionVolume_GetBoundingRadiusSq_0 = Module["_emscripten_bind_CollisionVolume_GetBoundingRadiusSq_0"] = asm["_emscripten_bind_CollisionVolume_GetBoundingRadiusSq_0"];
var _emscripten_bind_CollisionVolume_PostLoad_0 = Module["_emscripten_bind_CollisionVolume_PostLoad_0"] = asm["_emscripten_bind_CollisionVolume_PostLoad_0"];
var _emscripten_bind_CScriptMoveType_StopMoving_3 = Module["_emscripten_bind_CScriptMoveType_StopMoving_3"] = asm["_emscripten_bind_CScriptMoveType_StopMoving_3"];
var _emscripten_bind_CUnitDefHandler___destroy___0 = Module["_emscripten_bind_CUnitDefHandler___destroy___0"] = asm["_emscripten_bind_CUnitDefHandler___destroy___0"];
var _emscripten_bind_CAirCAI_FinishCommand_0 = Module["_emscripten_bind_CAirCAI_FinishCommand_0"] = asm["_emscripten_bind_CAirCAI_FinishCommand_0"];
var _emscripten_bind_CGlobalSynced_PreSimFrame_0 = Module["_emscripten_bind_CGlobalSynced_PreSimFrame_0"] = asm["_emscripten_bind_CGlobalSynced_PreSimFrame_0"];
var _emscripten_bind_CUnitScriptEngine___destroy___0 = Module["_emscripten_bind_CUnitScriptEngine___destroy___0"] = asm["_emscripten_bind_CUnitScriptEngine___destroy___0"];
var _emscripten_bind_CExtractorBuilding_GetExtractionRange_0 = Module["_emscripten_bind_CExtractorBuilding_GetExtractionRange_0"] = asm["_emscripten_bind_CExtractorBuilding_GetExtractionRange_0"];
var _emscripten_bind_CMoveMath___destroy___0 = Module["_emscripten_bind_CMoveMath___destroy___0"] = asm["_emscripten_bind_CMoveMath___destroy___0"];
var _emscripten_bind_CLuaUnitScript_AimFromWeapon_1 = Module["_emscripten_bind_CLuaUnitScript_AimFromWeapon_1"] = asm["_emscripten_bind_CLuaUnitScript_AimFromWeapon_1"];
var _emscripten_bind_CCommandQueue___destroy___0 = Module["_emscripten_bind_CCommandQueue___destroy___0"] = asm["_emscripten_bind_CCommandQueue___destroy___0"];
var ___muldsi3 = Module["___muldsi3"] = asm["___muldsi3"];
var _emscripten_bind_CCommandQueue_empty_0 = Module["_emscripten_bind_CCommandQueue_empty_0"] = asm["_emscripten_bind_CCommandQueue_empty_0"];
var _emscripten_bind_CScriptMoveType_StartMoving_2 = Module["_emscripten_bind_CScriptMoveType_StartMoving_2"] = asm["_emscripten_bind_CScriptMoveType_StartMoving_2"];
var _emscripten_bind_CollisionVolume_GetSecondaryAxis_1 = Module["_emscripten_bind_CollisionVolume_GetSecondaryAxis_1"] = asm["_emscripten_bind_CollisionVolume_GetSecondaryAxis_1"];
var _emscripten_bind_CCustomExplosionGenerator___destroy___0 = Module["_emscripten_bind_CCustomExplosionGenerator___destroy___0"] = asm["_emscripten_bind_CCustomExplosionGenerator___destroy___0"];
var _emscripten_bind_CLosHandler_IncreaseAllyTeamRadarErrorSize_1 = Module["_emscripten_bind_CLosHandler_IncreaseAllyTeamRadarErrorSize_1"] = asm["_emscripten_bind_CLosHandler_IncreaseAllyTeamRadarErrorSize_1"];
var _emscripten_bind_CollisionVolume_GetOffset_1 = Module["_emscripten_bind_CollisionVolume_GetOffset_1"] = asm["_emscripten_bind_CollisionVolume_GetOffset_1"];
var _emscripten_bind_CFeatureDefHandler_LoadFeatureDefsFromMap_0 = Module["_emscripten_bind_CFeatureDefHandler_LoadFeatureDefsFromMap_0"] = asm["_emscripten_bind_CFeatureDefHandler_LoadFeatureDefsFromMap_0"];
var _emscripten_bind_CLosHandler_Update_0 = Module["_emscripten_bind_CLosHandler_Update_0"] = asm["_emscripten_bind_CLosHandler_Update_0"];
var _malloc = Module["_malloc"] = asm["_malloc"];
var _emscripten_bind_CMobileCAI_GetCancelDistance_0 = Module["_emscripten_bind_CMobileCAI_GetCancelDistance_0"] = asm["_emscripten_bind_CMobileCAI_GetCancelDistance_0"];
var _emscripten_bind_CLuaUnitScript_SetSFXOccupy_1 = Module["_emscripten_bind_CLuaUnitScript_SetSFXOccupy_1"] = asm["_emscripten_bind_CLuaUnitScript_SetSFXOccupy_1"];
var _emscripten_bind_CCommandQueue_pop_back_0 = Module["_emscripten_bind_CCommandQueue_pop_back_0"] = asm["_emscripten_bind_CCommandQueue_pop_back_0"];
var _emscripten_bind_CFactoryCAI___destroy___0 = Module["_emscripten_bind_CFactoryCAI___destroy___0"] = asm["_emscripten_bind_CFactoryCAI___destroy___0"];
var _emscripten_bind_CCobUnitScriptNames___destroy___0 = Module["_emscripten_bind_CCobUnitScriptNames___destroy___0"] = asm["_emscripten_bind_CCobUnitScriptNames___destroy___0"];
var _emscripten_bind_CBuilderCAI_PostLoad_0 = Module["_emscripten_bind_CBuilderCAI_PostLoad_0"] = asm["_emscripten_bind_CBuilderCAI_PostLoad_0"];
var _emscripten_bind_CommonDefHandler___destroy___0 = Module["_emscripten_bind_CommonDefHandler___destroy___0"] = asm["_emscripten_bind_CommonDefHandler___destroy___0"];
var _i64Subtract = Module["_i64Subtract"] = asm["_i64Subtract"];
var ___udivdi3 = Module["___udivdi3"] = asm["___udivdi3"];
var _emscripten_bind_CLuaUnitScript_EndBurst_1 = Module["_emscripten_bind_CLuaUnitScript_EndBurst_1"] = asm["_emscripten_bind_CLuaUnitScript_EndBurst_1"];
var _emscripten_bind_CFeatureDefHandler___destroy___0 = Module["_emscripten_bind_CFeatureDefHandler___destroy___0"] = asm["_emscripten_bind_CFeatureDefHandler___destroy___0"];
var _emscripten_bind_CCircularSearchConstraint_WithinConstraints_2 = Module["_emscripten_bind_CCircularSearchConstraint_WithinConstraints_2"] = asm["_emscripten_bind_CCircularSearchConstraint_WithinConstraints_2"];
var _emscripten_bind_CScriptMoveType_SetWantedMaxSpeed_1 = Module["_emscripten_bind_CScriptMoveType_SetWantedMaxSpeed_1"] = asm["_emscripten_bind_CScriptMoveType_SetWantedMaxSpeed_1"];
var _emscripten_bind_CollisionVolume_SetBoundingRadius_0 = Module["_emscripten_bind_CollisionVolume_SetBoundingRadius_0"] = asm["_emscripten_bind_CollisionVolume_SetBoundingRadius_0"];
var ___udivmoddi4 = Module["___udivmoddi4"] = asm["___udivmoddi4"];
var _emscripten_bind_CollisionVolume_GetVolumeType_0 = Module["_emscripten_bind_CollisionVolume_GetVolumeType_0"] = asm["_emscripten_bind_CollisionVolume_GetVolumeType_0"];
var _emscripten_bind_CGeometricObjects_DeleteGroup_1 = Module["_emscripten_bind_CGeometricObjects_DeleteGroup_1"] = asm["_emscripten_bind_CGeometricObjects_DeleteGroup_1"];
var _fflush = Module["_fflush"] = asm["_fflush"];
var _emscripten_bind_CollisionVolume___destroy___0 = Module["_emscripten_bind_CollisionVolume___destroy___0"] = asm["_emscripten_bind_CollisionVolume___destroy___0"];
var _emscripten_bind_CRectangularSearchConstraint___destroy___0 = Module["_emscripten_bind_CRectangularSearchConstraint___destroy___0"] = asm["_emscripten_bind_CRectangularSearchConstraint___destroy___0"];
var _emscripten_bind_CExtractorBuilding___destroy___0 = Module["_emscripten_bind_CExtractorBuilding___destroy___0"] = asm["_emscripten_bind_CExtractorBuilding___destroy___0"];
var _emscripten_bind_CGlobalSynced_GetTempNum_0 = Module["_emscripten_bind_CGlobalSynced_GetTempNum_0"] = asm["_emscripten_bind_CGlobalSynced_GetTempNum_0"];
var _emscripten_bind_CScriptMoveType_SetNoBlocking_1 = Module["_emscripten_bind_CScriptMoveType_SetNoBlocking_1"] = asm["_emscripten_bind_CScriptMoveType_SetNoBlocking_1"];
var _emscripten_bind_CollisionVolume_IgnoreHits_0 = Module["_emscripten_bind_CollisionVolume_IgnoreHits_0"] = asm["_emscripten_bind_CollisionVolume_IgnoreHits_0"];
var ___muldi3 = Module["___muldi3"] = asm["___muldi3"];
var _emscripten_bind_CExtractorBuilding_SetExtractionRangeAndDepth_2 = Module["_emscripten_bind_CExtractorBuilding_SetExtractionRangeAndDepth_2"] = asm["_emscripten_bind_CExtractorBuilding_SetExtractionRangeAndDepth_2"];
var _emscripten_bind_CLuaUnitScript_StopMoving_0 = Module["_emscripten_bind_CLuaUnitScript_StopMoving_0"] = asm["_emscripten_bind_CLuaUnitScript_StopMoving_0"];
var _emscripten_bind_CLuaUnitScript_Create_0 = Module["_emscripten_bind_CLuaUnitScript_Create_0"] = asm["_emscripten_bind_CLuaUnitScript_Create_0"];
var _bitshift64Shl = Module["_bitshift64Shl"] = asm["_bitshift64Shl"];
var ___uremdi3 = Module["___uremdi3"] = asm["___uremdi3"];
var _emscripten_bind_CollisionVolume_DefaultToSphere_0 = Module["_emscripten_bind_CollisionVolume_DefaultToSphere_0"] = asm["_emscripten_bind_CollisionVolume_DefaultToSphere_0"];
var _emscripten_bind_CMobileCAI_FinishCommand_0 = Module["_emscripten_bind_CMobileCAI_FinishCommand_0"] = asm["_emscripten_bind_CMobileCAI_FinishCommand_0"];
var _emscripten_bind_CMobileCAI_StopMoveAndFinishCommand_0 = Module["_emscripten_bind_CMobileCAI_StopMoveAndFinishCommand_0"] = asm["_emscripten_bind_CMobileCAI_StopMoveAndFinishCommand_0"];
var _emscripten_bind_CCollisionHandler___destroy___0 = Module["_emscripten_bind_CCollisionHandler___destroy___0"] = asm["_emscripten_bind_CCollisionHandler___destroy___0"];
var _i64Add = Module["_i64Add"] = asm["_i64Add"];
var _emscripten_bind_CPathEstimator_GetPathChecksum_0 = Module["_emscripten_bind_CPathEstimator_GetPathChecksum_0"] = asm["_emscripten_bind_CPathEstimator_GetPathChecksum_0"];
var _emscripten_bind_CollisionQuery_IngressHit_0 = Module["_emscripten_bind_CollisionQuery_IngressHit_0"] = asm["_emscripten_bind_CollisionQuery_IngressHit_0"];
var _pthread_self = Module["_pthread_self"] = asm["_pthread_self"];
var _emscripten_bind_CModInfo___destroy___0 = Module["_emscripten_bind_CModInfo___destroy___0"] = asm["_emscripten_bind_CModInfo___destroy___0"];
var _emscripten_bind_CBuilder___destroy___0 = Module["_emscripten_bind_CBuilder___destroy___0"] = asm["_emscripten_bind_CBuilder___destroy___0"];
var _emscripten_bind_CExtractorBuilding_GetExtractionDepth_0 = Module["_emscripten_bind_CExtractorBuilding_GetExtractionDepth_0"] = asm["_emscripten_bind_CExtractorBuilding_GetExtractionDepth_0"];
var _emscripten_bind_CLuaUnitScript_StartUnload_0 = Module["_emscripten_bind_CLuaUnitScript_StartUnload_0"] = asm["_emscripten_bind_CLuaUnitScript_StartUnload_0"];
var _emscripten_bind_CResourceMapAnalyzer___destroy___0 = Module["_emscripten_bind_CResourceMapAnalyzer___destroy___0"] = asm["_emscripten_bind_CResourceMapAnalyzer___destroy___0"];
var _emscripten_bind_CGeometricObjects_AddLine_6 = Module["_emscripten_bind_CGeometricObjects_AddLine_6"] = asm["_emscripten_bind_CGeometricObjects_AddLine_6"];
var _emscripten_bind_CollisionVolume_GetScale_1 = Module["_emscripten_bind_CollisionVolume_GetScale_1"] = asm["_emscripten_bind_CollisionVolume_GetScale_1"];
var _emscripten_bind_CLuaUnitScript_Landed_0 = Module["_emscripten_bind_CLuaUnitScript_Landed_0"] = asm["_emscripten_bind_CLuaUnitScript_Landed_0"];
var _emscripten_bind_CollisionVolume_UseContHitTest_0 = Module["_emscripten_bind_CollisionVolume_UseContHitTest_0"] = asm["_emscripten_bind_CollisionVolume_UseContHitTest_0"];
var ___errno_location = Module["___errno_location"] = asm["___errno_location"];
var _emscripten_bind_CScriptMoveType_SetMaxSpeed_1 = Module["_emscripten_bind_CScriptMoveType_SetMaxSpeed_1"] = asm["_emscripten_bind_CScriptMoveType_SetMaxSpeed_1"];
var _emscripten_bind_CCommandQueue_pop_front_0 = Module["_emscripten_bind_CCommandQueue_pop_front_0"] = asm["_emscripten_bind_CCommandQueue_pop_front_0"];
var _emscripten_bind_CGlobalSynced_ResetState_0 = Module["_emscripten_bind_CGlobalSynced_ResetState_0"] = asm["_emscripten_bind_CGlobalSynced_ResetState_0"];
var _emscripten_bind_CLuaUnitScript___destroy___0 = Module["_emscripten_bind_CLuaUnitScript___destroy___0"] = asm["_emscripten_bind_CLuaUnitScript___destroy___0"];
var _emscripten_bind_CLuaUnitScript_Shot_1 = Module["_emscripten_bind_CLuaUnitScript_Shot_1"] = asm["_emscripten_bind_CLuaUnitScript_Shot_1"];
var _emscripten_bind_ClassAliasList___destroy___0 = Module["_emscripten_bind_ClassAliasList___destroy___0"] = asm["_emscripten_bind_ClassAliasList___destroy___0"];
var _emscripten_bind_CCannon_GetRange2D_2 = Module["_emscripten_bind_CCannon_GetRange2D_2"] = asm["_emscripten_bind_CCannon_GetRange2D_2"];
var _emscripten_bind_CCustomExplosionGenerator_OutputProjectileClassInfo_0 = Module["_emscripten_bind_CCustomExplosionGenerator_OutputProjectileClassInfo_0"] = asm["_emscripten_bind_CCustomExplosionGenerator_OutputProjectileClassInfo_0"];
var _emscripten_bind_CLuaUnitScriptNames___destroy___0 = Module["_emscripten_bind_CLuaUnitScriptNames___destroy___0"] = asm["_emscripten_bind_CLuaUnitScriptNames___destroy___0"];
var _emscripten_bind_CLuaUnitScript_StartBuilding_2 = Module["_emscripten_bind_CLuaUnitScript_StartBuilding_2"] = asm["_emscripten_bind_CLuaUnitScript_StartBuilding_2"];
var _emscripten_bind_CLuaUnitScript_StartBuilding_0 = Module["_emscripten_bind_CLuaUnitScript_StartBuilding_0"] = asm["_emscripten_bind_CLuaUnitScript_StartBuilding_0"];
var _memcpy = Module["_memcpy"] = asm["_memcpy"];
var _emscripten_bind_CollisionVolume_SetIgnoreHits_1 = Module["_emscripten_bind_CollisionVolume_SetIgnoreHits_1"] = asm["_emscripten_bind_CollisionVolume_SetIgnoreHits_1"];
var _emscripten_bind_CPathEstimator_MapChanged_4 = Module["_emscripten_bind_CPathEstimator_MapChanged_4"] = asm["_emscripten_bind_CPathEstimator_MapChanged_4"];
var _emscripten_bind_CBuilderCAI_InitStatic_0 = Module["_emscripten_bind_CBuilderCAI_InitStatic_0"] = asm["_emscripten_bind_CBuilderCAI_InitStatic_0"];
var _emscripten_bind_CMobileCAI_StartSlowGuard_1 = Module["_emscripten_bind_CMobileCAI_StartSlowGuard_1"] = asm["_emscripten_bind_CMobileCAI_StartSlowGuard_1"];
var _emscripten_bind_CLuaUnitScript_QueryWeapon_1 = Module["_emscripten_bind_CLuaUnitScript_QueryWeapon_1"] = asm["_emscripten_bind_CLuaUnitScript_QueryWeapon_1"];
var _emscripten_bind_CCannon_GetRange2D_1 = Module["_emscripten_bind_CCannon_GetRange2D_1"] = asm["_emscripten_bind_CCannon_GetRange2D_1"];
var dynCall_iiii = Module["dynCall_iiii"] = asm["dynCall_iiii"];
var dynCall_vid = Module["dynCall_vid"] = asm["dynCall_vid"];
var dynCall_viiiii = Module["dynCall_viiiii"] = asm["dynCall_viiiii"];
var dynCall_i = Module["dynCall_i"] = asm["dynCall_i"];
var dynCall_vi = Module["dynCall_vi"] = asm["dynCall_vi"];
var dynCall_vii = Module["dynCall_vii"] = asm["dynCall_vii"];
var dynCall_vidd = Module["dynCall_vidd"] = asm["dynCall_vidd"];
var dynCall_ii = Module["dynCall_ii"] = asm["dynCall_ii"];
var dynCall_viidi = Module["dynCall_viidi"] = asm["dynCall_viidi"];
var dynCall_viidd = Module["dynCall_viidd"] = asm["dynCall_viidd"];
var dynCall_v = Module["dynCall_v"] = asm["dynCall_v"];
var dynCall_viid = Module["dynCall_viid"] = asm["dynCall_viid"];
var dynCall_viiiiii = Module["dynCall_viiiiii"] = asm["dynCall_viiiiii"];
var dynCall_iii = Module["dynCall_iii"] = asm["dynCall_iii"];
var dynCall_viiii = Module["dynCall_viiii"] = asm["dynCall_viiii"];
;

Runtime.stackAlloc = asm['stackAlloc'];
Runtime.stackSave = asm['stackSave'];
Runtime.stackRestore = asm['stackRestore'];
Runtime.establishStackSpace = asm['establishStackSpace'];

Runtime.setTempRet0 = asm['setTempRet0'];
Runtime.getTempRet0 = asm['getTempRet0'];



// === Auto-generated postamble setup entry stuff ===





function ExitStatus(status) {
  this.name = "ExitStatus";
  this.message = "Program terminated with exit(" + status + ")";
  this.status = status;
};
ExitStatus.prototype = new Error();
ExitStatus.prototype.constructor = ExitStatus;

var initialStackTop;
var preloadStartTime = null;
var calledMain = false;

dependenciesFulfilled = function runCaller() {
  // If run has never been called, and we should call run (INVOKE_RUN is true, and Module.noInitialRun is not false)
  if (!Module['calledRun']) run();
  if (!Module['calledRun']) dependenciesFulfilled = runCaller; // try this again later, after new deps are fulfilled
}

Module['callMain'] = Module.callMain = function callMain(args) {
  assert(runDependencies == 0, 'cannot call main when async dependencies remain! (listen on __ATMAIN__)');
  assert(__ATPRERUN__.length == 0, 'cannot call main when preRun functions remain to be called');

  args = args || [];

  ensureInitRuntime();

  var argc = args.length+1;
  function pad() {
    for (var i = 0; i < 4-1; i++) {
      argv.push(0);
    }
  }
  var argv = [allocate(intArrayFromString(Module['thisProgram']), 'i8', ALLOC_NORMAL) ];
  pad();
  for (var i = 0; i < argc-1; i = i + 1) {
    argv.push(allocate(intArrayFromString(args[i]), 'i8', ALLOC_NORMAL));
    pad();
  }
  argv.push(0);
  argv = allocate(argv, 'i32', ALLOC_NORMAL);


  try {

    var ret = Module['_main'](argc, argv, 0);


    // if we're not running an evented main loop, it's time to exit
    exit(ret, /* implicit = */ true);
  }
  catch(e) {
    if (e instanceof ExitStatus) {
      // exit() throws this once it's done to make sure execution
      // has been stopped completely
      return;
    } else if (e == 'SimulateInfiniteLoop') {
      // running an evented main loop, don't immediately exit
      Module['noExitRuntime'] = true;
      return;
    } else {
      if (e && typeof e === 'object' && e.stack) Module.printErr('exception thrown: ' + [e, e.stack]);
      throw e;
    }
  } finally {
    calledMain = true;
  }
}




function run(args) {
  args = args || Module['arguments'];

  if (preloadStartTime === null) preloadStartTime = Date.now();

  if (runDependencies > 0) {
    Module.printErr('run() called, but dependencies remain, so not running');
    return;
  }

  writeStackCookie();

  preRun();

  if (runDependencies > 0) return; // a preRun added a dependency, run will be called later
  if (Module['calledRun']) return; // run may have just been called through dependencies being fulfilled just in this very frame

  function doRun() {
    if (Module['calledRun']) return; // run may have just been called while the async setStatus time below was happening
    Module['calledRun'] = true;

    if (ABORT) return;

    ensureInitRuntime();

    preMain();

    if (ENVIRONMENT_IS_WEB && preloadStartTime !== null) {
      Module.printErr('pre-main prep time: ' + (Date.now() - preloadStartTime) + ' ms');
    }

    if (Module['onRuntimeInitialized']) Module['onRuntimeInitialized']();

    if (Module['_main'] && shouldRunNow) Module['callMain'](args);

    postRun();
  }

  if (Module['setStatus']) {
    Module['setStatus']('Running...');
    setTimeout(function() {
      setTimeout(function() {
        Module['setStatus']('');
      }, 1);
      doRun();
    }, 1);
  } else {
    doRun();
  }
  checkStackCookie();
}
Module['run'] = Module.run = run;

function exit(status, implicit) {
  if (implicit && Module['noExitRuntime']) {
    Module.printErr('exit(' + status + ') implicitly called by end of main(), but noExitRuntime, so not exiting the runtime (you can use emscripten_force_exit, if you want to force a true shutdown)');
    return;
  }

  if (Module['noExitRuntime']) {
    Module.printErr('exit(' + status + ') called, but noExitRuntime, so halting execution but not exiting the runtime or preventing further async execution (you can use emscripten_force_exit, if you want to force a true shutdown)');
  } else {

    ABORT = true;
    EXITSTATUS = status;
    STACKTOP = initialStackTop;

    exitRuntime();

    if (Module['onExit']) Module['onExit'](status);
  }

  if (ENVIRONMENT_IS_NODE) {
    process['exit'](status);
  } else if (ENVIRONMENT_IS_SHELL && typeof quit === 'function') {
    quit(status);
  }
  // if we reach here, we must throw an exception to halt the current execution
  throw new ExitStatus(status);
}
Module['exit'] = Module.exit = exit;

var abortDecorators = [];

function abort(what) {
  if (what !== undefined) {
    Module.print(what);
    Module.printErr(what);
    what = JSON.stringify(what)
  } else {
    what = '';
  }

  ABORT = true;
  EXITSTATUS = 1;

  var extra = '';

  var output = 'abort(' + what + ') at ' + stackTrace() + extra;
  if (abortDecorators) {
    abortDecorators.forEach(function(decorator) {
      output = decorator(output, what);
    });
  }
  throw output;
}
Module['abort'] = Module.abort = abort;

// {{PRE_RUN_ADDITIONS}}

if (Module['preInit']) {
  if (typeof Module['preInit'] == 'function') Module['preInit'] = [Module['preInit']];
  while (Module['preInit'].length > 0) {
    Module['preInit'].pop()();
  }
}

// shouldRunNow refers to calling main(), not run().
var shouldRunNow = true;
if (Module['noInitialRun']) {
  shouldRunNow = false;
}


run();

// {{POST_RUN_ADDITIONS}}





// {{MODULE_ADDITIONS}}




// Bindings utilities

function WrapperObject() {
}
WrapperObject.prototype = Object.create(WrapperObject.prototype);
WrapperObject.prototype.constructor = WrapperObject;
WrapperObject.prototype.__class__ = WrapperObject;
WrapperObject.__cache__ = {};
Module['WrapperObject'] = WrapperObject;

function getCache(__class__) {
  return (__class__ || WrapperObject).__cache__;
}
Module['getCache'] = getCache;

function wrapPointer(ptr, __class__) {
  var cache = getCache(__class__);
  var ret = cache[ptr];
  if (ret) return ret;
  ret = Object.create((__class__ || WrapperObject).prototype);
  ret.ptr = ptr;
  return cache[ptr] = ret;
}
Module['wrapPointer'] = wrapPointer;

function castObject(obj, __class__) {
  return wrapPointer(obj.ptr, __class__);
}
Module['castObject'] = castObject;

Module['NULL'] = wrapPointer(0);

function destroy(obj) {
  if (!obj['__destroy__']) throw 'Error: Cannot destroy object. (Did you create it yourself?)';
  obj['__destroy__']();
  // Remove from cache, so the object can be GC'd and refs added onto it released
  delete getCache(obj.__class__)[obj.ptr];
}
Module['destroy'] = destroy;

function compare(obj1, obj2) {
  return obj1.ptr === obj2.ptr;
}
Module['compare'] = compare;

function getPointer(obj) {
  return obj.ptr;
}
Module['getPointer'] = getPointer;

function getClass(obj) {
  return obj.__class__;
}
Module['getClass'] = getClass;

// Converts big (string or array) values into a C-style storage, in temporary space

var ensureCache = {
  buffer: 0,  // the main buffer of temporary storage
  size: 0,   // the size of buffer
  pos: 0,    // the next free offset in buffer
  temps: [], // extra allocations
  needed: 0, // the total size we need next time

  prepare: function() {
    if (this.needed) {
      // clear the temps
      for (var i = 0; i < this.temps.length; i++) {
        Module['_free'](this.temps[i]);
      }
      this.temps.length = 0;
      // prepare to allocate a bigger buffer
      Module['_free'](this.buffer);
      this.buffer = 0;
      this.size += this.needed;
      // clean up
      this.needed = 0;
    }
    if (!this.buffer) { // happens first time, or when we need to grow
      this.size += 128; // heuristic, avoid many small grow events
      this.buffer = Module['_malloc'](this.size);
      assert(this.buffer);
    }
    this.pos = 0;
  },
  alloc: function(array, view) {
    assert(this.buffer);
    var bytes = view.BYTES_PER_ELEMENT;
    var len = array.length * bytes;
    len = (len + 7) & -8; // keep things aligned to 8 byte boundaries
    var ret;
    if (this.pos + len >= this.size) {
      // we failed to allocate in the buffer, this time around :(
      assert(len > 0); // null terminator, at least
      this.needed += len;
      ret = Module['_malloc'](len);
      this.temps.push(ret);
    } else {
      // we can allocate in the buffer
      ret = this.buffer + this.pos;
      this.pos += len;
    }
    var retShifted = ret;
    switch (bytes) {
      case 2: retShifted >>= 1; break;
      case 4: retShifted >>= 2; break;
      case 8: retShifted >>= 3; break;
    }
    for (var i = 0; i < array.length; i++) {
      view[retShifted + i] = array[i];
    }
    return ret;
  },
};

function ensureString(value) {
  if (typeof value === 'string') return ensureCache.alloc(intArrayFromString(value), HEAP8);
  return value;
}
function ensureInt8(value) {
  if (typeof value === 'object') return ensureCache.alloc(value, HEAP8);
  return value;
}
function ensureInt16(value) {
  if (typeof value === 'object') return ensureCache.alloc(value, HEAP16);
  return value;
}
function ensureInt32(value) {
  if (typeof value === 'object') return ensureCache.alloc(value, HEAP32);
  return value;
}
function ensureFloat32(value) {
  if (typeof value === 'object') return ensureCache.alloc(value, HEAPF32);
  return value;
}
function ensureFloat64(value) {
  if (typeof value === 'object') return ensureCache.alloc(value, HEAPF64);
  return value;
}


// CLosMap
function CLosMap() { throw "cannot construct a CLosMap, no constructor in IDL" }
CLosMap.prototype = Object.create(WrapperObject.prototype);
CLosMap.prototype.constructor = CLosMap;
CLosMap.prototype.__class__ = CLosMap;
CLosMap.__cache__ = {};
Module['CLosMap'] = CLosMap;

  CLosMap.prototype['__destroy__'] = CLosMap.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CLosMap___destroy___0(self);
};
// CUnitDefHandler
function CUnitDefHandler() { throw "cannot construct a CUnitDefHandler, no constructor in IDL" }
CUnitDefHandler.prototype = Object.create(WrapperObject.prototype);
CUnitDefHandler.prototype.constructor = CUnitDefHandler;
CUnitDefHandler.prototype.__class__ = CUnitDefHandler;
CUnitDefHandler.__cache__ = {};
Module['CUnitDefHandler'] = CUnitDefHandler;

CUnitDefHandler.prototype['Init'] = CUnitDefHandler.prototype.Init = function() {
  var self = this.ptr;
  _emscripten_bind_CUnitDefHandler_Init_0(self);
};;

CUnitDefHandler.prototype['ProcessDecoys'] = CUnitDefHandler.prototype.ProcessDecoys = function() {
  var self = this.ptr;
  _emscripten_bind_CUnitDefHandler_ProcessDecoys_0(self);
};;

CUnitDefHandler.prototype['AssignTechLevels'] = CUnitDefHandler.prototype.AssignTechLevels = function() {
  var self = this.ptr;
  _emscripten_bind_CUnitDefHandler_AssignTechLevels_0(self);
};;

CUnitDefHandler.prototype['ToggleNoCost'] = CUnitDefHandler.prototype.ToggleNoCost = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CUnitDefHandler_ToggleNoCost_0(self));
};;

CUnitDefHandler.prototype['IsValidUnitDefID'] = CUnitDefHandler.prototype.IsValidUnitDefID = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return !!(_emscripten_bind_CUnitDefHandler_IsValidUnitDefID_1(self, arg0));
};;

  CUnitDefHandler.prototype['__destroy__'] = CUnitDefHandler.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CUnitDefHandler___destroy___0(self);
};
// CWeaponDefHandler
function CWeaponDefHandler() { throw "cannot construct a CWeaponDefHandler, no constructor in IDL" }
CWeaponDefHandler.prototype = Object.create(WrapperObject.prototype);
CWeaponDefHandler.prototype.constructor = CWeaponDefHandler;
CWeaponDefHandler.prototype.__class__ = CWeaponDefHandler;
CWeaponDefHandler.__cache__ = {};
Module['CWeaponDefHandler'] = CWeaponDefHandler;

  CWeaponDefHandler.prototype['__destroy__'] = CWeaponDefHandler.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CWeaponDefHandler___destroy___0(self);
};
// CGeometricObjects
function CGeometricObjects() { throw "cannot construct a CGeometricObjects, no constructor in IDL" }
CGeometricObjects.prototype = Object.create(WrapperObject.prototype);
CGeometricObjects.prototype.constructor = CGeometricObjects;
CGeometricObjects.prototype.__class__ = CGeometricObjects;
CGeometricObjects.__cache__ = {};
Module['CGeometricObjects'] = CGeometricObjects;

CGeometricObjects.prototype['AddSpline'] = CGeometricObjects.prototype.AddSpline = function(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  if (arg2 && typeof arg2 === 'object') arg2 = arg2.ptr;
  if (arg3 && typeof arg3 === 'object') arg3 = arg3.ptr;
  if (arg4 && typeof arg4 === 'object') arg4 = arg4.ptr;
  if (arg5 && typeof arg5 === 'object') arg5 = arg5.ptr;
  if (arg6 && typeof arg6 === 'object') arg6 = arg6.ptr;
  if (arg7 && typeof arg7 === 'object') arg7 = arg7.ptr;
  return _emscripten_bind_CGeometricObjects_AddSpline_8(self, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
};;

CGeometricObjects.prototype['DeleteGroup'] = CGeometricObjects.prototype.DeleteGroup = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CGeometricObjects_DeleteGroup_1(self, arg0);
};;

CGeometricObjects.prototype['SetColor'] = CGeometricObjects.prototype.SetColor = function(arg0, arg1, arg2, arg3, arg4) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  if (arg2 && typeof arg2 === 'object') arg2 = arg2.ptr;
  if (arg3 && typeof arg3 === 'object') arg3 = arg3.ptr;
  if (arg4 && typeof arg4 === 'object') arg4 = arg4.ptr;
  _emscripten_bind_CGeometricObjects_SetColor_5(self, arg0, arg1, arg2, arg3, arg4);
};;

CGeometricObjects.prototype['AddLine'] = CGeometricObjects.prototype.AddLine = function(arg0, arg1, arg2, arg3, arg4, arg5) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  if (arg2 && typeof arg2 === 'object') arg2 = arg2.ptr;
  if (arg3 && typeof arg3 === 'object') arg3 = arg3.ptr;
  if (arg4 && typeof arg4 === 'object') arg4 = arg4.ptr;
  if (arg5 && typeof arg5 === 'object') arg5 = arg5.ptr;
  return _emscripten_bind_CGeometricObjects_AddLine_6(self, arg0, arg1, arg2, arg3, arg4, arg5);
};;

CGeometricObjects.prototype['Update'] = CGeometricObjects.prototype.Update = function() {
  var self = this.ptr;
  _emscripten_bind_CGeometricObjects_Update_0(self);
};;

CGeometricObjects.prototype['MarkSquare'] = CGeometricObjects.prototype.MarkSquare = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CGeometricObjects_MarkSquare_1(self, arg0);
};;

  CGeometricObjects.prototype['__destroy__'] = CGeometricObjects.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CGeometricObjects___destroy___0(self);
};
// CExplosionCreator
function CExplosionCreator() { throw "cannot construct a CExplosionCreator, no constructor in IDL" }
CExplosionCreator.prototype = Object.create(WrapperObject.prototype);
CExplosionCreator.prototype.constructor = CExplosionCreator;
CExplosionCreator.prototype.__class__ = CExplosionCreator;
CExplosionCreator.__cache__ = {};
Module['CExplosionCreator'] = CExplosionCreator;

  CExplosionCreator.prototype['__destroy__'] = CExplosionCreator.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CExplosionCreator___destroy___0(self);
};
// CRectangularSearchConstraint
function CRectangularSearchConstraint() { throw "cannot construct a CRectangularSearchConstraint, no constructor in IDL" }
CRectangularSearchConstraint.prototype = Object.create(WrapperObject.prototype);
CRectangularSearchConstraint.prototype.constructor = CRectangularSearchConstraint;
CRectangularSearchConstraint.prototype.__class__ = CRectangularSearchConstraint;
CRectangularSearchConstraint.__cache__ = {};
Module['CRectangularSearchConstraint'] = CRectangularSearchConstraint;

CRectangularSearchConstraint.prototype['WithinConstraints'] = CRectangularSearchConstraint.prototype.WithinConstraints = function(arg0, arg1) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  return !!(_emscripten_bind_CRectangularSearchConstraint_WithinConstraints_2(self, arg0, arg1));
};;

  CRectangularSearchConstraint.prototype['__destroy__'] = CRectangularSearchConstraint.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CRectangularSearchConstraint___destroy___0(self);
};
// CollisionQuery
function CollisionQuery() { throw "cannot construct a CollisionQuery, no constructor in IDL" }
CollisionQuery.prototype = Object.create(WrapperObject.prototype);
CollisionQuery.prototype.constructor = CollisionQuery;
CollisionQuery.prototype.__class__ = CollisionQuery;
CollisionQuery.__cache__ = {};
Module['CollisionQuery'] = CollisionQuery;

CollisionQuery.prototype['InsideHit'] = CollisionQuery.prototype.InsideHit = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CollisionQuery_InsideHit_0(self));
};;

CollisionQuery.prototype['IngressHit'] = CollisionQuery.prototype.IngressHit = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CollisionQuery_IngressHit_0(self));
};;

CollisionQuery.prototype['EgressHit'] = CollisionQuery.prototype.EgressHit = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CollisionQuery_EgressHit_0(self));
};;

CollisionQuery.prototype['AnyHit'] = CollisionQuery.prototype.AnyHit = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CollisionQuery_AnyHit_0(self));
};;

  CollisionQuery.prototype['__destroy__'] = CollisionQuery.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CollisionQuery___destroy___0(self);
};
// VoidPtr
function VoidPtr() { throw "cannot construct a VoidPtr, no constructor in IDL" }
VoidPtr.prototype = Object.create(WrapperObject.prototype);
VoidPtr.prototype.constructor = VoidPtr;
VoidPtr.prototype.__class__ = VoidPtr;
VoidPtr.__cache__ = {};
Module['VoidPtr'] = VoidPtr;

  VoidPtr.prototype['__destroy__'] = VoidPtr.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_VoidPtr___destroy___0(self);
};
// CCircularSearchConstraint
function CCircularSearchConstraint() { throw "cannot construct a CCircularSearchConstraint, no constructor in IDL" }
CCircularSearchConstraint.prototype = Object.create(WrapperObject.prototype);
CCircularSearchConstraint.prototype.constructor = CCircularSearchConstraint;
CCircularSearchConstraint.prototype.__class__ = CCircularSearchConstraint;
CCircularSearchConstraint.__cache__ = {};
Module['CCircularSearchConstraint'] = CCircularSearchConstraint;

CCircularSearchConstraint.prototype['WithinConstraints'] = CCircularSearchConstraint.prototype.WithinConstraints = function(arg0, arg1) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  return !!(_emscripten_bind_CCircularSearchConstraint_WithinConstraints_2(self, arg0, arg1));
};;

  CCircularSearchConstraint.prototype['__destroy__'] = CCircularSearchConstraint.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CCircularSearchConstraint___destroy___0(self);
};
// CUnitLoader
function CUnitLoader() { throw "cannot construct a CUnitLoader, no constructor in IDL" }
CUnitLoader.prototype = Object.create(WrapperObject.prototype);
CUnitLoader.prototype.constructor = CUnitLoader;
CUnitLoader.prototype.__class__ = CUnitLoader;
CUnitLoader.__cache__ = {};
Module['CUnitLoader'] = CUnitLoader;

  CUnitLoader.prototype['__destroy__'] = CUnitLoader.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CUnitLoader___destroy___0(self);
};
// CCobUnitScriptNames
function CCobUnitScriptNames() { throw "cannot construct a CCobUnitScriptNames, no constructor in IDL" }
CCobUnitScriptNames.prototype = Object.create(WrapperObject.prototype);
CCobUnitScriptNames.prototype.constructor = CCobUnitScriptNames;
CCobUnitScriptNames.prototype.__class__ = CCobUnitScriptNames;
CCobUnitScriptNames.__cache__ = {};
Module['CCobUnitScriptNames'] = CCobUnitScriptNames;

  CCobUnitScriptNames.prototype['__destroy__'] = CCobUnitScriptNames.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CCobUnitScriptNames___destroy___0(self);
};
// CUnitScriptEngine
function CUnitScriptEngine() { throw "cannot construct a CUnitScriptEngine, no constructor in IDL" }
CUnitScriptEngine.prototype = Object.create(WrapperObject.prototype);
CUnitScriptEngine.prototype.constructor = CUnitScriptEngine;
CUnitScriptEngine.prototype.__class__ = CUnitScriptEngine;
CUnitScriptEngine.__cache__ = {};
Module['CUnitScriptEngine'] = CUnitScriptEngine;

CUnitScriptEngine.prototype['Tick'] = CUnitScriptEngine.prototype.Tick = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CUnitScriptEngine_Tick_1(self, arg0);
};;

CUnitScriptEngine.prototype['InitStatic'] = CUnitScriptEngine.prototype.InitStatic = function() {
  var self = this.ptr;
  _emscripten_bind_CUnitScriptEngine_InitStatic_0(self);
};;

CUnitScriptEngine.prototype['KillStatic'] = CUnitScriptEngine.prototype.KillStatic = function() {
  var self = this.ptr;
  _emscripten_bind_CUnitScriptEngine_KillStatic_0(self);
};;

  CUnitScriptEngine.prototype['__destroy__'] = CUnitScriptEngine.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CUnitScriptEngine___destroy___0(self);
};
// CBuilder
function CBuilder() { throw "cannot construct a CBuilder, no constructor in IDL" }
CBuilder.prototype = Object.create(WrapperObject.prototype);
CBuilder.prototype.constructor = CBuilder;
CBuilder.prototype.__class__ = CBuilder;
CBuilder.__cache__ = {};
Module['CBuilder'] = CBuilder;

CBuilder.prototype['Update'] = CBuilder.prototype.Update = function() {
  var self = this.ptr;
  _emscripten_bind_CBuilder_Update_0(self);
};;

CBuilder.prototype['SlowUpdate'] = CBuilder.prototype.SlowUpdate = function() {
  var self = this.ptr;
  _emscripten_bind_CBuilder_SlowUpdate_0(self);
};;

CBuilder.prototype['StopBuild'] = CBuilder.prototype.StopBuild = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CBuilder_StopBuild_1(self, arg0);
};;

CBuilder.prototype['StartRestore'] = CBuilder.prototype.StartRestore = function(arg0, arg1) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  _emscripten_bind_CBuilder_StartRestore_2(self, arg0, arg1);
};;

CBuilder.prototype['ScriptStartBuilding'] = CBuilder.prototype.ScriptStartBuilding = function(arg0, arg1) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  return !!(_emscripten_bind_CBuilder_ScriptStartBuilding_2(self, arg0, arg1));
};;

  CBuilder.prototype['__destroy__'] = CBuilder.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CBuilder___destroy___0(self);
};
// CAirCAI
function CAirCAI() { throw "cannot construct a CAirCAI, no constructor in IDL" }
CAirCAI.prototype = Object.create(WrapperObject.prototype);
CAirCAI.prototype.constructor = CAirCAI;
CAirCAI.prototype.__class__ = CAirCAI;
CAirCAI.__cache__ = {};
Module['CAirCAI'] = CAirCAI;

CAirCAI.prototype['SlowUpdate'] = CAirCAI.prototype.SlowUpdate = function() {
  var self = this.ptr;
  _emscripten_bind_CAirCAI_SlowUpdate_0(self);
};;

CAirCAI.prototype['FinishCommand'] = CAirCAI.prototype.FinishCommand = function() {
  var self = this.ptr;
  _emscripten_bind_CAirCAI_FinishCommand_0(self);
};;

  CAirCAI.prototype['__destroy__'] = CAirCAI.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CAirCAI___destroy___0(self);
};
// CollisionVolume
function CollisionVolume() { throw "cannot construct a CollisionVolume, no constructor in IDL" }
CollisionVolume.prototype = Object.create(WrapperObject.prototype);
CollisionVolume.prototype.constructor = CollisionVolume;
CollisionVolume.prototype.__class__ = CollisionVolume;
CollisionVolume.__cache__ = {};
Module['CollisionVolume'] = CollisionVolume;

CollisionVolume.prototype['PostLoad'] = CollisionVolume.prototype.PostLoad = function() {
  var self = this.ptr;
  _emscripten_bind_CollisionVolume_PostLoad_0(self);
};;

CollisionVolume.prototype['InitSphere'] = CollisionVolume.prototype.InitSphere = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CollisionVolume_InitSphere_1(self, arg0);
};;

CollisionVolume.prototype['SetBoundingRadius'] = CollisionVolume.prototype.SetBoundingRadius = function() {
  var self = this.ptr;
  _emscripten_bind_CollisionVolume_SetBoundingRadius_0(self);
};;

CollisionVolume.prototype['GetVolumeType'] = CollisionVolume.prototype.GetVolumeType = function() {
  var self = this.ptr;
  return _emscripten_bind_CollisionVolume_GetVolumeType_0(self);
};;

CollisionVolume.prototype['SetVolumeType'] = CollisionVolume.prototype.SetVolumeType = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CollisionVolume_SetVolumeType_1(self, arg0);
};;

CollisionVolume.prototype['SetIgnoreHits'] = CollisionVolume.prototype.SetIgnoreHits = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CollisionVolume_SetIgnoreHits_1(self, arg0);
};;

CollisionVolume.prototype['SetUseContHitTest'] = CollisionVolume.prototype.SetUseContHitTest = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CollisionVolume_SetUseContHitTest_1(self, arg0);
};;

CollisionVolume.prototype['SetDefaultToPieceTree'] = CollisionVolume.prototype.SetDefaultToPieceTree = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CollisionVolume_SetDefaultToPieceTree_1(self, arg0);
};;

CollisionVolume.prototype['SetDefaultToFootPrint'] = CollisionVolume.prototype.SetDefaultToFootPrint = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CollisionVolume_SetDefaultToFootPrint_1(self, arg0);
};;

CollisionVolume.prototype['GetPrimaryAxis'] = CollisionVolume.prototype.GetPrimaryAxis = function() {
  var self = this.ptr;
  return _emscripten_bind_CollisionVolume_GetPrimaryAxis_0(self);
};;

CollisionVolume.prototype['GetSecondaryAxis'] = CollisionVolume.prototype.GetSecondaryAxis = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return _emscripten_bind_CollisionVolume_GetSecondaryAxis_1(self, arg0);
};;

CollisionVolume.prototype['GetBoundingRadius'] = CollisionVolume.prototype.GetBoundingRadius = function() {
  var self = this.ptr;
  return _emscripten_bind_CollisionVolume_GetBoundingRadius_0(self);
};;

CollisionVolume.prototype['GetBoundingRadiusSq'] = CollisionVolume.prototype.GetBoundingRadiusSq = function() {
  var self = this.ptr;
  return _emscripten_bind_CollisionVolume_GetBoundingRadiusSq_0(self);
};;

CollisionVolume.prototype['GetOffset'] = CollisionVolume.prototype.GetOffset = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return _emscripten_bind_CollisionVolume_GetOffset_1(self, arg0);
};;

CollisionVolume.prototype['GetScale'] = CollisionVolume.prototype.GetScale = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return _emscripten_bind_CollisionVolume_GetScale_1(self, arg0);
};;

CollisionVolume.prototype['GetHScale'] = CollisionVolume.prototype.GetHScale = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return _emscripten_bind_CollisionVolume_GetHScale_1(self, arg0);
};;

CollisionVolume.prototype['GetHScaleSq'] = CollisionVolume.prototype.GetHScaleSq = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return _emscripten_bind_CollisionVolume_GetHScaleSq_1(self, arg0);
};;

CollisionVolume.prototype['IgnoreHits'] = CollisionVolume.prototype.IgnoreHits = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CollisionVolume_IgnoreHits_0(self));
};;

CollisionVolume.prototype['UseContHitTest'] = CollisionVolume.prototype.UseContHitTest = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CollisionVolume_UseContHitTest_0(self));
};;

CollisionVolume.prototype['DefaultToSphere'] = CollisionVolume.prototype.DefaultToSphere = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CollisionVolume_DefaultToSphere_0(self));
};;

CollisionVolume.prototype['DefaultToFootPrint'] = CollisionVolume.prototype.DefaultToFootPrint = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CollisionVolume_DefaultToFootPrint_0(self));
};;

CollisionVolume.prototype['DefaultToPieceTree'] = CollisionVolume.prototype.DefaultToPieceTree = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CollisionVolume_DefaultToPieceTree_0(self));
};;

  CollisionVolume.prototype['__destroy__'] = CollisionVolume.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CollisionVolume___destroy___0(self);
};
// CFactory
function CFactory() { throw "cannot construct a CFactory, no constructor in IDL" }
CFactory.prototype = Object.create(WrapperObject.prototype);
CFactory.prototype.constructor = CFactory;
CFactory.prototype.__class__ = CFactory;
CFactory.__cache__ = {};
Module['CFactory'] = CFactory;

CFactory.prototype['StopBuild'] = CFactory.prototype.StopBuild = function() {
  var self = this.ptr;
  _emscripten_bind_CFactory_StopBuild_0(self);
};;

CFactory.prototype['Update'] = CFactory.prototype.Update = function() {
  var self = this.ptr;
  _emscripten_bind_CFactory_Update_0(self);
};;

CFactory.prototype['CreateNanoParticle'] = CFactory.prototype.CreateNanoParticle = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CFactory_CreateNanoParticle_1(self, arg0);
};;

  CFactory.prototype['__destroy__'] = CFactory.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CFactory___destroy___0(self);
};
// CFactoryCAI
function CFactoryCAI() { throw "cannot construct a CFactoryCAI, no constructor in IDL" }
CFactoryCAI.prototype = Object.create(WrapperObject.prototype);
CFactoryCAI.prototype.constructor = CFactoryCAI;
CFactoryCAI.prototype.__class__ = CFactoryCAI;
CFactoryCAI.__cache__ = {};
Module['CFactoryCAI'] = CFactoryCAI;

CFactoryCAI.prototype['SlowUpdate'] = CFactoryCAI.prototype.SlowUpdate = function() {
  var self = this.ptr;
  _emscripten_bind_CFactoryCAI_SlowUpdate_0(self);
};;

  CFactoryCAI.prototype['__destroy__'] = CFactoryCAI.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CFactoryCAI___destroy___0(self);
};
// CCollisionHandler
function CCollisionHandler() { throw "cannot construct a CCollisionHandler, no constructor in IDL" }
CCollisionHandler.prototype = Object.create(WrapperObject.prototype);
CCollisionHandler.prototype.constructor = CCollisionHandler;
CCollisionHandler.prototype.__class__ = CCollisionHandler;
CCollisionHandler.__cache__ = {};
Module['CCollisionHandler'] = CCollisionHandler;

CCollisionHandler.prototype['PrintStats'] = CCollisionHandler.prototype.PrintStats = function() {
  var self = this.ptr;
  _emscripten_bind_CCollisionHandler_PrintStats_0(self);
};;

  CCollisionHandler.prototype['__destroy__'] = CCollisionHandler.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CCollisionHandler___destroy___0(self);
};
// CommonDefHandler
function CommonDefHandler() { throw "cannot construct a CommonDefHandler, no constructor in IDL" }
CommonDefHandler.prototype = Object.create(WrapperObject.prototype);
CommonDefHandler.prototype.constructor = CommonDefHandler;
CommonDefHandler.prototype.__class__ = CommonDefHandler;
CommonDefHandler.__cache__ = {};
Module['CommonDefHandler'] = CommonDefHandler;

  CommonDefHandler.prototype['__destroy__'] = CommonDefHandler.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CommonDefHandler___destroy___0(self);
};
// CLuaUnitScriptNames
function CLuaUnitScriptNames() { throw "cannot construct a CLuaUnitScriptNames, no constructor in IDL" }
CLuaUnitScriptNames.prototype = Object.create(WrapperObject.prototype);
CLuaUnitScriptNames.prototype.constructor = CLuaUnitScriptNames;
CLuaUnitScriptNames.prototype.__class__ = CLuaUnitScriptNames;
CLuaUnitScriptNames.__cache__ = {};
Module['CLuaUnitScriptNames'] = CLuaUnitScriptNames;

  CLuaUnitScriptNames.prototype['__destroy__'] = CLuaUnitScriptNames.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScriptNames___destroy___0(self);
};
// CStarburstProjectile
function CStarburstProjectile() { throw "cannot construct a CStarburstProjectile, no constructor in IDL" }
CStarburstProjectile.prototype = Object.create(WrapperObject.prototype);
CStarburstProjectile.prototype.constructor = CStarburstProjectile;
CStarburstProjectile.prototype.__class__ = CStarburstProjectile;
CStarburstProjectile.__cache__ = {};
Module['CStarburstProjectile'] = CStarburstProjectile;

  CStarburstProjectile.prototype['__destroy__'] = CStarburstProjectile.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CStarburstProjectile___destroy___0(self);
};
// ClassAliasList
function ClassAliasList() { throw "cannot construct a ClassAliasList, no constructor in IDL" }
ClassAliasList.prototype = Object.create(WrapperObject.prototype);
ClassAliasList.prototype.constructor = ClassAliasList;
ClassAliasList.prototype.__class__ = ClassAliasList;
ClassAliasList.__cache__ = {};
Module['ClassAliasList'] = ClassAliasList;

ClassAliasList.prototype['Clear'] = ClassAliasList.prototype.Clear = function() {
  var self = this.ptr;
  _emscripten_bind_ClassAliasList_Clear_0(self);
};;

  ClassAliasList.prototype['__destroy__'] = ClassAliasList.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_ClassAliasList___destroy___0(self);
};
// CScriptMoveType
function CScriptMoveType() { throw "cannot construct a CScriptMoveType, no constructor in IDL" }
CScriptMoveType.prototype = Object.create(WrapperObject.prototype);
CScriptMoveType.prototype.constructor = CScriptMoveType;
CScriptMoveType.prototype.__class__ = CScriptMoveType;
CScriptMoveType.__cache__ = {};
Module['CScriptMoveType'] = CScriptMoveType;

CScriptMoveType.prototype['Update'] = CScriptMoveType.prototype.Update = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CScriptMoveType_Update_0(self));
};;

CScriptMoveType.prototype['ForceUpdates'] = CScriptMoveType.prototype.ForceUpdates = function() {
  var self = this.ptr;
  _emscripten_bind_CScriptMoveType_ForceUpdates_0(self);
};;

CScriptMoveType.prototype['SetHeading'] = CScriptMoveType.prototype.SetHeading = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CScriptMoveType_SetHeading_1(self, arg0);
};;

CScriptMoveType.prototype['SetNoBlocking'] = CScriptMoveType.prototype.SetNoBlocking = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CScriptMoveType_SetNoBlocking_1(self, arg0);
};;

CScriptMoveType.prototype['StartMoving'] = CScriptMoveType.prototype.StartMoving = function(arg0, arg1) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  _emscripten_bind_CScriptMoveType_StartMoving_2(self, arg0, arg1);
};;

CScriptMoveType.prototype['KeepPointingTo'] = CScriptMoveType.prototype.KeepPointingTo = function(arg0, arg1, arg2) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  if (arg2 && typeof arg2 === 'object') arg2 = arg2.ptr;
  _emscripten_bind_CScriptMoveType_KeepPointingTo_3(self, arg0, arg1, arg2);
};;

CScriptMoveType.prototype['StopMoving'] = CScriptMoveType.prototype.StopMoving = function(arg0, arg1, arg2) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  if (arg2 && typeof arg2 === 'object') arg2 = arg2.ptr;
  _emscripten_bind_CScriptMoveType_StopMoving_3(self, arg0, arg1, arg2);
};;

CScriptMoveType.prototype['SetMaxSpeed'] = CScriptMoveType.prototype.SetMaxSpeed = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CScriptMoveType_SetMaxSpeed_1(self, arg0);
};;

CScriptMoveType.prototype['SetWantedMaxSpeed'] = CScriptMoveType.prototype.SetWantedMaxSpeed = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CScriptMoveType_SetWantedMaxSpeed_1(self, arg0);
};;

CScriptMoveType.prototype['LeaveTransport'] = CScriptMoveType.prototype.LeaveTransport = function() {
  var self = this.ptr;
  _emscripten_bind_CScriptMoveType_LeaveTransport_0(self);
};;

  CScriptMoveType.prototype['__destroy__'] = CScriptMoveType.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CScriptMoveType___destroy___0(self);
};
// CFeatureDefHandler
function CFeatureDefHandler() { throw "cannot construct a CFeatureDefHandler, no constructor in IDL" }
CFeatureDefHandler.prototype = Object.create(WrapperObject.prototype);
CFeatureDefHandler.prototype.constructor = CFeatureDefHandler;
CFeatureDefHandler.prototype.__class__ = CFeatureDefHandler;
CFeatureDefHandler.__cache__ = {};
Module['CFeatureDefHandler'] = CFeatureDefHandler;

CFeatureDefHandler.prototype['LoadFeatureDefsFromMap'] = CFeatureDefHandler.prototype.LoadFeatureDefsFromMap = function() {
  var self = this.ptr;
  _emscripten_bind_CFeatureDefHandler_LoadFeatureDefsFromMap_0(self);
};;

  CFeatureDefHandler.prototype['__destroy__'] = CFeatureDefHandler.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CFeatureDefHandler___destroy___0(self);
};
// CBuilding
function CBuilding() { throw "cannot construct a CBuilding, no constructor in IDL" }
CBuilding.prototype = Object.create(WrapperObject.prototype);
CBuilding.prototype.constructor = CBuilding;
CBuilding.prototype.__class__ = CBuilding;
CBuilding.__cache__ = {};
Module['CBuilding'] = CBuilding;

  CBuilding.prototype['__destroy__'] = CBuilding.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CBuilding___destroy___0(self);
};
// CUnitScriptFactory
function CUnitScriptFactory() { throw "cannot construct a CUnitScriptFactory, no constructor in IDL" }
CUnitScriptFactory.prototype = Object.create(WrapperObject.prototype);
CUnitScriptFactory.prototype.constructor = CUnitScriptFactory;
CUnitScriptFactory.prototype.__class__ = CUnitScriptFactory;
CUnitScriptFactory.__cache__ = {};
Module['CUnitScriptFactory'] = CUnitScriptFactory;

  CUnitScriptFactory.prototype['__destroy__'] = CUnitScriptFactory.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CUnitScriptFactory___destroy___0(self);
};
// CLosHandler
function CLosHandler() { throw "cannot construct a CLosHandler, no constructor in IDL" }
CLosHandler.prototype = Object.create(WrapperObject.prototype);
CLosHandler.prototype.constructor = CLosHandler;
CLosHandler.prototype.__class__ = CLosHandler;
CLosHandler.__cache__ = {};
Module['CLosHandler'] = CLosHandler;

CLosHandler.prototype['IncreaseAllyTeamRadarErrorSize'] = CLosHandler.prototype.IncreaseAllyTeamRadarErrorSize = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLosHandler_IncreaseAllyTeamRadarErrorSize_1(self, arg0);
};;

CLosHandler.prototype['DecreaseAllyTeamRadarErrorSize'] = CLosHandler.prototype.DecreaseAllyTeamRadarErrorSize = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLosHandler_DecreaseAllyTeamRadarErrorSize_1(self, arg0);
};;

CLosHandler.prototype['SetAllyTeamRadarErrorSize'] = CLosHandler.prototype.SetAllyTeamRadarErrorSize = function(arg0, arg1) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  _emscripten_bind_CLosHandler_SetAllyTeamRadarErrorSize_2(self, arg0, arg1);
};;

CLosHandler.prototype['GetAllyTeamRadarErrorSize'] = CLosHandler.prototype.GetAllyTeamRadarErrorSize = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return _emscripten_bind_CLosHandler_GetAllyTeamRadarErrorSize_1(self, arg0);
};;

CLosHandler.prototype['SetBaseRadarErrorSize'] = CLosHandler.prototype.SetBaseRadarErrorSize = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLosHandler_SetBaseRadarErrorSize_1(self, arg0);
};;

CLosHandler.prototype['SetBaseRadarErrorMult'] = CLosHandler.prototype.SetBaseRadarErrorMult = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLosHandler_SetBaseRadarErrorMult_1(self, arg0);
};;

CLosHandler.prototype['GetBaseRadarErrorSize'] = CLosHandler.prototype.GetBaseRadarErrorSize = function() {
  var self = this.ptr;
  return _emscripten_bind_CLosHandler_GetBaseRadarErrorSize_0(self);
};;

CLosHandler.prototype['GetBaseRadarErrorMult'] = CLosHandler.prototype.GetBaseRadarErrorMult = function() {
  var self = this.ptr;
  return _emscripten_bind_CLosHandler_GetBaseRadarErrorMult_0(self);
};;

CLosHandler.prototype['GetFullRead'] = CLosHandler.prototype.GetFullRead = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CLosHandler_GetFullRead_0(self));
};;

CLosHandler.prototype['GetReadAllyTeam'] = CLosHandler.prototype.GetReadAllyTeam = function() {
  var self = this.ptr;
  return _emscripten_bind_CLosHandler_GetReadAllyTeam_0(self);
};;

CLosHandler.prototype['Update'] = CLosHandler.prototype.Update = function() {
  var self = this.ptr;
  _emscripten_bind_CLosHandler_Update_0(self);
};;

  CLosHandler.prototype['__destroy__'] = CLosHandler.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CLosHandler___destroy___0(self);
};
// CPathEstimator
function CPathEstimator() { throw "cannot construct a CPathEstimator, no constructor in IDL" }
CPathEstimator.prototype = Object.create(WrapperObject.prototype);
CPathEstimator.prototype.constructor = CPathEstimator;
CPathEstimator.prototype.__class__ = CPathEstimator;
CPathEstimator.__cache__ = {};
Module['CPathEstimator'] = CPathEstimator;

CPathEstimator.prototype['MapChanged'] = CPathEstimator.prototype.MapChanged = function(arg0, arg1, arg2, arg3) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  if (arg2 && typeof arg2 === 'object') arg2 = arg2.ptr;
  if (arg3 && typeof arg3 === 'object') arg3 = arg3.ptr;
  _emscripten_bind_CPathEstimator_MapChanged_4(self, arg0, arg1, arg2, arg3);
};;

CPathEstimator.prototype['Update'] = CPathEstimator.prototype.Update = function() {
  var self = this.ptr;
  _emscripten_bind_CPathEstimator_Update_0(self);
};;

CPathEstimator.prototype['GetPathChecksum'] = CPathEstimator.prototype.GetPathChecksum = function() {
  var self = this.ptr;
  return _emscripten_bind_CPathEstimator_GetPathChecksum_0(self);
};;

  CPathEstimator.prototype['__destroy__'] = CPathEstimator.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CPathEstimator___destroy___0(self);
};
// CCannon
function CCannon() { throw "cannot construct a CCannon, no constructor in IDL" }
CCannon.prototype = Object.create(WrapperObject.prototype);
CCannon.prototype.constructor = CCannon;
CCannon.prototype.__class__ = CCannon;
CCannon.__cache__ = {};
Module['CCannon'] = CCannon;

CCannon.prototype['Init'] = CCannon.prototype.Init = function() {
  var self = this.ptr;
  _emscripten_bind_CCannon_Init_0(self);
};;

CCannon.prototype['UpdateRange'] = CCannon.prototype.UpdateRange = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CCannon_UpdateRange_1(self, arg0);
};;

CCannon.prototype['UpdateWantedDir'] = CCannon.prototype.UpdateWantedDir = function() {
  var self = this.ptr;
  _emscripten_bind_CCannon_UpdateWantedDir_0(self);
};;

CCannon.prototype['SlowUpdate'] = CCannon.prototype.SlowUpdate = function() {
  var self = this.ptr;
  _emscripten_bind_CCannon_SlowUpdate_0(self);
};;

CCannon.prototype['GetRange2D'] = CCannon.prototype.GetRange2D = function(arg0, arg1) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  if (arg1 === undefined) { return _emscripten_bind_CCannon_GetRange2D_1(self, arg0) }
  return _emscripten_bind_CCannon_GetRange2D_2(self, arg0, arg1);
};;

  CCannon.prototype['__destroy__'] = CCannon.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CCannon___destroy___0(self);
};
// CWeaponLoader
function CWeaponLoader() { throw "cannot construct a CWeaponLoader, no constructor in IDL" }
CWeaponLoader.prototype = Object.create(WrapperObject.prototype);
CWeaponLoader.prototype.constructor = CWeaponLoader;
CWeaponLoader.prototype.__class__ = CWeaponLoader;
CWeaponLoader.__cache__ = {};
Module['CWeaponLoader'] = CWeaponLoader;

  CWeaponLoader.prototype['__destroy__'] = CWeaponLoader.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CWeaponLoader___destroy___0(self);
};
// CCustomExplosionGenerator
function CCustomExplosionGenerator() { throw "cannot construct a CCustomExplosionGenerator, no constructor in IDL" }
CCustomExplosionGenerator.prototype = Object.create(WrapperObject.prototype);
CCustomExplosionGenerator.prototype.constructor = CCustomExplosionGenerator;
CCustomExplosionGenerator.prototype.__class__ = CCustomExplosionGenerator;
CCustomExplosionGenerator.__cache__ = {};
Module['CCustomExplosionGenerator'] = CCustomExplosionGenerator;

CCustomExplosionGenerator.prototype['OutputProjectileClassInfo'] = CCustomExplosionGenerator.prototype.OutputProjectileClassInfo = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CCustomExplosionGenerator_OutputProjectileClassInfo_0(self));
};;

CCustomExplosionGenerator.prototype['GetFlagsFromHeight'] = CCustomExplosionGenerator.prototype.GetFlagsFromHeight = function(arg0, arg1) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  return _emscripten_bind_CCustomExplosionGenerator_GetFlagsFromHeight_2(self, arg0, arg1);
};;

  CCustomExplosionGenerator.prototype['__destroy__'] = CCustomExplosionGenerator.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CCustomExplosionGenerator___destroy___0(self);
};
// CResourceMapAnalyzer
function CResourceMapAnalyzer() { throw "cannot construct a CResourceMapAnalyzer, no constructor in IDL" }
CResourceMapAnalyzer.prototype = Object.create(WrapperObject.prototype);
CResourceMapAnalyzer.prototype.constructor = CResourceMapAnalyzer;
CResourceMapAnalyzer.prototype.__class__ = CResourceMapAnalyzer;
CResourceMapAnalyzer.__cache__ = {};
Module['CResourceMapAnalyzer'] = CResourceMapAnalyzer;

CResourceMapAnalyzer.prototype['GetAverageIncome'] = CResourceMapAnalyzer.prototype.GetAverageIncome = function() {
  var self = this.ptr;
  return _emscripten_bind_CResourceMapAnalyzer_GetAverageIncome_0(self);
};;

  CResourceMapAnalyzer.prototype['__destroy__'] = CResourceMapAnalyzer.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CResourceMapAnalyzer___destroy___0(self);
};
// CLuaUnitScript
function CLuaUnitScript() { throw "cannot construct a CLuaUnitScript, no constructor in IDL" }
CLuaUnitScript.prototype = Object.create(WrapperObject.prototype);
CLuaUnitScript.prototype.constructor = CLuaUnitScript;
CLuaUnitScript.prototype.__class__ = CLuaUnitScript;
CLuaUnitScript.__cache__ = {};
Module['CLuaUnitScript'] = CLuaUnitScript;

CLuaUnitScript.prototype['HasFunction'] = CLuaUnitScript.prototype.HasFunction = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return !!(_emscripten_bind_CLuaUnitScript_HasFunction_1(self, arg0));
};;

CLuaUnitScript.prototype['HasBlockShot'] = CLuaUnitScript.prototype.HasBlockShot = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return !!(_emscripten_bind_CLuaUnitScript_HasBlockShot_1(self, arg0));
};;

CLuaUnitScript.prototype['HasTargetWeight'] = CLuaUnitScript.prototype.HasTargetWeight = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return !!(_emscripten_bind_CLuaUnitScript_HasTargetWeight_1(self, arg0));
};;

CLuaUnitScript.prototype['RawCall'] = CLuaUnitScript.prototype.RawCall = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLuaUnitScript_RawCall_1(self, arg0);
};;

CLuaUnitScript.prototype['Create'] = CLuaUnitScript.prototype.Create = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript_Create_0(self);
};;

CLuaUnitScript.prototype['Killed'] = CLuaUnitScript.prototype.Killed = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript_Killed_0(self);
};;

CLuaUnitScript.prototype['WindChanged'] = CLuaUnitScript.prototype.WindChanged = function(arg0, arg1) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  _emscripten_bind_CLuaUnitScript_WindChanged_2(self, arg0, arg1);
};;

CLuaUnitScript.prototype['ExtractionRateChanged'] = CLuaUnitScript.prototype.ExtractionRateChanged = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLuaUnitScript_ExtractionRateChanged_1(self, arg0);
};;

CLuaUnitScript.prototype['SetSFXOccupy'] = CLuaUnitScript.prototype.SetSFXOccupy = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLuaUnitScript_SetSFXOccupy_1(self, arg0);
};;

CLuaUnitScript.prototype['StartBuilding'] = CLuaUnitScript.prototype.StartBuilding = function(arg0, arg1) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  if (arg0 === undefined) { _emscripten_bind_CLuaUnitScript_StartBuilding_0(self);  return }
  if (arg1 === undefined) { _emscripten_bind_CLuaUnitScript_StartBuilding_1(self, arg0);  return }
  _emscripten_bind_CLuaUnitScript_StartBuilding_2(self, arg0, arg1);
};;

CLuaUnitScript.prototype['QueryNanoPiece'] = CLuaUnitScript.prototype.QueryNanoPiece = function() {
  var self = this.ptr;
  return _emscripten_bind_CLuaUnitScript_QueryNanoPiece_0(self);
};;

CLuaUnitScript.prototype['QueryBuildInfo'] = CLuaUnitScript.prototype.QueryBuildInfo = function() {
  var self = this.ptr;
  return _emscripten_bind_CLuaUnitScript_QueryBuildInfo_0(self);
};;

CLuaUnitScript.prototype['Destroy'] = CLuaUnitScript.prototype.Destroy = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript_Destroy_0(self);
};;

CLuaUnitScript.prototype['StartMoving'] = CLuaUnitScript.prototype.StartMoving = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLuaUnitScript_StartMoving_1(self, arg0);
};;

CLuaUnitScript.prototype['StopMoving'] = CLuaUnitScript.prototype.StopMoving = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript_StopMoving_0(self);
};;

CLuaUnitScript.prototype['StartUnload'] = CLuaUnitScript.prototype.StartUnload = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript_StartUnload_0(self);
};;

CLuaUnitScript.prototype['EndTransport'] = CLuaUnitScript.prototype.EndTransport = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript_EndTransport_0(self);
};;

CLuaUnitScript.prototype['StopBuilding'] = CLuaUnitScript.prototype.StopBuilding = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript_StopBuilding_0(self);
};;

CLuaUnitScript.prototype['Falling'] = CLuaUnitScript.prototype.Falling = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript_Falling_0(self);
};;

CLuaUnitScript.prototype['Landed'] = CLuaUnitScript.prototype.Landed = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript_Landed_0(self);
};;

CLuaUnitScript.prototype['Activate'] = CLuaUnitScript.prototype.Activate = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript_Activate_0(self);
};;

CLuaUnitScript.prototype['Deactivate'] = CLuaUnitScript.prototype.Deactivate = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript_Deactivate_0(self);
};;

CLuaUnitScript.prototype['MoveRate'] = CLuaUnitScript.prototype.MoveRate = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLuaUnitScript_MoveRate_1(self, arg0);
};;

CLuaUnitScript.prototype['FireWeapon'] = CLuaUnitScript.prototype.FireWeapon = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLuaUnitScript_FireWeapon_1(self, arg0);
};;

CLuaUnitScript.prototype['EndBurst'] = CLuaUnitScript.prototype.EndBurst = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLuaUnitScript_EndBurst_1(self, arg0);
};;

CLuaUnitScript.prototype['QueryWeapon'] = CLuaUnitScript.prototype.QueryWeapon = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return _emscripten_bind_CLuaUnitScript_QueryWeapon_1(self, arg0);
};;

CLuaUnitScript.prototype['AimWeapon'] = CLuaUnitScript.prototype.AimWeapon = function(arg0, arg1, arg2) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  if (arg2 && typeof arg2 === 'object') arg2 = arg2.ptr;
  _emscripten_bind_CLuaUnitScript_AimWeapon_3(self, arg0, arg1, arg2);
};;

CLuaUnitScript.prototype['AimFromWeapon'] = CLuaUnitScript.prototype.AimFromWeapon = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  return _emscripten_bind_CLuaUnitScript_AimFromWeapon_1(self, arg0);
};;

CLuaUnitScript.prototype['Shot'] = CLuaUnitScript.prototype.Shot = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CLuaUnitScript_Shot_1(self, arg0);
};;

  CLuaUnitScript.prototype['__destroy__'] = CLuaUnitScript.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CLuaUnitScript___destroy___0(self);
};
// CMobileCAI
function CMobileCAI() { throw "cannot construct a CMobileCAI, no constructor in IDL" }
CMobileCAI.prototype = Object.create(WrapperObject.prototype);
CMobileCAI.prototype.constructor = CMobileCAI;
CMobileCAI.prototype.__class__ = CMobileCAI;
CMobileCAI.__cache__ = {};
Module['CMobileCAI'] = CMobileCAI;

CMobileCAI.prototype['StopMove'] = CMobileCAI.prototype.StopMove = function() {
  var self = this.ptr;
  _emscripten_bind_CMobileCAI_StopMove_0(self);
};;

CMobileCAI.prototype['StopMoveAndFinishCommand'] = CMobileCAI.prototype.StopMoveAndFinishCommand = function() {
  var self = this.ptr;
  _emscripten_bind_CMobileCAI_StopMoveAndFinishCommand_0(self);
};;

CMobileCAI.prototype['SlowUpdate'] = CMobileCAI.prototype.SlowUpdate = function() {
  var self = this.ptr;
  _emscripten_bind_CMobileCAI_SlowUpdate_0(self);
};;

CMobileCAI.prototype['NonMoving'] = CMobileCAI.prototype.NonMoving = function() {
  var self = this.ptr;
  _emscripten_bind_CMobileCAI_NonMoving_0(self);
};;

CMobileCAI.prototype['FinishCommand'] = CMobileCAI.prototype.FinishCommand = function() {
  var self = this.ptr;
  _emscripten_bind_CMobileCAI_FinishCommand_0(self);
};;

CMobileCAI.prototype['CanSetMaxSpeed'] = CMobileCAI.prototype.CanSetMaxSpeed = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CMobileCAI_CanSetMaxSpeed_0(self));
};;

CMobileCAI.prototype['StopSlowGuard'] = CMobileCAI.prototype.StopSlowGuard = function() {
  var self = this.ptr;
  _emscripten_bind_CMobileCAI_StopSlowGuard_0(self);
};;

CMobileCAI.prototype['StartSlowGuard'] = CMobileCAI.prototype.StartSlowGuard = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CMobileCAI_StartSlowGuard_1(self, arg0);
};;

CMobileCAI.prototype['Execute'] = CMobileCAI.prototype.Execute = function() {
  var self = this.ptr;
  _emscripten_bind_CMobileCAI_Execute_0(self);
};;

CMobileCAI.prototype['GetCancelDistance'] = CMobileCAI.prototype.GetCancelDistance = function() {
  var self = this.ptr;
  return _emscripten_bind_CMobileCAI_GetCancelDistance_0(self);
};;

  CMobileCAI.prototype['__destroy__'] = CMobileCAI.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CMobileCAI___destroy___0(self);
};
// CExtractorBuilding
function CExtractorBuilding() { throw "cannot construct a CExtractorBuilding, no constructor in IDL" }
CExtractorBuilding.prototype = Object.create(WrapperObject.prototype);
CExtractorBuilding.prototype.constructor = CExtractorBuilding;
CExtractorBuilding.prototype.__class__ = CExtractorBuilding;
CExtractorBuilding.__cache__ = {};
Module['CExtractorBuilding'] = CExtractorBuilding;

CExtractorBuilding.prototype['ResetExtraction'] = CExtractorBuilding.prototype.ResetExtraction = function() {
  var self = this.ptr;
  _emscripten_bind_CExtractorBuilding_ResetExtraction_0(self);
};;

CExtractorBuilding.prototype['SetExtractionRangeAndDepth'] = CExtractorBuilding.prototype.SetExtractionRangeAndDepth = function(arg0, arg1) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  if (arg1 && typeof arg1 === 'object') arg1 = arg1.ptr;
  _emscripten_bind_CExtractorBuilding_SetExtractionRangeAndDepth_2(self, arg0, arg1);
};;

CExtractorBuilding.prototype['ReCalculateMetalExtraction'] = CExtractorBuilding.prototype.ReCalculateMetalExtraction = function() {
  var self = this.ptr;
  _emscripten_bind_CExtractorBuilding_ReCalculateMetalExtraction_0(self);
};;

CExtractorBuilding.prototype['GetExtractionRange'] = CExtractorBuilding.prototype.GetExtractionRange = function() {
  var self = this.ptr;
  return _emscripten_bind_CExtractorBuilding_GetExtractionRange_0(self);
};;

CExtractorBuilding.prototype['GetExtractionDepth'] = CExtractorBuilding.prototype.GetExtractionDepth = function() {
  var self = this.ptr;
  return _emscripten_bind_CExtractorBuilding_GetExtractionDepth_0(self);
};;

CExtractorBuilding.prototype['FinishedBuilding'] = CExtractorBuilding.prototype.FinishedBuilding = function(arg0) {
  var self = this.ptr;
  if (arg0 && typeof arg0 === 'object') arg0 = arg0.ptr;
  _emscripten_bind_CExtractorBuilding_FinishedBuilding_1(self, arg0);
};;

  CExtractorBuilding.prototype['__destroy__'] = CExtractorBuilding.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CExtractorBuilding___destroy___0(self);
};
// CModInfo
function CModInfo() { throw "cannot construct a CModInfo, no constructor in IDL" }
CModInfo.prototype = Object.create(WrapperObject.prototype);
CModInfo.prototype.constructor = CModInfo;
CModInfo.prototype.__class__ = CModInfo;
CModInfo.__cache__ = {};
Module['CModInfo'] = CModInfo;

CModInfo.prototype['ResetState'] = CModInfo.prototype.ResetState = function() {
  var self = this.ptr;
  _emscripten_bind_CModInfo_ResetState_0(self);
};;

  CModInfo.prototype['__destroy__'] = CModInfo.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CModInfo___destroy___0(self);
};
// CCommandQueue
function CCommandQueue() { throw "cannot construct a CCommandQueue, no constructor in IDL" }
CCommandQueue.prototype = Object.create(WrapperObject.prototype);
CCommandQueue.prototype.constructor = CCommandQueue;
CCommandQueue.prototype.__class__ = CCommandQueue;
CCommandQueue.__cache__ = {};
Module['CCommandQueue'] = CCommandQueue;

CCommandQueue.prototype['empty'] = CCommandQueue.prototype.empty = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CCommandQueue_empty_0(self));
};;

CCommandQueue.prototype['pop_back'] = CCommandQueue.prototype.pop_back = function() {
  var self = this.ptr;
  _emscripten_bind_CCommandQueue_pop_back_0(self);
};;

CCommandQueue.prototype['pop_front'] = CCommandQueue.prototype.pop_front = function() {
  var self = this.ptr;
  _emscripten_bind_CCommandQueue_pop_front_0(self);
};;

CCommandQueue.prototype['clear'] = CCommandQueue.prototype.clear = function() {
  var self = this.ptr;
  _emscripten_bind_CCommandQueue_clear_0(self);
};;

  CCommandQueue.prototype['__destroy__'] = CCommandQueue.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CCommandQueue___destroy___0(self);
};
// CBuilderCAI
function CBuilderCAI() { throw "cannot construct a CBuilderCAI, no constructor in IDL" }
CBuilderCAI.prototype = Object.create(WrapperObject.prototype);
CBuilderCAI.prototype.constructor = CBuilderCAI;
CBuilderCAI.prototype.__class__ = CBuilderCAI;
CBuilderCAI.__cache__ = {};
Module['CBuilderCAI'] = CBuilderCAI;

CBuilderCAI.prototype['InitStatic'] = CBuilderCAI.prototype.InitStatic = function() {
  var self = this.ptr;
  _emscripten_bind_CBuilderCAI_InitStatic_0(self);
};;

CBuilderCAI.prototype['PostLoad'] = CBuilderCAI.prototype.PostLoad = function() {
  var self = this.ptr;
  _emscripten_bind_CBuilderCAI_PostLoad_0(self);
};;

CBuilderCAI.prototype['SlowUpdate'] = CBuilderCAI.prototype.SlowUpdate = function() {
  var self = this.ptr;
  _emscripten_bind_CBuilderCAI_SlowUpdate_0(self);
};;

CBuilderCAI.prototype['FinishCommand'] = CBuilderCAI.prototype.FinishCommand = function() {
  var self = this.ptr;
  _emscripten_bind_CBuilderCAI_FinishCommand_0(self);
};;

  CBuilderCAI.prototype['__destroy__'] = CBuilderCAI.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CBuilderCAI___destroy___0(self);
};
// CMoveMath
function CMoveMath() { throw "cannot construct a CMoveMath, no constructor in IDL" }
CMoveMath.prototype = Object.create(WrapperObject.prototype);
CMoveMath.prototype.constructor = CMoveMath;
CMoveMath.prototype.__class__ = CMoveMath;
CMoveMath.__cache__ = {};
Module['CMoveMath'] = CMoveMath;

  CMoveMath.prototype['__destroy__'] = CMoveMath.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CMoveMath___destroy___0(self);
};
// CGlobalSynced
function CGlobalSynced() { throw "cannot construct a CGlobalSynced, no constructor in IDL" }
CGlobalSynced.prototype = Object.create(WrapperObject.prototype);
CGlobalSynced.prototype.constructor = CGlobalSynced;
CGlobalSynced.prototype.__class__ = CGlobalSynced;
CGlobalSynced.__cache__ = {};
Module['CGlobalSynced'] = CGlobalSynced;

CGlobalSynced.prototype['ResetState'] = CGlobalSynced.prototype.ResetState = function() {
  var self = this.ptr;
  _emscripten_bind_CGlobalSynced_ResetState_0(self);
};;

CGlobalSynced.prototype['GetLuaSimFrame'] = CGlobalSynced.prototype.GetLuaSimFrame = function() {
  var self = this.ptr;
  return _emscripten_bind_CGlobalSynced_GetLuaSimFrame_0(self);
};;

CGlobalSynced.prototype['GetTempNum'] = CGlobalSynced.prototype.GetTempNum = function() {
  var self = this.ptr;
  return _emscripten_bind_CGlobalSynced_GetTempNum_0(self);
};;

CGlobalSynced.prototype['PreSimFrame'] = CGlobalSynced.prototype.PreSimFrame = function() {
  var self = this.ptr;
  return !!(_emscripten_bind_CGlobalSynced_PreSimFrame_0(self));
};;

  CGlobalSynced.prototype['__destroy__'] = CGlobalSynced.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CGlobalSynced___destroy___0(self);
};
// CExplosionGeneratorHandler
function CExplosionGeneratorHandler() { throw "cannot construct a CExplosionGeneratorHandler, no constructor in IDL" }
CExplosionGeneratorHandler.prototype = Object.create(WrapperObject.prototype);
CExplosionGeneratorHandler.prototype.constructor = CExplosionGeneratorHandler;
CExplosionGeneratorHandler.prototype.__class__ = CExplosionGeneratorHandler;
CExplosionGeneratorHandler.__cache__ = {};
Module['CExplosionGeneratorHandler'] = CExplosionGeneratorHandler;

CExplosionGeneratorHandler.prototype['ParseExplosionTables'] = CExplosionGeneratorHandler.prototype.ParseExplosionTables = function() {
  var self = this.ptr;
  _emscripten_bind_CExplosionGeneratorHandler_ParseExplosionTables_0(self);
};;

  CExplosionGeneratorHandler.prototype['__destroy__'] = CExplosionGeneratorHandler.prototype.__destroy__ = function() {
  var self = this.ptr;
  _emscripten_bind_CExplosionGeneratorHandler___destroy___0(self);
};
(function() {
  function setupEnums() {
    
  }
  if (Module['calledRun']) setupEnums();
  else addOnPreMain(setupEnums);
})();

