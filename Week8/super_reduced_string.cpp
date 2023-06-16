#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    int size = s.size();
    for(int i = 0; i < size - 1; i++){
        if(s[i] == s[i+1]){
            s.erase(i, 2);
            size -= 2;
            i -= 2;
        }
    }
    if (s.size() == 0) {
        return "Empty String";
    }
    return s;   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
