// Programmer:  Kevin F. Stanley
// Algorithms:  Team programming assignment 3
// Description: Heapsort. Most of the code was written by professor frasier. Allows the
//              user to enter numbers to be heapsorted. Builds the max heap, then moves
//              the biggest number to end and decrease the size by one, reheapifying.


#include <iostream>
using namespace std;

void swap(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int ar[], int size)
{
   for(int i = 0; i<size; i++)
      cout << ar[i] << " ";
   cout << endl;
}
// heapify function takes the array, index that we start with, and the size of the array
void heapify(int *ar, int idx, int size )
{
  // right now we only have one parent to worry about
  // we will need to adjust this eventually
  // test if root is bigger than left and right child

  //set the parent index as p
  int p = idx;

  //Calculate left child and right child positions
  int left = 2*p+1;
  int right = 2*p+2;

  //cout << "Check Left Child" << endl;
  if (ar[left] > ar[p] && left < size)
    {
      cout << "\tLeft Child Violation " << ar[p] << " and " << ar[left] << endl;
      //If we're going to swap the left node, prepare to reheapify starting at left node
      p = left;
    }
  //cout << "\n\nCheck Right Child" << endl;
  if (ar[right] > ar[p] && right < size)
    {
      cout << "\tRight Child Violation " << ar[p] << " and " << ar[right] << endl;
      //If we're going to swap the right node, prepare to reheapify starting at right node
      p = right;
    }

    //if parent node isnt the same as the original, swap old parent value with new parent value then reheapify
    if(p != idx)
    {
      //swap parent node with the child node
      swap(ar[p],ar[idx]);
      //heapify at the child node that we swapped
      heapify(ar, p, size);
    }

}

int main()
{

  int size = 0;

  while(size <= 0){
  cout << "How many numbers would you like to enter?" << endl;

  // User sets the size of the array to create
  cin >> size;
  // Forces a user to enter an integer
  while(!cin)
  {
      cout << "Please enter a positive integer as your choice: ";
      cin.clear();
      cin.ignore();
      cin >> size;
  }
}

  int* a = new int[size];

  for(int z=0;z<size;z++)
  {
    cout << "Number " << z+1 << ": ";
    cin >> a[z];
    while(!cin)
    {
        cout << "Please enter a valid integer: ";
        cin.clear();
        cin.ignore();
        cin >> a[z];
    }
  }


// Build the max heap. get the size of array and divide by 2 then subtract 1.
// Iterate up through the heap, performing the swaps.
for(int i= size/2-1; i>=0; i--)
{
  //cout << "i is " << i << endl;
  // Send the array and the parent node that were looking at
  // This starts at the bottom looking at the child.
  heapify(a,i,size);
}
  cout << "\n\n\nThis is the max heap..." << endl;
  display(a, size);
  cout << "size of heap: " << size << endl;

  // for loop to swap the first node (biggest) with the last node (i) and reheapify with the size
  // smaller each iteration so the biggest node doesnt get mixed into the heapify function

  for(int i = size - 1; i >= 0; i--) {
      swap(a[0], a[i]);
      heapify(a, 0, i);
}

cout << "Heap sorted: " << endl;
display(a,size);


   return 0;
}
