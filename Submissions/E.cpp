#include <stdio.h>
#include <string.h>

int main() {
    int n, q;

    scanf("%d", &n);
    getchar();
    
    char s[n + 1], t[n + 1], temp[n + 1];
    
    scanf("%[^\n]", s);
    getchar();
    
    scanf("%d", &q);
    getchar();

    for(int i = 0; i < q; i++) {
        scanf("%[^\n]", t);
        getchar();

        int possibility = 1, idx = 0;
        
        memset(temp, 0, sizeof(temp));

        for(int j = 0; j < n; j++) {
            strncat(temp, &t[j], 1);

            if(s[n - idx - 1] == t[j]) {
                if(!strncmp(&s[n - j - 1], temp, (j - idx + 1))) {
                    idx = j + 1;
                    memset(temp, 0, sizeof(temp));
                }
            }

            if(strlen(temp) && (j == (n - 1))) {
                possibility--;
            }
        }

        if(!possibility) {
            puts("NO");
        } else {
            puts("YES");
        }
    }

    return 0;
}
