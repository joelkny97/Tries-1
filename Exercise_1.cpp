// Time Complexity: O(n) where n is the number of characters in the word
// Space Complexity: O(n) for the Trie structure
// Were you able to solve the problem on Leetcode?: Yes
// Did you face any challenges while solving the problem? No

class TrieNode{

public:
    std::vector<TrieNode*> children;
    bool isEnd;

    TrieNode():children(26, nullptr), isEnd(false) {
        
    }

    ~TrieNode() {
        for (TrieNode* child : children) {
            if (child) {
                delete child;  // deletes all children
            }
        }
    }

};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    ~Trie() {  // Destructor for Trie
        delete root;  
    }
    
    void insert(string word) {

        TrieNode* curr = this->root;
        // Traverse through each character in the word
        // and insert it into the Trie
        // If the character's node does not exist, create it
        // At the end of the word, mark the node as an end of a word

        if (curr == nullptr) return;  // Edge case for empty Trie

        for (int i=0; i< word.size(); i++){

            int idx=word[i]-'a';

            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }

        curr->isEnd = true;
        
    }
    
    bool search(string word) {

        TrieNode* curr = this->root;
        // Traverse through each character in the word
        // If the character's node does not exist, return false
        // If we reach the end of the word and the current node is marked as an end of a word, return true
        // Otherwise, return false

        if (curr == nullptr) return false;  // Edge case for empty Trie
        for (int i=0; i< word.size(); i++){

            int idx=word[i]-'a';

            if(curr->children[idx] == nullptr){
                return false;
            }
            curr = curr->children[idx];

        }
        return curr->isEnd;
            
        

        
    }
    
    bool startsWith(string prefix) {

        TrieNode* curr = this->root;
        
        if (curr == nullptr) return false;  // Edge case for empty Trie
        // Traverse through each character in the prefix
        // If the character's node does not exist, return false
        // If we reach the end of the prefix, return true
        for (int i=0; i< prefix.size(); i++){

            int idx=prefix[i]-'a';

            if(curr->children[idx] == nullptr){
                return false;
            }
            curr = curr->children[idx];

        }
        
        return true;
        
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */