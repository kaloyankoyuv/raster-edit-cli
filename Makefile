raster-edit-cli: src/*.cpp src/Images/*.cpp src/Session/*.cpp
	@mkdir -p build
	@g++ 	src/*.cpp \
		src/Images/*.cpp \
		src/Session/*.cpp \
		-o build/raster-edit-cli

clean:
	@rm -rf build
