#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>
typedef long long ll;

using namespace std;

ll n,k,x;
vector <ll> llv;
vector <vector <ll> > llvv;
priority_queue <vector<ll>, vector<ll>,  greater<ll>> pq;
int main (){
    
    scanf("%lld %lld %lld",&n, &k, &x);
    
    for(int i = 0; i < n; i++){
        ll c;
        scanf("%lld",&c);
        llv.push_back(c);
    }
    sort(llv.begin(), llv.end());

    llvv.resize(1);
    llvv[0].push_back(llv[0]);
    
    int idx = 0, group = 0;
    for(int i = 1; i < n; i++){
        if ( llv[i] - llvv[group][idx] <= x ){
                llvv[group].push_back(llv[i]);
                idx++;
        }
        else{
            pq.push(llv[i] - llvv[group][idx]);
            group++;
            idx = 0;
            llvv.resize(group + 1);
            llvv[group].push_back(llv[i]);

        }
    }
    group++;
    if(k == 0){
        printf("%d\n", group);
        return 0;
    }

    while(!pq.empty()){
        ll minus;
        minus = (pq.top() / x);
        if(pq.top() % x == 0){
            minus--;
        }
        
        if(k - minus < 0){
            break;
        }
        k -= minus;
        group--;
        pq.pop();
    }
    printf("%d\n",group);
    return 0;
}