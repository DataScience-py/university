#include <iostream>
#define N 111260083
#define K 0 

int main(){
    std::cout << "1 task:" << (N % 30) + 1 << "\n";
    std::cout << "2 task:" << ((N + (K + 7)) % 30) + 1 << "\n";
    std::cout << "3 task:" << ((N + (K + 13)) % 30) + 1 << "\n";
    std::cout << "4 task:" << ((N + (K + 19)) % 30) + 1 << "\n";
    std::cout << "5 task:" << ((N + (K + 23)) % 30) + 1 << "\n";

    return 0;
};

