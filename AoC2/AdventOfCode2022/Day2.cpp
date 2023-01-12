#include "Day2.h"

void Day2::Run()
{
	vector<string> PuzzleArray = utils.GetPuzzleString("day2_input.txt");

	Part1(PuzzleArray);
	Part2(PuzzleArray);
	cout << '\n';
}

void Day2::Part2(std::vector<std::string>& PuzzleArray) {
	int total_score = 0;
	string condition = "";
	string player_move = "";
	string opp_move = "";

	for (auto line : PuzzleArray) {
		auto opponent = line.substr(0, 1);
		auto player = line.substr(2, 1);
		if (player[0] == 'X') condition = "Lose";
		if (player[0] == 'Y') condition = "Draw";
		if (player[0] == 'Z') condition = "Win";

		if (opponent[0] == 'A') opp_move = "Rock";
		if (opponent[0] == 'B') opp_move = "Paper";
		if (opponent[0] == 'C') opp_move = "Scissors";

		if (condition == "Draw") {
			player_move = opp_move;
			total_score += 3;
		}
		else if (condition == "Win") {
			total_score += 6;
			if (opp_move == "Rock") player_move = "Paper";
			else if (opp_move == "Paper") player_move = "Scissors";
			else if (opp_move == "Scissors") player_move = "Rock";
		}
		else if (condition == "Lose") {
			total_score += 0;
			if (opp_move == "Rock") player_move = "Scissors";
			else if (opp_move == "Paper") player_move = "Rock";
			else if (opp_move == "Scissors") player_move = "Paper";
		}

		if (player_move == "Rock") total_score += 1;
		if (player_move == "Paper") total_score += 2;
		if (player_move == "Scissors") total_score += 3;
	}

	cout << "--Day 2 part 2-- -> Total score: " << total_score << endl;
}

void Day2::Part1(std::vector<std::string>& PuzzleArray)
{
	int total_score = 0;
	string player_move = "";
	string opp_move = "";

	for (auto line : PuzzleArray) {
		auto opponent = line.substr(0, 1);
		auto player = line.substr(2, 1);
		if (player[0] == 'X') player_move = "Rock";
		if (player[0] == 'Y') player_move = "Paper";
		if (player[0] == 'Z') player_move = "Scissors";

		if (opponent[0] == 'A') opp_move = "Rock";
		if (opponent[0] == 'B') opp_move = "Paper";
		if (opponent[0] == 'C') opp_move = "Scissors";

		if (player_move == "Rock") total_score += 1;
		if (player_move == "Paper") total_score += 2;
		if (player_move == "Scissors") total_score += 3;

		if (player_move == opp_move) total_score += 3;
		else if (player_move == "Rock" && opp_move == "Scissors"
			|| player_move == "Paper" && opp_move == "Rock"
			|| player_move == "Scissors" && opp_move == "Paper") total_score += 6;
	}

	cout << "--Day 2 part 1-- -> Total score: " << total_score << endl;
}
