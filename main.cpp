#include <iostream>

#include "Gameplay/Game.h"
#include "Math/Collider.h"

int main()
{
	// Collider a;
	// Collider b;
	// Vector2 p = Vector2(0, 1);
	//
	// b.set_position(p);
	//
	// if (a.is_colliding(b))
	// 	std::cout << "true\n";
	// else
	// 	std::cout << "false\n";
	//
	// return 0;
	
	Game game;
	game.loop_game();
}
