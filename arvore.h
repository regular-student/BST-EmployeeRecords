#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pre-definição cadastro
typedef struct {
	int matricula;
	char nome[100];
	char cargo[100];
	double salario;
} Funcionario;

//estrutura dos nós
typedef struct No {
	Funcionario *funcionario;
	struct No *ponteiro_esquerda;
	struct No *ponteiro_direita;
} No;


//protótipo dos métodos
void cadastro_funcionario(Funcionario *funcionario);
void inserir_no(No **no, Funcionario *funcionario);
void in_ordem(No *no);
void liberar_arvore(No *no);
Funcionario* buscar_matricula(No *raiz, int matricula);

#endif
