#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <vector>
#include "playfield_traits.h"

class playfield {
public:
  // the size of the field
  const static int width = 7;
  const static int height = 6;

  // these elements are used to indicate whether a given position 
  // in the playing field is taken by a given player 
  const static int none = 0;
  const static int player1 = 1;
  const static int player2 = 2;

  const static int win = 4;

  const std::vector<std::string> stone;

protected:
  // the internal representation of the field
  char rep[playfield::width][playfield::height];
  // char rep[playfield::height][playfield::width];

public:
  playfield();
  
  void print() const;
  void insertstone(int column, int player);


  // return the stone (none/player1/player2) at the position(x,y)
  // 0 <= x <= width
  // 0 <= y <= height
  // stoneat(0,0) ................ top left
  // stoneat(width-1,height-1) ... bottom right
  // if we insert a stone in a new game in column i, 
  // it lands at (i,height-1)
  // implementation may be changed, interface not 
  int stoneat(int x, int y) const;
};

#endif // PLAYFIELD_H