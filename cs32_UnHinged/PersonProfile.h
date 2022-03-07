//
//  PersonProfile.h
//  cs32_UnHinged
//
//  Created by Michelle Navarrete on 3/2/22.
//

#ifndef PersonProfile_h
#define PersonProfile_h

#include <stdio.h>
#include <string>
#include "AttributeTranslator.h"
#include "RadixTree.h"
#include <vector>
using namespace std;



class PersonProfile{
public:
    //  This constructs a PersonProfile object, specifying the member’s name and email address
    PersonProfile(string name, string email);
    //  You may define a destructor for PersonProfile if you need one.
    ~PersonProfile();
    //  The getName method returns the member’s name.
    string GetName() const;
    //  The getName method returns the member’s email address.
    string GetEmail() const;
    //  The AddAttValPair method is used to add a new attribute-value pair to the member’s profile.
     void AddAttValPair(const AttValPair& attval);
    //  Returns the total number of distinct attribute-value pairs associated with this member.
    int GetNumAttValPairs() const;
    //  This method gets the attribute-value pair specified by attribute_num.
     bool GetAttVal(int attribute_num, AttValPair& attval) const;
private:
    string m_name, m_email;
    RadixTree<vector<string>>  p_tree;
    vector<string>attributes;
};





#endif /* PersonProfile_h */
