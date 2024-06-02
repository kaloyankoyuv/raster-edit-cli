raster-edit-cli: src/*.cpp src/images/*.cpp src/session/*.cpp
	@mkdir -p build
	@g++ 	src/*.cpp \
		src/images/*.cpp \
		src/session/*.cpp \
		-o build/raster-edit-cli

clean:
	@rm -rf build
