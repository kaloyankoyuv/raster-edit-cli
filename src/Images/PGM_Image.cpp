#include "PGM_Image.hpp"
#include "../MatrixAlgorithms/matrix_algorithms.hpp"
#include <fstream>
#include <iostream>

PGM_Image::PGM_Image(const std::string &_file_name) {

  std::ifstream image(_file_name);

  this->file_name = _file_name;
  image >> this->type >> this->width >> this->height >> this->max_value;

  int size = this->width * this->height;
  int x;
  for (int i = 0; i < size; i++) {
    image >> x;
    this->matrix.push_back(x);
  }
  image.close();
}

void PGM_Image::out(std::ostream &out) const {
  out << this->type << "\n"
      << this->width << " " << this->height << "\n"
      << this->max_value << "\n";
  int size = this->width * this->height;
  int k = 1;
  for (int i = 0; i < size; i++) {
    if (k % 15 == 0) {
      out << "\n";
      k = 1;
    }
    out << this->matrix[i] << " ";
    k++;
  }
}

bool PGM_Image::grayscale() {
  std::cout << "Grayscale operation not supported" << std::endl;
  return true;
}

bool PGM_Image::monochrome() {

  int x = this->max_value / 2;
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    if (matrix[i] > x) {
      this->matrix[i] = this->max_value;
    } else {
      this->matrix[i] = 0;
    }
  }
  return true;
}

bool PGM_Image::negative() {
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    this->matrix[i] = this->max_value - this->matrix[i];
  }
  return true;
}

bool PGM_Image::rotate(const std::string &direction) {
  rotate_matrix(this->matrix, this->width, this->height, direction);
  return true;
}

bool PGM_Image::collage(const std::string &direction, const std::string &img) {
  PGM_Image other(img);

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
