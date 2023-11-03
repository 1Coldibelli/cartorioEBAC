#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //função responsável por registrar novos usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//início da criação de variáveis
	char arquivo[40];
	char CPF[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser registrado: "); //coletando CPF do usuário
	scanf("%s", CPF); //%s se refere à strings
	
	strcpy(arquivo, CPF); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e "w" é write
	fprintf(file, CPF); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" é atualizar
	fprintf(file, ","); //insere uma "," no final da variável cadastrada
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser regitrado: "); //coletando nome do usuário
	scanf("%s", nome); //%s se refere à strings
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" é atualizar
	fprintf(file, nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" é atualizar
	fprintf(file, ","); //insere uma "," no final da variável cadastrada
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser regitrado: "); //coletando sobrenome do usuário
	scanf("%s", sobrenome); //%s se refere à strings
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" é atualizar
	fprintf(file, sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" é atualizar
	fprintf(file, ","); //insere uma "," no final da variável cadastrada
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser regitrado: "); //coletando cargo do usuário
	scanf("%s", cargo); //%s se refere à strings
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" é atualizar
	fprintf(file, cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo

	system("pause");	
}

int consultar() //função responsável por consultar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char CPF[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", CPF);
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if(file == NULL)
	{
		printf("Cadastro não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int excluir() //função responsável por excluir novos usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char CPF[40];
	
	printf("Digite o CPF do usuário a ser excluído: ");
	scanf("%s", CPF);
	
	remove(CPF);
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if(file == NULL)
	{
		printf("Cadastro não localizado.\n");
		system("pause");
	}
}

int main() //função principal do sistema, responsável pelo menu
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");
	
		printf("### Cartório da EBAC ### \n\n"); //início do menu
		printf("Escolha a opção desejada no menu: \n\n");
		printf("\t 1 - Registrar nomes \n");
		printf("\t 2 - Consultar nomes \n");
		printf("\t 3 - Excluir nomes \n\n"); 
		printf("Opção: ");
	
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao) //início da escolha do usuário
		{
			case 1:
			registrar();
			break;

			case 2:
			consultar();
			break;

			case 3:
			excluir();
			break;

			default:
			printf("Escolha inválida!\n");
			system("pause");
			break;				
		} //fim da escolha do usuário
	}
}


