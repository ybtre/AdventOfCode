#pragma once
#include "AoCUtils.h"

class Day3
{
public:

	AoCUtils utils{};

	void Run();
	char DuplicateItem(int items_count, std::string& rucksack);
	char DuplicateItem(int elf1_count, int elf2_count, int elf3_count, std::string& rucksack1, std::string& rucksack2, std::string& rucksack3);
	void Part1(std::vector<std::string>& PuzzleArray);
	void Part2(std::vector<std::string>& PuzzleArray);

	void day4_hack(std::vector<std::string>& PuzzleArray);
	void split_str(const std::string& str, const char delim, std::vector<std::string>& out);
};
