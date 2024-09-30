#include<bits/stdc++.h>
using namespace std;
class Node{
    private:
    //i need an array that can give acess to 26 charaters
    Node *array[26];
    bool flage; // i need a flage to check the word ends or not
    public:
    Node(){ // constructer 
        for(int i = 0 ; i < 26 ; i++){
            array[i] = nullptr; // all 26 to null
        }
        flage = false; // set initially flage as false
    }
    //used to check the charater is present or not
    bool constains(char ch){ 
        return array[ch-'a']!=nullptr; 
        //if not exist --> false;
        //if exist --> true;
    }
    //this will help you to place the charater
    void put(char ch, Node *node){
        array[ch-'a'] = node;
    }
    //it will help you to move to next 
    Node* getNext(char ch){
        return array[ch-'a'];
    }
    //if word ends make flage as true
    void set(){
        flage = true;
    }
    bool End(){
        return flage;
        
    }
    
};

class TrieDS{
    private:
    Node *root = new Node();
    
    public:
    //insert
    void Insert(string &word){
        Node *temp = root;
        for(char ch : word){
            if(!temp->constains(ch)){
                temp->put(ch,new Node());
            }
            temp = temp->getNext(ch);
        }
        temp->set();
    }
    //search
    bool Search(string &word){
        Node *temp = root;
        for(char ch : word){ // 
            if(!temp->constains(ch)){
                return false;
            }
            temp = temp->getNext(ch);
        }
        return temp->End();
    }
    
    
};

int main(){
    string s = "abcdabcdef";
    vector<string>words = {"abcd","xyz","abcdef","ab"};
    TrieDS trie;
    for(string word : words){
        trie.Insert(word);
    }
    string str = "abc";
    if(trie.Search(str)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
