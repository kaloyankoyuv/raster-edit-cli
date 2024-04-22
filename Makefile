raster-edit-cli: src/*.cpp src/Images/*.cpp
	@mkdir -p build
	@g++ 	src/*.cpp \
		src/Images/*.cpp \
		-o build/raster-edit-cli

clean:
	@rm -rf build
