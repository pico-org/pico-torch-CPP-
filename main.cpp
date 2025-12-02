#include <iostream>
#include <tensor.hpp>
#include<vector>

int main() {
    std::cout << "Hello from the main file" << std::endl;
    std::vector<std::vector<double>> mat1 = {{1.2,2.5},{3.4,4.6}}; 
    std::vector<std::vector<double>> mat2 = {{1.8,2.9},{0.00001,4.13}};   
    Tensor t1(mat1);
    Tensor t2(mat2);
    Tensor t3 = t1/t2;
    t3.data();
    t3.size();
    std::cout<<t1.address<<std::endl;
    std::cout<<t2.address<<std::endl;
    std::cout<<t3.address<<std::endl;
    for(auto &it:t3._parents){
        std::cout<<it<<std::endl;
    }
    return 0;
}

