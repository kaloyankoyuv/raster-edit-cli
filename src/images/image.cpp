#include "image.h"
#include "pbm_image.h"
#include "pgm_image.h"
#include "ppm_image.h"
#include <algorithm>
#include <filesystem>
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
}

void Image::rename(const std::string &new_file_name) {
  this->file_name = new_file_name;
}

Image *Image::image_factory(const std::string &img_path) {

  if (!std::filesystem::exists(img_path)) {
    std::cout << "File does not exist!\n";
    return nullptr;
  }

  std::string extension = Image::extract_extension(img_path);

  if (extension == "pbm") {
    return new PBMImage(img_path);
  } else if (extension == "pgm") {
    return new PGMImage(img_path);
  } else if (extension == "ppm") {
    return new PPMImage(img_path);
  } else {
    std::cout << "Can't create image, not a supported image format\n";
    return nullptr;
  }
}

void Image::skip_comments(std::ifstream &image) {
  std::string line;
  while (image >> std::ws && image.peek() == '#') {
    std::getline(image, line);
  }
}

std::string Image::extract_extension(const std::string &img_path) {
  std::string extension;
  int i = img_path.length() - 1;
  while (img_path[i] != '.') {
    extension.push_back(img_path[i]);
    i--;
    if (i < 0) {
      return "";
    }
  }
  reverse(extension.begin(), extension.end());
  return extension;
}
