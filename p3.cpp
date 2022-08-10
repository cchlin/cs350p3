#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;


void insertionSort(int A[], int n) {
  
  int j, key, i;
  for (j = 1; j <= n; ++j) {
    key = A[j]; 
    i = j - 1;
    while ((i >= 0) && A[i] > key) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
  }
}

void printArray(int A[], int n) {

  int i;
  cout << "[";
  for (i = 0; i < n; ++i) {
    if (i < n - 1)
      cout << A[i] << ", ";
    else
      cout << A[i] << "]";

  }
  cout << endl;
}

void merge(int * array, int l , int m, int r) {
  int i, j, k, nl, nr;
  //size of left and right sub-arrays
  nl = m-l+1; nr = r-m;
  int larr[nl], rarr[nr];
  //fill left and right sub-arrays
  for (i = 0; i < nl; i++)
    larr[i] = array[l+i];
  for (j = 0; j < nr; j++)
    rarr[j] = array[m+1+j];
  i = 0; j = 0; k = l;
  //merge temp arrays to real array
  while (i < nl && j < nr) {
    if (larr[i] <= rarr[j]) {
      array[k] = larr[i];
      i++;
    } else {
      array[k] = rarr[j];
      j++;
    }
    k++;
  }
  while (i < nl) { //extra element in left array
    array[k] = larr[i];
    i++;
    k++;
  }
  while (j <nr) { //extra element in the right array
    array[k] = rarr[j];
    j++;
    k++;
  }
}

void mergeSort(int * array, int l, int r) {
  int m;
  if (l <r) {
    m = l + (r-l)/2;
    mergeSort(array, l, m);
    mergeSort(array, m + 1, r);
    merge(array, l, m, r);
  }
}

int main(int argc, char**argv) {

  if (argc != 2) {
    cerr << "usage: " << argv[0] << "<n>" << endl
         << "where <n> is the size of the random arrays" << endl;
  }


  srand(time(NULL));
  clock_t startI, startM, endI, endM;
  
  int n = atoi(argv[1]);
  
  //cout << "Enter the size of array: ";
  //cin >> n;

  int A[n];

  /*
  for (int i = 0; i < n; i++)
    A[i] = rand() % 100;
  */
  for (int i = 0; i < n; i++)
    A[i] = i;

  startI = clock();
  insertionSort(A, n);
  endI = clock();
  //printArray(A, n);
  double time_takenI = double(endI - startI) / double(CLOCKS_PER_SEC);
  cout << "Insertion Sort execution time " << fixed << time_takenI
       << setprecision(10) << " sec " << endl;

  int m = n;
  int B[m];

  /*
  for (int i = 0; i < m; i++)
    B[i] = rand() % 100;
  */
  for (int i = 0; i < m; i++)
    B[i] = i;

  startM = clock();
  mergeSort(B, 0, m - 1);
  endM = clock();
  //printArray(B, m);
  double time_takenM = double(endM - startM) / double(CLOCKS_PER_SEC);
  cout << "Merge Sort execution time " << fixed << time_takenM
       << setprecision(10) << " sec " << endl;

  
  return 0;
}
