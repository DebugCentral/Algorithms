//Developer: Kevin F. Stanley
//Class: Algorithms
//Assignment: Team programming assignment 2
//Description: This program is to calculate the average sorting times of mergeSort
//             and quicksort by sorting randomly generated arrays of 1000 ints.

#include <iomanip>
#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

int printArray(int arr[]){

    for(int i = 0; i < 1000; i++)
    {
      cout << arr[i] << endl;
    }

    return 0;
}



//######################################################################
//
// Functions of Quicksort from:
// https://www.programiz.com/dsa/quick-sort
//
//######################################################################

// Function to swap position of elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high) {
  // Select the pivot element
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    // Select pivot position and put all the elements smaller
    // than pivot on left and greater than pivot on right
    int pi = partition(array, low, high);

    // Sort the elements on the left of pivot
    quickSort(array, low, pi - 1);

    // Sort the elements on the right of pivot
    quickSort(array, pi + 1, high);
  }
}




//######################################################################
//
// Functions of Mergesort from:
// https://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort
//
//######################################################################




void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}

void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}




//#################################################################












int main()
{

  //Initalize arrays to store merge and quick sort times.
  float avgMerge[100];
  float avgQuick[100];
  float avgM = 0;
  float avgQ = 0;
  int temp;

    //For loop to create duplicate arrays of size 1000 to run through quicksort then
    //through mergesort.
    for(int i = 0; i < 100; i++)
    {
    //Change the seed everytime based on time and interater
    srand(time(NULL) + i);

    //Arrays to store random ints to be sorted by quick/merge sort.
    int array1[1000];
    int array2[1000];

            //initalize both arrays with the same random values
            for(int j = 0; j < 1000; j++)
            {
              temp = rand();
              array1[j] = temp;
              array2[j] = temp;
            }

    //Set array size
    int arr_size = sizeof(array1) / sizeof(array1[0]);

    //Call mergesort on first array and take note of the time before and after
    auto start1 = high_resolution_clock::now();
    mergeSort(array1, 0, arr_size - 1);
    auto stop1 = high_resolution_clock::now();

    //Take the duration of mergesort and store it into the avgMerge array
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    avgMerge[i]=duration1.count();



    //Set array size
    arr_size = sizeof(array2) / sizeof(array2[0]);

    //Call quicksort on first array and take note of the time before and after
    auto start2 = high_resolution_clock::now();
    quickSort(array2, 0, arr_size - 1);
    auto stop2 = high_resolution_clock::now();

    //Take the duration of quicksort and store it into the avgQuick array
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    avgQuick[i]=duration2.count();
    }

//Print the results from both the mergesort and quicksort times stored in the avg Arrays
cout << "Results from comparing:\n\n(Mergesort time -- Quicksort time)\nTime is is microseconds\n\n";
for(int y = 0; y<100; y++)
{
  //Adds up the avgM and avgQ
  avgM = avgM + avgMerge[y];
  avgQ = avgQ + avgQuick[y];
  cout << y + 1 << ":  " << avgMerge[y] << " -- " << avgQuick[y] << endl;
}

//Print the average times of mergesort and quicksort
cout << "\nThe averge time of Mergesort: " << avgM/100 << " Microseconds"<< endl;

cout << "The averge time of Quicksort: " << avgQ/100 << " Microseconds" <<"\n\n";

cout << "Code for mergesort from: \nhttps://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort\n\n";
cout << "Code for Quicksort from: \nhttps://www.programiz.com/dsa/quick-sort\n";
return 0;
}
