#include <iostream>
#include "playfield.h"
#include "my_player.h"
#include "ai_player.h"
#include "playfield_traits.h"

using namespace std;
using playfieldtraits = playfield_traits<playfield>;

int main(int argc, char const *argv[]) {
  my_playfield field;

  // Player 1
  my_player player1(1);
  ai_player aiplayer1(1);


  // Player 2
  my_player player2(2);
  ai_player aiplayer2(2);

  field.print();

  for (;;) {

    // Check for draw
    if (playfieldtraits::isdraw(field)) {
      cout << "DRAW!" << endl;
      break;
    }

    cout << "Player 1" << endl;
    field.insertstone(player1.play(field), 1);
    // field.insertstone(aiplayer1.play(field), 1);
    field.print();
    if (playfieldtraits::haswon(field, 1)) {
      cout << "Player 1 has won!" << endl;
      break;
    }

    cout << "Player 2" << endl;
    // field.insertstone(player2.play(field), player2.getplayerid());
    field.insertstone(aiplayer2.play(field), 2);
    // field.insertstone(player2.play(field), player2.getplayerid());
    // field.insertstone(randplayer2.play(field), player2.getplayerid());
    field.print();
    if (playfieldtraits::haswon(field, 2)) {
      cout << "Player 2 has won!" << endl;
      break;
    }
  }

  return 0;
}