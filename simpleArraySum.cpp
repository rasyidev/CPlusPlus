#include <iostream>
using namespace std;

int simpleArraySum (int n){
    int sum =0, i=0;
    int a[n];
    while (n>0){
    	cin >> a[i];
        sum = sum + a[i];
        n--;i++;
    }
    return sum;
}
int main (){
    int n;
    cin >> n;
cout << simpleArraySum(n);
    cout << endl;
    cout << "Done";

}
