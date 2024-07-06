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

void ticTacToeGame()
{
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char player = 'X';
    int choice;
    bool isWin = false;

    auto displayBoard = [&]() {
        cout << "     |     |     " << endl;
        cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
        cout << "     |     |     " << endl;
    };

    auto checkWin = [&]() -> bool {
        // Check rows
        for (int i = 0; i < 3; i++)
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;

        // Check columns
        for (int i = 0; i < 3; i++)
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;

        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;

        return false;
    };

    auto isDraw = [&]() -> bool {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    };

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    while (!isWin && !isDraw())
    {
        displayBoard();
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> choice;

        // Map choice to board coordinates
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Check if the move is valid
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = player;

        // Check for win or draw
        isWin = checkWin();
        if (!isWin)
            player = (player == 'X') ? 'O' : 'X';  // Switch player
    }

    displayBoard();
    if (isWin)
        cout << "Player " << player << " wins!" << endl;
    else
        cout << "It's a draw!" << endl;
}

  
int main()
{
    //Number_Guessing_game();
    //Rock_Paper_Scissors_Game();
    ticTacToeGame();
}6