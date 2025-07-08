#include<iostream>
#include<vector>
#include<map>
#include<cassert>
using namespace std;
class Automaton{
    int n; // 状態数
    vector<map<char,int>> to;
    int start;
    vector<int> goals;
    int now;  
public:   
    Automaton(int _n=20,int _start=0,vector<int> _goals=vector<int>{0}):
        n(_n),
        start(_start),
        goals(_goals),
        now(_start)
        {to.resize(n);}
 
    void set_to(int i,char j,int _to)
    {
        assert(i<n);
        to[i][j] = _to;
    }

    void set_to_vec(const vector<map<char,int>> &_to)
    {
        assert((int)_to.size() == n);
        to = _to;
    }

    void set_goals(const vector<int> &_goals)
    {
        goals = _goals;
    }

    int run(string &input)
    {
        for(int u : input)
        {
            if(!to[now].contains(u))
            {
                return -1;
            }
            now = to[now][u];
        }

        for(int u : goals)
        {
            if(now == u)
            {
                return now;
            }
        }
        return now;
    }
};

