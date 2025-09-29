/*

Conceito:
1- Todo nó é vermelho ou preto
2- A raiz é preta
3- As folhas são NULL e da cor preta
4- Se um nó é vermelho
    -> é filho esquerdo de um nó preto
    -> seus filhos são pretos
    
5- Todo caminho de um nó às suas folhas descedentes possui a mesma quantidade de nós pretos - altura negra do nó

Condições de Correção:
1- Se o filho esquerdo e o filho direito de X forem vermelhos, subida de cor
2- Se o filho esquerdo for preto e o direito, vermelho, ROTAÇÃO À ESQUERDA
3- Se o filho esquerdo for vermelho e o filho esquerdo do filho esquerdo também, ROTAÇÃO A DIREITA.
*/



#include <stdio.h>

enum cor{VERM,PRETO};

typedef struct celula{

} celula;

void inserir(){

}



int main(){

}