#pragma once
#include "../images/image.h"
#include <string>
#include <vector>

/**
   @brief Session class.

   This class represents a session. Which is
   a list of images and pending operations, and
   has an ID number.
*/
class Session {
private:
  std::vector<std::string> operations; /**< @brief List of operations.*/
  std::vector<Image *> images;         /**< @brief List of images.*/
  int id;                              /**< @brief Session ID.*/

public:
  Session(int);             /**< @brief Session constructor.*/
  Session(const Session &); /**< @brief Session copy constructor.*/
  ~Session(); /**< @brief Session destructor. Frees memory of all images. */
  Session &operator=(const Session &); /**< @brief Session operator=.*/

  int get_id();                              /**< @brief Session id getter.*/
  std::vector<std::string> get_operations(); /**< @brief Session operations
                                                getter.*/
  std::vector<Image *> get_images(); /**< @brief Session images getter.*/

  bool add_image(const std::string &); /**< @brief Adds image to the images.*/
  void remove_image(const std::string &);  /**< @brief Removes
                                              image from the images.*/
  void add_operation(const std::string &); /**< @brief Adds
                                              operation to operations.*/
  void info() const; /**< @brief Prints info about the session.*/
  void undo();  /**< @brief Undoes last operatoin. If operations is empty, calls
                   undo on  every image.*/
  void apply(); /**< @brief Applies all pending operations.*/
  void save();  /**< @brief Saves all the images in images.*/
  void saveas(const std::string &); /**< @brief Save the first
                                       image as "file_name".*/
  void
  collage(const std::string &, const std::string &, const std::string &,
          const std::string &); /**< @brief Makes a collage from two images,
                                   saves it and adds it to the images.*/
  void scale(int, const std::string &,
             const std::string &); /**< @brief Scales
                                      an image and adds it to the images.*/
};
