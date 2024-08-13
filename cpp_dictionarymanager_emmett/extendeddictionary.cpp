//
// Created by Ashton Emmett on 2/5/23.
//

#include "extendeddictionary.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
//#include "Word.h"
//#include "dictionary.h"

using namespace std;

/* (Prologue) Task 5. find Palindromes.
 * Function: findPalindromes()
*
 * Input:
 * - Word(), Dictionary, dictionary(), vectorofwords.
 *
 * Output:
 * - Returns void unless called upon by main: findPalindromes().
 *
 * Functionality:
 * -  The findPalindromes() function completes the 5th task of assignment 2, the function searches the STL word vector for any palindromes and         * then lists.
 * Created:
 * - Ashton Emmett - 7th May 2023.
 */ //Task 5
void extendeddictionary::findPalindromes(vector<Word> &vectorOfWords){
    cout << "Palindromes List:" << endl;
    for (Word i : vectorOfWords) {
        string name = i.getName();
        bool palindrome = true;
        int start = 0;
        int end = name.length() - 1;
        while (start < end && palindrome) {
            if (name[start] != name[end]) {
                palindrome = false;
            }
            start++;
            end--;
        }
        if (palindrome) {
            cout << i.getName() << endl;
        }
    }
}

/* (Prologue) Task 6. find rhyming words.
 * Function: findRhyme()
*
 * Input:
 * - Word(), Dictionary, dictionary(), vectorofwords, user input.
 *
 * Output:
 * - Returns void unless called upon by main: findRhyme().
 *
 * Functionality:
 * -  The findRhyme() function completes the 6th task of assignment 2, prompts user for input of 3 letters. The function then searches the STL word vector for any words ending in the same sequence of three letters as the word inputed by the user and returns the rhyming words.
 * Created:
 * - Ashton Emmett - 9th May 2023.
 */ //Task 6
void extendeddictionary::findRhyme(vector<Word> &vectorOfWords){
    string rhymeword;
    cout << "Enter a word to rhyme: " << endl;
    cin >> rhymeword;
    transform(rhymeword.begin(), rhymeword.end(), rhymeword.begin(), ::tolower);
    string rhyme = rhymeword.substr(rhymeword.length()-3);
    for (Word i : vectorOfWords) {
        string name = i.getName();
        if (name.length() >= 3 && name.substr(name.length()-3) == rhyme) {
            cout << i.getName() << endl;
        }
//        else {
//            cout << "No words rhyme!" << endl;
//        }
    }
}

/* (Prologue) Task 7. Guess the 4th word in a definition.
 * Function: guess4thWord()
 *
 * Input:
 * - Word(), Dictionary, dictionary(), vectorofwords, user input.
 *
 * Output:
 * - Returns void unless called upon by main: guess4thWord().
 *
 * Functionality:
 * -  The guess4thWord() function welcomes user and prints high score record, initialising current score as 0, and returns a random word and definition from the dictionary that has over 4 words in the definition. The 4th word of the definition is replaced with underscores and the function prompts the user to guess the missing word, if successful the function prints “Congratulations!” and adds 10 points to the current score and stores this in the current score record this process repeats unless user presses ‘X’ to exit/attempt other tasks. If the current score record is greater than the high score record the high score the function prints “New Highscore!” and overwrites the high score record with the new high score.
 * Created:
 * - Ashton Emmett - 11th May 2023.
 */ //Task 7
