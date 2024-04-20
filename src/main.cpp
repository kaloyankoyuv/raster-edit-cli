#include "Image.hpp"
#include <iostream>

int main() {

  Image image(
      "/home/kkoyuv/Documents/projects/raster-edit-cli/demo-images/test.pbm");
  std::cout << image[4];

  return 0;
}
