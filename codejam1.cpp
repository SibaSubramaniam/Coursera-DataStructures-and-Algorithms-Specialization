#include<iostream>
#include<set>
using namespace std;


bool anagram(string a,string b){
	if(a.length()!=b.length())return false;
	//cout<<a<<" "<<b<<endl;
	int count1[26]={0};
	int count2[26]={0};

	for(int i=0;a[i];i++){
		count1[a[i]-65]++;
		count2[b[i]-65]++;
	}
	for(int i=0;i<26;i++){
		if(count1[i]!=count2[i])return false;
	}

	return true;
}

int stringgen(){
	int n,count=0;
	cin>>n;
	string a,b;
	cin>>a>>b;

	set<string> b_sub;


	
	for(int i=0;i<n;i++){
		for(int j=1;j<=n-i;j++){
			b_sub.insert(b.substr(i,j));
		}
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=n-i;j++){
			for(auto itr1=b_sub.begin();itr1!=b_sub.end();++itr1){
				if(anagram(a.substr(i,j),*itr1)){
					count++;
					break;
				}
			}
		}
	}
	return count;
}

int main(){
	
	int t;
	cin>>t;
	int arr[t];
	for(int i=0;i<t;i++)
		arr[i]=stringgen();

	for(int i=0;i<t;i++){
		cout<<"Case #"<<i+1<<": "<<arr[i]<<endl;
	}
}