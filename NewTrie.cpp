#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *array[26];
    bool flage = false;
    int cnt = 0;
    bool contains(char ch){
        return array[ch-'a'] != NULL;
    }
    void put(char ch, Node *node){
        array[ch -'a'] = node;
    }
    Node *getNext(char ch){
        return array[ch-'a'];
    }
    void set(){
        flage = true;
    }
    bool End(){
        return flage;
    }
    
};
//SDE rules 
class Trie{
    private:
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void Insert(string &word){
        //later
        Node *node = root;
        for(char ch : word){ 
            if(!node->contains(ch)){ // 'a'
                
                node->put(ch, new Node());
                
            }
            node->cnt++;
            node = node->getNext(ch);
            
        }
        node->set();
    }
    
    int Search(string &word){
        //later
        Node *node = root;
        int count = 0;
        for(char ch : word){
            if(!node->contains(ch)){
                return count;
            }
            node = node->getNext(ch);
            count+=node->cnt;
        }
        return count;
    }
};

int main(){
    
    vector<string>words = {"abc","aaabcd", "edfe"};
    Trie trie;
    for(string word : words){
        trie.Insert(word);
    }
    string word = "ab";
    int ans = trie.Search(word);
    cout << ans << "\n";
    
    
}
