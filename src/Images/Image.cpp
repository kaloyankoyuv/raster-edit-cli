#include "Image.hpp"
#include "PBM_Image.hpp"
#include "PGM_Image.hpp"
#include "PPM_Image.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

std::string Image::get_file_name() const { return this->file_name; }

std::string Image::get_type() const { return this->type; }

int Image::get_width() const { return this->width; }

int Image::get_height() const { return this->height; }

void Image::save() const { this->write(this->file_name); }

void Image::save_as(const std::string &new_file_name) {
  this->write(new_file_name);
  this->file_name = new_file_name;
}

Image *Image::imageFactory(const std::string &img_path) {
  std::string extension;
  int i = img_path.length() - 1;
  while (img_path[i] != '.') {
    extension.push_back(img_path[i]);
    i--;
  }
  reverse(extension.begin(), extension.end());

  if (extension == "pbm") {
    return new PBM_Image(img_path);
  } else if (extension == "pgm") {
    return new PGM_Image(img_path);
  } else if (extension == "ppm") {
    return new PPM_Image(img_path);
  } else {
    std::cout << "Invalid image";
  }
  return nullptr;
}

void Image::skip_comments(std::ifstream &image) {
  std::string line;
  while (image >> std::ws && image.peek() == '#') {
    std::getline(image, line);
  }
}
