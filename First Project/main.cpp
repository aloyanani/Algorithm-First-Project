#include "produc.h"
#include "Graph.h"
#include "invert.h"  
#include "kosaraju.h"
#include "linear.h"

int main() {

    int N, M;
    std::cin >> N;

    std::vector<std::string> vec;



    std::string a;
    for (int i = 0; i < N; ++i) {
        std::cin >> a;
        vec.push_back(a);

    }

    Production_stages our_production(N, vec);

    std::cin >> M;
    int from, to;

    Graph g(N);
    for (int i = 0; i < M; ++i) {
        std::cin >> from >> to;
        g.addEdge(from, to);
    }

    std::cout << std::endl;

    StronglyConnectedComponents scc(N, g);

    // Find strongly connected components
    std::vector<std::vector<int>> components = scc.findSCC();

    std::vector<int> my_vec;


    for (std::vector <int> el : components) {
        int count = 0;
        for (int i = el[0] - 1; i > 0; --i) {
            if (g[el[0]][i]) {
                count++;
            }
        }
        if (count == 0) {
            my_vec.push_back(el[0]);
        }
    }

    std::cout << "The number of <irreversible> stages is " << my_vec.size() << ". Those are" << std::endl;

    std::sort(my_vec.begin(), my_vec.end());
    for (int element : my_vec) {
        std::cout << element << "-" << our_production.index_to_name[element] << std::endl;
    }


    for (int i = 0; i < my_vec.size(); ++i) {
        std::cout << "We can go back to " << my_vec[i] << " from  ";

        for (int j = 0; j < N; ++j) {
            if (g[j][my_vec[i]]) {
                std::cout << j << "-" << our_production.index_to_name[j] << " ";
            }
        }
        std::cout << "." << std::endl;

    }

    std::cout << std::endl;

    Graph condensed_g(components.size());
    LinearProcess LinearProcessChecker;
    LinearProcessChecker.Condense_The_Graph(g, condensed_g, components);

    condensed_g.Print();

    // Call the isLinear function from LinearProcessChecker class
    std::unordered_set<int> isLinearSet = LinearProcessChecker.isLinear(condensed_g, 0);

    // Output the result
    if (isLinearSet.size() == components.size()) {
        std::cout << std::endl << "Yes. The process represented by the graph is linear." << std::endl;
        std::cout << "The process is linear because the production passes through all stages and passes in the following sequence : ";
        for (int el : isLinearSet) {
            for (int element : components[el]) {
                for (int el_of_vec : my_vec) {
                    if (element == el_of_vec) {
                        std::cout << element << " ";
                    }
                }



            }
        }
    }
    else {
        std::cout << std::endl << "No. The process represented by the graph is not linear." << std::endl;
    }


    return 0;
}
