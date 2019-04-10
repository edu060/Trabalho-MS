#include "Transicao.h"



Transicao::Transicao()
{
	mudou = false;
}

Transicao::Transicao(string id)
{
	mudou = false;
	this->id = id;
}


Transicao::~Transicao()
{
}

void Transicao::inserirConexao(Conexao * conec)
{
	if (conec->ehArcoEntrada())
		listaConexaoIn.push_back(conec);
	else
		listaConexaoOut.push_back(conec);
}

bool Transicao::estaAtivado()
{
	for (auto &conecIn : listaConexaoIn)
	{

		if (!conecIn->ehArcoInibidor())
		{
			if (conecIn->lugar->tamanho() < conecIn->peso)
				ativado = false;
			else
			{
				if (ativado == false)
					mudou = true;
				ativado = true;
			}
		}
		else
		{
			if (conecIn->lugar->estaVazio() == false)
				ativado = false;
			else
			{
				if (ativado == false)
					mudou = true;
				ativado = true;
			}
		}
	}

	return ativado;
}
