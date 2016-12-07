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

    pMoves.emplace_back(from.first + 1, from.second + 2);
    pMoves.emplace_back(from.first + 2, from.second + 1);
    pMoves.emplace_back(from.first + 2, from.second - 1);
    pMoves.emplace_back(from.first + 1, from.second - 2);
    pMoves.emplace_back(from.first - 1, from.second - 2);
    pMoves.emplace_back(from.first - 2, from.second - 1);
    pMoves.emplace_back(from.first - 2, from.second + 1);
    pMoves.emplace_back(from.first - 1, from.second + 2);

    return pMoves;
}

Path legal_moves(const int & size, const Path & path, const pair<int, int> & pos) {
    Path pLegalMoves = Path();
    Path pMoves = moves(pos);

    std::copy_if(pMoves.begin(), pMoves.end(), std::back_inserter(pLegalMoves),
    [size, path](const pair<int, int> & position) {

        bool isInside = position.first >= 0 && position.first < size &&
                position.second >= 0 && position.second < size;
        bool isInPath = std::find(path.begin(), path.end(), position) != path.end();
        return isInside && !isInPath;
    });

    return pLegalMoves;
}

pair<Path, bool> first_tour(const int & size, const Path & path) {
    auto startingPos = path.back();
    auto legalMoves = legal_moves(size, path, startingPos);

    std::sort(legalMoves.begin(), legalMoves.end(), [size, path](pair<int, int> & a, pair<int, int> & b) {

        return legal_moves(size, path, a).size() < legal_moves(size, path, b).size();
    });

    for (int i = 0; i < legalMoves.size(); ++i) {
        Path copy(path);
        copy.push_back(legalMoves[i]);
        auto rec = first_tour(size, copy);
        if(rec.second == true) return make_pair(rec.first, true);
    }

    if (path.size() == size*size) return make_pair(path, true);
    else return make_pair(Path(), false);
};

// Do not edit below this line

#endif
