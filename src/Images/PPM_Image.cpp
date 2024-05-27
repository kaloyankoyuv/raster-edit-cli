#include "PPM_Image.hpp"
#include "../MatrixAlgorithms/matrix_algorithms.hpp"
#include <fstream>
#include <iostream>

PPM_Image::PPM_Image(const std::string &_file_name) {
  this->read(_file_name);
  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;
}

bool PPM_Image::operator==(const PPM_Image &other) const {

  if (this->width != other.width || this->height != other.height) {
    return false;
  }

  bool b = true;
  for (int i = 0; i < this->width * this->height; i++) {
    if (this->matrix[i].r != other.matrix[i].r ||
        this->matrix[i].g != other.matrix[i].g ||
        this->matrix[i].b != other.matrix[i].b) {
      b = false;
    }
  }
  return this->type == other.type && this->max_value == other.max_value &&
         this->width == other.width && this->height == other.height && b;
}

Image *PPM_Image::clone() const { return new PPM_Image(*this); }

void PPM_Image::read(const std::string &_file_name) {
  if (this->extract_extension(_file_name) != "ppm") {
    std::cout << _file_name << " is not a PPM image!" << std::endl;
  }
  std::ifstream image(_file_name);

  this->file_name = _file_name;

  image >> this->type;
  this->skip_comments(image);
  image >> this->width >> this->height;
  this->skip_comments(image);
  image >> this->max_value;

  Pixel p;
  if (this->type == "P3") {
    for (int i = 0; i < this->width * this->height; i++) {
      this->skip_comments(image);
      image >> p.r;
      this->skip_comments(image);
      image >> p.g;
      this->skip_comments(image);
      image >> p.b;
      this->matrix.push_back(p);
    }
  } else if (this->type == "P6") {
    image.ignore(1);
    unsigned char c;
    for (int i = 0; i < this->width * this->height; i++) {
      image.read(reinterpret_cast<char *>(&c), 1);
      p.r = static_cast<int>(c);
      image.read(reinterpret_cast<char *>(&c), 1);
      p.g = static_cast<int>(c);
      image.read(reinterpret_cast<char *>(&c), 1);
      p.b = static_cast<int>(c);

      this->matrix.push_back(p);
    }
  }
  image.close();
}

void PPM_Image::write(const std::string &outimage_name) const {
  std::ofstream out(outimage_name);
  out << this->type << "\n"
      << this->width << " " << this->height << "\n"
      << this->max_value << "\n";
  if (this->type == "P3") {

    int k = 1;
    for (int i = 0; i < this->width * this->height; i++) {
      if (k % 5 == 0) {
        out << "\n";
        k = 1;
      }
      out << this->matrix[i].r << " " << this->matrix[i].g << " "
          << this->matrix[i].b << " ";
      k++;
    }

  } else if (this->type == "P6") {

    for (int i = 0; i < this->width * this->height; i++) {
      out.put(static_cast<unsigned char>(this->matrix[i].r));
      out.put(static_cast<unsigned char>(this->matrix[i].g));
      out.put(static_cast<unsigned char>(this->matrix[i].b));
    }
  }
  out.close();
}

void PPM_Image::grayscale() {

  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  int x;
  for (int i = 0; i < this->width * this->height; i++) {
    x = (this->matrix[i].r + this->matrix[i].g + this->matrix[i].b) / 3;
    this->matrix[i].r = x;
    this->matrix[i].g = x;
    this->matrix[i].b = x;
  }
}

void PPM_Image::monochrome() {

  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  int x;
  for (int i = 0; i < this->width * this->height; i++) {
    x = (this->matrix[i].r + this->matrix[i].g + this->matrix[i].b) / 3;
    if (x > this->max_value / 2) {
      this->matrix[i].r = this->max_value;
      this->matrix[i].g = this->max_value;
      this->matrix[i].b = this->max_value;
    } else {
      this->matrix[i].r = 0;
      this->matrix[i].g = 0;
      this->matrix[i].b = 0;
    }
  }
}

void PPM_Image::negative() {

  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  for (int i = 0; i < this->width * this->height; i++) {
    this->matrix[i].r = this->max_value - this->matrix[i].r;
    this->matrix[i].g = this->max_value - this->matrix[i].g;
    this->matrix[i].b = this->max_value - this->matrix[i].b;
  }
}

void PPM_Image::rotate(const std::string &direction) {

  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  rotate_matrix(this->matrix, this->width, this->height, direction);
}

void PPM_Image::collage(const std::string &direction, const std::string &img) {

  PPM_Image other(img);

  if (direction == "vertical") {
    cat_v_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);

  } else if (direction == "horizontal") {
    cat_h_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);
  }
}

void PPM_Image::scale(int factor) {
  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  scale_matrix(this->matrix, this->width, this->height, factor);
}

void PPM_Image::undo() {
  this->matrix = this->old_matrix;
  this->width = this->old_width;
  this->height = this->old_height;
}
