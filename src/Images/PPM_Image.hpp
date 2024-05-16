#pragma once
#include "Image.hpp"
#include <vector>

struct Pixel {
  int r, g, b;
};

class PPM_Image : public Image {
private:
  int max_value;
  std::vector<Pixel> matrix;

public:
  PPM_Image(const std::string &);

  bool grayscale();
  bool monochrome();
  bool negative();
  bool rotate(const std::string &);
  bool collage(const std::string &, const std::string &);
  bool scale(int factor);

  void out(std::ostream &) const;
};
