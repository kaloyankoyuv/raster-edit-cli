#include "PGM_Image.hpp"
#include <fstream>
#include <iostream>

PGM_Image::PGM_Image(const std::string &_file_name) {

  std::ifstream image(_file_name);

  this->file_name = _file_name;
  image >> this->type >> this->width >> this->height >> this->max_value;

  int size = this->width * this->height;
  int x;
  Pixel p;
  for (int i = 0; i < size; i++) {
    image >> x;
    p.r = x;
    p.g = x;
    p.b = x;
    this->matrix.push_back(p);
  }
  image.close();
}

void PGM_Image::out(std::ostream &out) const {
  out << this->type << "\n"
      << this->width << " " << this->height << "\n"
      << this->max_value << "\n";
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    if (((i + 1) % 70) == 0) {
      out << this->matrix[i].r << "\n";
    } else {
      out << this->matrix[i].r << " ";
    }
  }
}

bool PGM_Image::grayscale() {
  std::cout << "Grayscale operation not supported" << std::endl;
  return true;
}

bool PGM_Image::monochrome() {
  std::cout << "Monochrome operation not supported" << std::endl;
  return true;
}

bool PGM_Image::negative() {
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    this->matrix[i].r = this->max_value - this->matrix[i].r;
    this->matrix[i].g = this->max_value - this->matrix[i].g;
    this->matrix[i].b = this->max_value - this->matrix[i].b;
  }
  return true;
}
