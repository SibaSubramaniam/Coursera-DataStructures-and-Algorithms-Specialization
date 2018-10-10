#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int printarray(vector<int> &v,int start,int stop){
	cout<<endl;
	for(int i=start;i<stop;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}/*

int majority(vector<int> &arr){
	int n =arr.size();
	int maxCount = 0;  
    int index = -1; // sentinels 
    for(int i = 0; i < n; i++) 
    { 
        int count = 0; 
        for(int j = 0; j < n; j++) 
        { 
            if(arr[i] == arr[j]) 
            count++; 
        } 
          
        // update maxCount if count of  
        // current element is greater 
        if(count > maxCount) 
        { 
            maxCount = count; 
            index = i; 
        } 
    } 
      
    // if maxCount is greater than n/2  
    // return the corresponding element  
    if (maxCount > n/2) 
       return arr[index]; 
     return -1;
}*/
int get_majority_element(vector<int> &a, int left, int right) {
 printarray(a,left,right);
  if (left == right)return -1;
  if (left + 1 == right) return a[left];
  
  int mid=(left+right-1)/2 +1;
  int left_major=get_majority_element(a,left,mid);
  int right_major=get_majority_element(a,mid,right);

  int lcount=0,rcount=0;
  for(int i=left;i<right;i++){
  	if(a[i]==left_major)lcount++;
  	if(a[i]==right_major)rcount++;
  }

  if(lcount>(right-left)/2)return left_major;
  if(rcount>(right-left)/2)return right_major;

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
/*
  while(true){
		int n=rand()%1000 +2;
		cout<<n<<"\n";
		std::vector<int> a;

		for (int i = 0; i < n; ++i)
		{
			a.push_back(rand()%10);
		}
		for (int i = 0; i < n; ++i)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		int res1=majority(a);
		
		int res2=get_majority_element(a,0,a.size());

		if(res1!=res2){
			cout<<res1<<" "<<res2<<"\n";
			break;
		}
		else{
			cout<<"OK\n";
		}

	}*/

}
