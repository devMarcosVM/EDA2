#include <stdio.h>
#include <stdlib.h>

enum tipo { RED, BLACK };

#define RED 0
#define BLACK 1
#define Item int 

typedef struct STnode* link;
struct STnode {
    Item item;
    link l, r;
    int N;
    int color;
};

link h, z;

link New (Item item, link l, link r, int N) {
    link x = malloc (sizeof *x);
    x->color = RED;
    x->item = item;
    x->l = l;
    x->r = r;
    x->N = N;
    return x;
}

void STinit() {
    h = (z = New(0, 0, 0, 0));
    z->color = BLACK;
}

int STcount() {
    return h->N;
}

link rotateLeft(link h) {
    link x = h->r; 
    h->r = x->l; 
    x->l = h; 
    x->color = h->color; 
    h->color = RED; 
    x->N = h->N; 
    h->N = 1 + (h->l->N + h->r->N); 
    return x; 
}

link rotateRight(link h) {
    link x = h->l; 
    h->l = x->r; 
    x->r = h; 
    x->color = h->color; 
    h->color = RED; 
    x->N = h->N; 
    h->N = 1 + (h->l->N + h->r->N); 
    return x; 
}

void flipColors(link h) {
    h->color = RED; 
    h->l->color = BLACK; 
    h->r->color = BLACK; 
}

int isRed(link h) {
    if (h == z) return 0;
    return h->color == RED;
}

link insertR(link h, Item item) {
    if (h == z) return New(item, z, z, 1);
    if (item < h->item)
        h->l = insertR(h->l, item);
    else if (item > h->item)
        h->r = insertR(h->r, item);
    if (isRed(h->r) && !isRed(h->l)) h = rotateLeft(h);
    if (isRed(h->l) && isRed(h->l->l)) h = rotateRight(h);
    if (isRed(h->l) && isRed(h->r)) flipColors(h);
    h->N = 1 + (h->l->N + h->r->N);
    return h;
}

link search(link h, Item item) {
    if (h == z) return NULL;
    if (item < h->item)
        return search(h->l, item);
    else if (item > h->item)
        return search(h->r, item);
    else
        return h;
}

int main () {
    int N, num;
    scanf("%d", &N);
    STinit();
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        h = insertR(h, num);
    }
    while (scanf("%d", &num) != EOF) {
        link res = search(h, num);
        if (res != NULL)
            printf("sim\n");
        else
            printf("nao\n");
    }
}