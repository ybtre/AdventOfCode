#include "Day4.h"

void Day4::Run()
{
	vector<string> PuzzleArray = utils.GetPuzzleString("day4_input.txt");

	cout << "--- Day 4 ---" << '\n';

	Part1(PuzzleArray);
	Part2(PuzzleArray);
	cout << '\n';
}

void Day4::Part1(vector<string>& PuzzleArray) {
	int total = 0;

	for (auto& input : PuzzleArray) {
		//vector<string> pairs;
		string pairs[2] = { "0", "0" };
		SplitStr(input, ',', pairs);

		string first_pair[2] = { "0", "0" };
		SplitStr(pairs[0], '-', first_pair);

		string second_pair[2] = { "0", "0" };
		SplitStr(pairs[1], '-', second_pair);

		if (stoi(first_pair[0]) <= stoi(second_pair[0])
			&& stoi(first_pair[1]) >= stoi(second_pair[1])) {
			total++;
		}
		else if (stoi(first_pair[0]) >= stoi(second_pair[0])
			&& stoi(first_pair[1]) <= stoi(second_pair[1])) {
			total++;
		}
	}

	cout << "Part 1 --- Total: " << total << '\n';
}

void Day4::Part2(vector<string>& PuzzleArray)
{
	int total = 0;

	for (auto& input : PuzzleArray) {
		//vector<string> pairs;
		string pairs[2] = { "0", "0" };
		SplitStr(input, ',', pairs);

		string first_pair[2] = { "0", "0" };
		SplitStr(pairs[0], '-', first_pair);

		string second_pair[2] = { "0", "0" };
		SplitStr(pairs[1], '-', second_pair);

		if (stoi(first_pair[0]) >= stoi(second_pair[0]) && stoi(first_pair[0]) <= stoi(second_pair[1])) {
			total++;
		}
		else if (stoi(first_pair[1]) >= stoi(second_pair[0]) && stoi(first_pair[1]) <= stoi(second_pair[1])) {
			total++;
		}
		else if (stoi(second_pair[0]) >= stoi(first_pair[0]) && stoi(second_pair[0]) <= stoi(first_pair[1])) {
			total++;
		}
		else if (stoi(second_pair[1]) >= stoi(first_pair[0]) && stoi(second_pair[1]) <= stoi(first_pair[1])) {
			total++;
		}
	}

	cout << "Part 2 --- Total: " << total << '\n';
}

void Day4::SplitStr(const string& str, const char delim, vector<string>& out)
{
	// create a stream from the string
	stringstream s(str);

	string s2;
	while (getline(s, s2, delim))
	{
		out.push_back(s2); // store the string in s2
	}
}

void Day4::SplitStr(const string& str, const char delim, string* out) {
	// create a stream from the string
	stringstream sstream(str);

	string splitstr;
	while (getline(sstream, splitstr, delim))
	{
		if (out[0] == "0") {
			out[0] = splitstr;
		}
		else {
			out[1] = splitstr;
		}
	}
}