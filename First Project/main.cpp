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
    for (int i = 0; i < N; ++i)
    {
        std::cin >> a;
        vec.push_back(a);

    }

    Production_stages p(N, vec) ;
  /* for (int i = 0; i < N; ++i)
    {
        std::cout << p.index_to_name[i] << " ";
    }
    std::cout << std::endl;*/

    std::cin >> M;
    int from, to;
 
    Graph g(N);
    for (int i = 0; i < M; ++i) {
        std::cin >> from >> to;
        g.addEdge(from, to);
    }
   
    std::cout << "Adjacency Matrix:" << std::endl;
    g.Print();
    std::cout << std::endl;

   
    StronglyConnectedComponents scc(N, g);

    // Find strongly connected components
    std::vector<std::vector<int>> components = scc.findSCC();

    // Output the strongly connected components
    for (int i = 0; i < components.size(); ++i) {
        std::cout << "Component " << i + 1 << ": ";
        for (int j = 0; j < components[i].size(); ++j) {
            std::cout << components[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::vector<int> my_vec;

    for (std::vector <int> el : components) {
        int count = 0;
        for (int i = el[0] - 1 ; i > 0; --i) {
            if (g[el[0]][i]) {
                count++;
            }
        }
        if (count == 0) {
            my_vec.push_back(el[0]);
        }
    }

    
    std::sort(my_vec.begin(), my_vec.end());
   for(int element : my_vec) {
        std::cout << element << " ";
    }


    std::cout << std::endl;
    LinearProcess LinearProcessChecker;
    // Call the isLinear function from LinearProcessChecker class
    std::unordered_set<int> isLinearSet = LinearProcessChecker.isLinear(g, 0);

    // Output the result
    if (isLinearSet.size() == N) {
        std::cout << std::endl << "Yes. The process represented by the graph is linear." << std::endl;

        for (int element : isLinearSet) {
            for (int el_of_vec : my_vec) {
                if (element == el_of_vec) {
                    std::cout << element << " ";
                }
            }
            
        }
    }
    else {
        std::cout << std::endl << "No. The process represented by the graph is not linear." << std::endl;
    }

    
    return 0;
}