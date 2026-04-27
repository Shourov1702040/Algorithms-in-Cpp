#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
    int n;
    cout << "Enter number of unique characters: ";
    cin >> n;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    for (int i = 0; i < n; i++) {
        string ch;
        int freq;
        cout << "Enter character and its frequency: ";
        cin >> ch >> freq;
        pq.push({freq, ch});
    }

    cout << "Nodes merged in Huffman process (Simulated):" << endl;
    while (pq.size() > 1) {
        pair<int, string> left = pq.top(); pq.pop();
        pair<int, string> right = pq.top(); pq.pop();

        int combined_freq = left.first + right.first;
        string combined_name = "(" + left.second + "+" + right.second + ")";
        
        pq.push({combined_freq, combined_name});
        cout << "Merged " << left.second << " and " << right.second << " with total freq: " << combined_freq << endl;
    }

    cout << "Final Root Structure: " << pq.top().second << endl;

    return 0;
}
