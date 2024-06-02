#pragma once
#include <iostream>
#include <string>
#include <vector>

/**
   @brief Matrix transpose algorithm.

   This function takes a matrix, that is represented
   as a vector, and transposes it. I.e makes the rows
   to be columns and columns to be rows.
*/

template <typename T> void transpose_matrix(std::vector<T> &m, int &w, int &h) {
  std::vector<T> result(w * h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      result[j * h + i] = m[i * w + j];
    }
  }
  m = result;
  std::swap(w, h);
}

/**
   @brief Matrix horizontal flip algorithm.

   This function takes a matrix, that is represented
   as a vector, and flips it horizontaly. I.e reverses
   the columns of the matrix.
*/

template <typename T> void flip_h_matrix(std::vector<T> &m, int w, int h) {
  std::vector<T> result(w * h);

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      result[j * w + i] = m[w * (h - j - 1) + i];
    }
  }

  m = result;
}

/**
   @brief Matrix vertical flip algorithm.

   This function takes a matrix, that is represented
   as a vector, and flips it verticaly. I.e reverses
   the rows of the matrix.
*/

template <typename T> void flip_v_matrix(std::vector<T> &m, int w, int h) {
  std::vector<T> result(w * h);

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      result[i * w + j] = m[i * w + w - j - 1];
    }
  }

  m = result;
}

/**
   @brief Matrix rotate algorithm.

   This function takes a matrix, that is represented
   as a vector, and rotates it by given direction.
   It does that by transposing the matrix first, and
   then flipping it in the correct direction.
*/

template <typename T>
void rotate_matrix(std::vector<T> &m, int &w, int &h,
                   const std::string &direction) {
  transpose_matrix(m, w, h);
  if (direction == "left") {
    flip_h_matrix(m, w, h);
  } else if (direction == "right") {
    flip_v_matrix(m, w, h);
  }
}

/**
   @brief Concatenate matrix vertically algorithm.

   This function takes a matrix, that is represented
   as a vector, and another matrix, that is represented
   as a vector, and "glues" them together vertically.
*/

template <typename T>
void cat_v_matrix(std::vector<T> &m1, int &w1, int &h1,
                  const std::vector<T> &m2, int w2, int h2) {

  if (w1 != w2) {
    std::cout << "Width1 != Width2\n";
    return;
  }

  int size = w2 * h2;
  for (int i = 0; i < size; i++) {
    m1.push_back(m2[i]);
  }
  h1 += h2;
}

/**
   @brief Concatenate matrix horizontally algorithm.

   This function takes a matrix, that is represented
   as a vector, and another matrix, that is represented
   as a vector, and "glues" them together horizontally.
*/

template <typename T>
void cat_h_matrix(std::vector<T> &m1, int &w1, int &h1,
                  const std::vector<T> &m2, int w2, int h2) {

  if (h1 != h2) {
    std::cout << "Height1 != Height2\n";
    return;
  }

  int k = 0;
  int l = 0;
  std::vector<T> result;
  for (int i = 0; i < h1; i++) {
    for (int j = 0; j < w1; j++) {
      T x = m1[k];
      result.push_back(x);
      k++;
    }
    for (int j = 0; j < w2; j++) {
      T y = m2[l];
      result.push_back(y);
      l++;
    }
  }

  m1 = result;

  w1 += w2;
}

/**
   @brief Scale matrix algorithm.

   This function takes a matrix, represented
   as a vector, and a factor and scales it by
   the factor. I.e makes it bigger, i.e
   increases "resolution".
*/

template <typename T>
void scale_matrix(std::vector<T> &m, int &w, int &h, int factor) {

  while (factor--) {
    std::vector<T> new_m(w * h * 4);

    int row = 0;
    int col = 0;

    for (int i = 0; i < w * h; i++) {
      new_m[row * (w * 2) + col] = m[i];
      new_m[row * (w * 2) + col + 1] = m[i];
      new_m[(row + 1) * (w * 2) + col] = m[i];
      new_m[(row + 1) * (w * 2) + col + 1] = m[i];
      col += 2;
      if (col >= w * 2) {
        row += 2;
        col = 0;
      }
    }

    w *= 2;
    h *= 2;
    m = new_m;
  }
}
