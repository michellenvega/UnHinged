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
    
//  can have same attribute, but must also have different value
    
    p_att.insert(attval.attribute, attval.value);    // insert the pair into the radix tree
    attributes[numOfPairs] = attval.attribute;
    numOfPairs++;
    
}

//  Returns the total number of distinct attribute-value pairs associated with this member.
int PersonProfile::GetNumAttValPairs() const{
    return numOfPairs;
}


//  This method gets the attribute-value pair specified by attribute_num.
bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const{
    if(attribute_num > numOfPairs) return false;    //   not in range
    
    attval.attribute = attributes[attribute_num];   //   set key string
    
    attval.value = *(p_att.search(attval.attribute));  //   set value string
    
    return true;
}
