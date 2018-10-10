#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int> &a,size_t left,size_t ave,size_t right){
	long long num_of_inversions=0;
	for(size_t i=left;i<ave;i++){
		for(size_t j=ave;j<right;j++){
			if(a[i]>a[j])
				num_of_inversions++;
		}
	}
	return num_of_inversions;
}


long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  
  number_of_inversions+=merge(a,left,ave,right);



  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
