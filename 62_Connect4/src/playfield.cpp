#include "playfield.h"
#include <iostream>

using namespace std;

playfield::playfield() {
  // Init playfield with zeros
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      rep[i][j] = '0';
    }
  }
}

void playfield::print() const {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << "  " << rep[i][j] << "  ";
    }
    cout << endl;
  }
}

int playfield::stoneat(int x, int y) const { 
  return rep[x][y];
}
