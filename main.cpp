#include<iostream>

#ifndef AUTOMATON_HPP
#include "automaton.hpp"
#define AUTOMATON_HPP
#endif

int main() {
    Automaton automaton(4,0,vector<int>{2});

    int n,m;
    cin >> n >> m;
    vector<map<char,int>> to(n);
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
        char c;int v;
        cin >> c >> v;
        to[i][c] = v;
    }
    automaton.set_to_vec(to);
    string inp;
    cin >> inp;
    cout << "受理されたか : " << automaton.run(inp) << endl;
    auto hist = automaton.get_histry();
    cout << "遷移 : ";
    for(int v : hist)cout << v << " ";
    cout << endl;
}
