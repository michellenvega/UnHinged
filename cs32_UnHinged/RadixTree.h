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
#include <map>
using namespace std;

template <typename ValueType>
class RadixTree {
public:
    RadixTree(){
        
    }
    /*
    RadixTree(){
        root = new Node();
    }
    ~RadixTree(){
        delete root;
    }*/
 void insert(std::string key, const ValueType& value);
    
    ValueType* search(std::string key) const{
        typename map<string, ValueType*> :: const_iterator it;

        it = m_map.find(key);

        if (it == m_map.end()) {
            return nullptr;
        }

        else {
            return it->second;
        }
    }
   
    
private:
    map<string,ValueType*> m_map;
    
    
    /*
    class Node {
    public:
        Node()
         {
             n_key = "$";
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
                        }
            
         }

        Node(std::string k, ValueType v)
         {
            if(n_key[n_key.size()] != '$')
                n_key = k +'$';
            else
                n_key = k;
            n_val = v;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
                
                        }
            
        }
        ~Node(){
            for (auto n : children)
                delete n;
        }
private:
     vector<ValueType> suffix;
     std::string n_key;
     ValueType n_val;
     int count;
     Node * preFix [26];  //  prefix
     bool end_of_word = false;  // is_leaf
        };
    
    Node* root;
     */
    
    
    
};
template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType& value){
    ValueType* tval = new ValueType(value);
    m_map.insert(pair<string,ValueType*>(key,tval));
}

/*
template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType& value){

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
            if(current->children[pos] != NULL){
                
                
                // if not at end of word, but we have matching consecutive letters, add to count
                if(!current->end_of_word && current->children[pos]->n_key[count] == key[count]) {
                    count++;
                    // if we reached the end n_key or given key, set bool to true
                    
                    // need to change how I will get leftover
                    // right it works if: adding bigger word to smaller word
                    // ^ ex: we have 'slow' but want to add slower
                    if(alphaCount(key) > alphaCount(current->children[pos]->n_key))
                        leftover = key.substr(count, alphaCount(key));
                    else{
                        // we need: we have 'slower' but want to add 'slow'
                        
                        leftover = (current->children[pos]->n_key).substr(count, alphaCount(current->children[pos]->n_key));
                        longerKey = true; // we say that we need the operations reversed for this!
                    }
                }
                
                if((count == alphaCount(current->children[pos]->n_key))||
                   count  == alphaCount(key) || current->children[pos]->n_key[count] != key[count])
                    current->end_of_word = true;
                
            }
            
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
                }
                else{
                    newstr = leftover;   // current key
                    tempstr = current->n_key;  // the extra, ex: 'er'
                    if( current->n_key[ current->n_key.size()] != '$')
                        current->n_key = tempstr.substr(0, tempstr.size()-newstr.size()) + '$';
                    else
                        current->n_key = tempstr.substr(0, tempstr.size()-newstr.size());
                    
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
        } // end of else
        
        
        
        // if we are at the end of the word, move into the tree
        if(current->end_of_word){
            current = current->children[pos];
            
        } else
            i--;
    }
    
    // set this just for formality, will change later!
    current->end_of_word = true;
    
     
    
}


*/
/*

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

*/


#endif /* RadixTree_h */
