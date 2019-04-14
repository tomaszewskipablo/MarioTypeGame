#pragma once
class GameInfo
{
	int coins;
	int time;
	int score;
public:
	GameInfo();
	~GameInfo();

	void reset()
	{
		coins = 0;
		time = 0;
		score = 0;
	}
};

