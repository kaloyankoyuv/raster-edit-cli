#include "PGM_Image.hpp"
#include "../MatrixAlgorithms/matrix_algorithms.hpp"
#include <fstream>
#include <iostream>

PGM_Image::PGM_Image(const std::string &_file_name) { this->read(_file_name); }

void PGM_Image::read(const std::string &file_name) {
  std::ifstream image(file_name);

  this->file_name = file_name;
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

void PGM_Image::write(const std::string &outimage_name) const {
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

void PGM_Image::grayscale() {
  std::cout << "Grayscale operation not supported" << std::endl;
}

void PGM_Image::monochrome() {

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

void PGM_Image::negative() {
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    this->matrix[i] = this->max_value - this->matrix[i];
  }
}

void PGM_Image::rotate(const std::string &direction) {
  rotate_matrix(this->matrix, this->width, this->height, direction);
}

void PGM_Image::collage(const std::string &direction, const std::string &img) {
  PGM_Image other(img);

  if (direction == "vertical") {
    cat_v_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);

  } else if (direction == "horizontal") {
    cat_h_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);
  }
}

void PGM_Image::scale(int factor) {
  scale_matrix(this->matrix, this->width, this->height, factor);
}
