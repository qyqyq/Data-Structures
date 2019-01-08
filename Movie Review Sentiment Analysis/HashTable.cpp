#include "HashTable.h"
#include "WordEntry.h"

list<WordEntry>::iterator it;

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
	size = s;
	hashTable = new list<WordEntry>[size];
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
    int t = 0;
    for(unsigned int i = 0; i < s.length(); i++)
    {
        t = (t + s[i]) % size;
    }
    return t;
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearances with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
    int t = computeHash(s);
    for(it = hashTable[t].begin(); it != hashTable[t].end(); it++)
    {
        if(it->getWord() == s)
        {
            it->addNewAppearance(score);
            return;
        }
    }
    hashTable[t].push_back(WordEntry(s,score));
}

/* getAverage
*  input: string word
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
    int t = computeHash(s);
    for(it = hashTable[t].begin(); it != hashTable[t].end(); it++)
    {
        if(it->getWord() == s)
            return it->getAverage();
    }
    return 2.0;
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) {
    int t = computeHash(s);
    for(it = hashTable[t].begin(); it != hashTable[t].end(); it++)
    {
        if(it->getWord() == s)
            return true;
    }
    return false;
}

