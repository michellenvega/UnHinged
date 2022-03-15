//
//  utility.cpp
//  cs32_UnHinged
//
//  Created by Michelle Navarrete on 3/14/22.
//

#include <stdio.h>
#include "utility.h"

bool operator < (const AttValPair& a, const AttValPair& b){
    //  Check attributes
    if(a.attribute < b.attribute)
        return true;
    
    if(a.attribute == b.attribute){
        // Check values
        if(a.value < b.value)
            return true;
    }
    
    return false;
}
