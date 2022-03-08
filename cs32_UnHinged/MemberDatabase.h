//
//  MemberDatabase.h
//  cs32_UnHinged
//
//  Created by Michelle Navarrete on 3/2/22.
//

#ifndef MemberDatabase_h
#define MemberDatabase_h

#include <stdio.h>
#include <iostream>
#include "provided.h"
#include "RadixTree.h"
#include "PersonProfile.h"
#include <fstream>
#include <sstream>
using namespace std;



class MemberDatabase{
public:
    MemberDatabase();   // Constructor
    ~MemberDatabase();  // Destructor
    bool LoadDatabase(std::string filename);
    std::vector<std::string> FindMatchingMembers(const AttValPair& input) const;
    const PersonProfile* GetMemberByEmail(std::string email) const;
private:
//  Data Strcutures:
    RadixTree<vector<string>> member_attr;  // keep track of all attributes
    RadixTree<PersonProfile> member_emails; //  keep track of all emails
};





#endif /* MemberDatabase_h */
