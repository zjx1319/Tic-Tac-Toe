#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

char board[10] = { '0','1','2','3','4','5','6','7','8','9' };

void draw_board() {
	system("cls");
	cout << "-----------Welcome to Tic Tac Toe-----------" << endl;
	cout << "        Player (O)       Computer (X)       " << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	printf("  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	printf("  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	printf("  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
	cout << "     |     |     " << endl<<endl;
}

int player() {
	int m;
	cout << "Now it's your turn.Please enter the number on the gameboard." << endl;
move: cin >> m;
	if (m < 1 || m>9 || board[m] == 'O' || board[m] == 'X') {
		cout << "Invalid! Try different move" << endl;
		goto move;
	}
	else {
		board[m] = 'O';
		return m;
	}
	return -1;
}

int computer() {
	//AI algorithms is coming soon...
	int m;
	vector<int> s;
	cout << "Now it's computer's turn." << endl;
	for(int i = 1; i < 10; ++i) {
		if (board[i] != 'O' && board[i] != 'X') {
			s.push_back(i);
		}
	}
	srand(time(nullptr));
	m = s[rand() % s.size()];
	board[m] = 'X';
	return m;
}

bool isfull() {
	bool flag = true;
	for (int m = 1; m < 10; ++m) {
		if (board[m] != 'O' && board[m] != 'X') {
			flag = false;
			break;
		}
	}
	return flag;
}

bool iscomputerWin() {
	if (board[5] == 'X') {
		if (board[1] == 'X' && board[9] == 'X') {
			return true;
		}
		if (board[3] == 'X' && board[7] == 'X') {
			return true;
		}
		if (board[2] == 'X' && board[8] == 'X') {
			return true;
		}
		if (board[4] == 'X' && board[6] == 'X') {
			return true;
		}
	}
	if (board[1] == 'X') {
		if (board[2] == 'X' && board[3] == 'X') {
			return true;
		}
		if (board[4] == 'X' && board[7] == 'X') {
			return true;
		}

	}
	if (board[9] == 'X') {
		if (board[3] == 'X' && board[6] == 'X') {
			return true;
		}
		if (board[7] == 'X' && board[8] == 'X') {
			return true;
		}

	}
	return false;
}
bool isplayerWin() {
	if (board[5] == 'O') {
		if (board[1] == 'O' && board[9] == 'O') {
			return true;
		}
		if (board[3] == 'O' && board[7] == 'O') {
			return true;
		}
		if (board[2] == 'O' && board[8] == 'O') {
			return true;
		}
		if (board[4] == 'O' && board[6] == 'O') {
			return true;
		}
	}
	if (board[1] == 'O') {
		if (board[2] == 'O' && board[3] == 'O') {
			return true;
		}
		if (board[4] == 'O' && board[7] == 'O') {
			return true;
		}

	}
	if (board[9] == 'O') {
		if (board[3] == 'O' && board[6] == 'O') {
			return true;
		}
		if (board[7] == 'O' && board[8] == 'O') {
			return true;
		}

	}
	return false;
}
int main() {
	int choice, m;
	cout << "-----------Welcome to Tic Tac Toe-----------" << endl;
	cout << "        Player (O)       Computer (X)       " << endl;
	cout << "SELECT 1-> Player first | 2-> Computer first" << endl;

select: cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Player first" << endl;
		draw_board();
		m = player();
		draw_board();
		cout << "You choose " << m <<endl;
		break;
	case 2:
		cout << "Computer first" << endl;
		break;
	default:
		cout << "Invalid choice! Please enter 1 or 2" << endl;
		goto select;
	}

	while (true) {
		m = computer();
		draw_board();
		cout << "Computer choose " << m << endl;
		if (iscomputerWin()) {
			cout << R"(
  ____                            _                       _           
 / ___|___  _ __ ___  _ __  _   _| |_ ___ _ __  __      _(_)_ __  ___ 
| |   / _ \| '_ ` _ \| '_ \| | | | __/ _ \ '__| \ \ /\ / / | '_ \/ __|
| |__| (_) | | | | | | |_) | |_| | ||  __/ |     \ V  V /| | | | \__ \
 \____\___/|_| |_| |_| .__/ \__,_|\__\___|_|      \_/\_/ |_|_| |_|___/
                     |_|                                              
                                                                      )";
			cout << endl;
			break;
		}
		if (isfull()) {
			cout << R"(
 ____                     _ 
|  _ \ _ __ __ ___      _| |
| | | | '__/ _` \ \ /\ / / |
| |_| | | | (_| |\ V  V /|_|
|____/|_|  \__,_| \_/\_/ (_)
                            )";
			cout << endl;
			break;
		}

		m = player();
		draw_board();
		cout << "You choose " << m << endl;
		if (isplayerWin()) {
			cout << R"(
__   __                     _           
\ \ / /__  _   _  __      _(_)_ __  ___ 
 \ V / _ \| | | | \ \ /\ / / | '_ \/ __|
  | | (_) | |_| |  \ V  V /| | | | \__ \
  |_|\___/ \__,_|   \_/\_/ |_|_| |_|___/
                                        )";
			cout << endl;
			break;
		}
		if (isfull()) {
			cout << R"(
 ____                     _ 
|  _ \ _ __ __ ___      _| |
| | | | '__/ _` \ \ /\ / / |
| |_| | | | (_| |\ V  V /|_|
|____/|_|  \__,_| \_/\_/ (_)
                            )";
			cout << endl;
			break;
		}
	}

	cout << " Enter 1 to restart   |   Other key to exit " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		for (int i = 1; i < 10; ++i) {
			board[i] = '0' + i;
		}
		cout << "SELECT 1-> Player first | 2-> Computer first" << endl;
		goto select;
	default:
		break;
	}
	return 0;
}