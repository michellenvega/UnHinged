//
//  RadixTree.h
//  cs32_UnHinged
//
//  Created by Michelle Navarrete on 3/2/22.
//

#ifndef RadixTree_h
#define RadixTree_h


#include <string>
#include <vector>
using namespace std;

template <typename ValueType>
class RadixTree {
public:
    RadixTree(){
        root = new Node();
    }
    ~RadixTree(){
        delete root;
    }
 void insert(std::string key, const ValueType& value);
 ValueType* search(std::string key) const;
    
private:
    class Node {
    public:
        // info
        std::string n_key;
        ValueType n_val;
        // vector of children
        Node * children [26];
        Node * parent;
        bool end_of_word = false;
        Node()
         {
             n_key = "$";
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
                        }
            
         }

        Node(std::string k, ValueType v)
         {
            n_key = k +'$';
            n_val = v;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
                
                        }
            
        }
        ~Node(){
            for (auto n : children)
                delete n;
        }

        };
    
    Node* root;
};




/*
 for insert:
 
 depends on length of key!!1 thats time complexity
 so:
 - based on str.length() in a loop
 - once we hit a '$', go into node of pos of the next str letter
 - if it does not match, we will change nodes to include it (tricky)
 - if it does match, keep going until we find a non-match
 
 */









template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType& value){
    
     // we have a simple trie tree rght now
     // now we just need to GROUP words!!!
    int count = 0;
    string leftover;
    bool longerKey = false;
     Node * current = root;
    current->end_of_word = false;
             for (int i = 0; i < key.size(); i++) {
                 // find first letter of given key
                 int pos = key.at(i)-'a';
                 // if at letter, no other word, then add node
                 if (current->children[pos] == NULL && count == 0) {
                     current->children[pos] = new Node(key, value); // make new node
                     current->children[pos]->parent = current; // ???
                     return;
                 }
                 else{
                     // if at letter, no rest of word, then SPLIT!
                     // might change this into a function later to make it easier
                     if (current->children[pos] == NULL && count > 0) {
                         // which ever one is the smallest???
                         // we then split it?
                         // if leftover == 0 then...
                         string newstr, tempstr;
                         if(longerKey == false){
                          newstr = leftover;  // the extra, ex: 'er'
                          tempstr = current->n_key;   // current key
                         current->n_key = tempstr;
                         }
                         else{
                              newstr = leftover;   // current key
                              tempstr = current->n_key;  // the extra, ex: 'er'
                             current->n_key = tempstr.substr(0, tempstr.size()-newstr.size()) + '$';
                         }
                         Node * tempOne = current; // current key
                         Node * temp = current->parent;// the parent
                         
                         current = tempOne;
                    if(current != root)
                         current->parent = temp->parent; // curr's parent is its old parents' parent
                         
                         pos = newstr[0] - 'a'; // find position
                         current->children[pos] = new Node(newstr.substr(0, newstr.size()), value); // add new node in children
                         
                         tempOne->parent=NULL;
                         tempOne = NULL;
                        return;
                     }
                     // if we reached the end n_key or given key, set bool to true
                     if((count ==current->children[pos]->n_key.size() )|| count  == key.size())
                         current->end_of_word = true;
                     
                     // if not at end of word, but we have matching consecutive letters, add to count
                     if(!current->end_of_word && current->children[pos]->n_key[i] == key[i]) {
                         count++;
                         
                         
                         // need to change how I will get leftover
                         // right it works if: adding bigger word to smaller word
                         // ^ ex: we have 'slow' but want to add slower
                         // we need: we have 'slower' but want to add 'slow'
                         // need to put in good use the $
                         if(key.size() >= current->children[pos]->n_key.size())
                             leftover = key.substr(count-1, key.size());
                         else{
                            leftover = (current->children[pos]->n_key).substr(count, (current->children[pos]->n_key).size());
                             longerKey = true; // we say that we need the operations reversed for this!
                         }
                     }

                     
                     
                 }
                 
                 // if we are at the end of the word, move into the tree
                 if(current->end_of_word){
                 current = current->children[pos];
                     
                 }else i--;
             }
    
    // set this just for formality, will change later!
             current->end_of_word = true;
     
     
    
}

template <typename ValueType>
ValueType* RadixTree<ValueType>::search(std::string key) const{
    
    
    Node * current = root;
    for (size_t i = 0; i < key.size(); i++) {
     if (current->children[key.at(i)-'a']) {
         current = current->children[key.at(i)-'a'];
      } else {
         current = NULL;
         break;
      }
 }
    ValueType* value = &  (current->n_val);
    return value;
 
}








#endif /* RadixTree_h */
