#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

int main() {
    using views::filter,
            views::transform,
            views::reverse; // Some data for us to work on
    vector<int> numbers = {6, 5, 4, 3, 2, 1}; // Lambda function that will provide filtering
    auto is_even = [](int n) { return n % 2 == 0; }; // Process our dataset
    auto results = numbers | filter(is_even)
                   | transform([](int n) { return n++; })
                   | reverse; // Use lazy evaluation to print out the results
    for (auto v: results) {
        cout << v << " ";   // Output: 3 5 7
    }
    return 0;
}