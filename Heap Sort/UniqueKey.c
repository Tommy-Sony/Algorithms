#include <stdio.h>

int H[100]; //heap
int n = 0; //size of heap

//연산 효율을 위해 인덱스 0 위치는 사용하지않음

void printArray() {
	int i;
	for (i = 1; i < n + 1; i++) {
		printf("%d ", H[i]);
	}

	printf("\n");
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

	if (right <= n) { //오른쪽 자식이 더 크면 그 값과 비교
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

//n개의 키로 구성된 무순 배열을 제자리 힙 정렬
//최대힙에서 최소힙으로 만들기, 제일 끝 원소와 첫 원소를 교환
void inPlaceHeapSort() {
	int i, tmp;

	for (i = n; i > 1; i--) {
		tmp = H[1];
		H[1] = H[i];
		H[i] = tmp;

		downHeap(1, i - 1);
	}
}


int main() {
	int i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
	}

	buildHeap();
	inPlaceHeapSort();
	printArray();
}
