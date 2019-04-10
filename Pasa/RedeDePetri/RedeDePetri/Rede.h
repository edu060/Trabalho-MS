#pragma once
#include "Transicao.h"
#include <vector>
class Rede
{
public:
	Rede();
	~Rede();

	std::vector<Lugar*> listaLugar;
	std::vector<Transicao*> listaTransicao;

	void inserirTransicao(Transicao* transicao);
	void inserirLugar(Lugar* lugar);
	Transicao* getTrasicao(int pos);
	Lugar* getLugar(int pos);
	
	void executarCiclo();
};

