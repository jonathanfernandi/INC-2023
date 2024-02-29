#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    getchar();

    int p[n], maxDays = 0;

    for(int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    getchar();

    for(int i = 1; i <= n; i++) {
        int temp[n], count = 0;

        for(int j = 1; j <= i; j++) {
        	count += p[j];
		}

        for(int j = 1; j <= i; j++) {
        	temp[j] = p[j];
		}
		
        qsort((temp + 1), i, sizeof(int), compare);

        for(int j = 1; j <= k; j++) {
        	count -= temp[j];
		}
		
        if(count <= m) {
        	if(i > maxDays) {
        		maxDays = i;
			}
		}
    }
    
    printf("%d\n", maxDays);

    return 0;
}
