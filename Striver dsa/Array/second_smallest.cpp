#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findSecondSmallest(const vector<int>& arr) {
    int first_smallest = INT_MAX;
    int second_smallest = INT_MAX;

    for (int num : arr) {
        if (num < first_smallest) {
            second_smallest = first_smallest;
            first_smallest = num;
        } else if (num < second_smallest && num > first_smallest) {
            second_smallest = num;
        }
    }

    return (second_smallest == INT_MIN) ? -1 : second_smallest; // return -1 if no second largest
}

int main() {
    vector<int> arr = {10, 5, 20, 8};
    int result = findSecondSmallest(arr);
    cout << "Second smallest element: " << result << endl;
}