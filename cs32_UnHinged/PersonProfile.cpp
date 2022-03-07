//
//  PersonProfile.cpp
//  cs32_UnHinged
//
//  Created by Michelle Navarrete on 3/2/22.
//

#include "PersonProfile.h"

// constructor
PersonProfile::PersonProfile(string name, string email)
        : m_name(name), m_email(email){};


// destructor
PersonProfile::~PersonProfile(){
    
    
    
    //  //  //  //  //  //  //  //
    //  NEED TO DO THIS!
    //  //  //  //  //  //  //  //
    
    
    
}

//  Get Name
string PersonProfile::GetName() const{
    return m_name;
}

//  Get Email
string PersonProfile::GetEmail() const{
    return m_email;
}

//  Add a Pair
void PersonProfile::AddAttValPair(const AttValPair& attval){
    
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    // We need to check whether the attval's attribute is already
    // in the radix tree. If it is, then we must check if the values
    // differ. If they do, add attval to the radixtree. If they do
    // not, do nothing and return.
    // // // // // //  //  //  //  //  //  //  //  //  //  //  //  //
    
    // ------------------------------------------------------------//
    
    // check if attval is already in RadixTree
    vector<string>* p_value = p_tree.search(attval.attribute);
    
    // ------------------------------------------------------------//
    
    // If it IS in the Radix Tree, we check whether we have duplicate values.
    if(p_value != NULL){
        //  Now, we have to check the vector of strings for a duplicate.
            vector<string>::iterator it = p_value->begin(); //   Use iterator
            for( ;   it!=p_value->end()    ;   it++ ){
                if(*it == attval.value)   return;   // They equal!
                
            }
        
        //  If they do not equal, we add the value to the RadixTree!
        p_value->push_back(attval.value);   //  Put in vector
        p_tree.insert(attval.attribute, (*p_value) );
        attributes.push_back(attval.attribute);
        
    }
    
    // ------------------------------------------------------------//
    
    //  Not present, thus, we add it to the RadixTree and update our vectors.
    else if(p_value == NULL){   //  create new attribute if not present
        vector<string> temp_v;  // create a vector for the values
        temp_v.push_back(attval.value); // add the value to the vector.
        attributes.push_back(attval.attribute); //  add to vector of attr
        p_tree.insert(attval.attribute, temp_v); } // add to the radixTree
    
}

//  Returns the total number of distinct attribute-value pairs associated with this member.
int PersonProfile::GetNumAttValPairs() const{
    
    
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    // needs to be of DISTINCT attributes
    // // // // // //  //  //  //  //  //  //  //  //  //  //  //  //
    
    
    
    // needs to be of DISTINCT attributes
    
    int size = static_cast<int>(attributes.size());   // get size of vector
    return size;    // return number of att-value pairs
}


//  This method gets the attribute-value pair specified by attribute_num.
bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const{
    
    
    
    
    
    
    
    return true;
}
