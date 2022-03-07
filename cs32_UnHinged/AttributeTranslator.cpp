//
//  AttributeTranslator.cpp
//  cs32_UnHinged
//
//  Created by Michelle Navarrete on 3/2/22.
//

#include "AttributeTranslator.h"

#include <string>

AttributeTranslator :: AttributeTranslator(){
    
}

AttributeTranslator ::~AttributeTranslator(){
    
}


bool AttributeTranslator::Load(string filename){
    
    //     This method loads the attribute-value translation data from the data file specified by the
    //     filename parameter.
    
    ifstream ifs (filename);    //  Check if file loaded correctly
    
    if(!ifs)  return false;  // failed to open

    //      The method must load the data into a data structure that enables efficient
    //      translation of attribute-value pairs
    
    string oneLine; //Gonna go one line at a time
    
    while(getline(ifs, oneLine)){
        
        string att_1, att_2, val_1, val_2, temp;
        int commacounter = 0;
        int start = 0;
        for(int i = 0; i< oneLine.size();i++){
            if(oneLine[i] == ',' || i == oneLine.size()-1){
                commacounter++;
                if(commacounter == 1) {att_1 = temp; temp = "";
                    start = i+1;
                }
                if(commacounter == 2) {
                    val_1 = temp;
                    temp = "";
                    start = i;
                }
                if(commacounter == 3) {att_2 = temp; temp = "";
                    start = i+1;
                }
                if(commacounter == 4) {val_2 = temp; temp = "";
                    start = i+1;
                   // break;
                }
            }
            
            
            if(oneLine[start]!=',')
                temp+= oneLine[start];
            start++;
            
        }
 
        //check this again once you fix your radix tree!!!
       // t_source.insert(att_1, val_1);
       // t_comp.insert(att_2, val_2);
    }
    
    
   
    
    
    
    return true;
}

vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const{
    
    vector<AttValPair> m_pairs;
    

    
    
    return m_pairs;
}
