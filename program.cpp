 
// Mechanism:

// Ask user for numbers to square
// read users inputs inputs
// calculate the square for the inputs
// print out the inputs and squares

// cout for numbers
// cin for numbers
// throw error if not number
// save number into vector
// calcul

// Struct SqrtPair
// +:
//

// VS

/*
Struct SqrtPair
// cin input and calc sqrt to vector<sqrtsPair>
// looping through sqrtPair

VS

vector nums && vector sqrts

// Saving inputs to nums
// looping through nums to calc sqrts (O(N))
// looping through nums and sqrst to print both vals (O(N))

*/

#include "square.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <cassert>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::numeric_limits;
using std::runtime_error;
using std::streamsize;
using std::string;
using std::to_string;
using std::vector;

int main()
{
    vector<SquarePair> sqPairs;
    SquarePair numPair;
    int num, numDigits;
    int maxDigits = 0;
    string numStr;
    bool includesNegative = false;

    cout << "Enter numbers to square" << endl;

    // invariant: sqPairs.size() is as many num-square pairs as we have asked the user by this far
    while (1)
    {
        try
        {
            if (!(cin >> num)) // What if it is end of file aka buffer is full?
            {
                if (cin.eof())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Only numbers can be squares");
            }
            else
            {
                try
                {
                    numPair.square = square(num);
                    numPair.num = num;

                    sqPairs.push_back(numPair);

                    numDigits = to_string(num).size();

                    if (numDigits > maxDigits)
                    {
                        maxDigits = numDigits;
                    }

                    if (num < 0) {
                        includesNegative = true;
                    }

                    // assert(includesNegative == false);
                }
                catch (const invalid_argument &e)
                {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }
        catch (const runtime_error &e)
        {
            cerr << "Error: " << e.what() << endl;
        }

        // Debug
        for (SquarePair sqPair : sqPairs)
        {
            cout << "Num: " << sqPair.num << endl;
        }
    }

    try
    {
        printPairs(sqPairs, maxDigits, includesNegative);
    }
    catch (const invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}