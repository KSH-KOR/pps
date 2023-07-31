/*
2129. Capitalize the Title
Easy
629
44
Companies
You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:

If the length of the word is 1 or 2 letters, change all letters to lowercase.
Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
Return the capitalized title.

 

Example 1:

Input: title = "capiTalIze tHe titLe"
Output: "Capitalize The Title"
Explanation:
Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.
*/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        vector<string> words;
        stringstream ss(title);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        for (string& word : words) {
            if (word.length() == 1 || word.length() == 2) {
                for (char& ch : word) {
                    ch = tolower(ch);
                }
            } else {
                word[0] = toupper(word[0]);
                for (int i = 1; i < word.length(); i++) {
                    word[i] = tolower(word[i]);
                }
            }
        }

        string capitalizedTitle;
        for (const string& word : words) {
            capitalizedTitle += word + " ";
        }
        capitalizedTitle.pop_back();
        return capitalizedTitle;
    }
};