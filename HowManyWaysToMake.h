#ifndef HOW_MANY_WAYS_TO_MAKE_H
#define HOW_MANY_WAYS_TO_MAKE_H

// TODO: Your code goes here

template <typename T>
int howManyWaysToMake(T begin, T end, int target) {
    if (target == 0) return 1;
    else if (target > 0 && begin != end)
        return (howManyWaysToMake(begin, end, target - *begin) + howManyWaysToMake(++begin, end, target));
    else return 0;
}

// Do not write any code below this line

#endif
