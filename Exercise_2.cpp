class TrieNode {
public:
    std::vector<TrieNode*> children;
    string wordStored;

    TrieNode():children(26, nullptr) {

    }

    ~TrieNode() {
        for (TrieNode* child : children) {
            delete child;
        }
    }
        
};

class Solution {
public:
    TrieNode* root;
    string result;


    string longestWord(vector<string>& words) {

        root = new TrieNode();

        for(const auto & w : words){
            insert(w);
        }

        bfs(root);

        return result;
        
    }

    void bfs(TrieNode* root){
        queue<TrieNode*> q;
        TrieNode* curr = root;
        q.push(root);

        while(!q.empty()) {
            curr = q.front(); q.pop();

            for(int i = 25; i >= 0; --i) {
                if(curr->children[i] && curr->children[i]->wordStored != "") {
                    q.push(curr->children[i]);
                    
                }
            }

        }

        result = curr->wordStored;
        
    }

    void insert(const string& word){
        TrieNode* curr = root;

        for (int i=0; i< word.size(); i++){

            int idx=word[i]-'a';

            if (!curr->children[idx]){
                curr->children[idx] = new TrieNode();
            }
            
            curr=curr->children[idx];

        }
        curr->wordStored = word;


    }
};