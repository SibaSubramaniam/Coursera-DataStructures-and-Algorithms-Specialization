#include <iostream>
#include<vector>

using namespace std;

long long pissano_period(long long m){
    long long a=0,b=1,c=a+b;
    for(int i=0;i<m*m;i++){
        c=(a+b)%m;
        a=b;
        b=c;
        if(a==0 && b==1)return i+1;
    }
}

long long get_fibonacci_huge(long long n,long long m){
    long long remainder=n%pissano_period(m);
    long long first=0,second=1,res=remainder;

    for(int i=1;i<remainder;i++){
        res=(first+second)%m;
        first=second;
        second=res;
    }

    return res%m;


}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
