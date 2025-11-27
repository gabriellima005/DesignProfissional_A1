#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORICO 100

struct Operacao {
    char descricao[100];
    double numeros[30];
    double euler ;
    int termos;
    int numero_fatorial;
    int escolha;
    int quantidade;
    float soma ;
    long long resultado_fatorial ;
    float resultado;
    double raiz;
    double base;
    double expoente;
    double numero1;
    double numero2;
    double casos;
    double favoraveis;
};

struct Operacao historico[MAX_HISTORICO];
int contador = 0;


void exibirMenu() {
    printf("\n");
    printf("=============================================================\n");
    printf("   BEM-VINDO À CALCULADORA CIENTÍFICA\n");
    printf("=============================================================\n");
    printf("0  - Sair\n");
    printf("1  - Adicao\n");
    printf("2  - Subtracao\n");
    printf("3  - Multiplicacao\n");
    printf("4  - Divisao\n");
    printf("5  - Expoente\n");
    printf("6  - Raiz Quadrada\n");
    printf("7  - Raiz Cúbica\n");
    printf("8  - Seno\n");
    printf("9  - Coseno\n");
    printf("10 - Tangente\n");
    printf("11 - Arcoseno\n");
    printf("12 - Arcocosseno\n");
    printf("13 - Arcotangente\n");
    printf("14 - Logaritmo Decimal\n");
    printf("15 - Logaritmo Natural\n");
    printf("16 - Constante de Euler\n");
    printf("17 - Fatorial\n");
    printf("18 - Media aritmetica\n");
    printf("19 - Probabilidade\n");
    printf("20 - Valor Absoluto\n");
    printf("21 - Hipotenusa\n");
    printf("22 - Potencia de 10\n");
    printf("23 - Função Hiperbólica Seno\n");
    printf("24 - Função Hiperbólica Cosseno\n");
    printf("25 - Funcão Hiperbólica Tangente\n");
    printf("26 - Mostrar histórico\n");
    printf("--------------------------------------------------------------\n");
    printf("Escolha a operacao: ");
}

void adicionarHistorico(char descricao[], double resultado) {
    if (contador < MAX_HISTORICO) {
        strcpy(historico[contador].descricao, descricao);
        historico[contador].resultado = resultado;
        contador++;
    }
}

void mostrarHistorico(){
    if (contador == 0) {
        printf("\nNenhuma operação realizada ainda.\n");
        return;
    }

    printf("\n===== HISTÓRICO DE OPERAÇÕES =====\n");
    for (int i = 0; i < contador; i++) {
        printf("%d. %s = %.2lf\n", i + 1, historico[i].descricao, historico[i].resultado);
    }
    printf("==================================\n");
}

