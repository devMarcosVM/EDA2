#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M;
	if (scanf("%d %d", &N, &M) != 2) return 0;

	size_t n = (size_t) N;
	unsigned char *adj = calloc(n * n, sizeof(unsigned char));
	if (!adj) return 1;

	for (int i = 0; i < M; ++i) {
		int u, v;
		if (scanf("%d %d", &u, &v) != 2) break;
		u--; v--;
		adj[(size_t)u * n + v] = 1;
		adj[(size_t)v * n + u] = 1;
	}

	for (int a = 0; a < N; ++a) {
		for (int b = a + 1; b < N; ++b) {
			if (!adj[(size_t)a * n + b]) {
				printf("%d %d\n", a + 1, b + 1);
			}
		}
	}

	free(adj);
	return 0;
}

