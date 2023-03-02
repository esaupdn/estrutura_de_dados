#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaPilhaDesc.h"

int menu() {
	int op;
	printf("Agenda\n");
	printf("1 - Inserir evento\n");
	printf("2 - Desfazer evento\n");
	printf("0 - Sair\n");
	printf("Opcao: ");
	scanf("%d", &op);
	return op;
}

void main() {
	tPilha p1;
	inicializa(&p1);
	tdado dado;
	int op;

	
	do {
		op = menu();
		switch(op) {
			case 1:
				printf("Insira a data: \n");
				fflush(stdin);
				gets(dado.data);
				printf("Insira a descricao: \n");
				fflush(stdin);
				gets(dado.descricao);
				if(push(&p1, dado) == 1) {
					printf("Dados inseridos com sucesso!\n");
					getch();
					system("cls");
				}else {
					printf("Pilha cheia(Stack Overflow); o dado n foi inserido!\n");
					getch();
					system("cls");
				}
				break;
			case 2:
				if(!isEmpty(p1)) {
					dado = pop(&p1);
					printf("\nO evento foi removido: \n");
					printf("%s\n", dado.data);
					printf("%s\n", dado.descricao);
					getch();
					system("cls");
				}else {
					printf("agenda vazia; erro na remocao!");
				}
				break;
			case 0:
				printf("Saindo...\n");
				getch();
				break;
			default:
				printf("Opcao invalida!!!");
				break;
				
		}
	}while(op != 0);
}
