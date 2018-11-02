#include <iostream>
#include "playfield.h"
#include "player.h"
#include "random_player.h"
#include "ai_player.h"
#include "playfield_traits.h"
#include "alphonse_player.h"

using namespace std;
using playfieldtraits = playfield_traits<playfield>;

int main(int argc, char const *argv[]) {
  playfield field;

  // Player 1
  player<playfield> player1(1);
  aiplayer<playfield> aiplayer1(1);
  alphonse::player<playfield> alphie1(1);
  randomplayer<playfield> randplayer1(1);

  // Player 2
  player<playfield> player2(2);
  aiplayer<playfield> aiplayer2(2);
  randomplayer<playfield> randplayer2(2);
  alphonse::player<playfield> alphie2(2);

  field.print();

  for (;;) {
    cout << "Player 1" << endl;
    // field.insertstone(player1.play(field), player1.getplayerid());
    field.insertstone(aiplayer1.play(field), 1);
    // field.insertstone(alphie1.play(field), 1);
    field.print();
    if (playfieldtraits::haswon(field, 1)) {
      cout << "Player 1 has won!" << endl;
      break;
    }

    cout << "Player 2" << endl;
    // field.insertstone(player2.play(field), player2.getplayerid());
    field.insertstone(aiplayer2.play(field), 2);
    // field.insertstone(randplayer2.play(field), player2.getplayerid());
    field.print();
    if (playfieldtraits::haswon(field, 2)) {
      cout << "Player 2 has won!" << endl;
      break;
    }
  }

  return 0;
}