#ifndef MY_PLAYER_H
#define MY_PLAYER_H

#include <iostream>
#include "player.h"
#include "playfield_traits.h"
#include "playfield.h"

typedef playfield_traits<playfield> playfieldtraits;

class my_player : public player {
  const int player_id;

public:
  my_player(int player_id);

  int getplayerid();

  // returns the column where the player decides to throw in his stone
  // F is the playfield which may be any playfield implementing
  // the stoneat method, if you expect a different class because
  // you need methods to verify whether the opponent can win,
  // copy the field into the class that you expect.
  virtual int play(const playfield &field);
  virtual ~my_player();
};


#endif // MY_PLAYER_H