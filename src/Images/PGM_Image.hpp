#pragma once
#include "Image.hpp"
#include <vector>

class PGM_Image : public Image {
private:
  int max_value;
  std::vector<int> matrix;

  void read(const std::string &);
  void write(const std::string &) const;

public:
  PGM_Image(const std::string &);

  void grayscale();
  void monochrome();
  void negative();
  void rotate(const std::string &);
  void collage(const std::string &, const std::string &);
  void scale(int);
};
