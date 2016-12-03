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

    pMoves.emplace_back(from.first + 1, from.second - 2);
    pMoves.emplace_back(from.first + 2, from.second - 1);
    pMoves.emplace_back(from.first + 2, from.second + 1);
    pMoves.emplace_back(from.first + 1, from.second + 2);
    pMoves.emplace_back(from.first - 1, from.second + 2);
    pMoves.emplace_back(from.first - 2, from.second + 1);
    pMoves.emplace_back(from.first - 2, from.second - 1);
    pMoves.emplace_back(from.first - 1, from.second - 2);

    return pMoves;
}

Path legal_moves(const int & size, const Path & path, const pair<int, int> & pos) {
    Path pLegalMoves = Path();

    std::copy_if(path.begin(), path.end(), std::back_inserter(pLegalMoves),
    [size, path](const pair<int, int> & position) {

        bool isInside = position.first >= 0 && position.first < size &&
                position.second >= 0 && position.second < size;
        bool isInPath = std::find(path.begin(), path.end(), position) != path.end();
        return isInside && !isInPath;
    });

    return pLegalMoves;
}



// Do not edit below this line

#endif
