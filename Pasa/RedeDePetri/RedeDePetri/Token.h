#pragma once
#include <iostream>
#include <string>


using namespace std;

class Token
{
public:
	string id;

	Token();
	~Token();
	Token(string id);
	void mostrarId();


};

