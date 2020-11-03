#include <stdio.h>
#include <stdlib.h>

//정렬되어 있는 n개의 키와 탐색키 k를 입력받아, x>=k인 최대 x값 출력
int n;

int findElement(int *ar, int k);

int main() {
	int *ar, i, k;
	int t;

	scanf("%d %d", &n, &k);
	ar = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", ar + i);
	}

	t = findElement(ar, k);

	printf(" %d", t);

	return 0;
}

//비재귀라서 mid값이 while문 내에서 계속 바뀐다
int findElement(int *ar, int k) {
	int mid;
	int l = 0, r = n;

	l = 0;
	r = n;

	if (k > ar[n - 1]) {
		return n;
	}
	if (k < ar[0]) {
		return 0;
	}

	while (l<r) { //l값에 mid+1이 들어가거나 r값에 mid가 들어가거나 하므로.
		mid = (l + r) / 2;

		if (ar[mid] == k) {
			return mid;
		}
		if (ar[mid] < k) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return r; //문제에서 구하는게 x>=k라서 r값을 반환
}
