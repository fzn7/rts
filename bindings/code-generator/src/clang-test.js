var libclang = require('libclang');

console.log(libclang);

var index = new libclang.Index();
var tu = new libclang.TranslationUnit();


console.log(tu);
console.log("----");

console.log(tu.fromSource);

tu.fromSource(index, 'myLibrary.h', ['-I/path/to/my/project']);

tu.cursor().visitChildren(function (parent) {
  switch (this.kind) {
    case libclang.KINDS.CXCursor_FunctionDecl:
      console.log(this.spelling);
      break;
  }
  return libclang.CXChildVisit_Continue;
});

index.dispose();
tu.dispose();
