#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "player.h"
#include "playfield_traits.h"
#include "playfield.h"

typedef playfield_traits<playfield> playfieldtraits;

class ai_player : public player {
  const int player_id;
  const int opponent_id;
  const int win = 4;

public:

  ai_player(int player_id);

  int getrandomcolumn(const playfield &field);
  void insertteststone(std::vector<std::vector<char>> &rep, int column, int player);
  int findbestcolumn(const playfield &field);
  bool haswonhorizontal(const std::vector<std::vector<char>> rep, int column, int row, int player);
  bool haswonvertical(const std::vector<std::vector<char>> rep, int column, int row, int player);
  bool haswondiagonalslash(const std::vector<std::vector<char>> rep, int column, int row, int player);
  bool haswondiagonalbackslash(const std::vector<std::vector<char>> rep, int column, int row, int player);
  bool haswon(const std::vector<std::vector<char>> rep, int player);

  // returns the column where the player decides to throw in his stone
  // F is the playfield which may be any playfield implementing
  // the stoneat method, if you expect a different class because
  // you need methods to verify whether the opponent can win,
  // copy the field into the class that you expect.
  virtual int play(const playfield &field);
  virtual ~ai_player();
};

#endif // AIPLAYER_H