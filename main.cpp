#include <iostream>
#include <tensor.hpp>
#include<vector>

int main() {
    std::cout << "Hello from the main file" << std::endl;
    std::vector<std::vector<double>> mat1 = {{1.2,4.5},{3.4,0.8}}; 
    std::vector<std::vector<double>> mat2 = {{1.8,2.9},{0.00001,4.13}};   
    Tensor t1(mat1,true);
    Tensor t2(mat2);
    Tensor t3 = t1/t2;

    t3.data();
    std::vector<int64_t> shape = t3.shape();
    for(auto &it:shape){
        std::cout<<it<<" ";
    }
    std::cout<<"\n";
    std::cout<<t1.requires_grad<<"\n";
    t1.grad();
    
    return 0;
}

