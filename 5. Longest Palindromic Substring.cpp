#include <string>
#include <vector>

using namespace std;

class Solution {
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

int main(){
    return 0;
}