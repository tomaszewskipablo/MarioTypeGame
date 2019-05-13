#pragma once
class GameInfo
{
	int coins=0;
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
	void increseCoins() { coins++; }
};

