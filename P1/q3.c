void ordena(int *A, int lo, int hi){
    if(lo < hi){
        int p=processa(A, lo,hi);
        ordena(A,lo,p-1);
        ordena(A,p + 1, hi);
    }
}

int processa(int *A, int lo,int hi){
    int p = A[hi],i = lo;
    for (int j = lo; j
    )
}

Existe um grande numero de implmentações para algoritmos de ordenação. um dos fatores a serem considerados, por exemplo, é o numero maximo e médio de comparações que são necessárias para ordenar um vetor com n elementos. Diz-se também que um algoritmo de ordenação é estável se ele  preserva a ordem de elementos que são iguais, isto é, se tais elementos aparecem na sequencia ordenada na mesma ordem em que estão na sequencia inicial. analise o algoritmo abaixo, onde a é um vetor e "i,j,lo e hi" são indices do vetor:

