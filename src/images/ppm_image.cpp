#include "ppm_image.h"
#include "../matrix_algorithms/matrix_algorithms.h"
#include <filesystem>
#include <fstream>
#include <iostream>

PPMImage::PPMImage(const std::string &_file_name) {
  this->read(_file_name);
  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;
}

bool PPMImage::operator==(const PPMImage &other) const {

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

Image *PPMImage::clone() const { return new PPMImage(*this); }

void PPMImage::read(const std::string &_file_name) {

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

void PPMImage::write(const std::string &outimage_name) const {
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

void PPMImage::grayscale() {

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

void PPMImage::monochrome() {

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

void PPMImage::negative() {

  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  for (int i = 0; i < this->width * this->height; i++) {
    this->matrix[i].r = this->max_value - this->matrix[i].r;
    this->matrix[i].g = this->max_value - this->matrix[i].g;
    this->matrix[i].b = this->max_value - this->matrix[i].b;
  }
}

void PPMImage::rotate(const std::string &direction) {

  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  rotate_matrix(this->matrix, this->width, this->height, direction);
}

void PPMImage::collage(const std::string &direction,
                       const std::string &img_path) {

  if (!std::filesystem::exists(img_path)) {
    std::cout << "File: " << img_path << " does not exists!\n";
    return;
  }

  if (this->extract_extension(img_path) != "ppm") {
    std::cout << img_path << " is not a PPM image!\n";
  }

  PPMImage other(img_path);

  if (direction == "vertical") {
    cat_v_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);

  } else if (direction == "horizontal") {
    cat_h_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);
  }
}

void PPMImage::scale(int factor) {
  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  scale_matrix(this->matrix, this->width, this->height, factor);
}

void PPMImage::undo() {
  this->matrix = this->old_matrix;
  this->width = this->old_width;
  this->height = this->old_height;
}
