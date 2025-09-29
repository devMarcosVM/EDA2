#include <stdio.h> 

void sort(int *v, int n, int d){
    int div, i, j, k, l;
    fila *f[10];

    for(i = 0; i < 10; i++) f[i] = cria_fila();

    for (k=0; k < d; k++){
        for(i=0;i<n,i++){
            l = (v[i]/(int) pow(10,k))%10;
            enfileira(v[i], f[l]);
        }
        j = 0;
        for(i=0;i < 10;i++)
            while(!fila_vazia (f[i])) v[j++] = desenfileira (f[i]);
    }
}

//qual a complexidade do algoritmo apresentado? Justifique sucintamente
//R: O(d * (n + k)), onde d é o número de dígitos, n é o número de elementos e k é a base (10).
//Justificativa: O loop externo executa d vezes (número de dígitos), e para cada dígito,
//percorre n elementos para enfileirar e depois k filas para desenfileirar.

//qual a premissa que se deve conhecer da instancia do problema de ordenação para que o algoritmo apresentado funcione?
//R: É necessário conhecer o número máximo de dígitos (d) dos elementos a serem ordenados.
//O algoritmo funciona apenas com números inteiros não-negativos, pois utiliza operações
//de divisão e módulo para extrair dígitos individuais.

//quando compensa usar o algoritmo apresentado a o inves de um algoritmo com complexidade O(nlgn)
//R: Compensa quando d (número de dígitos) é pequeno em relação a log n, ou seja, quando
//d < log n. Por exemplo, para ordenar números de até 3 dígitos com milhares de elementos,
//pois O(3n) < O(n log n). Também é vantajoso quando se precisa de estabilidade na ordenação.