#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct table{
  int low;
  int mid;
};
int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

table partition3(vector<int> &a,int low,int high){
  int n=a.size();
  int x=a[low];
  int mid=low;
  while(mid<=high){
   if(a[mid]<x)swap(a[low++],a[mid++]);
   else if(a[mid]==x)mid++;
   else if(a[mid]>x)swap(a[mid],a[high--]);
  }
  table t={low,mid};
  return t;

}


void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  table t = partition3(a, l, r);

  randomized_quick_sort(a, l, t.low-1);
  randomized_quick_sort(a, t.mid, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
