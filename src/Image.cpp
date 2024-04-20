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

int &Image::operator[](int i) { return this->vec[i]; }

std::string Image::get_file_name() { return this->file_name; }

std::string Image::get_type() { return this->type; }

std::vector<int> Image::get_vec() { return this->vec; }

int Image::get_width() { return this->width; }

int Image::get_height() { return this->height; }

int Image::get_size() { return this->size; }
