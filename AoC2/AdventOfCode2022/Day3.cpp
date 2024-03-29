#include "Day3.h"

void Day3::Run()
{
	vector<string> PuzzleArray = utils.GetPuzzleString("day3_input.txt");

	cout << "--- Day 3 ---" << '\n';

	Part1(PuzzleArray);
	Part2(PuzzleArray);
	cout << '\n';
}

char Day3::DuplicateItem(int items_count, std::string& rucksack)
{
	char duplicate_item = ' ';
	for (int item = 0; item < items_count / 2; item++) {
		for (int y = items_count - 1; y > (items_count / 2) - 1; y--) {
			if (rucksack[item] == rucksack[y]) {
				duplicate_item = rucksack[item];
				return duplicate_item;
			}
		}
	}

	return duplicate_item;
}

char Day3::DuplicateItem(int elf1_count, int elf2_count, int elf3_count, std::string& rucksack1, std::string& rucksack2, std::string& rucksack3)
{
	char duplicate_item = ' ';
	vector<char> duplicate_items{};
	for (int i = 0; i < elf1_count; i++) {
		for (int j = 0; j < elf2_count; j++) {
			if (rucksack1[i] == rucksack2[j]) {
				duplicate_items.emplace_back(rucksack1[i]);
			}
		}
	}

	for (int i = 0; i < duplicate_items.size(); i++) {
		for (int j = 0; j < elf3_count; j++) {
			if (duplicate_items[i] == rucksack3[j]) {
				duplicate_item = duplicate_items[i];
				return duplicate_item;
			}
		}
	}

	return duplicate_item;
}

void Day3::Part1(std::vector<std::string>& PuzzleArray)
{
	string uppercase_lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::vector<char> duplicates_set{};
	vector<char> half{};
	vector<char> halftwo{};

	for (int i = 0; i < PuzzleArray.size(); i++) {
		auto rucksack = PuzzleArray[i];
		int items_count = static_cast<int>(rucksack.length());

		auto dupe_item = DuplicateItem(items_count, rucksack);
		if (dupe_item != ' ') duplicates_set.emplace_back(dupe_item);
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

	cout << "Part 1 --- Sum in set: " << sum << '\n';
}

void Day3::Part2(std::vector<std::string>& PuzzleArray)
{
	string uppercase_lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::vector<char> duplicates_set{};

	for (int i = 0; i < PuzzleArray.size(); i += 3) {
		std::vector<std::string> elves{};
		elves.emplace_back(PuzzleArray[i]);
		elves.emplace_back(PuzzleArray[i + 1]);
		elves.emplace_back(PuzzleArray[i + 2]);

		int items_count[3]{};
		items_count[0] = static_cast<int>(elves[0].size());
		items_count[1] = static_cast<int>(elves[1].size());
		items_count[2] = static_cast<int>(elves[2].size());

		auto dupe_item = DuplicateItem(
			items_count[0],
			items_count[1],
			items_count[2],
			elves[0],
			elves[1],
			elves[2]);
		if (dupe_item != ' ') duplicates_set.emplace_back(dupe_item);
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

	cout << "Part 2 --- Sum in set: " << sum << '\n';
}