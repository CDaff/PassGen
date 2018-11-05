#include <string>
#include <iostream>

using namespace std;

//#include "Token.h";
#include "PasswordGenerator.h"

void Main() {

	enum MainMenu
	{

	};

	enum SwitchOptions
	{
		Menu							=	'M',
		FileInput					=	'F',
		Size							=	'S',
		LowerCase					=	'LC',
		UpperCase					=	'UC',
		Numbers						=	'N',
		SpecialCharacters	=	'C',
		Underscore				=	'Ud',
		Space							=	'Sp',
		Password					=	'Pass',
		Exit							=	'E'
	};

	//Local Variable Section
	char repeat = 'N';
	int Length = 0;
	char CurrentOption = 'a'; // will be used to store the y/n selection for each option
	//bool FileChoice;
	bool PasswordOptions [7]; // FileInput, Lowercase, Uppercase, Numbers, Special Characters, Underscore, Space

	SwitchOptions SwitchChoice = Menu;
	string SwitchSelection;
	string CurrPassChar;
	string PASSWORD;

	Token PassGen;

	do {
		system("clear");
		cout << "        ------------ RANDOM PASSWORD GENRATOR ------------" << endl << endl;

		switch (SwitchChoice)
		{
			case Menu:
				cout << " ---------- Command Legend/Menu/Options ---------- ";
				cout << "F)		File: Entering a file." << endl;
				cout << "S)		Size: Change the length of password." << endl;
				cout << "LC)	Lowercase." << endl;
				cout << "UC)	Uppercase." << endl;
				cout << "N)		Numbers." << endl;
				cout << "C)		Special Characters." << endl;
				cout << "Ud)	Underscore." << endl;
				cout << "Sp)	Space." << endl;
				cout << "Pass)	Get Password." << endl;

				cout << "Please enter your choice. ";
				cin >> SwitchSelection;

				system("clear");
				break;

			case FileInput : // FileChoice
				do {
					cout << "Are you entering manually? Yy/Nn";
					cin >> CurrentOption;

					if (CurrentOption == 'Y' || CurrentOption == 'y')
					{
						PasswordOptions[0] = true;
						SwitchChoice = Password; // skips directly to password
					}
					else if (CurrentOption == 'N' || CurrentOption == 'n')
						PasswordOptions[0] = false;

				} while (CurrentOption != 'Y' || CurrentOption != 'y' || CurrentOption != 'N' || CurrentOption != 'n');

				system("clear");
				SwitchChoice = Menu; // returns to the main menu
				break;

			case Size : // Length
				do {
					cout << "Please enter a number greater than 1 to be your password's length. ";
					cin >> Length;
				} while (Length < 1);
				system("clear");
				SwitchChoice = Menu;
				break;

			case LowerCase: // PasswordOptions [0]
				do {
					cout << "Would you like to include LOWERCASE letters (a-z) in your password? y/n";
					cin >> CurrentOption;

					if (CurrentOption == 'Y' || CurrentOption == 'y')
						PasswordOptions[1] = true;
					else if (CurrentOption == 'N' || CurrentOption == 'n')
						PasswordOptions[1] = false;

				} while (CurrentOption != 'Y' || CurrentOption != 'y' || CurrentOption != 'N' || CurrentOption != 'n');

				system("clear");
				SwitchChoice = Menu;
				break;

			case UpperCase: // 2
				do {
					cout << "Would you like to include UPPERCASE letters (A-Z) in your password? y/n";
					cin >> CurrentOption;

					if (CurrentOption == 'Y' || CurrentOption == 'y')
						PasswordOptions[1] = true;
					else if (CurrentOption == 'N' || CurrentOption == 'n')
						PasswordOptions[1] = false;

				} while (CurrentOption != 'Y' || CurrentOption != 'y' || CurrentOption != 'N' || CurrentOption != 'n');

				system("clear");
				SwitchChoice = Menu;
				break;

			case Numbers: // 3
				do {
					cout << "Would you like to include NUMBERS (0-9) in your password? y/n";
					cin >> CurrentOption;

					if (CurrentOption == 'Y' || CurrentOption == 'y')
						PasswordOptions[2] = true;
					else if (CurrentOption == 'N' || CurrentOption == 'n')
						PasswordOptions[2] = false;

				} while (CurrentOption != 'Y' || CurrentOption != 'y' || CurrentOption != 'N' || CurrentOption != 'n');

				system("clear");
				SwitchChoice = Menu;
				break;

			case SpecialCharacters: // 4
				do {
					cout << "Would you like to include SPECIAL CHARACTERS in your password? y/n";
					cin >> CurrentOption;

					if (CurrentOption == 'Y' || CurrentOption == 'y')
						PasswordOptions[3] = true;
					else if (CurrentOption == 'N' || CurrentOption == 'n')
						PasswordOptions[3] = false;

				} while (CurrentOption != 'Y' || CurrentOption != 'y' || CurrentOption != 'N' || CurrentOption != 'n');

				system("clear");
				SwitchChoice = Menu;
				break;

			case Underscore: // 5
				do {
					cout << "Would you like to include an UNDERSCORE (_) in your password? y/n";
					cin >> CurrentOption;

					if (CurrentOption == 'Y' || CurrentOption == 'y')
						PasswordOptions[4] = true;
					else if (CurrentOption == 'N' || CurrentOption == 'n')
						PasswordOptions[4] = false;

				} while (CurrentOption != 'Y' || CurrentOption != 'y' || CurrentOption != 'N' || CurrentOption != 'n');

				system("clear");
				SwitchChoice = Menu;
				break;

			case Space: // 6
				do {
					cout << "Would you like to include a SPACE ( ) in your password? y/n";
					cin >> CurrentOption;

					if (CurrentOption == 'Y' || CurrentOption == 'y')
						PasswordOptions[5] = true;
					else if (CurrentOption == 'N' || CurrentOption == 'n')
						PasswordOptions[5] = false;

				} while (CurrentOption != 'Y' || CurrentOption != 'y' || CurrentOption != 'N' || CurrentOption != 'n');

				system("clear");
				SwitchChoice = Menu;
				break;

			case Password:
				PassGen.SetPassedOptions(PasswordOptions, 6);
				PassGen.Build();

				PASSWORD = PassGen.GetPassword();

				cout << "New Password: " << PassGen.GetPassword();
				system("pause");
				SwitchChoice = Menu;
				break;

			case Exit:
				system("clear");
		}

		cout << "------------ RANDOM PASSWORD GENRATOR ------------" << endl;
		// Second Level of Checking to see if the User wants to exit program
		cout << "Would you like to repeat? Yy/Nn";
		cin >> repeat;
		system("pause");

		if (repeat != 'Y' || repeat != 'y' || repeat != 'N' || repeat != 'n')
		{
			cout << "Would you like to repeat? Y/N";
			cin >> repeat;
		}

	} while (repeat == 'Y' || repeat == 'y');
}
