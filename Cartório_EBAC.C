#include <stdio.h> //biblioteca de ccomunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar as string

int registro() // função responsalvesl por cadastrar os usuários no sitema
{ 
	//inicio criação de variável/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variável/string
	
	printf("Digite o CPF a ser cadastrado: " ); //coletando informação do usuário
	scanf("%s", cpf); //%S refere-se a string
	
	strcpy(arquivo, cpf); //responsavesl por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" singifica escrever
	fprintf(file,cpf); //salvao valor da varivel
	fclose(file); //fecha o aquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file =  fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file =  fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);

	file =  fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadrastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");

}	

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definido a linguagem
	
	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE  *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n");
	}

	while(fgets (conteudo, 200, file) != NULL )
	{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado; ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file ==  NULL)
	{
		printf("O Usuário não se encontra no sistema! \n");
		system("pause");
	}
	
}

int main()
{
	
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definido a linguagem
	
		printf("\t Cartório da EBAC \n\n"); //inicio da menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n"); 
		printf("\t4 - Sair do sistema\n\n  ");
		printf("Opção:"); //Fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); // responsavel por limpar a tela
	
		switch(opcao)
		{
			case 1:
			registro(); //chamada de função 
			break;		
			
			case 2:
			consultar(); //chamada de função
			break;
			
			case 3:
			deletar(); //chamada de função
			break;
			
		 	case 4:
			printf ("Obrigado por utilizar o sistema!\n\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel! \n");
			system("pause");
			break;
			
		} //fim da seleção 
		
	}
}
