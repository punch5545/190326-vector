#include "stdafx.h"
#include "monster.h"

std::random_device rd;
std::mt19937 randEngine(rd());

monster::monster(char * symbol, int damage, int hp, Pos pos)
	: character(symbol, damage, hp, pos)
	, dir(Direction::E0)
	, timer(0)
{
}

monster::~monster()
{
}

void monster::Update()
{
	//std::uniform_int_distribution<int>dist(0,3);
	//int rand = dist(randEngine);

	//Chrono 시간함수
	if (timeGetTime() - timer > 1000)
	{
		//uniform initialization (중괄호 초기화)
		dir = static_cast<Direction>(
			std::uniform_int_distribution<int>{0, 3}(randEngine)
			);
		timer = timeGetTime();
	}


	jump:
	switch (dir)
	{
	case Direction::N0: pos.y--;		 break;
	case Direction::NE: pos.x += 2; pos.y--; break;
	case Direction::E0: pos.x += 2;		 break;
	case Direction::SE: pos.x += 2; pos.y++; break;
	case Direction::S0: pos.y++;	     	 break;
	case Direction::SW: pos.x -= 2; pos.y++; break;
	case Direction::W0: pos.x -= 2;	      	 break;
	case Direction::NW: pos.x -= 2; pos.y--; break;
	default:break;
	}

	bool bCheck = false;
	bCheck |= pos.x <= 1;
	bCheck |= pos.x >= 40;
	bCheck |= pos.y <= 1;
	bCheck |= pos.y >= 20;
	if (bCheck) {
		unsigned int tempDir = static_cast<unsigned int>(dir);
		tempDir = (tempDir < 4) ? tempDir + 4 : tempDir - 4;
		dir = static_cast<Direction>(tempDir);
		goto jump;
	}
}
