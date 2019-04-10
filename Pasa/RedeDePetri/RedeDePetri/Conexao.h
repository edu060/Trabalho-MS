#pragma once
#include "Lugar.h"

class Conexao
{
public:
	bool arcoInibidor;
	bool arcoEntrada;
	Lugar* lugar;
	int peso;

	Conexao();
	Conexao(Lugar* lugar, bool ehArcoEntrada, bool eArcoInibidor, int peso);
	~Conexao();

	bool ehArcoInibidor();
	bool ehArcoEntrada();
};

