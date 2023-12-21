#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 1000
#include <stdio.h>
#include <stdlib.h>

struct node {
	int vertex;
	struct node* link;
};
short int visited[MAX_VERTICES];
struct node** graph;

struct queue {
	int data;
	struct queue* link;
};
void addq(int v);
int deleteq();

int main() {
	graph = (struct node**)calloc(MAX_VERTICES, sizeof(struct node*));
}

void dfs(int v) {
	struct node* w;

	visited[v] = TRUE;
	printf("%3d", v);

	for (w = graph[v]; w; w = w->link)
		if (!visited[w->vertex])
			dfs(w->vertex);
}

void bfs(int v) {
	struct node* w;
	struct queue* front = NULL, * rear = NULL;

	visited[v] = TRUE;
	printf("%3d", v);
	addq(v);

	while (front) {
		v = deleteq();

		for(w = graph[v]; w; w = w->link)
			if (!visited[w->vertex]) {
				visited[w->vertex] = TRUE;
				printf("%3d", w->vertex);
				addq(w->vertex);
			}
	}
}

void connected() {
	int i;
	for(i = 0; i < MAX_VERTICES; i++)
		if (!visited[i]) {
			dfs(i);
			printf("\n");
		}
}

// Krustal Algorithm 원리, 시간복잡도
// Prim Algorithm 원리, 시간복잡도
// Sollin Algorithm 원리, 시간복잡도
// Dijkstra Algorithm 원리, 시간복잡도
int v;
int cost[][MAX_VERTICES];
int distance[MAX_VERTICES];
int n = MAX_VERTICES;
short int found[MAX_VERTICES];

void shortestpath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]) {
	int i, u, w;
	for (i = 0; i < n; i++) {
		found[i] = FALSE;
		distance[i] = cost[v][i];
	}

	found[v] = TRUE;
	distance[v] = 0;

	for (i = 0; i < n - 2; i++) {
		u = choose(distance, n, found);
		found[u] = TRUE;

		for (w = 0; w < n; w++)
			if (found[w] == FALSE)
				if (distance[u] + cost[u][w] < distance[w])
					distance[w] = distance[u] + cost[u][w];
	}
}

int choose(int distance[], int n, short int found[]) {
	int i, min, minpos;

	min = INT_MAX;
	minpos = -1;

	for(i = 0; i < n; i++)
		if (distance[i] < min && found[i] == FALSE) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

// Dynamic Programming 원리, 시간복잡도, 각각의 행렬(A0, A1, A2, ...)
int distance2D[][MAX_VERTICES];

void allcosts(int cost[][MAX_VERTICES], int distance[][MAX_VERTICES], int n) {
	int i, j, k;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			distance[i][j] = cost[i][j];

	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (distance[i][k] + distance[k][j] < distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];
}
// Transitive Closure 원리, 시간복잡도, 코드
// distance[i][j] = distance[i][j] || distance[i][k] && distance[k][j];

// AOV : Topological Sort 동작 원리
// AOE : Critical Path, Critical Activity, Earliest Time, Latest Time