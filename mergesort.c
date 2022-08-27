#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 1000000
#define MAX_INT_DIGITS 11

void merge_sort(int arr[], int l, int r);

int main(int argc, char const *argv[])
{
	int c, i, j;
	char buf[MAX_INT_DIGITS+1];
	int arr[MAX_LEN];

	i = 0;
	j = 0;

	while ((c = getchar()) != EOF) {
		if (j >= MAX_LEN) {
			break;
		}

		if (isspace(c) && i > 0) {
			// flush the buf
			buf[i] = '\0';
			arr[j++] = atoi(buf);
			i = 0;
		} else if (isdigit(c) && i < MAX_INT_DIGITS) {
			buf[i++] = c;
		}
	}

	// flush the buf
	if (i > 0 && j < MAX_LEN) {
		buf[i] = '\0';
		arr[j++] = atoi(buf);
	}

	// sort the array
	merge_sort(arr, 0, j-1);

	for (i = 0; i < j; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

/* merge_sort: sort an array in ascending order using the merge sorting
   algorithm with O(n*log(n)) time complexity and O(n) space complexity */
void merge_sort(int arr[], int l, int r) {
	if (l >= r) {
		return;
	}

	int i, j, k, mid;
	int temp[r - l + 1];

	mid = (l + r) / 2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid + 1, r);

	for (k = 0, i = l, j = mid + 1; k < (r - l + 1); ++k) {
		if (i > mid) {
			temp[k] = arr[j++];
		} else if (j > r) {
			temp[k] = arr[i++];
		} else if (arr[i] <= arr[j]) {
			temp[k] = arr[i++];
		} else {
			temp[k] = arr[j++];
		}
	}

	// copy sorted values back to the array
	for (i = l; i <= r; ++i) {
		arr[i] = temp[i-l];
	}
}


