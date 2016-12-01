#include "HowManyWaysToMake.h"

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

int testOne() {
    vector<int> coins{1};
    const int possibilities = howManyWaysToMake(coins.begin(), coins.end(), 9);
    
    if (possibilities == 1) {
        cout << "1) Pass: code correctly returns that there is 1 way to make 9 out of {1}\n";     
        return 0;
    } else {
        cout << "1) Fail: code returns that there are " << possibilities << " ways to make 9 out of {1} -- but the answer is 1\n";     
        return 1;
    }
}

int testTwo() {
    list<int> coins{6,2,1};
    const int possibilities = howManyWaysToMake(coins.begin(), coins.end(), 9);
    
    if (possibilities == 7) {
        cout << "2) Pass: code correctly returns that there are 7 ways to make 9 out of {6,2,1}\n";     
        return 0;
    } else {
        cout << "2) Fail: code returns that there are " << possibilities << " ways to make 9 out of {6,2,1} -- but the answer is 7\n";     
        return 1;
    }
}

int main() {
    int retval = 0;
    
    retval += testOne();
    retval += testTwo();    
    
    return retval;
}
