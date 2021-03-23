//Kevin F. Stanley
//Class algorithms

// The complex sorting algorithms are being compared to test complexity and sort times.: Kevin F. Stanley

//Purpose: to test time complexity of these 2 topological sorting algorithms using generated data.


#include <iostream>
#include <list>
#include <stack>
#include <chrono>
#include <vector>
#include <queue>
using namespace std;
using namespace std::chrono;

class Graph {
private:
  int n;
  list<int> *adj;
  //Functions

public:
  Graph(int n); //constructor
  void addEdge(int v, int w);
  void printEdges();
  void printVertices();
  void DFSsort();
  void Investigate(int verticies, bool v[]);
  void indegreeSort();
};

Graph::Graph(int n)
{
   this->n = n;
   adj = new list<int> [n];
}

void Graph::printEdges()
{
  cout << "\n\nGraph Edges" << endl;
  list<int>::iterator i;
  for(int v = 0; v < n; v++)
    {
      for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
	  cout << v << " - " << *i << endl;
	}
    }
}

void Graph::printVertices()
{
  cout << "\n\nVertices" << endl;
  for (int v = 0; v < n; v++)
    {
      cout << v << endl;
    }
}
void Graph::addEdge(int v, int w) // add the edges to the graph.
{
   adj[v].push_back(w); //add w to v’s list
}

//Sends the numbers of verticies along with the list of visited nodes
void Graph::Investigate(int verticies, bool visited[])
{
  //Visiting this node so mark as visited.
  visited[verticies] = true;

//create list iterator
  list<int>::iterator i;

  //print out the vertex as we iterate through.
  cout << verticies << " ";


  //the list iterator is set to the vertex passed to it in the function all.
  //Looking at the connected verticies
  for (i = adj[verticies].begin(); i != adj[verticies].end(); ++i)
  {
      //if the vertex hasnt been visited, do a recursive call
      if (!visited[*i]){
          Investigate(*i, visited);

        }
  }
}


void Graph::DFSsort()
{
//Create a new array of booleans to track the nodes we've visited.
bool* visited = new bool[n];
stack<int> stack;


//Set all the booleans to false as nothing has been visited yet.
for (int z = 0; z < n; z++){
    visited[z] = false;}

        //Iterate through the number of verticies. The ones that have been visited are skipped
        for(int v = 0; v < n; v++)
        {
          if(visited[v] == false){

          Investigate(v,visited);

        }
        }

}



//Function from: https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
void Graph::indegreeSort()
{

  int V = n;

    // Create a vector to store
    // indegrees of all
    // vertices. Initialize all
    // indegrees as 0.
    vector<int> in_degree(V, 0);

    // Traverse adjacency lists
    // to fill indegrees of
    // vertices.  This step
    // takes O(V+E) time
    for (int u = 0; u < V; u++) {
        list<int>::iterator itr;
        for (itr = adj[u].begin();
             itr != adj[u].end(); itr++)
            in_degree[*itr]++;
    }

    // Create an queue and enqueue
    // all vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);

    // Initialize count of visited vertices
    int cnt = 0;

    // Create a vector to store
    // result (A topological
    // ordering of the vertices)
    vector<int> top_order;

    // One by one dequeue vertices
    // from queue and enqueue
    // adjacents if indegree of
    // adjacent becomes 0
    while (!q.empty()) {
        // Extract front of queue
        // (or perform dequeue)
        // and add it to topological order
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        // Iterate through all its
        // neighbouring nodes
        // of dequeued node u and
        // decrease their in-degree
        // by 1
        list<int>::iterator itr;
        for (itr = adj[u].begin();
             itr != adj[u].end(); itr++)

            // If in-degree becomes zero,
            // add it to queue
            if (--in_degree[*itr] == 0)
                q.push(*itr);

        cnt++;
    }

    // Check if there was a cycle
    if (cnt != V) {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    // Print topological order
    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i] << " ";
    cout << endl;
}




int main()
{


    cout << "Test data of size 10..." << endl;

    Graph g(10);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(3, 7);
    g.addEdge(7, 8);
    g.addEdge(7, 9);
    g.addEdge(5, 6);

    g.printEdges();
    cout << "DFS Algorithm: \n\n";

    //Take note of the clock and do the sort, stop the clock, and subtract final time from start.
    auto start1 = high_resolution_clock::now();


    g.DFSsort();

    // Stop measuring time and calculate the elapsed time
    auto stop1 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "\nTime taken by function: " << duration1.count() << " microseconds\n\n" << endl;

//**************************************************************************************************


cout << "Test data of size 10..." << endl;

Graph g2(10);

g2.addEdge(0, 2);
g2.addEdge(1, 2);
g2.addEdge(2, 3);
g2.addEdge(3, 4);
g2.addEdge(4, 5);
g2.addEdge(4, 6);
g2.addEdge(3, 7);
g2.addEdge(7, 8);
g2.addEdge(7, 9);
g2.addEdge(5, 6);

cout << "indegree topological sort:  (Sort function from GeeksforGeeks.org)\n\n";

//Take note of the clock and do the sort
auto start2 = high_resolution_clock::now();

// Function Call
g2.indegreeSort();

// Stop measuring time and calculate the elapsed time
auto stop2 = high_resolution_clock::now();
auto duration2 = duration_cast<microseconds>(stop2 - start2);
cout << "\nTime taken by function: " << duration2.count() << " microseconds\n\n" << endl;




return 0;
}
