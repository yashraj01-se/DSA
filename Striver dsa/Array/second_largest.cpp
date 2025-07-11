#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findSecondLargest(const vector<int>& arr) {
    int first = INT_MIN;
    int second = INT_MIN;

    for (int num : arr) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second && num < first) {
            second = num;
        }
    }

    return (second == INT_MIN) ? -1 : second; // return -1 if no second largest
}

int main() {
    vector<int> arr = {10, 5, 20, 8};
    int result = findSecondLargest(arr);
    cout << "Second largest element: " << result << endl;
}