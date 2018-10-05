#include<iostream>
#include<vector>
using namespace std;

static std::vector<long long> f(1000);
static std::vector<long long> pissano(10000);

long long pissano_period(long long m,bool flag){
    long long first=0,second=1,current;
    pissano[1]=second;
    for(long long i=0;i<m*m;i++){
        current=(first+second)%m;
        first=second;
        second=current;
        if(flag)pissano[i+2]=current;
        if(first==0 && second==1)
            return i+1;
    }

}

int lastdigit_sum(long long m,long long n){
    int p_num=pissano_period(n,true);
    int val=pissano[(m+2)%p_num]-1;
    return (val>=0)?val:10+val;
}

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << lastdigit_sum(n,10);
}
