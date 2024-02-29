#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 200000

long long a[MAX_NUM], types[1 << 21], activeBits [1 << 21];

int main() {
	long long n, mask = 1 << 21;
    scanf("%lld", &n);
    getchar();
	
	memset(types, 0, sizeof(types));
    memset(activeBits, 0, sizeof(activeBits));
    
    for(long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        
		long long type = 0, j = 1;
        
		while(a[i] > 0) {
            if((a[i] % 2) == 1) {
                type += j;
            }
            
            a[i] /= 4;
            j *= 2;
        }
        
        types[type]++;
    }
    getchar();
    
    for(long long i = 20; i >= 0; i--) {
        long long j = 1 << i;
        
        for(long long k = (mask - 1); k >= 0; k--) {
            if(!(k & j)) {
                types[k] += types[k + j];
            }
        }
    }
    
    for(long long i = 0; i < 21; i++) {
        long long j = 1 << i;
        
        for(long long k = 0; k < mask; k++) {
            if(k & j){
                activeBits[k] = activeBits[k - j] + 1;
            }
        }
    }
    
    long long pairs = ((n * (n - 1)) / 2);
    
    for(long long i = 1; i < mask; i++) {
        if(types[i] > 0){
            if(!(activeBits[i] % 2)) {
                pairs += ((types[i] * (types[i] - 1)) / 2);
            } else {
                pairs -= ((types[i] * (types[i] - 1)) / 2);
            }
        }
    }
    
    printf("%lld\n", pairs);
    
    return 0;
}
