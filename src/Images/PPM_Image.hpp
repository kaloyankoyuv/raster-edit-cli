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
  std::vector<Pixel> old_matrix;

  void read(const std::string &);
  void write(const std::string &) const;

public:
  PPM_Image(const std::string &);
  bool operator==(const PPM_Image &) const;
  Image *clone() const;

  void grayscale();
  void monochrome();
  void negative();
  void rotate(const std::string &);
  void collage(const std::string &, const std::string &);
  void scale(int);
  void undo();
};
