#ifndef GENERIC_PASSWORD_H
#define GENERIC_PASSWORD_H

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

	// Inputs to be called ; Input at beginning for organization
	enum	InputType {
		InputUnknown,
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

	// Character Returns (character type) ; Has Character at the end to make identificaiton easier
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

	// Pushes to next state
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

	private:

	template <class T>
	struct GenericChar
	{
		T Char;
		CharacterType Char_Type;
		TokenType Token_Type;
	};

	template <class T>
	struct GenericPassword
	{
		GenericChar Char;
		int Pass_Length;
		GenericChar Passwords[Pass_Length][5]; // Password_Length will be dynamic, and will have 5 passwords to choose from
											   /*
											   [X] -->
											   [Y]	 P	 A	 S	 S	 W	 O	 R	 D	 0
											   |	 P	 A	 S	 S	 W	 O	 R	 D	 1
											   v	 P	 A	 S	 S	 W	 O	 R	 D	 2
											   */
	};

	public:

	//	**********	Table Typedefs	**********  //

	typedef			bool			TableBool;
	typedef			int				State;
	typedef			ConditionState(*StateFunc)		(Token &);

	//	**********	Table Control Functions	**********	//

	static	ConditionState			NotYetWritten(Token &);
	static	ConditionState			GotEndOfFile(Token &);
	static	ConditionState			GotUnexpectedEOF(Token &);
	static	ConditionState			StartedTokenWithSpace(Token &);
	static	ConditionState			UnknownInput(Token &);

	static	InputType				InputTable[]; // Lists all inputs
	static	StateFunc				StateFunction[];

	static	TableBool				LastBool; // For Getting Bool Input
	static	ifstream				SourceFile;
	static	TableBool				StateTable[NumInputs][NumStates];

	//	**********	Collection & Initiateialization Functions	**********	//

	//	**********	Token (Con/De) structors  **********  //

	Token(); // Default Constructor
	Token(const Token &); // Token parameter
	Token(TokenType, CharacterType, char); // 
	~Token(); // Destructor

	Token &					Build();

	public:
	InputType				GetInputBool();
	void					Initiate(TokenType, CharacterType, char);
	void					PutBackLastBool() const;
	static void				SetPassedOptions(bool[], const int &); // int for size

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

	template <class T>
	GenericChar				GenChar;
	template <class T>
	GenericPassword			GenPassword;

	TokenType				TokeType;
	CharacterType			CharType;
	char					CharValue;

	static	bool					Options[6]; // Order: Lowercase, Uppercase, Numbers, Special Chars, Underscore, Space
	static	int						CurrElemArray;
	static	bool					FileInput;	//	False means manual; True means input from a file
	static	int						CharCategoryChoice; // Determines which of Option will be used for the next char in the password
	static	int						PasswordLength; // Condition for exiting Char deciding while loop
	static	int						CurrPassSize; // Keeps track of password size
	static	char					CurrPassChar; // character in the password that is currently being decided
	static	string					Password;
};

// ----- Token Constructors ----- //

inline Token::Token()
{
	Initiate(TokenEndOfInput, UnknownCharacter, 'a');
}

inline Token::Token(const Token & T)
{
	Initiate(TokenEndOfInput, UnknownCharacter, CharValue);
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
		Options[Count] = PassedOptions[Count]; // Pushes past the first option which is FileInput and will be handled in a different function
	}
}

// ----- Token Getters ----- //

inline Token::InputType Token::GetInputBool()
{
	if (FileInput == false)
	{
		return InputTable[LastBool = (TableBool)Options[CurrElemArray]];
	}
	else if (FileInput == true)
		return InputTable[LastBool = (TableBool)SourceFile.get()];
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