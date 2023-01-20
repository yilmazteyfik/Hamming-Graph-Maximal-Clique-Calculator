#include "hammingGraph.h"

int hammingGraph::hammingDistance(const std::string& str1, const std::string& str2) {
    if(str1.length() != str2.length()){
        std::cerr << "ERROR Bits size must be equal !!" << std::endl;
        return -1;
    }
    int distance = 0;
    int size = (int)(str1.length());
    for (int i = 0; i < size; ++i) {
        if(str1[i] != str2[i]){distance++;}
    }
    return distance;
}
void hammingGraph::hammingGraphCreator() {
    for (int i = 0; i < (1 << numberOfBits); i++) {
        std::string str;
        int num = i;
        while (num > 0) {
            str.insert(str.begin(),(num & 1) + '0');
            num >>= 1;
        }
        while (str.size() < numberOfBits) {
            str.insert(str.begin(), '0');
        }
        binaryVector.push_back(str);
    }
}

int hammingGraph::findMaximalClique() {
    int maxClique = 0;
    for (int i = 0; i < (1 << numberOfBits); i++) {
        bool isOkay = true;
        for(auto iterator= maximalClique.begin();iterator != maximalClique.end(); iterator++) {
            const std::string & vector = *iterator;
            if (hammingDistance(binaryVector.at(i), vector) < dimension) {
                isOkay = false;
                break;
            }
        }
        if (isOkay) {
            maximalClique.insert(binaryVector.at(i));
            maximalVector.push_back(binaryToDecimal(binaryVector.at(i)));
        }
    }
    maxClique = (int)maximalClique.size();
    return maxClique;
}

hammingGraph::hammingGraph(int numOfBits, int dim):numberOfBits(numOfBits),dimension(dim) {
    hammingGraphCreator();
}

void hammingGraph::printMaximal() {
    std::vector<int>::iterator iterator;
    for (iterator = maximalVector.begin(); iterator != maximalVector.end() ; iterator++) {
        std::cout << *iterator << " " ;
    }
    std::cout << std::endl;
}

int hammingGraph::binaryToDecimal(const std::string& str1) {
    int result = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == '1') {
            result += (int)pow(2, str1.size() - i - 1);
        }
    }
    return result;
}



