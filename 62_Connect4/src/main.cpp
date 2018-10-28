#include <iostream>
#include "playfield.h"
#include "player.h"
#include "random_player.h"

using namespace std;

int main(int argc, char const *argv[]) {
  playfield field;
  player<playfield> player1;
  player<playfield> player2;
  randomplayer<playfield> randplayer2;

  field.print();

  int column;

  for (;;) {
    cout << "Player 1" << endl;
    column = player1.play(field);
    while (field.columnfull(column) || column > field.width - 1) {
      cout << "Column full or not existant! Choose another one..." << endl;
      column = player1.play(field);
    }
    field.insertstone(column, 1);
    field.print();
    if (field.haswon(1)) {
      cout << "Player 1 has won!" << endl;
      break;
    }

    cout << "Player 2" << endl;
    column = randplayer2.play(field);
    while (field.columnfull(column) || column > field.width - 1) {
      cout << "Column full or not existant! Choose another one..." << endl;
      column = randplayer2.play(field);
    }
    field.insertstone(column, 2);
    field.print();
    if (field.haswon(2)) {
      cout << "Player 2 has won!" << endl;
      break;
    }
  }

  return 0;
}