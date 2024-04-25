#pragma once
#include "../Images/Image.hpp"
#include <string>
#include <vector>

class Session {
private:
  std::vector<std::string> operations;
  std::vector<Image *> images;
  int id;

public:
  Session(Image *, int);

  int get_id();

  bool add_image(Image *);
  bool add_operation(const std::string &);
  bool info() const;
  bool undo();
  bool apply();
  bool save();
};
