#pragma once

#include "Graph.h"
#include "invert.h"

class StronglyConnectedComponents {
private:
    Graph& graph;
    int num_of_vertices;
    std::vector<bool> visited;
    std::stack<int> my_stack;

    void FirstDFS(int vertex) {
        visited[vertex] = true;
        for (int i = 0; i < num_of_vertices; ++i) {
            if (graph[vertex][i] && !visited[i]) {
                FirstDFS(i);
            }
        }
        my_stack.push(vertex);
    }

    void SecondDFS(int vertex, std::vector<int>& component) {
        visited[vertex] = true;
        component.push_back(vertex);
        for (int i = 0; i < num_of_vertices; ++i) {
            if (graph[i][vertex] && !visited[i]) {
                SecondDFS(i, component);
            }
        }
    }

    void cleanVisited() {
        for (int i = 0; i < num_of_vertices; ++i) {
            visited[i] = false;
        }
    }

public:
    StronglyConnectedComponents(int _vertices, Graph& _graph) : num_of_vertices(_vertices), graph(_graph) {
        visited.resize(num_of_vertices, false);
    }

    std::vector<std::vector<int>> findSCC() {
        std::vector<std::vector<int>> components;

        cleanVisited();

        for (int i = 0; i < num_of_vertices; ++i) {
            if (!visited[i]) {
                FirstDFS(i);
            }
        }

        Invert_Graph graphInverter;
        Graph inverted_graph(num_of_vertices);
        graphInverter.Invert_graph(graph, inverted_graph);

        cleanVisited();

        while (!my_stack.empty()) {
            int vertex = my_stack.top();
            my_stack.pop();

            if (!visited[vertex]) {
                std::vector<int> component;
                SecondDFS(vertex, component);
                components.push_back(component);
            }
        }

        return components;
    }
};
