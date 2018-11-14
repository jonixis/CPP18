#include <iostream>
#include "my_player.h"
#include "playfield_traits.h"


my_player::my_player(int player_id) : player_id(player_id){ }

my_player::~my_player() { }

int my_player::getplayerid() {
  return player_id;
}

int my_player::play(const playfield &field) {
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



