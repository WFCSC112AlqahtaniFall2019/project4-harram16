/* Class: TicTacToe
 * Author: Addie Harrison
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
using namespace std;

int main() {
    //creating the tictac toe class
    TicTacToe game1;
    int row, column;
    int player;
    bool enter = true;
    srand(time(NULL));

    //number of players loops until valid entry
    cout << "One-player or Two-player (1 or 2): " << endl;
    cin >> player;
    while (enter == true) {
        if (player == 1 || player == 2) {
            enter = false;
        } else {
            cout << "INVALID Entry." << endl;
        }
    }

    //initial and print empty board
    game1.initializeBoard();
    game1.printBoard();

    //version 1 of game with 1 player
    if (player == 1) {
        //loop until game finishes with a win or tie because full board
        while (!game1.isBoardFull() && !game1.checkForWin()) {
            //player turn
            if (game1.getCurrentPlayerNumber() == 1) {
                cout << "Enter row:" << endl;
                cin >> row;
                cout << "Enter column:" << endl;
                cin >> column;
                //check bound of rows and columns
                if ((row != 1 && row != 2 && row != 3) || (column != 1 && column != 2 && column != 3)) {
                    cout << "INVALID Entry." << endl;
                }
                    //check if already has a mark on board in that row and column
                else if (game1.placeMark(row - 1, column - 1) == false) {
                    cout << "INVALID: You have entered a value that has already been used" << endl;
                } else {
                    game1.placeMark(row - 1, column - 1);//subtract 1 because need 0,1,2 not 1,2,3
                    game1.printBoard();
                    game1.changePlayer();
                }

            }
                //computer turn
            else {
                row = rand() % 3;
                column = rand() % 3;
                //check if already has a mark on board in that row and column
                if (game1.placeMark(row, column) == false) {
                    cout << "INVALID: You have entered a value that has already been used" << endl;
                } else {
                    cout << "Your computerized opponent has chosen: " << row << " row and " << column << " column."
                         << endl;
                    game1.placeMark(row, column);
                    game1.printBoard();
                    game1.changePlayer();
                }
            }
        }
    }

    //version 2 of game with 2 players
    if (player == 2) {
        //loop until game finishes with a win or tie because full board
        while (!game1.isBoardFull() && !game1.checkForWin()) {
            cout << "Player: " << game1.getCurrentPlayerNumber() << endl;
            cout << "Enter row: " << endl;
            cin >> row;
            cout << "Enter column: " << endl;
            cin >> column;
            //check bound of rows and columns
            if ((row != 1 && row != 2 && row != 3) || (column != 1 && column != 2 && column != 3)) {
                cout << "INVALID Entry." << endl;
            } else if (game1.placeMark(row - 1, column - 1) == false) {
                cout << "INVALID: You have entered a value that has already been used" << endl;
            } else {
                game1.placeMark(row - 1, column - 1); //subtract 1 because need 0,1,2 not 1,2,3
                game1.printBoard();
                game1.changePlayer();
            }


        }

        //Printing outcomes
        if (game1.checkForWin() == true) {
            cout << "Player " << game1.getCurrentPlayerNumber() << " wins!" << endl;
        } else {
            cout << "The board has filled, it is a tie!" << endl;
        }
    }
    return 0;
}