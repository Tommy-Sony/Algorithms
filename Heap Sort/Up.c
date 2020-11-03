#include <stdio.h>

//최대힙
//재귀, 비재귀 둘다 구현
int H[99]; //heap
int n; //size of heap

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

//비재귀 방식으로 상향식 힙 생성
void buildHeap() {
	int i;

	for (i = n / 2; i > 0; i--) {
		downHeap(i); //마지막 내부노드부터 역방향으로 루트까지..
	}
}

//재귀 방식으로 상향식 힙 생성
void rBuildHeap(int i) {
	if (i > n) {
		return;
	}

	rBuildHeap(2 * i); //현재 부트리의 좌 부트리를 힙 생성
	rBuildHeap(2 * i + 1); //현재 부트리의 우 부트리를 힙 생성
	downHeap(i); //현재 부트리의 루트와 좌우 부트리를 합친 힙 생성
}

void printHeap() {
	int i;
	for (i = 1; i < n + 1; i++) {
		printf(" %d", H[i]);
	}

	printf("\n");
}


int main() {
	int i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
	}

	for (i = 1; i <= n; i++) {
		rBuildHeap(i); //매 원소마다 호출
	}

	//buildHeap();
	printHeap();
	return 0;
}
