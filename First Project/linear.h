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

    std::unordered_set<int> isLinear(Graph& graph, int startNode) {
        int numVertices = graph.get_count_of_vertices();
        std::unordered_set<int> visited;
        std::queue<int> queue;

        int count = 0;

        queue.push(startNode);
        visited.insert(startNode);

        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();

            count++;
            for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
                if (graph[node][neighbor] && visited.find(neighbor) == visited.end()) {
                    queue.push(neighbor);
                    visited.insert(neighbor);
                    break;
                }
            }
        }
        std::cout << "it is count of bfs steps  - " << count << std::endl;
        return visited;
    }


};