#ifndef MY_PLAYFIELD_H
#define MY_PLAYFIELD_H

#include <vector>
#include "playfield.h"

class my_playfield : public playfield {
public:
  const static int win = 4;

  const std::vector<std::string> stone;

protected:
  // the internal representation of the field
  char rep[playfield::width][playfield::height];
  // char rep[playfield::height][playfield::width];

public:
  my_playfield();

  void print() const;
  void insertstone(int column, int player);

  virtual int stoneat(int x, int y) const;
};

#endif // PLAYFIELD_JONI_H