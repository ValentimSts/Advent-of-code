#include <iostream>
#include <fstream>

using std::ifstream;

int main()
{   
    ifstream input("day1.input");

    int prev, curr, res = 0;

    input >> prev;

    while(input)
    {
        input >> curr;

        if(curr > prev)
            res++;
        
        prev = curr;
    }

    std::cout << res;
    return 0;
}
