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
     
     multiset<AttValPair> comp_set;   // attributes
     
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
         const AttValPair c_pair (comp_vec[j].attribute, comp_vec[j].value);
         comp_set.insert(comp_vec[j]);

         }
         
     }  // <= end of first for-loop

     //-----------------------------------------------------------------//

     // Then, we obtain all compatible members
     set<std::string> email_set;  //  To keep track of emails
     
     // find matching members!
     set<AttValPair>::iterator it = comp_set.begin();
     for( ; it != comp_set.end(); it++){
         vector<string> compad_e = m_mdb->FindMatchingMembers(*it); // Get emails related to each pair
         for(int k = 0; k < compad_e.size(); k++)
             email_set.insert(compad_e[k]); 
       }
     
     
     //-----------------------------------------------------------------//
     
     // Let's check how many times an email shows up (has to be more than threshold)
     //  This is how we see which member is more compatible!
     set<std::string>::iterator e_it = email_set.begin();
     for( ; e_it != email_set.end(); e_it++){
          const PersonProfile* person = m_mdb->GetMemberByEmail(*e_it);
          int counter = 0;  //  To keep track of how many times this perso shows up
         

          for(int n = 0; n < person->GetNumAttValPairs(); n++){
              AttValPair potentialAttPair;
              person->GetAttVal(n, potentialAttPair);
              
              if(comp_set.find(potentialAttPair) != comp_set.end())
                    counter ++;
                    
          } // <= end of second for-loop
         
         //-----------------------------------------------------------------//
         
          if(threshold <= counter) {    //  Can only be added if seen at least 'threshold' of times
                    EmailCount a_email(*e_it,counter);
                    email_vec.push_back(a_email); //  Add it to the vector
          }
         
     }  //  <= end of first for-loop
         
     //-----------------------------------------------------------------//
     
     //Then, sort so it is in a descending order!!
     
                    sort(email_vec.begin(),email_vec.end(), descending);
     
     //-----------------------------------------------------------------//

     
     return email_vec;
     
     
         
     }

bool MatchMaker::descending(const EmailCount& e1, const EmailCount& e2){
    
    //  //  //  //  //  //  //  //  //  //  //  //  //
    //  If count is the same, we have to sort by the
    //  alphabet!!!
    //  //  //  //  //  //  //  //  //  //  //  //  //
    
    //------------------------------------------------//
    
    if(e1.count == e2.count) {
        return e1.email<e2.email;   //  Return alphabetized
    }
    return e1.count>e2.count;   // Otherwise return based on count
}

