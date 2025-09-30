#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
	int l_s, r_s;
	l_s = m - l + 1;
	r_s = r - m;

	int l_ar[l_s];
	int r_ar[r_s];

	for (int i =0; i < l_s; i++) {
		l_ar[i] = arr[i + l];
	}

	for (int j = 0; j < r_s; j++) {
		r_ar[j] = arr[m+j +1];
	}

	int l_p = 0, r_p = 0, k = l;

	while (l_p < l_s && r_p < r_s) {
		if (l_ar[l_p] <= r_ar[r_p]) {
			arr[k] = l_ar[l_p];
			l_p++;
		} else {
			arr[k] = r_ar[r_p];
			r_p++;
		}
		k++;
	}


	while (l_p < l_s) {
		arr[k] = l_ar[l_p];
		l_p++;
		k++;
	}

	while (r_p < r_s) {
		arr[k] = r_ar[r_p];
		r_p++;
		k++;
	}
}



void mergeSort(int arr[], int l, int r) {

	if (l < r) {
		int m = l + (r -l) /2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}

}


int main() {
	// just for testing

	int arr[] = {2,3,9,1,0,12,54,4,71,24,21,59,312,41,491,234,33};

	int len = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, 0, len-1);
	


}



