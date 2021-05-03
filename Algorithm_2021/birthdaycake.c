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
	//������ head�� null�� �ʱ�ȭ
	L->head = NULL;
}

void buildList(LinkedListType* L, int n) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //1�����
	L->head = p;
	p->data = 1;
	for (int i = 1; i < n; i++) {
		//���ο� ��� ����
		ListNode* pnext = (ListNode*)malloc(sizeof(ListNode));
		//�� �־��ֱ�
		pnext->data = i+1;
		p->link = pnext;
		p = p->link;
	}
	//���������ҿ� ��� ����
	p->link = L->head; 
}

int runSimulation(LinkedListType* L, int n, int k) {
	//���� ��� ���
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p = L->head;

	//�ʰ� ���̻� ����������
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
	printf("�к� �� ������ �Է��ϼ��� : ");
	scanf("%d", &n);

	int k; //�к� ����
	printf("�к� ������ �Է��ϼ��� : ");
	scanf("%d", &k);

	buildList(&list, n);
	printf("���������� ���� �к� : %d", runSimulation(&list, n, k));
}