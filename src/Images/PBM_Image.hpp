#pragma once
#include "Image.hpp"
#include <vector>

class PBM_Image : public Image {
private:
  std::vector<bool> matrix;
  std::vector<bool> old_matrix;

  void read(const std::string &);
  void write(const std::string &) const;

public:
  PBM_Image(const std::string &);
  bool operator==(const PBM_Image &) const;
  Image *clone() const;

  void grayscale();
  void monochrome();
  void negative();
  void rotate(const std::string &);
  void collage(const std::string &, const std::string &);
  void scale(int);
  void undo();
};
