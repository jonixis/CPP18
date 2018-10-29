#include <iostream>
#include "playfield.h"
#include "player.h"
#include "random_player.h"
#include "ai_player.h"

using namespace std;

int main(int argc, char const *argv[]) {
  playfield field;
  player<playfield> player1(1);
  player<playfield> player2(2);
  randomplayer<playfield> randplayer2(2);

  field.print();

  for (;;) {
    cout << "Player 1" << endl;
    player1.play(field);
    field.print();
    if (field.haswon(1)) {
      cout << "Player 1 has won!" << endl;
      break;
    }

    cout << "Player 2" << endl;
    randplayer2.play(field);
    field.print();
    if (field.haswon(2)) {
      cout << "Player 2 has won!" << endl;
      break;
    }
  }

  return 0;
}