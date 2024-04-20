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
  int &operator[](int);

  std::string get_file_name();
  std::string get_type();
  std::vector<int> get_vec();
  int get_height();
  int get_width();
  int get_size();
};
