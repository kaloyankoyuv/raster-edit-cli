#pragma once
#include "image.h"
#include <vector>

class PBMImage : public Image {
private:
  std::vector<bool> matrix;
  std::vector<bool> old_matrix;

  void read(const std::string &);
  void write(const std::string &) const;

public:
  PBMImage(const std::string &);
  bool operator==(const PBMImage &) const;
  Image *clone() const;

  void grayscale();
  void monochrome();
  void negative();
  void rotate(const std::string &);
  void collage(const std::string &, const std::string &);
  void scale(int);
  void undo();
};
