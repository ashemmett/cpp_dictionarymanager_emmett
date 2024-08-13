//
// Created by Ashton Emmett on 2/5/23.
//
#ifndef ASSIGNMENT_1_PROJECT_DICTIONARY_H
#define ASSIGNMENT_1_PROJECT_DICTIONARY_H

#include "Word.h"

/* (Prologue) dictionary.H
 * Class: dictionary()
*
 * Input:
 * - Dictionary, Word()
 *
 * Output:
 * - Returns void unless called upon by main: vectorofwords, Load file(), Search word(), findZwords(), Add word().
 *
 * Functionality:
 * -  The dictionary() class completes the first part of assignment 2, the class holds and maintains the STL Vector of Words, encapsulates member functions; “1. Load file”, “2. Search word”, “3. findZwords” and “4. Add word”.

 * Created:
 * - Ashton Emmett - 29th April 2023.
 *///dictionary class

class dictionary {
private:
    string name;
    string definition;
    string type;
public:
    static void loadFile(vector<Word> &vectorOfWords);
    static void wordSearch(vector<Word> &vectorOfWords);
    static void findZWords(vector<Word> &vectorOfWords);
    static void addWords(vector<Word> &vectorOfWords);
};

#endif //ASSIGNMENT_1_PROJECT_DICTIONARY_H
