#pragma once
#include "../images/image.h"
#include <string>
#include <vector>

class Session {
private:
  std::vector<std::string> operations;
  std::vector<Image *> images;
  int id;

public:
  Session(int);
  Session(const Session &);
  ~Session();
  Session &operator=(const Session &);

  int get_id();
  std::vector<std::string> get_operations();
  std::vector<Image *> get_images();

  bool add_image(const std::string &);
  void remove_image(const std::string &);
  void add_operation(const std::string &);
  void info() const;
  void undo();
  void apply();
  void save();
  void saveas(const std::string &);
  void collage(const std::string &, const std::string &, const std::string &,
               const std::string &);
  void scale(int, const std::string &, const std::string &);
};
