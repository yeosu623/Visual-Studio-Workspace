#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 100
#include <stdio.h>
#include <stdlib.h>

// 그래프 관련
struct node {
	int data;
	struct node* next;
};
struct node** graph;
int visited[MAX_VERTICES];

void create_graph(struct node**);
struct node* create_node(int);
void insert_front(struct node**, struct node*);
void init_visited(); // visited[]를 초기화하는 함수. dfs(), bfs() 실행 전에 반드시 호출 필요!!
void dfs(int);
void dfs_spanning_tree(int);
void bfs(int);
void bfs_spanning_tree(int);
int get_degree(struct node*);

// 큐 관련 : 일반 queue가 아닌 listed queue 사용. (강의자료 4장 Page 22~24)
struct queue {
	int data;
	struct queue* link;
};
struct queue* front = NULL;
struct queue* rear = NULL;

void addq(int);
int deleteq();

// 출력 관련
void print_10_1(struct node**, int);
void print_10_2(int);
void print_10_3(int);

// 메인 함수
int main() {
	while (1) {
		printf("10.1. 인접 리스트 형태의 무방향성 그래프 생성\n");
		printf("  노드 개수(n): ");
		int n;
		scanf("%d", &n);
		if (n == -1) break;

		graph = (struct node**)calloc(n, sizeof(struct node*));
		create_graph(graph);
		print_10_1(graph, n);

		printf("10.2. 탐색 알고리즘(DFS, BFS)\n");
		print_10_2(n);

		printf("10.3. 신장트리 알고리즘(DFS, BFS 기반)\n");
		print_10_3(n);
	}
}

void create_graph(struct node** graph) {
	int vi, vj;

	while (1) {
		printf("  에지 정보(vi vj) : ");
		scanf("%d %d", &vi, &vj);

		if (vi == -1 && vj == -1) break;
		else {
			insert_front(&graph[vi], create_node(vj));
			insert_front(&graph[vj], create_node(vi));
		}
	}
	printf("\n");
}

struct node* create_node(int data) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->next = NULL;

	return node;
}

void insert_front(struct node** list, struct node* node) {
	struct temp* existed_list = *list; // 기존의 linked list를 다른 곳에 저장

	*list = node; // linked list 시작 부분에 새로운 node를 연결
	node->next = existed_list; // 새로운 node 뒤에는 기존의 linked list를 연결
}

void init_visited() {
	for (int i = 0; i < MAX_VERTICES; i++) {
		visited[i] = FALSE;
	}
}

void dfs(int v) { // v는 방문하려는 vertex

	visited[v] = TRUE; // 방문하려는 vertex를 표시하고
	printf("%3d", v); // 출력한다.

	for (struct node* w = graph[v]; w; w = w->next) // v vertex부터 시작해서, graph에 인접한 vertex를 하나씩 탐색한다.
		if (!visited[w->data]) // 인접한 vertex를 아직 방문하지 않았다면,
			dfs(w->data); // 인접한 vertex부터 다시 탐색을 시작한다.
}

void dfs_spanning_tree(int v) {

	visited[v] = TRUE;

	for (struct node* w = graph[v]; w; w = w->next) 
		if (!visited[w->data]) {
			printf("(%d, %d) ", v, w->data);
			dfs_spanning_tree(w->data);
		}
}

void bfs(int v) { // v는 방문하려는 vertex

	front = rear = NULL; // 큐 초기화

	visited[v] = TRUE; // 방문하려는 vertex를 표시하고
	printf("%3d", v); // 출력한 후
	addq(v); // 큐에 넣는다.

	while (front) {
		v = deleteq(); // 큐에 있는 vertex 하나를 꺼낸 후,

		for (struct node* w = graph[v]; w; w = w->next) {  // 꺼낸 vertex부터 시작해서, graph에 인접한 vertex를 하나씩 탐색한다.
			if (!visited[w->data]) { // 인접한 vertex를 아직 방문하지 않았다면,

				visited[w->data] = TRUE; // 인접한 vertex에 표시를 한 후
				printf("%3d", w->data); // 출력한 다음,
				addq(w->data); // 나중에 인접한 vertex부터 탐색할 수 있도록 큐에 넣어 둔다.
			}
		}
	}
}

