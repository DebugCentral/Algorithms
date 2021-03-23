//Developer: Kevin F. Stanley
//Date 1/20/2021
//Class: CSC 3180 - Algorithms
//Programming Assignment 1

//Include string, io, and limit (to know how much to clear from cin errors) library
#include <string>
#include <iostream>
#include <limits>

using namespace std;

//Main loop
int main(){

//Create empty int array of size 10 (0-9) to store input from user.
int array [9] = {};
int temp, count = 0;

cout << "Enter 10 Numbers.";

//Loop to get input from user
for(int i = 0; i<10; i++)
{
cout << "\nEnter number " << i+1 << ": ";
cin >> array[i];

//Loop to catch invalid input error and force int input.
while(1)
{	//If cin fails, clear input stream, ignore the input, and retry.
	if(cin.fail())
	{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\nYou have entered a noninteger. Please enter an integer...\n";
	cout << "\nEnter number " << i+1 << ": ";
	cin >> array[i];
	}
	if(!cin.fail())
	{
	break;
	}
}
}

//Loop that runs runs through the entire array. Check each element and if its bigger
//than the number stored in temp, replace temp with that number.

//Basic Operation, the if statement within the for loop.
for(int i = 0; i<10; i++)
{
count++;
if(array[i] > temp)
temp = array[i];
}

//Output the biggest number and basic operation count.
cout << "\n" << temp << " is the biggest number.\n";
cout << "The basic operation executed " << count << " times." << endl;

return 0;
}
