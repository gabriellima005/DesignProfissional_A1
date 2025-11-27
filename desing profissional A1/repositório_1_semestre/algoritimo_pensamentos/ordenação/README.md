Análise de Algoritmos de Ordenação - Insertion Sort
Descrição do Problema e Métodos Implementados
Problema
Implementação e análise do algoritmo Insertion Sort para ordenação de vetores numéricos, com foco na comparação de desempenho entre diferentes cenários (melhor caso, pior caso e caso real).

Método Escolhido: Insertion Sort
Por que escolher o Insertion Sort?

Simplicidade: Algoritmo intuitivo e fácil de implementar

Eficiência em casos específicos: Excelente desempenho com vetores parcialmente ordenados

Estabilidade: Mantém a ordem relativa de elementos iguais

Ordenação in-place: Não requer memória adicional significativa

Como Compilar e Executar
Compilação
bash
gcc -O1 -std=c11 insertion_sort.c -o insertion_sort
Execução
bash
./insertion_sort
Política de Contagem de Passos e Medição de Tempo
Contagem de Passos
Métrica: Número de deslocamentos realizados durante a ordenação

Cada movimento de elemento dentro do vetor é contabilizado como um passo

Fórmula teórica:

Melhor caso (vetor ordenado): 0 deslocamentos

Pior caso (vetor reverso): ∑(n-1) = n(n-1)/2 deslocamentos

Medição de Tempo
Método: Clock da CPU usando clock() da biblioteca time.h

Precisão: Medido em segundos com precisão de 8 casas decimais

Metodologia: Média de 5 execuções consecutivas para reduzir variações

Resultados Experimentais
Estrutura do CSV
csv
algoritmo,tamanho,passos,tempo_medio
insertion_sort,10,15,0.00000120
Exemplo de Saída
text
=== ORDENACAO POR INSERTION SORT COM HISTORICO ===
Digite o tamanho do vetor (maximo 50): 5
Numero 1: 5
