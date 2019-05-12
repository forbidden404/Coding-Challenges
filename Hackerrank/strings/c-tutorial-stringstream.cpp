#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	vector<int> arr;

    stringstream ss(str.c_str());
    int value;
    char ch;
    ss >> value;
    arr.push_back(value);
    while (ss.rdstate() != ios::eofbit) {
        ss >> ch >> value;
        arr.push_back(value);
    }

    return arr;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

