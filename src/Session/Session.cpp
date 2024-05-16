#include "Session.hpp"
#include <iostream>

Session::Session(const std::string &img_path, int _id) {
  this->add_image(img_path);
  this->id = _id;
}

Session::~Session() {
  for (Image *img : this->images) {
    delete img;
  }
}

int Session::get_id() { return this->id; }

bool Session::add_image(const std::string &img_path) {

  Image *img = Image::imageFactory(img_path);
  this->images.push_back(img);
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

bool Session::apply() {
  for (std::string s : this->operations) {
    if (s == "rotate left") {
      for (Image *img : this->images) {
        img->rotate("left");
      }
    } else if (s == "rotate right") {
      for (Image *img : this->images) {
        img->rotate("right");
      }
    } else if (s == "grayscale") {
      for (Image *img : this->images) {
        img->grayscale();
      }
    } else if (s == "negative") {
      for (Image *img : this->images) {
        img->negative();
      }
    } else if (s == "monochrome") {
      for (Image *img : this->images) {
        img->monochrome();
      }
    }
  }
  this->operations.clear();
  return true;
}

bool Session::save() {
  for (Image *img : this->images) {
    img->save();
  }
  return true;
}

bool Session::saveas(const std::string &img_path) {

  this->images[0]->save_as(img_path);

  return true;
}

bool Session::collage(const std::string &direction,
                      const std::string &img1_path,
                      const std::string &img2_path,
                      const std::string &outimage_path) {

  Image *img1 = Image::imageFactory(img1_path);
  img1->collage(direction, img2_path);
  img1->save_as(outimage_path);
  this->images.push_back(img1);

  return true;
}

bool Session::scale(int factor, const std::string &img_path,
                    const std::string &outimage_path) {
  Image *img = Image::imageFactory(img_path);
  img->scale(factor);
  img->save_as(outimage_path);
  this->images.push_back(img);

  return true;
}
