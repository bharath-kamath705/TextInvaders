#include "TextInvaders.h"
#include "curses.h"
#include "TIFuncs.h"

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

void DrawPlayer(const Player& player)
{
	DrawSprite(player.sprites[player.curSprite], player.pos);

	if (player.isFired)
	{
		DrawSprite(player.missile, player.missilePos);
	}

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

	player.missile.bodyRowStrings.push_back("|");
}

void PlayerInput(Player& player, int input)
{
	// get move/fire missile input from player
	// update player and missile positions

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

	case ' ':
	{
		FireMissile(player);
	}

	default:
	{

	}


	}
}

void FireMissile(Player& player)
{
	if (!player.isFired)
	{
		player.missilePos.col = player.pos.col + PLAYER_MISSILE_COL;
		player.missilePos.row = player.pos.row + PLAYER_MISSILE_ROW;
		player.isFired = true;
	}

}

void UpdateMissile(Player& player)
{
	if (player.isFired)
	{
		if (player.missilePos.row <= 0)
		{
			player.isFired = false;
			return;
		}

		else
		{
			player.missilePos.row--;
		}
	}
}






