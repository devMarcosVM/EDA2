#include <stdio.h>   // Inclui biblioteca padrão de entrada/saída para printf, scanf, etc.

// Função que implementa o algoritmo Radix Sort para ordenar um vetor de inteiros
void sort(int *v, int n, int d){
    int div, i, j, k, l;          // Declara 5 variáveis inteiras:
                                  // div: não usada (pode ser removida)
                                  // i, j: contadores para loops
                                  // k: contador do dígito atual (0=unidades, 1=dezenas, etc.)
                                  // l: armazena o dígito extraído do número
    
    fila *f[10];                  // Declara array de 10 ponteiros para filas (uma para cada dígito 0-9)

    for(i = 0; i < 10; i++)       // Loop que executa 10 vezes (i vai de 0 até 9)
        f[i] = cria_fila();       // Inicializa cada fila chamando função cria_fila()

    for (k=0; k < d; k++){        // Loop externo: executa d vezes (d = número máximo de dígitos)
                                  // k representa qual dígito está sendo processado (0=menos significativo)
        
        for(i=0;i<n;i++){         // ERRO DE SINTAXE: deveria ser for(i=0; i<n; i++)
                                  // Loop que percorre todos os n elementos do vetor
            
            l = (v[i]/(int) pow(10,k))%10;  // Extrai o k-ésimo dígito do número v[i]:
                                            // 1. v[i] é o número atual
                                            // 2. pow(10,k) calcula 10^k (1, 10, 100, 1000...)
                                            // 3. (int) converte resultado para inteiro
                                            // 4. v[i]/pow(10,k) "remove" dígitos à direita
                                            // 5. %10 pega apenas o último dígito restante
                                            // Exemplo: para 1234 e k=1: 1234/10=123, 123%10=3
            
            enfileira(v[i], f[l]);  // Insere o número inteiro v[i] na fila correspondente
                                    // ao dígito l (se l=3, vai para f[3])
        }
        
        j = 0;                    // Reinicia contador j para reconstruir o vetor
        
        for(i=0;i < 10;i++)      // Loop que percorre todas as 10 filas (dígitos 0 a 9)
            while(!fila_vazia (f[i]))     // Enquanto a fila f[i] não estiver vazia:
                v[j++] = desenfileira (f[i]);  // 1. Remove elemento da fila f[i]
                                               // 2. Coloca no vetor v na posição j
                                               // 3. Incrementa j para próxima posição
                                               // Isso reconstrói o vetor ordenado pelo dígito atual
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

/*
faça:
considere uma tabela de dispersão implmenetada da seguinte forma: (1) usa endereçamento aberto, (2) lida com as colisões por meio da sondagem linear, (3) a remoção pe feira reinserindo as chaves necessárias na tabela e (4) a função de espalhamento é h(x) = x mod 10.

(a) considere que a tabela possui tamanho T=10. Execute as seguintes operações da sua tabela. insira as chaves, 41,10, 36,87, 28,99, 16 e por ultimo remova a chave 87. desenhe a sua tabela hash final.

SOLUÇÃO:

Função de hash: h(x) = x mod 10
Tamanho da tabela: T = 10
Método: Endereçamento aberto com sondagem linear

Vamos executar as operações passo a passo:

INSERÇÕES:

1. Inserir 41:
   h(41) = 41 mod 10 = 1
   Tabela[1] = 41
   
   Tabela: [_, 41, _, _, _, _, _, _, _, _]
           [0, 1,  2, 3, 4, 5, 6, 7, 8, 9]

2. Inserir 10:
   h(10) = 10 mod 10 = 0
   Tabela[0] = 10
   
   Tabela: [10, 41, _, _, _, _, _, _, _, _]
           [0,  1,  2, 3, 4, 5, 6, 7, 8, 9]

3. Inserir 36:
   h(36) = 36 mod 10 = 6
   Tabela[6] = 36
   
   Tabela: [10, 41, _, _, _, _, 36, _, _, _]
           [0,  1,  2, 3, 4, 5, 6,  7, 8, 9]

4. Inserir 87:
   h(87) = 87 mod 10 = 7
   Tabela[7] = 87
   
   Tabela: [10, 41, _, _, _, _, 36, 87, _, _]
           [0,  1,  2, 3, 4, 5, 6,  7,  8, 9]

5. Inserir 28:
   h(28) = 28 mod 10 = 8
   Tabela[8] = 28
   
   Tabela: [10, 41, _, _, _, _, 36, 87, 28, _]
           [0,  1,  2, 3, 4, 5, 6,  7,  8,  9]

6. Inserir 99:
   h(99) = 99 mod 10 = 9
   Tabela[9] = 99
   
   Tabela: [10, 41, _, _, _, _, 36, 87, 28, 99]
           [0,  1,  2, 3, 4, 5, 6,  7,  8,  9]

7. Inserir 16:
   h(16) = 16 mod 10 = 6
   Posição 6 ocupada (36), sondagem linear:
   Posição 7 ocupada (87), continua:
   Posição 8 ocupada (28), continua:
   Posição 9 ocupada (99), continua:
   Posição 0 ocupada (10), continua:
   Posição 1 ocupada (41), continua:
   Posição 2 livre!
   Tabela[2] = 16
   
   Tabela: [10, 41, 16, _, _, _, 36, 87, 28, 99]
           [0,  1,  2,  3, 4, 5, 6,  7,  8,  9]

REMOÇÃO:

8. Remover 87:
   Encontrar 87 na posição 7
   Remove 87 da posição 7
   
   Tabela temporária: [10, 41, 16, _, _, _, 36, _, 28, 99]
                      [0,  1,  2,  3, 4, 5, 6,  7, 8,  9]
   
   Agora precisa reinserir as chaves que podem ter sido afetadas pela remoção.
   Verifica as posições após a posição 7:
   
   - Posição 8 (28): h(28) = 8, estava na posição correta, mantém
   - Posição 9 (99): h(99) = 9, estava na posição correta, mantém
   - Posição 0 (10): h(10) = 0, estava na posição correta, mantém
   - Posição 1 (41): h(41) = 1, estava na posição correta, mantém
   - Posição 2 (16): h(16) = 6, mas foi colocado em 2 devido à sondagem
   
   Para 16: h(16) = 6, verifica se pode voltar para posição original
   Posição 6 ocupada por 36, não pode mover
   
   Nenhuma reinserção necessária.

TABELA HASH FINAL:

   Posição: [0,  1,  2,  3, 4, 5, 6,  7, 8,  9]
   Valor:   [10, 41, 16, _, _, _, 36, _, 28, 99]

Onde _ representa posições vazias.

RESUMO DA TABELA FINAL:
- Posição 0: 10
- Posição 1: 41  
- Posição 2: 16
- Posição 3: vazia
- Posição 4: vazia
- Posição 5: vazia
- Posição 6: 36
- Posição 7: vazia (após remoção de 87)
- Posição 8: 28
- Posição 9: 99
*/