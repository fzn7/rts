for f in $(find . -name '*.h');
	do {
		filepath=${f%.*}
		file=${f##*/}
		filename=${file%.*}
		echo $filename
		rm ${filepath:2}.cpp
		ruby impl_me.rb $f | sed "s|ImplClass|C${filename}|" > ${filepath:2}_mock.cpp;
	};
done
