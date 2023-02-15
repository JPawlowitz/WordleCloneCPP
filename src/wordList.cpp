//
// Created by Jan Pawlowitz on 15.02.23.
//
#include "wordList.h"
#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::string> words;

void loadWords() {
    std::ifstream textFile("/Users/jan/CLionProjects/WordleCloneCPP/src/assets/words_alpha.txt");
    std::string currentLine;

    while(std::getline(textFile, currentLine)) {
        if (currentLine.length() == 6) {
            words.push_back(currentLine);
        }
    }

    textFile.close();
}

std::string getRandomWord() {
    std::srand(time(0));
    unsigned int randomIndex = std::rand() % words.size();
    return words[randomIndex];
}