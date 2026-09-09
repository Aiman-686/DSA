class Solution {
public: 
    class TrieNode {
        public:
        TrieNode* children[26];
        vector<string> suggestions;
        TrieNode(){
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root = new TrieNode();
    void insert(string& word){
        TrieNode* node = root;
        for(char c : word){
            int index = c - 'a';
            //create path if it doesn't exist
            if(node->children[index] == nullptr){
                node->children[index] = new TrieNode();
            }
            //move to that character
            node = node->children[index];

            //keep only 3 smallest products
            if(node->suggestions.size() < 3){
                node->suggestions.push_back(word);
            }
        }
    }
    vector<vector<string>> suggestedProducts(
        vector<string>& 
        products, 
        string searchWord) {
          //Important: smallest product first
          sort(products.begin(), products.end());
          //build trie
          for(string& product : products){
            insert(product);
          }
          vector<vector<string>> answer;
          TrieNode* node = root;
          //walk through searchWord
          for(char c : searchWord){
            int index = c - 'a';
            //prefix doesn't exist
            if(node->children[index] == nullptr){
                //current and all future prefixes have no matches
                while(answer.size() < searchWord.size()){
                    answer.push_back({});
                }
                break;
            }
            //move to current prefix
            node = node->children[index];
            //get top 3 suggestions
            answer.push_back(node->suggestions);
          }return answer;
        
    }
};