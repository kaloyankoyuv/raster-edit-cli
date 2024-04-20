#include "Image.hpp"
#include <fstream>

Image::Image(const std::string &_file_name) {

  this->file_name = _file_name;
  std::ifstream image;
  image.open(_file_name);
  image >> this->type;
  image >> this->width;
  image >> this->height;
  this->size = width * height;
  int x;
  for (int i = 0; i < this->size; i++) {
    image >> x;
    vec.push_back(x);
  }
  image.close();
}

Image::Image(const Image &other)
    : file_name(other.file_name), type(other.type), height(other.height),
      width(other.width), vec(other.vec), size(other.size) {}

Image &Image::operator=(const Image &other) {
  if (this != &other) {
    this->file_name = other.file_name;
    this->type = other.type;
    this->height = other.height;
    this->width = other.width;
    this->vec = other.vec;
    this->size = other.size;
  }
  return *this;
}

int &Image::operator[](const int &i) { return this->vec[i]; }

std::ostream &operator<<(std::ostream &out, const Image &img) {
  out << img.get_type() << "\n"
      << img.get_width() << " " << img.get_height() << "\n";

  out << img.get_vec()[0] << " ";
  for (int i = 1; i < img.get_size(); i++) {
    if (i % img.get_width() == img.get_width() - 1) {
      out << img.get_vec()[i] << "\n";
    } else {
      out << img.get_vec()[i] << " ";
    }
  }

  return out;
}

std::string Image::get_file_name() const { return this->file_name; }

std::string Image::get_type() const { return this->type; }

std::vector<int> Image::get_vec() const { return this->vec; }

int Image::get_width() const { return this->width; }

int Image::get_height() const { return this->height; }

int Image::get_size() const { return this->size; }

bool Image::save() {

  std::ofstream out_image(this->file_name);
  out_image << *this;

  return true;
}

bool Image::save_as(const std::string &new_file_name) {

  std::ofstream out_image(new_file_name);
  out_image << *this;

  return true;
}
