#pragma once
#include "image.h"
#include <vector>

class PGMImage : public Image {
private:
  int max_value;
  std::vector<int> matrix;
  std::vector<int> old_matrix;

  void read(const std::string &);
  void write(const std::string &) const;

public:
  PGMImage(const std::string &);
  bool operator==(const PGMImage &) const;
  Image *clone() const;

  void grayscale();
  void monochrome();
  void negative();
  void rotate(const std::string &);
  void collage(const std::string &, const std::string &);
  void scale(int);
  void undo();
};
