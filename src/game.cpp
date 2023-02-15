//
// Created by Jan Pawlowitz on 15.02.23.
//
#include "game.h"
#include "wordList.h"
#include <iostream>
#include <vector>

void run() {
    std::cout << "Welcome to Wordle!\n" << "\033[31mcorrect Letter, correct Position\033[0m\n" << "\033[34mcorrect Letter, false Position\033[0m\n" << std::endl;

    auto word = getRandomWord();

    for (int i = 0; i <= 5; i++) {
        std::cout << "Try " << i << "/5:" << std::endl;

        auto guess = getInput();

        if (compareWords(word, guess)) {
            std::cout << "You won!" << std::endl;
            return;
        }
    }

    std::cout << "You loose! \n The word was: " << word << std::endl;
}

std::string getInput() {
    std::string input;

    while (true) {
        std::cin >> input;

        if (input.length() == 5) {
            return input;
        }

        std::cout << "Invalid input!" << std::endl;
    }
}

bool compareWords(std::string &word, std::string &guess) {
    int correctPosition = 0;
    std::string result[6];

    for (int i = 0; i < word.length(); i++) {
        std::string character(1, guess[i]);
        result[i] = character;

        if (word[i] == guess[i]) {
            correctPosition++;
            result[i] = "\033[31m" + character + "\033[0m";
            continue;
        }

        for (char c : word) {
            if (c == guess[i]) {
                result[i] = "\033[34m" + character + "\033[0m";
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        std::cout << result[i];
    }

    std::cout << std::endl;

    return correctPosition == 5;
}