#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, j;
	int *arr;
	int tmp, maxLoc;

	scanf("%d", &n);

	//크기가 n인 배열 동적할당
	arr = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	//배열의 뒷부분을 정렬상태로 유지, 가장 큰 값을 찾아 오른쪽부터 채운다.
	for (i = 0; i < n; i++) {
		maxLoc = n - i - 1;
		for (j = n - i - 2; j >= 0; j--) { //범위는 정렬된 뒷부분을 제외한 앞부분
			if (arr[j] > arr[maxLoc]) { //작>큰으로 정렬이니까 큰 수 찾으면 교환
				maxLoc = j;
			}
		}
		tmp = arr[n - i - 1];
		arr[n - i - 1] = arr[maxLoc];
		arr[maxLoc] = tmp;
	}

	for (i = 0; i < n; i++) {
		printf(" %d", *(arr + i));
	}

	free(arr);
	return 0;
}
