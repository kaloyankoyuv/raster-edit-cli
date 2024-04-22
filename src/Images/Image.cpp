#include "Image.hpp"
#include <fstream>

Image::Image(const std::string &_file_name) {

  this->file_name = _file_name;
  std::ifstream image(_file_name);
  image >> this->type;
  image >> this->width;
  image >> this->height;
  image.close();
}

std::string Image::get_file_name() const { return this->file_name; }

std::string Image::get_type() const { return this->type; }

int Image::get_width() const { return this->width; }

int Image::get_height() const { return this->height; }
