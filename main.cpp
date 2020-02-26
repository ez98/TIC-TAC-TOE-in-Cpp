#include <iostream>
#include "funcs.h"

using namespace std;

bool in_game = true;

int counter = 0;

int main() {
	cout << "\t     =======================";
	cout << "\n\t      Welcome to Tic-Tac-Toe" << endl;
	cout << "\t     =======================" << endl;
	cout << "\t         -Created by Eric" << endl;
	cout << "\t             03/25/2020" << endl;
	print_board();
	 //clear board but not print
	while (in_game) {
		if (counter > 0)
			print_board();
		while (playingGame()) 
		{
			make_move();
		}

		if (play_again()) 
		{
			playingGame();
			clear_board();
			counter += 1;
		}

		else {
			cout << "\nGoodbye!" << endl;
			in_game = false;
		}
	}




	return 0;
}