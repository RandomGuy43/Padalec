#include "Score.h"


Score::Score()
{
	this->value = 0;
}

int Score::GetScoreValue()
{
	return this->value;
}

void Score::ScoreIncrement()
{
	value += score_step;
}

void Score::SetScoreStep(int _score_step)
{
	this->score_step = _score_step;
}
