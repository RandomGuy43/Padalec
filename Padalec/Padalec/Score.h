#pragma once

ref class Score
{

public:

	Score();

	int GetScoreValue();
	void ScoreIncrement();
	void SetScoreStep(int _score_step);

private:

	// managing score counter
	int score_step;   // how many points to add after eating an apple
	int value;		// variable which store sum of points
};