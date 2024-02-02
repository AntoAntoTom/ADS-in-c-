#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int src, dest, weight;
} Edge;

typedef struct {
  int parent, rank;
} Subset;

int find(Subset subsets[], int i) {
  if (subsets[i].parent != i) {
    subsets[i].parent = find(subsets, subsets[i].parent);
  }
  return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y) {
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);

  if (subsets[xroot].rank < subsets[yroot].rank) {
    subsets[xroot].parent = yroot;
  } else if (subsets[xroot].rank > subsets[yroot].rank) {
    subsets[yroot].parent = xroot;
  } else {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

int compareEdges(const void *a, const void *b) {
  return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskalMST(Edge *edges, int V, int E) {
  qsort(edges, E, sizeof(Edge), compareEdges);

  Subset *subsets = (Subset *)malloc(V * sizeof(Subset));

  for (int v = 0; v < V; v++) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  Edge *result = (Edge *)malloc((V - 1) * sizeof(Edge));
  int i = 0;
  int total = 0;

  for (int j = 0; j < E && i < V - 1; j++) {
    Edge next_edge = edges[j];

    int x = find(subsets, next_edge.src);
    int y = find(subsets, next_edge.dest);

    if (x != y) {
      result[i++] = next_edge;
      total += next_edge.weight;
      unionSets(subsets, x, y);
    }
  }

  printf("Minimum Spanning Tree (Kruskal's Algorithm):\n");
  for (int j = 0; j < i; j++) {
    printf("%d -- %d (Weight: %d)\n", result[j].src, result[j].dest, result[j].weight);
  }
  printf("Total cost is: %d\n", total);

  free(subsets);
  free(result);
}

int main() {
  int v, e;
  printf("Enter the number of vertices: ");
  scanf("%d", &v);
  printf("Enter the number of edges: ");
  scanf("%d", &e);

  Edge *edges = (Edge *)malloc(e * sizeof(Edge));

  printf("Enter the edges (src, dest, weight):\n");
  for (int i = 0; i < e; i++) {
    scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
  }

  kruskalMST(edges, v, e);

  free(edges);

  return 0;
}
