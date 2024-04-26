#include "Images/PBM_Image.hpp"
#include "Images/PGM_Image.hpp"
#include "Images/PPM_Image.hpp"
#include "Session/Session.hpp"
#include <iostream>

int main() {

  PBM_Image image("/home/kkoyuv/Documents/projects/raster-edit-cli/demo-images/"
                  "test3.pbm");
  PBM_Image image2("/home/kkoyuv/Documents/projects/raster-edit-cli/"
                   "demo-images/test3.pbm");

  PGM_Image image3("/home/kkoyuv/Downloads/apollonian_gasket.ascii.pgm");
  PPM_Image image4("/home/kkoyuv/Downloads/test.ppm");

  image4.collage("horizontal", image4);
  image4.save();

  return 0;
}
