// Object Orientated Programming Assignment 1, Ashton Emmett (10564416)

#include <iostream>
#include <vector>
//#include "Word.h"
#include "dictionary.h"
#include "extendeddictionary.h"
//#include "dictionary.cpp"
//#include "extendeddictionary.cpp"

using namespace std;

/* (Prologue) Main()
 *
 * Input:
 *  STL vector<Word> , Dictionary, user input.
 *
 * Output:
 * - Outputs results from the 4 functions/tasks.
 *
 * Functionality:
 * - Main() handles the title, task selection screen, declares STL vector<Word> and
 * calls upon the 4 functions above to complete each of the task.
 *
 * Created:
 * - Ashton Emmett - 23rd March 2023
 */ //Main
int main()
{

    vector<Word> vectorOfWords;
    bool loaded = false;

    while (true)
    {
        //print menu/text
        cout << " \n-------------------------------------------------------------------- " << endl;
        cout << " Welcome to Dictionary Application, please enter a task number (1-5): " << endl;
        cout << " -------------------------------------------------------------------- " << endl;
        cout << "Task 1. Load and Parse a dictionary file! " << endl;
        cout << "Task 2. Search for a word within the dictionary! " << endl;
        cout << "Task 3. Print all words that contain more than three ‘z’ characters in them! " << endl;
        cout << "Task 4. Add new word to dictionary! " << endl;
        cout << "Task 5. List all words in the dictionary that are palindromes! " << endl;
        cout << "Task 6. Find rhyming words in the dictionary! " << endl;
        cout << "Task 7. Guess the fourth word game! " << endl;
        cout << "Task 8. Searchdle Helper! " << endl;
        cout << "Task 9. Quit Program!" << endl;

        int taskNo;
        cout << " -------------------------------------------------------------------- " << endl;
        cout << "Enter your input (1-9):";
        cin >> taskNo;

// Task 1
        if (taskNo == 1){
            dictionary obj;
            obj.loadFile(vectorOfWords);
            loaded = true;

        }
// Task 2
        else if (taskNo == 2){
            dictionary obj;
            obj.wordSearch(vectorOfWords);
            if (loaded) {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "Either search complete or word not found..." << endl;

            }
            else {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "No dictionary loaded!" << endl;
                cout << "Restarting program..." << endl;
            }
        }
// Task 3
        else if (taskNo == 3){
            dictionary obj;
            obj.findZWords(vectorOfWords);
            if (loaded) {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "Z word search complete..." << endl;


            }
            else {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "No dictionary loaded!" << endl;
                cout << "Restarting program..." << endl;
            }
        }
// Task 4
        else if (taskNo == 4){
            dictionary obj;
            obj.addWords(vectorOfWords);
            if (loaded) {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "New word process complete" << endl;

            }
            else {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "Dictionary not loaded, Word not added to dictionary!" << endl;
                cout << "Restarting program..." << endl;
            }
        }
// Task 9
        else if (taskNo == 9){
            cout << " -------------------------------------------------------------------- " << endl;
            cout << "Thank you, Goodbye!\n";
            return 1;
        }

// Task 5
        else if (taskNo == 5){
            extendeddictionary obj;
            obj.findPalindromes(vectorOfWords);
            if (loaded) {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "Palindrome search process complete" << endl;

            }
            else {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "Dictionary not loaded!" << endl;
                cout << "Restarting program..." << endl;
            }
        }
// Task 6
        else if (taskNo == 6){
            extendeddictionary obj;
            obj.findRhyme(vectorOfWords);
            if (loaded) {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "Rhyming words process complete" << endl;
            }
            else {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "Dictionary not loaded!" << endl;
                cout << "Restarting program..." << endl;
            }
        }
// Task 7
        else if (taskNo == 7){
            extendeddictionary obj;
            obj.guess4thWord(vectorOfWords);
            if (loaded) {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "Guess fourth word game complete" << endl;

            }
            else {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "Dictionary not loaded!" << endl;
                cout << "Restarting program..." << endl;
            }
        }
// Task 8
        else if (taskNo == 8){
            extendeddictionary obj;
            obj.searchdlehelper(vectorOfWords);
            if (loaded) {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "New word process complete" << endl;

            }
            else {
                cout << " -------------------------------------------------------------------- " << endl;
                cout << "Dictionary not loaded!" << endl;
                cout << "Restarting program..." << endl;
            }
        }


        else {
            cout << " -------------------------------------------------------------------- " << endl;
            cout << "invalid task, please try again" << endl;
            cout << "Restarting program..." << endl;
        }


}
    return -1;
}