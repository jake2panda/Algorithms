
#include <stdio.h>


/*

Time Complexity O(n²)

*/


void InsertionSort(int arr[], int len) {

	for (int i = 1; i < len; i++) {
		int key = arr[i];
		int j = i -1;

		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j = j -1;
		}
		arr[j + 1] = key;
	}
}


int main() {

	int arr[] = {2,3,9,1,0,12,54,4,71,24,21,59,312,41,491,234,33};



	int len = sizeof(arr) / sizeof(arr[0]);

	InsertionSort(arr, len);


}