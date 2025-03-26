#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int t;cin>>t;
    while(t--){
        int n,m,L;
        cin>>n>>m>>L;
        vector<pair<int,int>> ivs;
        for(int i=0;i<n;i++){
            int l,r;cin>>l>>r;
            ivs.push_back({l,r});
        }
        vector<pair<int,int>> pu;
        for(int i=0;i<m;i++){
            int l,r;cin>>l>>r;
            pu.push_back({l,r});
        }
        priority_queue<int>apu;
        int cur_pu = 0;
        int k = 1,res = 0;
        int flag = 1;
        for(int i=0;i<n;i++){
            int l = ivs[i].first,r = ivs[i].second;
            int it=r-l+1;
            if((it)<k)continue;
            
            for(;cur_pu<m && pu[cur_pu].first<l;cur_pu++){
                apu.push(pu[cur_pu].second);
            }
            
    
            while(apu.size() && (k<=it)){
                k += apu.top();
                apu.pop();
                res++;
                // cout<<"interval"<<it<<" "<<k<<endl;
            }
            if(it>=k){
                flag = 0;
                cout<<-1<<endl;
                break;
            }
        }
        if(flag){
            cout<<res<<endl;
        }
    }
 
}