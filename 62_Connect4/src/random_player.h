#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include <iostream>
#include "playfield_traits.h"


template<typename F, typename P=playfield_traits<F>>
class randomplayer {
  const int player_id;

public:
  using playfieldtraits = P;

  randomplayer(int player_id) : player_id(player_id){
    srand(time(NULL));
  }

  // returns the column where the player decides to throw in his stone
  // F is the playfield which may be any playfield implementing
  // the stoneat method, if you expect a different class because
  // you need methods to verify whether the opponent can win,
  // copy the field into the class that you expect.
  int play(F &field) {
    int column = std::rand() % 7;
    while (playfieldtraits::columnfull(field, column)) {
      column = std::rand() % 7;
    }

    return column;
  }
};


#endif // RANDOMPLAYER_H