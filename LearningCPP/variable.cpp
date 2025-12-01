#include <stdio.h>

float media = 0.0f;

void atualiza_media(float nota) {
    static int quantidade_notas = 0;
    media = media * quantidade_notas + nota;
    quantidade_notas++;
    media /= quantidade_notas;
}

int main(){
    float nota1 = 8, nota2 = 9.2f;
    atualiza_media(nota1);
    atualiza_media(nota2);

    printf("A media e igual a %3.2f\n", media);

    return 0;
}