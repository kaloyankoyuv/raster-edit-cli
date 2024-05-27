#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest/doctest.h"

#include "../src/Images/PBM_Image.hpp"
#include "../src/Images/PGM_Image.hpp"
#include "../src/Images/PPM_Image.hpp"
#include "../src/Session/Session.hpp"

TEST_CASE("Test PBM plain image file name") {
  PBM_Image testimg("tests-images/sample-plain.pbm");

  CHECK(testimg.get_file_name() == "tests-images/sample-plain.pbm");
}

TEST_CASE("Test PBM plain image type") {
  PBM_Image testimg("tests-images/sample-plain.pbm");

  CHECK(testimg.get_type() == "P1");
}

TEST_CASE("Test PBM plain image width") {
  PBM_Image testimg("tests-images/sample-plain.pbm");

  CHECK(testimg.get_width() == 640);
}

TEST_CASE("Test PBM plain image height") {
  PBM_Image testimg("tests-images/sample-plain.pbm");

  CHECK(testimg.get_height() == 426);
}

TEST_CASE("Test PBM plain image negative") {
  PBM_Image testimg("tests-images/sample-plain.pbm");
  PBM_Image correctimg("tests-images/sample-plain-negative.pbm");
  testimg.negative();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM plain image rotate left") {
  PBM_Image testimg("tests-images/sample-plain.pbm");
  PBM_Image correctimg("tests-images/sample-plain-rotate-left.pbm");
  testimg.rotate("left");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM plain image rotate right") {
  PBM_Image testimg("tests-images/sample-plain.pbm");
  PBM_Image correctimg("tests-images/sample-plain-rotate-right.pbm");
  testimg.rotate("right");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM plain image collage horizontal") {
  PBM_Image testimg("tests-images/sample-plain.pbm");
  PBM_Image correctimg("tests-images/sample-plain-collage-horizontal.pbm");
  testimg.collage("horizontal", "tests-images/sample-plain.pbm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM plain image collage vertical") {
  PBM_Image testimg("tests-images/sample-plain.pbm");
  PBM_Image correctimg("tests-images/sample-plain-collage-vertical.pbm");
  testimg.collage("vertical", "tests-images/sample-plain.pbm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM plain image scale") {
  PBM_Image testimg("tests-images/sample-plain.pbm");
  PBM_Image correctimg("tests-images/sample-plain-scale.pbm");
  testimg.scale(2);

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image file name") {
  PBM_Image testimg("tests-images/sample-binary.pbm");

  CHECK(testimg.get_file_name() == "tests-images/sample-binary.pbm");
}

TEST_CASE("Test PBM binary image type") {
  PBM_Image testimg("tests-images/sample-binary.pbm");

  CHECK(testimg.get_type() == "P4");
}

TEST_CASE("Test PBM binary image width") {
  PBM_Image testimg("tests-images/sample-binary.pbm");

  CHECK(testimg.get_width() == 640);
}

TEST_CASE("Test PBM binary image height") {
  PBM_Image testimg("tests-images/sample-binary.pbm");

  CHECK(testimg.get_height() == 426);
}

TEST_CASE("Test PBM binary image negative") {
  PBM_Image testimg("tests-images/sample-binary.pbm");
  PBM_Image correctimg("tests-images/sample-binary-negative.pbm");
  testimg.negative();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image rotate left") {
  PBM_Image testimg("tests-images/sample-binary.pbm");
  PBM_Image correctimg("tests-images/sample-binary-rotate-left.pbm");
  testimg.rotate("left");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image rotate right") {
  PBM_Image testimg("tests-images/sample-binary.pbm");
  PBM_Image correctimg("tests-images/sample-binary-rotate-right.pbm");
  testimg.rotate("right");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image collage horizontal") {
  PBM_Image testimg("tests-images/sample-binary.pbm");
  PBM_Image correctimg("tests-images/sample-binary-collage-horizontal.pbm");
  testimg.collage("horizontal", "tests-images/sample-binary.pbm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image collage vertical") {
  PBM_Image testimg("tests-images/sample-binary.pbm");
  PBM_Image correctimg("tests-images/sample-binary-collage-vertical.pbm");
  testimg.collage("vertical", "tests-images/sample-binary.pbm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image scale") {
  PBM_Image testimg("tests-images/sample-binary.pbm");
  PBM_Image correctimg("tests-images/sample-binary-scale.pbm");
  testimg.scale(2);

  CHECK(testimg == correctimg);
}

int main() {

  doctest::Context().run();

  return 0;
}
