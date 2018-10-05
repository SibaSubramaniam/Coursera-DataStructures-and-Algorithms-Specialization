#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct item{
	long long value;
	long long weight;
  double pervalue;
};

bool comparator(struct item a,struct item b){
	double r1=(double)a.value/a.weight;
	double r2=(double)b.value/b.weight;
	return r1>r2;
}

double get_optimal_value(long long capacity, vector<long long> weights, vector<long long> values) {
  double value = 0.0;
  long long n=weights.size();
  struct item arr[n];

  for(long long i=0;i<n;i++){
  	arr[i].value=values[i];
  	arr[i].weight=weights[i];
    arr[i].pervalue=(double)values[i]/weights[i];

  }

  sort(arr,arr+n,comparator);
  
  long long curWeight=0;
  
  for(long long i=0;i<n;i++){
    if(capacity==0)
      return value;

    long long taken=min(arr[i].weight,capacity);
    value+=(double)taken*arr[i].pervalue;
    capacity-=taken;
  }


  return value;
}

int main() {
  long long n;
  long long capacity;
  std::cin >> n >> capacity;
  vector<long long> values(n);
  vector<long long> weights(n);
  for (long long i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout<<fixed<<setprecision(4)<<optimal_value;
  return 0;
}
