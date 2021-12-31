// for input/output
#include <iostream>
// for rand()
#include <stdlib.h>
// for time()
#include <time.h>


int main ()
{
    int user_num = 0;
    int max_random = 0;
    // random seed
    srand(time(NULL));
    std::cout << "Choose a range for the numbers:" << std::endl;
    std::cin >> max_random;
    if (max_random <=0)
    {
        std::cout << "Choose a number > 0:" << std::endl;
        std::cin >> max_random;
    }
    int ran_num = rand()%max_random;
    std::cout << "Guess a number (1-"<< max_random << "):" << std::endl;
    std::cin >> user_num;
    if (user_num < 0 or user_num > max_random) {
        std::cout << "The number isn't in the correct range." ;
        std::cout << "Guess a number (1-"<< max_random << "):" << std::endl;
    }
    if (user_num == ran_num)
    {
        std::cout << "Congratulations! You guessed the correct number" << std::endl;
    }
    else {
        std::cout << "Your number isn't correct!" << std::endl;
        std::cout << "The random number was " << ran_num << std::endl;
    }
    return 0;
}
