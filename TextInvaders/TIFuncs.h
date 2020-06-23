#pragma once
#include "TextInvaders.h"
 
void DrawSprite(Sprite sprite, Position pos);
void InitPlayer(Player& player);
void Move(Position& pos, Direction direction);
void PlayerInput(Player& player, int input);
