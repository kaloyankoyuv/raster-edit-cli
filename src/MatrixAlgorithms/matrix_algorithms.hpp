#pragma once
#include <iostream>
#include <string>
#include <vector>

template <typename T> void transpose_matrix(std::vector<T> &v, int &w, int &h) {
  std::vector<T> result(w * h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      result[j * h + i] = v[i * w + j];
    }
  }
  v = result;
  std::swap(w, h);
}

template <typename T> void flip_h_matrix(std::vector<T> &v, int w, int h) {
  std::vector<T> result(w * h);

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      result[j * w + i] = v[w * (h - j - 1) + i];
    }
  }

  v = result;
}

template <typename T> void flip_v_matrix(std::vector<T> &v, int w, int h) {
  std::vector<T> result(w * h);

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      result[i * w + j] = v[i * w + w - j - 1];
    }
  }

  v = result;
}

template <typename T>
void rotate_matrix(std::vector<T> &v, int &w, int &h,
                   const std::string &direction) {
  transpose_matrix(v, w, h);
  if (direction == "left") {
    flip_h_matrix(v, w, h);
  } else if (direction == "right") {
    flip_v_matrix(v, w, h);
  }
}

template <typename T>
void cat_v_matrix(std::vector<T> &v1, int &w1, int &h1,
                  const std::vector<T> &v2, int w2, int h2) {

  if (w1 != w2) {
    std::cout << "Width1 != Width2" << std::endl;
    return;
  }

  int size = w2 * h2;
  for (int i = 0; i < size; i++) {
    v1.push_back(v2[i]);
  }
  h1 += h2;
}

template <typename T>
void cat_h_matrix(std::vector<T> &v1, int &w1, int &h1,
                  const std::vector<T> &v2, int w2, int h2) {

  if (h1 != h2) {
    std::cout << "Height1 != Height2" << std::endl;
    return;
  }

  w1 += w2;

  for (int i = 0; i < h1; i++) {
    typename std::vector<T>::iterator pos = v1.begin() + ((i + 1) * w1) - w2;
    v1.insert(pos, v2.begin() + (i * w2), v2.begin() + ((i + 1) * w2));
  }
}
