#include "Images/PBM_Image.hpp"
#include "Session/Session.hpp"
#include <iostream>

int main() {

  PBM_Image image("/home/kkoyuv/Documents/projects/raster-edit-cli/demo-images/"
                  "test.pbm");
  PBM_Image image2("/home/kkoyuv/Documents/projects/raster-edit-cli/"
                   "demo-images/test2.pbm");

  Session s(&image, 1);
  s.add_image(&image2);
  s.add_operation("rotate left");
  s.info();
  s.apply();
  s.save();

  return 0;
}
