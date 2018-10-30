#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "playfield_traits.h"

template<typename F, typename P=playfield_traits<playfield>>
class player {
  const int player_id;

public:
  using playfieldtraits = P;
  player(int player_id) : player_id(player_id){ }

  int getplayerid() {
    return player_id;
  }

  // returns the column where the player decides to throw in his stone
  // F is the playfield which may be any playfield implementing 
  // the stoneat method, if you expect a different class because 
  // you need methods to verify whether the opponent can win, 
  // copy the field into the class that you expect.
  int play(F &field) {
    int column;
    std::cout << "Insert stone at: ";
    std::cin >> column;
    std:: cout << std::endl;

    while (playfieldtraits::columnfull(field, column) || column > field.width - 1) {
      std::cout << "Column full or not existant! Choose another one..." << std::endl;
      std::cin >> column;
      std:: cout << std::endl;
    }

    return column;
  }
};


#endif // PLAYER_H