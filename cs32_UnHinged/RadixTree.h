#ifndef RadixTree_h
#define RadixTree_h
#include <string>
#include <vector>
#include <map>
#include <iostream>
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
        Node(ValueType* val_p):counter(0)
        {
            n_val = val_p;
        }
        
        ~Node(){    //  Double check this

        }
        
        bool addNode(Node * n, string key, ValueType m_value) {
            for (int i = 0; i < 26; i++) {
                if (prefix[i] == n)
                    return false;
            }
            int pos = key[0] - 'a';
            if(n!=nullptr){
            prefix[pos] = n;
            prefix[pos]->setKeyNode(key);
            prefix[pos]->setValueNode(m_value);
            counter++;
            }
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
        
        bool getLeaf() {
            return end_of_word;}
        
        ValueType* getValue() {
            if(n_val == NULL)
                return nullptr;
            return n_val;}
        
        void setEndofWord(bool end) {
            end_of_word = end;}
        
        ValueType getValatPos(int n) {
            return prefix[n]->getValue();}
        
        void splitNodes (Node* t, string key, ValueType val,int share){
            int leftover = 0; //   How many letters are extra
            bool given = false; //  Given key is too long => true
            
            //  Find how much leftover and which one
            if(key.size() > t->n_key.size()){
                given = true;
                leftover = key.size()  - t->n_key.size();
            } else {
                leftover = t->n_key.size() - key.size();
            }
            
            //  Now we add new nodes
            Node * given_Node = new Node(&val);
            given_Node->setEndofWord(true);

           t->addNode(given_Node, key.substr(share, key.size()), val);
            //-------------------------------------------------
            string n_key = t->n_key;
            ValueType new_val =  *( t->getValue() );
            Node * orig_Node = new Node(&new_val);
            orig_Node->setEndofWord(true);
            t->addNode(orig_Node, n_key.substr(share, n_key.size()) , *(orig_Node->getValue()) );

            
            
            //  Set n's key
            t->setKeyNode(t->n_key.substr(0, share));
            t->setEndofWord(false);
            delete t->getValue();
            //  Now, we decide the value
            
            ValueType* tem_v = orig_Node->getValue();
            if(n_key > key) {    //  If node's key is longer
                t->setValueNode(val);
            }
        }
        
        vector<ValueType> suffix;
        Node * prefix [26];  //  prefix
        string n_key = "$";
private:

        bool end_of_word = false;  // is it a leaf
        ValueType* n_val;
        int counter = 0;
        };

    Node* root;
    
};


template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType& value){
   
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    //  Special Cases to look at:
    //  1. The tree is empty => we add the node as the root
    //  2. Both prefix and given word match perfectly.
    //  3. The prefix and given word have a match in a PART of the prefix, same length
    //  4. The prefix matches a first part of the word, but there is extra letters.
    //      => leftover in the prefix
    //      => leftover in the given word
    // // // // // //  //  //  //  //  //  //  //  //  //  //  //  //   //  //  //  //
    
    //------------------------------------------------------------------------------//
    
    //  Case 1: The tree is empty => we add the node as the root
    int pos = key[0] - 'a';
    if(root->getNum() == 0 || root->prefix[pos] == nullptr){ //  Has no nodes, aka is EMPTY
        Node * n_root = new Node(nullptr); //  We make new pointer at a new Node.
        n_root->setKeyNode(key);  //  We store the given value
        root->addNode(n_root, key, value);   //  Add new Node;
        root->setEndofWord(true);
        return;
    }
    else if(root->prefix[pos]->getValue() == NULL){
        Node * n_root = new Node(nullptr); //  We make new pointer at a new Node.
        n_root->setKeyNode(key);  //  We store the given value
        root->addNode(n_root, key, value);   //  Add new Node;
        root->setEndofWord(true);
        return;
    }
    
    //------------------------------------------------------------------------------//
    
      
    if(root->getNum() != 0){    //  If the tree is not empty,
        
        
        Node* temp = root;
        int pos = key[0] - 'a';
                
    //  Case 2: Prefix and key are the exact same!
                
                if(key == temp->prefix[pos]->n_key){
                    temp = temp->prefix[pos];
                    temp->setValueNode(value);
                    return;
                }
                
    //------------------------------------------------------------------------------//

         
    //  Case 3: The prefix and given word have a match in a PART of the prefix, same length
            int shared = 0; int size_t = 0;
                if(key.size() == temp->prefix[pos]->n_key.size()){
                    //  How many letters do they share?
                    size_t = key.size();
                }
                
    //------------------------------------------------------------------------------//
                
    //  Case 4: The prefix matches a first part of the word, but there is extra letters.
                //      a   => leftover in the prefix
                //      b   => leftover in the given word
                else if(key.size() != temp->prefix[pos]->n_key.size()){
                    //  Find shared letters
                
                    //  Find size for loop
                    if(key.size() > temp->prefix[pos]->n_key.size())
                         size_t = temp->prefix[pos]->n_key.size();
                    else
                        size_t = key.size();
                }   //  <= end of else if for different sizes
        
        
        
                    for( int  j = 0; j < size_t; j++ ){         //  Let's iterate through the array.
                        if(key[j] !=  temp->prefix[pos]->n_key[j])
                            break;
                        else
                            shared++;
                    }   //  <=  end of for-loop
                     
        
    //------------------------------------------------------------------------------//
        
                  //    Now we split!
                    temp->splitNodes(temp->prefix[pos], key, value, shared);

    }   //  <= end of if root Num != 0
    
    
    //------------------------------------------------------------------------------//

}




#endif /* RadixTree_h */
