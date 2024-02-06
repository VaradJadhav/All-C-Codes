#include<bits/stdc++.h>
using namespace std;

struct triplet{
    int x,y,gcd;
};

triplet extendedEuclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet smallans=extendedEuclid(b,a%b);
    triplet ans;
    ans.gcd=smallans.gcd;
    ans.x=smallans.y;
    ans.y=smallans.x - (a/b)*smallans.y;
    return ans;
}

int main()
{
   int a,b;
   cin>>a>>b;
   triplet ans = extendedEuclid(a,b);
   cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y;
   
   return 0;
}