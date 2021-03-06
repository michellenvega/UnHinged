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
    
    //-------------------------------------------------------------//
    
    const string att = attval.attribute;
    // check if attval is already in RadixTree
    set<string>* p_value = p_tree.search(att);
    
    //-------------------------------------------------------------//

    // If it IS in the Radix Tree, we check whether we have duplicate values.
    if(p_value != NULL){
        //  Now, we have to check the vector of strings for a duplicate.
            set<string>::iterator it = p_value->begin(); //   Use iterator
            for( ;   it!=p_value->end()    ;   it++ ){
                if(*it == attval.value)   return;   // They equal!
                
            }
        
        //  If they do not equal, we add the value to the RadixTree!
        p_value->insert(attval.value);   //  Put in vector
        p_tree.insert(attval.attribute, (*p_value) );
        attributes.push_back(attval);
        
    }
    
    //-------------------------------------------------------------//

    //  Not present, thus, we add it to the RadixTree and update our set.
    else if(p_value == NULL){   //  create new attribute if not present
        set<string> temp_v;  // create a set for the values
        temp_v.insert(attval.value); // add the value to the set.
        attributes.push_back(attval); //  add to set of attr
        p_tree.insert(attval.attribute, temp_v); } // add to the radixTree
    
}


int PersonProfile::GetNumAttValPairs() const{
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    //  Returns the total number of distinct attribute-value pairs
    //  associated with this member.
    // // // // // //  //  //  //  //  //  //  //  //  //  //  //  //
    
    //-------------------------------------------------------------//

    int size = static_cast<int>(attributes.size());   // get size of vector
    return size;    // return number of att-value pairs
}


//  This method gets the attribute-value pair specified by attribute_num.
bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const{
    
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    //  This method gets the attribute-value pair specified by attribute_num.
    //  The method returns true if it successfully retrieves an attribute;
    //  otherwise, it returns false and leaves attval unchanged.
    // // // // // //  //  //  //  //  //  //  //  //  //  //  //  //
    
    //-------------------------------------------------------------//
    if (attributes.empty()) {
        return false;   //  Did not find it, so we return false.
    }
    //-------------------------------------------------------------//
    if (attribute_num < 0 || attribute_num >= attributes.size()) {
        return false;
    }
    //-------------------------------------------------------------//
    attval = attributes[attribute_num];
    return true;
}

