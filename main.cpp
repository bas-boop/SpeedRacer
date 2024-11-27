#include "Gameplay/Game.h"
#include "Math/Vector2.h"

#include <iostream>

using std::cout;

int main()
{
	cout << Vector2::one.x << " " << Vector2::zero.y << "\n";
	
	Game game;
	game.loop_game();

	
	



	



	Vector2 a(2, 7);
	const Vector2 b(2, 356);
	const Vector2* c =  new Vector2(6, 3);

	cout << a.x << " " << a.y << "\n";

	a += c;
	a += b;

	cout << c->x << " " << c->y << "\n";
	cout << b.x << " " << b.y << "\n";
	cout << a.x << " " << a.y << "\n";
}
