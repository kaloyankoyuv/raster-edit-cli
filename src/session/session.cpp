#include "session.h"
#include "../images/image.h"
#include <iostream>

Session::Session(int _id) { this->id = _id; }

Session::Session(const Session &other) {
  this->operations = other.operations;
  for (Image *img : other.images) {
    this->images.push_back(img->clone());
  }
  this->id = other.id;
}

Session::~Session() {
  for (Image *img : this->images) {
    delete img;
  }
}

Session &Session::operator=(const Session &other) {
  if (this != &other) {
    for (Image *img : this->images) {
      delete img;
    }
    this->operations = other.operations;
    for (Image *img : other.images) {
      this->images.push_back(img->clone());
    }
    this->id = other.id;
  }
  return *this;
}

int Session::get_id() { return this->id; }

std::vector<std::string> Session::get_operations() { return this->operations; }

std::vector<Image *> Session::get_images() { return this->images; }

bool Session::add_image(const std::string &img_path) {

  Image *img = Image::image_factory(img_path);

  if (img != nullptr) {
    for (Image *image : this->images) {
      if (img->get_file_name() == image->get_file_name()) {
        std::cout << "Image already added to session!\n";
        return false;
      }
    }
    this->images.push_back(img);
    std::cout << "Added image: " << img_path << "\n";
    return true;
  } else {
    std::cout << "Not a valid image!\n";
    return false;
  }
}

void Session::remove_image(const std::string &img_path) {

  if (this->images[0]->get_file_name() == img_path) {
    std::cout << "Can not remove first loaded image!\n";
    return;
  }

  for (auto it = this->images.begin(); it != this->images.end(); ++it) {
    if ((*it)->get_file_name() == img_path) {
      this->images.erase(it);
      std::cout << "Removed image: " << img_path << " from current session\n";
      return;
    }
  }
  std::cout << "No image named: " << img_path << " in current session\n";
}

void Session::add_operation(const std::string &operation) {

  if (operation == "rotate left" || operation == "rotate right" ||
      operation == "grayscale" || operation == "monochrome" ||
      operation == "negative") {

    this->operations.push_back(operation);
    std::cout << "Added operation: " << operation << "\n";

  } else {
    std::cout << "Not a valid operation!\n";
  }
}

void Session::info() const {
  std::cout << "Session id: " << this->id << "\n";
  std::cout << "Images: ";
  for (Image *img : this->images) {
    std::cout << img->get_file_name() << " ";
  }
  std::cout << "\n";
  std::cout << "Pending operations: ";
  for (std::string s : this->operations) {
    std::cout << s << " ";
  }
  std::cout << "\n";
}

void Session::undo() {

  if (this->images.size() == 0) {
    std::cout << "No images in session!\n";
    return;
  }
  if (this->operations.size() == 0) {
    std::cout << "No pending operations, doing hard undo!\n";
    for (Image *img : this->images) {
      img->undo();
    }
    return;
  }
  this->operations.pop_back();
  std::cout << "Undid last operation!\n";
}

void Session::apply() {
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
  std::cout << "Applied pending operations!\n";
}

void Session::save() {
  for (Image *img : this->images) {
    img->save();
  }
  std::cout << "Saved images in current session!\n";
}

void Session::saveas(const std::string &img_path) {
  std::cout << "Saved image: " << this->images[0]->get_file_name()
            << " as: " << img_path << "\n";
  this->images[0]->save_as(img_path);
  Image *img = Image::image_factory(img_path);
  if (img != nullptr) {
    this->images.push_back(img);
  }
}

void Session::collage(const std::string &direction,
                      const std::string &img1_path,
                      const std::string &img2_path,
                      const std::string &outimage_path) {

  if (Image::extract_extension(img1_path) !=
      Image::extract_extension(img2_path)) {
    std::cout << "Cannot make collage from different image types!\n";
    return;
  }

  if (direction != "horizontal" && direction != "vertical") {
    std::cout << "Not a valid collage direction!\n";
    return;
  }

  Image *img1 = Image::image_factory(img1_path);
  if (img1 != nullptr) {
    img1->collage(direction, img2_path);
    img1->save_as(outimage_path);
    img1->rename(outimage_path);
    this->images.push_back(img1);
    std::cout << "Made collage from images: " << img1_path << " and "
              << img2_path << "\n";
  } else {
    std::cout << "Not a valid image!\n";
  }
}

void Session::scale(int factor, const std::string &img_path,
                    const std::string &outimage_path) {
  Image *img = Image::image_factory(img_path);
  if (img != nullptr) {
    img->scale(factor);
    img->save_as(outimage_path);
    this->images.push_back(img);
    std::cout << "Scaled image: " << img_path << " by factor of: " << factor
              << "\n";
  } else {
    std::cout << "Not a valid image!\n";
  }
}
