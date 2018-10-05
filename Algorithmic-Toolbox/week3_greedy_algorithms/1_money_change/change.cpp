#include <iostream>

int get_change(int m) {
  //write your code here
	int no_of_coins=0;
	while(m>=10){
			m=m-10;
			no_of_coins++;
		}
		while(m>=5){
			m=m-5;
			no_of_coins++;
		}
		while(m>=1){
			m=m-1;
			no_of_coins++;
		}
  return no_of_coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
