#include <iostream>
#include <windows.h>
using namespace std;

#define MAX 15

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

int push(Pilha *p, float v)
{
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar)
	{
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

float pop(Pilha *p)
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

/*Pilha* merge(Pilha *p1, Pilha *p2)
{
	Pilha *nova = init();
	for(int i = 0; i < p1-> qtde; i++)
	{
		push(nova, p1->elementos[i]);
	}
	for(int i = 0; i < p2-> qtde; i++)
	{
		push(nova, p2->elementos[i]);
	}
	for(int i = 0; i < nova-> qtde; i++)
	{
		for(int j = 0; j < nova-> qtde; j++)
		{
			if ( nova->elementos[i] < nova->elementos[j])
			{
				int ant = nova->elementos[i];
				nova->elementos[i] = nova->elementos[j];
				nova->elementos[j] = ant;
			}
		}
	}

	return nova;
}*/

void freePilha(Pilha *p)
{
	delete p;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
	Pilha *pilhaPar = init();
	Pilha *pilhaImpar = init();
	int valorAnterior = INFINITE;

	cout << "Pilha par vazia: "
		 << (isEmpty(pilhaPar) ? "Sim" : "Nao")
		 << endl;

	cout << "Pilha impar vazia: "
		 << (isEmpty(pilhaImpar) ? "Sim" : "Nao")
		 << endl;

	int contador = 0;

	for(int i = 0; i < 15; i++)
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

			bool valido = true;

			for(int i = 0; i < entrada.length(); i++)
			{
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
