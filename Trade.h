#ifndef TRADE_H
#define TRADE_H

// TODO your code goes here:

#include <vector>
using std::vector;

template <typename T>
int bestProfit(T begin, T end) {
    if (begin - end == 2) {
        auto first = *begin;
        ++begin;
        auto second = *begin;
        return first - second;
    }

    else if(begin - end == 1) return *begin;

    else {
        int distance = std::distance(begin, end)/2;
        auto middle = begin + distance;
        int firstHalf = bestProfit(begin, middle);
        int secondHalf = bestProfit(middle, end);

        if (firstHalf > secondHalf) return firstHalf;
        else return secondHalf;
    }
}


// Don't write any code below this line

#endif
