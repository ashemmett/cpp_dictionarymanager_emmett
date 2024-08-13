//
// Created by Ashton Emmett on 2/5/23.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include "Word.h"
#include "dictionary.h"

using namespace std;

/* (Prologue) Task 1: load and parse dictionary file
 * Function: loadFile()
*
 * Input:
 *  STL vector<Word> , Dictionary.
 *
 * Output:
 * - No output, called upon by main, “void” returns value.
 *
 * Functionality:
 * -  This function completes Task 1 by asking the user for a dictionary filename or “default”
 * to produce a fileEntry, the function will then attempt to read and load the file to a
 * new instance of the Word struct before appending the contents the vector<Word>.
 * All word names, definitions and types will be printed, if a file is not found or cannot be opened
 * the function will print an error message.
 *
 * Created:
 * - Ashton Emmett - 25th March 2023.
 */ //Task 1
void dictionary::loadFile(vector<Word> &vectorOfWords) {
    cout << "Enter [default] for 'dictionary_2023S1' or enter alt filename: ";
    string fileEntry;
    cin >> fileEntry;
    if (fileEntry == "default") {
        fileEntry = "dictionary_2023S1.txt";
    }

    ifstream myfile(fileEntry);

    if (myfile.is_open()) {

        Word record = Word("name", "definition", "type");

        while (!myfile.eof()) {

            string line;

            getline(myfile, line);
            line.erase(remove(line.end() - 1, line.end(), '\r'), line.end());

            if (line == "<word>") {

                // name
                string nameLine;
                getline(myfile, nameLine);

                nameLine.erase(remove(nameLine.end() - 1, nameLine.end(), '\r'), nameLine.end());
                record.setName(nameLine);

                // definition
                string definitionLine;
                getline(myfile, definitionLine);

                definitionLine.erase(remove(definitionLine.end() - 1, definitionLine.end(), '\r'), definitionLine.end());
                record.setDefinition(definitionLine);

                // type
                string typeLine;
                getline(myfile, typeLine);

                typeLine.erase(remove(typeLine.end() - 1, typeLine.end(), '\r'), typeLine.end());
                record.setType(typeLine);
                //append to vector
                vectorOfWords.push_back(record);
            }
        }
        myfile.close();
        cout << "Dictionary loaded successfully" << endl;
    }
    else {
        cout << "No dictionary loaded" << endl;
    }
}

/* (Prologue) Task 2: prompt user for word (word search function)
 * Function: wordSearch()
 *
 * Input:
 *  STL vector<Word> , Dictionary.
 *
 * Output:
 * - No output, called upon by main, “void” returns value.
 *
 * Functionality:
 * - This function completes Task 2 by prompting the user to enter a word and performing a search
 * through the currently loaded dictionary, the word entered is compared to word names in the dictionary.
 * When the word is found, the function prints the word’s name, definition and type.
 * However, an error message will print if the word isn’t found.
 *
 * Created:
 * - Ashton Emmett - 29th March 2023
 */ //Task 2
void dictionary::wordSearch(vector<Word> &vectorOfWords) {

    string search;
    cout << "Search for a valid word by name: " << endl; //users search
    cin >> search;
    transform(search.begin(), search.end(), search.begin(), ::tolower); //make input lower case

    for (Word i : vectorOfWords) {
        if (search == i.getName()) {         //does search equal existing name
            cout << search << endl;         //output search/name and definition
            cout << i.getDefinition() << endl;
            // cout << i.getType() << endl;

            if (i.getType() == "n") {                //type: n to noun etc
                cout << "[noun]" << endl;
            }
            else if (i.getType() == "v") {
                cout << "[verb]" << endl;
            }
            else if (i.getType() == "adv") {
                cout << "[adverb]" << endl;
            }
            else if (i.getType() == "adj") {
                cout << "[adjective]" << endl;
            }
            else if (i.getType() == "prep") {
                cout << "[preposition]" << endl;
            }
            else if (i.getType() == "misc") {
                cout << "[miscellaneous]" << endl;
            }
            else if (i.getType() == "pn") {
                cout << "[proper noun]" << endl;
            }
            else if (i.getType() == "n_and_v") {
                cout << "[noun and verb]" << endl;
            }

        }

    }

}

/* (Prologue) Task 3: find and print words with more than z,z,z characters
 * Function: findZWords()
 *
 * Input:
 *  STL vector<Word> , Dictionary.
 *
 * Output:
 * - No output, called upon by main, “void” returns value.
 *
 * Functionality:
 * - This function completes Task 3 by iterating through the currently loaded
 * dictionary to check for more than three “z” characters appearing in a single
 * word name field. All the words found are then printed to the screen by the function.
 *
 * Created:
 * - Ashton Emmett - 30th March 2023
 */ //Task 3
void dictionary::findZWords(vector<Word> &vectorOfWords) {

    for (Word i: vectorOfWords) {
        int count = 0; //start count
        for (char a: i.getName()) { //for loop to iterate
            if (a == 'z') { //does z = char in word line
                count++; //then count
            }
        }
        if (count >= 3) { //count more than or equal to 3
            cout << i.getName() << endl; //print word name
        }

    }

}

/* (Prologue) Task 4: add word to dictionary (add to stl vector)
 * Function: addWords()
 *
 * Input:
 *  STL vector<Word> , Dictionary.
 *
 * Output:
 * - No output, called upon by main, “void” returns value.
 *
 * Functionality:
 * - This function completes Task 4 by prompting the user for the name, definition and type of
 * new word they can add to the dictionary. If the word already exists within the dictionary then
 * an error message is printed. However, assuming the word given has a valid type the function will
 * create a corresponding word struct instance and add the word to the dictionary.
 *
 * Created:
 * - Ashton Emmett - 30th March 2023
 */ //Task 4
void dictionary::addWords(vector<Word> &vectorOfWords) {

    string newName;         //variables
    string newDefinition;
    string newType;


    cout << "Enter new word name: " << endl;        //user inputs
    cin >> newName ;
    cout << "Enter new word definition: " << endl;
    cin >> newDefinition ;
    cout << "Enter new word type: " << endl;
    cin >> newType ;

    for (Word i: vectorOfWords){
        if (i.getName() == newName) {            //test if word exists
            cout << "error: word exists, elevated privileges required to edit existing words" << endl;
            break;
        }
        //if else()
        // write into file ofstream myfile(“dictionary_2023S1.txt”);
        //        //
        //        // Write to the file
        //        //
        //        // MyFile << ? ;
        //        //
        //        // Close the file
        //        // MyFile.close();
    }



}

