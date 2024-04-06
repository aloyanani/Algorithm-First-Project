#pragma once
#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>

class Graph {
private:
    bool** adjMatrix;
    int numVertices;

public:
    // Initialize the matrix to zero
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix = new bool* [numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = false;
            }
        }
    }

    //Graph(const Graph& graph)
    //{
    //    this->numVertices = graph.numVertices;

    //    // Allocate memory for the adjacency matrix
    //    this->adjMatrix = new bool* [numVertices];
    //    for (int i = 0; i < numVertices; ++i) {
    //        this->adjMatrix[i] = new bool[numVertices];
    //    }

    //    for (int i = 0; i < numVertices; i++) {
    //        for (int j = 0; j < numVertices; j++) {
    //            this->adjMatrix[i][j] = graph.adjMatrix[i][j];
    //        }
    //    }

    //}

    // Add edges
    void addEdge(int i, int j) {
        adjMatrix[i][j] = true;
    }

    // Remove edges
    void removeEdge(int i, int j) {
        adjMatrix[i][j] = false;
    }
    int get_count_of_vertices() {
        return numVertices;

    }

    // Print the matrix
    void Print() {

        std::cout << "    ";

        for (int i = 0; i < numVertices; i++) {
            std::cout << i << " ";
        }
        std::cout << "\n";
        std::cout << "\n";
        for (int i = 0; i < numVertices; i++) {
            std::cout << i << " : ";
            for (int j = 0; j < numVertices; j++) {
                std::cout << adjMatrix[i][j] << " "; // Output the value of the cell
            }
            std::cout << "\n";
        }
    }

    // Operator overloading for accessing elements of the adjacency matrix
    bool* operator[](int index) {
        if (index < 0 || index >= numVertices) {
            std::cerr << "Index out of bounds" << std::endl;
            exit(1);
        }
        return adjMatrix[index];
    }

  

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};
