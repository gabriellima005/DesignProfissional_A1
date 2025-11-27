# 🔢 Projeto: Cálculo de Média de Estudantes

## 💡 Visão Geral

Este projeto é uma demonstração prática de conceitos fundamentais de **Programação Estruturada** e **Estruturas de Dados** na linguagem C.

O objetivo principal é gerenciar o cadastro e calcular a média de um número variável de estudantes, determinando se eles estão Aprovados, em Recuperação ou Reprovados.

---

## ⚙️ Tecnologias e Conceitos

| Categoria | Detalhe | Conceito Aplicado |
| :--- | :--- | :--- |
| **Linguagem** | **C** | Programação Estruturada. |
| **Estrutura de Dados** | `struct Estudante` | Uso de *structs* para agrupar dados relacionados (nome, matrícula, notas). |
| **Controle de Fluxo** | `for`, `if/else if/else` | Iteração sobre a quantidade de alunos e lógica condicional para avaliação. |
| **Entrada/Saída** | `scanf`, `printf` | Interação básica com o usuário no console. |

---

## 🚀 Funcionalidades

O programa executa as seguintes tarefas:

1.  **Entrada de Dados:** Solicita ao usuário a **quantidade de alunos** a ser processada (com validação de limite).
2.  **Iteração:** Repete o processo de coleta de dados para cada aluno, utilizando um laço de repetição (`for`).
3.  **Cálculo:** Calcula a média final do estudante.
4.  **Avaliação Condicional:**
    * **Aprovado(a):** Média $\ge 6.0$
    * **Recuperação:** Média $> 4.0$ e $< 6.0$
    * **Reprovado(a):** Média $\le 4.0$

---

## 📂 Código-Fonte

Aqui está o código completo do projeto para referência:

```c
#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar os dados de um estudante
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
	
	// Validação básica da quantidade
	if (quantidade > 50 || quantidade <= 0){
		printf("\nNumero Invalido. ");
	}
	else {
	
		for( int i = 0; i < quantidade; i++){
			
			printf("\n-----------------------------------------");
	
			printf("\nDigite o nome do Aluno: ");
			// Usando %[^\n] para ler a string com espaços
			scanf(" %[^\n]", aluno.nome);
			
			printf("\nDigite a matricula do Aluno: ");
			scanf("%d", &aluno.matricula);
			
			printf("\nPrimeira nota: ");
			scanf ("%f", &aluno.nota1);
			
			printf("\nSegunda nota: ");
			scanf("%f", &aluno.nota2);
			
			// Cálculo da Média
			aluno.media = (aluno.nota1 + aluno.nota2) / 2;
			
			printf("\nMedia do %s: %.2f \n", aluno.nome, aluno.media);
			
			// Estrutura Condicional para Avaliação
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
