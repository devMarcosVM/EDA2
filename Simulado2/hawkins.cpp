#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    // Map para contar ocorrências de cada soma de prefixo
    unordered_map<long long, long long> prefixCount;
    
    // Inicializa com prefixo 0 (para intervalos que começam do índice 0)
    prefixCount[0] = 1;
    
    long long prefixSum = 0;
    long long count = 0;
    const long long S = 11;
    
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        
        prefixSum += a;
        
        // Queremos: prefixSum - prefix[l-1] = 11
        // Então: prefix[l-1] = prefixSum - 11
        long long target = prefixSum - S;
        
        if (prefixCount.find(target) != prefixCount.end()) {
            count += prefixCount[target];
        }
        
        prefixCount[prefixSum]++;
    }
    
    cout << count << "\n";
    
    return 0;
}
