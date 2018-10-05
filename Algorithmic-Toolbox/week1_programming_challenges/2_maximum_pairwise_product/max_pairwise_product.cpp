#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFaster(const std::vector<int> &numbers){
    long long n=numbers.size(),first=0,second=0;

    if(numbers[0]>numbers[1]){
        first=numbers[0];
        second=numbers[1];
    }
    else{
        first=numbers[1];
        second=numbers[0];
    }

    for(int i=2;i<n;i++){
        if(numbers[i]>first){
            second=first;
            first=numbers[i];
        }
        else if(numbers[i]>second)
            second=numbers[i];
    }
    return first*second;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProductFaster(numbers);
    std::cout << result << "\n";
    return 0;
}
