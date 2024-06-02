#include "pgm_image.h"
#include "../matrix_algorithms/matrix_algorithms.h"
#include <filesystem>
#include <fstream>
#include <iostream>

PGMImage::PGMImage(const std::string &_file_name) {
  this->read(_file_name);
  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;
}

bool PGMImage::operator==(const PGMImage &other) const {
  return this->type == other.type && this->max_value == other.max_value &&
         this->width == other.width && this->height == other.height &&
         this->matrix == other.matrix;
}

Image *PGMImage::clone() const { return new PGMImage(*this); }

void PGMImage::read(const std::string &_file_name) {

  std::ifstream image(_file_name);

  this->file_name = _file_name;
  image >> this->type;
  this->skip_comments(image);
  image >> this->width >> this->height;
  this->skip_comments(image);
  image >> this->max_value;

  int x;
  if (this->type == "P2") {
    for (int i = 0; i < this->width * this->height; i++) {
      this->skip_comments(image);
      image >> x;
      this->matrix.push_back(x);
    }
  } else if (this->type == "P5") {
    image.ignore(1);
    unsigned char c;
    for (int i = 0; i < this->width * this->height; i++) {
      image.read(reinterpret_cast<char *>(&c), 1);
      x = static_cast<int>(c);
      this->matrix.push_back(x);
    }
  }
  image.close();
}

void PGMImage::write(const std::string &outimage_name) const {
  std::ofstream out(outimage_name);
  out << this->type << "\n"
      << this->width << " " << this->height << "\n"
      << this->max_value << "\n";
  if (this->type == "P2") {
    int k = 1;
    for (int i = 0; i < this->width * this->height; i++) {
      if (k % 15 == 0) {
        out << "\n";
        k = 1;
      }
      out << this->matrix[i] << " ";
      k++;
    }
  } else if (this->type == "P5") {
    for (int i = 0; i < this->width * this->height; i++) {
      out.put(static_cast<unsigned char>(this->matrix[i]));
    }
  }
  out.close();
}

void PGMImage::grayscale() {
  std::cout << "Grayscale operation not supported for PGM images!\n";
}

void PGMImage::monochrome() {

  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  int x = this->max_value / 2;
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    if (matrix[i] > x) {
      this->matrix[i] = this->max_value;
    } else {
      this->matrix[i] = 0;
    }
  }
}

void PGMImage::negative() {
  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  for (int i = 0; i < this->width * this->height; i++) {
    this->matrix[i] = this->max_value - this->matrix[i];
  }
}

void PGMImage::rotate(const std::string &direction) {
  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  rotate_matrix(this->matrix, this->width, this->height, direction);
}

void PGMImage::collage(const std::string &direction,
                       const std::string &img_path) {

  if (!std::filesystem::exists(img_path)) {
    std::cout << "File: " << img_path << " does not exists!\n";
    return;
  }

  if (this->extract_extension(img_path) != "pgm") {
    std::cout << img_path << "is not a PGM image!\n";
    return;
  }

  PGMImage other(img_path);

  if (direction == "vertical") {
    cat_v_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);

  } else if (direction == "horizontal") {
    cat_h_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);
  }
}

void PGMImage::scale(int factor) {

  this->old_matrix = this->matrix;
  this->old_width = this->width;
  this->old_height = this->height;

  scale_matrix(this->matrix, this->width, this->height, factor);
}

void PGMImage::undo() {
  this->matrix = this->old_matrix;
  this->width = this->old_width;
  this->height = this->old_height;
}