#include <stdio.h>
#include <limits.h>

#define V 10

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    int totalWeight = 0;

    char vertexMap[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    for (int i = 1; i < V; i++) {
        printf("%c - %c \t%d \n", vertexMap[parent[i]], vertexMap[i], graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }

    printf("\nTotal Minimum Spanning Tree Weight (Prim Dijkstra): %d\n", totalWeight);
}

void printGraph(int graph[V][V]) {
    printf("Graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void primDijkstra(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);

        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}

// Helper function for Union-Find data structure
int find(int parent[], int i) {
  if (parent[i] == -1)
    return i;
  return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
  int xset = find(parent, x);
  int yset = find(parent, y);
  parent[xset] = yset;
}

void kruskal(int graph[V][V]) {
  int parent[V];
  for (int i = 0; i < V; i++)
    parent[i] = -1;

  int edgeCount = 0;
  int totalWeight = 0;

  while (edgeCount < V - 1) {
    int min = INT_MAX, min_indexI = -1, min_indexJ = -1;

    for (int i = 0; i < V; i++) {
      for (int j = i + 1; j < V; j++) {
        if (graph[i][j] && find(parent, i) != find(parent, j) && graph[i][j] < min) {
          min = graph[i][j];
          min_indexI = i;
          min_indexJ = j;
        }
      }
    }

    if (min_indexI != -1 && min_indexJ != -1) {
      printf("%c - %c \t%d\n", 'A' + min_indexI, 'A' + min_indexJ, min);
      totalWeight += min;
      unionSet(parent, min_indexI, min_indexJ);
      edgeCount++;
    }
  }

  printf("\nTotal Minimum Spanning Tree Weight (Kruskal): %d\n", totalWeight);
}


int main() {
    int graph[V][V] = {
        {0, 23, 9, 10, 0, 0, 0, 0, 0, 0},
        {23, 0, 14, 0, 0, 0, 0, 0, 30, 25},
        {9, 14, 0, 12, 8, 13, 0, 15, 0, 0},
        {10, 0, 12, 0, 7, 0, 18, 0, 0, 0},
        {0, 0, 8, 7, 0, 0, 0, 13, 0, 0},
        {0, 0, 13, 0, 0, 0, 0, 10, 11, 12},
        {0, 0, 0, 18, 0, 0, 0, 19, 0, 0},
        {0, 0, 15, 0, 13, 10, 19, 0, 20, 0},
        {0, 30, 0, 0, 0, 11, 0, 20, 0, 9},
        {0, 25, 0, 0, 0, 12, 0, 0, 9, 0}
    };
    
    printGraph(graph);
    printf("\n");

    printf("Prim's Algorithm:\n");
    primDijkstra(graph);
    printf("\nKruskal's Algorithm:\n");
    kruskal(graph);

    return 0;
}
