#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest/doctest.h"

#include "../src/Images/PBM_Image.hpp"

PBM_Image pbm_image("tests-images/test.pbm");
PBM_Image pbm_image2("tests-images/test2.pbm");

TEST_CASE("Test image file name") {
  CHECK(pbm_image.get_file_name() == "tests-images/test.pbm");
}

TEST_CASE("Test image type") { CHECK(pbm_image.get_type() == "P1"); }

TEST_CASE("Test image vector") {

  bool b = true;

  int arr[60] = {
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
      1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };

  for (int i = 0; i < 60; i++) {
    if (pbm_image.get_ith(i) != arr[i]) {
      b = false;
      break;
    }
  }

  CHECK(b);
}

TEST_CASE("Test image width") { CHECK(pbm_image.get_width() == 6); }

TEST_CASE("Test image height") { CHECK(pbm_image.get_height() == 10); }

int main() {

  doctest::Context().run();

  return 0;
}
