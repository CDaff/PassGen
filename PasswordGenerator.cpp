#define PASSWORD_GENERATOR_CPP

#include "PasswordGenerator.h"

//**********  Static Variables from Token Class **********

Token::TableBool Token::LastBool;

ifstream Token::SourceFile;

Token::InputType Token::InputTable[] = {
	InputUnknown,		// 00
	InputUnknown,		// 01
	InputUnknown,		// 02
	InputUnknown,		// 03
	InputUnknown,		// 04
	InputUnknown,		// 05
	InputUnknown,		// 06
	InputUnknown,		// 07
	InputUnknown,		// 08
	InputUnknown,		// 09
	InputSpace,			// 0A
	InputUnknown,		// 0B
	InputUnknown,		// 0C
	InputSpace,			// 0D
	InputUnknown,		// 0E
	InputUnknown,		// 0F
	InputUnknown,		// 10
	InputUnknown,		// 11
	InputUnknown,		// 12
	InputUnknown,		// 13
	InputSpace,			// 14
	InputUnknown,		// 15
	InputUnknown,		// 16
	InputUnknown,		// 17
	InputUnknown,		// 18
	InputUnknown,		// 19
	InputUnknown,		// 1A
	InputUnknown,		// 1B
	InputUnknown,		// 1C
	InputUnknown,		// 1D
	InputUnknown,		// 1E
	InputUnknown,		// 1F
	InputSpace,			// 20
	InputUnknown,		// 21
	InputUnknown,		// 22
	InputUnknown,		// 23
	InputUnknown,		// 24
	InputUnknown,		// 25
	InputUnknown,		// 26
	InputUnknown,		// 27
	InputUnknown,		// 2C
	InputUnknown,		// 2E
	InputUnknown,		// 3A
	InputUnknown,		// 3C
	InputUnknown,		// 3D
	InputUnknown,		// 3E
	InputUnknown,		// 3F
	InputUnknown,		// 40
	InputUnknown,		// 42
	InputUnknown,		// 43
	InputUnknown,		// 44
	InputUnknown,		// 46
	InputUnknown,		// 47
	InputUnknown,		// 48
	InputUnknown,		// 49
	InputUnknown,		// 4A
	InputUnknown,		// 4B
	InputUnknown,		// 4D
	InputUnknown,		// 4E
	InputUnknown,		// 4F
	InputUnknown,		// 51
	InputUnknown,		// 52
	InputUnknown,		// 53
	InputUnknown,		// 54
	InputUnknown,		// 57
	InputUnknown,		// 59
	InputUnknown,		// 5A
	InputUnknown,		// 5B
	InputUnknown,		// 5C
	InputUnknown,		// 5D
	InputUnknown,		// 5E
	InputUnknown,		// 5F
	InputUnknown,		// 60
	InputUnknown,		// 62
	InputUnknown,		// 63
	InputUnknown,		// 64
	InputUnknown,		// 66
	InputUnknown,		// 67
	InputUnknown,		// 68
	InputUnknown,		// 69
	InputUnknown,		// 6A
	InputUnknown,		// 6B
	InputUnknown,		// 6D
	InputUnknown,		// 6E
	InputUnknown,		// 6F
	InputUnknown,		// 71
	InputUnknown,		// 72
	InputUnknown,		// 73
	InputUnknown,		// 74
	InputUnknown,		// 77
	InputUnknown,		// 79
	InputUnknown,		// 7A
	InputUnknown,		// 7B
	InputUnknown,		// 7C
	InputUnknown,		// 7D
	InputUnknown,		// 7E
	InputUnknown,		// 7F
	InputUnknown,		// 80
	InputUnknown,		// 81
	InputUnknown,		// 82
	InputUnknown,		// 83
	InputUnknown,		// 84
	InputUnknown,		// 85
	InputUnknown,		// 86
	InputUnknown,		// 87
	InputUnknown,		// 88
	InputUnknown,		// 89
	InputUnknown,		// 8A
	InputUnknown,		// 8B
	InputUnknown,		// 8C
	InputUnknown,		// 8D
	InputUnknown,		// 8E
	InputUnknown,		// 8F
	InputUnknown,		// 90
	InputUnknown,		// 91
	InputUnknown,		// 92
	InputUnknown,		// 93
	InputUnknown,		// 94
	InputUnknown,		// 95
	InputUnknown,		// 96
	InputUnknown,		// 97
	InputUnknown,		// 98
	InputUnknown,		// 99
	InputUnknown,		// 9A
	InputUnknown,		// 9B
	InputUnknown,		// 9C
	InputUnknown,		// 9D
	InputUnknown,		// 9E
	InputUnknown,		// 9F
	InputUnknown,		// A0
	InputUnknown,		// A1
	InputUnknown,		// A2
	InputUnknown,		// A3
	InputUnknown,		// A4
	InputUnknown,		// A5
	InputUnknown,		// A6
	InputUnknown,		// A7
	InputUnknown,		// A8
	InputUnknown,		// A9
	InputUnknown,		// AA
	InputUnknown,		// AB
	InputUnknown,		// AC
	InputUnknown,		// AD
	InputUnknown,		// AE
	InputUnknown,		// AF
	InputUnknown,		// B0
	InputUnknown,		// B1
	InputUnknown,		// B2
	InputUnknown,		// B3
	InputUnknown,		// B4
	InputUnknown,		// B5
	InputUnknown,		// B6
	InputUnknown,		// B7
	InputUnknown,		// B8
	InputUnknown,		// B9
	InputUnknown,		// BA
	InputUnknown,		// BB
	InputUnknown,		// BC
	InputUnknown,		// BD
	InputUnknown,		// BE
	InputUnknown,		// BF
	InputUnknown,		// C0
	InputUnknown,		// C1
	InputUnknown,		// C2
	InputUnknown,		// C3
	InputUnknown,		// C4
	InputUnknown,		// C5
	InputUnknown,		// C6
	InputUnknown,		// C7
	InputUnknown,		// C8
	InputUnknown,		// C9
	InputUnknown,		// CA
	InputUnknown,		// CB
	InputUnknown,		// CC
	InputUnknown,		// CD
	InputUnknown,		// CE
	InputUnknown,		// CF
	InputUnknown,		// D0
	InputUnknown,		// D1
	InputUnknown,		// D2
	InputUnknown,		// D3
	InputUnknown,		// D4
	InputUnknown,		// D5
	InputUnknown,		// D6
	InputUnknown,		// D7
	InputUnknown,		// D8
	InputUnknown,		// D9
	InputUnknown,		// DA
	InputUnknown,		// DB
	InputUnknown,		// DC
	InputUnknown,		// DD
	InputUnknown,		// DE
	InputUnknown,		// DF
	InputUnknown,		// E0
	InputUnknown,		// E1
	InputUnknown,		// E2
	InputUnknown,		// E3
	InputUnknown,		// E4
	InputUnknown,		// E5
	InputUnknown,		// E6
	InputUnknown,		// E7
	InputUnknown,		// E8
	InputUnknown,		// E9
	InputUnknown,		// EA
	InputUnknown,		// EB
	InputUnknown,		// EC
	InputUnknown,		// ED
	InputUnknown,		// EE
	InputUnknown,		// EF
	InputUnknown,		// F0
	InputUnknown,		// F1
	InputUnknown,		// F2
	InputUnknown,		// F3
	InputUnknown,		// F4
	InputUnknown,		// F5
	InputUnknown,		// F6
	InputUnknown,		// F7
	InputUnknown,		// F8
	InputUnknown,		// F9
	InputUnknown,		// FA
	InputUnknown,		// FB
	InputUnknown,		// FC
	InputUnknown,		// FD
	InputUnknown,		// FE
	EndOfInput			// FF
};

