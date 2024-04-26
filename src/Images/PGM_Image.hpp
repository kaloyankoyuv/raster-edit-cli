#pragma once
#include "Image.hpp"

class PGM_Image : public Image {
private:
  int max_value;

public:
  PGM_Image(const std::string &);

  bool grayscale();
  bool monochrome();
  bool negative();

  void out(std::ostream &) const;
};
