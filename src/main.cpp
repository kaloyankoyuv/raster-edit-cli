#include "Images/PBM_Image.hpp"
#include <iostream>

int main() {

  PBM_Image image("/home/kkoyuv/Documents/projects/raster-edit-cli/demo-images/"
                  "test.pbm");
  PBM_Image image2("/home/kkoyuv/Documents/projects/raster-edit-cli/"
                   "demo-images/sample_640×426.pbm");

  std::cout << image;

  return 0;
}
