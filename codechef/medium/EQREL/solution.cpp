#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	int mn=*std::min_element(arr.begin(), arr.end());
	int energy=0;
	for(int i=0;i<n;i++)energy+=(arr[i]-mn);
	cout<<energy<<endl;

}
