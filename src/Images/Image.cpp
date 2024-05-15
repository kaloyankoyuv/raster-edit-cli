#include "Image.hpp"
#include "../MatrixAlgorithms/matrix_algorithms.hpp"
#include <fstream>

std::string Image::get_file_name() const { return this->file_name; }

std::string Image::get_type() const { return this->type; }

int Image::get_width() const { return this->width; }

int Image::get_height() const { return this->height; }

bool Image::save() const {

  std::ofstream out_image(this->file_name);
  this->out(out_image);
  out_image.close();

  return true;
}

bool Image::save_as(const std::string &new_file_name) const {

  std::ofstream out_image(new_file_name);
  this->out(out_image);
  out_image.close();

  return true;
}

bool Image::rotate(const std::string &direction) {

  rotate_matrix(this->matrix, this->width, this->height, direction);
  return true;
}

bool Image::collage(const std::string &direction, const Image &other) {

  if (direction == "vertical") {
    cat_v_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);
    return true;
  } else if (direction == "horizontal") {
    cat_h_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);
    return true;
  }
  return false;
}
