#include <iostream>
#include <array>
#include <algorithm>
#include <ctime>


using namespace std;

const int height = 10;
const int width = 40;


bool is_alive(array<array<int, height>, width>& game, const int x, const int y) {

	//testing left
	int alive = 0;
	if (x - 1 > 0 && game[y][x - 1] == 1)
	{
		alive++;
	}
	//testing right
	if (x + 1 < height && game[y][x + 1] == 1)
	{
		alive++;
	}
	//testing top
	if (y - 1 > 0 && game[y - 1][x] == 1)
	{
		alive++;
	}
	//testing bottom
	if (y + 1 < width && game[y + 1][x] == 1)
	{
		alive++;
	}
	//testing top left
	if (x - 1 > 0 && y - 1 > 0 && game[y - 1][x - 1] == 1)
	{
		alive++;
	}
	//testing top right
	if (x + 1 < height && y - 1 > 0 && game[y - 1][x + 1] == 1)
	{
		alive++;
	}
	//testing bottom left
	if (x - 1 > 0 && y + 1 < width && game[y + 1][x - 1] == 1)
	{
		alive++;
	}
	//testing bottom right
	if (x + 1 < height && y + 1 < width && game[y + 1][x + 1] == 1)
	{
		alive++;
	}

	// Implementing RULES
	//
	// underpopulation
	if (game[y][x] == 1 && alive < 2)
	{
		return false;
	}
	//next generation
	if (game[y][x] == 1 && (alive == 2 || alive == 3))
	{
		return true;
	}
	//overpopulation
	if (game[y][x] == 1 && alive > 3)
	{
		return false;
	}
	//reproduction
	if (game[y][x] == 1 && alive == 3)
	{
		return true;
	}

	return false;
}

int main() {

	srand(time(nullptr));
	array<array<int, height>, width> display;
	array<array<int, height>, width> swap;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			display[j][i] = rand() % 4 == 0;
		}
	}

	bool again;
	do
	{
		//draw
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (display[j][i] == true)
				{
					cout << "*";
				}
				else
				{
					cout << "-";

				}
			}
			cout << endl;
		}

		//check for alive points
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				swap[j][i] = is_alive(display, i, j);
			}
		}
		display = swap;

		cout << "Again? (1/0)";
		cin >> again;
	} while (again);


	return 0;
}