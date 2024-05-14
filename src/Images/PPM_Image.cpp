#include "PPM_Image.hpp"
#include <fstream>
#include <iostream>

PPM_Image::PPM_Image(const std::string &_file_name) {

  std::ifstream image(_file_name);

  this->file_name = _file_name;
  image >> this->type >> this->width >> this->height >> this->max_value;

  int size = this->width * this->height;
  int x, y, z;
  Pixel p;
  for (int i = 0; i < size; i++) {
    image >> x;
    image >> y;
    image >> z;
    p.r = x;
    p.g = y;
    p.b = z;
    this->matrix.push_back(p);
  }
  image.close();
}

void PPM_Image::out(std::ostream &out) const {
  out << this->type << "\n"
      << this->width << " " << this->height << "\n"
      << this->max_value << "\n";
  int size = this->width * this->height;
  int k = 1;
  for (int i = 0; i < size; i++) {
    if (k % 5 == 0) {
      out << "\n";
      k = 0;
    }
    out << this->matrix[i].r << " " << this->matrix[i].g << " "
        << this->matrix[i].b << " ";
    k++;
  }
}

bool PPM_Image::grayscale() {
  int size = this->width * this->height;
  int x;
  for (int i = 0; i < size; i++) {
    x = (this->matrix[i].r + this->matrix[i].g + this->matrix[i].b) / 3;
    this->matrix[i].r = x;
    this->matrix[i].g = x;
    this->matrix[i].b = x;
  }
  return true;
}

bool PPM_Image::monochrome() {
  int size = this->width * this->height;
  int threshold = this->max_value / 2;
  int x;
  for (int i = 0; i < size; i++) {
    x = (this->matrix[i].r + this->matrix[i].g + this->matrix[i].b) / 3;
    if (x > threshold) {
      this->matrix[i].r = this->max_value;
      this->matrix[i].g = this->max_value;
      this->matrix[i].b = this->max_value;
    } else {
      this->matrix[i].r = 0;
      this->matrix[i].g = 0;
      this->matrix[i].b = 0;
    }
  }
  return true;
}

bool PPM_Image::negative() {
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    this->matrix[i].r = this->max_value - this->matrix[i].r;
    this->matrix[i].g = this->max_value - this->matrix[i].g;
    this->matrix[i].b = this->max_value - this->matrix[i].b;
  }
  return true;
}
