#pragma once
#include "Image.hpp"
#include <vector>

class PBM_Image : public Image {
private:
  std::vector<bool> matrix;

public:
  PBM_Image(const std::string &);

  bool grayscale();
  bool monochrome();
  bool negative();
  bool rotate(const std::string &);
  bool collage(const std::string &, const std::string &);
  bool scale(int factor);

  void out(std::ostream &) const;
};
