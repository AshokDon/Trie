#include<bits/stdc++.h>

using namespace std;


class Node{
    private:
    Node *array[26];
    bool flage;
    public:
    
    Node(){
        flage = false;
        for(int i = 0 ; i < 26 ; i++)array[i] = nullptr;
    }
    bool contains(char ch){
        return array[ch-'a']!=nullptr;
    }
    void put(char ch, Node *node){
        array[ch-'a'] = node;
    }
    Node *getNext(char ch){
        return array[ch-'a'];
    }
    void set(){
        flage = true;
    }
    bool IsEnd(){
        return flage;
    }
};
class Trie{
    private:
    Node *root = new Node();
    public:
    void Insert(string &word){
        Node *node = root;
        for(char ch : word){
            if(!node->contains(ch)){
                node->put(ch,new Node());
            }
            node = node->getNext(ch);
        }
        node->set();
        
    }
    
    bool Search(int start, int end ,string &word){
        Node *node = root;
        for(int i = start ; i < end ; i++){
            if(!node->contains(word[i])){
                return false;
            }
            node = node->getNext(word[i]);
        }
        return node->IsEnd();
    }
    
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(string &word : wordDict){
            trie.Insert(word);
        }
        int n = s.size();
        vector<bool>dp(n+1,false);
        dp[0] = true;
        for(int i = 1 ; i <= n ;i++){
            for(int j = 0 ; j < i ; j++){
                if(dp[j] == true){
                    if(trie.Search(j,i,s)){
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[n];
    }
    
};


int main(){
    string s = "leetcode";
    vector<string>wordDict={"leet","code"};
    Solution obj;
    cout << obj.wordBreak(s,wordDict);
    
}
