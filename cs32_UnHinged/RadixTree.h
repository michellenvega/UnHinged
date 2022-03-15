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
    
    
};
template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType& value){
    ValueType* tval = new ValueType(value);
    m_map.insert(pair<string,ValueType*>(key,tval));
}



#endif /* RadixTree_h */
