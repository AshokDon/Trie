#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
using namespace std;
const int mod = (int)1e9 + 7;


void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
struct Trie{
	Trie *arr[52];
	bool flage = false;
	bool Contains(char ch){
		if(ch >= 97 and ch <= 122){
			return arr[ch-'a'+26]!=NULL;
		}
		else return arr[ch-'A']!=NULL;
	}
	void Put(char ch, Trie *node){
		if(ch >= 97 and ch <= 122){
			arr[ch-'a'+26]=node;
		}
		else arr[ch-'A']=node;
	}
	Trie *GetNext(char ch){
		if(ch >= 97 and ch <= 122){
			return arr[ch-'a'+26];
		}
		else return arr[ch-'A'];
	}
	void Set(){
		flage = true;
	}
	bool End(){
		return flage;
	}

};
Trie *root = new Trie();
void Insert(string word){
	Trie *temp = root;
	for(int i = 0 ; i < word.size() ; i++){
		if(!temp->Contains(word[i])){
			temp->Put(word[i],new Trie());
		}
		temp = temp->GetNext(word[i]);
	}
	temp->Set();
}
int main() {
    
    fast_io;
    TakeInput();
    int n;
    cin >> n;
    vector<string>dictionary;
    for(int i = 0 ; i < n ; i++){
    	string s;
    	cin >> s;
    	dictionary.pb(s);
    }
    int r,c;
    cin >> r >> c;
    char board[r][c];
    for(int i = 0 ; i < r ; i++){
    	for(int j = 0 ; j < c ; j++){
    		char c;
    		cin >> c;
    		board[i][j]=c;
    	}
    }
    for(int i = 0 ; i < n ; i++){
    	Insert(dictionary[i]);
    }
 

    return 0;
}
