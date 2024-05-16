#pragma once
#include <string>

class Image {
protected:
  std::string file_name;
  std::string type;
  int width;
  int height;

public:
  virtual ~Image() = default;

  std::string get_file_name() const;
  std::string get_type() const;
  int get_width() const;
  int get_height() const;

  bool save() const;
  bool save_as(const std::string &);

  virtual bool grayscale() = 0;
  virtual bool monochrome() = 0;
  virtual bool negative() = 0;
  virtual bool rotate(const std::string &) = 0;
  virtual bool collage(const std::string &, const std::string &) = 0;
  virtual bool scale(int) = 0;

  virtual void out(std::ostream &) const = 0;

  static Image *imageFactory(const std::string &);
};
