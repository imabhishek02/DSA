#include <iostream>
using namespace std;

int main() {
    float ages[5];

    for (int i = 0; i < 5; i++) {
        cin >> ages[i];
    }
    //your code goes here
    for( int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(ages[j]<ages[i]){
                int temp=ages[i];
                ages[i]=ages[j];
                ages[j]=temp;
            }
        }
    }for (int i=0;i<5;i++){
    
   if(ages[i]<=ages[i+1]){
       cout<<(50-(50*(ages[i]/100)));
       break;
   }
  
    }
        
    
    
    return 0;
}