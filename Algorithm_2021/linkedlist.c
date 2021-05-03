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

void addFirst(LinkedListType* L, int item) {
	//���ο� ��� ����
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	//�� �־��ֱ�
	node->data = item;
	node->link = L->head;
	//head�� ù���� ����
	L->head = node;
}

void add(LinkedListType* L, int pos, int item) {
	//���ο� ��� ����
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
	//���ο� ��� ����
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	//������ link���ϱ�
	ListNode* before = L->head;
	ListNode* lastnode = L->head;
	while(lastnode != NULL){
		before = lastnode;
		lastnode = lastnode->link;
	}
	before->link = node;
	//�� ��忡 item �־��ֱ�
	node->data = item;
	node->link = NULL;
}
void removeFirst(LinkedListType* L) {
	//���� ��� ����ֱ�
	ListNode* before = L->head;
	//head�� �ι�° ���� ����
	L->head = before ->link;
	//ù��° ���� ���� ����
	free(before);
}

void remove1(LinkedListType* L, int pos) {
	//���� ��� ���
	ListNode* before = L->head;
	//���ϴ� ��ġ �ϳ� ������ ������
	for (int i = 0; i < pos - 1; i++) {
		before = before->link;
	}
	//������� ��� Ȯ��
	ListNode* deleteNode = before->link;
	//���� ���� ������� ����� ���� ��带 ����
	before->link = deleteNode->link;
	//������� ��� ���� ����
	free(deleteNode);
}

void removeLast(LinkedListType* L){
	//���ο� ��� ����
	ListNode* before = L->head;
	ListNode* lastnode = L->head;

	//������ link���ϱ�
	while (lastnode->link != NULL) {
		before = lastnode;
		lastnode = lastnode->link;
	}
	//�Ѵ� ���� NULL�� �ݾƹ�����
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
	printf("\n ��� ����� ���� ��ȯ�ұ��?");
	scanf("%d", &pos);
	printf("%d�� ����� ���� %d�Դϴ�.\n\n", pos, get(&list, pos));
	printf("removeFirst(&list);\n");
	removeFirst(&list); printList(&list);
	printf("remove1(&list, 3 );\n");
	remove1(&list, 3 ); printList(&list);
	printf("removeLast(&list);\n");
	removeLast(&list); printList(&list);
}