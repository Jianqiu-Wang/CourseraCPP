// Convert program into C++
// Author: Jianqiu Wang, jw2329[at]cornell[dot]edu
// Date: May 10, 2020

#include <iostream>
#include <vector>

using namespace std;

const int N = 40; // vector size

// sum over vector 
inline void sum(int &p, vector<int> d)
{
    for(vector<int>::iterator it = d.begin(); it != d.end(); ++it)
        p += *it;
}

int main()
{
    int i = 0;
    int accum = 0;
    vector<int> data;
    
    // initialize vector data
    for(i = 0; i < N; ++i)
        data.push_back(i);

    sum(accum, data);
    cout << "sum is " << accum << endl;

    return 0;
}