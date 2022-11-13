#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int p, int q, int r) {
  int a = q - p + 1;
  int b = r - q;
  int L[a], M[b];
  for (int i = 0; i < a; i++)L[i] = arr[p + i];
  for (int j = 0; j < b; j++)M[j] = arr[q + 1 + j];
  int i = 0;   
  int j = 0; 
  int k = p;
  while (i < a && j < b) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < a) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < b) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cout << "Enter Value index " << i << ": ";
        cin >> arr[i];
    }
    cout << "Unsorted array: \n";
    for(int i=0 ; i<n ; i++)
        cout << arr[i] << " ";
    cout << endl;
	mergeSort(arr, 0,n-1);
	cout << "Sorted array: \n";
	for(int i=0 ; i<n ; i++)
        cout << arr[i] << " ";
    cout << endl;
	return 0;
}
