#pragma once
#include "Conexao.h"
#include <vector>
class Transicao
{
public:
	Transicao();
	Transicao(string id);
	~Transicao();


	string id;
	bool ativado;
	bool mudou;
	vector<Conexao*> listaConexaoIn;
	vector<Conexao*> listaConexaoOut;

	void inserirConexao(Conexao* conec);
	bool estaAtivado();
	
};

