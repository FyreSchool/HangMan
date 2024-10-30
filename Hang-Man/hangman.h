#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

class Hangman {
private:
    std::string wordToGuess;
    std::string guessedWord;
    int lives;
    std::vector<char> guessedLetters;

public:
    
    Hangman(const std::string& word, int lives = 6);

    // Function to display current progress
    void displayProgress();

    // Check if player has won or lost
    bool isWin() const;
    bool isLost() const;

    // Guess a letter
    bool guessLetter(char letter);

    // Display guessed letters and stick figure
    void displayGuessedLetters() const;
    void displayStickFigure() const;  
};

#endif // HANGMAN_H