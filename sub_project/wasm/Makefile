
foo.js:
	emcc ./src/foo.cpp -o build/foo1.js

foo.html:
	# EXPORTED_FUNCTIONS 导出指定函数
	emcc -s EXPORTED_FUNCTIONS=[_addOne] \
	./src/foo.cpp -o build/foo2.html

clean:
	rm -rf build/*