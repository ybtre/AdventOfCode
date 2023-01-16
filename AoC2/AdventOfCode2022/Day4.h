#pragma once
#include "AoCUtils.h"

class Day4
{
public:

	AoCUtils utils{};

	void Run();
	void Part1(vector<string>& PuzzleArray);
	void Part2(vector<string>& PuzzleArray);

	void SplitStr(const string& str, const char delim, vector<string>& out);
	void SplitStr(const string& str, const char delim, string* out);
};