#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio2.h>
#include <windows.h>
#include <locale.h>

#define tf 20

struct tpData
{
	int d,m,a;
};
struct tpProduto
{
	int cod, estoque,codForne;
	float preco;
	tpData validade;
	char desc[tf];

};
struct tpFornecedor
{
	int codFornecedor;
	char nomeForne[tf],cidadeForne[tf];
};
struct tpCliente
{
	int cpf,qntdCompra;
	float ValorTotComprado;
	char NomeCli[tf];	
};
struct tpVendas
{
	int CodVenda,CpfCli;
	float TotVenda;
	tpData DVenda;
	
};
struct tpVendasProdutos
{
	int CodVenda,CodProd,qntd;
	float ValorUni;
};



void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF)
{
int i;
textcolor(CorT);
textbackground(CorF);
gotoxy(CI,LI);
printf("%c",201);
gotoxy(CI,LF);
printf("%c",200);
gotoxy(CF,LI);
printf("%c",187);
gotoxy(CF,LF);
printf("%c",188);
for(i=CI+1; i<CF; i++)
{
	gotoxy(i,LI); printf("%c",205);
	gotoxy(i,LF); printf("%c",205);
}
for(i=LI+1; i<LF; i++)
{
	gotoxy(CI,i); printf("%c",186);
	gotoxy(CF,i); printf("%c",186);
} 

textcolor(7);
textbackground(0);
}
void Formulario(void)
{
system("cls");
Moldura(1,1,80,25,0,9); //Moldura geral


//	 moldura(2,2,79,4,14,1); moldura do titulo 
//	Moldura(2,5,27,21,12,7); Moldura lateral esquerda
//MenuPrincipal();
// Moldura(2,22,79,24,11,4); moldur da mensagem
gotoxy(4,23);
textcolor(1);
printf("Mensagem: ");

Moldura(2,5,79,21,8,7);  // moldura da lateral direita
}
char menu(void)
{

	textcolor(15);
	
	gotoxy(5,7);
	printf("[A] Cadastrar Produtos\n");
	gotoxy(5,8);
	printf("[B] Cadastrar Fornecedor\n");
	gotoxy(5,9);
	printf("[C] Cadastro de Cliente\n");
		gotoxy(5,10);
	printf("[D] Venda");
	gotoxy(5,11);
	printf("[E] Consulta");
	gotoxy(5,12);
	printf("[F] Exclusao");
	gotoxy(5,13);
	printf("[G] Aumento de preco");
	gotoxy(5,14);
	printf("[H] Relatorio");
	gotoxy(5,15);
	printf("[I] Inserir Dados");
	gotoxy(5,16);
	printf("[ESC] Sair\n");
	gotoxy(5,17);
	printf("Opcao desejada: ");
	return toupper(getche());
	
}
int BuscarProd(tpProduto Tab[tf], int TL, int CodProd)
{
	int a=0;
	while (a<TL && CodProd!=Tab[a].cod)
				a++;
	
	if (a<TL)
	// ACHOU
		return a;
	else
// NÃO ACHOU
		return -1;
}
int BuscarForne(tpFornecedor Tab[tf], int TL, int CodForne)
{
	int a=0;
	while (a<TL && CodForne!=Tab[a].codFornecedor)
				a++;
	
	if (a<TL)
	// Aqui ACHOU
		return a;
	else
	// Aqui NÃO achou
		return -1;
}
int BuscarCPF(struct tpCliente tab[tf], int tlc, int cpf)
{
	int a=0;
	while(a<tlc && cpf!=tab[a].cpf)
		a++;
	if(a<tlc)
	{
		// achou
		return a;
		
	}
	else 
	{
		// não achou
		return -1;
	}
	
}
void limpartela()
{
	int i;
	for(i=7;i <= 20;i++)
	{
		gotoxy(3,i);
		for(int j=2;j<=77;j++)
		{
			printf(" ");
		}
	}
}
void InserirDados(tpProduto TabProd[tf],tpCliente TabCliente[tf],tpFornecedor TabForne[tf],int &TLP,int &TLC,int &TLF)
{
	
	//Produtos
	
	TabProd[TLP].cod = 5000;
	strcpy(TabProd[TLP].desc,"Arroz");
	TabProd[TLP].estoque = 20;
	TabProd[TLP].preco = 25;
	TabProd[TLP].validade.d = 15;
	TabProd[TLP].validade.m = 8;
	TabProd[TLP].validade.a = 2025;
	TabProd[TLP].codForne = 1515;
	TLP++;
	
	TabProd[TLP].cod = 6000;
	strcpy(TabProd[TLP].desc,"Bolacha");
	TabProd[TLP].estoque = 50;
	TabProd[TLP].preco = 2.25;
	TabProd[TLP].validade.d = 10;
	TabProd[TLP].validade.m = 12;
	TabProd[TLP].validade.a = 2024;
	TabProd[TLP].codForne = 2525;
	TLP++;
	
	TabProd[TLP].cod = 7000;
	strcpy(TabProd[TLP].desc,"Leite");
	TabProd[TLP].estoque = 500;
	TabProd[TLP].preco = 8;
	TabProd[TLP].validade.d = 12;
	TabProd[TLP].validade.m = 1;
	TabProd[TLP].validade.a = 2025;
	TabProd[TLP].codForne = 3030;
	TLP++;
		
	TabProd[TLP].cod = 8000;
	strcpy(TabProd[TLP].desc, "Feijão");
	TabProd[TLP].estoque = 30;
	TabProd[TLP].preco = 4.50;
	TabProd[TLP].validade.d = 25;
	TabProd[TLP].validade.m = 9;
	TabProd[TLP].validade.a = 2025;
	TabProd[TLP].codForne = 1515;
	TLP++;
	
	TabProd[TLP].cod = 9000;
	strcpy(TabProd[TLP].desc, "Macarrão");
	TabProd[TLP].estoque = 40;
	TabProd[TLP].preco = 3.00;
	TabProd[TLP].validade.d = 8;
	TabProd[TLP].validade.m = 11;
	TabProd[TLP].validade.a = 2024;
	TabProd[TLP].codForne = 3030; 
	TLP++;
	
	TabProd[TLP].cod = 10000;
	strcpy(TabProd[TLP].desc, "Sabonete");
	TabProd[TLP].estoque = 100;
	TabProd[TLP].preco = 1.75;
	TabProd[TLP].validade.d = 10;
	TabProd[TLP].validade.m = 3;
	TabProd[TLP].validade.a = 2025;
	TabProd[TLP].codForne = 2525;
	TLP++;

	// Clientes
	
	TabCliente[TLC].cpf= 1515;
	strcpy(TabCliente[TLC].NomeCli,"Ruan Caetano");
	TabCliente[TLC].qntdCompra=5;
	TabCliente[TLC].ValorTotComprado=2500.00;
	TLC++; 
	
	TabCliente[TLC].cpf= 2525;
	strcpy(TabCliente[TLC].NomeCli,"Caetano Veloso");
	TabCliente[TLC].qntdCompra=10;
	TabCliente[TLC].ValorTotComprado=500.00;
	TLC++;
	
	//Fornecedor
	
	TabForne[TLF].codFornecedor=2525;
	strcpy(TabForne[TLF].nomeForne,"Coca-Cola");
	strcpy(TabForne[TLF].cidadeForne,"Sampa");
	TLF++;
	
	TabForne[TLF].codFornecedor=3030;
	strcpy(TabForne[TLF].nomeForne,"Carioca");
	strcpy(TabForne[TLF].cidadeForne,"Rio de janeiro");
	TLF++;
	
	TabForne[TLF].codFornecedor=1515;
	strcpy(TabForne[TLF].nomeForne,"seila");
	strcpy(TabForne[TLF].cidadeForne,"Acre");
	TLF++;
}
void CadFornecedor(tpFornecedor TabForne[tf],int &TLF)
{
	int i,pos,codaux,opc;
	
	gotoxy(27,3);
	printf("* * * Cadastro de Fornecedor * * *");
	gotoxy(5,7);
	printf("Digite o Codigo do Fornecedor: ");
	scanf("%d", &codaux);
	while(TLF<tf && codaux>0)
	{
		pos=BuscarForne(TabForne,TLF,codaux);
		
		if(pos==-1)
		{
			TabForne[TLF].codFornecedor=codaux;
			gotoxy(5,8);
			printf("Digite o nome do Fornecedor: ");
			fflush(stdin);
			gets(TabForne[TLF].nomeForne);
			gotoxy(5,9);
			printf("Digite a cidade do Fornecedor: ");
			fflush(stdin);
			gets(TabForne[TLF].cidadeForne);
			TLF++;
			gotoxy(17,23);
			printf("* Fornecedor Cadastrado!! *");
			getch();
			
			// Faz o Cadastro
		}
		else
		{
			 system("cls");
			 Formulario();
			 gotoxy(5,7);
			 printf("Nome: %s | Codigo: %d",TabForne[pos].nomeForne,TabForne[pos].codFornecedor);
			 gotoxy(17,23);
			 textcolor(4);
			 printf("*** FORNECEDOR JA CADASTRADO ***");
			 getch();
		
		}
		limpartela();
			gotoxy(5,7);
			printf("Outro Fornecedor? S=1|N=0: ");
			scanf("%d",&opc);
			codaux=0;
		if(opc==1 && TLF<tf)
		{
			system("cls");
		 	Formulario();
		 	gotoxy(5,7);
			printf("Digite o Codigo do Fornecedor: ");
			scanf("%d", &codaux);	
		}
	}
	
}
void CadProduto(tpProduto TabProd[tf],tpFornecedor TabForne[tf],int TLF,int &TLP)
{
	int AuxCod,pos,AuxForne=0,posforne=0,opc;
	
	
	gotoxy(27,3);
	printf("* * * Cadastro de Produtos * * *");
	gotoxy(5,7);
	printf("Codigo do Produto: ");
	scanf("%d",&AuxCod);
	while(TLP<tf && AuxCod>0)
	{
		pos = BuscarProd(TabProd,TLP,AuxCod);
		// essa porra ta entrando mesmo não tendo o fornecedor
		if (pos==-1)
		{
			//cadastrando produto
			TabProd[TLP].cod=AuxCod;
			//buscando fornecedor
			gotoxy(5,8);
			printf("Digite o codigo do Fornecedor: ");
			scanf("%d", &AuxForne);
			posforne = BuscarForne(TabForne,TLF,AuxForne);
			if (posforne==-1)
			{
				gotoxy(17,23);
				printf("*** FORNECEDOR NAO LOCALIZADO");
				getch(); 	
			}
			else
			{
				//cadastrando fornecedor
				TabProd[TLP].codForne=AuxForne;
				
				//cadastrando produto
				gotoxy(5,9);
				printf("Descricao do Produto: ");
				fflush(stdin);
				gets(TabProd[TLP].desc);
				gotoxy(5,10);
				printf("Valor Unitario: ");
				scanf("%f", &TabProd[TLP].preco);
				gotoxy(5,11);
				printf("Quantidade em Estoque: ");
				scanf("%d", &TabProd[TLP].estoque);
				gotoxy(5,12);
				printf("Digite a data de Validade [DD MM AAAA]: ");
				scanf("%d %d %d", &TabProd[TLP].validade.d,&TabProd[TLP].validade.m,&TabProd[TLP].validade.a);
					TLP++;
				gotoxy(17,23);
				textcolor(2);
				printf("* Produto Cadastrado!! *");
				getch();
			}
			
			
			
			
		}
		
		else
			{
				system("cls");
				Formulario();
				gotoxy(5,7);
				printf("Produto Cadastrado!");
				gotoxy(5,8);
				printf("Produto[%d] - Descricao: [%s]\n\n",TabProd[pos].cod,TabProd[pos].desc);
				getch();
			}
		limpartela();
			gotoxy(5,7);
			printf("Outra Produto? S=1|N=0: ");
			scanf("%d",&opc);
			AuxCod=0;
		if(opc==1 && TLP<tf)
		{
			system("cls");
			Formulario();
			gotoxy(5,7);
			printf("Codigo do Produto: ");
			scanf("%d",&AuxCod);
		}
		//else
//			{
//				printf("\nTabela Cheia!\n");
//				getch();
//			}
	}
}
void CadCliente(tpCliente TabCliente[tf],int &TLC)
{
	int codaux,pos,opc;
	gotoxy(27,3);
	printf("*** Cadastro de Cliente ***");
	gotoxy(5,7);
	printf("Digite o CPF: ");
	scanf("%d", &codaux);
	if (TLC<tf)
	{
		while(TLC<tf && codaux>0)
		{
			pos=BuscarCPF(TabCliente,TLC,codaux);	
			if(pos==-1)
			{
				// não achei o cpf então posso cadastrar
				TabCliente[TLC].cpf=codaux;
				gotoxy(5,8);
				printf("Digite o nome: ");
				fflush(stdin);
				gets(TabCliente[TLC].NomeCli);
				// quantidade de compra , como eu faço essa porra
				// acho que isso é dentro da função venda, busca o cliente e add na tabela
				
				// valor total como eu faço essa porra
				// faz na função venda	
				TLC++;
			}
			else
			{
				system("cls");
				Formulario();
				gotoxy(17,23);
				printf("*** Cliente ja cadastrado ***");
				gotoxy(5,7);
				printf("Nome: %s | CPF: %d",TabCliente[pos].NomeCli,TabCliente[pos].cpf);
				TabCliente[pos].qntdCompra+=0;
				TabCliente[pos].ValorTotComprado+=0.0;
				getch();
				
			}
			
			limpartela();
			gotoxy(5,7);
			printf("Outro cliente? S=1|N=0: ");
			scanf("%d",&opc);
			codaux=0;
			if(opc==1 && TLC<tf)
			{
				system("cls");
				Formulario();
				gotoxy(5,7);
				printf("Digite o CPF: ");
				scanf("%d", &codaux);
			}
			//else
//			{
//				gotoxy(17,23);
//				printf("*** Lista Cheia ***");
//				getch();
//			}
		}
		
	}
				
}

