#include <iostream>
#include <tensor.hpp>
#include<vector>

int main() {
    std::cout << "Hello from the main file" << std::endl;
    std::vector<std::vector<double>> mat1 = {{1,2},{3,4}}; 
    std::vector<std::vector<double>> mat2 = {{1,2},{3,4}};   
    Tensor t1(mat1);
    Tensor t2(mat2);
    Tensor t3 = t1+t2;
    t3.data();
    t3.size();
    return 0;
}

