#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 100
#include <stdio.h>
#include <stdlib.h>

// �׷��� ����
struct node {
	int data;
	struct node* next;
};
struct node** graph;
int visited[MAX_VERTICES];

void create_graph(struct node**);
struct node* create_node(int);
void insert_front(struct node**, struct node*);
void init_visited(); // visited[]�� �ʱ�ȭ�ϴ� �Լ�. dfs(), bfs() ���� ���� �ݵ�� ȣ�� �ʿ�!!
void dfs(int);
void dfs_spanning_tree(int);
void bfs(int);
void bfs_spanning_tree(int);
int get_degree(struct node*);

// ť ���� : �Ϲ� queue�� �ƴ� listed queue ���. (�����ڷ� 4�� Page 22~24)
struct queue {
	int data;
	struct queue* link;
};
struct queue* front = NULL;
struct queue* rear = NULL;

void addq(int);
int deleteq();

// ��� ����
void print_10_1(struct node**, int);
void print_10_2(int);
void print_10_3(int);

// ���� �Լ�
int main() {
	while (1) {
		printf("10.1. ���� ����Ʈ ������ �����⼺ �׷��� ����\n");
		printf("  ��� ����(n): ");
		int n;
		scanf("%d", &n);
		if (n == -1) break;

		graph = (struct node**)calloc(n, sizeof(struct node*));
		create_graph(graph);
		print_10_1(graph, n);

		printf("10.2. Ž�� �˰���(DFS, BFS)\n");
		print_10_2(n);

		printf("10.3. ����Ʈ�� �˰���(DFS, BFS ���)\n");
		print_10_3(n);
	}
}

void create_graph(struct node** graph) {
	int vi, vj;

	while (1) {
		printf("  ���� ����(vi vj) : ");
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
	struct temp* existed_list = *list; // ������ linked list�� �ٸ� ���� ����

	*list = node; // linked list ���� �κп� ���ο� node�� ����
	node->next = existed_list; // ���ο� node �ڿ��� ������ linked list�� ����
}

void init_visited() {
	for (int i = 0; i < MAX_VERTICES; i++) {
		visited[i] = FALSE;
	}
}

void dfs(int v) { // v�� �湮�Ϸ��� vertex

	visited[v] = TRUE; // �湮�Ϸ��� vertex�� ǥ���ϰ�
	printf("%3d", v); // ����Ѵ�.

	for (struct node* w = graph[v]; w; w = w->next) // v vertex���� �����ؼ�, graph�� ������ vertex�� �ϳ��� Ž���Ѵ�.
		if (!visited[w->data]) // ������ vertex�� ���� �湮���� �ʾҴٸ�,
			dfs(w->data); // ������ vertex���� �ٽ� Ž���� �����Ѵ�.
}

void dfs_spanning_tree(int v) {

	visited[v] = TRUE;

	for (struct node* w = graph[v]; w; w = w->next) 
		if (!visited[w->data]) {
			printf("(%d, %d) ", v, w->data);
			dfs_spanning_tree(w->data);
		}
}

void bfs(int v) { // v�� �湮�Ϸ��� vertex

	front = rear = NULL; // ť �ʱ�ȭ

	visited[v] = TRUE; // �湮�Ϸ��� vertex�� ǥ���ϰ�
	printf("%3d", v); // ����� ��
	addq(v); // ť�� �ִ´�.

	while (front) {
		v = deleteq(); // ť�� �ִ� vertex �ϳ��� ���� ��,

		for (struct node* w = graph[v]; w; w = w->next) {  // ���� vertex���� �����ؼ�, graph�� ������ vertex�� �ϳ��� Ž���Ѵ�.
			if (!visited[w->data]) { // ������ vertex�� ���� �湮���� �ʾҴٸ�,

				visited[w->data] = TRUE; // ������ vertex�� ǥ�ø� �� ��
				printf("%3d", w->data); // ����� ����,
				addq(w->data); // ���߿� ������ vertex���� Ž���� �� �ֵ��� ť�� �־� �д�.
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
	// ť�� rear�� ���ο� item�� �߰�

	// temp ����
	struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
	if (temp == NULL) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}

	// temp �� �ֱ�
	temp->data = item;
	temp->link = NULL;

	// temp ��ũ ����
	if (front) { // �̹� ���� �ִ� ���
		rear->link = temp; // rear �ڿ� ���ο� ��带 �߰��ϰ�
		rear = temp; // rear�� ���ο� ���� ����
	}
	else { // �̹� ���� ���� ���, front�� rear�� �ʱ�ȭ
		front = temp;
		rear = temp;
	}
}

int deleteq() {
	// ť���� front�� ����Ű�� ��带 ���� �� ���� return

	struct queue* temp = front;
	int item;

	if (temp == NULL) {
		fprintf(stderr, "The queue is empty\n");
		exit(1);
	}

	item = temp->data;
	front = temp->link; // front�� front ������ ��带 ����Ű���� ����

	free(temp);
	return item;
}

void print_10_1(struct node** graph, int n) {
	printf("  ���� ����Ʈ�� �̿��Ͽ� ������ �׷���\n");
	for (int i = 0; i < n; i++) {
		printf("  [%d] : ", i);

		for (struct node* ptr = graph[i]; ptr != NULL; ptr = ptr->next)
			printf("%d -> ", ptr->data);

		printf("end\n");
	}
	printf("\n");

	printf("  degree�� ���� ū ���� degree �� : ");
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

	printf("��� %d, degree %d\n", node_largest, node_largest_degree);
	printf("  ��� %d�� ����� ���� : ", node_largest);

	for (struct node* ptr = graph[node_largest]; ptr != NULL; ptr = ptr->next)
		printf("%d -> ", ptr->data);

	printf("end\n\n");
}

void print_10_2(int n) {

	printf("  ���� �켱 Ž�� (DFS)\n");
	for (int i = 0; i < n; i++)
		if (i % 2 == 0) {
			printf("  ���۳�� %d: ", i);

			init_visited(); // visited[] �ʱ�ȭ
			dfs(i);

			printf("\n");
		}
	printf("\n");

	printf("  �ʺ� �켱 Ž�� (BFS)\n");
	for (int i = 0; i < n; i++)
		if (i % 2 == 1) {
			printf("  ���۳�� %d: ", i);

			init_visited(); // visited[] �ʱ�ȭ
			bfs(i);

			printf("\n");
		}
	printf("\n");
}

void print_10_3(int n) {

	printf("  DFS ����Ʈ��\n");
	for (int i = 0; i < n; i++)
		if (i % 2 == 0) {
			printf("  ���۳�� %d: ", i);

			init_visited(); // visited[] �ʱ�ȭ
			dfs_spanning_tree(i);

			printf("\n");
		}
	printf("\n");

	printf("  BFS ����Ʈ��\n");
	for (int i = 0; i < n; i++)
		if (i % 2 == 1) {
			printf("  ���۳�� %d: ", i);

			init_visited(); // visited[] �ʱ�ȭ
			bfs_spanning_tree(i);

			printf("\n");
		}
	printf("\n");
}