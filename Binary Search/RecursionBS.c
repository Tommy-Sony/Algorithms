#include <stdio.h>
#include <stdlib.h>

//정렬되어 있는 n개의 키와 탐색키 k를 입력받아, x<=k인 최대 x값 출력
int n;
int an; //전역변수에 답을 저장

int findElement(int *ar, int k); //재귀호출
int rFE(int *ar, int k, int l, int r); //정렬되어 있으므로, 반으로 나눠서 탐색(이진탐색)

int main() {
	int *ar, i, k;
	int t;

	scanf("%d %d", &n, &k);
	ar = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", ar + i);
	}

	t = findElement(ar, k);

	if (t == -1) { 
		if (ar[0] > k) { printf(" %d", t); }
		else {
			printf(" %d", an);
		}
	}
	else { printf(" %d", t); }

	return 0;
}

int findElement(int *ar, int k) {
	return rFE(ar, k, 0, n - 1);
}

int rFE(int *ar, int k, int l, int r) {
	int mid; //계속 절반씩 나누어야하므로 l~mid-1, mid+1~r이 됨

	if (l > r) {
		return -1;
	}

	mid = (l + r) / 2;

	if (k == ar[mid]) {
		return mid;
	}
	else if (k < ar[mid]) {
		return rFE(ar, k, l, mid - 1);
	}
	else {
		an = mid; //문제가 x<=K라서 이 구문이 여깄음!
		return rFE(ar, k, mid + 1, r);
	}
}
