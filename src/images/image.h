#pragma once
#include <string>

/**
   @brief Abstract class Image.

*/
class Image {
protected:
  std::string file_name; /**< @brief File name of the image.*/
  std::string type;      /**< @brief Type of the image.*/
  int width;             /**< @brief Width of the image.*/
  int old_width;         /**< @brief Old width of the image. Used for undo.*/
  int height;            /**< @brief Height of the image.*/
  int old_height;        /**< @brief Old height of the image. Used for undo.*/

  /** @brief Reads from file image data.

      Pure virtual, so must be implemented
      by all derived classes.*/
  virtual void read(const std::string &) = 0;

  /** @brief Writes image data to file.

      Pure virtual, so must be implemented
      by all derived classes.*/
  virtual void write(const std::string &) const = 0;

  void skip_comments(std::ifstream &); /**< @brief Helper function. Skips
                                          commented lines in image files.*/

public:
  virtual ~Image() = default; /**< @brief Virtual destructor.
                                 Needed for polymorphism.*/

  /** @brief "Virtual copy constructor".

      Needed for polymorphism. Pure virtual, so must be
      implemented by all derived classes*/
  virtual Image *clone() const = 0;

  std::string get_file_name() const; /**< @brief File name getter.*/
  std::string get_type() const;      /**< @brief Image type getter.*/
  int get_width() const;             /**< @brief Image width getter.*/
  int get_height() const;            /**< @brief Image height getter.*/

  void save() const;                 /**< @brief Saves image.*/
  void save_as(const std::string &); /**< @brief Saves image as "file_name".*/
  void rename(const std::string &);  /**< @brief Renames image as "file_name".*/

  /** @brief Grayscale algorithm.

      Turns colored images to images with only shades of gray. It
      replaces every pixels RGB values to their average. Pure virtual so must be
      implemented by all derived classes. Pure virtual so must be implemented by
      all derived classes.*/
  virtual void grayscale() = 0;

  /** @brief Monochrome algorithm.

      Turns grayscale or colored images to monochrome ones.
      Like grayscale but takes the average and compares it to the
      max value of the colors divided by two. If the average is
      greater, the pixels turns pure white, else pure black. Pure virtual so
     must be implemented by all derived classes.*/
  virtual void monochrome() = 0;

  /** @brief Negative algorithm.

      Turns every pixel to its negative. I.e from the max value of
      the colores subtracts the current value of the colors. Pure virtual so
     must be implemented by all derived classes.*/
  virtual void negative() = 0;

  /** @brief Rotate image algorithm.

      See the matrix rotate algorithm in matrix_algorithms.h
      for more information. Pure virtual so must be implemented by all derived
      classes.*/
  virtual void rotate(const std::string &) = 0;

  /** @brief Collage algorithm.

      See the matrix concat algorithms in matrix_algorithms.h
      for more information. Pure virtual so must be implemented by all derived
      classes.*/
  virtual void collage(const std::string &, const std::string &) = 0;

  /** @brief Scale algorithm.

      See the matrix scale algorithm in matrix_algorithms.h
      for more information. Pure virtual so must be implemented by all derived
      classes.*/
  virtual void scale(int) = 0;

  /** @brief Undo function.

      Whenever there is a change in the image, we store the old info about the
      image and when this function is called we restore this old info. Pure
      virtual so must be implemented by all derived classes.*/
  virtual void undo() = 0;

  /** @brief Image factory.

      Takes a file name for argument, checks what type of image it is, and
      returns a new image pointer of that type. Needed for polymorphism.*/
  static Image *image_factory(const std::string &);

  /** @brief Extract extension.

      Helper function. Takes a file name for argument and gives us its file
      extension.*/
  static std::string extract_extension(const std::string &);
};
