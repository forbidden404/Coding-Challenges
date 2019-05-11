#include <bits/stdc++.h>

using namespace std;

// If we want to run this algorithm multiple times, we can preprocess the text and save each word
// frequency in a Hash Table, this will take O(n) to complete, but each query will be answered in O(1)
// Also we need to make sure we know wich delimiters exist and save the word as lowercase if it's not
// case sensitive
unordered_map<string, int> cache;
void precompute(string text) {
    int start = 0;
    int end = 0;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.') {
            if (start != end) {
                string data = text.substr(start, end - start);
                transform(data.begin(), data.end(), data.begin(), ::tolower);
                cache[data]++;
            } 
            start = i+1;
            end = i+1;
        } else {
            end++;
        }

        if (i == text.size() - 1) {
            string data = text.substr(start);
            transform(data.begin(), data.end(), data.begin(), ::tolower);
            cache[data]++;
        }
    }
}

int wordFrequencies(string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return cache[word];
}

int main() {
    // Read input
    string text;
    getline(cin, text);

    vector<string> queries;
    string input;
    while (cin >> input) {
        queries.push_back(input);
    }

    precompute(text);

    // Write output
    for (auto word: queries) {
        cout << word << ": " << wordFrequencies(word) << endl;
    }

    return 0;
}
