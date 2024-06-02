#pragma once
#include "image.h"
#include <vector>

/** @brief Pixel struct.

    Structure that holds individual pixel data.
    I.e red, green and blue color channels.
 */
struct Pixel {
  int r; /**< @brief red color channel*/
  int g; /**< @brief green color channel*/
  int b; /**< @brief blue color channel*/
};

/** @brief PPMImage class.

    Represents a PPM image.
 */
class PPMImage : public Image {
private:
  int max_value;                 /**< @brief Max value for the color channels.*/
  std::vector<Pixel> matrix;     /**< @brief Matrix to store image data.*/
  std::vector<Pixel> old_matrix; /**< @brief Matrix to store
                                  prevoius image data.*/

  void read(const std::string &); /**< @brief See image.h documentation for more
                                     information.*/
  void write(const std::string &) const; /**< @brief See image.h documentation
                                            for more information.*/

public:
  PPMImage(const std::string &); /**< @brief PPMImage constructor.*/
  bool
  operator==(const PPMImage &) const; /**< @brief Checks if all image data is
                                         the same, except for the file name.*/
  Image *clone() const; /**< @brief See image.h documentation for more
                           information.*/

  void grayscale();  /**< @brief See image.h documentation for more
                        information.*/
  void monochrome(); /**< @brief See image.h documentation for more
                        information.*/
  void negative();   /**< @brief See image.h documentation for more
                        information.*/
  void rotate(const std::string &); /**< @brief See image.h documentation for
                                       more information.*/
  void
  collage(const std::string &,
          const std::string &); /**< @brief See
                                   image.h documentation for more information.*/
  void scale(int);              /**< @brief See image.h documentation for more
                                   information.*/
  void undo();                  /**< @brief See image.h documentation for more
                                   information.*/
};
