#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int palindromeIndex(string s) {


    int n = s.size();
    int i = 0, j = n - 1;
    int stored_i = i, stored_j = j;
    bool flag = false;
    if (n >= 3) {
        while (i <= j) {
            if (s[i] != s[j]) {
                if (flag) return stored_j;
                flag = true;
                stored_i = i;
                stored_j = j;
                i++;
            } else {
                i++;
                j--;
            }
        }
    }
    return flag ? stored_i : -1;

    // The following code cannot pass Test Case 11 & 14

    /*
    int i = 0;
    int j = s.length() - 1;
    while(i < j) {
        if(s[i] != s[j]) {
            if(s[i + 1] == s[j]) {
                return i;
            }
            else if(s[i] == s[j - 1]) {
                return j;
            }
        }
        i++;
        j--;
    }
    return -1;
    */
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
