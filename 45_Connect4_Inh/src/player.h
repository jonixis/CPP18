#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "playfield.h"
#include "my_playfield.h"

class player {

public:

	virtual int play(const playfield &field) = 0;
	virtual ~player() {};
};

#endif /* PLAYER_H_ */