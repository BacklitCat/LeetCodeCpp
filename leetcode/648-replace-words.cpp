#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        stringstream res;

        // 将“字典”转化为set
        unordered_set<string> set;
        for (auto &word: dictionary) {
            set.emplace(word);
        }

        // 分割句子为小单词
        stringstream ss;
        ss << sentence;
        string word;
        bool insert_flag,first_flag=false;
        while (ss>>word) {
            insert_flag = false;
            // 小单词word，判断是否有前缀在set中
            for (int j = 0; j < word.size(); j++) {
                // 在
                if (set.count(word.substr(0, 1 + j))) {
                    if (first_flag){
                        res << " ";
                    }
                    res << word.substr(0, 1 + j);
                    insert_flag = true;
                    first_flag = true;
                    break;
                }
            }
            if (!insert_flag) {
                if (first_flag){
                    res << " ";
                }
                res << word;
                first_flag = true;
            }
        }
        return res.str();
    }
};


int main() {
    Solution solution;
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    cout << solution.replaceWords(dictionary, sentence);
    return 0;
}

