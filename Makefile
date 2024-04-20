raster-edit-cli: src/main.cpp src/Image.cpp
	@mkdir -p build
	@g++ src/main.cpp src/Image.cpp -o build/raster-edit-cli

clean:
	@rm -rf build
