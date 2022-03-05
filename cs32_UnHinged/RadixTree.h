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
    string leftover, tmp_nkey;
     Node * current = root;
    current->end_of_word = false;
             for (size_t i = 0; i < key.size(); i++) {
                 int pos = key.at(i)-'a';
                 if (current->children[pos] == NULL && count == 0) {
                     current->children[pos] = new Node();
                     current->children[pos]->parent = current;
                     current->children[pos]->n_key = key;
                     return;
                 }
                 else{

                     if (current->children[pos] == NULL && count > 0) {
                         
                         string newstr = leftover;
                         string tempstr = current->n_key;
                         current->n_key = tempstr;
                         // need to switch places here
                         Node * tempOne = current; // 'er'
                         Node * temp = current->parent;//'slow'
                         current = tempOne;
                         current->parent = temp->parent;
                         pos = newstr[0] - 'a';
                         current->children[pos] = new Node(newstr, value);
                         temp->n_key = tempstr;
                         tempOne->parent=NULL;
                         tempOne = NULL;
                        return;
                     }
                     if((count ==current->children[pos]->n_key.size() )|| count  == key.size() )
                         current->end_of_word = true;
 if(!current->end_of_word && current->children[pos]->n_key[0] == key[0]) {
                         // found that letter so we keep going!!
                         count++;
                         leftover = key.substr(count, key.size());
                        if(current != root)
                            tmp_nkey = current->n_key.substr(0, count);
                        
                     }
                     
                     
                     // here is not equal!!
                     
                     // make a split function, split it
                     
                     // then return;
                     
                     
                     
                     
                     
                     
                 }
                 if(current->end_of_word){
                 current = current->children[pos];
                     
                 } else i--;
             }
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
