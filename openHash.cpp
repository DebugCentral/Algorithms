#include <iomanip>
#include <iostream>
#include <string>
#include <list>

using namespace std;

//Function to return bucket to put data in.
int hashfun(int num){
    //If the number is negative, then dont mod it, just quit the program.
    if(num < 0){
      cout << "\nunable to process negative number.\n";
      exit(-1);
    }
    return (num % 10);
}

//Function to search the approperate bucket for the search item.
//Takes the approperate hash bucket, bucket number, and search item parameters.
void searchBucket(list<string>& HT, int b ,string item){
    //Count variable to keep track of position the item was found in.
    int count = 1;

    //Print out what bucket were searching
    cout << "********* Searching Bucket: " << b <<" ***********" << endl;
    for (list<string>::iterator it = HT.begin(); it != HT.end(); it++  )
      {
        //Check to see if each item in the bucket is the item were searching for.
        if(item == *it){
          cout << "\nItem " << item << " found in bucket " << b << " at position " << count << "\n\n";
          return;
        }
        count++;
      }
      cout << "\nItem " << item << " not found\n" << endl;
}

//Function to print out the hasttable bucket items.
void printList(list<string>& HT, int b){

    cout << "********* Bucket: " << b <<" ***********" << endl;
    for (list<string>::iterator it = HT.begin(); it != HT.end(); it++  )
      {
        cout << *it << endl;
      }
}

//Main function
int main(){

//Create the hash table. 10 buckets total
list<string> HT[10];
//Variable to hold user input
int n = 1;
//Variable to hold user choice
char choice;
//Varibale to hold the search item
int searchNum;



//While loop to force use to keep enters numbers until zero is entered
while(n != 0){

    cout << "Enter a number (Enter 0 when done): ";
    cin >> n;

    while(!cin)
    {
        cout << "Please enter an integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> n;
    }

    if(n==0)
    {break;}
  int h = hashfun(n);
  cout << "bucket: " << h << "    Value: " << n << endl;
  HT[h].push_back(to_string(n));
}

//Loop through all the buckets, printing every element
cout << "\n\n*******************************************************\n\n";
for(int i = 0; i < 10; i++){

  printList(HT[i], i);

}
cout << "\n\n*******************************************************\n\n";

//Loop to force user to selecting yes or no
while(1){

  cout << "Do you want to search for an item? y or n:\n";
  cin >> choice;

    //If the user wants to search for an item
    if(choice == 'y' or choice == 'Y'){
      cout << "Enter search item or -1 to exit.\n";
      //Take user input
      cin >> searchNum;
      while(!cin)
      {
          cout << "Please enter an integer: ";
          cin.clear();
          cin.ignore(10000, '\n');
          cin >> searchNum;
      }

      //Find bucket number the item would be in
      int h = hashfun(searchNum);
      //Search the bucket for that item. (converting the searchNum to string because the list is string)
      searchBucket(HT[h], h, to_string(searchNum));
    }
    //If the user doesn't want to search, break out.
    else if(choice == 'n' or choice == 'N'){
      break;
    }
    //Error catching.
    else{
      cout << "You must enter a valid character.\n";
      cin.clear();
      cin.ignore(10000, '\n');
    }
}


  return 0;
}
