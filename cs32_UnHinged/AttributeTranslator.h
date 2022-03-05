//
//  AttributeTranslator.h
//  cs32_UnHinged
//
//  Created by Michelle Navarrete on 3/2/22.
//

#ifndef AttributeTranslator_h
#define AttributeTranslator_h

#include <stdio.h>
#include <string>
//#include "translator.txt"
#include "RadixTree.h"
#include <vector>
using namespace std;

template <typename AttValPair>

class AttributeTranslator{
public:
    //  This constructs a AttributeTranslator object.
    AttributeTranslator();
    //  You may define a destructor for AttributeTranslator if you need one.
    ~AttributeTranslator();
    //  This method loads the attribute-value translation data from the data file specified by the filename parameter
    bool Load(string filename);
    //  This method must identify all compatible attribute-value pairs for the specified source
    //  attributevalue pair in an efficient manner (meeting the requirements at the top of this section) and return
    //  a vector containing them
    vector<AttValPair> FindCompatibleAttValPairs(const AttValPair& source) const;

private:
    
};



#endif /* AttributeTranslator_h */
