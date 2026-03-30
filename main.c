#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// header
#include "arvore.h"

int main() {
  int opcao = -1;
  No *no_raiz = NULL;
  int matricula_busca;
  Funcionario *func_encontrado;

  //O código usa %s, ele só aceita 1 string por vez, escrever 2 vai quebrar o código... 
  //exemplo de cadastro: nome = joão 

  //menu - autoexplicativo - organização do código
  do {
    printf("\nMenu •••");
    printf("\n1 - Cadastrar Funcionario");
    printf("\n2 - Buscar Funcionario");
    printf("\n3 - Listar");
    printf("\n4 - Atualizar Dados");
    printf("\n0 - Sair");
    printf("\nEscolha uma opcao: ");
    scanf("%i", &opcao);

    switch (opcao) {
    case 1: {
      Funcionario *funcionario = malloc(sizeof(Funcionario));
      cadastro_funcionario(funcionario);
      inserir_no(&no_raiz, funcionario); 

      break;
    }
    case 2:
      printf("\nDigite a matricula para busca: ");
      scanf("%d", &matricula_busca);
      func_encontrado = buscar_matricula(no_raiz, matricula_busca); //

      if (func_encontrado != NULL) {
        printf("\nDados do funcionario\n");
        printf("Numero da Matricula: %d\n", func_encontrado->matricula);
        printf("Nome: %s\n", func_encontrado->nome);
        printf("Cargo: %s\n", func_encontrado->cargo);
        printf("Salario: %.2f\n", func_encontrado->salario);
      } else {
        printf("Funcionario %d nao encontrado.\n", matricula_busca);
      }
      break;

    case 3:
      printf("\n••• Lista de Funcionarios");
      in_ordem(no_raiz);
      break;

    case 4:
      printf("\nMatricula para atualizar: ");
      scanf("%d", &matricula_busca);
      atualizar_funcionario(no_raiz, matricula_busca);

       if (func_encontrado != NULL) {
        printf("\nDados do funcionario\n");
        printf("Numero da Matricula: %d\n", func_encontrado->matricula);
        printf("Nome: %s\n", func_encontrado->nome);
        printf("Cargo: %s\n", func_encontrado->cargo);
        printf("Salario: %.2f\n", func_encontrado->salario);
      }
      
      break;

    case 0:
      printf("\nSaindo•-•-•\n");
      liberar_arvore(no_raiz); 
      break;

    default:
      printf("\nOpcao invalida!\n");
    }
  } while (opcao != 0);

  return 0;
}
