#include <string>
#include <iostream>

using namespace std;

//#include "Token.h";


void Main() {

	enum MainMenu
	{
		PasswordOptions,
		CreatePassword,
		Exit
	};

	//Local Variable Section
	char repeat = 'N';
	int Length = 0;
	char CurrentOption = 'a'; // will be used to store the y/n selection for each option
							  //bool FileChoice;

	MainMenu SwitchChoice = Menu;
	string SwitchSelection;

	do {
		system("clear");
		cout << "        ------------ RANDOM PASSWORD GENRATOR ------------" << endl << endl;

		switch (SwitchChoice)
		{
		case Menu:
			std::cout << " ---------- Main Menu ---------- ";
			std::cout << "1) Alter Password Restrictions" << endl;
			std::cout << "2) Generate Password" << endl;
			std::cout << "3) " << endl;
			std::cout << "4) " << endl;
			std::cout << "5) Generate Password" << endl;
			std::cout << "6) RESET" << endl;
			std::cout << "0) Exit" << endl;

			cout << "Please enter your choice. ";
			cin >> SwitchSelection;

			system("clear");
			break;
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