#include <stdio.h>
#include <stdlib.h>

// define constants for max num of vertices and edges
#define MAX_VERTICES 6
#define MAX_EDGES 10

// struct edge
typedef struct {
    int src, dest, weight;
} Edge;

// union-find data structur
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];

// initialize union-find
void initializeUnionFind(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// find with path compression
int find(int i) {
    if (parent[i] != i) {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}


// bubble Sort to sort edges by weight
void bubbleSortEdges(Edge edges[], int numEdges) {
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// union by rank
void unionByRank(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);
    
    if (xRoot != yRoot) {
        if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
}

// comparator for sorting edges by weight
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// kruskal algorithm to find the MST
void process_kruskal(Edge edges[], int numEdges, int numVertices) {
    Edge result[MAX_VERTICES]; // array to store result
    int e = 0;  // edges
    int i = 0;  // index var for sorted edges
    int r = 0;  // index var for result[]
    
    // union-Find structure
    initializeUnionFind(numVertices);
    
    // sort edges by weight
    bubbleSortEdges(edges, numEdges);
    
    // process edges in sorted order
    while (e < numVertices - 1 && i < numEdges) {
        Edge next_edge = edges[i++];
        
        int x = find(next_edge.src);
        int y = find(next_edge.dest);
        
        // if including this edge does not cause a cycle
        if (x != y) {
            result[r++] = next_edge;
            unionByRank(x, y);
            e++;
        }
    }
    
    // print the MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < r; i++) {
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    // number of vertices and edges
    int numVertices = 5;
    int numEdges = 8;
    
    // list of edges (source, destination, weight)
    Edge edges[MAX_EDGES] = {
        {0, 1, 30},  // DC -> K1
        {0, 2, 20},  // DC -> K2
        {0, 3, 10},  // DC -> P1
        {1, 3, 5},   // K1 -> P1
        {1, 4, 25},  // K1 -> P2
        {2, 3, 13},  // K2 -> P1
        {2, 4, 40},  // K2 -> P2
    };
    
    process_kruskal(edges, numEdges, numVertices);
    
    return 0;
}
