#include <stdio.h>
#include <string.h>

int main() {
	int n, m, k, x = 0;
	char s[100][11], t[100][11], topIns[100][11], goldTeam[100][11];
	
	scanf("%d %d %d", &n, &m, &k);
	getchar();
	
	for(int i = 0; i < n; i++) {
		scanf("%s %[^\n]", s[i], t[i]);
		getchar();
		
		if(i < m) {
			strcpy(topIns[i], t[i]);
		}
	}
	
	for(int i = m; i < n; i++) {
		if(k == 0) {
			break;
		} else {
			for(int j = 0; j < i; j++) {
				if(!strcmp(t[j], t[i])) {
					break;
				} else if(j == (i - 1)) {
					strcpy(goldTeam[x], s[i]);
					
					x++;
					k--;
					
					if(k == 0) {
						break;
					}
				}
			}	
		}	
	}
	
	printf("%d\n", x);
	if(x != 0) {
		for(int i = 0; i < x; i++) {
			puts(goldTeam[i]);
		}
	}
	
	return 0;
}
