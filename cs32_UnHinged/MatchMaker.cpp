//
//  MatchMaker.cpp
//  cs32_UnHinged
//
//  Created by Michelle Navarrete on 3/2/22.
//

#include "MatchMaker.h"
#include <string>

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at){
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    //  This constructs a MatchMaker object with the indicated parameters
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    
    //------------------------------------------------------------------//
    
    m_mdb = new MemberDatabase(mdb);    //  'Copy' of given database
    m_at = new AttributeTranslator(at); //  'Copy' of given attributes
    
}

MatchMaker::~MatchMaker(){
    //  //  //  //  //  //  //  //  //  //  //  //  //
    //  This destructs a MatchMaker object if needed.
    //  Frees all dynamically allocated data.
    //  //  //  //  //  //  //  //  //  //  //  //  //
    
    //------------------------------------------------//
    
    delete m_at;
    delete m_mdb;
    
}

 vector<EmailCount> MatchMaker::IdentifyRankedMatches(string email, int threshold) const{
    
     
     //  //  //  //  //  //  //  //  //  //  //  //  // //  //  //  //  //  //
     //  Given a member’s email address, it must look up the attribute-value
     //  pairs associated with that member (using the MemberDatabase and
     //  PersonProfile classes), identify compatible attribute-value pairs
     //  (using the AttributeTranslator class), and then identify and rank
     //  order compatible members for the original member that have at least
     //  the threshold number of compatible attributes. Finally, it must
     //  output these matching members.
     //  //  //  //  //  //  //  //  //  //  //  //  // //  //  //  //  //  //
     
     //-----------------------------------------------------------------//
      
     // Look up the attributes of a member using the email
    const PersonProfile* profile = m_mdb->GetMemberByEmail(email);
     
     // To store all the information we need
     vector<EmailCount> email_vec;
     unordered_set<AttValPair> comp_set;   // attributes
     
     // First, get all attributes of this profile
     int total_att = profile->GetNumAttValPairs();  //  Total num of attributes
     
     //-----------------------------------------------------------------//

     for(int i = 0; i < total_att; i++){
         AttValPair att_temp;
         profile->GetAttVal(i, att_temp);    // obtain AttValPair to compare
         vector<AttValPair>comp_vec ;
         comp_vec = m_at->FindCompatibleAttValPairs(att_temp);
         
    //-----------------------------------------------------------------//

        // Now we add each compatible into set of strings for easy access
    
         for(int j = 0; j < comp_vec.size(); j++){
         AttValPair c_pair = comp_vec[i];
         comp_set.insert(c_pair);

         }
         
     }  // <= end of first for-loop

     //-----------------------------------------------------------------//

     // Then, we obtain all compatible members
     unordered_set<std::string> email_set;  //  To keep track of emails
     
     // find matching members!
     unordered_set<AttValPair>::iterator it = comp_set.begin();
     for( ; it != comp_set.end(); it++){
         vector<string> compad_e = m_mdb->FindMatchingMembers(*it); // Get emails related to each pair
         for(int k = 0; k < compad_e.size(); k++)
             email_set.insert(compad_e[k]); 
       }
     
     
     //-----------------------------------------------------------------//
     
     // Now we check how many times an email shows up
            //  This is how we see which member is more compatible!
     
     
     //Then, sort then by 'smallest to greatest'
        // Check that order^ idk if its supposed to be like that
     
     
     // Identify a rank order of other members with at least same
        //  threshold of compatible attributes
        //  use get num of att val pairs
     
     // Add these members to the vector in order and return.
        //  In descending order
     
     
     
    //  -----------------------------------------------  //
     
     
    return std::vector<EmailCount>();
    
}

