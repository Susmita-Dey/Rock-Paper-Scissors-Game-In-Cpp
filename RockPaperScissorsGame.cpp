// Create Rock, Paper and Scissors Game
// Player 1: rock
// Player 2 (computer): scissors --> player 1 gets 1 point

// rock vs scissors - rock wins
// paper vs scissors - scissors wins
// paper vs rock - paper wins

#include <bits\stdc++.h>
using namespace std;

int generateRandomNumber(int n)
{
    srand(time(NULL)); //srand takes seed as an input and is defined inside "stdlib.h".
    //It is used in generating random numbers
    return rand() % n;
}

int greaterScore(char ch1, char ch2)
{
    // For rock paper scissors - Returns 1 if c1>c2 and 0 otherwise.
    // If c1==c2 it will return -1.
    if (ch2 == ch1)
    {
        return -1;
    }
    else if ((ch1 == 'r') && (ch2 == 's'))
    {
        return 1;
    }
    else if ((ch2 == 'r') && (ch1 == 's'))
    {
        return 0;
    }
    else if ((ch1 == 'p') && (ch2 == 'r'))
    {
        return 1;
    }
    else if ((ch2 == 'p') && (ch1 == 'r'))
    {
        return 0;
    }
    else if ((ch1 == 's') && (ch2 == 'p'))
    {
        return 1;
    }
    else if ((ch2 == 's') && (ch1 == 'p'))
    {
        return 0;
    }
}

void PlayingWithComputer()
{
    int playerScore = 0, compScore = 0, temp, i;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};

    printf("Welcome to the Rock, Paper, Scissors. \n");

    for (i = 0; i < 3; i++)
    {
        // Take player 1's input
        cout << "Player 1's Turn: \n";
        cout << "Choose 1 for Rock, 2 for Paper and 3 for Scissors \n";
        cin >> temp;
        getchar();
        playerChar = dict[temp - 1];
        cout << "You chose " << playerChar << "\n\n";

        // Generate computer's input
        cout << "Computer's Turn: \n";
        cout << "Choose 1 for Rock, 2 for Paper and 3 for Scissors \n";
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        cout << "Computer chose " << compChar << "\n\n";

        // Compare the Scores
        if (greaterScore(compChar, playerChar) == 1)
        {
            compScore += 1;
            cout << "Computer got it!\n\n";
        }
        else if (greaterScore(compChar, playerChar) == -1)
        {
            compScore += 1;
            playerScore += 1;
            cout << "It's a draw!\n\n";
        }
        else
        {
            playerScore += 1;
            cout << "You got it!\n\n";
        }
        cout << "You: " << playerScore << "\nComputer: " << compScore << "\n\n";
    }

    if (playerScore > compScore)
    {
        cout << "You win the game\n";
    }
    else if (playerScore < compScore)
    {
        cout << "Computer win the game\n";
    }
    else
    {
        cout << "It's a draw\n";
    }
}

void PlayingWithPlayer2()
{
    int player1Score = 0, player2Score = 0, temp, i;
    char player1Char, player2Char;
    char dict[] = {'r', 'p', 's'};

    printf("Welcome to the Rock, Paper, Scissors. \n");

    for (i = 0; i < 3; i++)
    {
        // Take player 1's input
        cout << "Player 1's Turn: \n";
        cout << "Choose 1 for Rock, 2 for Paper and 3 for Scissors \n";
        cin >> temp;
        getchar();
        player1Char = dict[temp - 1];
        cout << "You chose " << player1Char << "\n\n";

        // Take player 2's input
        cout << "Player 2's Turn: \n";
        cout << "Choose 1 for Rock, 2 for Paper and 3 for Scissors \n";
        cin >> temp;
        getchar();
        player2Char = dict[temp - 1];
        cout << "Player 2 chose " << player2Char << "\n\n";

        // Compare the Scores
        if (greaterScore(player2Char, player1Char) == 1)
        {
            player2Score += 1;
            cout << "Player 2 got it!\n\n";
        }
        else if (greaterScore(player2Char, player1Char) == -1)
        {
            player2Score += 1;
            player1Score += 1;
            cout << "It's a draw!\n\n";
        }
        else
        {
            player1Score += 1;
            cout << "Player 1 got it!\n\n";
        }
        cout << "Player 1: " << player1Score << "\nPlayer 2: " << player2Score << "\n\n";
    }

    if (player1Score > player2Score)
    {
        cout << "Player 1 win the game\n";
    }
    else if (player1Score < player2Score)
    {
        cout << "Player 2 won the game\n";
    }
    else
    {
        cout << "It's a draw\n";
    }
}

int main()
{
    int ch;
    char choice;
up:
    cout << "---------------------- Welcome To Rock Paper Game ----------------------" << endl;
    cout << "With whom you wanna play?" << endl;
    cout << "Input 1 to play with computer\n";
    cout << "Input 2 to play with another player" << endl;
    cin >> ch;

    if (ch == 1)
    {
        PlayingWithComputer();
    }
    else if (ch == 2)
    {
        PlayingWithPlayer2();
    }
    else
    {
        cout << "Wrong Input! Please Enter Correctly!!!" << endl;
        goto up;
    }

    cout << "Do you wanna play again?\nInput y for yes and n for no." << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        goto up;
    }
    else
    {
        cout << "\n\n-----------!!Come later again to play!!-----------\n\n";
    }

    return 0;
}