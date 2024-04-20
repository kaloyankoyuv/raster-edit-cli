#pragma once
#include <string>
#include <vector>

class Image {
private:
  std::string file_name;
  std::string type;
  std::vector<int> vec;
  int height;
  int width;
  int size;

public:
  Image(const std::string &);
  Image(const Image &);

  Image &operator=(const Image &);
  int &operator[](const int &);

  std::string get_file_name() const;
  std::string get_type() const;
  std::vector<int> get_vec() const;
  int get_height() const;
  int get_width() const;
  int get_size() const;

  bool save();
  bool save_as(const std::string &);
};

std::ostream &operator<<(std::ostream &, const Image &);
