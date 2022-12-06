#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> GetPuzzleString() {
    std::vector<std::string> outputText;

    std::ifstream file("PuzzleInput.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            outputText.emplace_back(line);
        }
    }

    return outputText;
}

std::string GetNumbers(std::string inputText) {
    size_t whitespace = inputText.find(" ");
    std::string numbersString = inputText.substr(0, whitespace);

    return numbersString;
}

int GetFirstNumber(std::string numbersString) {
    size_t firstNumberIndex = numbersString.find("-");
    std::string firstNumber = numbersString.substr(0, firstNumberIndex);

    return std::stoi(firstNumber);
}

int GetSecondNumber(std::string numbersString) {
    size_t whitespace = numbersString.find(" ");
    size_t second = numbersString.find("-");
    std::string secondNumber = numbersString.substr(second + 1, whitespace);

    return std::stoi(secondNumber);
}

auto GetCharToSearch(std::string inputText) {
    size_t whitespace = inputText.find(" ");
    size_t colon = inputText.find(":");
    auto letter = inputText.substr(whitespace + 1, colon);
    auto searchLetter = letter.substr(0, 1);

    return searchLetter[0];
}

auto GetLetterToSearch(std::string inputText) {
    size_t whitespace = inputText.find(" ");
    size_t colon = inputText.find(":");
    auto letter = inputText.substr(whitespace + 1, colon);
    auto searchLetter = letter.substr(0, 1);

    return searchLetter;
}

auto GetTextToSearch(std::string inputText) {
    size_t lastWhitespace = inputText.rfind(" ");
    auto text = inputText.substr(lastWhitespace + 1);

    return text;
}

auto rabinKarp(std::string input, string inputText) {
    long int counter = 0;
    long int i, j; // Loop iterators
    int h = 1;
    int inputHash = 0, patternHash = 0;
    const int charCount = 256;
    const int q = 101;
    bool flag = false;

    for (i = 0; i < input.length() - 1; i++)
        h = (h * charCount) % q;
    for (i = 0; i < input.length(); i++) {
        inputHash = (charCount * inputHash + inputText[i]) % q;
        patternHash = (charCount * patternHash + input[i]) % q;
    }

    for (i = 0; i <= inputText.length() - input.length(); i++) {
        if (inputHash == patternHash) {
            for (j = 0; j < input.length(); j++)
                if (inputText[i + j] != input[j])
                    break;
            if (j == input.length()) {
                // cout << "Pattern found at position: " << i << endl;
                counter++;
            }
        }
        inputHash = (charCount * (inputHash - h * inputText[i]) + inputText[i + input.length()]) % q;
        if (inputHash < 0)
            inputHash = inputHash + q;
    }

    return counter;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> PuzzleArray = GetPuzzleString();
    int ValidPasswords = 0;

    std::vector<int> minNumbersArr;
    std::vector<int> maxNumbersArr;
    std::vector<std::string> keysArr;
    std::vector<char> keysCharArr;
    std::vector<std::string> searchTextArr;

    for (int i = 0; i < PuzzleArray.size(); ++i) {
        std::string numbers = GetNumbers(PuzzleArray[i]);
        minNumbersArr.emplace_back(GetFirstNumber(numbers));
        maxNumbersArr.emplace_back(GetSecondNumber(numbers));
        keysArr.emplace_back(GetLetterToSearch(PuzzleArray[i]));
        keysCharArr.emplace_back(GetCharToSearch(PuzzleArray[i]));
        searchTextArr.emplace_back(GetTextToSearch(PuzzleArray[i]));
    }

    //////////////
    /// Part 1 ///
    //////////////
    for (int i = 0; i < PuzzleArray.size(); ++i) {
        auto matches = rabinKarp(keysArr[i], searchTextArr[i]);

        if (matches >= minNumbersArr[i] && matches <= maxNumbersArr[i]) {
            ValidPasswords++;
        }
    }

    std::cout << "Found " << ValidPasswords << " valid passwords for part 1" << endl;


    //////////////
    /// Part 2 ///
    //////////////

    int matchCount = 0;
    for (int i = 0; i < searchTextArr.size(); ++i) {
        int min = minNumbersArr[i];
        int max = maxNumbersArr[i];

        auto firstKey = searchTextArr[i][min - 1];
        auto secondKey = searchTextArr[i][max - 1];

        if ((firstKey == keysCharArr[i]) != (secondKey == keysCharArr[i])) {
            matchCount++;
        }
    }
    cout << "Found " << matchCount << " valid passwords for Part 2";

    return 0;
}
