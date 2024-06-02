#pragma once
#include "image.h"
#include <vector>

/** @brief PGMImage class.

    Represents a PGM image.
 */
class PGMImage : public Image {
private:
  int max_value;               /**< @brief Max value for the color channels.*/
  std::vector<int> matrix;     /**< @brief Matrix to store image data.*/
  std::vector<int> old_matrix; /**< @brief Matrix to store
                                  prevoius image data.*/

  void read(const std::string &); /**< @brief See image.h documentation for more
                                     information.*/
  void write(const std::string &) const; /**< @brief See image.h documentation
                                            for more information.*/

public:
  PGMImage(const std::string &); /**< @brief PGMImage constructor.*/
  bool
  operator==(const PGMImage &) const; /**< @brief Checks if all image data is
                                         the same, except for the file name.*/
  Image *clone() const; /**< @brief See image.h documentation for more
                           information.*/

  void grayscale();  /**< @brief See image.h documentation for more
                        informatioxn.*/
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
