#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count_recursiveSearch = 0; // recursiveSearch 를 몇 번 호출했는지 세는 전역 변수. 호출 후에는 반드시 0으로 직접 초기화 할 것!!
int count_print_inorder_short = 0; // print_inorder_short 를 몇 번 호출했는지 세는 전역 변수. 호출 후에는 반드시 0으로 직접 초기화 할 것!!
typedef struct node* treePointer;
struct node {
	int key;
	double value;
	struct node* lchild;
	struct node* rchild;
};

void insert(treePointer*, int, double); // 예제 프로그램 5.17. 강의자료 5장 Page 73
treePointer modifiedSearch(treePointer, int); // 강의자료 5장 Page 74
treePointer recursiveSearch(treePointer, int); // 예제 프로그램 5.15. 강의자료 5장 Page 69
void print_inorder(treePointer); // 강의자료 5장 Page 20 응용
int count_node(treePointer); // 강의자료 5장 Page 33
int count_depth(treePointer); // 강의자료 5장 Page 33 응용
int count_leaf(treePointer); // 강의자료 5장 Page 35
int MAX(int, int); // 두 숫자를 받아서 더 큰 숫자를 반환하는 함수

treePointer get_sample_data(); // 자료구조실습 문제 9.1을 위한 데이터셋
treePointer make_bst(int); // 자료구조실습 문제 9.3을 위한 데이터셋

void print_9_2(treePointer); // 문제 9.2 결과 출력
void print_9_3(); // 문제 9.3 결과 출력

int main() {
	printf("9.1. 12개의 (key, value)쌍을 생성하여 이진 탐색 트리 생성\n");
	treePointer A = get_sample_data();
	printf("생성 완료\n\n");

	printf("9.2. 생성된 이진 검색 트리에서 key값을 활용한 검색\n");
	print_9_2(A);

	printf("9.3. n개의 노드를 가진 이진트리 생성시간 및 노드 수, 높이(깊이), 단말 노드 수 관찰\n");
	print_9_3();

	free(A);
}

