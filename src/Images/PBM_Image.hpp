#pragma once
#include "Image.hpp"
#include <vector>

class PBM_Image : public Image {
private:
  std::vector<bool> matrix;

public:
  PBM_Image(const std::string &);

  bool save() const;
  bool save_as(const std::string &) const;

  bool negative();
  bool rotate(const std::string &);

  friend std::ostream &operator<<(std::ostream &, const PBM_Image &);
};

std::ostream &operator<<(std::ostream &, const PBM_Image &);
