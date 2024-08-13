#include <iostream>
#include <string>
#include <vector>
#ifndef Word_H
#define Word_H
using namespace std;

/* (Prologue) Word.H
 * Class: Word()
*
 * Input:
 * - Dictionary.
 *
 * Output:
 * - None
 *
 * Functionality:
 * -  This class completes the first part of assignment 2, by acting as a word struct for the corresponding STL word vector and dictionary of words.
 * Encapsulates the required getters, setters and constructor for Word.
 *
 * Created:
 * - Ashton Emmett - 29th April 2023.
 */

class Word {
private:
    string name;
    string definition;
    string type;
public:
    // constructor.
    Word(string name, string definition, string type) {
        Word::name = name;
        Word::definition = definition;
        Word::type = type;
    }

    //setter and getter methods for the class
    string getName() {
        return name;
    }

    void setName(string name) {
        this-> name = name;
    }

    string getDefinition() {
        return definition;
    }

    void setDefinition(string definition) {
        this-> definition = definition;
    }

    string getType() {
        return type;
    }
    void setType(string type) {
        this-> type = type;
    }
    bool hasYellowLetters(string& letters)  {
        for (char c : letters) {
            if (name.find(c) == string::npos) {
                return false;
            }
        }
        return true;
    }
    int getLength() {
        return name.length();
    }
    bool hasGreyLetters(string& letters) {
        for (char c: letters) {
            if (name.find(c) == string::npos) {
                return true;
            }
        }
        return false;
    }

};

#endif //Word_H