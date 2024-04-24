#include "Image.hpp"

std::string Image::get_file_name() const { return this->file_name; }

std::string Image::get_type() const { return this->type; }

int Image::get_width() const { return this->width; }

int Image::get_height() const { return this->height; }

std::ostream &operator<<(std::ostream &out, const Image *img) {
  img->out(out);
  return out;
}
