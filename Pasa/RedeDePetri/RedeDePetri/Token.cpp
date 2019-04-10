#include "Token.h"



Token::Token()
{
}


Token::~Token()
{
}

Token::Token(string id)
{
	this->id = id;
}

void Token::mostrarId()
{
	cout << "Id do token: " << id << endl;
}
