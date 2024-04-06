#pragma once
#include "Graph.h"

class Production_stages
{
private:
    int N;
    std::vector<std::string> names;

public:
    std::unordered_map<std::string, int> name_to_index;
    std::vector<std::string> index_to_name;

public:

    Production_stages( int _N, const std::vector<std::string> _names) : N(_N), names(_names)
    {
        index_to_name.resize(N);
        for (int i = 0; i < N; ++i) {
            name_to_index[names[i]] = i;
            index_to_name[i] = names[i];
        }

    }
};