#include "Gameplay/Game.h"
#include "Math/Vector2.h"

#include <iostream>

using std::cout;

int main()
{
	Game game;
	game.loop_game();

	
	
	



	








	
	const Vector2* b = new Vector2(1, 2);
	const Vector2* c = new Vector2(1, 0);

	Vector2* a = new Vector2(5, 6);

	Vector2 d(1, 2);

	d.add(*a);

	a->x = 9;
	
	a->add(*b);
	cout << a->x << " " << a->y << "\n";
	
	a->subtract(*b);
	cout << a->x << " " << a->y << "\n";

	a->x = 5;

	a->multiply(*b);
	cout << a->x << " " << a->y << "\n";

	a->divide(*b);
	cout << a->x << " " << a->y << "\n";

	a->divide(*c);
	cout << a->x << " " << a->y << "\n";
}
