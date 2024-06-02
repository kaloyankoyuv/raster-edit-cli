#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest/doctest.h"

#include "../src/images/pbm_image.h"
#include "../src/images/pgm_image.h"
#include "../src/images/ppm_image.h"
#include "../src/session/session.h"

TEST_CASE("Test PBM plain image file name") {
  PBMImage testimg("tests-images/sample-plain.pbm");

  CHECK(testimg.get_file_name() == "tests-images/sample-plain.pbm");
}

TEST_CASE("Test PBM plain image type") {
  PBMImage testimg("tests-images/sample-plain.pbm");

  CHECK(testimg.get_type() == "P1");
}

TEST_CASE("Test PBM plain image width") {
  PBMImage testimg("tests-images/sample-plain.pbm");

  CHECK(testimg.get_width() == 640);
}

TEST_CASE("Test PBM plain image height") {
  PBMImage testimg("tests-images/sample-plain.pbm");

  CHECK(testimg.get_height() == 426);
}

TEST_CASE("Test PBM plain image negative") {
  PBMImage testimg("tests-images/sample-plain.pbm");
  PBMImage correctimg("tests-images/sample-plain-negative.pbm");
  testimg.negative();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM plain image rotate left") {
  PBMImage testimg("tests-images/sample-plain.pbm");
  PBMImage correctimg("tests-images/sample-plain-rotate-left.pbm");
  testimg.rotate("left");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM plain image rotate right") {
  PBMImage testimg("tests-images/sample-plain.pbm");
  PBMImage correctimg("tests-images/sample-plain-rotate-right.pbm");
  testimg.rotate("right");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM plain image collage horizontal") {
  PBMImage testimg("tests-images/sample-plain.pbm");
  PBMImage correctimg("tests-images/sample-plain-collage-horizontal.pbm");
  testimg.collage("horizontal", "tests-images/sample-plain.pbm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM plain image collage vertical") {
  PBMImage testimg("tests-images/sample-plain.pbm");
  PBMImage correctimg("tests-images/sample-plain-collage-vertical.pbm");
  testimg.collage("vertical", "tests-images/sample-plain.pbm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM plain image scale") {
  PBMImage testimg("tests-images/sample-plain.pbm");
  PBMImage correctimg("tests-images/sample-plain-scale.pbm");
  testimg.scale(2);

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image file name") {
  PBMImage testimg("tests-images/sample-binary.pbm");

  CHECK(testimg.get_file_name() == "tests-images/sample-binary.pbm");
}

TEST_CASE("Test PBM binary image type") {
  PBMImage testimg("tests-images/sample-binary.pbm");

  CHECK(testimg.get_type() == "P4");
}

TEST_CASE("Test PBM binary image width") {
  PBMImage testimg("tests-images/sample-binary.pbm");

  CHECK(testimg.get_width() == 640);
}

TEST_CASE("Test PBM binary image height") {
  PBMImage testimg("tests-images/sample-binary.pbm");

  CHECK(testimg.get_height() == 426);
}

TEST_CASE("Test PBM binary image negative") {
  PBMImage testimg("tests-images/sample-binary.pbm");
  PBMImage correctimg("tests-images/sample-binary-negative.pbm");
  testimg.negative();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image rotate left") {
  PBMImage testimg("tests-images/sample-binary.pbm");
  PBMImage correctimg("tests-images/sample-binary-rotate-left.pbm");
  testimg.rotate("left");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image rotate right") {
  PBMImage testimg("tests-images/sample-binary.pbm");
  PBMImage correctimg("tests-images/sample-binary-rotate-right.pbm");
  testimg.rotate("right");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image collage horizontal") {
  PBMImage testimg("tests-images/sample-binary.pbm");
  PBMImage correctimg("tests-images/sample-binary-collage-horizontal.pbm");
  testimg.collage("horizontal", "tests-images/sample-binary.pbm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image collage vertical") {
  PBMImage testimg("tests-images/sample-binary.pbm");
  PBMImage correctimg("tests-images/sample-binary-collage-vertical.pbm");
  testimg.collage("vertical", "tests-images/sample-binary.pbm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PBM binary image scale") {
  PBMImage testimg("tests-images/sample-binary.pbm");
  PBMImage correctimg("tests-images/sample-binary-scale.pbm");
  testimg.scale(2);

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM plain image file name") {
  PGMImage testimg("tests-images/sample-plain.pgm");

  CHECK(testimg.get_file_name() == "tests-images/sample-plain.pgm");
}

TEST_CASE("Test PGM plain image type") {
  PGMImage testimg("tests-images/sample-plain.pgm");

  CHECK(testimg.get_type() == "P2");
}

TEST_CASE("Test PGM plain image width") {
  PGMImage testimg("tests-images/sample-plain.pgm");

  CHECK(testimg.get_width() == 640);
}

TEST_CASE("Test PGM plain image height") {
  PGMImage testimg("tests-images/sample-plain.pgm");

  CHECK(testimg.get_height() == 426);
}

TEST_CASE("Test PGM plain image negative") {
  PGMImage testimg("tests-images/sample-plain.pgm");
  PGMImage correctimg("tests-images/sample-plain-negative.pgm");
  testimg.negative();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM plain image monochrome") {
  PGMImage testimg("tests-images/sample-plain.pgm");
  PGMImage correctimg("tests-images/sample-plain-monochrome.pgm");
  testimg.monochrome();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM plain image rotate left") {
  PGMImage testimg("tests-images/sample-plain.pgm");
  PGMImage correctimg("tests-images/sample-plain-rotate-left.pgm");
  testimg.rotate("left");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM plain image rotate right") {
  PGMImage testimg("tests-images/sample-plain.pgm");
  PGMImage correctimg("tests-images/sample-plain-rotate-right.pgm");
  testimg.rotate("right");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM plain image collage horizontal") {
  PGMImage testimg("tests-images/sample-plain.pgm");
  PGMImage correctimg("tests-images/sample-plain-collage-horizontal.pgm");
  testimg.collage("horizontal", "tests-images/sample-plain.pgm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM plain image collage vertical") {
  PGMImage testimg("tests-images/sample-plain.pgm");
  PGMImage correctimg("tests-images/sample-plain-collage-vertical.pgm");
  testimg.collage("vertical", "tests-images/sample-plain.pgm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM plain image scale") {
  PGMImage testimg("tests-images/sample-plain.pgm");
  PGMImage correctimg("tests-images/sample-plain-scale.pgm");
  testimg.scale(2);

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM binary image file name") {
  PGMImage testimg("tests-images/sample-binary.pgm");

  CHECK(testimg.get_file_name() == "tests-images/sample-binary.pgm");
}

TEST_CASE("Test PGM binary image type") {
  PGMImage testimg("tests-images/sample-binary.pgm");

  CHECK(testimg.get_type() == "P5");
}

TEST_CASE("Test PGM binary image width") {
  PGMImage testimg("tests-images/sample-binary.pgm");

  CHECK(testimg.get_width() == 640);
}

TEST_CASE("Test PGM binary image height") {
  PGMImage testimg("tests-images/sample-binary.pgm");

  CHECK(testimg.get_height() == 426);
}

TEST_CASE("Test PGM binary image negative") {
  PGMImage testimg("tests-images/sample-binary.pgm");
  PGMImage correctimg("tests-images/sample-binary-negative.pgm");
  testimg.negative();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM binary image monochrome") {
  PGMImage testimg("tests-images/sample-binary.pgm");
  PGMImage correctimg("tests-images/sample-binary-monochrome.pgm");
  testimg.monochrome();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM binary image rotate left") {
  PGMImage testimg("tests-images/sample-binary.pgm");
  PGMImage correctimg("tests-images/sample-binary-rotate-left.pgm");
  testimg.rotate("left");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM binary image rotate right") {
  PGMImage testimg("tests-images/sample-binary.pgm");
  PGMImage correctimg("tests-images/sample-binary-rotate-right.pgm");
  testimg.rotate("right");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM binary image collage horizontal") {
  PGMImage testimg("tests-images/sample-binary.pgm");
  PGMImage correctimg("tests-images/sample-binary-collage-horizontal.pgm");
  testimg.collage("horizontal", "tests-images/sample-binary.pgm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM binary image collage vertical") {
  PGMImage testimg("tests-images/sample-binary.pgm");
  PGMImage correctimg("tests-images/sample-binary-collage-vertical.pgm");
  testimg.collage("vertical", "tests-images/sample-binary.pgm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PGM binary image scale") {
  PGMImage testimg("tests-images/sample-binary.pgm");
  PGMImage correctimg("tests-images/sample-binary-scale.pgm");
  testimg.scale(2);

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM plain image file name") {
  PPMImage testimg("tests-images/sample-plain.ppm");

  CHECK(testimg.get_file_name() == "tests-images/sample-plain.ppm");
}

TEST_CASE("Test PPM plain image type") {
  PPMImage testimg("tests-images/sample-plain.ppm");

  CHECK(testimg.get_type() == "P3");
}

TEST_CASE("Test PPM plain image width") {
  PPMImage testimg("tests-images/sample-plain.ppm");

  CHECK(testimg.get_width() == 640);
}

TEST_CASE("Test PPM plain image height") {
  PPMImage testimg("tests-images/sample-plain.ppm");

  CHECK(testimg.get_height() == 426);
}

TEST_CASE("Test PPM plain image negative") {
  PPMImage testimg("tests-images/sample-plain.ppm");
  PPMImage correctimg("tests-images/sample-plain-negative.ppm");
  testimg.negative();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM plain image monochrome") {
  PPMImage testimg("tests-images/sample-plain.ppm");
  PPMImage correctimg("tests-images/sample-plain-monochrome.ppm");
  testimg.monochrome();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM plain image grayscale") {
  PPMImage testimg("tests-images/sample-plain.ppm");
  PPMImage correctimg("tests-images/sample-plain-grayscale.ppm");
  testimg.grayscale();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM plain image rotate left") {
  PPMImage testimg("tests-images/sample-plain.ppm");
  PPMImage correctimg("tests-images/sample-plain-rotate-left.ppm");
  testimg.rotate("left");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM plain image rotate right") {
  PPMImage testimg("tests-images/sample-plain.ppm");
  PPMImage correctimg("tests-images/sample-plain-rotate-right.ppm");
  testimg.rotate("right");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM plain image collage horizontal") {
  PPMImage testimg("tests-images/sample-plain.ppm");
  PPMImage correctimg("tests-images/sample-plain-collage-horizontal.ppm");
  testimg.collage("horizontal", "tests-images/sample-plain.ppm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM plain image collage vertical") {
  PPMImage testimg("tests-images/sample-plain.ppm");
  PPMImage correctimg("tests-images/sample-plain-collage-vertical.ppm");
  testimg.collage("vertical", "tests-images/sample-plain.ppm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM plain image scale") {
  PPMImage testimg("tests-images/sample-plain.ppm");
  PPMImage correctimg("tests-images/sample-plain-scale.ppm");
  testimg.scale(2);

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM binary image file name") {
  PPMImage testimg("tests-images/sample-binary.ppm");

  CHECK(testimg.get_file_name() == "tests-images/sample-binary.ppm");
}

TEST_CASE("Test PPM binary image type") {
  PPMImage testimg("tests-images/sample-binary.ppm");

  CHECK(testimg.get_type() == "P6");
}

TEST_CASE("Test PPM binary image width") {
  PPMImage testimg("tests-images/sample-binary.ppm");

  CHECK(testimg.get_width() == 640);
}

TEST_CASE("Test PPM binary image height") {
  PPMImage testimg("tests-images/sample-binary.ppm");

  CHECK(testimg.get_height() == 426);
}

TEST_CASE("Test PPM binary image negative") {
  PPMImage testimg("tests-images/sample-binary.ppm");
  PPMImage correctimg("tests-images/sample-binary-negative.ppm");
  testimg.negative();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM binary image monochrome") {
  PPMImage testimg("tests-images/sample-binary.ppm");
  PPMImage correctimg("tests-images/sample-binary-monochrome.ppm");
  testimg.monochrome();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM binary image grayscale") {
  PPMImage testimg("tests-images/sample-binary.ppm");
  PPMImage correctimg("tests-images/sample-binary-grayscale.ppm");
  testimg.grayscale();

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM binary image rotate left") {
  PPMImage testimg("tests-images/sample-binary.ppm");
  PPMImage correctimg("tests-images/sample-binary-rotate-left.ppm");
  testimg.rotate("left");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM binary image rotate right") {
  PPMImage testimg("tests-images/sample-binary.ppm");
  PPMImage correctimg("tests-images/sample-binary-rotate-right.ppm");
  testimg.rotate("right");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM binary image collage horizontal") {
  PPMImage testimg("tests-images/sample-binary.ppm");
  PPMImage correctimg("tests-images/sample-binary-collage-horizontal.ppm");
  testimg.collage("horizontal", "tests-images/sample-binary.ppm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM binary image collage vertical") {
  PPMImage testimg("tests-images/sample-binary.ppm");
  PPMImage correctimg("tests-images/sample-binary-collage-vertical.ppm");
  testimg.collage("vertical", "tests-images/sample-binary.ppm");

  CHECK(testimg == correctimg);
}

TEST_CASE("Test PPM binary image scale") {
  PPMImage testimg("tests-images/sample-binary.ppm");
  PPMImage correctimg("tests-images/sample-binary-scale.ppm");
  testimg.scale(2);

  CHECK(testimg == correctimg);
}

TEST_CASE("Test session get id") {
  Session s(0);
  CHECK(s.get_id() == 0);
}

TEST_CASE("Test session add image") {
  Session s(0);
  s.add_image("tests-images/sample-binary.pbm");
  CHECK(s.get_images()[0]->get_file_name() == "tests-images/sample-binary.pbm");
}

TEST_CASE("Test session add image with invalid image") {
  Session s(0);
  s.add_image("not_found.pbm");
  s.add_image("not_found.pgm");
  s.add_image("not_found.ppm");
  s.add_image("not_found");
  s.add_image("tests-images/found.ppp");
  s.add_image("tests-images/found");
  CHECK(s.get_images().size() == 0);
}

TEST_CASE("Test session remove image") {
  Session s(0);
  s.add_image("tests-images/sample-binary.pbm");
  s.add_image("tests-images/sample-plain.pbm");
  s.remove_image("tests-images/sample-plain.pbm");
  CHECK(s.get_images().size() == 1);
}

TEST_CASE("Test session remove image with invalid image") {
  Session s(0);
  s.add_image("tests-images/sample-binary.pbm");
  s.remove_image("notfound");
  s.remove_image("tests-images/sample-binary.pbm");
  CHECK(s.get_images().size() == 1);
}

TEST_CASE("Test session add operation") {
  Session s(0);
  s.add_operation("rotate left");
  CHECK(s.get_operations()[0] == "rotate left");
}

TEST_CASE("Test session add operation with invalid operation") {
  Session s(0);
  s.add_operation("not operation");
  CHECK(s.get_operations().size() == 0);
}

int main() {

  doctest::Context().run();

  return 0;
}
