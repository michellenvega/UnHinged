//
//  MemberDatabase.cpp
//  cs32_UnHinged
//
//  Created by Michelle Navarrete on 3/2/22.
//

#include "MemberDatabase.h"

MemberDatabase::MemberDatabase(){}

MemberDatabase::~MemberDatabase(){}


bool MemberDatabase::LoadDatabase(std::string filename){

    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    //  We need to load the information from the file into our data
    //  structures. We have the name, email, num of pairs, and then
    //  the actual pairs.
    // // // // // //  //  //  //  //  //  //  //  //  //  //  //  //
    
    //-------------------------------------------------------------//
    
    ifstream ifs (filename);    //  To open the file
    if( !ifs )  {
        cerr << "unable to open the file" << endl;
        return false; } // failed to open
    
    string oneLine; // To look at each line, one at a time
    
    //-------------------------------------------------------------//
    
    string m_name, m_email, m_pair, m_attribute, m_value;
    int numPairs = 0;   int lineCount = 1;

       while(getline(ifs, oneLine)){
           
           //  First, calculate num of lines per member.
           if(oneLine =="") //  If line if empty
               break;
              
           
           
       //-------------------------------------------------------------//

           else{
                if (lineCount == 1){    //  Name is the first line
                   m_name = oneLine;
                   lineCount ++;
               }   else if (lineCount == 2){   //  Email
                   m_email = oneLine;
                   lineCount ++;
               } else if (lineCount == 3){   // Count of attr-valued pairs
                   numPairs =stoi(oneLine);   //   Obtain number in the string
                   lineCount++;
               }   else{   //  Here we obtain all the attributes and finally insert the email with it.
                   
                   PersonProfile profile (m_name, m_email);//  Now, we access the profile for this member.
                   
                   
    //-------------------------------------------------------------//

                   
                   
                     
                   if(numPairs > 0){    //  We have at least one attribute pair.
                    
                       for(int i = 0; i < numPairs; i++){

                            if(i!= 0 && !getline(ifs, oneLine))
                                         break;
                       stringstream t_str(oneLine);   // will help us alter string
                       getline(t_str, m_attribute, ',');  //  Obtain the attribute
                       getline(t_str, m_value, '\n');     //  Obtain the value
                       profile.AddAttValPair(AttValPair(m_attribute, m_value));    //  Add it to the profile
                        
                       //-------------------------------------------------------------//
                        
                       m_pair  =   m_attribute + ',' + m_value;    // Concatenate the pair string
                       
                       //  Check if pair is in Radix Tree, we want to obtain only the letters of it.
                       auto inTree = member_attr.search(m_pair);
                       if(inTree == NULL){     //  If not, then add email to new vector.
                           vector<string> newVec;
                           newVec.push_back(m_email);
                           member_attr.insert(m_pair, newVec); //  Add to Radix Tree
                       }
                       else{        //  If there is, add email to existing vector.
                           inTree->push_back(m_email);
                       }
                   }   // end of 'numpair' else statement
                       lineCount = 1;
                       numPairs = 0;

                   }
                   
                   
                   
                   
                   
                   
 //-------------------------------------------------------------//

                   member_emails.insert(profile.GetEmail(), profile);  //  Update attributes per the line
                   
               }
               
           }   //  <= end of 'non empty line' else statement
       
           
           
           
       }   // <= end of while loop

       return true;
   }


std::vector<std::string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const{
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    //  Now, lets take input's val and attribute and return members
    //  who have the same attributes. If there are no such members,
    //  the vector returned must be empty.
    // // // // // //  //  //  //  //  //  //  //  //  //  //  //  //
    
    //-------------------------------------------------------------//
    
    string check_pair = input.attribute + ',' + input.value;    // Concatenate the pair string

    return *member_attr.search(check_pair); //  It will return the vector of strings
}

const PersonProfile*  MemberDatabase::GetMemberByEmail(std::string email) const{
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    //  Now, lets look to obtain a member's information with just
    //  their email
    // // // // // //  //  //  //  //  //  //  //  //  //  //  //  //
    
    //-------------------------------------------------------------//
    
    //  Here, if we get a NULLPTR, we know there is no data for a member with that email.
    if ((member_emails.search(email)) == nullptr) {
        return nullptr;
    }

    //  Otherwise, we return the profile of the member with that email
    return (member_emails.search(email));
}

