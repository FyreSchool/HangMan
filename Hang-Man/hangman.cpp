#include "hangman.h"
#include <iostream>
#include <algorithm>


Hangman::Hangman(const std::string& word, int lives)
    : wordToGuess(word), lives(lives), guessedWord(word.size(), '_') {}

// Display the current progress of the guessed word
void Hangman::displayProgress() {
    std::cout << "Current word: ";
    for (char letter : guessedWord) {
        std::cout << letter << ' ';  
    }
    std::cout << std::endl;
}

// Check if the player has won or lost
bool Hangman::isWin() const { return guessedWord == wordToGuess; }
bool Hangman::isLost() const { return lives <= 0; }

// Display stick figure based on remaining lives
void Hangman::displayStickFigure() const {
    const char* figures[7] = {
        "  \n  \n  \n  \n  \n___",   
        "  O\n  \n  \n  \n  \n___",   
        "  O\n \\|\n  \n  \n  \n___",  
        "  O\n \\|/\n  \n  \n  \n___", 
        "  O\n \\|/\n  |\n  \n  \n___", 
        "  O\n \\|/\n  |\n / \n  \n___", 
        "  O\n \\|/\n  |\n / \\\n \n___" 
    };
    std::cout << figures[6 - lives] << std::endl;
}

// Guess a letter and update the game state
bool Hangman::guessLetter(char letter) {
    letter = std::tolower(letter);  
    if (std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
        std::cout << "You already guessed this letter!" << std::endl;
        return false;
    }

    guessedLetters.push_back(letter);
    bool correct = false;

    // Check if the letter is in the word
    for (size_t i = 0; i < wordToGuess.size(); ++i) {
        if (wordToGuess[i] == letter) {
            guessedWord[i] = letter;
            correct = true;
        }
    }

    if (!correct) {
        --lives;
        std::cout << "Wrong guess! Lives remaining: " << lives << std::endl;
    }
    else {
        std::cout << "Good guess!" << std::endl;
    }

    return correct;
}

// Display guessed letters
void Hangman::displayGuessedLetters() const {
    std::cout << "Guessed letters: ";
    for (char letter : guessedLetters) {
        std::cout << letter << ' ';
    }
    std::cout << std::endl;
}