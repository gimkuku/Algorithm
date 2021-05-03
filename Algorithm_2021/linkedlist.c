#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L) {
	//시작은 head가 null로 초기화
	L->head = NULL;
}

void addFirst(LinkedListType* L, int item) {
	//새로운 노드 생성
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	//값 넣어주기
	node->data = item;
	node->link = L->head;
	//head와 첫원소 연결
	L->head = node;
}

void add(LinkedListType* L, int pos, int item) {
	//새로운 노드 생성
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++) {
		before = before->link;
	}
	node->data = item;
	node->link = before->link;
	before->link = node;
}
void addLast(LinkedListType* L, int item) {
	//새로운 노드 생성
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	//마지막 link구하기
	ListNode* before = L->head;
	ListNode* lastnode = L->head;
	while(lastnode != NULL){
		before = lastnode;
		lastnode = lastnode->link;
	}
	before->link = node;
	//새 노드에 item 넣어주기
	node->data = item;
	node->link = NULL;
}
void removeFirst(LinkedListType* L) {
	//시작 노드 잡아주기
	ListNode* before = L->head;
	//head와 두번째 원소 연결
	L->head = before ->link;
	//첫번째 원소 연결 끊기
	free(before);
}

void remove1(LinkedListType* L, int pos) {
	//시작 노드 잡기
	ListNode* before = L->head;
	//원하는 위치 하나 전까지 보내기
	for (int i = 0; i < pos - 1; i++) {
		before = before->link;
	}
	//지우려는 노드 확인
	ListNode* deleteNode = before->link;
	//전의 노드와 지우려는 노드의 다음 노드를 연결
	before->link = deleteNode->link;
	//지우려는 노드 연결 끊기
	free(deleteNode);
}

void removeLast(LinkedListType* L){
	//새로운 노드 생성
	ListNode* before = L->head;
	ListNode* lastnode = L->head;

	//마지막 link구하기
	while (lastnode->link != NULL) {
		before = lastnode;
		lastnode = lastnode->link;
	}
	//둘다 끝을 NULL로 닫아버리기
	before->link = NULL;
	free(lastnode);
}


int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++) {
		p = p->link;
	}
	return p->data;
}

void set(LinkedListType* L, int pos, int item) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++) {
		p = p->link;
	}
	p->data = item;
}

void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link) {
		printf("[%d] -> ", p->data);
	}
	printf("NULL\n");
}

void main() {
	LinkedListType list;
	init(&list);
	printf("addFirst(&list, 10);\n");
	addFirst(&list, 10); printList(&list);
	printf("addFirst(&list, 20);\n");
	addFirst(&list, 20); printList(&list);
	printf("add(&list, 1, 40);\n");
	add(&list, 1, 40); printList(&list);
	printf("add(&list, 1, 50);\n");
	add(&list, 1, 50); printList(&list);
	printf("add(&list, 2, 60);\n");
	add(&list, 2, 60); printList(&list);
	printf("add(&list, 2, 70);\n");
	add(&list, 2, 70); printList(&list);
	printf("addLast(&list, 80);\n");
	addLast(&list, 80); printList(&list);
	int pos;
	printf("\n 몇번 노드의 값을 반환할까요?");
	scanf("%d", &pos);
	printf("%d번 노드의 값은 %d입니다.\n\n", pos, get(&list, pos));
	printf("removeFirst(&list);\n");
	removeFirst(&list); printList(&list);
	printf("remove1(&list, 3 );\n");
	remove1(&list, 3 ); printList(&list);
	printf("removeLast(&list);\n");
	removeLast(&list); printList(&list);
}