Token::StateFunc Token::ConditionState[] = {
	NotYetWritten,			//	0
	UnknownInput,			//	1
	SetFileOption,			//	2
	SetPasswordSize,		//	3
	SetLowerCase,			//  4
	SetUpperCase,			//  5
	SetNumbers,				//	6
	SetSpecialCharacters,	//	7
	SetUnderscore,			//	8
	SetSpace,				//	9
	SetCharCategory,		//	10
	SetPasswordChar,		//	11
	SetPassword,			//	12
	GotEndOfFile,			//	13
	GotUnexpectedEOF,		//	14
	StartedTokenWithSpace,	//	15
};

Token::TableBool Token::StateTable[NumInputs][NumStates] = {
	//						SGC				AfterFile		AfterSize		AfterLC			AfterUC			After#			AfterSpecChar	After_			After< >		AfterCharCat	AfterPassChar
	/*	InputUnknown	*/{ 0,				0,				0,				0,				0,				0,				0,				0,				0,				0,				0, },
	/*	InputFileChoice	*/{ 2,				0,				0,				0,				0,				0,				0,				0,				0,				0,				0, },
	/*	InputSize		*/{ 0,				3,				0,				0,				0,				0,				0,				0,				0,				0,				0, },
	/*	InputLowercase	*/{ 0,				0,				4,				0,				0,				0,				0,				0,				0,				0,				0, },
	/*	InputUppercase	*/{ 0,				3,				0,				5,				0,				0,				0,				0,				0,				0,				0, },
	/*	InputNumbers	*/{ 0,				0,				4,				0,				6,				0,				0,				0,				0,				0,				0, },
	/*	InputSpecChar	*/{ 0,				0,				0,				5,				0,				7,				0,				0,				0,				0,				0, },
	/*	InputUnderscore	*/{ 0,				0,				0,				0,				6,				0,				8,				0,				0,				0,				0, },
	/*	InputSpace		*/{ 0,				0,				0,				0,				0,				7,				0,				9,				0,				0,				0, },
	/*	InputCharCat	*/{ 0,				0,				0,				0,				0,				0,				8,				0,				10,				0,				0, },
	/*	InputPassChar	*/{ 0,				0,				0,				0,				0,				0,				0,				9,				0,				11,				11 },
	/*	InputPassword	*/{ 0,				0,				0,				0,				0,				0,				0,				0,				0,				0,				12, },
	/*	EndOfInput		*/{ 0,				0,				0,				0,				0,				0,				0,				0,				0,				0,				0, }
};

