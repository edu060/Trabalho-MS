#include "Rede.h"



Rede::Rede()
{
}


Rede::~Rede()
{
}

void Rede::inserirTransicao(Transicao * transicao)
{
	listaTransicao.push_back(transicao);
}

void Rede::inserirLugar(Lugar* lugar)
{
	listaLugar.push_back(lugar);
}

Transicao* Rede::getTrasicao(int pos)
{
	return listaTransicao[pos];
}

Lugar* Rede::getLugar(int pos)
{
	return listaLugar[pos];
}

void Rede::executarCiclo()
{
	Token novoToken;

	for (auto &transicao : listaTransicao)
	{
		if (transicao->estaAtivado())
		{ 
			if (transicao->mudou == false)
			{
				for (auto &conecIn : transicao->listaConexaoIn)
				{
					if (!conecIn->lugar->estaVazio())
					{
						for (int i = 0; i < conecIn->peso; i++)
						{
							conecIn->lugar->removerToken(0);
						}
					}
				}

				for (auto &conecOut : transicao->listaConexaoOut)
				{
					for (int i = 0; i < conecOut->peso; i++)
					{
						conecOut->lugar->adicionarToken(novoToken);
					}
				}
			}
		}
		
		//transicao->ativado = true;
		transicao->mudou = false;
	}
}
