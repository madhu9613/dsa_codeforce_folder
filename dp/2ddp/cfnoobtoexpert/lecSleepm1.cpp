#include<bits/stdc++.h>
#define int long long


using namespace std;
// int32_t main()
// {


//     int n,k;cin>>n>>k;
//     int a[n],b[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i];

//     int p[n];  //you can say base sum;
//     p[0]=a[0]*b[0];
//     for(int i=1;i<n;i++)
//     {
//         p[i]=a[i]*b[i]+p[i-1];
//     }

//     //prefix sum:
//     int prefix[n];
//     int s=0;
//     for(int i=0;i<n;i++)
//     {
//         s+=a[i];
//         prefix[i]=s;
//     }


//     //s[i] : sum of a[i...n];
//     int suf[n];
//     s=0;
//     for(int i=n-1;i>0;i--)
//     {
//         s+=a[i]*b[i];
//         suf[i]=s;

//     }

//     int ans=0;
//     for(int i=0;i+k-1<n;i++)
//     {
//         //a[0..i-1] tak ka jo hota hai + sum of all including 0 of [i...i+k-1]+suf[i+k..n](genuine)
         
//         int cur=0;
//         if(i>0) cur+=p[i-1];
//         if(i+k<n) cur+=suf[i+k];

//         int range_sum=prefix[i+k-1];
//         if(i>0) range_sum-=prefix[i-1];

//         cur+=range_sum;

//         ans=max(ans,cur);
        

//     }

//     cout<<ans<<endl;


//     return 0;
// }

//same queation with slidding window as we know that we can handle k element with
// special power so finding it 

int32_t main()
{

int n, k;
cin >> n >> k;
vector<int> a(n), t(n);
for (int i = 0; i < n; ++i) cin >> a[i];
for (int i = 0; i < n; ++i) cin >> t[i];

int base = 0;
for (int i = 0; i < n; ++i)
    if (t[i] == 1) base += a[i];

int max_extra = 0, current_extra = 0;
// Calculate initial window
for (int i = 0; i < k; ++i)
    if (t[i] == 0) current_extra += a[i];

max_extra = current_extra;

// Sliding window
for (int i = k; i < n; ++i) {
    if (t[i - k] == 0) current_extra -= a[i - k];
    if (t[i] == 0) current_extra += a[i];
    max_extra = max(max_extra, current_extra);
}

cout << base + max_extra << endl;

}