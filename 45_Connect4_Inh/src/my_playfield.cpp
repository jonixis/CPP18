#include "my_playfield.h"
#include <iostream>

using namespace std;

my_playfield::my_playfield() : stone({"  ", "\U0001F534", "\U0001F535"}) {
  // Init playfield with zeros
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      rep[i][j] = none;
    }
  }
}

void my_playfield::insertstone(int column, int player) {
  int row = height - 1;
  while(rep[column][row] != none) {
    row--;
  }

  rep[column][row] = player;
}

void my_playfield::print() const {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << "" << stone[rep[j][i]] << " ";
    }
    cout << endl;
  }
}

int my_playfield::stoneat(int x, int y) const {
  return rep[x][y];
}
