// Time Complexity: O(m + n) where m is the number of words in the dictionary and n is the number of words in the sentence
// Space Complexity: O(m) for the Trie structure
// Were you able to solve the problem on Leetcode?: Yes
// Did you face any challenges while solving the problem? No

class TrieNode {
public:
    std::vector<TrieNode*> children;
    bool isEnd;

    TrieNode():children(26, nullptr), isEnd(false) {

    }

    ~TrieNode() {
        for (TrieNode* child : children) {
            delete child;
        }
    }
        
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    };

    void insert(const string& word){
        TrieNode* curr = root;

        for (int i=0; i< word.size(); i++){
            int idx=word[i]-'a';

            if (!curr->children[idx]){
                curr->children[idx] = new TrieNode();
            }

            curr=curr->children[idx];
        }

        curr->isEnd = true;

    }

    string getRoot(const string& word){

        TrieNode* curr = root;
        string res = "";
        // Traverse through each character in the word
        // If the character's node does not exist or we reach the end of a word in the Trie, break
        
        
        for (int i=0; i< word.size(); i++){
            int idx=word[i]-'a';

            if (!curr->children[idx] || curr->isEnd){
                break;
            }
            
            curr=curr->children[idx];
            res+=word[i];
            cout<<res;
            
        }
        // If we reach the end of the word in the Trie, return the prefix found
        // If no prefix is found, return the original word

        return curr->isEnd ? res : word;

    }
};

class Solution {

public:
    
    string replaceWords(vector<string>& dictionary, string sentence) {

        Trie* dictTrie = new Trie();

        string newSentence;

        // Insert all dictionary words into the Trie
        for(const auto& d: dictionary){
            dictTrie->insert(d);
        }

        // Split the sentence into words and replace each word with its root from the Trie
        // If no root is found, keep the original word
        // Reconstruct the sentence with replaced words 
        stringstream ss(sentence);
        string word;
        string result = "";
        bool firstWord = true;

        while (ss >> word) {
            if (!firstWord) {
                result += " ";
            }  // add space between words unless it's the first word
            result += dictTrie->getRoot(word);
            firstWord = false;
        }

        return result;

        
    }
};