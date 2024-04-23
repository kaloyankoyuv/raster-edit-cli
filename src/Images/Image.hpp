#pragma once
#include <string>

class Image {
protected:
  std::string file_name;
  std::string type;
  int width;
  int height;

public:
  std::string get_file_name() const;
  std::string get_type() const;
  int get_width() const;
  int get_height() const;

  virtual bool save() const = 0;
  virtual bool save_as(const std::string &) const = 0;
  virtual bool undo() = 0;

  virtual bool grayscale() = 0;
  virtual bool monochrome() = 0;
  virtual bool negative() = 0;
  virtual bool rotate(const std::string &) = 0;
};
