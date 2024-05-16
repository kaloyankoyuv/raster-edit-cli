#include "PBM_Image.hpp"
#include "../MatrixAlgorithms/matrix_algorithms.hpp"
#include <fstream>
#include <iostream>

PBM_Image::PBM_Image(const std::string &_file_name) {

  std::ifstream image(_file_name);

  this->file_name = _file_name;
  image >> this->type >> this->width >> this->height;

  int size = this->width * this->height;
  char x;
  for (int i = 0; i < size; i++) {
    image >> x;
    this->matrix.push_back(x - '0');
  }
  image.close();
}

void PBM_Image::out(std::ostream &out) const {
  out << this->type << "\n" << this->width << " " << this->height << '\n';
  int size = this->width * this->height;
  int k = 1;
  for (int i = 0; i < size; i++) {
    if (k % 70 == 0) {
      out << "\n";
      k = 1;
    }
    out << this->matrix[i];
    k++;
  }
}

bool PBM_Image::grayscale() {
  std::cout << "Grayscale operation not supported" << std::endl;
  return true;
}

bool PBM_Image::monochrome() {
  std::cout << "Monochrome operation not supported" << std::endl;
  return true;
}

bool PBM_Image::negative() {
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    this->matrix[i] = 1 - this->matrix[i];
  }
  return true;
}

bool PBM_Image::rotate(const std::string &direction) {
  rotate_matrix(this->matrix, this->width, this->height, direction);
  return true;
}

bool PBM_Image::collage(const std::string &direction,
                        const std::string &img_path) {

  PBM_Image other(img_path);
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

bool PBM_Image::scale(int factor) {

  scale_matrix(this->matrix, this->width, this->height, factor);
  return true;
}
