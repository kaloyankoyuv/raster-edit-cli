#include "Session.hpp"
#include <iostream>

Session::Session(Image &img, int _id) {
  this->images.push_back(&img);
  this->id = _id;
}

int Session::get_id() { return this->id; }

bool Session::add_image(Image &img) {
  this->images.push_back(&img);
  return true;
}

bool Session::add_operation(const std::string &operation) {
  this->operations.push_back(operation);
  return true;
}

bool Session::info() const {
  std::cout << "Session id: " << this->id << std::endl;
  std::cout << "Images: ";
  for (Image *img : this->images) {
    std::cout << img->get_file_name() << " ";
  }
  std::cout << std::endl;
  std::cout << "Pending operations: ";
  for (std::string s : this->operations) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  return true;
}

bool Session::undo() {
  if (this->operations.size() == 0) {
    return false;
  }
  this->operations.pop_back();
  return true;
}