// ********** Methods from Token Class ********** //

// ** HYPER-IMPORTANT ** This function contains the loop that tells us to continue through the table until TokenComplete(aka Exit) is called/returned.
Token & Token::Build()
{
	ConditionState CurrentState (StartGettingToken);
	SetTokenType(TokenUnknown);
	do {
		CurrentState = StateFunction[StateTable[GetInputBool()][CurrentState]](*this); // Sets's CurrentState's value which Queue's current input bool for usage
		} while (CurrentState != TokenComplete); // Continues fetching current input bool until CurrentState is TokenComplete

		return *this;
}

Token::ConditionState Token::NotYetWritten(Token &)
{
	cout << "You called a method which has not yet been implemented" << endl;
	return TokenComplete;
}

//---------------- Table Functions(Methods) ----------------//
/*
		Each Method in this section will have an IF statement as an extra layer of error checking
*/

//	File Input: Determines if the following values will be user input or be passed from a file
Token::ConditionState Token::SetFileOption(Token & T, bool & B)
{
	FileInput = B;

	return AfterFileChoice;
}

//	Password: Determines Password Size
Token::ConditionState Token::SetPasswordSize(Token & T, int & I)
{
	PasswordLength = I;

	return AfterPassSize;
}


//	Lowercase: false (no lowercase)
Token::ConditionState Token::SetLowerCase (Token & T)
{
	CurrElemArray = 0;

	// If Statement for an extra level of error checking
	if (Options[CurrElemArray] == true)
		return AfterLowerCase;
	else if (Options[CurrElemArray] == false)
	{
		T.SetTokenType(TokenInvalidBool);
		return StartGettingToken;
	}
		
}

