#include <stdio.h>

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[],int low, int high) {
	int pivot = arr[high];

	int i = low-1;

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}


void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int p_indx = partition(arr, low, high);
		quickSort(arr, low, p_indx-1);
		quickSort(arr, p_indx +1, high);

	}
}




int main() {

	int arr[] = {2,3,9,1,0,12,54,4,71,24,21,59,312,41,491,234,33};

	int len = sizeof(arr) / sizeof(arr[0]);

	quickSort(arr, 0, len-1);
}





