#include <iostream>
#include "hangman.h"
#include <cstdlib>
#include <ctime>

// Get a random word from the list
// Asked Chat for a list of random words
std::string getRandomWord() {
    std::vector<std::string> words = {
        "apple", "bridge", "candle", "dream", "flower",
        "friend", "garden", "grapes", "happy", "house",
        "light", "lunch", "mountain", "ocean", "orange",
        "planet", "rabbit", "river", "school", "season",
        "shadow", "sister", "smile", "spring", "street",
        "summer", "sunset", "teacher", "thunder", "tomato",
        "travel", "village", "window", "winter", "world",
        "forest", "island", "people", "nature", "parrot",
        "banana", "butter", "pencil", "castle", "dinner"
    };
    std::srand(std::time(0));  
    int index = std::rand() % words.size();
    return words[index];
}

int main() {
    char playAgain = 'y';  

    std::cout << "Welcome to Hangman!" << std::endl;

    while (playAgain == 'y' || playAgain == 'Y') {
        std::string word = getRandomWord();  // Get a new random word
        Hangman game(word);  

        // Game loop for the current word
        while (!game.isWin() && !game.isLost()) {
            game.displayStickFigure();  
            game.displayProgress();
            game.displayGuessedLetters();

            std::cout << "Enter a letter: ";
            char letter;
            std::cin >> letter;

            game.guessLetter(letter);
        }

        // Print the final stick figure if the player loses
        if (game.isLost()) {
            game.displayStickFigure();  
        }

        // Check the result of the game
        if (game.isWin()) {
            std::cout << "Congratulations! You guessed the word: " << word << std::endl;
        }
        else {
            std::cout << "Game over! The word was: " << word << std::endl;
        }

        // Ask if the player wants to play again
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    }

    std::cout << "Thank you for playing Hangman! Goodbye!" << std::endl;
    return 0;
}