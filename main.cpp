#include <iostream>
#include <algorithm>
using namespace std;

int x,y;
string str1;
string str2;
long long dist[4000][4000]={0};
void init(){
    for(int i=0;i<=str2.length();i++){
        dist[0][i]=i * x;
    }
    for(int i=0;i<=str1.length();i++){
        dist[i][0]=i * x;
    }
}


int main() {
   cin>>x>>y;
   cin>>str1>>str2;
   init();
   for(int i=1;i<=str1.length();i++){
       for(int j=1;j<=str2.length();j++){
           if(str1[i-1]==str2[j-1]){
               dist[i][j]=dist[i-1][j-1];
           }
           else{
               dist[i][j]= min(min(dist[i-1][j]+x, dist[i][j-1]+x), dist[i-1][j-1]+y);
           }
       }
   }
   cout<<dist[str1.length()][str2.length()];
    return 0;
}
