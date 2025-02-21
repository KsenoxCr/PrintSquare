#ifndef GUARD_square_h
#define GUARD_square_h

//Square Header File
#include <vector>

struct SquarePair {
    int num;
    int square;
};

int square(int);

void printPairs(const std::vector<SquarePair>&, int, bool);

#endif