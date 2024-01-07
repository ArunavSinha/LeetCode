#include <string>
#include <vector>

using namespace std;

class Solution { // Gets a TLE (Time Limit Exceeded) for testcases with long strings
private: 
    bool check(string& s, int i, int j){
        while (i < j){
            if (s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        vector<string> substrings;
        for (int i = 0; i < s.length(); i++){
            string temp = "";
            for (int j = i; j < s.length(); j++){
                temp += s[j];
                substrings.push_back(temp);
            }
        }
        string result = substrings[0];
        int max = 0;
        for (int j = 0; j < substrings.size(); j++){
            int currentSize = substrings[j].size();
            if (check(substrings[j], 0, currentSize-1)){
                if (currentSize > max){
                    max = currentSize;
                    result = substrings[j];
                }
            }
        }
        return result;
    }
};

class Solution2 { // Optimal using Dynamic Programming
private:
    bool solve(vector<vector<bool>>& dp, int i, int j, string& s){
        if (i == j){
            return dp[i][j] = true;
        }
        else if (j-i == 1){
            if (s[i] == s[j]){
                return dp[i][j] = true;
            }
            else {
                return dp[i][j] = false;
            }
        }
        else if (s[i] == s[j] && dp[i+1][j-1] == true){
            return dp[i][j] = true;
        }
        else {
            return dp[i][j] = false;
        }
    }

public:
    string longestPalindrome(string s) {
        int n = s.length(), startIndex = 0, max = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int offset = 0; offset < n; offset++){
            for (int i = 0, j = offset; j < n; i++, j++){
                if (solve(dp, i, j, s) && offset+1 > max){
                    max = offset+1;
                    startIndex = i;
                }
            }
        }
        return s.substr(startIndex, max);
    }
};

int main(){
    return 0;
}