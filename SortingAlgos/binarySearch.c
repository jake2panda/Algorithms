
#include <stdio.h>




int binarySearch(int arr[], int left, int right, int target) {
	if (left > right) {
		return -1;
	}

	int mid = left + (right - left)/2;

	if (arr[mid] == target) {
		printf("arr[%d] = %d\n", mid, arr[mid]);
		return mid;
	}
	if (target < arr[mid]) {
		binarySearch(arr, left, mid, target);
	}else {
		binarySearch(arr, mid +1, right, target);
	}
}


int main() {
	int arr[] = {2,3,9,1,0,12,54,4,71,24,21,59,312,41,491,234,33};


	int len = sizeof(arr) / sizeof(arr[0]);

	// first sort the array


	//binarySearch(arr, 0, len-1, 59);



}


