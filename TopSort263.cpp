// TopSort263.cpp 
//Sarah Arnott
// CIS 263
// October 30th 2020
//
//Adjacency list base code from:
//https://www.tutorialspoint.com/cplusplus-program-to-implement-adjacency-list
//The graph is stored as integers and then converted to the proper letters when it needs to be printed, so that I could use queue/vector methods.

#include<iostream>
#include<list>
#include<iterator>
#include <vector>
#include <queue>
using namespace std;

void displayAdjList(list<int> adj_list[], int v) {
    for (int i = 0; i < v; i++) {
        if (i == 0) {
            cout << 's' << "---> ";
        }
        if (i == 1) {
            cout << 'a' << "---> ";
        }
        if (i == 2) {
            cout << 'd' << "---> ";
        }
        if (i == 3) {
            cout << 'g' << "---> ";
        }
        if (i == 4) {
            cout << 'b' << "---> ";
        }
        if (i == 5) {
            cout << 'e' << "---> ";
        }
        if (i == 6) {
            cout << 'h' << "---> ";
        }
        if (i == 7) {
            cout << 'c' << "---> ";
        }
        if (i == 8) {
            cout << 'i' << "---> ";
        }
        if (i == 9) {
            cout << 'f' << "---> ";
        }
        if (i == 10) {
            cout << 't' << "---> ";
        }
        
        list<int> ::iterator it;
        for (it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
            if (*it == 0) {
                cout << 's' << " ";
            }
            if (*it == 1) {
                cout << 'a' << " ";
            }
            if (*it == 2) {
                cout << 'd' << " ";
            }
            if (*it == 3) {
                cout << 'g' << " ";
            }
            if (*it == 4) {
                cout << 'b' << " ";
            }
            if (*it == 5) {
                cout << 'e' << " ";
            }
            if (*it == 6) {
                cout << 'h' << " ";
            }
            if (*it == 7) {
                cout << 'c' << " ";
            }
            if (*it == 8) {
                cout << 'i' << " ";
            }
            if (*it == 9) {
                cout << 'f' << " ";
            }
            if (*it == 10) {
                cout << 't' << " ";
            }
        }
        cout << endl;
    }
}


void add_edge(list<int> adj_list[], int u, int v) {    //add v into the list u
    adj_list[u].push_back(v);
}


//topological sort using kahn's algorithm. prints the ordering to cout
void topSort(list<int> adj_list[]) {
    //stores in-degrees of all vertices, sets them initially to 0
    vector<int> in_degree(11, 0);

    //store the ordering to be printed
    vector<int> ordering;

    //count of how many vertices have been visited
    int c = 0;

    //set the indegree of each vertex in adj_list using an iterator
    for (int u = 0; u < 11; u++) {
        list<int>::iterator itr;
        for (itr = adj_list[u].begin(); itr != adj_list[u].end(); itr++)
            in_degree[*itr]++;
    }

    //queue to store all vertices with indegree 0, stores them with push()
    queue<int> stack;
    for (int i = 0; i < 11; i++) { //11 is length of adj_list
        if (in_degree[i] == 0)
            stack.push(i);
    }

    //sort until all vertices are sorted
    while (!stack.empty()) {
        //store the vertex to be unqueued
        int unq = stack.front();

        //unqueue it
        stack.pop();

        //add it to the ordering using where we stored it
        ordering.push_back(unq);

        //update indegree of unqueued vertex's neighbors using iterator
        list<int>::iterator itr;
        for (itr = adj_list[unq].begin(); itr != adj_list[unq].end(); itr++) {

            //if the (indegree - 1) is zero, add to queue
            if (--in_degree[*itr] == 0)
                stack.push(*itr);

            c++; //haha, get it?
        }
    }

    // Print ordering after it's completed by the while loop (converting numbers into letters)
    for (int i = 0; i < ordering.size(); i++) {

        if (ordering[i] == 0) {
            cout << 's' << " ";
        }
        if (ordering[i] == 1) {
            cout << 'a' << " ";
        }
        if (ordering[i] == 2) {
            cout << 'd' << " ";
        }
        if (ordering[i] == 3) {
            cout << 'g' << " ";
        }
        if (ordering[i] == 4) {
            cout << 'b' << " ";
        }
        if (ordering[i] == 5) {
            cout << 'e' << " ";
        }
        if (ordering[i] == 6) {
            cout << 'h' << " ";
        }
        if (ordering[i] == 7) {
            cout << 'c' << " ";
        }
        if (ordering[i] == 8) {
            cout << 'i' << " ";
        }
        if (ordering[i] == 9) {
            cout << 'f' << " ";
        }
        if (ordering[i] == 10) {
            cout << 't' << " ";
        }
    }
    cout << endl;
}

int main() {    
    list<int> adj_list[11]; //there are 11 vertices in the graph

    //setting up the graph
    add_edge(adj_list, 0, 1);//s,a
    add_edge(adj_list, 0, 2);//s,d
    add_edge(adj_list, 0, 3);//s,g
    add_edge(adj_list, 1, 4);//a,b
    add_edge(adj_list, 1, 5);//a,e
    add_edge(adj_list, 3, 2);//g,d
    add_edge(adj_list, 3, 5);//g,e
    add_edge(adj_list, 3, 6);//g,h
    add_edge(adj_list, 2, 5);//d,e
    add_edge(adj_list, 4, 7);//b,c
    add_edge(adj_list, 6, 5);//h,e
    add_edge(adj_list, 6, 8);//h,i
    add_edge(adj_list, 5, 7);//e,c
    add_edge(adj_list, 5, 9);//e,f
    add_edge(adj_list, 5, 8);//e,i
    add_edge(adj_list, 9, 7);//f,c
    add_edge(adj_list, 9, 10);//f,t
    add_edge(adj_list, 7, 10);//c,t
    add_edge(adj_list, 8, 9);//i,f
    add_edge(adj_list, 8, 10);//i,t

    cout << "Adjacency list of graph: \n";
    displayAdjList(adj_list, 11); //11 vertices

    cout << "\nTopographical sorting of graph: \n";
    topSort(adj_list);

    cout << "\nComparing the adjacency list to the sorting, we can check that each vertex comes before all of the vertices it has a directed edge to.\n";

    return 0;
}