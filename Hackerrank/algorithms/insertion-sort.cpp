#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the insertionSort function below.

long merge(vector<int> &arr, vector<int> &temp, int left, int middle,
           int right) {
  int i, j, k;
  long count = 0;

  i = left;
  j = middle;
  k = left;
  while ((i <= middle - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];

      count = count + (middle - i);
    }
  }

  while (i <= middle - 1) {
    temp[k++] = arr[i++];
  }

  while (j <= right) {
    temp[k++] = arr[j++];
  }

  for (i = left; i <= right; i++) {
    arr[i] = temp[i];
  }

  return count;
}

long mergeSort(vector<int> &arr, vector<int> &temp, int left, int right) {
  int middle = 0;
  long count = 0;

  if (right > left) {
    middle = (right + left) / 2;

    count = mergeSort(arr, temp, left, middle);
    count += mergeSort(arr, temp, middle + 1, right);

    count += merge(arr, temp, left, middle + 1, right);
  }

  return count;
}

long mergeSortHelper(vector<int> &arr) {
  vector<int> temp(arr.size());
  return mergeSort(arr, temp, 0, arr.size() - 1);
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) { return mergeSortHelper(arr); }
long insertionSort(vector<int> arr) {
    return mergeSortHelper(arr);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = insertionSort(arr);

        fout << result << "\n";
    }

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

