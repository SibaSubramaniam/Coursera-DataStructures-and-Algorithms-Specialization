#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

struct Segment{
    int value;
    char position;
    size_t index;
};


bool comparator(Segment a,Segment b){
  if(a.value<b.value)return true;
  if(a.value==b.value){
    if(a.position<b.position)return true;
    return false;
  }
  return false;
}
int findwins(vector<Segment> a,int pos){
  if(a[pos].position=='l')pos++;
  if(a[pos].position=='r')pos--;
  long long count=0;
  if(pos>=a.size() || pos<0)return 0;
  while(a[pos].position!='r' && pos>=0){
    pos--;
    if(a[pos].position=='r')break;
    if(a[pos].position=='l')count++;
    
  }
  return count;
}
int binary_search(vector<Segment> a,int l,int r,int x){
  if(r>=l){
    int mid=l+(r-l)/2;

    if(a[mid].value==x)return mid;
    if(a[mid].value>x)return binary_search(a,l,mid-1,x);
    return binary_search(a,mid+1,r,x);
  }
  return -1;
}
vector<int> fast_count_segments(vector<Segment> a,vector<int> points ) {
  int m=points.size();
  vector<int> cnt(m);
  
  sort(a.begin(),a.end(),comparator);
  int segment=0;
  int index=0;
  for(int i=0;i<a.size();i++){
    if(a[i].position=='l')
      segment++;
    else if(a[i].position=='r')
      segment--;
    else{
      cnt[a[i].index]=segment;
      index++;
    }
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<Segment> segments;
  segments.reserve(2*n +m);
  Segment a;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
    Segment a={starts[i],'l',0};
    segments.push_back(a);
    a={ends[i],'r',0};
    segments.push_back(a);

  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
    a={points[i],'p',i};
    segments.push_back(a);
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(segments,points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
