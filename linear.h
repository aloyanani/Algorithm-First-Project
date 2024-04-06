#pragma once
#include "Graph.h"


class LinearProcess {
public:

	std::unordered_set<int> isLinear( Graph& graph, int startNode) {
        int numVertices = graph.get_count_of_vertices();
        std::unordered_set<int> visited;
        std::queue<int> queue;

        queue.push(startNode);
        visited.insert(startNode);

        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();

            for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
                if (graph[node][neighbor] && visited.find(neighbor) == visited.end()) {
                    queue.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        return visited;
    }
	

};