#pragma once
#include "Graph.h"


class Invert_Graph {
public:

    void Invert_graph(Graph& _graph, Graph& inverted_graph) {
        int numVertices = _graph.get_count_of_vertices();
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (_graph[i][j]) {
                    inverted_graph.addEdge(j, i);
                }
            }
        }
    }




};
