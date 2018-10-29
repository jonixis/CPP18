#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include <iostream>
#include <cstdlib>
#include <ctime>


template<typename F>
class randomplayer {
  const int player_id;

public:

  randomplayer(int player_id) : player_id(player_id){
    std::srand(std::time(NULL));
  }

  // returns the column where the player decides to throw in his stone
  // F is the playfield which may be any playfield implementing 
  // the stoneat method, if you expect a different class because 
  // you need methods to verify whether the opponent can win, 
  // copy the field into the class that you expect.
  int play(F &field) {
    int column = std::rand() % 7;
    while (field.columnfull(column)) {
      column = std::rand() % 7;
    }
    field.insertstone(column, player_id);

    return column;
  }
};


#endif // RANDOMPLAYER_H