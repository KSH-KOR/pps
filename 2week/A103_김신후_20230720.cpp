
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string list[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> bucket;
        for(string word : words){
            string t = "";
            for(char c : word){
                t += list[c-'a'];
            }
            bucket.insert(t);
        }
        return bucket.size();
    }
};