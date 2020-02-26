#include "funcs.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>


using namespace std;

char turn{};
int choice{};
int row, column{};
bool draw;
bool _play_again = false;

char board[3][3] = { { '1', '2', '3' }, //created a 3x3 array matrix
		      { '4', '5', '6' },
		      { '7', '8', '9' } };
		/*
		==============Board Index Locations===============
		   { '0-0', '0-1', '0-2' },
	  	   { '1-0', '1-1', '1-2' },
		   { '2-0', '2-1', '2-2' }
		==================================================
		*/

void const print_board() //prints board using a nested for loop
{
	cout << "		_________________" << endl;
	for (int i = 0; i < 3; i++) {

		cout << "		     |     |		" << endl;
		for (int j = 0; j < 3; j++) {
			cout << "		  " << board[i][j] << "  |  " << board[i][j + 1] << "  |  " << board[i][j + 2] << "\n";
			break;
		}
		cout << "		_____|_____|_____" << endl;
	}

};

char rand_assign() { //this func assigns a random character. rand_int can only come out to be 0 OR 1
	srand(time(0));
	int rand_int = rand() % 2;
	if (rand_int == 0) {
		cout << "Player X goes first!" << endl;
		return 'X';
	}
	else {
		cout << "Player O goes first!" << endl;
		return 'O';
	}
}

void make_move() { // This func handles the current player and the players move and validates whether the spot is available or not.
		   // If the spot is available, then we use a switch to handle the move and assign the index location on the matrix
	if (turn != 'X' && turn != 'O')
		turn = rand_assign();
	if (turn == 'X') {
		cout << "Player X Go!: ";
		choice = get_choice();
		cout << "\n";
	}
	else if (turn == 'O') {
		cout << "Player O Go!: ";
		choice = get_choice();
		cout << "\n";
	}
	switch (choice) {
	case 1: {row = 0; column = 0; break; }
	case 2: {row = 0; column = 1; break; }
	case 3: {row = 0; column = 2; break; }
	case 4: {row = 1; column = 0; break; }
	case 5: {row = 1; column = 1; break; }
	case 6: {row = 1; column = 2; break; }
	case 7: {row = 2; column = 0; break; }
	case 8: {row = 2; column = 1; break; }
	case 9: {row = 2; column = 2; break; }
	default: {cout << "Invalid Choice!" << endl;}
	}
	if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') //Handles move and validates available space
	{
		board[row][column] = 'X';
		print_board();
		turn = 'O';
	}
	else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') 
	{
		board[row][column] = 'O';
		print_board();
		turn = 'X';
	}
	else if((turn == 'O' || turn == 'X') && (board[row][column] == 'X' || board[row][column] == 'O'))
	{
		cout << "Position is taken by Player " << board[row][column] << "!" << endl;
		cout << "Choose another position." << endl;
		make_move();
	}
	
}

bool playingGame() { //this func runs everytime a player makes a move. It checks for player wins, or tie games. Also checks if player 
	             //wants to play again
	if (_play_again) {
		_play_again = false;
		return true;
	}
	else if (player_O_won()) {
		cout << "\t     =======================";
		cout << "\n\t\t  Player O Won!\n";
		cout << "\t     =======================" << endl;
		return false;
	}
	else if (player_X_won()) {
		cout << "\t     =======================";
		cout << "\n\t\t  Player X Won!\n";
		cout << "\t     =======================" << endl;
		return false;
	}
	else if (check_for_draw()) {
		cout << "\t     =======================";
		cout << "\n\t\t It is a TIE!\n";
		cout << "\t     =======================" << endl;
		return false;
	}
	else {
		return true;
	}
}

bool player_O_won() { // scans through each possible win combinations
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') //Top Row
		return true;
	if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') //Middle Row
		return true;
	if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') //Bottom Row
		return true;
	if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') //Left Column
		return true;
	if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') //Middle Column
		return true;
	if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') //Right Column
		return true;
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') //Vertical Decline
		return true;
	if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O') //Vertical Incline
		return true;
	else
		return false;
}

bool player_X_won() {
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') //Top Row
		return true;
	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') //Middle Row
		return true;
	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') //Bottom Row
		return true;
	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') //Left Column
		return true;
	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') //Middle Column
		return true;
	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') //Right Column
		return true;
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') //Vertical Decline
		return true;
	if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') //Vertical Incline
		return true;
	else
		return false; 
}

bool check_for_draw() { //Checks if all spaces are occupied by X OR O by updating a counter variable 'space_used'
	int space_used{}; 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 'X' || board[i][j] == 'O') {
				space_used += 1;
				continue; 
			}
		}
	}
	if (space_used == 9) 
		return true;
	else
		return false;
}

int get_choice() { //this func handles the player's board choice and makes sure the player ONLY choose a int 1-9.
	int i;
	cin >> i;
	while (cin.fail() || i == 0 || i > 9) {
		cout << "Choose a number on the board!: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> i;
	}
	return i;
}

bool play_again() { //Play Again Function runs after a win or draw
	char user_choice{};
	cout << "Would you like to play again? (Y/N): " << endl;
	cin >> user_choice;
	if (tolower(user_choice) == 'y') {
		_play_again = true;
		return _play_again;
	}
	else {
		return false;
	}
}
void clear_board(int x, int y) //this func runs if a player chooses to play again. Prints an empty board.
{

	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			board[x][y] = ' ';
			board[x][y + 1] = ' ';
			board[x][y + 2] = ' ';
			break;
		}
	}

};
