#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 1, 1, 12, 2};
    set<int> unique_elements;

    // Insert all elements into the set (automatically removes duplicates)
    for (int i = 0; i < arr.size(); i++) {
        unique_elements.insert(arr[i]);
    }

    // Copy unique elements back to a vector if needed
    vector<int> result(unique_elements.begin(), unique_elements.end());

    cout << "Array after removing duplicates: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
