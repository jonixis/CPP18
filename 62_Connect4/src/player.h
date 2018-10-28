#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

template<typename F>
class player {

public:
  // returns the column where the player decides to throw in his stone
  // F is the playfield which may be any playfield implementing 
  // the stoneat method, if you expect a different class because 
  // you need methods to verify whether the opponent can win, 
  // copy the field into the class that you expect.
  int play(const F &field) {
    int column;
    std::cout << "Insert stone at: ";
    std::cin >> column;
    std:: cout << std::endl;

    return column;
  }
};


#endif // PLAYER_H