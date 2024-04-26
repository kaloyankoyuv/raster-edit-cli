#pragma once
#include "Image.hpp"

class PPM_Image : public Image {
private:
  int max_value;

public:
  PPM_Image(const std::string &);

  bool grayscale();
  bool monochrome();
  bool negative();

  void out(std::ostream &) const;
};
