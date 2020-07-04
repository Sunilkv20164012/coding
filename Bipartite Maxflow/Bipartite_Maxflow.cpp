#include<vector>
#include<utility>
using namespace std;
 
class MaxFlowImplementation
{
public:
	vector<vector<int> > g;
	vector<bool> used;
	int n, k;
 
	bool find_path(int a, int b) 
        {
		if(a == b) return true;
		if(used[a]) return false;
		used[a] = true;
		for(int i = 0; i < n+k+2; i++) 
			if(g[a][i] > 0 && find_path(i, b))
                        {
				g[a][i]--;
				g[i][a]++;
				return true;
			}
		return false;
	}
 
	vector<pair<int, int> > find_max_matching(vector<vector<int> > &v, int _n, int _k)
        {
		//v[i] is a list of adjacent vertices to vertex i, where i is from left part and v[i][j] is from right part
		n = _n;
		//n is number of vertices in left part of graph
		k = _k;
		//k is number of vertices in right part of graph
 
		g = vector<vector<int> >(n+k+2, vector<int>(n+k+2));
		//g[i][j] = 1 if there is edge between vertex i from left part 
		//            			    and vertex j from right part
		for(int i = 0; i < v.size(); i++)
                    for(int j = 0; j < v[i].size(); j++)
                        g[i][v[i][j]] = 1;
		int S = n+k;
		int T = n+k+1; 
		for(int i = 0; i < n; i++)
			g[S][i] = 1;
		for(int i = 0; i < k; i++)
			g[n+i][T] = 1;
 
		vector<vector<int> > _g(g);
 
		used = vector<bool> (n+k+2, false);
		while(find_path(S, T))
			fill(used.begin(), used.end(), false);
 
		vector<pair<int, int> > res;
		for(int i = 0; i < n; i++)
			for(int j = n; j < n+k; j++)
				if(g[i][j] < _g[i][j])
					res.push_back(make_pair(i, j));
 
		return res;
	}
};
