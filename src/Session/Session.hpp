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
  Session(const std::string &, int);
  ~Session();

  int get_id();

  bool add_image(const std::string &);
  bool add_operation(const std::string &);
  bool info() const;
  bool undo();
  bool apply();
  bool save();
  bool saveas(const std::string &);
  bool collage(const std::string &, const std::string &, const std::string &,
               const std::string &);
  bool scale(int, const std::string &, const std::string &);
};
