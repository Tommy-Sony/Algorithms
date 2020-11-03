#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, j;
	int *arr;
	int save;

	scanf("%d", &n);

	//크기가 n인 배열 동적할당
	arr = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	//제자리 정렬 사용
	//배열의 앞 부분을 정렬 상태로 유지
	for (i = 1; i < n; i++) {
		save = arr[i];
		j = i - 1; //범위는 정렬되지 않은 뒷부분

		while ((j >= 0) && (arr[j] > save)) { //작>큰으로 정렬이니까 큰 수 찾으면 교환
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = save;
	}

	for (i = 0; i < n; i++) {
		printf(" %d", *(arr + i));
	}

	free(arr);
	return 0;
}
