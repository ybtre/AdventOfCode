#include "Day3.h"

void Day3::Run()
{
	vector<string> PuzzleArray = utils.GetPuzzleString("day3_input.txt");

	Part1(PuzzleArray);
	Part2(PuzzleArray);
	cout << '\n';
}

void Day3::Part1(std::vector<std::string>& PuzzleArray)
{
	string uppercase_lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::vector<char> duplicates_set{};
	vector<char> half{};
	vector<char> halftwo{};

	//for (auto rucksack : PuzzleArray) {
	for(int i = 0; i < PuzzleArray.size(); i++){
		auto rucksack = PuzzleArray[i];
		int items_count = rucksack.length();

		char duplicate_item = ' ';
		bool found_dupe = false;
		//for (int x = 0; x < items_count / 2; x++) {
		//	half.emplace_back(rucksack[x]);
		//}
		//for (int y = items_count - 1; y > (items_count / 2) - 1; y--) {
		//	halftwo.emplace_back(rucksack[y]);
		//}
		for (int item = 0; item < items_count / 2; item++) {
			for (int y = items_count - 1; y > (items_count / 2) - 1; y--) {
				if (rucksack[item] == rucksack[y]) {
					found_dupe = true;
					duplicate_item = rucksack[item];
					duplicates_set.emplace_back(duplicate_item);
					break;
				}
			}

			if (found_dupe) break;
		}
	}

	int sum = 0;
	int counter = 0;
	for (auto item : duplicates_set) {
		for (auto bukva : uppercase_lookup) {
			counter++;
			if (item == bukva) {
				sum += counter + 26;
				counter = 0;
				break;
			}
			else if (item == tolower(bukva)) {
				sum += counter;
				counter = 0;
				break;
			}
		}	
	}

	cout << "Sum in set: " << sum << '\n';
}

void Day3::Part2(std::vector<std::string>& PuzzleArray)
{
}
