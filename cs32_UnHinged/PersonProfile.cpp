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
 
    
    vector<string>* val = p_tree.search(attval.attribute);
    
    //  create new attribute if not present
    
    
    //  check if there is a duplicate
    
    
    //  if there is, check if the values are the same
            //  if they are, do nothing
            //  if they arent, add the pair!
    
    
    
    
}

//  Returns the total number of distinct attribute-value pairs associated with this member.
int PersonProfile::GetNumAttValPairs() const{
    // needs to be of DISTINCT attributes
    
    int size = static_cast<int>(attributes.size());   // get size of vector
    return size;    // return number of att-value pairs
}


//  This method gets the attribute-value pair specified by attribute_num.
bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const{
    
    
    return true;
}
