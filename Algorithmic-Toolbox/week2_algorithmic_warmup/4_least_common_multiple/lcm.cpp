#include <iostream>

long long eucledian_gcd(long long a,long long b){
	if(b==0)
		return a;
	eucledian_gcd(b,a%b);
}

long long lcm_fast(long a,long long b){
	long long gcd=eucledian_gcd(a,b);
	return ((a*b)/gcd);
}

long long lcm_naive(long long a, long long b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
int  main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