void  Venda(struct tpVendas TabVenda[tf],struct tpCliente TabCliente[tf],struct tpProduto TabProd[tf],struct tpVendasProdutos TabVenda_Prod[tf],int &TLV,int &TLC,int &TLP,int &TLVP)
{
	int opc=1,aux=0,pos,cod=TLV,qntd,prod,poscpf,auxcpf,somaq=0,y,i;
	float somav;
	gotoxy(28,3);
	printf("*** Vendas ***");
	gotoxy(5,8);
	printf("CPF do Cliente: ");
	scanf("%d", &auxcpf);
	if(TLV<tf)
	{
	while(TLV<tf && auxcpf>0)
	{
//		limpartela();
		poscpf=BuscarCPF(TabCliente,TLC,auxcpf);
		
		if(poscpf==-1)
		{
			gotoxy(17,23);
			printf("*** CPF NÃO ENCONTRADO ***");
			getch();
		}
		else
		{
			gotoxy(5,7);
			TabVenda[TLV].CodVenda=TLV+1;
			printf("Venda: %d",TLV+1);
			gotoxy(5,9);
			printf("Data da Venda [dd mm aaaa]: ");
			scanf("%d %d %d", &TabVenda[TLV].DVenda.d,&TabVenda[TLV].DVenda.m,&TabVenda[TLV].DVenda.a);
			
			// repetição pra mais produtos
			do
			{
				somav=0;
				system("cls");
				Formulario();
				gotoxy(28,3);
				printf("*** Vendas ***");
				gotoxy(5,7);	
				printf("Venda: %d",TLV+1);
				TabVenda_Prod[TLVP].CodVenda=TLV+1;// Vendas Produtos recebe o cod da venda
				gotoxy(5,8);
				printf("Codigo do Produto: ");
				scanf("%d", &aux);
				
				
				prod=BuscarProd(TabProd,TLP,aux);
				if(prod==-1)
				{
					textcolor(4);
					gotoxy(17,23);
					printf("*** PRODUTO NÃO ENCONTRADO ***");
					getch();
				}
				else
				{
					
					TabVenda_Prod[TLVP].CodProd=TabProd[prod].cod;// Venda Prod recebe o cod do produto 
					gotoxy(5,9);
					printf("Produto: %s", TabProd[prod].desc);
					gotoxy(5,10);
					printf("Quantidade Comprada: ");
					scanf("%d", &qntd);
					if(TabProd[prod].estoque>qntd)
					{
							TabVenda_Prod[TLVP].qntd = qntd; // Venda Prod recebe a qntd
					//	printf("%d",TabVenda_Prod[TLVP].qntd);
						TabVenda_Prod[TLVP].ValorUni=TabProd[prod].preco;//Venda Prod recebe o
						
						TabVenda[TLV].TotVenda+=TabProd[prod].preco*qntd; // calculo a pagar
					//	printf("%.2f",TabVenda[TLV].TotVenda);
					//	printf("%f",TabVenda[TLV].TotVenda); // colocanfdo pra ver se ta atribuindo
						somaq=TabCliente[poscpf].qntdCompra+qntd; // calculando pra atribuir
						TabCliente[poscpf].ValorTotComprado+=TabVenda[TLV].TotVenda; // colocando o valor da venda na tab do cliente
					// fazer a qntd sai do estoque
						TabProd[prod].estoque=TabProd[prod].estoque-qntd;
							
						TLVP++;
						qntd=0;
						gotoxy(5,11);
						printf("Outro Produto? S=1|N=0: ");
						scanf("%d",&opc);	
						}
					else
					{
						gotoxy(17,23);
						printf("*** Estoque insuficiente para venda ***");
						getch();
					}
				
				}
			}while(opc==1);
			TabCliente[poscpf].qntdCompra = somaq;
			//TabCliente[poscpf].ValorTotComprado+= somav;
			
			// NOTA FISCAL
			limpartela();
			gotoxy(5,7);
			printf("Venda: %d",TLV+1);
			gotoxy(40,7);
			printf("%d/%d/%d",TabVenda[TLV].DVenda.d,TabVenda[TLV].DVenda.m,TabVenda[TLV].DVenda.a);
			gotoxy(5,9);
			printf("Cod");
			gotoxy(20,9);
			printf("Prod");
			gotoxy(35,9);
			printf("Valor");
			gotoxy(45,9);
			printf("Qntd");
			for(i=0,y=10;i<TLVP;i++,y++)
			{
				if(TabVenda_Prod[i].CodVenda==TLV+1)
				{
					gotoxy(5,y);
					printf("%d",TabVenda_Prod[i].CodProd);

					prod=BuscarProd(TabProd,TLP,TabVenda_Prod[i].CodProd);
					gotoxy(20,y);
					printf("%s",TabProd[prod].desc);
			
					gotoxy(35,y);
					printf("%.2f",TabProd[prod].preco);
			
					gotoxy(45,y);
					printf("%d",TabVenda_Prod[i].qntd);
					
				}
				
			}
			y++;
			gotoxy(5,y);
			printf("Total: %.2f",TabVenda[TLV].TotVenda);
			getch();

			//gotoxy(5,13);
//			printf("id: %d ",TLV+1);
			TLV++;
			limpartela();
			gotoxy(5,7);
			printf("Outra Venda? S=1|N=0: ");
			scanf("%d",&opc);
			auxcpf=0;	
			if(opc==1 && TLV<tf)
			{
				limpartela();
				gotoxy(5,8);
				printf("CPF do Cliente: ");
				scanf("%d", &auxcpf);
			}
 		
			
		}
	}	
	}
	
}


	
void consulta(tpProduto TabProd[tf],tpFornecedor TabForne[tf],tpCliente TabCliente[tf],int TLP,int TLF,int TLC)
{
	int opc,esc,y,a,b;
	
	do
	{
		system("cls");
		Formulario();
		gotoxy(27,3);
		printf("*** Consulta de Dados ***");
		gotoxy(5,7);
		printf("1 = Produtos ");
		gotoxy(5,8);
		printf("2 = Fornecedores ");
		gotoxy(5,9);
		printf("3 = Clientes ");
		gotoxy(5,10);
		printf("Digite o numero desejado:");
		scanf("%d",&esc);
		
		switch(esc)
		{
			case 1:
				system("cls");
		 		Formulario();
				gotoxy(27,3);
				printf("*** Consulta de Produtos ***");	
					limpartela();
						for(a=0,y=7,b=32 ; b==32 && a<TLP;y++, a++)
						{
							
							gotoxy(5,y);
							printf("-----------------------------------------------------------------");
							y++;
							gotoxy(5,y);
							printf("ID: %d | Nome: %s | Estoque: %d | Preco: %.2f "
							,TabProd[a].cod,TabProd[a].desc,TabProd[a].estoque,TabProd[a].preco);
							y++;
							gotoxy(5,y);
							printf("|Data de validade: %d %d %d | ID Fornecedor: %d ",TabProd[a].validade,TabProd[a].codForne);
						if(y>13)
						{
						y++;
						gotoxy(5,y+1);
						printf("Aperte espaco para mostrar mais produtos;");
						b=getch();
						if(b==32)
						{
							limpartela();
							y=7;	
						}	
						}
							
						}
				break;
			case 2:
				system("cls");
		 		Formulario();
				gotoxy(27,3);
				printf("*** Consulta de Fornecedores ***");	
				for(a=0, y=7; a<TLF ;a++,y++)
				{
					
					gotoxy(5,y);
					printf("-----------------------------------------------------------------");
					y++;
					gotoxy(5,y);
					printf("ID: %d | Nome: %s | Cidade: %s ",TabForne[a].codFornecedor,TabForne[a].nomeForne,TabForne[a].cidadeForne);
					if(y>13)
						{
						y++;
						gotoxy(5,y+1);
						printf("Aperte espaco para mostrar mais Fornecedores;");
						b=getch();
						if(b==32)
						{
							limpartela();
							y=7;	
						}	
						}
				}
				break;
			case 3:
				system("cls");
		 		Formulario();
				gotoxy(27,3);
				printf("*** Consulta de Clientes ***");	
				for(a=0, y=7; a<TLC ;a++,y++)
				{
					gotoxy(5,y);
					printf("-----------------------------------------------------------------");
					gotoxy(5,y);
					printf("CPF: %d | Nome: %s | Qntd Comprada: %d | Total: %.2f ",TabCliente[a].cpf,TabCliente[a].NomeCli,TabCliente[a].qntdCompra,TabCliente[a].ValorTotComprado);
					if(y>13)
						{
						y++;
						gotoxy(5,y+1);
						printf("Aperte espaco para mostrar mais Clientes;");
						b=getch();
						if(b==32)
						{
							limpartela();
							y=7;	
						}	
						}
				}
				break;
		}
		gotoxy(17,23);
		printf("Nova Consulta: S=1|N=0: ");
		scanf("%d",&opc);
	}while(opc==1);
}
void excluir(tpProduto TabProd[tf],tpFornecedor TabForne[tf],tpCliente TabCliente[tf],int &TLP,int &TLF,int &TLC)
{
	int opc,esc,y,a,aux,pos;
	do
	{
		system("cls");
		Formulario();
		gotoxy(27,3);
		printf("*** Exclusão de Dados ***");
		gotoxy(5,7);
		printf("1 = Produtos ");
		gotoxy(5,8);
		printf("2 = Fornecedores ");
		gotoxy(5,9);
		printf("3 = Clientes ");
		gotoxy(5,10);
		printf("Digite o numero desejado:");
		scanf("%d",&esc);
		switch(esc)
		{
			case 1:
				system("cls");
				Formulario();
				gotoxy(27,3);
				printf("*** Exclusão de Dados ***");
				gotoxy(5,7);
				printf("Digite o Codigo do Produto: ");
				scanf("%d", &aux);
				pos=BuscarProd(TabProd,TLP,aux);
				if(pos==-1)
				{
					gotoxy(17,23);
					printf("*** PRODUTO NAO ENCONTRADO ***");
				}
				else
				{
					
					gotoxy(5,8);
					printf("Produto: %s",TabProd[pos].desc);
					gotoxy(5,9);
					printf("Excluir: 1 = SIM | 2 = NAO : ");
					scanf("%d",&aux);
					if(aux==1)
					{
						for(a=pos; a<TLP-1 ; a++)
						{
							TabProd[a].cod=TabProd[a+1].cod;
							TabProd[a].codForne=TabProd[a+1].codForne;
							TabProd[a].estoque=TabProd[a+1].estoque;
							TabProd[a].preco=TabProd[a+1].preco;
							TabProd[a].validade.d=TabProd[a+1].validade.d;
							strcpy(TabProd[a].desc,TabProd[a+1].desc);
						}
						TLP--;
						gotoxy(17,23);
						printf("*** Produto EXLUIDO!!! ***");
					}
					
				}
				break;
			case 2:
				system("cls");
				Formulario();
				gotoxy(27,3);
				printf("*** Exclusão de Dados ***");
				gotoxy(5,7);
				printf("Digite o Codigo do Fornecedor: ");
				scanf("%d", &aux);
				pos=BuscarForne(TabForne,TLF,aux);
				
				if(pos==-1)
				{
					gotoxy(17,23);
					printf("*** Fornecedor NAO ENCONTRADO ***");
				}
				else
				{
					gotoxy(5,8);
					printf("Fornecedor: %s",TabForne[pos].nomeForne);
					gotoxy(5,9);
					printf("Excluir: 1 = SIM | 2 = NAO : ");
					scanf("%d",&aux);
					if(aux==1)
					{
							for(a=pos ; a<TLF ; a++)
						{
							TabForne[a].codFornecedor=TabForne[a+1].codFornecedor;
							strcpy(TabForne[a].nomeForne,TabForne[a+1].nomeForne);
							strcpy(TabForne[a].cidadeForne,TabForne[a+1].cidadeForne);
						}
						TLF--;
						gotoxy(17,23);
						printf("*** Fornecedor EXLUIDO!!! ***");
					}
					
				}
				
				break;
			case 3:
				system("cls");
				Formulario();
				gotoxy(27,3);
				printf("*** Exclusão de Dados ***");
				gotoxy(5,7);
				printf("Digite o CPF do Cliente: ");
				scanf("%d", &aux);
				pos=BuscarCPF(TabCliente,TLC,aux);
				
				if(pos==-1)
				{
					gotoxy(17,23);
					printf("*** Cliente NAO LOCALIZDO ***");
				}
				else
				{
					gotoxy(5,8);
					printf("Cliente: %s",TabCliente[pos].NomeCli);
					gotoxy(5,9);
					printf("Excluir: 1 = SIM | 2 = NAO : ");
					scanf("%d",&aux);
					if(aux==1)
					{
						for(a=pos ; a<TLC ; a++)
						{
							TabCliente[a].cpf=TabCliente[a+1].cpf;
							TabCliente[a].qntdCompra=TabCliente[a+1].qntdCompra;
							TabCliente[a].ValorTotComprado=TabCliente[a+a].ValorTotComprado;
							strcpy(TabCliente[a].NomeCli,TabCliente[a+1].NomeCli);
												
						}
						TLC--;
						gotoxy(17,23);
						printf("*** Cliente EXLUIDO!!! ***");
					}
				}		
				break;
		}
		gotoxy(5,10);
		printf("Nova Exclusão? 1 = SIM | 2 = NAO");
		scanf("%d",&opc);
	}while(opc==1);
}
void mudarpreco(tpFornecedor tabforne[tf],tpProduto tabprod[tf],int TLF, int TLP)
{
	int i,cod,pos,opc=1;
	float porce;
	system("cls");
	Formulario();
	gotoxy(27,3);
	printf("*** Exclusão de Dados ***");
	gotoxy(5,7);
	while(opc==1)
	{
		gotoxy(5,7);
		printf("Digite o Codigo do Fornecedor: ");
		scanf("%d", &cod);
		pos=BuscarForne(tabforne,TLF,cod);
		
		if(pos==-1)
		{
			gotoxy(17,23);
			printf("***  Fornecedor NAO encontrado  ***");
		}
		else
		{
			gotoxy(5,8);
			printf("Digite o aumento em porcentagem: ");
			scanf("%f", &porce);
			for(i=0;i<TLF;i++)
			{
				if(tabprod[i].codForne==cod)
				{
					tabprod[i].preco=tabprod[i].preco+(tabprod[i].preco*porce/100); // calculo de mudança de preço
				}
				//valor*15/100;
			}
			gotoxy(17,23);
			printf("*** Aumentos Efetuados ***");
			
			gotoxy(5,10);
			printf("Novo aumento? 1 = Sim | 0 = Nao");
			scanf("%d",&opc);
			
		}

			//gotoxy(5,8);
//			printf("Outra Alteracao? S=1|N=0: ");
//			scanf("%d",&opc);
			if(opc==1)
			{
				system("cls");
				Formulario();
			}	
	}
	
		
	
}
void relatoriovenda(tpProduto tabprod[tf],tpFornecedor tabforne[tf],tpCliente tabcli[tf],tpVendasProdutos tabVendasP[tf],tpVendas tabVenda[tf],int &TLP, int &TLF, int &TLC,int &TLVP,int &TLV)
{
	int i,j,y,posprod,posforne,b;
	
	for(i=0,y=7;i<TLV;i++)
	{

		gotoxy(5,y);
		printf("Codigo da Venda: %d",tabVenda[i].CodVenda);
		
		for(j=0; j<TLVP; j++)
		{
			if(tabVendasP[j].CodVenda==tabVenda[i].CodVenda)
			{
				y++;
				posprod=BuscarProd(tabprod,TLP,tabVendasP[j].CodProd);
				posforne=BuscarForne(tabforne,TLF,tabprod[posprod].codForne);
				gotoxy(5,y);
				printf("%d",tabVendasP[j].CodProd);	
				gotoxy(12,y);
				printf("%s",tabprod[posprod].desc);			
				gotoxy(33,y);
				printf("%d",tabVendasP[j].qntd);
				gotoxy(40,y);
				printf("%.2f",tabVendasP[j].ValorUni*tabVendasP[j].qntd);
				gotoxy(12,y);
				printf("%s",tabforne[posforne].nomeForne);
			}
			
		}
		
		gotoxy(5,y);
		printf("Total: %.2f",tabVenda[i].TotVenda);
		y++;	
		gotoxy(5,y);
		printf("------------------------------------------------------------------------");
		y++;
		if(y>13)
		{
			y++;
			gotoxy(5,y);
			printf("Aperte espaco para mostrar mais produtos;");
			b=getch();
			y++;
			gotoxy(5,y+1);
			getch();	
			limpartela();
			y=6;
		}
	}
	
	
	
	
}

