#include <stdio.h>

int main() {
	long long n, m, k;
	
	scanf("%lld %lld %lld", &n, &m, &k);
	getchar();
	
	if(k == (n * m)) {
		puts("0");
	} else if(!(k % n) || !(k % m)) {
		puts("1");
	} else {
		long long i;
		for(i = 1; i <= n; i++) {
			if(!(k % i) && ((k / i) <= m)) {
				break;
			}
		}
		
		if(i <= n) {
			puts("2");
		} else {
			long long temp = n * m - k;
			
			for(i = 1; i <= n; i++) {
				if(!(temp % i) && ((temp / i) <= m)) {
					break;
				}
			}
			
			if(i <= n) {
				puts("2");
			} else {
				puts("3");
			}
		}
	}
	
	return 0;
}
