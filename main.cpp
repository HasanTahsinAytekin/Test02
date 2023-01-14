#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

template <typename T>
struct Sum{
    T value = 0;
    void operator() (T par){ value += par; }
};

void testLambda() {
    vector<int> a {1,2,3,4,5,6,7,9,11,16,19};
    Sum<int> sum;
// for_each copies sum: we need to copy the result back
    sum = for_each(a.begin(), a.end(), sum);
    cout << "testLambda: result: " << sum.value << endl; // 83
}

int main() {
    using views::filter,
            views::transform,
            views::reverse;
    vector<int> numbers = {10, 8, 6, 5, 4, 3, 2, 1}; // Some data for us to work on
    auto is_even = [](int n) { return n % 2 == 0; }; // Lambda function that will provide filtering
    auto results = numbers | filter(is_even)    // Process our dataset
                   | transform([](int n) {
                       return n++; })
                   | reverse; // Use lazy evaluation to print out the results
    for (auto v: results) {
        cout << v << " ";   // Output: 3 5 7
    }
    cout << endl;

    testLambda();

    cin.get();

    return 0;
}