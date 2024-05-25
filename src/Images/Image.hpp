#pragma once
#include <string>

class Image {
protected:
  std::string file_name;
  std::string type;
  int width, old_width;
  int height, old_height;

  virtual void read(const std::string &) = 0;
  virtual void write(const std::string &) const = 0;

  void skip_comments(std::ifstream &);

public:
  virtual ~Image() = default;

  std::string get_file_name() const;
  std::string get_type() const;
  int get_width() const;
  int get_height() const;

  void save() const;
  void save_as(const std::string &);

  virtual void grayscale() = 0;
  virtual void monochrome() = 0;
  virtual void negative() = 0;
  virtual void rotate(const std::string &) = 0;
  virtual void collage(const std::string &, const std::string &) = 0;
  virtual void scale(int) = 0;
  virtual void undo() = 0;

  static Image *imageFactory(const std::string &);
  static std::string extract_extension(const std::string &);
};
