#include <stdio.h>
#include <string.h>

struct Estudante{
	char nome[50];
	int matricula;
	float nota1;
	float nota2;
	float media;
};

int main(){
	struct Estudante aluno;
	int quantidade;
	
	printf("Numero de alunos: ");
	scanf("%d", &quantidade);
	if (quantidade > 50 || quantidade <= 0){
		printf("\nNumero Invalido. ");
	}
	else {
	
		for( int i = 0; i < quantidade; i++){
			
			printf("\n-----------------------------------------");
	
			printf("\nDigite o nome do Aluno: ");
			scanf(" %[^\n]", &aluno.nome);
			
			printf("\nDigite o rgm do Aluno: ");
			scanf("%d", &aluno.matricula);
			
			printf("\nPrimeira nota: ");
			scanf ("%f", &aluno.nota1);
			
			printf("\nSegunda nota: ");
			scanf("%f", &aluno.nota2);
			
			aluno.media= (aluno.nota1 + aluno.nota2) /2;
			
			printf("\nMedia do %s: %.2f \n", aluno.nome, aluno.media);
			
			if (aluno.media >= 6 ){
				printf("\nAprovado(a)! ");
			} else if (aluno.media > 4 && aluno.media < 6){
				printf("\nRecuperacao!");
			}else{
				printf("\nReprovado(a)!");
			}
		}
	}
	return 0;
}
