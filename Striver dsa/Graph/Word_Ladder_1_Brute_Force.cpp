#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
int Word_Ladder_1_Brute_Force(string beginword,string endword,vector<string>&wordList){
    unordered_set<string>st(wordList.begin(),wordList.end());  //Play role of visited Array...
    queue<pair<string,int>>q;
    q.push({beginword,1});
    st.erase(beginword);
    
    while(!q.empty()){
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(word==endword) return steps;
        //Now change every character and check in the wordlist:
        for(int i=0;i<word.size();i++){
            char ori=word[i];
            for(int letter='a';letter<='z';letter++){
                word[i]=letter;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=ori;
        }
    }
    return 0;
}
int main(){
    vector<string> wordList = {"hit", "hot", "dot", "dog", "cog"};
    string beginWord = "hit";
    string endWord = "cog";
    int ans = Word_Ladder_1_Brute_Force(beginWord, endWord, wordList);
    cout << ans << endl;
}