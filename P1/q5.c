void imprimeTopN(int *v, int n, int m) {
    int *heap = (int*) malloc(m * sizeof(int));
    int tamanho = 0;

    // Construção do heap mínimo de tamanho m
    for (int i = 0; i < n; i++) {
        if (tamanho < m) {
            insereHeapMin(heap, v[i]); // insere no heap
            tamanho++;
        } else if (v[i] > heap[0]) {
            removeMinHeap(heap);       // remove o menor
            insereHeapMin(heap, v[i]); // insere o novo valor
        }
    }

    // Impressão dos m maiores em ordem crescente
    while (tamanho > 0) {
        int menor = removeMinHeap(heap); // remove retorna o menor
        printf("%d ", menor);
        tamanho--;
    }
    printf("\n");

    free(heap);
}
