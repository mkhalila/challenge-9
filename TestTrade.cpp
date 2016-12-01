#include "Trade.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main() {
    vector<int> prices{28, 18, 20, 26, 24};
    
    int profit = bestProfit(prices.begin(), prices.end());
    
    if (profit == 8) {
        cout << "Profit of 8 is correct\n";
    } else {
        cout << "Profit of " << profit << " is incorrect\n";
    }
}
