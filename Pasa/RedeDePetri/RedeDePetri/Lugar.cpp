#include "Lugar.h"



Lugar::Lugar()
{
	vazio = true;
}

Lugar::Lugar(string id)
{
	vazio = true;
	this->id = id;
}


Lugar::~Lugar()
{
}

Token Lugar::getToken(int pos)
{
	return listaTokens[pos];
}

void Lugar::adicionarToken(Token token)
{
	listaTokens.push_back(token);
	vazio = false;
}

void Lugar::removerToken(int pos)
{
	listaTokens.erase(listaTokens.begin() + pos);
	vazio = listaTokens.empty();
}

bool Lugar::estaVazio()
{
	return vazio;
}

int Lugar::tamanho()
{
	return listaTokens.size();
}

void Lugar::mostrarId()
{
	cout << "Id do Lugar: " << id << endl;
}
