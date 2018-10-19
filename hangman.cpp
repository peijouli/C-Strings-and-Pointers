// hangman.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter
for (int i = 0; i < strlen(targetWord); i++){
    word[i]='*';
  }


while (numTurns != 0){
  for (int i = 0; i < strlen(targetWord); i++){
    if (i == strlen(targetWord)-1){
      word[strlen(targetWord)]='\0';
    }
  }

  cout << "Current Word: " << word << endl;
cout << numTurns << " remain... Enter a letter to guess"<< endl;
cin >> guess;
wordGuessed= false;
  for (int j=0; j< strlen(targetWord); j++){

    if (guess == targetWord[j]){

      word[j] = guess;
      wordGuessed = true;
    }   

  }


  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
if (wordGuessed == false){
  numTurns = numTurns - 1;
}

if (numTurns < 1){
  cout << "you lose"<< endl;
  return 0;
  
}
if (strcmp(word, targetWord) == 0 ){
  cout << "you win"<< endl;
  break;

}


  // Print out end of game status

}
    
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  for (int j=0; j< strlen(targetWord); j++){
    if (guess == targetWord[j]){
      int count = 0;
      word[j] = guess;
      count ++;   
      return count; 
    }   

  }



}

