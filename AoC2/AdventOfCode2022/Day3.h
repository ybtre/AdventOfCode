#pragma once
#include "AoCUtils.h"

class Day3
{
public:

	AoCUtils utils{};

	void Run();
	char DuplicateItem(int items_count, std::string& rucksack);
	void Part1(std::vector<std::string>& PuzzleArray);
	void Part2(std::vector<std::string>& PuzzleArray);
};

