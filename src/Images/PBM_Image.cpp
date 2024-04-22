#include "PBM_Image.hpp"
#include "../MatrixAlgorithms/matrix_algorithms.hpp"
#include <fstream>

PBM_Image::PBM_Image(const std::string &_file_name) : Image(_file_name) {

  std::ifstream image(_file_name);
  std::string s;
  image >> s >> s >> s;
  bool x;
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    image >> x;
    this->matrix.push_back(x);
  }
  image.close();
}

std::ostream &operator<<(std::ostream &out, const PBM_Image &img) {
  out << img.type << "\n" << img.width << " " << img.height << "\n";
  int size = img.width * img.height;
  for (int i = 0; i < size; i++) {
    if (i % img.width == img.width - 1) {
      out << img.matrix[i] << "\n";
    } else {
      out << img.matrix[i] << " ";
    }
  }

  return out;
}

bool PBM_Image::save() const {
  std::ofstream out_image(this->file_name);
  out_image << *this;
  out_image.close();

  return true;
}

bool PBM_Image::save_as(const std::string &new_file_name) const {

  std::ofstream out_image(new_file_name);
  out_image << *this;
  out_image.close();

  return true;
}

bool PBM_Image::negative() {
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    if (this->matrix[i]) {
      this->matrix[i] = false;
    } else {
      this->matrix[i] = true;
    }
  }
  return true;
}

bool PBM_Image::rotate(const std::string &direction) {

  rotate_matrix(this->matrix, this->width, this->height, direction);
  return true;
}
