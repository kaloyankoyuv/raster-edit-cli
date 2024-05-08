#pragma once
#include <string>
#include <vector>

struct Pixel {
  int r, g, b;
};

class Image {
protected:
  std::string file_name;
  std::string type;
  int width;
  int height;
  std::vector<Pixel> matrix;

public:
  virtual ~Image() = default;

  std::string get_file_name() const;
  std::string get_type() const;
  int get_width() const;
  int get_height() const;

  bool save() const;
  bool save_as(const std::string &) const;

  virtual bool grayscale() = 0;
  virtual bool monochrome() = 0;
  virtual bool negative() = 0;
  bool rotate(const std::string &);
  bool collage(const std::string &, const Image &);

  virtual void out(std::ostream &) const = 0;
};