void relatorio(tpProduto tabprod[tf],tpFornecedor tabforne[tf],tpCliente tabcli[tf],tpVendasProdutos tabvendap[tf],tpVendas tabvendas[tf],int &TLP, int &TLF, int &TLC,int &TLVP,int &TLV)
{
	int esc,codaux,pos,opc,i,a,y,b;
	
	system("cls");
	Formulario();
	gotoxy(27,3);
	printf("*** Relatorios  ***");
	
	do
	{
		gotoxy(5,7);
		printf("1 = Produtos ");
		gotoxy(5,8);
		printf("2 = Fornecedores ");
		gotoxy(5,9);
		printf("3 = Clientes ");
		gotoxy(5,10);
		printf("4 = Vendas");
		gotoxy(5,11);
		printf("Digite o numero desejado:");
		scanf("%d",&esc);
		limpartela();
		switch(esc)
		{
			case 1:
				gotoxy(5,7);
				printf("Relatorio de produto");
				gotoxy(5,8);
				printf("Digite o codigo do Fornecedor: ");
				scanf("%d", &codaux);
				pos=BuscarForne(tabforne,TLF,codaux);
				
				if(pos==-1)
				{
					gotoxy(17,23);
					printf("*** Fornecedor NAO encontrado ***");
				}
				else
				{
					limpartela();
					for(i=0,y=6;i<TLP;i++,y++)
					{
						if(tabprod[i].codForne==codaux)
						{	
								gotoxy(5,y);
								printf("-----------------------------------------------------------------");
								y++;
								gotoxy(5,y);
								printf("ID: %d | Nome: %s | Estoque: %d | Preco: %.2f "
								,tabprod[i].cod,tabprod[i].desc,tabprod[i].estoque,tabprod[i].preco);
								y++;
								gotoxy(5,y);
								printf("|Data de validade: %d/%d/%d | ID Fornecedor: %d ",tabprod[i].validade,tabprod[i].codForne);
								if(y>14)
								{
								y++;
								gotoxy(5,y+1);
								printf("Aperte espaco para mostrar mais produtos;");
								b=getch();
								if(b==32)
								{
									limpartela();
									y=6;	
								}	
								}
							
							
						
							
						}
						
					}
				}
				
				break;
			case 2:
				gotoxy(5,7);
				printf("Relatorio de Fornecedor");
				gotoxy(5,8);
				printf("Digite o codigo do Fornecedor: ");
				scanf("%d", &codaux);
				pos=BuscarForne(tabforne,TLF,codaux);
				
				if(pos==-1)
				{
					gotoxy(17,23);
					printf("*** Fornecedor NAO encontrado ***");
				}
				else
				{
					gotoxy(5,7);
					printf("-----------------------------------------------------------------");
					gotoxy(5,8);
					printf("ID: %d | Nome: %s | Cidade: %s",tabforne[pos].codFornecedor,tabforne[pos].nomeForne,tabforne[pos].cidadeForne);
					gotoxy(5,9);
					printf("-----------------------------------------------------------------");
				}
				break;
			case 3:
				gotoxy(5,7);
				printf("Relatorio de Cliente");
				gotoxy(5,8);
				printf("Digite o CPF do Cliente: ");
				scanf("%d", &codaux);
				pos=BuscarCPF(tabcli,TLC,codaux);
				
				if(pos==-1)
				{
					gotoxy(17,23);
					printf("*** Cliente NAO encontrado ***");
				}
				else
				{
					
					gotoxy(5,7);
					printf("-----------------------------------------------------------------");
					gotoxy(5,8);
					printf("CPF: %d | Nome: %s | Qtde comprada: %d | Total: %.2f",tabcli[pos].cpf,tabcli[pos].NomeCli,tabcli[pos].qntdCompra,tabcli[pos].ValorTotComprado);
					gotoxy(5,9);
					printf("-----------------------------------------------------------------");	
				}
				break;
			case 4:
				relatoriovenda(tabprod,tabforne,tabcli,tabvendap,tabvendas,TLP,TLF,TLC,TLVP,TLV);
				break;
		}
		
	}while(opc==1);
}

