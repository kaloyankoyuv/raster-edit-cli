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
  int k = 0;
  for (int i = 0; i < size; i++) {
    if (k % 15 == 0) {
      out << "\n";
    }
    out << this->matrix[i].r << " ";
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
    if (matrix[i].r > x) {
      matrix[i].r = 1;
      matrix[i].g = 1;
      matrix[i].b = 1;
    } else {
      matrix[i].r = 0;
      matrix[i].g = 0;
      matrix[i].b = 0;
    }
  }

  this->max_value = 1;
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
