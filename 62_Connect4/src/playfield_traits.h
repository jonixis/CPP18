#ifndef PLAYFIELD_TRAITS_H
#define PLAYFIELD_TRAITS_H

#include <iostream>
#include <vector>
#include "playfield.h"

template <typename F> 
struct playfield_traits {
  
  static const int win = 4;

  static std::vector<std::vector<char>> copyrep(const F &field) {
    std::vector<std::vector<char>> rep(F::height, std::vector<char>(F::width));
    for (int i = 0; i < F::height; i++) {
      for (int j = 0; j < F::width; j++) {
        rep[i][j] = field.stoneat(i,j);
      }
    }
    return rep;
  }

  static bool columnfull(const F &field, int column) {
    return field.stoneat(0, column) != F::none;
  }

  static bool haswonhorizontal(const F &field, int column, int row, int player) {
    for (int i = 0; i < win; i++) {
      if (field.stoneat(row, column + i) != player) {
        return false;
      }
    }
    return true;
  }

  static bool haswonvertical(const F &field, int column, int row, int player) {
    for (int i = 0; i < win; i++) {
      if (field.stoneat(row - i, column) != player) {
        return false;
      }
    }
    return true;
  }

  static bool haswondiagonalslash(const F &field, int column, int row, int player) {
    for (int i = 0; i < win; i++) {
      if (field.stoneat(row - i, column + i) != player) {
        return false;
      }
    }
    return true;
  }

  static bool haswondiagonalbackslash(const F &field, int column, int row, int player) {
    for (int i = 0; i < win; i++) {
      if (field.stoneat(row - i, column - i) != player) {
        return false;
      }
    }
    return true;
  }

  static bool haswon(const F &field, int player) {
    for (int i = F::height - 1; i >= 0; i--) {
      for (int j = 0; j < F::width; j++) {

        if (j + win <= F::width && haswonhorizontal(field, j, i, player)) {
          return true;
        }

        if (i - win >= 0 && haswonvertical(field, j, i, player)) {
          return true;
        }

        if (j + win <= F::width && i - win >= 0 &&
            haswondiagonalslash(field, j, i, player)) {
          return true;
        }

        if (i + win >= 0 && j - win >= 0 &&
            haswondiagonalbackslash(field, j, i, player)) {
          return true;
        }
      }
    }
    return false;
  }
};

#endif // PLAYFIELD_TRAITS_H