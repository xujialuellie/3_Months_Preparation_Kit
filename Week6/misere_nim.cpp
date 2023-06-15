#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'misereNim' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY s as parameter.
 */

string misereNim(vector<int> s) {

    int n = s.size(), xr = 0;
    bool great = false;
    for(auto i :s){
        xr ^= i;
        if(i > 1) great = true;
    }
    if((xr == 0 && great == true) || (xr == 1 && great == false)) 
        return "Second";
    return "First";

    // The following code cannot pass some of the Test Cases:

    /*
    int n = s.size();
    int sum = 0;
    int min = 1000000000;
    for(int i = 0; i < n; i++) {
        sum = sum + s[i];
        if(s[i] < min) {
            min = s[i];
        }
    }
    if(sum == n) {
        if(n % 2 == 0) {
            return "First";
        } else {
            return "Second";
        }
    }
    if(min == 1) {
        if(sum % 2 == 0) {
            return "First";
        } else {
            return "Second";
        }
    }
    if(sum % 2 == 0) {
        return "Second";
    } else {
        return "First";
    }
    */

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string s_temp_temp;
        getline(cin, s_temp_temp);

        vector<string> s_temp = split(rtrim(s_temp_temp));

        vector<int> s(n);

        for (int i = 0; i < n; i++) {
            int s_item = stoi(s_temp[i]);

            s[i] = s_item;
        }

        string result = misereNim(s);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
