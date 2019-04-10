#include "Rede.h"
#include "Conexao.h"
#include "Lugar.h"
#include "Transicao.h"
#include "Token.h"
#include <vector>
int main()
{
	

	Rede petri;

	petri.inserirLugar(new Lugar("posicao0"));
	petri.inserirLugar(new Lugar("posicao1"));
	petri.inserirLugar(new Lugar("posicao2"));
	petri.inserirLugar(new Lugar("posicao3"));
	petri.inserirLugar(new Lugar("posicao4"));
	petri.inserirLugar(new Lugar("posicao5"));

	petri.inserirTransicao(new Transicao("transicao0"));
	petri.inserirTransicao(new Transicao("transicao1"));
	petri.inserirTransicao(new Transicao("transicao2"));

	petri.getTrasicao(0)->inserirConexao(new Conexao(petri.getLugar(0), true, true, 1));
	petri.getTrasicao(0)->inserirConexao(new Conexao(petri.getLugar(1), true, false, 1));
	petri.getTrasicao(0)->inserirConexao(new Conexao(petri.getLugar(2), true, false, 1));
	petri.getTrasicao(0)->inserirConexao(new Conexao(petri.getLugar(4), false, false, 1));

	petri.getTrasicao(1)->inserirConexao(new Conexao(petri.getLugar(2), true, false, 1));
	petri.getTrasicao(1)->inserirConexao(new Conexao(petri.getLugar(4), false, false, 2));

	petri.getTrasicao(2)->inserirConexao(new Conexao(petri.getLugar(3), true, false, 3));
	petri.getTrasicao(2)->inserirConexao(new Conexao(petri.getLugar(4), true, false, 1));
	petri.getTrasicao(2)->inserirConexao(new Conexao(petri.getLugar(5), false, false, 1));

	Token token;

	petri.getLugar(1)->adicionarToken(token);
	petri.getLugar(1)->adicionarToken(token);
	petri.getLugar(2)->adicionarToken(token);
	petri.getLugar(3)->adicionarToken(token);
	petri.getLugar(3)->adicionarToken(token);
	petri.getLugar(3)->adicionarToken(token);
	petri.getLugar(3)->adicionarToken(token);
	
	cout << "Inicio: " << endl;
	/*for (int i = 0; i < 6; i++)
	{
		cout << "Lugar(" << i << "): ";

		if (!petri.getLugar(i)->estaVazio())
			cout << petri.getLugar(i)->tamanho() << endl;
		else
			cout << endl;
	}
	petri.executarCiclo();
	cout << "\n\n";
	for (int i = 0; i < 6; i++)
	{
		cout << "Lugar(" << i << "): ";

		if (!petri.getLugar(i)->estaVazio())
			cout << petri.getLugar(i)->tamanho() << endl;
		else
			cout << endl;
	}
	petri.executarCiclo();
	cout << "\n\n";	for (int i = 0; i < 6; i++)
	{
		cout << "Lugar(" << i << "): ";

		if (!petri.getLugar(i)->estaVazio())
			cout << petri.getLugar(i)->tamanho() << endl;
		else
			cout << endl;
	}
	cout << "\n\n";*/

	petri.executarCiclo();
	cout << "\nLugar(0): ";
	if (!petri.getLugar(0)->estaVazio())
		cout << petri.getLugar(0)->tamanho();
	cout << "\nLugar(1): ";
	if (!petri.getLugar(1)->estaVazio())
		cout << petri.getLugar(1)->tamanho();
	cout << "\nLugar(2): ";
	if (!petri.getLugar(2)->estaVazio())
		cout << petri.getLugar(2)->tamanho();
	cout << "\nLugar(3): ";
	if (!petri.getLugar(3)->estaVazio())
		cout << petri.getLugar(3)->tamanho();
	cout << "\nLugar(4): ";
	if (!petri.getLugar(4)->estaVazio())
		cout << petri.getLugar(4)->tamanho();
	cout << "\nLugar(5): ";
	if (!petri.getLugar(5)->estaVazio())
		cout << petri.getLugar(5)->tamanho();

	petri.executarCiclo();

	cout << "\n\n\n";

	cout << "\nLugar(0): ";
	if (!petri.getLugar(0)->estaVazio())
		cout << petri.getLugar(0)->tamanho();
	cout << "\nLugar(1): ";
	if (!petri.getLugar(1)->estaVazio())
		cout << petri.getLugar(1)->tamanho();
	cout << "\nLugar(2): ";
	if (!petri.getLugar(2)->estaVazio())
		cout << petri.getLugar(2)->tamanho();
	cout << "\nLugar(3): ";
	if (!petri.getLugar(3)->estaVazio())
		cout << petri.getLugar(3)->tamanho();
	cout << "\nLugar(4): ";
	if (!petri.getLugar(4)->estaVazio())
		cout << petri.getLugar(4)->tamanho();
	cout << "\nLugar(5): ";
	if (!petri.getLugar(5)->estaVazio())
		cout << petri.getLugar(5)->tamanho();
	petri.executarCiclo();

	cout << "\n\n\n";

	cout << "\nLugar(0): ";
	if (!petri.getLugar(0)->estaVazio())
		cout << petri.getLugar(0)->tamanho();
	cout << "\nLugar(1): ";
	if (!petri.getLugar(1)->estaVazio())
		cout << petri.getLugar(1)->tamanho();
	cout << "\nLugar(2): ";
	if (!petri.getLugar(2)->estaVazio())
		cout << petri.getLugar(2)->tamanho();
	cout << "\nLugar(3): ";
	if (!petri.getLugar(3)->estaVazio())
		cout << petri.getLugar(3)->tamanho();
	cout << "\nLugar(4): ";
	if (!petri.getLugar(4)->estaVazio())
		cout << petri.getLugar(4)->tamanho();
	cout << "\nLugar(5): ";
	if (!petri.getLugar(5)->estaVazio())
		cout << petri.getLugar(5)->tamanho();
	//petri.executarCiclo();
	 
	cout << "\n\n\n";

	


	//cout << "Lugar(0): ";
	//if (!petri.getLugar(0)->estaVazio())
	//	cout << petri.getLugar(0)->tamanho() << endl;

	system("pause");
	return 0;

}