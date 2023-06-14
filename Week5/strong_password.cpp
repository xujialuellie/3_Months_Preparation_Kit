#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

// Return the minimum number of characters to make the password strong
int minimumNumber(int n, string password) {
    int count = 0;
    bool digit = false, lower = false, upper = false, special = false;
    for(int i = 0; i < n; i++) {
        if(isdigit(password[i])) digit = true;
        else if(islower(password[i])) lower = true;
        else if(isupper(password[i])) upper = true;
        else special = true;
    }
    if(!digit) count++;
    if(!lower) count++;
    if(!upper) count++;
    if(!special) count++;
    if(n + count < 6) count += 6 - (n + count);
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
