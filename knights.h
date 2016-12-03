#ifndef KNIGHTS_H
#define KNIGHTS_H

#include <utility>
#include <vector>
#include <algorithm>

using std::pair;
using std::make_pair;
using std::vector;

typedef vector<pair<int,int> > Path;

/** Helper function: adds two pairs of ints */
pair<int,int> operator+(const pair<int,int> & a, const pair<int,int> & b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

// TODO - your code goes here

Path moves(const pair<int, int> & from) {
    Path pMoves = Path();

    pair<int, int> one = pair(from.first + 1, from.second - 2);
    pair<int, int> two = pair(from.first + 2, from.second - 1);
    pair<int, int> three = pair(from.first + 2, from.second + 1);
    pair<int, int> four = pair(from.first + 1, from.second + 2);
    pair<int, int> five = pair(from.first - 1, from.second + 2);
    pair<int, int> six = pair(from.first - 2, from.second + 1);
    pair<int, int> seven = pair(from.first - 2, from.second - 1);
    pair<int, int> eight = pair(from.first - 1, from.second - 2);
}



// Do not edit below this line

#endif
