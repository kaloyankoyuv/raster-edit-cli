#include "Image.hpp"
#include <iostream>

int main() {

  Image image(
      "/home/kkoyuv/Documents/projects/raster-edit-cli/demo-images/test.pbm");
  image.save_as("testttt");

  return 0;
}