void insert(treePointer* node, int k, double theItem) { // node 매개변수는 더블포인터 임에 유의
	/* 트리 내 노드가 k를 가지고 있으면 아무 일도 하지 않음.
	그렇지 않은 경우는 data = (k, theItem)인 새 노드를 첨가 */
	treePointer ptr; // 새로 추가될 노드
	treePointer search_result = modifiedSearch(*node, k); // key 존재시 NULL을 리턴. key가 없을시 검색 결과의 마지막 노드를 반환
	if (search_result || !(*node)) { // 검색 결과에 key가 없거나, 아예 트리가 없는 경우

		// 새로운 노드 생성
		ptr = (treePointer)malloc(sizeof(struct node));
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

treePointer modifiedSearch(treePointer root, int key) {
	/* key가 존재할 경우 NULL을 리턴.
	key가 존재하지 않을 경우, 검색 알고리즘에서 방문한 마지막 노드에 대한 포인터를 반환 */
	for (treePointer ptr = root; ptr != NULL;) {
		if (ptr->key == key) // 기존에 존재하는 키를 입력 : 중복 오류 이므로 NULL을 반환
			return NULL;
		if (key < ptr->key) { // 새로 들어갈 key가 현재 트리에서 가리키고 있는 노드의 key보다 작을 경우
			if (ptr->lchild == NULL) return ptr; // 마지막 노드이므로 반환
			else ptr = ptr->lchild; // 자식이 있으면 자식을 가리킨 뒤에 다시 for 루프를 돈다.
		}
		else { // 위의 if와 원리는 동일하다.
			if (ptr->rchild == NULL) return ptr;
			else ptr = ptr->rchild;
		}
	}
	return NULL; // 마지막 노드를 반환해야 하는데, 알고리즘에 오류가 있어서 강제로 NULL을 반환
}

treePointer recursiveSearch(treePointer root, int key) {
	// key를 포함하고 있는 노드의 포인터를 return
	// 해당되는 노드가 없을 경우, return NULL
	// Recursive version 

	count_recursiveSearch++; // 전역 변수

	if (!root) return NULL;
	if (key == root->key) return root;
	if (key < root->key)  return recursiveSearch(root->lchild, key);
	else                  return recursiveSearch(root->rchild, key);
}

void print_inorder(treePointer ptr) {
	// 이진 탐색 트리를 inorder 방식으로 key, value 출력
	if (ptr) {
		print_inorder(ptr->lchild);
		printf("%d %.6f\n", ptr->key, ptr->value);
		print_inorder(ptr->rchild);
	}
}

int count_node(treePointer ptr) {
	int count = 0;
	if (ptr != NULL)
		count = 1 + count_node(ptr->lchild) + count_node(ptr->rchild);
	return count;
}

int count_depth(treePointer ptr) {
	int depth = 0;
	if (ptr != NULL)
		depth = 1 + MAX(count_depth(ptr->lchild), count_depth(ptr->rchild));
	return depth;
}

int count_leaf(treePointer ptr) {
	int count = 0;

	if (ptr != NULL) {
		if (ptr->lchild == NULL &&
			ptr->rchild == NULL) // 단말 노드
			return 1;
		else count = count_leaf(ptr->lchild) + count_leaf(ptr->rchild);
	}
	return count;
}

int MAX(int a, int b) {
	return (a > b) ? a : b;
}

treePointer get_sample_data() {
	/* 자료구조실습 문제 9.1.
	* 12개의 (key, value) 쌍을 생성하여 이진 탐색 트리에 추가
	* 
	실습 결과보고서 9.1. 에 따라서 key, value 값을 결정
	key : 10, 6, 15, 8, 18, 12, 3, 14, 9, 20, 5, 2
	value : 1.0 / key
	*/
	treePointer root = NULL;

	insert(&root,  10,	1.0 / 10);
	insert(&root,   6,	1.0 / 6);
	insert(&root,  15,	1.0 / 15);
	insert(&root,   8,	1.0 / 8);
	insert(&root,  18,	1.0 / 18);
	insert(&root,  12,	1.0 / 12);
	insert(&root,   3,	1.0 / 3);
	insert(&root,  14,	1.0 / 14);
	insert(&root,   9,	1.0 / 9);
	insert(&root,  20,	1.0 / 20);
	insert(&root,   5,	1.0 / 5);
	insert(&root,   2,	1.0 / 2);

	return root;
}

treePointer make_bst(int n) {
	/* 자료구조실습 문제 9.3.
	* n을 인자로 받아, n개의
	* key : ( rand() / (0x7fff * 1.0) ) * 100,000,000
	* value : 1.0 / key
	* 쌍을 이진 탐색 트리에 추가하는 함수 make_bst(int n)을 작성
	* 
	* 참고 : 
	* rand() 난수의 범위는 0 ~ 32,767
	* 0x7fff는 32,767
	* 따라서 key는 0 ~ 100,000,000 사이의 숫자를 32,768 개의 단위로 쪼갠 숫자가 들어간다.
	*/

	int key;
	double value;
	treePointer root = NULL;

	srand(time(NULL)); // rand()에서 난수를 생성하기 위한 시드 값을 초기화

	for (int i = 0; i < n; i++) {
		key = (rand() / (0x7fff * 1.0) ) * 100000000;
		value = 1.0 / key;

		insert(&root, key, value);
	}

	return root;
}

void print_9_2(treePointer A) {
	int key;
	treePointer resultNode = NULL;
	while (1) {
		// 검색할 key를 입력
		printf("찾고자 하는 key 값을 입력하세요. : ");
		scanf("%d", &key);

		// -1 입력시 종료
		if (key == -1) {
			printf("\n\n"); break;
		}

		// 검색 결과 출력
		resultNode = recursiveSearch(A, key);
		if (resultNode) {
			printf("count : %d, key : %d의 value : %.6f\n", count_recursiveSearch, resultNode->key, resultNode->value);
			count_recursiveSearch = 0; // 초기화를 해서, 다음에 검색 횟수를 샐 때 사용
		}
		else {
			printf("key : %d 노드가 없습니다.\n", key);
			count_recursiveSearch = 0;
		}
	}
}

void print_9_3() {
	int n;
	int theNumberOfNodes, theNumberOfDepths, theNumberOfLeafs;
	int print_count = 0;
	clock_t start, stop; // 프로그램 실행 시간을 재는데 사용되는 변수
	double duration;
	treePointer resultTree = NULL; // 이진검색트리 B
	treePointer resultNode = NULL;

	while (1) {
		// n값 입력
		printf("n개의 노드를 가진 이진검색 트리 생성 (n) : ");
		scanf("%d", &n);

		// -1 입력시 종료
		if (n == -1) break;


		// 트리 생성 및 트리의 정보 계산
		start = clock();
		resultTree = make_bst(n);
		stop = clock();

		duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
		theNumberOfNodes = count_node(resultTree);
		theNumberOfDepths = count_depth(resultTree);
		theNumberOfLeafs = count_leaf(resultTree);


		/* 이진검색트리의 처음 2개, 마지막 3개의 key - value 쌍만 출력
		*
		* 문제 9.3에서 key의 범위는 0 ~ 100,000,000 이므로
		* 이를 이용하여 결과를 출력
		*/
		print_count = 0;

		printf("이진검색트리 : \n");
		printf("(key        value   )\n");
		for (int targetKey = 0; targetKey < 100000000; targetKey++) {
			resultNode = recursiveSearch(resultTree, targetKey);

			if (resultNode) { // 해당되는 노드가 있고
				if (print_count == 0 || // 처음 2개, 마지막 3개에 해당하는 key 라면
					print_count == 1 ||
					print_count == theNumberOfNodes - 1 ||
					print_count == theNumberOfNodes - 2 ||
					print_count == theNumberOfNodes - 3
					)
				{ // 결과를 출력하고 출력 카운트를 높인다.
					printf("(%-9d, %.6f)\n", resultNode->key, resultNode->value);
					print_count++;
				}
				else if (print_count == 2) { // 중간에 ...... 출력
					printf("......\n");
					print_count++;
				}
				else print_count++; // 중간에는 카운트만 높인다.
			}
		}

		// 이진검색트리의 정보 출력
		printf("이진검색트리의 생성시간 : %.3f\n", duration);
		printf("이진검색트리의 노드 수 : %d\n", theNumberOfNodes);
		printf("이진검색트리의 높이(깊이) : %d\n", theNumberOfDepths);
		printf("이진검색트리의 단말노드 수 : %d\n\n", theNumberOfLeafs);

		// 메모리 초기화
		free(resultTree);
	}
}