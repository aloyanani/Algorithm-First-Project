#pragma once
#include "Graph.h"


class LinearProcess {
public:
    void Condense_The_Graph(Graph& _graph, Graph& condensed_graph, std::vector<std::vector<int>> scc) {

        int numVertices = _graph.get_count_of_vertices();
        std::vector<int>node_to_scc(numVertices, 0);

        // Create a mapping from original nodes to their SCC index
        for (int i = 0; i < scc.size(); ++i) {

            for (int node : scc[i]) {
                node_to_scc[node] = i;
            }
        }

        int scc_i, scc_j;

        // Add condensed edges
        for (int i = 0; i < numVertices; ++i) {

            for (int j = 0; j < numVertices; ++j) {

                if (_graph[i][j]) {
                    scc_i = node_to_scc[i];
                    scc_j = node_to_scc[j];

                    if (scc_i != scc_j) {
                        condensed_graph.addEdge(scc_i, scc_j);
                    }
                }
            }
        }



    }
    // Return true if there is one vertex that has no incoming edge
    bool IncomingEdge(std::vector<int> vec) {
        int count = 0;

        for (int i = 0; i < vec.size(); i++) {

            if (vec[i] == 0) {
                count++;
            }
        }

        if (count == 1) {
            return true;
        }
        return false;
    }

    bool isLinearUsingKahn(Graph& graph, int startNode, std::vector<int>& result) {

        int numVertices = graph.get_count_of_vertices();


        std::vector<int> vec(numVertices, 0);

        for (int i = 0; i < numVertices; i++) {

            for (int j = 0; j < numVertices; j++) {

                if (graph[i][j]) {
                    vec[j]++;
                }
            }
        }


        if (!IncomingEdge(vec)) {
            return false;

        }

        std::queue<int> q;



        while (result.size() != numVertices) {

            if (!IncomingEdge(vec)) {
                return false;

            }

            for (int i = 0; i < numVertices; i++) {

                if (vec[i] == 0) {
                    q.push(i);
                    vec[i]--;
                }
            }


            while (!q.empty()) {

                int u = q.front();
                q.pop();
                result.push_back(u);

                // Reduce the count of incoming edges for adjacent vertices
                for (int v = 0; v < numVertices; v++) {

                    if (graph[u][v]) {
                        vec[v]--;
                    }
                }
            }
        }

        return true;
    }
};