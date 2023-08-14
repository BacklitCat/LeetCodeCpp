//
// Created by TianQ on 2023/7/31.
//

#include "dictionary_tree.h"


int main() {
    cout << "dictionary_tree_test"<<endl;
    // Example usage
    vector<string> words = {"hello", "world", "foo", "bar","worl","foo"};
    for (int i = 0; i < words.size(); i++) {
        dt_insert(words[i]);
    }
    cout << dt_query("hello") << endl; // prints 0
    cout << dt_query("world") << endl; // prints 1
    cout << dt_query("worl") << endl; // prints 1
    cout << dt_query("foo") << endl; // prints 1
    cout << dt_query("baz") << endl; // prints -1
}