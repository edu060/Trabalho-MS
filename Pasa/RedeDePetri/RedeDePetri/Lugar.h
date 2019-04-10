#pragma once
#include <vector>
#include "Token.h"
class Lugar
{
public:
	Lugar();
	Lugar(string id);
	~Lugar();
	
	string id;
	bool vazio;
	vector<Token> listaTokens;

	Token getToken(int pos);
	void adicionarToken(Token token);
	void removerToken(int pos);
	bool estaVazio();
	int tamanho();
	void mostrarId();
};

