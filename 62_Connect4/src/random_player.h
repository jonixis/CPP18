#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include <iostream>
#include <cstdlib>
#include <ctime>


template<typename F>
class randomplayer {

public:

  randomplayer() {
    std::srand(std::time(NULL));
  }

  // returns the column where the player decides to throw in his stone
  // F is the playfield which may be any playfield implementing 
  // the stoneat method, if you expect a different class because 
  // you need methods to verify whether the opponent can win, 
  // copy the field into the class that you expect.
  int play(const F &field) {
    return std::rand() % 7;
  }
};


#endif // RANDOMPLAYER_H