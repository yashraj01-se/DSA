#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
vector<vector<string>> Find_sequence(string beginWord, string endWord, vector<string> &wordList)
{
    // Initial Configuration:
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});

    vector<string> UsedOnLevel;
    UsedOnLevel.push_back(beginWord);
    int level = 0;
    vector<vector<string>> ans;

    // Start The Algorithm:
    while (!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();

        // Deleting logic:
        if (vec.size() > level)
        {
            level++;
            for (auto it : UsedOnLevel)
            {
                st.erase(it);
            }
            UsedOnLevel.clear();
        }

        // Finding all the sequeue included in the wordList:
        string word = vec.back();
        if (word == endWord)
        {
            if (ans.size() == 0)
            {
                ans.push_back(vec);
            }
            else if (ans[0].size() == vec.size())
            {
                ans.push_back(vec);
            }
        }
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char le = 'a'; le <= 'z'; le++)
            {
                word[i] = le;
                if (st.count(word) > 0)
                {
                    vec.push_back(word);
                    q.push(vec);
                    UsedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}
int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> ans = Find_sequence(beginWord, endWord, wordList);

    for (auto it : ans)
    {
        cout << endl;
        for (auto i : it)
        {
            cout << i << " ";
        }
    }
}