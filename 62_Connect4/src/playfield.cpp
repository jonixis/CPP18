#include "playfield.h"
#include <iostream>

using namespace std;

playfield::playfield() : stone({"  ", "\U0001F534", "\U0001F535"}) {
  // Init playfield with zeros
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      rep[i][j] = none;
    }
  }
}

void playfield::print() const {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << "" << stone[rep[i][j]] << " ";
    }
    cout << endl;
  }
}

bool playfield::columnfull(int column) {
  return rep[0][column] != none;
}

void playfield::insertstone(int column, int player) {
  int row = height - 1;
  while(rep[row][column] != none) {
    row--;
  }

  rep[row][column] = player;
}

bool playfield::haswonhorizontal(int column, int row, int player) const{
  for (int i = 0; i < win; i++) {
    if (rep[row][column + i] != player) {
      return false;
    }
  }
  return true;
}

bool playfield::haswonvertical(int column, int row, int player) const{
  for (int i = 0; i < win ; i++) {
    if (rep[row - i][column] != player) {
      return false;
    }
  }
  return true;
}

bool playfield::haswondiagonalslash(int column, int row, int player) const{
  for (int i = 0; i < win; i++) {
    if (rep[row - i][column + i] != player) {
      return false;
    }
  }
  return true;
}

bool playfield::haswondiagonalbackslash(int column, int row, int player) const {
  for (int i = 0; i < win; i++) {
    if (rep[row - i][column - i] != player) {
      return false;
    }
  }
  return true;
}

bool playfield::haswon(int player) const {
  for (int i = height - 1; i >= 0; i--) {
    for (int j = 0; j < width; j++) {
      
      if (j + win <= width && haswonhorizontal(j, i, player)) {
        return true;
      }

      if (i - win >= 0 && haswonvertical(j, i, player)) {
        return true;
      }

      if (j + win <= width && i - win >= 0 && haswondiagonalslash(j, i, player)) {
        return true;
      }

      if (i + win >= 0 && j - win >= 0 && haswondiagonalbackslash(j, i, player)) {
        return true;
      }

    }
  }

  return false;
}

int playfield::stoneat(int x, int y) const { 
  return rep[x][y];
}
