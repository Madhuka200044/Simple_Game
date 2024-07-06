#include <iostream>
#include <ctime>
#include <cstdlib> 
using namespace std;


void Number_Guessing_game()
{
    int num;
    int guess;
    int traies = 050;

    srand(time (NULL) );
    num=(rand() %100 + 1);

    cout<< "******** NUMBER GUESSING GAME ***********"<<endl;

    do
    {
        cout<<"Enter a guess between (1 to 100) : "<<endl;
        cin>>guess;
        traies++;

        if(guess > num)
        {
            cout<<"Too High ! "<<endl;
        }
        else if(guess < num )
        {
            cout<<"Too low ! "<<endl;
        }
        else
        {
            cout<<"CORRECT ! #Your Guessing number is : "<<num<<endl;
        }

    }while(guess != num);

    cout<<"******************************************"<<endl;

}

void Rock_Paper_Scissors_Game()
{
    char userChoice, playAgain;
    string userChoiceStr, computerChoiceStr;
    int computerChoice;

    cout << "ROCK-PAPER-SCISSORS GAME" << endl;
    cout << "************************" << endl;

    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    do
    {
        // Get user's choice
        do
        {
            cout << "Choose one of the following:" << endl;
            cout << "'R' for Rock" << endl;
            cout << "'P' for Paper" << endl;
            cout << "'S' for Scissors" << endl;
            cout << "Enter your choice: ";
            cin >> userChoice;

            userChoice = tolower(userChoice);

            if (userChoice != 'r' && userChoice != 'p' && userChoice != 's')
            {
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (userChoice != 'r' && userChoice != 'p' && userChoice != 's');

        // Map user choice to string
        switch (userChoice)
        {
            case 'r': userChoiceStr = "Rock"; break;
            case 'p': userChoiceStr = "Paper"; break;
            case 's': userChoiceStr = "Scissors"; break;
        }

        // Generate computer's choice
        computerChoice = rand() % 3;
        switch (computerChoice)
        {
            case 0: computerChoiceStr = "Rock"; break;
            case 1: computerChoiceStr = "Paper"; break;
            case 2: computerChoiceStr = "Scissors"; break;
        }

        // Display choices
        cout << "You chose: " << userChoiceStr << endl;
        cout << "Computer chose: " << computerChoiceStr << endl;

        // Determine the winner
        if (userChoiceStr == computerChoiceStr)
        {
            cout << "It's a tie!" << endl;
        }
        else if ((userChoiceStr == "Rock" && computerChoiceStr == "Scissors") ||
                 (userChoiceStr == "Paper" && computerChoiceStr == "Rock") ||
                 (userChoiceStr == "Scissors" && computerChoiceStr == "Paper"))
        {
            cout << "You win!" << endl;
        }
        else
        {
            cout << "Computer wins!" << endl;
        }

        // Ask if the user wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (tolower(playAgain) == 'y');

    cout << "Thank you for playing!" << endl;
}

  
int main()
{
    //Number_Guessing_game();
    Rock_Paper_Scissors_Game();
}