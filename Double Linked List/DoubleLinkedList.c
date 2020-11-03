#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	struct ListNode *prev;
	char elem;
	struct ListNode *next;
}listNode;


void initList(listNode **header, listNode **tailer) {
	*header = (listNode*)malloc(sizeof(listNode));
	*tailer = (listNode*)malloc(sizeof(listNode));

	(*header)->next = *tailer;
	(*tailer)->prev = *header;
}

void print(listNode *header, listNode *tailer) {
	listNode *p = header->next;

	while (p != tailer) {
		printf("%c", p->elem);
		p = p->next;
	}

	printf("\n");
}

listNode *getNumNode(listNode *header, listNode *tailer, int num) {
	listNode *p = header;
	int i;

	for (i = 0; i < num; i++) {
		p = p->next;
		if (p == tailer) {
			printf("X\n");
			return NULL;
		}
	}

	return p;
}

listNode *insert(listNode *p, char x) {
	listNode *tmp;
	tmp = (listNode*)malloc(sizeof(listNode));
	tmp->elem = x;

	tmp->prev = p;
	tmp->next = p->next;
	p->next->prev = tmp;
	p->next = tmp;

	return tmp;
}

void add(listNode *header, listNode *tailer, int num, char x) {
	listNode *newNode;
	newNode = getNumNode(header, tailer, num - 1);

	if (newNode != NULL) {
		insert(newNode, x);
	}

}

void Delete(listNode *header, listNode *tailer, int num) {
	listNode *p;
	p = getNumNode(header, tailer, num);

	if (p != NULL) {
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}

	free(p);
}

void get(listNode *header, listNode *tailer, int num) {
	listNode *p;

	p = getNumNode(header, tailer, num);
	if (p != NULL) {
		printf("%c", p->elem);
		printf("\n");
	}
}

int main() {
	listNode *header, *tailer;
	int cnt, i;
	char key, ele;
	int num;

	scanf("%d", &cnt);
	getchar();
	initList(&header, &tailer);

	for (i = 0; i < cnt; i++) {
		scanf("%c", &key);
		getchar();
		switch (key)
		{
		case 'i':
			scanf("%d %c", &num, &ele);
			getchar();
			add(header, tailer, num, ele);
			break;
		case 'D':
			scanf("%d", &num);
			getchar();
			Delete(header, tailer, num);
			break;
		case 's':
			scanf("%d", &num);
			getchar();
			get(header, tailer, num);
			break;
		case 'P':
			print(header, tailer);
			break;
		default:
			break;
		}
	}
	return 0;
}
