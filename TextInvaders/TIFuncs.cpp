#include "TextInvaders.h"
#include "curses.h"
using namespace std;

void Move(Position& pos, Direction direction)
{
	switch (direction)
	{
	case UP:
	{
		pos.row--;
	}
	break;

	case DOWN:
	{
		pos.row++;
	}

	case LEFT:
	{
		pos.col--;
	}
	break;

	case RIGHT:
	{
		pos.col++;
	}
	break;

	}
}

void DrawSprite(Sprite sprite, Position pos)
{
	// draw sprite with top left character at the Position "pos"

	for (int i = 0; i < sprite.bodyRowStrings.size(); i++)
	{
		mvprintw(pos.row + i, pos.col, sprite.bodyRowStrings[i].c_str());
	}

	refresh();
}

void InitPlayer(Player& player)
{
	player.pos.row = PLAYER_START_ROW;
	player.pos.col = PLAYER_START_COL;
	player.curSprite = 0;

	Sprite playerSprite1;
	playerSprite1.bodyRowStrings.push_back(" =A= ");
	playerSprite1.bodyRowStrings.push_back("=====");
	
	Sprite playerSprite2;
	playerSprite2.bodyRowStrings.push_back(",~^.'");
	playerSprite2.bodyRowStrings.push_back("=====");

	Sprite playerSprite3;
	playerSprite3.bodyRowStrings.push_back("'+-`.");
	playerSprite3.bodyRowStrings.push_back("=====");

	player.sprites.reserve(PLAYER_SPRITE_STATES);
	player.sprites.push_back(playerSprite1);
	player.sprites.push_back(playerSprite2);
	player.sprites.push_back(playerSprite3);
}

void PlayerInput(Player& player, int input)
{

	if (player.pos.col == 0 || player.pos.col == WINDOW_COLS)
	{
		// player is at the edge of the screen
		return;
	}

	switch (input)
	{

	case KEY_LEFT:
	{

		if (player.pos.col == 1) // should be == 0, but sprite seems to get stuck if it hits the left wall for some reason
		{
			// player is at the edge of the screen, dont move further
			return;
		}

		Move(player.pos, LEFT);
	}
	break;

	case KEY_RIGHT:
	{
		if (player.pos.col == (WINDOW_COLS-player.sprites[player.curSprite].bodyRowStrings[PLAYER_HEIGHT -1].length()-1))
		{
			// player is at the edge of the screen, dont move further
			return;
		}

		Move(player.pos, RIGHT);
	}
	break;

	default:
	{
		return;
	}

	}
}






