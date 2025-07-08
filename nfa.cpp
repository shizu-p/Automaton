#include<iostream>

#include "NFA.hpp"

using namespace std;

int main() 
{
    NFA nfa(4,0,set<int>{3});
    int n;cin>>n;
    vector < map<char,vector<int>> > to(n);
    for(int i=0;i<n;++i)
    {
        int k;cin>>k;
        for(int j=0;j<k;++j)
        {
            char c;int v;
            cin >> c >> v;
            to[i][c].emplace_back(v);
        }
    }

    nfa.set_to_vec(to);

    string input;
    cin>>input;
    cout << nfa.run(input) << endl;
    nfa.print_histories();
}
