//
//  MatchMaker.hpp
//  cs32_UnHinged
//
//  Created by Michelle Navarrete on 3/2/22.
//

#ifndef MatchMaker_h
#define MatchMaker_h

#include <stdio.h>
#include <string>
#include "provided.h"
#include "MemberDatabase.h"
#include "AttributeTranslator.h"
#include <unordered_set>
#include <string>

using namespace std;

class MatchMaker {
public:
    MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at);
    ~MatchMaker();
    vector<EmailCount> IdentifyRankedMatches(string email, int threshold) const;
    
private:
    MemberDatabase* m_mdb;  //  Keep track of all the members
    AttributeTranslator* m_at;  //  Keep track of all the attributes
    static bool descending(const EmailCount& e1, const EmailCount& e2);
};




#endif /* MatchMaker_h */
