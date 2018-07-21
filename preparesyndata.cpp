#include <bits/stdc++.h>
using namespace std;

int main() {
int count =0;
//data set 
vector<vector<double>> v={{0,3.5},{2,3.4},{4,3.5},{6,3},{8,3.8},{10,4},{12,3.5},{14,4},
{16,3.5},{18,5},{20,5.5},{20,5.5},{22,6},{24,6},{26,5},{28,4.5},{30,5},{32,4.8},
{34,4.5},{36,3.5},{38,4},{40,5},{42,6},{44,6},{46,6.5},{48,7},{50,6.5},{52,6.8},{54,6},{56,6.4},
{58,5},{60,6},{62,4.5},{64,5.8},{66,6.1},{68,6.2},{70,6.4},{72,6.5},{74,6.2},{76,5.8},{78,6.1},
{80,6.2},{82,6},{84,6.1},{86,5.8}};

vector<vector<double>> v2;
//creating syn data from given data using mean of 2 elements 
while(count<800){
	for(int i=0;i<v.size()-1;i++){
		vector<double> v1={(v[i][0]+v[i+1][0])/2,(v[i][1]+v[i+1][1])/2};
                   	v2.push_back(v1);
		count++;
	}
	for(int i=0;i<v2.size();i++) v.push_back(v2[i]);
	
	sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++)
    	v.erase( unique( v.begin(), v.end() ), v.end() );
}
for(int i=0;i<v.size()-1;i++){
	cout<<v[i][0]<<"	 "<<v[i][1]<<"\n";
}
	return 0;
}
