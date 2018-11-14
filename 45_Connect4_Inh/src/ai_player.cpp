#include "ai_player.h"
#include <iostream>
#include <ctime>


  ai_player::ai_player(int player_id) : player_id(player_id), opponent_id(player_id == 1 ? 2 : 1) {
    std::srand(std::time(NULL));
  }

  ai_player::~ai_player() { }

  int ai_player::getrandomcolumn(const playfield &field) {
    int column = std::rand() % 7;
    while (playfieldtraits::columnfull(field, column)) {
      column = std::rand() % 7;
    }

    return column;
  }

  void ai_player::insertteststone(std::vector<std::vector<char>> &rep, int column, int player) {
    int row = playfield::height - 1;
    while (rep[column][row] != playfield::none) {
      row--;
    }

    rep[column][row] = player;
  }

  int ai_player::findbestcolumn(const playfield &field) {
    // Tests if oppenent coudl win in one move and prevents that
    for (int i = 0; i < playfield::width; i++) {
      std::vector<std::vector<char>> rep = playfieldtraits::copyrep(field);
      if (!playfieldtraits::columnfull(field, i)) {
        insertteststone(rep, i, opponent_id);
        if (haswon(rep, opponent_id)) {
          return i;
        }
      }
    }
    // Tests if player can win in one move an chooses winning column
    for (int i = 0; i < playfield::width; i++) {
      std::vector<std::vector<char>> rep = playfieldtraits::copyrep(field);
      if (!playfieldtraits::columnfull(field, i)) {
        insertteststone(rep, i, player_id);
        if (haswon(rep, player_id)) {
          return i;
        }
      }
    }

    // If both is not the case, choose random column
    return getrandomcolumn(field);
  }

  bool ai_player::haswonhorizontal(const std::vector<std::vector<char>> rep, int column, int row, int player) {
    for (int i = 0; i < win; i++) {
      if (rep[column + i][row] != player) {
        return false;
      }
    }
    return true;
  }

  bool ai_player::haswonvertical(const std::vector<std::vector<char>> rep, int column, int row, int player) {
    for (int i = 0; i < win; i++) {
      if (rep[column][row - i] != player) {
        return false;
      }
    }
    return true;
  }

  bool ai_player::haswondiagonalslash(const std::vector<std::vector<char>> rep, int column, int row, int player) {
    for (int i = 0; i < win; i++) {
      if (rep[column + i][row - i] != player) {
        return false;
      }
    }
    return true;
  }

  bool ai_player::haswondiagonalbackslash(const std::vector<std::vector<char>> rep, int column, int row, int player) {
    for (int i = 0; i < win; i++) {
      if (rep[column - i][row - i] != player) {
        return false;
      }
    }
    return true;
  }

  bool ai_player::haswon(const std::vector<std::vector<char>> rep, int player) {
    for (int i = playfield::height - 1; i >= 0; i--) {
      for (int j = 0; j < playfield::width; j++) {

        if (j + (win-1) < playfield::width && haswonhorizontal(rep, j, i, player)) {
          return true;
        }

        if (i - (win-1) >= 0 && haswonvertical(rep, j, i, player)) {
          return true;
        }

        if (j + (win-1) < playfield::width && i - (win-1) >= 0 &&
            haswondiagonalslash(rep, j, i, player)) {
          return true;
        }

        if (i + (win-1) >= 0 && j - (win-1) >= 0 &&
            haswondiagonalbackslash(rep, j, i, player)) {
          return true;
        }
      }
    }
    return false;
  }

  // returns the column where the player decides to throw in his stone
  // F is the playfield which may be any playfield implementing
  // the stoneat method, if you expect a different class because
  // you need methods to verify whether the opponent can win,
  // copy the field into the class that you expect.
  int ai_player::play(const playfield &field) {
    return findbestcolumn(field);
  }