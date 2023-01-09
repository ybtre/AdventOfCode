#include "Day1.h"

void Day1::Run()
{
	vector<string> PuzzleArray = utils.GetPuzzleString("day1_input.txt");

	Part1(PuzzleArray);

	Part2(PuzzleArray);

}
void Day1::Part2(std::vector<std::string>& PuzzleArray)
{
	/// <summary>
	/// part 2
	/// </summary>
	int sum_top_three = 0;
	int top_one = 0;
	int top_two = 0;
	int top_three = 0;

	int current_calories = 0;

	for (int i = 0; i < PuzzleArray.size(); i++) {
		if (PuzzleArray[i] == "" || PuzzleArray[i] == PuzzleArray.back()) {
			if (current_calories > top_one) {
				int temp_one = 0;
				temp_one = top_one;
				top_one = current_calories;
				if (temp_one > top_two) {
					int temp = top_two;
					top_two = temp_one;

					if (temp > top_three) top_three = temp;
				}
			}
			else {
				int temp_two = 0;
				if (current_calories > top_two) {
					temp_two = top_two;
					top_two = current_calories;
					if (temp_two > top_three) top_three = temp_two;
				}

				if (current_calories > top_three) top_three = current_calories;
			}
			current_calories = 0;
		}
		else {
			current_calories += stoi(PuzzleArray[i]);
		}
	}

	cout << "--- Part 2 ---" << endl;
	std::cout << "top one cal: " << top_one << "\n";
	std::cout << "top two cal: " << top_two << "\n";
	std::cout << "top three cal: " << top_three << "\n";
	std::cout << "sum: " << top_one + top_two + top_three << "\n";
}
void Day1::Part1(std::vector<std::string>& PuzzleArray)
{
	/// <summary>
	/// part 1
	/// </summary>
	int highest_calories = 0;
	int current_calories = 0;

	for (auto line : PuzzleArray) {
		if (line != "") {
			current_calories += stoi(line);
		}
		else {
			if (current_calories >= highest_calories) {
				highest_calories = current_calories;
			}
			current_calories = 0;
		}
	}

	cout << "--- Part 1 ---" << endl;
	cout << "highest cal: " << highest_calories << endl;
}

