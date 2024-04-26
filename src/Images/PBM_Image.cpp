#include "PBM_Image.hpp"
#include "../MatrixAlgorithms/matrix_algorithms.hpp"
#include <fstream>

PBM_Image::PBM_Image(const std::string &_file_name) {

  std::ifstream image(_file_name);

  this->file_name = _file_name;
  image >> this->type >> this->width >> this->height;

  int size = this->width * this->height;
  bool x;
  for (int i = 0; i < size; i++) {
    image >> x;
    this->matrix.push_back(x);
  }

  this->undo_matrix = this->matrix;
  this->undo_width = this->width;
  this->undo_height = this->height;
  image.close();
}

void PBM_Image::out(std::ostream &out) const {
  out << this->type << "\n" << this->width << " " << this->height << "\n";
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    if (i % this->width == this->width - 1) {
      out << this->matrix[i] << "\n";
    } else {
      out << this->matrix[i] << " ";
    }
  }
}

bool PBM_Image::save() const {
  std::ofstream out_image(this->file_name);
  this->out(out_image);
  out_image.close();

  return true;
}

bool PBM_Image::save_as(const std::string &new_file_name) const {

  std::ofstream out_image(new_file_name);
  this->out(out_image);
  out_image.close();

  return true;
}

bool PBM_Image::undo() {
  this->matrix = this->undo_matrix;
  this->width = this->undo_width;
  this->height = this->undo_height;
  return true;
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
  this->undo_matrix = this->matrix;
  this->undo_width = this->width;
  this->undo_height = this->height;
  int size = this->width * this->height;
  for (int i = 0; i < size; i++) {
    if (this->matrix[i]) {
      this->matrix[i] = false;
    } else {
      this->matrix[i] = true;
    }
  }
  return true;
}

bool PBM_Image::rotate(const std::string &direction) {

  this->undo_matrix = this->matrix;
  this->undo_width = this->width;
  this->undo_height = this->height;
  rotate_matrix(this->matrix, this->width, this->height, direction);
  return true;
}

bool PBM_Image::collage(const std::string &direction, const PBM_Image &other) {
  this->undo_matrix = this->matrix;
  this->undo_width = this->width;
  this->undo_height = this->height;
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
