#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>
typedef long long ll;

using namespace std;

int n;
ll ruble = 0;
ll total_items, least_buy, current_purchased_items = 0; 
vector<pair<ll,ll> > v;

bool compare(const pair<ll, ll>& a, const pair<ll, ll>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    
    scanf("%d",& n);
    for(int i=0;i<n; i++){
        ll ta, tb;
        scanf("%lld %lld",&ta,&tb);
        v.push_back(make_pair(ta, tb));
        total_items += ta;
    }

    sort(v.begin(), v.end(), compare);
    /*
    for(int i =0;i< n ; i++ ){
        printf("%lld %lld\n",v[i].first, v[i].second);
    }
    */
    least_buy = v[0].second;
    int len = v.size();
    /*
    while(!v.empty()){
        if(least_buy <= current_purchased_items){
            current_purchased_items += v[0].first;
            ruble += v[0].first * 1;
            v.erase(v.begin());
            len--;
            if(!v.empty()){
                least_buy = v[0].second;
            }
        }
        else {
            if(current_purchased_items + v[len-1].first > least_buy){
                v[len - 1].first -= least_buy - current_purchased_items;    
                ruble += 2 * (least_buy- current_purchased_items);
                current_purchased_items = least_buy;
                
                
            }
            else{
                current_purchased_items += v[len-1].first;
                ruble += 2 * v[len - 1].first;
                v[len - 1].first = 0;
            }

            if(v[len-1].first == 0){
                v.erase(v.begin() + (len-1));
                len--;
            } 
        }
        //printf("cur ruble : %d\n",ruble);
    }*/
    int st = 0, end = n - 1;
    while(st <= end){
        if(least_buy <= current_purchased_items){
            current_purchased_items += v[st].first;
            ruble += v[st].first * 1;
            least_buy = v[++st].second;
            
        }
        else {
            if(current_purchased_items + v[end].first > least_buy){
                v[end].first -= least_buy - current_purchased_items;    
                ruble += 2 * (least_buy- current_purchased_items);
                current_purchased_items = least_buy;
            }
            else{
                current_purchased_items += v[end].first;
                ruble += 2 * v[end].first;
                v[end].first = 0;
            }
            if(v[end].first == 0){
                end--;
            } 
        }
    } 
    printf("%lld\n",ruble);
    return 0;
}