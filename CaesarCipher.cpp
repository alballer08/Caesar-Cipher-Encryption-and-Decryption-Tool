//connect this to header file
#include "CaesarCipher.h"
#include <cctype>

//constructor
CaesarCipher::CaesarCipher(int key) : shiftKey(key){}

//encrypt function 
std::string CaesarCipher::encrypt(const std::string& plaintext) const{
  //calls shift function with these parameters
  return shift(plaintext, shiftKey);
}
//decrypt function
std::string CaesarCipher::decrypt(const std::string& ciphertext) const{
  //calls shift function with these parameters
  return shift(ciphertext, -shiftKey);
}

//shift function to shift characters
std::string CaesarCipher::shift(const std::string& text, int key) const{
  //variables
  int letterShiftKey = key % 26;
  int digitShiftKey = key%10;
 // int digitShiftKey = shiftKey % 10;
  std::string result=text;

  //checking for encrpytion or decryption   
  //for each loop
  for (char& c : result) {
      // Conditional statement for letters
      if (isalpha(c)) {
          // Base char
          /*Shifting 'A' by 3:
          c = 'A'
          base = 'A'
          letterShiftKey = 3
          c = ('A' - 'A' + 3) % 26 = 3 % 26 = 3
          c += 'A' (adding 'A' back to get the shifted letter)
          c = 'D'*/
          char base = isupper(c) ? 'A' : 'a';
          // Shifting character
          c = (c - base + letterShiftKey) % 26;
          if (c < 0) c += 26; // Handle negative shift for decryption
          c += base;
      }
      // Conditional statement for digits
      else if (isdigit(c)) {
          // Base char for digit (start of '0')
          char base = '0';
          // Shifting number based on key
          c = (c - base + digitShiftKey) % 10;
          if (c < 0) c += 10; // Handle negative shift for decryption
          c += base;
      }
  }
  //returning shifted string to the called functions above
  return result;
}
