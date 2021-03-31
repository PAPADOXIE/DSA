#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int exponent(int val, int prime, int power){
    if(pow(prime, power) > val){
        return power - 1;
    }
    
    return exponent(val, prime, power++);
}

int solve(int val, int *prime){
    int remval;
    int power = exponent(val, *prime, 1);
    
    std::cout << prime << " " << power << " ";
    
    remval = val - pow(*prime, power);
    prime++;
    
    if(*prime > remval){
        if(remval !=0){
            std::cout << remval << '\n';
        }
    }
    
    return solve(remval, prime);
    
}

int main() {
    int val;
    
    int primetable[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    
    std::cin >> val;
    
    std::cout << solve(val, primetable) << std::endl;
    return 0;
}