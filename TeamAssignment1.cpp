//Developer - Kevin F. Stanley
//Class - Algorithms - CSC 3180
//Assignment - Team Programming Assignment 1
//Description - This program creates an array of points with x,y coordinates randomly generated upon initilization. The user
//              Must input the number at the beginning. The array is looped through compareing each pair, checking to see which is the smallest. The smallest
//              Pair is then displayed to the user.


#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;

// Class point Contains the x, y coordinate
class point{
    public:
      int x;
      int y;

        //Upon initilization, the x and y coordinates are randomly generated between -100 and 100
        point(){
          x = rand() % 200 + -100;
          y = rand() % 200 + -100;
        }

        //Unused class constructor
        point(int num1, int num2){
          num1 = x;
          num2 = y;
        }

        //Print out the values of the coordinates inside the object
        void printP(){
          cout << "x: " << x << "   y: " << y << "\n";
        }

        //returns value of x
        int getx(){
          return x;
        }

        //returns value of y
        int gety(){
          return y;
        }

};

//calculates the distance between two points
float distance(int x1, int y1, int x2, int y2){
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}


int main()
{

// tPoints holds value entered by user. (total points on graph)
int tPoints;
// Sets the seed to use when randomly generating numbers with rand()
srand(time(NULL));

// A while loop catching errors. The program will only continue upon user entering a number.
cout << "Enter number of points to generate.\n";
      while (true)
        {
          cin >> tPoints;
          if (!cin)
          {
            cout << "\nEnter a number of points to generate. Use numbers.\n " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
          }
          else break;
        }

        // Initialize array of point type
        point array[tPoints];

        // Loops through array and prints values of the objects x,y variables
        for (int i=0; i<tPoints; i++) {
          array[i].printP();
        }



cout << "\n********************   Results   ******************** \n";

//min holds value of the smallest. Temp holds value of current compareson.
//The minIndex1 and minIndex2 holds the position index of the two points with
//smallest distance between the two.
float min = 999;
float temp = 0.0;
int minIndex1 = 0;
int minIndex2 = 0;

// Loop to compare every points x,y coordinate with the others.Starts at index one, all elements are compared
// then moves to index two with the inner loop staying to the right side of it.
for(int i=1;i<tPoints-2;i++){

    for(int j=i+1; j<tPoints-1;j++){
      temp = distance(array[i].getx(),array[i].gety(),array[j].getx(),array[j].gety());
      //The basic operation is the comparison between current min and potential next min.
      if(temp < min){
        min = temp;
        minIndex1 = i;
        minIndex2 = j;
      }
    }
}

//Print out the closest points found along with the min distance.
cout << "\nThe 2 closest points are: \n";
array[minIndex1].printP();
array[minIndex2].printP();
cout << "\n" << "Distance: " << min << "\n";














return 0;
}
