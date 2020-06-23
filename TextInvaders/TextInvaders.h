#pragma once
# include <vector>
# include <string>
using namespace std;

const int WINDOW_COLS = 82;
const int WINDOW_ROW = 32;

const int PLAYER_START_ROW = 30;
const int PLAYER_START_COL = 41;
const int PLAYER_HEIGHT = 2;
const int PLAYER_SPRITE_STATES = 3;
const int PLAYER_MISSILE_ROW = -1; // missile init position relateive to player
const int PLAYER_MISSILE_COL = 2;  // missile init position relative to player

enum Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

// to specify the position of any entity on the screen
struct Position
{
	int row;
	int col;
};

// to store the sprite
struct Sprite
{
	vector<string> bodyRowStrings; // characters that make up the body
};

struct Player
{
	Position pos;
	vector<Sprite> sprites;
	int curSprite;    // current sprite animation state

	Sprite missile;
	Position missilePos;
	bool isFired = false;
};

