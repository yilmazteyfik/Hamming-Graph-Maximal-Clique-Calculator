#ifndef HAMMINGGRAPH_HAMMINGGRAPH_H
#define HAMMINGGRAPH_HAMMINGGRAPH_H
#endif //HAMMINGGRAPH_HAMMINGGRAPH_H

#include <iostream>
#include <unordered_set>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

class hammingGraph{
private:
    std::unordered_set <std::string> maximalClique;
    std::vector<std::string> binaryVector;
    std::vector<int> maximalVector;
    int numberOfBits;
    int dimension;
public:
    hammingGraph(int numOfBits, int dim);
    hammingGraph():numberOfBits(0),dimension(0){}
    int hammingDistance(const std::string& str1,const std::string& str2);
    void hammingGraphCreator();
    int findMaximalClique();
    void printMaximal();
    static int binaryToDecimal(const std::string& str);
};
