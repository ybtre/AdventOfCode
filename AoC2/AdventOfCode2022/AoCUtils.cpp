#include "AoCUtils.h"

vector<string> AoCUtils::GetPuzzleString(string input_file_name)
{
    vector<string> outputText;

    ifstream file(input_file_name);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            outputText.emplace_back(line);
        }
    }

    return outputText;
}
