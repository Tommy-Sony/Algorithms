#include <stdio.h>
#include <stdlib.h>

//추가 공간사용x - 헤드노드를 사용하지 않음
typedef struct ListNode {
	int elem;
	struct ListNode* link;
}listNode;

typedef struct {
	listNode *L1;
	listNode *L2;
}NodeIdx;

void printList(listNode *L) {
	listNode *p = L;

	while (p != NULL) {
		printf(" %d", p->elem);
		p = p->link;
	}
}

listNode* insertNewNode(int x) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->link = NULL;
	newNode->elem = x;

	return newNode;
}

int getSize(listNode* L) {
	listNode* p;
	int size = 0;

	p = L;

	while (p != NULL) {
		size++;
		p = p->link;
	}

	return size;
}

//단일연결리스트 L을 k개의 사이즈인 리스트L1과 나머지 L2로 나누어 반환
NodeIdx mgPartition(listNode* L, int k) {
	listNode *L1, *L2;
	NodeIdx idx;
	listNode *temp;
	int i = 0;

	temp = L;

	if (getSize(L) > 1) {
		L1 = L;

		while (temp != NULL && i < (k - 1)) {
			temp = temp->link;
			i++;
		}

		L2 = temp->link;
		temp->link = NULL;
	}

	idx.L1 = L1;
	idx.L2 = L2;

	return idx;
}

//L1과 L2를 크기에 맞게 합병하여 하나의 단일연결리스트로 반환
//작>큰 순서대로
listNode* merge(listNode* L1, listNode* L2) {
	listNode *L;

	L = NULL;

	if (getSize(L1) == 0) {
		return L2;
	}
	else if (getSize(L2) == 0) {
		return L1;
	}

	else {
		if (L1->elem <= L2->elem) {
			L = L1;
			L->link = merge(L1->link, L2);
		}
		else {
			L = L2;
			L->link = merge(L1, L2->link);
		}
	}
	return L;
}

//단일연결리스트L의 원소들을 합병정렬하여 정렬된 결과 오름차순으로 출력
void mergeSort(listNode** L) {
	listNode *L1, *L2;
	NodeIdx res;
	int size = getSize(*L) / 2;

	if (size >= 1) {
		res = mgPartition(*L, size); //두개로 분할하고

		L1 = res.L1;
		L2 = res.L2;

		mergeSort(&L1); //각각 정렬
		mergeSort(&L2);

		*L = merge(L1, L2); //하나로 합침

	}

}

int main() {
	listNode *tmpHead, *p;
	int i, x;
	int n;

	scanf("%d", &n);

	tmpHead = (listNode*)malloc(sizeof(listNode));
	tmpHead->link = NULL;
	p = tmpHead;

	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		p->link = insertNewNode(x);
		p = p->link;
	}

	mergeSort(&tmpHead->link);
	printList(tmpHead->link);

	return 0;
}
