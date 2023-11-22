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
void addq(struct node**, struct node**, int); // 미구현
int deleteq(); // 미구현
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
	//Vertex v부터 탐색 수행. vistied[] 배열은 FALSE로 초기화. 큐를 사용.
	//참고 : 강의자료 Page 22~23에는 구조체 이름이 struct queue이나, strcut node와 구조와 같아서 같은 이름을 사용함.

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
	// 그래프의 연결 요소들을 한 줄씩 출력
	int i;
	for (i = 0; i < MAX_VERTICES; i++)
		if (!visited[i]) {
			dfs(i);
			printf("\n");
		}
}