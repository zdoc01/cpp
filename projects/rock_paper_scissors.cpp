#include <iostream>
#include <map>
#include <string>
#include <vector>

/**
 The logic:
    Scissors cuts Paper.
    Paper covers Rock.
    Rock crushes Lizard.
    Lizard poisons Spock.
    Spock smashes Scissors.
    Scissors decapitate Lizard.
    Lizard eats Paper.
    Paper disproves Spock.
    Spock vaporizes Rock.
    (and as it always has) Rock crushes Scissors.

 So:
    rock
        > scissors
        > lizard
        < paper
        < spock

    paper
        > rock
        > spock
        < scissors
        < lizard

    scissors
        > paper
        > lizard
        < rock
        < spock

    lizard
        > spock
        > paper
        < scissors
        < rock

    spock
        > scissors
        > rock
        < lizard
        < paper
*/

enum options
{
    rock = 1,
    paper,
    scissors,
    lizard,
    spock
};

std::map<options, std::string> options_map = {
    {rock, "rock"}, {paper, "paper"}, {scissors, "scissors"}, {lizard, "lizard"}, {spock, "spock"}};

bool is_winner(int user, int computer)
{
    switch (user)
    {
    case rock:
        return computer == scissors || computer == lizard;
    case paper:
        return computer == rock || computer == spock;
    case scissors:
        return computer == paper || computer == lizard;
    case lizard:
        return computer == paper || computer == spock;
    case spock:
        return computer == scissors || computer == rock;
    default:
        return false;
    }
}

int main()
{
    // Use current time as seed for random generator
    // Should only be seeded once, before any calls to `rand`, at start of program
    std::srand(time(0));

    int user_selection;

    std::cout << "=================================\n";
    std::cout << "rock paper scissors lizard spock!\n";
    std::cout << "=================================\n";

    std::cout << "1 = rock\n";
    std::cout << "2 = paper\n";
    std::cout << "3 = scissors\n";
    std::cout << "4 = lizard\n";
    std::cout << "5 = spock\n";

    std::cout << "Enter your selection: ";
    std::cin >> user_selection;
    std::cout << std::endl;

    // The rand() function is used to generate random numbers in the range [0, RAND_MAX).
    // If random numbers are generated with rand() without first calling srand(), the
    // program will create the same sequence of numbers each time it runs.
    int computer_selection = std::rand() % 5 + 1; // 1 - 5

    std::cout << "Your selection: " << options_map[(options)user_selection] << std::endl;
    std::cout << "Computer selection: " << options_map[(options)computer_selection] << std::endl;
    std::cout << std::endl;

    if (user_selection == computer_selection)
    {
        std::cout << "It's a tie! Close one.";
    }
    else if (is_winner(user_selection, computer_selection))
    {
        std::cout << "Congratulations! You won!";
    }
    else
    {
        std::cout << "Awe shucks, you lost.";
    }

    std::cout << std::endl;

    return 0;
}