#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <fstream>
#include <iostream>

using namespace std;

class Token
{
	public:

		//	**********	Enumerated Types  **********  //

		enum	Errors {
			FileWillNotOpen,
			InvalidCharacters,
			InvalidBools
		};

		// Inputs (password option restrictions) to be called ; Input at beginning for organization
		enum	InputType {
			InputUnknown,
			InputFileChoice,
			InputSize,
			InputLowerCase,
			InputUpperCase,
			InputNumbers,
			InputSpecialCharacters,
			InputUnderscore,
			InputSpace,
			InputCharCat,
			InputPassChar,
			InputPassword,
			EndOfInput,

			NumInputs
		};

		// Token Returns (errors)
		enum	TokenType
		{
			TokenEndOfInput,
			TokenUnknown,
			StateUnkownBool,
			TokenInvalid,
			TokenInvalidBool
		};

		// Character Returns (character type) ; Has Character at the end to make identificaiton when calling easier
		enum	CharacterType {
			UnknownCharacter,
			FileOrManualCharacter,
			SizeCharacter,
			LowercaseCharacter,
			UppercaseCharacter,
			NumbersCharacter,
			SpecialCharactersCharacter,
			UnderscoreCharacter,
			CharacterCateogryCharacter,

			NumTokens
		};

		// Possible States of the State Machine
		enum	ConditionState {
			TokenComplete = -1,
			StartGettingToken,
			AfterFileChoice,
			AfterPassSize,
			AfterLowerCase,
			AfterUpperCase,
			AfterNumbers,
			AfterSpecialCharacters,
			AfterUnderscore,
			AfterSpace,
			AfterCharCat,
			AfterPasswordChar,
			AfterPassword,

			NumStates
		};

		// Extra (Optional) Condtions for the password
		enum	Conditions {
			MustBeginWithNumber,
			MustBeginWithUpperChar,
			MustBeginWithLowerChar,
			MustContainSpecialCharacter
		};

	public:

		//	**********	Table Typedefs	**********  //

		typedef			bool			TableBool;
		typedef			int				State;
		typedef			ConditionState	(*StateFunc)		(Token &);
	
		//	**********	Table Control Functions	**********	//

			// To Be used with the enum  [Errors]
		static	ConditionState			NotYetWritten(Token &);
		static	ConditionState			GotEndOfFile(Token &);
		static	ConditionState			GotUnexpectedEOF(Token &);
		static	ConditionState			StartedTokenWithSpace(Token &);
		static	ConditionState			UnknownInput(Token &);

		static	InputType				InputTable[]; // Lists all inputs
		static	StateFunc				StateFunction[];

		static	TableBool				LastBool; // For Getting Bool Input
		static	ifstream				SourceFile; // UNIMPLIMENTED: Meant to automate password options with a file
		static	TableBool				StateTable[NumInputs][NumStates]; // The 2D array which acts as the State Machine

	
		//	**********	Collection & Initiateialization Functions	**********	//
	
								//	**********	Token (Con/De) structors  **********  //

								Token(); // Default Constructor
								Token(const Token &); // Token parameter
								Token(TokenType, CharacterType, char); // 
								~Token(); // Destructor

		Token &					Build(); // Creates the state machine

	public:
		InputType				GetInputBool(); // collects the current bool.
		void					Initiate(TokenType, CharacterType, char);
		void					PutBackLastChar() const; // NOT FINISHED. Intended as a way to redo the latest char if it matches a current char
		static void				SetPassedOptions(bool[], const int &); // int for size, bool array for other options

		// ----- Getters ----- //
		TokenType				GetTokenType() const;
		CharacterType			GetCharacterType() const;
		char					GetChar() const; // Function called in Main that returns the current char
		//char					GetCharValue() const;

		// ----- Setters ----- //
		void					SetTokenType(TokenType);
		void					SetCharacterType(CharacterType);
		void					SetChar(char);
		//void					SetCharValue(char);

	private:

	//	**********	Password Functions	**********	//
		
		// ----- Password Setters ----- //
		static	ConditionState				InvalidBool(Token &);
		static	ConditionState				NotYetImplemented(Token &);
		static	ConditionState				SetFileOption(Token &, bool &);
		static	ConditionState				SetPasswordSize(Token &, int &);
		static	ConditionState				SetLowerCase(Token &);
		static	ConditionState				SetUpperCase(Token &);
		static	ConditionState				SetNumbers(Token &);
		static	ConditionState				SetSpecialCharacters(Token &); //excludes <_underscore> and < space>
		static	ConditionState				SetUnderscore(Token &);
		static	ConditionState				SetSpace(Token &);
		static	ConditionState				SetCharCategory(Token &);
		static	ConditionState				SetPasswordChar(Token &);
		static	ConditionState				SetPassword(Token &);

		// ----- Password Getters ----- //
	public:
		static	string						GetPassword();

		//	**********	Data Memebers  ********** //

				TokenType				TokeType;
				CharacterType			CharType;
				char					CharValue;

		static	bool					Options[6];			// Order: Lowercase, Uppercase, Numbers, Special Chars, Underscore, Space
		static	int						CurrElemArray;		// Insures that the correct element of the Options array is selected in the setters of the state machine
		static	bool					FileInput;			//	False means manual; True means input from a file
		static	int						CharCategoryChoice; // Determines which of Option will be used for the next char in the password
		static	int						PasswordLength;		// Condition for exiting Char deciding while loop
		static	int						CurrPassSize;		// Keeps track of password size
		static	char					CurrPassChar;		// character in the password that is currently being decided
		static	string					Password;
};

// ----- Token Constructors ----- //

inline Token::Token()
{
	Initiate(TokenEndOfInput,UnknownCharacter,'a');
}

inline Token::Token(const Token & T)
{
	Initiate(TokenEndOfInput,UnknownCharacter,CharValue);
}

inline Token::Token(TokenType NewTokenType, CharacterType NewCharType, char NewCharValue)
{
	Initiate(NewTokenType, NewCharType, NewCharValue);
}

inline Token::~Token()
{
}

inline void Token::Initiate(TokenType Toke, CharacterType ChType, char CharV)
{
	TokeType = Toke;
	CharType = ChType;
	CharValue = CharV;
}

// ----- Token Setters ----- //

inline void Token::SetTokenType(TokenType T)
{
	TokeType = T;
}

inline void Token::SetCharacterType(CharacterType CT)
{
	CharType = CT;
}

inline void Token::SetChar(char C)
{
	CurrPassChar = C;
}

void Token::SetPassedOptions(bool PassedOptions[], const int & PassedOptionSize)
{
	for (int Count = 0; Count < PassedOptionSize; Count++)
	{
		Options[Count] == PassedOptions[Count]; // Pushes past the first option which is FileInput and will be handled in a different function
	}
}

// ----- Token Getters ----- //

inline Token::InputType Token::GetInputBool()
{
	if (FileInput == false)
	{
		return InputTable [LastBool = (TableBool) Options[CurrElemArray]];
	}
	else if (FileInput == true)		// This part doesn't work as I haven't implimented an iostream
		return InputTable [LastBool = (TableBool) SourceFile.get()];
}

inline Token::TokenType Token::GetTokenType() const
{
	return TokeType;
}

inline Token::CharacterType Token::GetCharacterType() const
{
	return CharType;
}

inline char Token::GetChar() const
{
	return CurrPassChar;
}

inline string Token::GetPassword()
{
	return Password;
}

#endif