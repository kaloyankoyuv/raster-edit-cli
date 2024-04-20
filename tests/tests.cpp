#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest/doctest.h"

#include "../src/Image.hpp"

Image image("tests-images/test.pbm");

TEST_CASE("Test image file name") {
  CHECK(image.get_file_name() == "tests-images/test.pbm");
}

TEST_CASE("Test image type") { CHECK(image.get_type() == "P1"); }

TEST_CASE("Test image vector") {

  bool b = true;

  int arr[60] = {
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
      1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };

  for (int i = 0; i < 60; i++) {
    if (image[i] != arr[i]) {
      b = false;
      break;
    }
  }

  CHECK(b);
}

TEST_CASE("Test image width") { CHECK(image.get_width() == 6); }

TEST_CASE("Test image height") { CHECK(image.get_height() == 10); }

TEST_CASE("Test image size") { CHECK(image.get_size() == 60); }

int main() {

  doctest::Context().run();

  return 0;
}
