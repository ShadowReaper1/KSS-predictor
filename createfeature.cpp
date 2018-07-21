#include <bits/stdc++.h>
using namespace std;

int main() {
	int count =0;
	vector<double> t;
	vector<double> k;
	while(!cin.eof()){
		double temp1,temp2;
		cin>>temp1>>temp2;
		t.push_back(temp1);
		k.push_back(temp2);
	}
	vector<double> s(t.size(),0);
	vector<double> c(t.size(),0);
	vector<double> td(t.size(),0);
	//constants 
	double sa=3.5,l=2.4,m=2.5,p=24,pi = 3.1415926535897;
	//S is an exponential function representing the time since awakening,dec exp at a rate d=0.0353
	//C represents sleepiness due to circadian influences and has a sinusoidal form with an afterno	on peak
	//from given data ie kss and t -> find time in day(td)
	for(int i=0;i<t.size();i++)
	{
		s[i]=l+(sa-l)*(exp(-1*0.0353*t[i]));
		c[i]=-1*s[i] + ((k[i]-10.9)/(-1.6));
		td[i]=p-((12/pi)*acos(c[i]/2.5));
	}
	//printing the features
	cout<<"hrs	 time	 fatigue\n";
	for(int i=0;i<t.size();i++){
		cout<<t[i]<<"	 "<<td[i]<<"	 "<<k[i]<<"\n";
	}
	return 0;
}
