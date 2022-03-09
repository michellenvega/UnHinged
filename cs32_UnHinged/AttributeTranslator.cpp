//
//  AttributeTranslator.cpp
//  cs32_UnHinged
//
//  Created by Michelle Navarrete on 3/2/22.
//

#include "AttributeTranslator.h"
#include <string>

//  Constructor
AttributeTranslator :: AttributeTranslator(){
    
}

AttributeTranslator ::~AttributeTranslator(){
    
}

//  Destructor
bool AttributeTranslator::Load(string filename){
    
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    //   This method loads the attribute-value translation data from
    //   the data file specified by the filename parameter.
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
    
    //-------------------------------------------------------------//

    ifstream ifs (filename);    //  Check if file loaded correctly
    
    if(!ifs)  return false;  // failed to open

    //   The method must load the data into a data structure that enables efficient
    //   translation of attribute-value pairs
    
    string oneLine; //Gonna go one line at a time
    
    while(getline(ifs, oneLine)){
        
        string att_1, att_2, val_1, val_2, temp;
        int commacounter = 0;
        int start = 0;
        
    //-------------------------------------------------------------//

        for(int i = 0; i< oneLine.size();i++){
            if(oneLine[i] == ',' || i == oneLine.size()-1){
                commacounter++;
                if(commacounter == 1) {
                    att_1 = temp;
                    temp = "";
                    start = i+1;
                }
                if(commacounter == 2) {
                    val_1 = temp;
                    temp = "";
                    start = i;
                }
                if(commacounter == 3) {
                    att_2 = temp;
                    temp = "";
                    start = i+1;
                }
                if(commacounter == 4) {
                    val_2 = temp;
                    temp = "";
                    start = i+1;
                   // break;
                }
            }
            
            if(oneLine[start]!=',')
                temp+= oneLine[start];
            start++;
            
        }   //  <= end of for-loop
 
    //-------------------------------------------------------------//

        //  Now we add it to our radixtree.
        string s_pair = att_1 + ',' + val_1;    // source pair
        AttValPair c_pair ( att_2, val_2);         // compatible pair
        
        auto it = att_pairs.search(s_pair); //  Looking for pairs associated with source
        
        //  We check if there is already a vector for this source pair
        if(it == nullptr){ // if there is not,
            vector<AttValPair> c_temp;  //  Create new vector of AttValPairs
            c_temp.push_back(c_pair);   //  Add compatible pair to vector
            att_pairs.insert(s_pair, c_temp);   //  Add to Radix Tree
        }   else{   //  if there is...
            
            it->push_back(c_pair);  //  Add pair to the found vector
            
            
        }
    }
    return true;    //  Successfully open and loaded file, so return true.
}

vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const{
    
    string t_pair = source.attribute + "," + source.value;
    
    
    //  vector<AttValPair>* m_pairs = att_pairs.search(t_pair);
    //  To check for later tests...
    /*
    for (int i = 0; i < (*m_pairs).size(); i++) {

        cerr << (*att_pairs.search(t_pair))[i].attribute << ", " << (*att_pairs.search(t_pair))[i].value << endl;
    }*/

    return *att_pairs.search(t_pair);
}