//	Uppercase
Token::ConditionState Token::SetUpperCase (Token & T)
{
	CurrElemArray = 1;

	if (Options[CurrElemArray] == true)
		return AfterUpperCase;
	else if (Options[CurrElemArray] == false)
	{
		T.SetTokenType(TokenInvalidBool);
		return StartGettingToken;
	}
}

//	Numbers
Token::ConditionState Token::SetNumbers (Token & T)
{
	CurrElemArray = 2;

	if (Options[CurrElemArray] == true)
		return AfterNumbers;
	else if (Options[CurrElemArray] == false)
	{
		T.SetTokenType(TokenInvalidBool);
		return StartGettingToken;
	}
}

//	Special Characters
Token::ConditionState Token::SetSpecialCharacters (Token & T)
{
	CurrElemArray = 3;

	if (Options[CurrElemArray] == true)
		return AfterSpecialCharacters;
	else if (Options[CurrElemArray] == false)
	{
		T.SetTokenType(TokenInvalidBool);
		return StartGettingToken;
	}
}

//	Underscore
Token::ConditionState Token::SetUnderscore (Token & T)
{
	CurrElemArray = 4;

	if (Options[CurrElemArray] == true)
		return AfterUnderscore;
	else if (Options[CurrElemArray] == false)
	{
		T.SetTokenType(TokenInvalidBool);
		return StartGettingToken;
	}
}

//	Space
Token::ConditionState Token::SetSpace (Token & T)
{
	CurrElemArray = 5;

	if (Options[CurrElemArray] == true)
		return AfterSpace;
	else if (Options[CurrElemArray] == false)
	{
		T.SetTokenType(TokenInvalidBool);
		return StartGettingToken;
	}
}

//	Character Category
Token::ConditionState Token::SetCharCategory (Token &)
{
	CharCategoryChoice = rand() % (6);

	//Looped to ensure that only a selected category is chosen
	while (Options[CharCategoryChoice] != true) // +1 pushes past file input since that won't be used for characters
	{
		CharCategoryChoice = rand() % (6);
	}

	return AfterCharCat;
}

// Password Character
Token::ConditionState Token::SetPasswordChar (Token & T)
{
	switch (CharCategoryChoice)
	{
	case 0: // Lowercase
		CurrPassChar = rand() % (26 + 'a');
		T.SetCharacterType(LowercaseCharacter);
		return AfterPasswordChar;
		break;
	case 1: // Uppercase
		CurrPassChar = rand() % (26 + 'A');
		return AfterPasswordChar;
		break;
	case 2: // Numbers
		CurrPassChar = rand() % (10 + '0');
		return AfterPasswordChar;
		break;
	case 3: // Special Characters
		CurrPassChar = rand() % (13 + '!');
		return AfterPasswordChar;
		break;
	case 4: // Underscore
		CurrPassChar = '_';
		return AfterPasswordChar;
		break;
	case 5: // Space
		CurrPassChar = ' ';
		return AfterPasswordChar;
		break;
	default:
		return AfterPasswordChar;
		break;
	} // Switch Case END
}

// Sets the value for Password
Token::ConditionState Token::SetPassword(Token & T)
{
	if (CurrPassSize < PasswordLength)
	{
		Password = Password + CurrPassChar;
		CurrPassSize++;
		return AfterSpace; // loops from CharCateogory until password size is met
	}
	T.SetTokenType(TokenEndOfInput);
	return TokenComplete;
}

//	Exit due to end of a file
Token::ConditionState Token::GotEndOfFile (Token & T)
{
	T.SetTokenType(TokenEndOfInput);
	return TokenComplete;
}

//	**********	Troubleshooting Functions	**********	//

// End of File error: unexpected (faulty file?)
Token::ConditionState Token::GotUnexpectedEOF (Token & T)
{
	cout << "Got Unexpected EOF" << endl;
	//T.SetType(EndOfInputToken);
	return TokenComplete;
}

Token::ConditionState Token::StartedTokenWithSpace (Token &)
{
	return StartGettingToken;
}

Token::ConditionState Token::UnknownInput (Token & T)
{
	cout << "Got unexpected input" << endl;
	T.SetTokenType(TokenUnknown);
	return TokenComplete;
}