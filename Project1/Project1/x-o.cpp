#include <iostream>
using namespace std;

bool cheakAvailbitiy(int);
void draw();
void replace(int, char);
bool cheakwinner();
void initializeCharacters();
char c1 = '1';
char c2 = '2';
char c3 = '3';
char c4 = '4';
char c5 = '5';
char c6 = '6';
char c7 = '7';
char c8 = '8';
char c9 = '9';
char currentplayer='X';
int main()
{
	initializeCharacters();

	while (true)
	{
		initializeCharacters();
		cout << "hello again in X-O game" << endl << endl;
		draw();

		int input;
		int counter = 0;
		while (true) {



			cout << "now "<< currentplayer << endl;
			cin >> input;
			while (!cheakAvailbitiy(input)) {
				cout << "wrong number " << endl;
				cout << "write another number" << endl;
				cin >> input;
			}
			if (counter % 2 == 0) 
			{
				currentplayer = 'X';
				replace(input, currentplayer);
				currentplayer = 'O';
			}
				else {
				
				replace(input, currentplayer);
				currentplayer = 'X';
			}
				counter++;
				draw();

			if (cheakwinner()) {
				cout << "do you want play again" << endl;
				break;
			}
				else if (counter ==9) {

				cout << "no winner " << endl;
				break;
			}
		}
		cout << "1 -continue " << endl;
		cout << "2_exit" << endl;
		cin >> input;
		if (input == 1) {
			continue;

		}
		else {
			exit(0);
		}
	}
	return 0;
}


void initializeCharacters() {
	 c1 = '1';
	 c2 = '2';
	 c3 = '3';
	 c4 = '4';
	 c5 = '5';
	 c6 = '6';
	 c7 = '7';
	 c8 = '8';
	 c9 = '9';

}

void draw()
{

	cout << "\t" << c1 << "\t|\t" << c2 << "\t|\t" << c3 << endl;;
	cout << "\t------------------------------------------"<<endl;
	cout << "\t" << c4 << "\t|\t" << c5 << "\t|\t" << c6 << endl;;
	cout << "\t------------------------------------------"<<endl;
	cout << "\t" << c7<< "\t|\t" << c8 << "\t|\t" << c9 << endl;;
	cout << endl;
}

void replace(int i,char c)
{

	switch (i)

	{
	case 1:
		c1 = c;
		break;
	case 2:
		c2 = c;
		break;
	case 3:
		c3 = c;
		break;
	case 4:
		c4 = c;
		break;
	case 5:
		c5 = c;
		break;
	case 6:
		c6 = c;
		break;
	case 7:
		c7 = c;
		break;
	case 8:
		c8 = c;
		break;
	case 9:
		c9 = c;
		break;
	}
}

bool cheakAvailbitiy(int input) 
	{
	if (input < 1 || input >9)
	return false;
		switch (input) 
		{
			case 1:
				if (c1 == '1')
					return true;
				break;
			case 2:
				if (c2 == '2')
					return true;
				break;
			case 3:
				if (c3 == '3')
					return true;
				break;
			case 4:
				if (c4 == '4')
					return true;
				break;
			case 5:
				if (c5 == '5')
					return true;
				break;
			case 6:
				if (c6 == '6')
					return true;
				break;
			case 7:
				if (c7 == '7')
					return true;
				break;
			case 8:
				if (c8 == '8')
					return true;
				break;
			case 9:
				if (c9 == '9')
					return true;
				break;
	}
			return false;
}




bool cheakXwinner()
{
	bool r1 = (c1 == 'X' && c2 == 'X' && c3 == 'X');
	bool r2 = (c4 == 'X' && c5 == 'X' && c6 == 'X');
	bool r3 = (c7 == 'X' && c8 == 'X' && c9 == 'X');

	bool cl1 = (c1 == 'X' && c4 == 'X' && c7 == 'X');
	bool cl2 = (c2 == 'X' && c5 == 'X' && c8 == 'X');
	bool cl3 = (c3 == 'X' && c2 == 'X' && c3 == 'X');

	bool di1 = (c1 == 'X' && c5 == 'X' && c9 == 'X');
	bool di2 = (c3 == 'X' && c5 == 'X' && c7 == 'X');
	if (r1 || r2 || r3 || cl1 || cl2 || cl3 || di1 || di2)
	{
		cout << "X  winner " << endl;

		return true;
	}
	return false;
}
bool cheakOwinner() {


	bool r1 = (c1 == 'O' && c2 == 'O' && c3 == 'O');
	bool r2 = (c4 == 'O' && c5 == 'O' && c6 == 'O');
	bool r3 = (c7 == 'O' && c8 == 'O' && c9 == 'O');

	bool cl1 = (c1 == 'O' && c4 == 'O' && c7 == 'O');
	bool cl2 = (c2 == 'O' && c5 == 'O' && c8 == 'O');
	bool cl3 = (c3 == 'O' && c2 == 'O' && c3 == 'O');

	bool di1 = (c1 == 'O' && c5 == 'O' && c9 == 'O');
	bool di2 = (c3 == 'O' && c5 == 'O' && c7 == 'O');
	if (r1 || r2 || r3 || cl1 || cl2 || cl3 || di1 || di2)
	{
		cout << "O  winner " << endl;

		return true;
	}

	return false;

}

bool cheakwinner() {

	return cheakXwinner() || cheakOwinner();
}