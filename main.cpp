// C++ implementation of the approach
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

// Function to print the required path
void printpath(vector<int>& parent, int vertex, int target)
{
	if (vertex == 0) {
		return;
	}

	printpath(parent, parent[vertex], target);

	cout << vertex << (vertex == target ? "\n" : "->");
}

// Function to return the maximum weight
// in the widest path of the given graph
int widest_path_problem(vector<vector<pair<int, int> > >& Graph,
						int src, int target)
{
	// To keep track of widest distance
	vector<int> widest(Graph.size(), INT_MIN);

	// To get the path at the end of the algorithm
	vector<int> parent(Graph.size(), 0);

	// Use of Minimum Priority Queue to keep track minimum
	// widest distance vertex so far in the algorithm
	priority_queue<pair<int, int>, vector<pair<int, int> >,
				greater<pair<int, int> > >
		container;

	container.push(make_pair(0, src));

	widest[src] = INT_MAX;

	while (container.empty() == false) {
		pair<int, int> temp = container.top();

		int current_src = temp.second;

		container.pop();

		for (auto vertex : Graph[current_src]) {

// Finding the widest distance to the vertex
// using current_source vertex's widest distance
// and its widest distance so far
			int distance = max(widest[vertex.second],
							min(widest[current_src], vertex.first));

// Relaxation of edge and adding into Priority Queue
			if (distance > widest[vertex.second]) {

				// Updating bottle-neck distance
				widest[vertex.second] = distance;

	// To keep track of parent
				parent[vertex.second] = current_src;

// Adding the relaxed edge in the prority queue
				container.push(make_pair(distance, vertex.second));
			}
		}
	}

	// printpath(parent, target, target);

	return widest[target];
}

int path_l(vector<vector<pair<int, int> > >& Graph,
						int src, int target)
{
	// To keep track of widest distance
	vector<int> widest(Graph.size(), INT_MIN);

	// To get the path at the end of the algorithm
	vector<int> parent(Graph.size(), 0);

	// Use of Minimum Priority Queue to keep track minimum
	// widest distance vertex so far in the algorithm
	priority_queue<pair<int, int>, vector<pair<int, int> >,
				greater<pair<int, int> > >
		container;

	container.push(make_pair(0, src));

	widest[src] = INT_MAX;

	while (container.empty() == false) {
		pair<int, int> temp = container.top();

		int current_src = temp.second;

		container.pop();

		for (auto vertex : Graph[current_src]) {

			// Finding the widest distance to the vertex
			// using current_source vertex's widest distance
			// and its widest distance so far
			int distance = max(widest[vertex.second],
							min(widest[current_src], vertex.first));

			// Relaxation of edge and adding into Priority Queue
			if (distance > widest[vertex.second]) {

				// Updating bottle-neck distance
				widest[vertex.second] = distance;

				// To keep track of parent
				parent[vertex.second] = current_src;

				// Adding the relaxed edge in the prority queue
				container.push(make_pair(distance, vertex.second));
			}
		}
	}

	 printpath(parent, target, target);

	return 0;
}

// Driver code
int main()
{
int a[10],b[10],c[10];
int i=0;

ifstream sampleFile("./test1.txt");
int start,destination,weight;
	// Graph representation
	vector<vector<pair<int, int> > > graph;
//cout<<"No of vertices in the graph : "<<endl;
	int no_vertices;
	
	
if(sampleFile.is_open()){
while(sampleFile>>start>>destination>>weight){
a[i]=start;
b[i]=destination;
c[i]=weight;
i=i+1;
//graph[a[i]].push_back(make_pair(c[i],b[i]));
}
}


else
cout<<"File could not open cause of error-might me access permissions"<<endl;

i=no_vertices;
	graph.assign(no_vertices + 1, vector<pair<int, int> >());
	
	for(int x=0;x<i;x++){
	graph[a[x]].push_back(make_pair(c[x],b[x]));}

cout<<"###########RESULTS###########"<<endl;


cout<<path_l(graph,start,destination);

cout << widest_path_problem(graph,start,destination);
sampleFile.close();

	return 0;
}

