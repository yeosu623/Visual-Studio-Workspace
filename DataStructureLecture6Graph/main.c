#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 100

struct node {
	int vertex;
	struct node* link;
};
int visited[MAX_VERTICES];
struct node* graph[];

void clear_visited_array();
void dfs(int);
void addq(struct node**, struct node**, int); // �̱���
int deleteq(); // �̱���
void bfs(int);
void connected();

int main() {

}

void clear_visited_array() {
	int i;
	for (i = 0; i < MAX_VERTICES; i++)
		visited[i] = FALSE;
}

void dfs(int v) {
	struct node* w;
	visited[v] = TRUE;
	printf("%3d", v);
	for (w = graph[v]; w; w = w->link)
		if (!visited[w->vertex])
			dfs(w->vertex);
}

void addq(struct node** front, struct node** rear, int v) {

}

int deleteq() {

}

void bfs(int v) {
	//Vertex v���� Ž�� ����. vistied[] �迭�� FALSE�� �ʱ�ȭ. ť�� ���.
	//���� : �����ڷ� Page 22~23���� ����ü �̸��� struct queue�̳�, strcut node�� ������ ���Ƽ� ���� �̸��� �����.

	struct node* w;
	struct node* front = NULL, * rear = NULL;

	printf("%3d", v);
	visited[v] = TRUE;
	addq(&front, &rear, v);
	while (front) {
		v = deleteq();
		for (w = graph[v]; w; w = w->link) {
			if (!visited[w->vertex]) {
				printf("%3d", w->vertex);
				addq(&front, &rear, w->vertex);
				visited[w->vertex] = TRUE;
			}
		}
	}
}

void connected() {
	// �׷����� ���� ��ҵ��� �� �پ� ���
	int i;
	for (i = 0; i < MAX_VERTICES; i++)
		if (!visited[i]) {
			dfs(i);
			printf("\n");
		}
}