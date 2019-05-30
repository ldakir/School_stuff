// File: multi_sort.c
// Purpose: Sorting arrays using different sorting algorithms
// Written by: Lamiaa Dakir
// Date: Feb 15, 2019

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define N 20

// From C Programming K. N. KING
void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);
int randint(int a, int b);
void swap(int A[], int i, int j);
void shuffle(int n, int A[]);
void bubblesort(int n, int A[]);
void selectionsort(int n, int A[]);
void merge(int A[], int B[], int a, int b,int result[]);
void merge_sort(int a[], int n);

// From C Programming K. N. KING
void quicksort(int a[], int low, int high){
  int middle;
  if(low >= high) return;
  middle = split(a, low ,high);
  quicksort(a ,low, middle -1);
  quicksort(a, middle +1, high);
}

int split(int a[], int low, int high){
  int part_element = a [low];
  for(;;){
    while(low<high && part_element <= a[high])
      high--;
    if (low >= high) break;
    a[low++] = a[high];
    while(low < high && a[low] <= part_element)
      low++;
    if(low >= high) break;
    a[high--] = a[low];
  }
  a[high] = part_element;
  return high;
}
//From sort.c
//Written by: Deepak Kumar
int randint(int a, int b) {	// returns [a..b)
    return (int) (a + (rand() % (b-a)));
} // randint()

void swap(int A[], int i, int j) {
   int temp = A[i];
   A[i] = A[j];
   A[j] = temp;
} // swap()

void shuffle(int n, int A[]) {	// Shuffle A[] (uses Fisher-Yates algorithm)
    for (int i=0; i <= n-2; i++) {
        int j = randint(i, n);
        swap(A, i, j);
    }
} // shuffle()

//Algorithm taken from
//https://interactivepython.org/runestone/static/pythonds/SortSearch/TheBubbleSort.html
void bubblesort(int n, int A[]){
  if(n ==1){
    return; //array is sorted
  }
  for(int i =0; i < n-1; i++){
    if(A[i]> A[i+1]){
      swap(A, i, i+1); //exchange two elements if there are not in order
    }
  }
  bubblesort(n-1,A); //recursion on the rest of the array
} //bubblesort()

//algorithm taken from data structure Bryn Mawr course slides
void selectionsort(int n, int A[]){
  for( int fill = 0; fill <= n-2; fill++){
    int index_min = fill;
    for( int next= fill +1; next <= n-1; next++){
      if(A[next] < A[index_min])
        index_min= next; //find the index of the smallest element
    }
    swap(A,index_min, fill); //swap A[fill] with A[posMin]
  }
} //selectionsort()
//algorithm taken from data structure Bryn Mawr course slides
//Function that merges two ordered arrays
void merge(int A[], int B[], int a, int b,int result[]){ // a is size of A
  int i =0;
  int j = 0;
  int k = 0;
  //Compare the current items and copy the smallest in the resulting array
  while(j < a && k < b){
    if (A[j] < B[k]){
      result[i] = A[j];
      j++; //increment the index of the array with the smallest current item
    }
    else{
      result[i] = B[k];
      k++;//increment the index of the array with the smallest current item
    }
    i++; //increment the index of the resulting array
  } //end while
  //Copy remaining items from the first array
  while(j<a){
    result[i] = A[j];
    j++;
    i++;
  } //end while
  //Copy remaining items from the second array
  while(k<b){
    result[i] = B[k];
    k++;
    i++;
  } //end while
}// merge()
//algorithm taken from data structure Bryn Mawr course slides
void merge_sort(int a[], int n){
  // if n == 1, the array is sorted
  if (n >1){
    int left[n/2];
    int right[n-(n/2)];
    int j=0;
    //diving the array into two halves
    for(int i =0; i< n/2; i++){
      left[i]= a[j];
      j++;
    }

    for( int i = 0; i< n-(n/2); i++){
      right[i]= a[j];
      j++;
    }
    //sort the left half
    merge_sort(left, n/2);
    //sort the right half
    merge_sort(right, n-(n/2));
    //merge the left and the right
    merge(left, right, n/2,(n-(n/2)),a);
  }
}//merge_sort

int main(){
  int data[N];
  srand(time(NULL));
  //Initialize an array of length N with random numbers from 1 to 100
  printf("Initial array: \n");
  for (int i=0; i < N; i++) {
      data[i] = randint(1, 101);
      printf("%2d ", data[i]);
  }
  printf("Not Sorted.\n");
  //Sort the array using quick sort
  printf("Sorted with quick sort: \n");
  quicksort(data,0, N-1);
  for (int i=0; i < N; i++)
      printf("%2d ", data[i]);
  printf("Sorted.\n");

  //Shuffle the array
  printf("Shuffled array: \n");
  shuffle(N, data);
  for (int i=0; i < N; i++)
      printf("%2d ", data[i]);
  printf("Not Sorted. \n");

  //Sort the array using bubble sort
  printf("Sorted with bubble sort: \n");
  bubblesort(N,data);
  for (int i=0; i < N; i++)
      printf("%2d ", data[i]);
  printf("Sorted.\n");

  //Shuffle the array
  printf("Shuffled array: \n");
  shuffle(N, data);
  for (int i=0; i < N; i++)
      printf("%2d ", data[i]);
  printf("Not Sorted. \n");

  //Sort the array using selection sort
  printf("Sorted with selection sort: \n");
  selectionsort(N,data);
  for (int i=0; i < N; i++)
      printf("%2d ", data[i]);
  printf("Sorted.\n");

  //Shuffle the array
  printf("Shuffled array: \n");
  shuffle(N, data);
  for (int i=0; i < N; i++)
      printf("%2d ", data[i]);
  printf("Not Sorted. \n");

  //Sort the array using merge sort
  printf("Sorted with merge sort: \n");
  merge_sort(data, N);
  for (int i=0; i < N; i++)
      printf("%2d ", data[i]);

  printf("Sorted.\n");
}//end main
