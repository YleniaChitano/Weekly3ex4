#include <iostream>
#include <cstdlib> // Needed for srand ()
#include <ctime> // Needed for time (0)
#include <vector>
#include <string>

int random();
int number;

int main() {
    std::vector <std::string> player(10); // Vector for player name
    std::vector <int> NewScore(10); // Vector for saving scores
    srand(std::time(0)); // Generates a new random number, using time as a seed.
    int i{ 0 }; // Counter for player number
beginning: // Will begin from here when a new random number is needed.

    int score{ 10000 }; // Max score points
    int times{ 1 }; // Guess counter variable that increments every time the user guesses a number.
    
    int guess; // The guessed number

    std::cout << "Please enter your name\n";
   
    std::cin >> player.at(i);
    random();

    std::cout << "Try to guess the number I have thought. Please enter a number:\n";
question: // Will go back here when the guessed number is wrong.
    std::cin >> guess;


    if (guess == number) {
        char yn;
        std::cout << "\nThat's correct! You won! It took you " << times << " guess(es). " << player.at(i) << ", your score is " << score << ". \n";

        if (i > 0) {
            if (score > NewScore.at(i - 1)) {
                std::cout << "You beated the score of the previous player!\n";
            }

            else {
                std::cout << "You were not able to beat the score of the previous player :-(\n";
            }
        }

        NewScore.at(i) = score;


        for (int j = 0; j < player.size(); j++) {

            std::cout << player.at(j) << " "; // Prints out player name
            std::cout << NewScore.at(j) << std::endl; // Prints out score for player number
        }

        std::cout << "Do you want to play again (Y/N) ? \n";
        std::cin >> yn;
        yn = toupper(yn); // Makes yn case insensitive.
        if (yn == 'Y') {
            i++;
            goto beginning;
        }


    }

    else {
        times++;
        score = (score - 100);

        if (guess < number) {
            std::cout << "\nNope, try a higher number!\n";
            goto question;
        }
        else {
            std::cout << "\nNope, try a lower number!\n";
            goto question;
        }
    }

    return 0;
}

int random() {
    int difficulty;
    std::cout << "Please choose a difficulty level:\n";
    std::cout << "1 = easy(numbers 1 - 5)\n";
    std::cout << "2 = medium(numbers 1 - 10)\n";
    std::cout << "3 = hard(numbers 1 - 30)\n ";
    std::cin >> difficulty;
  
   

    if (difficulty == 1)
    {
        number = (1 + rand() % 5);
        

    }

    else if (difficulty == 2)
    {
        number = (1 + rand() % 10);
       

    }

    else if (difficulty == 3)
    {
        number = (1 + rand() % 30);
        

    }

    else
    {
        std::cout << "Sorry, that's not a valid level number.\n";
    }
    return number;
}