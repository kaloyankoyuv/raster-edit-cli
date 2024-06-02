#pragma once
#include "image.h"
#include <vector>

struct Pixel {
  int r, g, b;
};

class PPMImage : public Image {
private:
  int max_value;
  std::vector<Pixel> matrix;
  std::vector<Pixel> old_matrix;

  void read(const std::string &);
  void write(const std::string &) const;

public:
  PPMImage(const std::string &);
  bool operator==(const PPMImage &) const;
  Image *clone() const;

  void grayscale();
  void monochrome();
  void negative();
  void rotate(const std::string &);
  void collage(const std::string &, const std::string &);
  void scale(int);
  void undo();
};
