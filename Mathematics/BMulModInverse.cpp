#include<bits/stdc++.h>
using namespace std;

struct triplet{
    int x,y,gcd;
};

triplet extendedEuclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.y=0;
        ans.x=1;
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

int multiplicativeModuloInverse(int a,int m){
    triplet temp=extendedEuclid(a,m);
    return temp.x;
}

int main()
{
   int a,m;
   cin>>a>>m;
   cout<<multiplicativeModuloInverse(a,m)<<endl;
   return 0;
}