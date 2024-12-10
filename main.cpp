#include "Gameplay/Game.h"
#include "Math/Vector2.h"

#include <iostream>

using std::cout;

int main()
{
	Game game;
	game.loop_game();

	
	



	



	cout << Vector2::zero << "\n";
	Vector2 a(2, 7);
	const Vector2 b(2, 356);
	const Vector2* c =  new Vector2(6, 3);

	cout << a << "\n";

	a += c;
	a += b;

	cout << c << "\n";
	delete c;
	cout << b << "\n";
	cout << a << "\n";
}
