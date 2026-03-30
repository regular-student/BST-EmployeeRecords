#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//header
#include "arvore.h"

int main() {

	No *no_raiz = NULL;
	int tamanho = 16; //valor fixo apenas para testes

	for (int i = 0; i < tamanho; i++) {

		Funcionario *funcionario = malloc(sizeof(Funcionario));

		cadastro_funcionario(funcionario);

		inserir_no(&no_raiz, funcionario);

	}

	int matricula_busca;
	Funcionario *func_encontrado;

	printf("Digite a matricula: ");
	scanf("%i", &matricula_busca);

	func_encontrado = buscar_matricula(no_raiz, matricula_busca);

	//Com o ponteiro que a função buscar_matricula retorna, nós temos todos os dados do nó:
	if (func_encontrado != NULL) {
	     printf("\nDados do funcionario\n");
	     printf("Numero da Matricula: %d\n", func_encontrado->matricula);
	     printf("Nome: %s\n", func_encontrado->nome);
	     printf("Cargo: %s\n", func_encontrado->cargo);
	     printf("Salario: %.2f\n", func_encontrado->salario);
	} else {
	     printf("Funcionario %d nao encontrado.\n", matricula_busca);
	}

    in_ordem(no_raiz);
	liberar_arvore(no_raiz);

	return 0;
}
