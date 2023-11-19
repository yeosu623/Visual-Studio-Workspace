#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
struct node {
	int key;
	double value;
	struct node* lchild;
	struct node* rchild;
};

void insert(treePointer*, int, double); // 예제 프로그램 5.17
treePointer modifiedSearch(treePointer, int);
void print_inorder(treePointer ptr);
treePointer get_sample_data();

int main() {
	treePointer A = get_sample_data();
	print_inorder(A);
}

void insert(treePointer* node, int k, double theItem) { // node 매개변수는 더블포인터 임에 유의
	/* 트리 내 노드가 k를 가지고 있으면 아무 일도 하지 않음.
	그렇지 않은 경우는 data = (k, theItem)인 새 노드를 첨가 */
	treePointer ptr; // 새로 추가될 노드
	treePointer search_result = modifiedSearch(*node, k); // key 존재시 NULL을 리턴. key가 없을시 검색 결과의 마지막 노드를 반환
	if (search_result || !(*node)) { // 검색 결과에 key가 없거나, 아예 트리가 없는 경우

		// 새로운 노드 생성
		ptr = (treePointer)malloc(sizeof(*ptr));
		if (!ptr) {
			fprintf(stderr, "Insufficient memory");
			exit(1);
		}

		// 새로운 노드에 값 대입
		ptr->key = k;
		ptr->value = theItem;
		ptr->lchild = ptr->rchild = NULL;

		// 새로운 노드 위치 선정
		if (*node) { // 새로운 노드가 자식으로 들어가는 경우
			if (k < search_result->key) search_result->lchild = ptr; // 새로운 노드가 왼쪽에 삽입되는 경우
			else search_result->rchild = ptr; // 새로운 노드가 오른쪽에 삽입되는 경우
		}
		else *node = ptr; // 새로운 노드가 root가 되는 경우
	}
}

treePointer modifiedSearch(treePointer node, int k) {
	/* key가 존재할 경우 NULL을 리턴.
	key가 존재하지 않을 경우, 검색 알고리즘에서 방문한 마지막 노드에 대한 포인터를 반환 */
	for (treePointer ptr = node; ptr != NULL;) {
		if (ptr->key == k)
			return NULL;
		if (k < ptr->key) {
			if (ptr->lchild == NULL) return ptr;
			else ptr = ptr->lchild;
		}
		else {
			if (ptr->rchild == NULL) return ptr;
			else ptr = ptr->rchild;
		}
	}
	return NULL;
}

void print_inorder(treePointer ptr) {
	// 이진 탐색 트리를 inorder 방식으로 key, value 출력
	if (ptr) {
		print_inorder(ptr->lchild);
		printf("%d %.1f\n", ptr->key, ptr->value);
		print_inorder(ptr->rchild);
	}
}

treePointer get_new_node() {
	treePointer node = (treePointer)malloc(sizeof(struct node));
	node->key = -1;
	node->value = -1.0;
	node->lchild = NULL;
	node->rchild = NULL;

	return node;
}

treePointer get_sample_data() {
	// 12개의 (key, value) 쌍을 생성하여 이진 탐색 트리에 추가
	// key 값은 1~12로 테스트
	// value 값도 1~12로 테스트
	treePointer root = get_new_node();
	treePointer A = get_new_node();
	treePointer B = get_new_node();
	treePointer C = get_new_node();
	treePointer D = get_new_node();
	treePointer E = get_new_node();
	treePointer F = get_new_node();
	treePointer G = get_new_node();
	treePointer H = get_new_node();
	treePointer I = get_new_node();
	treePointer J = get_new_node();
	treePointer K = get_new_node();

	for (int i = 1; i <= 12; i++) {
		insert(&root, i, (double)i);
	}

	return root;
}