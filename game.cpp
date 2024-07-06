#include <iostream>
#include <ctime>
#include <cstdlib> 
using namespace std;


void Number_Guessing_game()
{
      int num, guess, tries;
    char menuChoice, playAgain;

    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    do
    {
        // Display menu
        cout << "NUMBER GUESSING GAME" << endl;
        cout << "************************" << endl;
        cout << "1. Start New Game" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> menuChoice;

        switch (menuChoice)
        {
            case '1':  // Start new game
                do
                {
                    num = rand() % 100 + 1;
                    tries = 0;
                    cout << "******** NUMBER GUESSING GAME ***********" << endl;

                    do
                    {
                        cout << "Enter a guess between 1 and 100: ";
                        cin >> guess;
                        tries++;

                        if (guess > num)
                        {
                            cout << "Too High!" << endl;
                        }
                        else if (guess < num)
                        {
                            cout << "Too Low!" << endl;
                        }
                        else
                        {
                            cout << "CORRECT! Your guessing number is: " << num << endl;
                            cout << "You guessed it in " << num <<endl;
                        }

                    } while (guess != num);

                    cout << "******************************************" << endl;

                    cout << "Do you want to play again? (y/n): ";
                    cin >> playAgain;

                } while (tolower(playAgain) == 'y');
                cout << "Thank you for playing!" << endl;
                break;

            case '2':  // Instructions
                cout << "Instructions:" << endl;
                cout << "1. The computer will randomly select a number between 1 and 100." << endl;
                cout << "2. You need to guess the number." << endl;
                cout << "3. After each guess, the computer will tell you if your guess is too high, too low, or correct." << endl;
                cout << "4. You can play multiple rounds until you decide to stop." << endl;
                break;

            case '3':  // Exit
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (menuChoice != '3');

}

void Rock_Paper_Scissors_Game()
{
    
    char userChoice, playAgain, menuChoice;
    string userChoiceStr, computerChoiceStr;
    int computerChoice;
    
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    do
    {
        // Display menu
        cout << "ROCK-PAPER-SCISSORS GAME" << endl;
        cout << "************************" << endl;
        cout << "1. Start New Game" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> menuChoice;

        switch (menuChoice)
        {
            case '1':  // Start new game
                do
                {
                    // Get user's choice
                    do
                    {
                        
                        cout << "************************" << endl;
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
                break;

            case '2':  // Instructions
                cout << "Instructions:" << endl;
                cout << "1. The game is played against the computer." << endl;
                cout << "2. You can choose Rock, Paper, or Scissors." << endl;
                cout << "3. The rules are as follows:" << endl;
                cout << "   - Rock beats Scissors" << endl;
                cout << "   - Scissors beats Paper" << endl;
                cout << "   - Paper beats Rock" << endl;
                cout << "4. If both choices are the same, it’s a tie." << endl;
                cout << "5. You can play multiple rounds." << endl;
                break;

            case '3':  // Exit
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (menuChoice != '3');

}



void Tic_Tac_Toe_Game()
{
    char board[3][3];
    char player;
    bool isWin, isDraw;
    char menuChoice;
    
    auto initializeBoard = [&]() {
        char initChar = '1';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = initChar++;
    };

    auto displayBoard = [&]() {
        cout << "     |     |     " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  " << endl;
            if (i < 2) cout << "_____|_____|_____" << endl << "     |     |     " << endl;
        }
        cout << "     |     |     " << endl;
    };

    auto checkWin = [&]() -> bool {
        for (int i = 0; i < 3; i++)
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;

        for (int i = 0; i < 3; i++)
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;

        return false;
    };

    auto isBoardFull = [&]() -> bool {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    };

    auto playGame = [&]() {
        initializeBoard();
        player = 'X';
        isWin = false;
        isDraw = false;

        cout << "Starting a new game of Tic-Tac-Toe!" << endl;
        while (!isWin && !isBoardFull())
        {
            displayBoard();
            int choice;
            cout << "Player " << player << ", enter your move (1-9): ";
            cin >> choice;

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O')
            {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            board[row][col] = player;
            isWin = checkWin();
            if (!isWin)
                player = (player == 'X') ? 'O' : 'X';
        }

        displayBoard();
        if (isWin)
            cout << "Player " << player << " wins!" << endl;
        else
            cout << "It's a draw!" << endl;
    };

    auto showInstructions = [&]() {
        cout << "Instructions:" << endl;
        cout << "1. The game is played on a 3x3 grid." << endl;
        cout << "2. Player 1 is 'X' and Player 2 is 'O'." << endl;
        cout << "3. Players take turns putting their marks in an empty cell." << endl;
        cout << "4. The first player to get 3 of their marks in a row (up, down, across, or diagonally) wins." << endl;
        cout << "5. If all 9 cells are filled and no player has 3 in a row, the game is a draw." << endl;
    };

    do {
        cout << "WELCOME TO TIC-TAC-TOE" << endl;
        cout << "**********************" << endl;
        cout << "1. New Game" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> menuChoice;

        switch (menuChoice)
        {
            case '1':
                playGame();
                break;
            case '2':
                showInstructions();
                break;
            case '3':
                cout << "Exiting the game. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (menuChoice != '3');
}

 
int main()
{
    //Rock_Paper_Scissors_Game();
    //Tic_Tac_Toe_Game();
    Number_Guessing_game();
}