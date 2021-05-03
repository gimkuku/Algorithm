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

void buildList(LinkedListType* L, int n) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //1번노드
	L->head = p;
	p->data = 1;
	for (int i = 1; i < n; i++) {
		//새로운 노드 생성
		ListNode* pnext = (ListNode*)malloc(sizeof(ListNode));
		//값 넣어주기
		pnext->data = i+1;
		p->link = pnext;
		p = p->link;
	}
	//마지막원소와 헤드 연결
	p->link = L->head; 
}

int runSimulation(LinkedListType* L, int n, int k) {
	//시작 노드 잡기
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p = L->head;

	//초가 더이상 없을때까지
	while (p != p->link) {
		for (int i = 0; i < k-1; i++) {
			p = p->link;
		}
		ListNode* pnext = (ListNode*)malloc(sizeof(ListNode));
		pnext = p->link;
		p->link = pnext->link;
		free(pnext);
		p = p->link;
	}
	return p->data;
}

void main() {
	LinkedListType list;
	init(&list);
	int n;
	printf("촛불 총 개수를 입력하세요 : ");
	scanf("%d", &n);

	int k; //촛불 간격
	printf("촛불 간격을 입력하세요 : ");
	scanf("%d", &k);

	buildList(&list, n);
	printf("마지막으로 남은 촛불 : %d", runSimulation(&list, n, k));
}