#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct {
    int w;
    int v;
} Treasure;

typedef struct {
    Treasure heap[MAX_SIZE];
    int size;
} PriorityQueue;

void push(PriorityQueue *pq, Treasure val) {
    int i = pq->size++;
    
    while (i > 0) {
        int j = ((i - 1) / 2);
        
        if(pq->heap[j].v >= val.v) {
        	break;
		}
		
        pq->heap[i] = pq->heap[j];
        
        i = j;
    }
    
    pq->heap[i] = val;
}

Treasure top(PriorityQueue *pq) {
    return pq->heap[0];
}

void pop(PriorityQueue *pq) {
    Treasure val = pq->heap[--pq->size];
    
    int i = 0;
    while((i * 2 + 1) < pq->size) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int j = left;
        
        if((right < pq->size) && (pq->heap[right].v > pq->heap[left].v)) {
        	j = right;
		}
		
        if(pq->heap[j].v <= val.v) {
        	break;
		}
		
        pq->heap[i] = pq->heap[j];
        
        i = j;
    }
    
    pq->heap[i] = val;
}

int empty(PriorityQueue *pq) {
    return (pq->size == 0);
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    Treasure treasures[n];
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &treasures[i].w, &treasures[i].v);
        getchar();
    }

    int s[m];
    for(int i = 0; i < m; i++) {
        scanf("%d", &s[i]);
    }
    getchar();

    qsort(treasures, n, sizeof(Treasure), compare);
    qsort(s, m, sizeof(int), compare);

    PriorityQueue pq;
    pq.size = 0;

    int j = 0;
    long long maxTotalVal = 0;
    for(int i = 0; i < m; i++) {
        while ((j < n) && (treasures[j].w <= s[i])) {
            push(&pq, treasures[j++]);
        }
        
        if(!empty(&pq)) {
            maxTotalVal += top(&pq).v;
            pop(&pq);
        }
    }

    printf("%lld\n", maxTotalVal);

    return 0;
}
