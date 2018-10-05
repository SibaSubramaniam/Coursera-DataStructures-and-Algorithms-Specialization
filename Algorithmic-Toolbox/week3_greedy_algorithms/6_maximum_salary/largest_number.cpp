#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string isgreaterorEqual(string a,string b){
  if(stoi(a+b)>stoi(b+a))
    return a;
  return b;
}


string largest_number(vector<string> a) {

  string salary;

  int n=a.size();
  while(n!=0){
    string maxdigit=a[0];
    for(size_t i=1;i<n;i++){
        maxdigit=isgreaterorEqual(a[i],maxdigit);
    }
    salary+=maxdigit;
    auto itr=find(a.begin(),a.end(),maxdigit);
    if(itr!=a.end()){
      a.erase(itr);}
    n--;
  }

  cout<<salary;

  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
  return "asda";
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  //out<<isgreaterorEqual("13","31");
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
