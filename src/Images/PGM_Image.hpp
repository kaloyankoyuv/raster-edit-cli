#pragma once
#include "Image.hpp"
#include <vector>

class PGM_Image : public Image {
private:
  int max_value;
  std::vector<int> matrix;

public:
  PGM_Image(const std::string &);

  bool grayscale();
  bool monochrome();
  bool negative();
  bool rotate(const std::string &);
  bool collage(const std::string &, const std::string &);
  bool scale(int);

  void out(std::ostream &) const;
};
