#include <stdio.h>

//최대힙
int H[99]; //heap
int n = 0; //size of heap

//인자 위치에 저장된 키를 크기에 맞는 위치로 상향 이동
void upHeap(int i) {
	int tmp;

	if (i == 1) {
		return; 
	}

	//최대힙-인자 위치가 작은 거니까 제대로 있음-리턴
	if (H[i] <= H[i / 2]) {
		return; //트리 구조니까 부모 노드를 보는 것
	}

	//인자 위치가 더 크면 부모와 위치바꿈
	tmp = H[i];
	H[i] = H[i / 2];
	H[i / 2] = tmp;

	upHeap(i / 2); //재귀..
}

//인자 위치에 저장된 키를 크기에 맞는 위치로 하향 이동
void downHeap(int i) {
	int left = 2 * i; //트리 구조니까 자식 노드를 봄
	int right = 2 * i + 1;
	int greater;
	int tmp;

	if (left > n) {
		return;
	}
	greater = left; //왼쪽 자식이라고 가정

	if (right <= n) { //오른쪽 자식이 더 크면 걔랑 비교
		if (H[right] > H[greater]) {
			greater = right;
		}
	}

	//최대힙-인자 위치가 크면 제대로 있는거니까 리턴
	if (H[i] >= H[greater]) {
		return;
	}

	//작으면 자리바꿈
	tmp = H[i];
	H[i] = H[greater];
	H[greater] = tmp;

	downHeap(greater); //재귀..
}

void insertItem(int key) {
	n++;
	H[n] = key;
	upHeap(n);
}

int removeMax() {
	int key;

	if (n > 0) {
		key = H[1];
	}
	H[1] = H[n];
	n--;

	downHeap(1);

	return key;
}


void printHeap() {
	int i;
	for (i = 1; i < n + 1; i++) {
		printf(" %d", H[i]);
	}

	printf("\n");
}


int main() {
	int key;
	char func;

	do {
		scanf("%c", &func);

		switch (func) {
		case 'i':
			scanf("%d", &key);
			getchar();
			insertItem(key);
			printf("%d\n", 0);
			break;

		case 'd':
			key = removeMax();
			printf("%d\n", key);
			break;

		case 'p':
			printHeap();
			break;

		default:
			break;
		}
	} while (func != 'q');
}
