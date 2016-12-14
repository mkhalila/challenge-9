#ifndef TRADE_H
#define TRADE_H

// TODO your code goes here:

#include <vector>
using std::vector;

#include <numeric>

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
int bestProfit(T begin, T end) {
    int first = *begin;

    return std::accumulate(begin, end, 0, [&first](int profit, int & value) {
               if ((value - first) > profit)
                   profit = value - first;
               if (value < first) first = value;
               return profit;
    });
}


// Don't write any code below this line

#endif
