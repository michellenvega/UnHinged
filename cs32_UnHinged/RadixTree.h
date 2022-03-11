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
        
        bool addNode(Node * n, string key, ValueType m_value) {
        for (int i = 0; i < counter; i++) {
                      if (prefix[i] == n)
                       return false;
           }
            int pos = key[0] - 'a';
            prefix[pos] = n;
           prefix[pos]->setKeyNode(key);
            prefix[pos]->setValueNode(m_value);
                 counter++;
            n->setEndofWord(false);
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
        
        string getKey() {
            return n_key;}
        
        bool getLeaf() {
            return end_of_word;}
        
        ValueType getValue() {
            return *n_val;}
        
        void setEndofWord(bool end) {
            end_of_word = end;}
        
        ValueType getValatPos(int n) {
            return prefix[n]->getValue();}
        
        void splitNodes (Node* t, string key, ValueType val,int share){
            int leftover = 0; //   How many letters are extra
            bool given = false; //  Given key is too long => true
            
            //  Find how much leftover and which one
            if(key.size() > t->getKey().size()){
                given = true;
                leftover = key.size()  - t->getKey().size();
            } else {
                leftover = t->getKey().size() - key.size();
            }
            
            //  Now we add new nodes
            Node * given_Node = new Node(&val);
           t->addNode(given_Node, key.substr(share, key.size()), val);
            //-------------------------------------------------
            string n_key = t->getKey();
            ValueType new_val =  ( t->getValue() );
            Node * orig_Node = new Node(&new_val);
            t->addNode(orig_Node, n_key.substr(share, n_key.size()) , orig_Node->getValue());
            
            
            //  Set n's value to nothing!!
            
            t->setKeyNode(t->getKey().substr(0, share));
          //  t->setValueNode(nullptr);
        }
        
        vector<ValueType> suffix;
        Node * prefix [26];  //  prefix
private:

        bool end_of_word = true;  // is it a leaf
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
        root->setEndofWord(false);  //  No longer end of word aka leaf
        return;
    }
    
    //------------------------------------------------------------------------------//
    
      
    if(root->getNum() != 0){    //  If the tree is not empty,
        
        
        Node* temp = root;
        int count = 0;
        int pos = key[0] - 'a';
                
    //  Case 2: Prefix and key are the exact same!
                
                if(key == temp->prefix[pos]->getKey()){
                    temp = temp->prefix[pos];
                    temp->setValueNode(value);
                    return;
                }
                
    //------------------------------------------------------------------------------//

         
    //  Case 3: The prefix and given word have a match in a PART of the prefix, same length
                
                if(key.size() == temp->prefix[pos]->getKey().size()){
                    //  How many letters do they share?
                    temp->splitNodes(temp->prefix[pos], key, value, key.size());
                    cout << "here" << endl;
                    return;
                }
                
    //------------------------------------------------------------------------------//
                
    //  Case 4: The prefix matches a first part of the word, but there is extra letters.
                //      a   => leftover in the prefix
                //      b   => leftover in the given word
                else if(key.size() != temp->prefix[pos]->getKey().size()){
                    //  Find shared letters
                    int shared = 0; int size_t = 0;
                    //  Find size for loop
                    if(key.size() > temp->prefix[pos]->getKey().size())
                         size_t = temp->prefix[pos]->getKey().size();
                    else
                        size_t = key.size();
                        
                    for( int  j = 0; j < size_t; j++ ){         //  Let's iterate through the array.
                        if(key[j] !=  temp->prefix[pos]->getKey()[j])
                            return;
                        else
                            shared++;
                    }   //  <=  end of for-loop
                     
                  //    Now we split!
                    
                    temp->splitNodes(temp->prefix[pos], key, value, shared);
                    
                    
                    
                }   //  <= end of else if for different sizes
                
        

        
        
    }   //  <= end of if root Num != 0
    


    
    //------------------------------------------------------------------------------//

}




#endif /* RadixTree_h */
