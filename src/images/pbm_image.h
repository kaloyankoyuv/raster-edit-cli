#pragma once
#include "image.h"
#include <vector>

/** @brief PBMImage class.

    Represents a PBM image.
 */
class PBMImage : public Image {
private:
  std::vector<bool> matrix;     /**< @brief Vector to store image matrix data.*/
  std::vector<bool> old_matrix; /**< @brief Vector to store previous image
                                   matrix data. Needed for undo.*/

  void read(const std::string &); /**< @brief See image.h documentation for more
                                     information.*/
  void write(const std::string &) const; /**< @brief See image.h documentation
                                            for more information.*/
public:
  PBMImage(const std::string &); /**< @brief PBMImage constructor.*/
  bool
  operator==(const PBMImage &) const; /**< @brief Checks if all image data is
                                         the same, except for the file name.*/
  Image *clone() const; /**< @brief See image.h documentation for more
                           information.*/

  void grayscale();  /**< @brief See
                        image.h documentation for more information.*/
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
