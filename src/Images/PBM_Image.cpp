#include "PBM_Image.hpp"
#include "../MatrixAlgorithms/matrix_algorithms.hpp"
#include <bitset>
#include <fstream>
#include <iostream>

PBM_Image::PBM_Image(const std::string &_file_name) { this->read(_file_name); }

void PBM_Image::read(const std::string &_file_name) {
  if (Image::extract_extension(_file_name) != "pbm") {
    std::cout << _file_name << " is not a PBM image!" << std::endl;
    return;
  }
  std::ifstream image(_file_name);

  this->file_name = _file_name;
  image >> this->type;
  this->skip_comments(image);
  image >> this->width >> this->height;

  if (this->type == "P1") {
    char x;
    for (int i = 0; i < this->width * this->height; i++) {
      this->skip_comments(image);
      image >> x;
      this->matrix.push_back(x - '0');
    }
  } else if (this->type == "P4") {
    image.ignore(1);
    unsigned char c;
    for (int i = 0; i < this->width * this->height / 8; i++) {
      image.read(reinterpret_cast<char *>(&c), 1);
      int value = static_cast<int>(c);

      std::bitset<8> bits(value);

      for (int i = 7; i >= 0; --i) {
        this->matrix.push_back(static_cast<bool>(bits[i]));
      }
    }
  }
  image.close();
}

void PBM_Image::write(const std::string &outfile_name) const {
  std::ofstream out(outfile_name);
  out << this->type << "\n" << this->width << " " << this->height << '\n';
  if (this->type == "P1") {
    int k = 1;
    for (int i = 0; i < this->width * this->height; i++) {
      if (k % 70 == 0) {
        out << "\n";
        k = 1;
      }
      out << this->matrix[i];
      k++;
    }
  } else if (this->type == "P4") {
    for (int i = 0; i < this->height; i++) {
      for (int j = 0; j < this->width; j += 8) {
        unsigned char value = 0;
        for (int k = 0; k < 8; k++) {
          if (j + k < this->width) {
            value |= (this->matrix[i * this->width + j + k] << (7 - k));
          }
        }
        out.put(static_cast<unsigned char>(value));
      }
    }
  }
  out.close();
}

void PBM_Image::grayscale() {
  std::cout << "Grayscale operation not supported for PBM images" << std::endl;
}

void PBM_Image::monochrome() {
  std::cout << "Monochrome operation not supported for PBM images" << std::endl;
}

void PBM_Image::negative() {
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    this->matrix[i] = 1 - this->matrix[i];
  }
}

void PBM_Image::rotate(const std::string &direction) {
  rotate_matrix(this->matrix, this->width, this->height, direction);
}

void PBM_Image::collage(const std::string &direction,
                        const std::string &img_path) {

  PBM_Image other(img_path);
  if (direction == "vertical") {
    cat_v_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);

  } else if (direction == "horizontal") {
    cat_h_matrix(this->matrix, this->width, this->height, other.matrix,
                 other.width, other.height);
  }
}

void PBM_Image::scale(int factor) {
  scale_matrix(this->matrix, this->width, this->height, factor);
}
