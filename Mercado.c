#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings


int Registrar() //função que registra os produtos
{
	
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	 
	 
	//inicio da criação de variáveis/string
    char produtos[40];
	char nome[40];
    char marca[40];
    char preco[40];
    //final da crianção de variáveis
    
    
    printf("Digite o Nome do produto: "); //coletando informações dos produtos
    scanf("%s", nome); // %s = refere-se a sting
    
    strcpy(produtos, nome); //responsavel por copiar os valores das strings
    FILE *file; //cria o aquivo
	 
    file = fopen(produtos, "w"); //cria o arquivo
    fprintf(file,"NOME: ");
    fprintf(file, nome); //salva o valor da variavel
    fclose(file); // fecha o aquivo
    
    file = fopen(produtos, "a");
    fprintf(file,",\nMARCA: ");
    fclose(file);
    
    printf("Digite a Marca do produto: ");
    scanf("%s", nome);
    
    file = fopen(produtos, "a");
    fprintf(file, nome);
    fclose(file);
    
    printf("Digite a o preço: ");
    scanf("%s", nome);
    
    file = fopen(produtos, "a");
    fprintf(file,",\nPREÇO: ");
    fclose(file);
    
    file = fopen(produtos, "a");
    fprintf(file,nome);
    fprintf(file,".\n\n");
	fclose(file);
    
    
    system("pause");
}

int Consultar()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
    char produtos[40];
    char conteudo[200];
    
    printf("Digite o NOME do produto: ");
    scanf("%s", produtos);
    
    FILE *file;
    file = fopen(produtos, "r");
    
    if(file == NULL)
    {
    	printf("o Produto não foi localizado!.\n");
	}
    
    printf("Essas são as informações do Produto: \n\n");
    
    while(fgets(conteudo, 200, file) != NULL)
	{
    	printf("%s", conteudo);
	}
	
	system("pause");
	fclose(file);
}


int Apagar()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char produtos[40];
	
	
	printf("Digite o NOME do produto a ser APAGADO: ");
	scanf("%s", produtos);
	
	remove(produtos);
	
	FILE *file; //acessa a biblioteca que está salva no computador(pessoal)
	file = fopen(produtos, "r");
	
	if(file == NULL)
	{
		printf("Esse produto não foi registrado!\n");
		system("pause");
    }
    
}

int main()
{
    int opcao=0; //Definindo Variáveis 
    int x=1;

    for (x=1;x=1;)
    {
    
        system("cls");     
        
	    setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	
     	printf("#### Mercadão Bao ####\n\n"); //Inicio do menu
    	printf("Selecione a opção desejada:\n\n\n");
	    printf("\t1 Registrar produto\n");
	    printf("\t2 Consultar produto\n");
	    printf("\t3 Apagar produto\n\n");
	    printf("\t4 Sair do Sistema\n\n");
        printf("Opção: "); //fim do menu
	
	
	    scanf("%d", &opcao); // armazenando a escolha do usuário
	
	    system("cls"); // Limpar a tela
	
	    switch(opcao) //Inicio da seleção do menu
		{ 
	    	case 1:
	    	    Registrar(); //chamda de funções
			    break;	
			
			case 2:
		        Consultar();
		        break;
		    
		    case 3:
		    	Apagar();
		        break;
		        
		    case 4:
			    printf("Obrigado por utilizar o sistema!\n");
			    return 0;
			    break;    
		        
		        
		    default:
		    	printf("Essa opção não está disponível!\n");
		        system("pause");
		        break;
		        // fim da seleção
		}
}

}




