#include "PBM_Image.hpp"
#include <fstream>
#include <iostream>

PBM_Image::PBM_Image(const std::string &_file_name) {

  std::ifstream image(_file_name);

  this->file_name = _file_name;
  image >> this->type >> this->width >> this->height;

  int size = this->width * this->height;
  char x;
  Pixel p;
  for (int i = 0; i < size; i++) {
    image >> x;
    p.r = x - '0';
    p.g = x - '0';
    p.b = x - '0';
    this->matrix.push_back(p);
  }
  image.close();
}

void PBM_Image::out(std::ostream &out) const {
  out << this->type << "\n" << this->width << " " << this->height;
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    if (i % 70 == 0) {
      out << "\n";
    }
    out << this->matrix[i].r;
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
    if (this->matrix[i].r == 0) {
      this->matrix[i].r = 1;
      this->matrix[i].g = 1;
      this->matrix[i].b = 1;
    } else {
      this->matrix[i].r = 0;
      this->matrix[i].g = 0;
      this->matrix[i].b = 0;
    }
  }
  return true;
}
