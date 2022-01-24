#include <iostream>
#include <fstream>
#include <vector>

using std::ifstream;
using std::vector;
using std::cout;
using std::endl;


int vectorSum(vector<int> &v)
{
    int res = 0;
    for(int i = 0; i < 3; i++)
        res += v[(v.size()-1)-i];

    return res;
}


int main()
{   
    ifstream input("day1.input");

    int temp, prev = 0, curr, res = 0;

    vector<int> values = vector<int>(3);

    for(int i = 0; i < 3; i++) {

        if(!input) {
            cout << "<not enough measurments>";
            return 0;
        }

        input >> temp;
        values.push_back(temp);
    }

    prev = vectorSum(values);

    while(input)
    {   
        if(!input) {
            cout << "<ending>\n" << res << std::endl;
            return 0;
        }

        input >> temp;
        values.push_back(temp);

        curr = vectorSum(values);

        if(curr > prev)
            res++;
            
        prev = curr;
    }

    cout << res << endl;
    return 0;
}
