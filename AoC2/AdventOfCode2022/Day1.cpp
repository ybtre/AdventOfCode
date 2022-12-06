#include "Day1.h"

void Day1::Run()
{
	vector<string> PuzzleArray = utils.GetPuzzleString("day1_input.txt");

	for (auto line : PuzzleArray) {
		cout << line << "\n";
	}
}
