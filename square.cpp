// #define NDEBUG;

#include "square.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <format>
#include <cmath>
#include <string>
#include <cassert>
using std::abs;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::setprecision;
using std::setw;
using std::streamsize;
using std::string;
using std::to_string;
using std::vector;

int square(int num)
{ // inline?
    if (num > 100 || num < -100)
    {
        throw invalid_argument("Max num to square: 100, min: -100");
    }
    return num * num;
}

void printPairs(const vector<SquarePair> &vSquarePairs, int maxDigits, bool includesNegatives) // can be const int& maxWidth?
{
    if (vSquarePairs.size() == 0)
    {
        throw invalid_argument("No squares to print");
    }

    string expressionStr;
    int extraSpace;
    int numSize;

    for (const SquarePair &squarePair : vSquarePairs)
    {
        numSize = to_string(squarePair.num).size();

        extraSpace = maxDigits - numSize;

        if (includesNegatives && squarePair.num >= 0)
        {
            cout << setw(numSize + 1) << squarePair.num;
            extraSpace--;
        }
        else
        {
            cout << squarePair.num;
        }

        cout << setw(2) << "^2" << setw(extraSpace + 3) << " = " << setw(0) << squarePair.square << endl;
    }
}