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
    return (val>0)? val%10:(10+val)%10;
}

int lastdigit_sum_restricted(long long m,long long n){
    int val=lastdigit_sum(n,10)-lastdigit_sum(m-1,10);
    return (val>0)? val%10:(10+val)%10;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << lastdigit_sum_restricted(from, to) << '\n';
}
