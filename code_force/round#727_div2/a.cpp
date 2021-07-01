#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int k;
ll n, x, t;
vector<pair<ll, ll>> v;
 
int main() {
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		ll dis = 0 ;
		scanf("%lld %lld %lld", &n, &x, &t);
		dis += max(n - t/x , (ll) 0)*(t / x);
		if (max(n - t / x , (ll)0) == (n - t / x)) {
			dis += ((t / x) * (t / x - 1)) / 2;
		}
		else {
			dis += (n * (n- 1)) / 2;
		}
		printf("%lld\n", dis);
	}
	return 0;
}