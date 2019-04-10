#include "Conexao.h"



Conexao::Conexao()
{
}

Conexao::Conexao(Lugar * lugar, bool ehArcoEntrada, bool ehArcoInibidor, int peso)
{
	this->arcoInibidor = ehArcoInibidor;
	this->arcoEntrada = ehArcoEntrada;
	this->lugar = lugar;
	this->peso = peso;

}


Conexao::~Conexao()
{
}

bool Conexao::ehArcoInibidor()
{
	return arcoInibidor;
}

bool Conexao::ehArcoEntrada()
{
	return arcoEntrada;
}
