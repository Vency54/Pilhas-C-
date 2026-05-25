#include <iostream>
#include <windows.h>
#include <clocale>
#include <climits>

using namespace std;

//Nome: João Victor Lima Venceslau


struct No
{
	int  dado;
	struct No *ant;
};

struct Pilha
{
	No *topo;
};

Pilha* init()
{
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

int isEmpty(Pilha *p)
{
	return (p->topo == NULL);
}

int count(Pilha *p)
{
	int i = 0;
	No *no;
	no = p->topo;
	while (no != NULL)
	{
		i++;
		no = no->ant;
	}
	return i;
}

void print(Pilha *p)
{
	No *no;
	no = p->topo;
	cout << "--------------------------" << endl;
	cout << "-- Qtde: " << count(p) << "            --" << endl;
	cout << "--------------------------" << endl;
	while (no != NULL)
	{
		cout << no->dado << endl;
		no = no->ant;
	}
	cout << "--------------------------" << endl;
}

void push(Pilha *p, int  v)
{
	No *no = new No;
	no->dado = v;
	no->ant = p->topo;
	p->topo = no;
}

int  pop(Pilha *p)
{
	int  v = -1;
	int podeDesempilhar = (! isEmpty(p));
	if (podeDesempilhar)
	{
		No *no = p->topo;
		v = no->dado;
		p->topo = no->ant;
		delete(no);
	}
	return v;
}

int topo(Pilha *p)
{
	return p->topo->dado;
}



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
	Pilha *pilhaPar = init();
	Pilha *pilhaImpar = init();
	int valorAnterior = INT_MIN;

	int contador = 0;

	cout << "Digite 30 números em ordem crescente:\n" << endl;


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
