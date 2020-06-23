#pragma once
#include "TextInvaders.h"
 
void DrawSprite(Sprite sprite, Position pos);
void InitPlayer(Player& player);
void Move(Position& pos, Direction direction);
void PlayerInput(Player& player, int input);
void DrawPlayer(const Player& player);
void FireMissile(Player& player);
void UpdateMissile(Player& player);
