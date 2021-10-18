#include <iostream>
using namespace std;

int main() {
    double items[] = {500, 12.4, 94, 45, 3, 81, 1000.9, 85, 90, 1, 35};
    double pf;
    cin>>pf;

    for( int i=0;i<11;i++){
        double dpf=0;
        dpf = items[i]- (items[i]*(pf/100));
        cout<<dpf<<" ";

    }


    return 0;
}
