#include <iostream>
#include <windows.h>
#include <climits>
using namespace std;

#define MAX 30

//Nome: João Victor Lima Venceslau


struct Pilha
{
	int qtde;
	int elementos[MAX];
};

Pilha* init()
{
	Pilha *p = new Pilha();
	p->qtde = 0;
	return p;
}

int isEmpty(Pilha *p)
{
	return (p->qtde == 0);
}

int count(Pilha *p)
{
	return (p->qtde);
}

int push(Pilha *p, int v)
{
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar)
	{
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

int pop(Pilha *p)
{
	int podeDesempilhar = (p->qtde > 0);
	int v = -1;
	if (podeDesempilhar)
	{
		v = p->elementos[p->qtde - 1];
		p->qtde--;
	}
	return v;
}

void print(Pilha *p)
{
	cout << "--------------------------" << endl;
	cout << "-- Qtde: " << count(p) << " ------------" << endl;
	cout << "--------------------------" << endl;
	for(int i = p->qtde - 1; i >= 0; --i)
	{
		cout << p->elementos[i] << endl;
	}
	cout << "--------------------------" << endl;
}

int topo(Pilha *p)
{
	return p->elementos[p->qtde - 1];
}



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
	Pilha *pilhaPar = init();
	Pilha *pilhaImpar = init();
	int valorAnterior = INT_MIN;

cout << "Digite 30 números em ordem crescente:\n" << endl;

	int contador = 0;

	for(int i = 0; i < 30; i++)
	{
		int digito;
		while (true)
		{
			string entrada;
			cout << "Digite um número: ";
			getline(cin, entrada);
			cout << endl;
			if(entrada.empty())
			{
				cout << "O número não pode ser vazio!" << endl;
				cout << endl;
				continue;
			}

			if(entrada == "-")
			{
				cout << "Número inválido!" << endl;
				cout << endl;
				continue;
			}


			bool valido = true;

			for(int i = 0; i < entrada.length(); i++)
			{
				if(i == 0 && entrada[i] == '-')
				{
					continue;
				}

				if(!isdigit((unsigned char)entrada[i]))
				{
					valido = false;
					break;
				}
			}


			if(!valido)
			{
				cout << "Digite apenas números!" << endl;
				cout << endl;
				continue;
			}

			digito = atoi(entrada.c_str());

			if(digito <= valorAnterior)
			{
				cout << "O número deve sempre ser maior que o anterior! ";
				cout << endl;
			}
			else
			{
				break;
			}
		}
		if(digito % 2 == 0)
		{
			(push(pilhaPar, digito));
			cout << endl;
		}
		else
		{
			(push(pilhaImpar, digito));
			cout << endl;
		}

		valorAnterior = digito;

		contador++;

		if(contador == 2)
		{
			system("cls");
			contador = 0;
		}
	}

	print(pilhaPar);
	print(pilhaImpar);
	
	cout << "\nSequência decrescente:\n";

	while(!isEmpty(pilhaPar) && !isEmpty(pilhaImpar))
	{
		if(topo(pilhaPar) > topo(pilhaImpar))
		{
			cout << pop(pilhaPar) << " ";
		}
		else
		{
			cout << pop(pilhaImpar) << " ";
		}
	}

	while(!isEmpty(pilhaPar))
	{
		cout << pop(pilhaPar) << " ";
	}

	while(!isEmpty(pilhaImpar))
	{
		cout << pop(pilhaImpar) << " ";
	}


	return 0;
}