int main() {
    
    struct Operacao tipo;
    char descricao[100];

    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        exibirMenu();
        if (scanf("%d", &tipo.escolha) != 1) {  
            printf("Entrada invalida! Digite apenas numeros.\n");
            printf("\nPressione ENTER para voltar ao menu...");
            getchar();
            getchar();
            while (getchar() != '\n');
            tipo.escolha = -1; 
            continue;
        }

        switch (tipo.escolha) {
            case 0:
                printf("\nSaindo...\n");
                break;

            case 1: 
                printf("\nQuantos numeros voce deseja somar?: ");
                scanf("%d", &tipo.quantidade);
                
                if (tipo.quantidade <= 1){
                    printf("\nE preciso de 2 numeros para fazer uma Soma. \n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                tipo.resultado = 0;
                
                for (int i = 0; i < tipo.quantidade; i++) {
                    printf("\nDigite o %dº numero: ", i+1);
                    scanf("%lf", &tipo.numeros[i]);
                    tipo.resultado += tipo.numeros[i];
                }
                sprintf(descricao, "Soma de %d numeros", tipo.quantidade);
                
                printf("\nResultado: %.2lf\n", tipo.resultado);
                
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 2: 
                printf("\nQuantos numeros voce deseja subtrair?: ");
                scanf("%d", &tipo.quantidade);
                
                if (tipo.quantidade <= 1){
                    printf("\nE preciso de 2 numeros para fazer uma Subtracao. \n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;    
                } 
                
                printf("Digite o 1º numero: ");
                scanf("%lf", &tipo.numeros[0]);
                
                tipo.resultado = tipo.numeros[0];
                
                for (int i = 1; i < tipo.quantidade; i++) {
                    printf("\nDigite o %dº numero para subtrair: ", i+1);
                    scanf("%lf", &tipo.numeros[i]);
                    tipo.resultado -= tipo.numeros[i];
                }
                
                sprintf(descricao, "Subtracao de %d numeros", tipo.quantidade);
                
                printf("\nResultado: %.2lf\n", tipo.resultado);
                
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 3: 
                printf("\nQuantos numeros voce deseja multiplicar?: ");
                scanf("%d", &tipo.quantidade);
                
                if (tipo.quantidade <= 1){
                    printf("\nEscolha pelo menos 2 numeros.\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                tipo.resultado = 1;
                
                for (int i = 0; i < tipo.quantidade; i++) {
                    printf("\nDigite o %dº numero: ", i+1);
                    scanf("%lf", &tipo.numeros[i]);
                    tipo.resultado *= tipo.numeros[i];
                }
                sprintf(descricao, "Multiplicacao de %d numeros", tipo.quantidade);
                
                printf("\nResultado: %.2lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 4: 
                printf("Quantos numeros voce deseja dividir?: ");
                scanf("%d", &tipo.quantidade);
                
                if (tipo.quantidade <= 1) {
                    printf("\nEscolha pelo menos 2 numeros.\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                printf("\nDigite o 1º numero: ");
                scanf("%lf", &tipo.numeros[0]);
                
                tipo.resultado = tipo.numeros[0];
                int erro = 0;
                
                for (int i = 1; i < tipo.quantidade; i++) {
                    printf("\nDigite o %dº numero: ", i+1);
                    scanf("%lf", &tipo.numeros[i]);
                    
                    if (tipo.numeros[i] == 0) {
                        printf("\nNao e possivel divir por 0.\n");
                        erro = 1;
                        break;
                    }
                    tipo.resultado /= tipo.numeros[i];
                }
                if (!erro) {
                    sprintf(descricao, "Divisao de %d numeros", tipo.quantidade);
                
                    printf("\nResultado: %.2lf\n", tipo.resultado);
                    adicionarHistorico(descricao, tipo.resultado);
                }

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 5: 
                printf("Digite a base: ");
                scanf("%lf", &tipo.base);
                
                printf("Digite o expoente: ");
                scanf("%lf", &tipo.expoente);
                
                if (tipo.base == 0 && tipo.expoente == 0){
                    printf("\nNao e possivel fazer o calculo com esses numeros.\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                tipo.resultado = pow(tipo.base, tipo.expoente);
                
                sprintf(descricao, "%.2lf elevado a %.2lf", tipo.base, tipo.expoente);
                printf("\nResultado: %.2lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 6: 
                printf("\nDigite o numero da raiz quadrada: ");
                scanf("%lf", &tipo.raiz);
                
                if (tipo.raiz < 0) {
                    printf("\nNao e possivel calcular raiz quadrada de numero negativo.\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                tipo.resultado = sqrt(tipo.raiz);
                
                sprintf(descricao, "Raiz Quadrada de %.2lf", tipo.raiz);
                printf("\nResultado: %.2lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 7: 
                printf("\nDigite o numero que deseja saber a raiz cubica: ");
                scanf("%lf", &tipo.raiz);
                
                tipo.resultado = cbrt(tipo.raiz);
                
                sprintf(descricao, "Raiz Cubica de %.2lf", tipo.raiz);
                printf("\nResultado: %.2lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 8: 
                printf("\nDigite o numero do Seno: ");
                scanf("%lf", &tipo.numero2);
                
                tipo.resultado = sin(tipo.numero2);
                
                sprintf(descricao, "Seno de %.2lf", tipo.numero2);
                printf("\nResultado: %.4lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 9: 
                printf("\nDigite o numero do Cosseno: ");
                scanf("%lf", &tipo.numero2);
                
                tipo.resultado = cos(tipo.numero2);
                
                sprintf(descricao, "Cosseno de %.2lf", tipo.numero2);
                printf("\nResultado: %.4lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 10: 
                printf("\nDigite o numero da Tangente: ");
                scanf("%lf", &tipo.numero2);
                
                tipo.resultado = tan(tipo.numero2);
                
                sprintf(descricao, "Tangente de %.2lf", tipo.numero2);
                printf("\nResultado: %.4lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 11: 
                printf("\nDigite o numero do Arcoseno: ");
                scanf("%lf", &tipo.numero2);
                
                if (tipo.numero2 < -1 || tipo.numero2 > 1) {
                    printf("nao e possivel saber o Arcoseno desse numero\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                tipo.resultado = asin(tipo.numero2);
                
                sprintf(descricao, "Arcoseno de %.2lf", tipo.numero2);
                printf("\nResultado: %.4lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 12: 
                printf("\nDigite o numero do Arcocosseno: ");
                scanf("%lf", &tipo.numero2);
                
                if (tipo.numero2 < -1 || tipo.numero2 > 1) {
                    printf("\nNao e possivel saber o Arcocosseno.\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                tipo.resultado = acos(tipo.numero2);
                
                sprintf(descricao, "Arcocosseno de %.2lf", tipo.numero2);
                printf("\nResultado: %.4lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 13:
                printf("\nDigite o numero do Arcotangente: ");
                scanf("%lf", &tipo.numero2);
                
                tipo.resultado = atan(tipo.numero2);
                
                sprintf(descricao, "Arcotangente de %.2lf", tipo.numero2);
                printf("\nResultado: %.4lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 14: 
                printf("\nDigite o numero do logaritmo decimal: ");
                scanf("%lf", &tipo.numero2);
                
                if (tipo.numero2 <= 0) {
                    printf("\nNao e possivel usar o numero 0.\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                tipo.resultado = log10(tipo.numero2);
                
                sprintf(descricao, "Logaritmo Decimal de %.2lf", tipo.numero2);
                printf("\nResultado: %.4lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 15: 
                printf("\nDigite o numero do logaritmo natural: ");
                scanf("%lf", &tipo.numero2);
                
                if (tipo.numero2 <= 0) {
                    printf("\nNao e possivel usar o numero 0.\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                tipo.resultado = log(tipo.numero2);
                
                sprintf(descricao, "Logaritmo Natural de %.2lf", tipo.numero2);
                printf("\nResultado: %.4lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 16: 
                printf("\nDigite quantos termos deseja usar na aproximacao de euler: ");
                scanf("%d", &tipo.termos);
                
                if (tipo.termos <= 0){
                    printf("\nQuantidade de termos invalida.\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;  
                } 
                
                tipo.euler = 0.0;
                
                for (int i = 0; i < tipo.termos; i++) {
                    double fat = 1.0;
                    for (int j = 1; j <= i; j++) 
                    fat *= j;
                    tipo.euler += 1.0 / fat;
                }
                
                sprintf(descricao, "Constante de Euler com %d termos", tipo.termos);
                
                printf("\nConstante de Euler: %.*f\n", tipo.termos, tipo.euler);
                adicionarHistorico(descricao, tipo.euler);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 17: 
                printf("\nDigite o numero fatorial: ");
                scanf("%d", &tipo.numero_fatorial);
                
                if (tipo.numero_fatorial < 0){
                    printf("\nnao da pra usar numero negativo para calcular fatorial.\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                tipo.resultado_fatorial = 1;
                
                for (int i = 1; i <= tipo.numero_fatorial; i++) 
                tipo.resultado_fatorial *= i;
                
                sprintf(descricao, "Fatorial de %d", tipo.numero_fatorial);
                printf("\nResultado: %lld\n", tipo.resultado_fatorial);
                adicionarHistorico(descricao, (double)tipo.resultado_fatorial);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 18: 
                printf("\nQuantos numeros deseja calcular a media?: ");
                scanf("%d", &tipo.quantidade);
                
                if (tipo.quantidade <= 0 || tipo.quantidade > 50) {
                    printf("\nQuantidade invalida. Escolha entre 1 e 50 numeros.\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                tipo.soma = 0;
                
                for (int i = 0; i < tipo.quantidade; i++) {
                    printf("\nDigite o %dº numero: ", i+1);
                    scanf("%lf", &tipo.numeros[i]);
                    tipo.soma += tipo.numeros[i];
                }
                
                tipo.resultado = tipo.soma / tipo.quantidade;
                
                sprintf(descricao, "Media de %d numeros", tipo.quantidade);
                
                printf("\nMedia: %.2lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 19: 
                printf("\nDigite a quantidade de casos favoraveis: ");
                scanf("%lf", &tipo.favoraveis);
                
                printf("\nDigite a quantidade total de casos: ");
                scanf("%lf", &tipo.casos);
                
                if (tipo.casos <= 0 || tipo.favoraveis < 0 || tipo.favoraveis > tipo.casos) {
                    printf("\nValores invalidos para probabilidade.\n");
                    printf("\nPressione ENTER para voltar ao menu...");
                    getchar();
                    getchar();
                    break;
                }
                
                tipo.resultado = (tipo.favoraveis / tipo.casos) * 100;
                
                sprintf(descricao, "Probabilidade %.0lf/%.0lf", tipo.favoraveis, tipo.casos);
                printf("\nProbabilidade: %.2lf%%\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 20: 
                printf("\nDigite o numero para saber o valor absoluto: ");
                scanf("%lf", &tipo.numero2);
                
                tipo.resultado = fabs(tipo.numero2);
                
                sprintf(descricao, "Valor Absoluto de %.2lf", tipo.numero2);
                printf("\nValor Absoluto: %.2lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 21: 
                printf("Digite o 1º cateto: ");
                scanf("%lf", &tipo.numero1);
                
                printf("Digite o 2º cateto: ");
                scanf("%lf", &tipo.numero2);
                
                tipo.resultado = sqrt(pow(tipo.numero1, 2) + pow(tipo.numero2, 2));
                
                sprintf(descricao, "Hipotenusa de %.2lf e %.2lf", tipo.numero1, tipo.numero2);
                printf("\nResultado: %.2lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 22: 
                printf("\nDigite o expoente: ");
                scanf("%lf", &tipo.numero1);
                
                tipo.resultado = pow(10, tipo.numero1);
                
                sprintf(descricao, "10 elevado a %.2lf", tipo.numero1);
                printf("\nResultado: %.2lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 23: 
                printf("\nDigite o numero: ");
                scanf("%lf", &tipo.numero1);
                
                tipo.resultado = sinh(tipo.numero1);
                
                sprintf(descricao, "Seno Hiperbolico de %.2lf", tipo.numero1);
                printf("\nResultado: %.4lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 24: 
                printf("\nDigite o numero: ");
                scanf("%lf", &tipo.numero1);
                
                tipo.resultado = cosh(tipo.numero1);
                
                sprintf(descricao, "Cosseno Hiperbolico de %.2lf", tipo.numero1);
                printf("\nResultado: %.4lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;
    
            case 25: 
                printf("\nDigite o numero: ");
                scanf("%lf", &tipo.numero1);
                
                tipo.resultado = tanh(tipo.numero1);
                
                sprintf(descricao, "Tangente Hiperbolica de %.2lf", tipo.numero1);
                printf("\nResultado: %.4lf\n", tipo.resultado);
                adicionarHistorico(descricao, tipo.resultado);
                
                
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            case 26: 
                mostrarHistorico();
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();
                getchar();
                break;
        }

        

    } while (tipo.escolha != 0);

    return 0;
}