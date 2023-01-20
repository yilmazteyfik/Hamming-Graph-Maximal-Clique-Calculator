#include "hammingGraph.h"
#include <chrono>

int main() {
    std::cout << "Enter the value of numOfBits: ";
    int numOfBits;
    std::cin >> numOfBits;
    std::cout << "Enter the value of dimension (binary): ";
    int dimension;
    std::cin >> dimension;
    clock_t tStart = clock();
    hammingGraph hamG(numOfBits, dimension);
    std::cout << "The size of the maximal clique is: " << hamG.findMaximalClique() << std::endl;
    std::cout << "Time taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "Nodes (decimal values of nodes) : " ;
    hamG.printMaximal();
    std::cout << std::endl;
    return 0;
}
