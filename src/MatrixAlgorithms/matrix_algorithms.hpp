#pragma once
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
