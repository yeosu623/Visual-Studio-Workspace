#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define TRUE 1
#define MAX_DISTANCE 99999
#include <stdio.h>
#include <stdlib.h>

int* distance; // = (int*)malloc(sizeof(int) * n); // �� main �Լ����� �������־�� ��.
int* found; // = (int*)malloc(sizeof(int) * n); // �� main �Լ����� �������־�� ��.
int** distance2D; // main �Լ����� n x n ũ���� 2���� ���� �迭�� �Ҵ����־�� ��.

int** makeAdjacencyMatrix(int);
void shortestpath(int v, int** cost, int* distance, int n, int* found); // Program 6.9. Dijkstra Algorithm
int choose(int*, int, int*); // Program 6.10. Dijkstra Algorithm�� ���� �Լ�
void allcosts(int** cost, int** distance, int n); // Program 6.12. Dynamic Programming
void print_11_1(int, int**);
void print_11_2(int, int**);
void print_11_3(int, int**);

int main() {
	int n;
	int** adjacencyMatrix;

	while (1) {

		// �ǽ� 11.1
		printf("11.1. ���� ��� ������ ���⼺ �׷��� ����\n");
		printf("  ��� �� (n) : ");
		scanf("%d", &n);

		if (n == -1) break;
		else {
			adjacencyMatrix = makeAdjacencyMatrix(n);

			print_11_1(n, adjacencyMatrix);
		}


		// �ǽ� 11.2
		printf("11.2. �ִ� ��� (���� �����)\n");
		distance = (int*)malloc(sizeof(int) * n);
		found = (int*)malloc(sizeof(int) * n);

		print_11_2(n, adjacencyMatrix);


		// �ǽ� 11.3
		printf("11.3. �ִ� ��� (��� ���)\n");
		distance2D = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++)
			distance2D[i] = (int*)malloc(sizeof(int) * n);

		print_11_3(n, adjacencyMatrix);

	}

}

int** makeAdjacencyMatrix(int n) {

	// �޸� �Ҵ�
	int** adjacencyMatrix = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		adjacencyMatrix[i] = (int*)malloc(sizeof(int) * n);

	// �ʱⰪ ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) adjacencyMatrix[i][j] = 0;
			else adjacencyMatrix[i][j] = MAX_DISTANCE;
		}
	}

	// ���� ���� �Է�
	int col, row, weight;
	while (1) {
		printf("  ���� ���� (from to weight) : ");
		scanf("%d %d %d", &col, &row, &weight);

		if (col == -1 || row == -1 || weight == -1) break;
		else adjacencyMatrix[col][row] = weight;
	}
	printf("\n");

	return adjacencyMatrix;
}

void shortestpath(int v, int** cost, int* distance, int n, int* found) {

	// Dijkstra Algorithm

	int i, u, w;
	for (i = 0; i < n; i++) { // �ʱⰪ ����
		found[i] = FALSE;
		distance[i] = cost[v][i];
	}

	found[v] = TRUE; // ���� ��带 TRUE�� ����
	distance[v] = 0; // ���� ��忡�� �Ÿ��� 0���� ����
	for (i = 0; i < n - 2; i++) {
		u = choose(distance, n, found);
		found[u] = TRUE;

		for (w = 0; w < n; w++)
			if (found[w] == FALSE)
				if (distance[u] + cost[u][w] < distance[w])
					distance[w] = distance[u] + cost[u][w];

	}

}

int choose(int* distance, int n, int* found) {

	// ���� S�� ���Ե��� ���� vertex �߿��� �ּ� �Ÿ��� ���� vertex�� return

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

void allcosts(int** cost, int** distance, int n) {

	// �� vertex���� ������ ��� vertex������ �ִ� ��θ� ���.

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

void print_11_1(int n, int** adjacencyMatrix) {

	printf("  ���� ����� �̿��� �׷����� ���� : \n");

	/* ��� : [0]    [1]    [2]    [3]    [4]    [5]*/
	printf("         ");
	for (int i = 0; i < n; i++)
		printf("[%d]   ", i);
	printf("\n");

	/* ��� :
	   [ 0]      0     50     45     10  99999  99999
	   [ 1]  99999      0     10     15  99999  99999
	   [ 2]  99999  99999      0  99999     30  99999
	   [ 3]     20  99999  99999      0     15  99999
	   [ 4]  99999     20     35  99999      0  99999
	   [ 5]  99999  99999  99999  99999      3      0
	*/
	for (int i = 0; i < n; i++) {
		printf("  [%d] ", i);
		for (int j = 0; j < n; j++) {
			printf("%6d", adjacencyMatrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

void print_11_2(int n, int** adjacencyMatrix) {

	int v;

	while (1) {
		printf("  ���� ��� (v) : ");
		scanf("%d", &v);

		if (v == -1) break;
		else {
			shortestpath(v, adjacencyMatrix, distance, n, found);

			printf("  Distance : ");
			for (int i = 0; i < n; i++)
				printf("%d ", distance[i]);
			printf("\n");
		}
	}
	printf("\n");

}

void print_11_3(int n, int** adjacencyMatrix) {

	// �� vertex���� ������ ��� vertex������ �ִ� ��θ� ���.
	// ����� distance[][]�� ����
	allcosts(adjacencyMatrix, distance2D, n);

	// ���
	printf("  All Path Distance : \n");

	/* ��� :  [0]    [1]    [2]    [3]    [4]    [5]*/
	printf("         ");
	for (int i = 0; i < n; i++)
		printf("[%d]   ", i);
	printf("\n");

	/* ��� :
	   [ 0]      0     45     45     10     25  99999
	   [ 1]     35      0     10     15     30  99999
	   [ 2]     85     50      0     65     30  99999
	   [ 3]     20     35     45      0     15  99999
	   [ 4]     55     20     30     35      0  99999
	   [ 5]     58     23     33     38      3      0
	*/
	for (int i = 0; i < n; i++) {
		printf("  [%d] ", i);
		for (int j = 0; j < n; j++) {
			printf("%6d", distance2D[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}