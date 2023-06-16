#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {

    if (s.size() == 1) {
        return "YES";
    }

    map<char, int> d;
    for (auto x : s) {
        if (d.count(x) == 0) {
            d[x] = 1;
        } else {
            d[x]++;
        }
    }

    vector<int> arr;
    for (auto x : d) {
        arr.push_back(x.second);
    }
    sort(arr.begin(), arr.end());

    int n = arr.size();

    if (arr[n-2] + 1 == arr[n-1] && arr[0] == arr[n-2]) {
        return "YES";
    }
    if (arr[0] == arr[n-1]) {
        return "YES";
    }
    if (arr[0] == 1 && arr[1] == arr[n-1]) {
        return "YES";
    }

    return "NO";

    // The following code cannot pass Test Case 4, 6, 7, 13, 16, 19

    /*
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    int max_freq = 0;
    int min_freq = INT_MAX;
    int max_freq_count = 0;
    int min_freq_count = 0;
    
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
                max_freq_count = 1;
            } else if (freq[i] == max_freq) {
                max_freq_count++;
            }
            if (freq[i] < min_freq) {
                min_freq = freq[i];
                min_freq_count = 1;
            } else if (freq[i] == min_freq) {
                min_freq_count++;
            }
        }
    }
    if (max_freq == min_freq) {
        return "YES";
    }
    if (max_freq - min_freq == 1 && max_freq_count == 1) {
        return "YES";
    }
    if (min_freq == 1 && min_freq_count == 1 && max_freq_count == 1) {
        return "YES";
    }
    return "NO";
    */

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
