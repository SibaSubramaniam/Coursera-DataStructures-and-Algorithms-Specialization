#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  if(n==1||n==2){
    summands.push_back(n);
    return summands;
  }
  int present =n;
  for(size_t i=1;i<n;i++){
    
    if(present-i>i)
      summands.push_back(i);
    else{
      summands.push_back(present);
      break;
    }
    present-=i;
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
