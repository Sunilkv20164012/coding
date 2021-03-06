Implementation (C++):

#include<vector>
#include<utility>
using namespace std;
 
class KuhnImplementation
{
public:
	int n, k;
	vector < vector<int> > g;
	vector<int> pairs;
	vector<bool> used;
 
 
	bool kuhn (int v) 
        {
		if (used[v])  return false;
		used[v] = true;
		for (int i = 0; i < g[v].size(); ++i) 
                {
			int to = g[v][i]-n;
			if (pairs[to] == -1 || kuhn (pairs[to])) 
                        {
				pairs [to] = v;
				return true;
			}
		}
		return false;
	}
 
	vector<pair<int, int> > find_max_matching(vector<vector<int> > &_g, int _n, int _k) 
        {
		g = _g;
		//g[i] is a list of adjacent vertices to vertex i, where i is from left patr and g[i][j] is from right part
		n = _n;
		//n is number of vertices in left part of graph
		k = _k;
		//k is number of vertices in right part of graph
 
		pairs = vector<int> (k, -1);
		//pairs[i] is a neighbor of vertex i from right part, on marked edge
		used = vector<bool> (n, false);
		for (int i = 0; i < n; ++i) 
                {
			fill(used.begin(), used.end(), false);
			kuhn (i);
		}
	
		vector<pair<int, int> > res;
		for(int i = 0; i < k; i++)
			if(pairs[i] != -1)
				res.push_back(make_pair(pairs[i], i+n));
 
		return res;
 
	}
};

