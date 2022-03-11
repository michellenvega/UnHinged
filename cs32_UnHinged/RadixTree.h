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
        root = new Node(nullptr);
    }
    ~RadixTree(){
        delete root;
    }
 void insert(std::string key, const ValueType& value);
    
    ValueType* search(std::string key) const;
    
private:

    class Node {
    public:
        Node(ValueType* val_p)
        {
            n_key = "";
            n_val = val_p;
            counter = 0;
            end_of_word = true;
        }
        
        ~Node(){    //  Double check this
            for (auto n : prefix)
                delete n;
            delete n_val;
        }
        
        bool addNode(Node * n, ValueType m_value) {
        for (int i = 0; i < counter; i++) {
                      if (prefix[i] == n)
                       return false;
           }
              prefix[counter] = n;
                   prefix[counter]->setValueNode(m_value);
                 counter++;
                   return true;
              }
        
        
        void setKeyNode(string key) {
            n_key = key;}
        
        void setValueNode(ValueType val) {
            if(n_val == NULL)
                n_val = new ValueType(val);
            else
            *n_val = val;}
        
        int getNum() {
            return counter;}
        
        ValueType getValue() {
            return *n_val;}
        
        void setEndofWord(bool end) {
            end_of_word = end;}
        
        ValueType getValatPos(int n) {
            return prefix[n]->getValue();}
        
private:
        vector<ValueType> suffix;
        Node * prefix [26];  //  prefix
        bool end_of_word = false;  // is it a leaf
        ValueType* n_val;
        string n_key;
        int counter;
        };
    
    
    
    Node* root;
    
};


template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType& value){
   
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    //  Special Cases to look at:
    //  1. The tree is empty => we add the node as the root
    //  2.Both prefix and given word match perfectly.
    //  3. The prefix and given word have a match in a PART of the prefix.
    //  4. The prefix matches a first part of the word, but there is extra letters.
    //      => leftover in the prefix
    //      => leftover in the given word
    // // // // // //  //  //  //  //  //  //  //  //  //  //  //  //   //  //  //  //
    
    //------------------------------------------------------------------------------//
    
    //  Case 1: The tree is empty => we add the node as the root
    
    if(root->getNum() == 0){ //  Has no nodes, aka is EMPTY
        Node * n_root = new Node(nullptr); //  We make new pointer at a new Node.
        n_root->setKeyNode(key);  //  We store the given value
        root->addNode(n_root, value);   //  Add new Node;
        root->setEndofWord(false);  //  No longer end of word aka leaf
        return;
    }
    
    //------------------------------------------------------------------------------//
    
    //  Case 2: Prefix and key are the exact same!
      
    if(root->getNum() != 0){
        
    }
    
    
    
    
    //------------------------------------------------------------------------------//

    //  Case 4: The prefix matches a first part of the word, but there is extra letters.
    int letterCount = 0; // Will help determine subcase.
    
    for( int j = 0; j < key.size(); j++){
        int let = key[j] - 'a';
        
        letterCount++;
    }
    
    
        //  Subcase A:  leftover in the prefix
    
        //  Subcase B:  leftover in the given word
    
    //------------------------------------------------------------------------------//

}




#endif /* RadixTree_h */