int main(void)
{
	
	int tlp=0,tlf=0,tlc=0,tlv=0,tlvp=0;
	char op;
	struct tpProduto Produtos[tf];
	struct tpFornecedor Fornecedor[tf];
	struct tpCliente Cliente[tf];
	struct tpVendas Vendas[tf];
	struct tpVendasProdutos Vendas_Prod[tf];
	 
	 Formulario();
	 
	 
	 gotoxy(27,3);
	 textcolor(1);
	 printf(" * * * Produtos * * * ");
	
	 do{

		 gotoxy(4,5);
		 op=menu();
		 switch(op){
		 	case 'A': 
		 		system("cls");
		 		Formulario();
		 		
		 		CadProduto(Produtos,Fornecedor,tlf,tlp);
		 	
		 		break;
			case 'B': 
					system("cls");
		 			Formulario();
		 		CadFornecedor(Fornecedor,tlf);
		 		
				break;
		 	case 'C': 
		 			system("cls");
		 			Formulario();
		 			CadCliente(Cliente,tlc);
		 		break;
		 	case 'D': 
		 			system("cls");
		 			Formulario();
		 			Venda(Vendas,Cliente,Produtos,Vendas_Prod,tlv,tlc,tlp,tlvp);
		 		break;
		 	case 'E': 
			 		system("cls");
		 			Formulario();
		 			consulta(Produtos,Fornecedor,Cliente,tlp,tlf,tlc);
			 // Consulta
		 		break;
		 	case 'F': 
		 			system("cls");
		 			Formulario();
					excluir(Produtos,Fornecedor,Cliente,tlp,tlf,tlc);
		 		break;
		 	case 'G': 
		 			mudarpreco(Fornecedor,Produtos,tlf,tlp);
		 		break;
		 	case 'H': 
		 			relatorio(Produtos,Fornecedor,Cliente,Vendas_Prod,Vendas,tlp,tlf,tlc,tlvp,tlv);
		 		break;
			case 'I': 
					InserirDados(Produtos,Cliente,Fornecedor,tlp,tlc,tlf);
		 		break;	
		 		
		 			 
			}	
		 getch();
		 system("cls");
		 Formulario();
		 
	 }while(op != 27);

	 
	return 0;
}
