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

void playfield::insertstone(int column, int player) {
  int row = height - 1;
  while(rep[row][column] != none) {
    row--;
  }

  rep[row][column] = player;
}

void playfield::print() const {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << "" << stone[rep[i][j]] << " ";
    }
    cout << endl;
  }
}

int playfield::stoneat(int x, int y) const { 
  return rep[x][y];
}
