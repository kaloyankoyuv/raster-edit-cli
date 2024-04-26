#pragma once
#include "Image.hpp"

class PBM_Image : public Image {
public:
  PBM_Image(const std::string &);

  bool grayscale();
  bool monochrome();
  bool negative();

  void out(std::ostream &) const;
};
