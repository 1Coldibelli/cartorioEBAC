#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //fun��o respons�vel por registrar novos usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//in�cio da cria��o de vari�veis
	char arquivo[40];
	char CPF[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser registrado: "); //coletando CPF do usu�rio
	scanf("%s", CPF); //%s se refere � strings
	
	strcpy(arquivo, CPF); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e "w" � write
	fprintf(file, CPF); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" � atualizar
	fprintf(file, ","); //insere uma "," no final da vari�vel cadastrada
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser regitrado: "); //coletando nome do usu�rio
	scanf("%s", nome); //%s se refere � strings
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" � atualizar
	fprintf(file, nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" � atualizar
	fprintf(file, ","); //insere uma "," no final da vari�vel cadastrada
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser regitrado: "); //coletando sobrenome do usu�rio
	scanf("%s", sobrenome); //%s se refere � strings
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" � atualizar
	fprintf(file, sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" � atualizar
	fprintf(file, ","); //insere uma "," no final da vari�vel cadastrada
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser regitrado: "); //coletando cargo do usu�rio
	scanf("%s", cargo); //%s se refere � strings
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" � atualizar
	fprintf(file, cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo

	system("pause");	
}

int consultar() //fun��o respons�vel por consultar usu�rios no sistema
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
		printf("Cadastro n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int excluir() //fun��o respons�vel por excluir novos usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char CPF[40];
	
	printf("Digite o CPF do usu�rio a ser exclu�do: ");
	scanf("%s", CPF);
	
	remove(CPF);
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if(file == NULL)
	{
		printf("Cadastro n�o localizado.\n");
		system("pause");
	}
}

int main() //fun��o principal do sistema, respons�vel pelo menu
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");
	
		printf("### Cart�rio da EBAC ### \n\n"); //in�cio do menu
		printf("Escolha a op��o desejada no menu: \n\n");
		printf("\t 1 - Registrar nomes \n");
		printf("\t 2 - Consultar nomes \n");
		printf("\t 3 - Excluir nomes \n\n"); 
		printf("Op��o: ");
	
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao) //in�cio da escolha do usu�rio
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
			printf("Escolha inv�lida!\n");
			system("pause");
			break;				
		} //fim da escolha do usu�rio
	}
}


