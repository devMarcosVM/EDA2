// Considere o algoritmo de particionamento, essencial para o QuickSort

int particiona(int*v, int e,int d){
    int p = v[d]; // pivo
    int t, j = e;
    for(int k = e;k<d;k++){
        if(v[k]<=p){
        t = v[j], v[j] = v[k] = t;
        ++j;
        }
        t = v[j], v[j] = v[r],v[r] = t;
        return j;
    }
}
a) ilustre a execução do algoritmo particiona para o vetor v = [13,19,9,5,12]

b) qual valor de j que particiona retorna se o todos os elementos de v forem iguais?