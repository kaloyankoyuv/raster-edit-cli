#pragma once
#include "Image.hpp"
#include <vector>

class PBM_Image : public Image {
private:
  std::vector<bool> matrix;
  std::vector<bool> undo_matrix;
  int undo_width;
  int undo_height;

public:
  PBM_Image(const std::string &);

  bool save() const;
  bool save_as(const std::string &) const;
  bool undo();

  bool grayscale();
  bool monochrome();
  bool negative();
  bool rotate(const std::string &);
  bool collage(const std::string &, const PBM_Image &);

  friend std::ostream &operator<<(std::ostream &, const PBM_Image &);
};

std::ostream &operator<<(std::ostream &, const PBM_Image &);
