class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> frequencies;
};

class AutoCompleteSystem {
private:
    TrieNode* root;
    TrieNode* current;
    string currentQuery;

    static bool compare(pair<string, int>& a, pair<string, int>& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }

public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        current = root;
        currentQuery = "";

        for (int i = 0; i < sentences.size(); ++i) {
            insert(sentences[i], times[i]);
        }
    }

    void insert(string sentence, int time) {
        TrieNode* node = root;
        for (char c : sentence) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->frequencies[sentence] += time;
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            insert(currentQuery, 1);
            currentQuery = "";
            current = root;
            return {};
        }

        currentQuery += c;
        if (!current->children[c]) {
            current->children[c] = new TrieNode();
            current = current->children[c];
            return {};
        }

        current = current->children[c];
        vector<pair<string, int>> suggestions(current->frequencies.begin(), current->frequencies.end());
        sort(suggestions.begin(), suggestions.end(), compare);

        vector<string> result;
        for (int i = 0; i < min(3, (int)suggestions.size()); ++i) {
            result.push_back(suggestions[i].first);
        }

        return result;
    }
}; 
/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
