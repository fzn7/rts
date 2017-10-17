basedir=../spring_103.0/rts
outputdir=output/stubs

echo "clear outputdir -> ${outputdir}"
rm -rf $outputdir

#файла прописать #include <iostream>, а внутри метода std::cout << _FUNCTION_ << std::endl;

for f in $(find ${basedir} -name '*.cpp');
	do {
		filepath=${f%.*}
		outputpath=$(echo "$filepath" | sed "s|${basedir}|$outputdir|")
		outdir=$(dirname "$f" | sed "s|${basedir}|$outputdir|")
#		file=${f##*/}
#		filename=${file%.*}
#		echo $outdir
#		echo $f
#		echo $outputpath
		mkdir -p $outdir

		generated="${outputpath}_generated.cpp"
		./clang-format $f -style=file > $generated

		if cat "$generated" | grep 'iostream' >/dev/null ; 
			then echo "skip $generated"; 
			else sed -i '1s;^;#include <iostream>\n;' $generated; 
		fi		

		perl -0777 -pe 's/^{([\s\S])+?^}$/{\n    \/\/stub method\n    std::cout << __FUNCTION__ << std::endl;\n}/gm' < $generated > "${outputpath}_stub.cpp"
#		cat $f | sed "s|^{([\s\S])+?^}$|FOOOBAR|"
#		ruby impl_me.rb $f | sed "s|ImplClass|C${filename}|" > ${filepath:2}_mock.cpp;
	};
done
