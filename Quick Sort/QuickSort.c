#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//크기가 n인 배열 동적할당
//입력된 수 중 3개를 랜덤 선택 -> 그 중 중간값을 pivot으로 해서 파티션
//작>큰 순으로 정렬
int n;
int idx[2];

/*반환값은 (a,b) 
배열의 l부터 a-1은 pivot보다 작은 값,
	  b+1부터 r까지는 pivot보다 큰 값
pivot과 같은 값들은 재귀에서 제외된다.
*/
int* inPlacePartition(int *A, int l, int r, int k) {
	int tmp;
	int i, j;
	int p;

	//k가 pivot, A[k] 값 저장
	p = A[k];

	//일단 맨끝으로 보냄
	tmp = A[k];
	A[k] = A[r];
	A[r] = tmp;

	//맨끝으로 보낸 pivot값의 직전까지를 l과 r 범위로 지정
	i = l; //맨 왼쪽부터 시작해서 오른쪽으로 감
	j = r - 1; //맨 오른쪽부터 시작해서 왼쪽으로 감

	if (l < 0 || r < 0) return;
	if (l >= n || r >= n) return;

	while (i < j) {
		while (i < j && A[i] <= p) {
			i = i + 1;
		}

		while (j > i && A[j] > p) {
			j = j - 1;
		}

		if (i < j) {
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}

	if (A[i] <= p) {
		i++;
	}

	//i가 맨 오른쪽까지 갔을테니 pivot 위치 복구
	tmp = A[i];
	A[i] = A[r];
	A[r] = tmp;

	idx[0] = i;
	idx[1] = j;

	return idx;
}

//3개 값 중 중간값 반환
int findPivotIndex(int l, int r) {
	int pivot1, pivot2, pivot3;
	int pivot;

	srand(time(NULL));
	pivot1 = rand() % (r + 1 - l) + l;
	pivot2 = rand() % (r + 1 - l) + l;
	pivot3 = rand() % (r + 1 - l) + l;

	if (pivot1 >= pivot2) {
		if (pivot2 >= pivot3) {
			pivot = pivot2;
		}
		else if (pivot1 <= pivot3) {
			pivot = pivot1;
		}
		else {
			pivot = pivot3;
		}
	}
	else if (pivot1 >= pivot3) {
		pivot = pivot1;
	}
	else if (pivot2 >= pivot3) {
		pivot = pivot3;
	}
	else {
		pivot = pivot2;
	}

	return pivot;
}

//재귀호출
void inplaceQuickSort(int *L, int l, int r) {
	int a, b; //a<b
	int pivot;
	int i;
	if (l >= r) { return; }

	pivot = findPivotIndex(l, r); //피봇값 정해서

	inPlacePartition(L, l, r, pivot); //반으로 나눔
	a = idx[0];
	b = idx[1];

	inplaceQuickSort(L, l, a - 1); //재귀호출
	inplaceQuickSort(L, b + 1, r);
}

int main() {
	int *ar, i;

	scanf("%d", &n);

	ar = (int *)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", ar + i);
	}

	inplaceQuickSort(ar, 0, n - 1);

	for (i = 0; i < n; i++) {
		printf(" %d", *(ar + i));
	}


	return 0;
}
