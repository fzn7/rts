basedir=../spring_103.0/rts
outputdir=output

echo "clear outputdir -> ${outputdir}"
rm -rf $outputdir

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
		perl -0777 -pe 's/^{([\s\S])+?^}$/{\n    \/\/stub method\n}/gm' < $f > "${outputpath}_stub.cpp"
#		cat $f | sed "s|^{([\s\S])+?^}$|FOOOBAR|"
#		ruby impl_me.rb $f | sed "s|ImplClass|C${filename}|" > ${filepath:2}_mock.cpp;
	};
done
