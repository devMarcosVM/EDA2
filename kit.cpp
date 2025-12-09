#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <bits/stdc++.h>
using namespace std;
ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MAXN = 200005; // Ajustar conforme o problema!
using ll = long long;    // Atalho para long long

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Seu código aqui
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // 1. Max-Heap (Padrão): O MAIOR fica no
    priority_queue<int> max_heap; //topo
    max_heap.push(10);
    max_heap.push(5);
    int x = max_heap.top(); // x vale 10
    max_heap.pop();         // Remove o 10

    // 2. Min-Heap: O MENOR fica no topo
    priority_queue<int, vector<int>, greater<int>> min_heap;
    min_heap.push(10);
    min_heap.push(5);
    int y = min_heap.top(); // y vale 5

    return 0;
}