class PythTriplets 
{
public:
        int gcd(int a, int b)
        {
                return b?gcd(b, a%b):a;
        }
 
        bool edge(int a, int b)//is there an edge between a and b?
        {
		long long _a = a, _b = b, n = _a*_a + _b*_b;
		long long sqr = (long long)(sqrt((double)(n))+1e-9);
		if(sqr*sqr != n) return false;
		return gcd(a, b) == 1;
        }
 
        int findMax(vector <string> stick) 
        {
		string s;
		for(int i = 0; i < stick.size(); i++)
			s += stick[i];
 
		vector<int> v;
		istringstream is(s);
		int a;
		while(is >> a)
			v.push_back(a);
 
		vector<int> nums;//even numbers and then odd numbers(first n numbers are even, the rest are odd)
		for(int i = 0; i < v.size(); i++)
			if(v[i]%2 == 0)
				nums.push_back(v[i]);
		int n = nums.size(), k = v.size() - n;
		for(int i = 0; i < v.size(); i++)
			if(v[i]%2 == 1)
				nums.push_back(v[i]);
 
		
		vector<vector<int> > g(nums.size());
		for(int i = 0; i < v.size(); i++)
			for(int j = i+1; j < v.size(); j++)
				if(edge(nums[i], nums[j]))
					g[i].push_back(j);
 
		//if you use Kuhn algorithm
		KuhnImplementation obj;
                // or if you use max flow algorithm
                //MaxFlowImplementation obj
		return obj.find_max_matching(g, n, k).size();
        }
};
