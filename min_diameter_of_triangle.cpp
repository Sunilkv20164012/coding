#pragma GCC optimize("Ofast")
/*#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <random>
#include <iomanip>
#include <bitset>
                      
using namespace std;
                      
template<typename T> void uin(T &a, T b) {
    if (b < a) {
        a = b;
    }
}
                      
template<typename T> void uax(T &a, T b) {
    if (b > a) {
        a = b;
    }
}

#define int long long
#define ghost signed
#define left left228
#define right right228
#define prev prev228
#define list list228

const double INF = 1e15;

struct pt
{
	double x, y;
	pt() {}
	pt(double _x, double _y) {
		x = _x;
		y = _y;
	}
};

double dist(pt a, pt b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmpy(const pt &a, const pt &b) {
	return a.y < b.y;
}

double B = INF;

void relax(vector< pt> a, vector<pt > b) {
	// choose 1 point from the a and 2 points from the b
	int j = 0;
	int _j = 0;
	for (int i = 0; i < (int)a.size(); ++i) {
		_j = j;
		while (j && a[i].y - b[j - 1].y <= B) --j;
		int l = j;
		j = _j;
		while (j + 1 < (int)b.size() && b[j + 1].y - a[i].y <= B) ++j;
		int r = j;
		for (int fir = l; fir <= r; ++fir) {
			for (int sec = fir + 1; sec <= r && b[sec].y-b[fir].y<=B; ++sec) {
				uin(B, dist(a[i], b[fir]) + dist(a[i], b[sec]) + dist(b[fir], b[sec]));
			}
		}
	}
}

void solve(vector< pt > p) {
	int sz = (int)p.size();
	if (sz <= 7) {
		for (int i = 0; i < sz; ++i) {
			for (int j = i + 1; j < sz; ++j) {
				for (int k = j + 1; k < sz; ++k) {
					uin(B, dist(p[i],p[j])+dist(p[j],p[k])+dist(p[i],p[k]));
				}
			}
		}
		return ;
	}
	int m = sz / 2;
	vector< pt > a, b;
	for (int i = 0; i < m; ++i) {
		a.push_back(p[i]);
	}
	for (int i = m; i < sz; ++i) {
		b.push_back(p[i]);
	}
	solve(a), solve(b); // we solved recursively!
	vector< pt > aa = a, bb = b;
	a.clear(), b.clear();
	for (pt P : aa) {
		if (p[m].x - P.x > B) continue;
		a.push_back(P);
	}
	for (pt P : bb) {
		if (P.x - p[m].x > B) continue;
		b.push_back(P);
	}
	sort(a.begin(), a.end(), cmpy);
	sort(b.begin(), b.end(), cmpy);
	relax(a, b);
	relax(b, a);
}

int n;

void eeeee() {
	cin >> n;
	vector< pt > p(n);
	for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
	B = INF;
	sort(p.begin(), p.end(), [&](const pt &a, const pt &b) {
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	});
	solve(p);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
	int t;
	cin >> t;
	for (int q = 1; q <= t; ++q) {
		eeeee();
		cout << "Case " << q << ": " << B << "\n";
	}
	return 0;
} // kek ;


