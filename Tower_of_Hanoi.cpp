#include <iostream>
using namespace std;

void tower(int n,char source, char help,char dest){
 if(n==0){
     return;
 }
 tower(n-1,source,dest,help);
 cout<<"move from "<<source<<" to "<<dest<<endl;
 tower(n-1,help,source,dest);
}

int main(){
    tower(3,'A','B','C');
    return 0;
}