#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
double getMedian(int d, vector<int> countArray) {
    double median = 0.0;
    int count = 0;

    if (d % 2 == 0) {
        int m1 = -1;
        int m2 = -1;
        for (int j = 0; j < countArray.size(); j++) {
            count += countArray[j];
            if (m1 == -1 && count >= d / 2) {
                m1 = j;
            }
            if (m2 == -1 && count >= (d / 2) + 1) {
                m2 = j;
                break;
            }
        }   
        median = (m1 + m2)/2.0; 
    } else {
        for (int j = 0; j < countArray.size(); j++) {
            count += countArray[j];
            if (count > d / 2) {
                median = j;
                break;
            }
        } 
    }

    return median;
}

int activityNotifications(vector<int> expenditure, int d) {
    int count = 0;

    vector<int> countArray(201);
    for (int i = 0; i < d; i++) { countArray[expenditure[i]]++; }

    for (int i = d; i < expenditure.size(); i++) {
        double median = getMedian(d, countArray);

        if (expenditure[i] >= 2*median) {
            count++;
        }

        countArray[expenditure[i]]++;
        countArray[expenditure[i - d]]--;
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
            return x == y and x == ' ';
            });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

