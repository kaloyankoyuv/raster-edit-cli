raster-edit-cli: src/main.cpp
	@mkdir -p build
	@g++ src/main.cpp -o build/raster-edit-cli

clean:
	@rm -rf build
