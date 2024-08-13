//
// Created by Ashton Emmett on 2/5/23.
//

#ifndef ASSIGNMENT_1_PROJECT_EXTENDEDDICTIONARY_H
#define ASSIGNMENT_1_PROJECT_EXTENDEDDICTIONARY_H
#include "Word.h"
#include "dictionary.h"

/* (Prologue) extendeddictionary.H
 * Class: extendeddictionary()
*
 * Input:
 * - Word(), Dictionary, dictionary(), vectorofwords.
 *
 * Output:
 * - Returns void unless called upon by main: findPalindromes(), findRhyme(), guess4thWord(), searchdle().
 *
 * Functionality:
 * -  The extendeddictionary() class completes the first part of assignment 2, the class holds and maintains the STL Vector of Words, encapsulates      * member functions; “5. findPalindromes()”, “6. findRhyme()”, “7. guess4thWord()” and “8. searchdle()”.
 *
 * Created:
 * - Ashton Emmett - 2nd May 2023.
 *///extendeddictionary class

class extendeddictionary : public dictionary {
private:
    string name;
    string definition;
    string type;
public:
    static void findPalindromes(vector<Word> &vectorOfWords);
    static void findRhyme(vector<Word> &vectorOfWords);
    static void guess4thWord(vector<Word> &vectorOfWords);
    static void searchdlehelper(vector<Word> &vectorOfWords);
};


#endif //ASSIGNMENT_1_PROJECT_EXTENDEDDICTIONARY_H