void bfs_spanning_tree(int v) {

	front = rear = NULL;

	visited[v] = TRUE;
	addq(v); 

	while (front) {
		v = deleteq();

		for (struct node* w = graph[v]; w; w = w->next) { 
			if (!visited[w->data]) { 

				visited[w->data] = TRUE;
				printf("(%d, %d) ", v, w->data);
				addq(w->data);
			}
		}
	}
}

int get_degree(struct node* list) {
	int degree = 0;

	for (struct node* ptr = list; ptr != NULL; ptr = ptr->next)
		degree++;

	return degree;
}

void addq(int item) {
	// 큐의 rear에 새로운 item을 추가

	// temp 생성
	struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
	if (temp == NULL) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}

	// temp 값 넣기
	temp->data = item;
	temp->link = NULL;

	// temp 링크 설정
	if (front) { // 이미 값이 있는 경우
		rear->link = temp; // rear 뒤에 새로운 노드를 추가하고
		rear = temp; // rear를 새로운 노드로 설정
	}
	else { // 이미 값이 없는 경우, front와 rear를 초기화
		front = temp;
		rear = temp;
	}
}

int deleteq() {
	// 큐에서 front가 가리키는 노드를 삭제 후 값을 return

	struct queue* temp = front;
	int item;

	if (temp == NULL) {
		fprintf(stderr, "The queue is empty\n");
		exit(1);
	}

	item = temp->data;
	front = temp->link; // front는 front 다음의 노드를 가리키도록 설정

	free(temp);
	return item;
}

void print_10_1(struct node** graph, int n) {
	printf("  인접 리스트를 이용하여 구성한 그래프\n");
	for (int i = 0; i < n; i++) {
		printf("  [%d] : ", i);

		for (struct node* ptr = graph[i]; ptr != NULL; ptr = ptr->next)
			printf("%d -> ", ptr->data);

		printf("end\n");
	}
	printf("\n");

	printf("  degree가 가장 큰 노드와 degree 값 : ");
	int node_largest;
	int node_largest_degree = -1;
	int degree;

	for (int i = 0; i < n; i++) {
		degree = get_degree(graph[i]);

		if (node_largest_degree < degree) {
			node_largest = i;
			node_largest_degree = degree;
		}
	}

	printf("노드 %d, degree %d\n", node_largest, node_largest_degree);
	printf("  노드 %d와 연결된 노드들 : ", node_largest);

	for (struct node* ptr = graph[node_largest]; ptr != NULL; ptr = ptr->next)
		printf("%d -> ", ptr->data);

	printf("end\n\n");
}

void print_10_2(int n) {

	printf("  깊이 우선 탐색 (DFS)\n");
	for (int i = 0; i < n; i++)
		if (i % 2 == 0) {
			printf("  시작노드 %d: ", i);

			init_visited(); // visited[] 초기화
			dfs(i);

			printf("\n");
		}
	printf("\n");

	printf("  너비 우선 탐색 (BFS)\n");
	for (int i = 0; i < n; i++)
		if (i % 2 == 1) {
			printf("  시작노드 %d: ", i);

			init_visited(); // visited[] 초기화
			bfs(i);

			printf("\n");
		}
	printf("\n");
}

void print_10_3(int n) {

	printf("  DFS 신장트리\n");
	for (int i = 0; i < n; i++)
		if (i % 2 == 0) {
			printf("  시작노드 %d: ", i);

			init_visited(); // visited[] 초기화
			dfs_spanning_tree(i);

			printf("\n");
		}
	printf("\n");

	printf("  BFS 신장트리\n");
	for (int i = 0; i < n; i++)
		if (i % 2 == 1) {
			printf("  시작노드 %d: ", i);

			init_visited(); // visited[] 초기화
			bfs_spanning_tree(i);

			printf("\n");
		}
	printf("\n");
}