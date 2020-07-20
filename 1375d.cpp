
/**
 长度为n的数组，值域为[0, n]，每次用该数组的mex替换其中一个位置的值，不超过2n次替换把数组变成不下降序列。
 
 思路：直接构造array:[0,1,2,3,...,n-1]
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1005],b[1005];
int n;

int getv(){
    
    for(int i=0;i<=n;++i){
        b[i]=0;
    }
    for(int i=1;i<=n;++i)b[a[i]]=1;
    for(int i=0;i<=n;++i){
        if(!b[i])return i;
    }return n;
}

int main(){
    
    int t;cin>>t;
    while(t--){
        vector<int> ans;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",a+i);
        }
        while(1){
            int x = getv();
            int aa=1;
            for(int i=2;i<=n;++i){
                if(a[i]<a[i-1])aa=0;
            }
            if(aa)break;
            if(x<n){
                ans.push_back(x+1);
                a[x+1]=x;
            }
            else{
                
                for(int i=1;i<=n;++i)if(a[i]!=i-1){
                    ans.push_back(i);
                    a[i]=x;break;
                }
                
            }
        }
        cout<<ans.size()<<endl;
        for(int v:ans)cout<<v<<" ";cout<<endl;
    }
    return 0;
}

