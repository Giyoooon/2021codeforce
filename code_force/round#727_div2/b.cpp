#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int k;
ll x, t;
vector<int> v;
 
int main() {
	int n, q;
	char str[100001];
	scanf("%d %d", &n, &q);
 
	scanf("%s", str);
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		v.push_back(v[i - 1] + str[i-1] - 'a' + 1);
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", v[r] - v[l-1]);
	}
	
	return 0;
}