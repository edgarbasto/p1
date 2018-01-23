
//**************************
// ref 073 como referencia
//**************************

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <cstdlib>
#include <cstdio>
//#include <WinBase.h>
using namespace std;

struct livro
{
	long num;
	char nome[30];
	char autor[30];
	float valor;
};

struct livro liv;
FILE *fp;
char ch;

//fun��es
int listar() {
	//estudar melhor os REF 74 & 72, pois esta fun��o n�o est� a funcionar bem
	//exemplo: h� neste momento dois registos - 123 e 1234 - se escrevermos 1 ele devolve o primeiro
	//se escrevermos 1234 ele s� devolve o 123

	long salto;
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOp��o Listar" << endl;
	cout << "\n######################" << endl;

	// aceder e ler um registo especifico  
	// fazer reset do ptr do fich para o inicio

	fp = fopen("dados.dat", "r");

	printf("\n\n\nDigite o numero do registo que pretenda ler: ");

	fflush(stdin);
	scanf("%ld", &salto);

	// posicionar-se

	fseek(fp, (long)(salto - 1) * sizeof(liv), SEEK_SET);

	// ler o reg localizado 
	fread(&liv, sizeof(liv), 1, fp);

	// mostrar o reg seleccionado
	printf("\nISBN: %ld", liv.num);
	printf("\nNome: %s", liv.nome);
	printf("\nAutor: %s", liv.autor);
	printf("\nValor: %4.2f\n\n\n", liv.valor);

	fclose(fp);

	system("PAUSE");
	return 0;
};

int inserir() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOp��o Inserir" << endl;
	cout << "\n######################" << endl;	
	//o programa ao correr mostra as linhas acima e fica a espera de um ENTER
	//como saltamos a frente e mostramos logo as perguntas?

	
	//abre ficheiro
	fp = fopen("dados.dat", "a");
	
	//dormir aqui? Sleep(3000);
	
	if (fp == NULL)
	{
		cout << "ERRO!\nO Ficheiro n�o foi aberto.\n" << endl;

		cout << "\n\nDigite uma tecla para terminar Programa\n" << endl;

		cout.flush();		
		ch = getchar();
		exit(0);
	}
		
	if (_getch() != 27)
		do
		{			
			// nota - n�o estamos a validar a introdu��o. experimentem ver a op��o consultar, visto
			// se inserirem espa�os/ENTER ele guarda isso tudo no ficheiro e a consulta/listagem fica "feia"
			printf("\n\nDigite o ISBN do livro: ");
			fflush(stdin);
			scanf("%ld", &liv.num);
			//printf("\n\n\nISBN: %ld", liv.num);

			// HELP - n�o consigo que a pergunta "titulo do livro" funcione no visual studio
			// :( Simplesmente salta para a pergunta seguinte
			
			printf("\n\nDigite o Titulo do livro:");
			while (getchar() != '\n');
			fgets(liv.nome, 30, stdin);
			// fgets � o gets mas novo e atualizado
			//printf("\nNome: %s", liv.nome);

			printf("\n\nDigite o Autor do livro: ");
			fflush(stdin);
			fgets(liv.autor, 30, stdin);
			//printf("\nAutor: %s", liv.autor);

			printf("\n\nDigite o valor do livro: ");
			fflush(stdin);
			scanf("%f", &liv.valor);
			//printf("\nValor: %4.2f", liv.valor);
			
			fwrite(&liv, sizeof(liv), 1, fp);

			// o ESC est� a gerar loop no menu inicial � preciso perceber porqu�
			printf("\n\nClique em ESC para sair\n\n");
			printf("\t ou em outra tecla para novo registo\n\n");

			fflush(stdin);
		} while (_getch() != 27);


		// fecha ficheiro que estava aberto para escrita-append

		fclose(fp);

		



	system("PAUSE");
	return 0;
};

int alterar() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOp��o Alterar" << endl;
	cout << "\n######################" << endl;
	system("PAUSE");
	return 0;
};

int consultar() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOp��o Consultar" << endl;
	cout << "\n######################" << endl;

	// abre agora o ficheiro para leitura

	fp = fopen("dados.dat", "r");

	// enquanto houverem registos imprimir cada um para o ecr�

	while (fread(&liv, sizeof(liv), 1, fp))
	{
		printf("\n\n\nISBN: %ld", liv.num);

		printf("\nNome: %s", liv.nome);

		printf("\nAutor: %s", liv.autor);

		printf("\nValor: %4.2f", liv.valor);
	}


	system("PAUSE");
	return 0;
};

int eliminar() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOp��o Eliminar" << endl;
	cout << "\n######################" << endl;
	system("PAUSE");
	return 0;
}





int main() {
	//aceitar chars portugueses
	setlocale(LC_ALL, "Portuguese");

	//validar se precisamos de repetir o menu
	bool repetirmenu = true;
	
	//repete o menu em loop
	while (repetirmenu = true) {
		int escolhamenu;
		system("cls");
		cout << "######################" << endl;
		cout << "\nBem-vindo ao nosso projeto de programacao Janeiro 2018" << endl;
		cout << "\n######################" << endl;
		cout << "\nSeleccione a sua op��o:" << endl;
		cout << "\n\t1. Listar" << endl;
		cout << "\n\t2. Inserir" << endl;
		cout << "\n\t3. Alterar" << endl;
		cout << "\n\t4. Consultar" << endl;
		cout << "\n\t5. Eliminar" << endl;		
		cout << "\n\tOp��o: ";
		cin >> escolhamenu;

		//Marcos a testar - valida��o do input. o objetivo � s� conseguir inserir numeros e n�o outros chars
		if (cin.fail()) {
			/*system("cls");
			cout << "erro";
			cin.clear();
			system("pause");*/
		}
		else {

			switch (escolhamenu) {
				case 1:
					listar();

					break;
				case 2:
					inserir();

					break;
				case 3:
					alterar();

					break;
				case 4:
					consultar();

					break;
				case 5:
					eliminar();

					break;
				default:
					cout << "N�o escolheu uma op��o v�lida. Tente novamente." << endl;
					system("pause");

			}			
		}		
	}

	







	system("PAUSE");
	return 0;
		
};
