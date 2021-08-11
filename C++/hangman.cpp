#include <iostream>
#include <string>
#include <vector>
#include <random> // random_device
#include <algorithm>

int main() {
    std::cout << "welcome to the gallows" << std::endl;
    std::vector<std::string> wordlist = {"gangscheisse", "upcummies", "reddit", "george", "sidvicius", "simon", "ferocious", "ass"};
    std::random_device rd;
    std::string word = wordlist[rd() % wordlist.size()];
    std::cout << word << std::endl;
    int attempts = word.size();
    char user_input;
    bool present;
    std::vector<char> guessright;
    std::vector<char> guesswrong;

    while (true) {
        std::cout << "take a guess! im suffocating. if you want to save me, guess one letter from the alphabet!" << std::endl;
        std::cin >> user_input;
        
        present == false;
        for (char i : word) {
            if (user_input != i) {
                continue;
            }
            else { // letter found. we proceed to eliminating every instance of the letter and break out
                // remove every single time when matching user_input
                present = true;
                word.erase(std::remove(word.begin(), word.end(), user_input), word.end());
                break;
            }
        }

        if (present == false) { // if character not in word, decrease attempts remaining
            std::cout << "letter not in word! im dying!" << std::endl;
            guesswrong.push_back(user_input);
            attempts--;
        }
        else {
            std::cout << "u guessed a right letter." << std::endl;
            guessright.push_back(user_input);
        }
        present = false;

        std::cout << "correct letters guessed: ";
        for (char i : guessright) {
            std::cout << i << " ";
        }
        std::cout << "\n" << std::endl;
        std::cout << "wrong letters guessed: ";
        for (char i : guesswrong) {
            std::cout << i << " ";
        }
        std::cout << "\n" << std::endl;
        std::cout << "word length remaining: " << word.size() << std::endl;
        std::cout << "attempts remaining: " << attempts << std::endl;


        if (attempts == 0) { // you lose
            std::cout << "u lose. i died from asphyxia!" << std::endl;
            break;
        }
        if (word == "") { // you win
            std::cout << "u won. now untie me!" << std::endl;
            break;
        }

    }

}