void extendeddictionary::guess4thWord(vector<Word> &vectorOfWords) {
    srand(time(0));
    int highscore = 0;
while (true) {
    cout << "Welcome Player 1, current high-score: " << highscore << endl;
    cout << "Given a random word, guess the 4th word in the definition" << endl;
    int score = 0;
    int randomIndex = rand() % vectorOfWords.size();
    Word randomWord = vectorOfWords[randomIndex];
    string name = randomWord.getName();
    for (Word i: vectorOfWords) {
        if (name == i.getName()) {
            cout << name << endl;
            // cout << i.getDefinition() << endl;
            string definition4thWord = i.getDefinition();
            size_t firstSpace = definition4thWord.find(' ', 0);
            size_t secondSpace = definition4thWord.find(' ', firstSpace + 1);
            size_t thirdSpace = definition4thWord.find(' ', secondSpace + 1);
            size_t fourthSpace = definition4thWord.find(' ', thirdSpace + 1);

            string fourthWord = definition4thWord.substr(thirdSpace + 1, fourthSpace - thirdSpace - 1);
            string replacement = string(fourthWord.length(), '_');
            definition4thWord.replace(thirdSpace + 1, fourthSpace - thirdSpace - 1, replacement);

            cout << definition4thWord << endl;
            string guess;
            cout << "Guess the missing (4th) word: " << endl;
            cin >> guess;
            transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

            if (guess == fourthWord) {
                score += 10;
                cout << "Congratulations!" << endl;
                cout << "Score: " << score << endl;
            } else {
                cout << "Incorrect, correction: " << i.getDefinition() << endl;
                cout << "Your final score: " << score << endl;

                if (score > highscore) {
                    highscore = score;
                    cout << "New High-score!" << endl;
                }

            }
        }
    }

    char retry;
    cout << "play again? (y/n)" << endl;
    cin >> retry;

    if (retry != 'y') {
        break;
    }
}
};

/* (Prologue) Task 8. Completes “searchdle” search parameters.
 * Function: searchdle()
*
 * Input:
 * - Word(), Dictionary, dictionary(), vectorofwords, user input.
 *
 * Output:
 * - Returns void unless called upon by main: searchdle().
 *
 * Functionality:
 * -  The searchdle() function first prints the name of the game with instructions. Prompts user to enter parameters for: “same number of letters as the ‘mystery’ word”, “Does not contain any of the letters in a user-specified set”, contains the entire set of letters in a second, user-specified, set, anywhere in the word”, “contains the entire set of letters in a third user-specified set at positions specified for each of the letters”. The function searches the dictionary for the words that meet these parameters and prints the words found.
 * Created:
 * - Ashton Emmett - 13th May 2023.
 */ //Task 8
void extendeddictionary::searchdlehelper(vector<Word> &vectorOfWords) {
        cout << " -------------------------------------------------------------------- " << endl;
        cout << "Searchdle Helper!" << endl;
        cout << "Instructions: Searchdle is a clone of Wordle, the word guessing game." << endl;
        cout << "   Use the parameter options to cheat at Searchdle;" << endl;
        cout << "   Follow the prompts and enter the length of the mystery word, the letters that aren't " << endl;
        cout << "   in the mystery word (grey letters), enter the set of letters that appear in the mystery word! (yellow letters)" << endl;
        cout << "   (i.e. Narrow down the possible options for the word) " << endl;
        cout << " -------------------------------------------------------------------- " << endl;

        int nLetters; //length of word
        cout << "1. Enter the length the mystery word (number of letters): " << endl;
        cin >> nLetters;

        string greyLetters; //green letters
        cout << "2. Enter the grey letters in the mystery word (no spaces): " << endl;
        cin >> greyLetters;
        transform(greyLetters.begin(), greyLetters.end(), greyLetters.begin(), ::tolower);

        string setLetters; //yellow letters
        cout << "3. Enter the set of letters in the mystery word (no spaces): " << endl;
        cin >> setLetters;
        transform(setLetters.begin(), setLetters.end(), setLetters.begin(), ::tolower);

        cout << " -------------------------------------------------------------------- " << endl;
        cout << " Words found include: " << endl;
        cout << " -------------------------------------------------------------------- " << endl;

        for (Word &name: vectorOfWords) {
            if (name.hasYellowLetters(setLetters) && name.getLength() == nLetters && name.hasGreyLetters(greyLetters)) {
                cout << name.getName() << endl;
            }
        }
        //green letters
    };