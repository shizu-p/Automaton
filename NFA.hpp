#ifndef NFA_HPP
#define NFA_HPP

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cassert>

using namespace std;

class NFA{
    int n; // 状態数
    vector< map<char,vector<int>> > to;
    int start;
    set<int> goals;
    vector<int> history;
    vector<vector<int>> histories;


    // 走らせる
    bool execute(string &input,int index,int node)
    {
        history.emplace_back(node);
        if(index == (int)input.size())
        {
            if(goals.contains(node))
            {
                histories.push_back(history);
                history.pop_back();
                return true;
            }
            else 
            {
                history.pop_back();
                return false;
            }
        }

        char target = input[index];
        if(!to[node].contains(target))
        {
            history.pop_back();
            return false;
        }

        bool accepted = false;
        for(auto next : to[node][target])
        {
            if(execute(input,index+1,next))
            {
                accepted = true;
            }
        }
        history.pop_back();
        return accepted;
    }

public:
    NFA(int _n=20,int _start=0,set<int> _goals=set<int>{0}):
        n(_n),
        start(_start),
        goals(_goals)
        {to.resize(n);}

    void set_to(int i,char j,int _to)
    {
        assert(i<n);
        to[i][j].emplace_back(_to);
    }

    void set_to_vec(const vector< map<char,vector<int>> > &_to)
    {
        assert((int)_to.size() == n);
        to = _to;
    }

    void set_goals(const set<int> &_goals)
    {
        goals = _goals;
    }

    // 実行
    bool run(string &input)
    {
        history.clear();
        histories.clear();
        return execute(input,start,0);
    }

    vector<vector<int>> get_histry()
    {
        return histories;
    }

    void print_histories()
    {
        for(auto v : histories)
        {
            for(auto vv : v)
            {
                cout << vv << " ";
            }
            cout << endl;
        }
        return;
    }
};

#endif
