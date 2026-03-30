#include "arvore.h"
//Le os dados de um funcionario e atribui a um struct Funcionario
void cadastro_funcionario( Funcionario *funcionario) {
	char nome[100], cargo[100];
	int matricula;
	double salario;

	//Le os dados
	printf("\nNumero de matricula: ");
	scanf("%d", &matricula);
	printf("\nNome: ");
	scanf("%s", nome);
	printf("\nCargo: ");
	scanf("%s", cargo);
	printf("\nSalario: ");
	scanf("%lf", &salario);

	//Atribui os dados lidos para funcionario 
	funcionario->matricula = matricula;
	strcpy(funcionario->nome, nome);
	strcpy(funcionario->cargo, cargo);
	funcionario->salario = salario;
}

//cria um novo No caso não exista, se existir percorre a arvore até achar o seu lugar adequado
void inserir_no(No **no, Funcionario *funcionario) {
	if(*no == NULL) {
	    
		//Aloca memoria para um novo No
		*no = malloc(sizeof(No));
		
		//Atribui os dados de funcionario para o novo no criado
		(*no)->funcionario = funcionario;
		(*no)->ponteiro_esquerda = NULL;
		(*no)->ponteiro_direita = NULL;
		
	} else {

		//Compara a matricula para decidir se insere na subarvore esquerda ou direita
		if(funcionario->matricula < (*no)->funcionario->matricula) {
			inserir_no(&((*no)->ponteiro_esquerda), funcionario);
		} else if(funcionario->matricula > (*no)->funcionario->matricula) {
			inserir_no(&(*no)->ponteiro_direita, funcionario);
		}
		
	}
}

//percorre a arvore com o metodo in_ordem SAE - ROOT - SAD
void in_ordem(No *no){
    if(no != NULL){

        in_ordem((*no).ponteiro_esquerda);
        printf("\nDados do funcionário:\n");
        printf("Numero da Matrícula: %d\n", no->funcionario->matricula);
        printf("Nome: %s\n", no->funcionario->nome);
        printf("Cargo: %s\n", no->funcionario->cargo);
        printf("Salario: %.2f\n", no->funcionario->salario);
        in_ordem((*no).ponteiro_direita);
    }
}
 
//libera a memoria alocada
void liberar_arvore(No *no){
    if(no != NULL){
        liberar_arvore(no->ponteiro_esquerda);
        liberar_arvore(no->ponteiro_direita);
        free(no->funcionario);
        free(no);
    }
}

//Percorre a arvore buscando o valor da Matricula passada
Funcionario* buscar_matricula(No *raiz, int matricula) {

	// Retorna se a arvore estiver vazia
	if (raiz == NULL) return 0;

	if (raiz->funcionario->matricula == matricula) {
		return raiz->funcionario; // retorna o ponteiro se ele existir
	}

	// recursão pra varrer a subárvore
	if (matricula < raiz->funcionario->matricula) {
		return buscar_matricula(raiz->ponteiro_esquerda, matricula);
	} else {
		return buscar_matricula(raiz->ponteiro_direita, matricula);
	}
}

void atualizar_funcionario(No *raiz, int matricula) {
	Funcionario *func = buscar_matricula(raiz, matricula);

	if (func != NULL) {
		printf("\nAtualizando os dados •••");
		
		printf("\nNome anterior\t%s ", func->nome);
		printf("\nNovo nome: ");
		scanf("%s", func->nome);

		printf("\nCargo anterior\t%s ", func->cargo);
		printf("\nNovo cargo: ");
		scanf("%s", func->cargo);

		printf("\nSalario anterior\t%.2lf ", func->salario);
		printf("\nNovo salário: ");
		scanf("%lf", &func->salario);

		printf("\n••• Dados atualizados");
	} else {
		printf("\nFuncionário não foi encontardo...");
	}
}
