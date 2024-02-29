#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct Node {
    long long vertex;
    struct Node *next;
} Node;

Node *createNode(long long v) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    newNode->vertex = v;
    newNode->next = NULL;
    
    return newNode;
}

typedef struct Graph {
    int numVertices;
    Node **adjLists;
} Graph;

Graph *createGraph(long long vertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node));
    
    for(long long i = 0; i < vertices; i++) {
    	graph->adjLists[i] = NULL;
	}
	
    return graph;
}

void addEdge(Graph *graph, long long src, long long dest) {
    Node *newNode = createNode(dest);
    
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

int dynamicProgramming[MAX_SIZE][2];

void depthFirstSearch(Graph *graph, long long curr, long long prev) {
    dynamicProgramming[curr][0] = 0;
    dynamicProgramming[curr][1] = 1;
    
    Node *temp = graph->adjLists[curr];
    while(temp) {
        int next = temp->vertex;
        if(next != prev) {
            depthFirstSearch(graph, next, curr);
            
            if(dynamicProgramming[next][0] > dynamicProgramming[next][1]) {
                dynamicProgramming[curr][0] += dynamicProgramming[next][0];
            } else {
                dynamicProgramming[curr][0] += dynamicProgramming[next][1];
            }
            
            dynamicProgramming[curr][1] += dynamicProgramming[next][0];
        }
        
        temp = temp->next;
    }
}

int main() {
    long long n, u, v;
    scanf("%lld", &n);
    getchar();
    
    Graph *graph = createGraph(n+1);
    
    for(long long i = 1; i < n; i++) {
        scanf("%lld %lld", &u, &v);
        getchar();
        
        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }
    
    if(n == 2) {
        puts("0");
    } else {
        depthFirstSearch(graph, 1, 0);
        
        if(dynamicProgramming[1][0] > dynamicProgramming[1][1]) {
            printf("%lld\n", ((n - 1) * dynamicProgramming[1][0]));
        } else {
            printf("%lld\n", ((n - 1) * dynamicProgramming[1][1]));
        }
    }
    
    return 0;
}
