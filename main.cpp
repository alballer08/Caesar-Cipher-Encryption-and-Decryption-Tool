//Name: Albert Zhang
//Date: 4 June 2024
//Program: Console Based Caesar Cipher Tool
//Extra: Encrypt and decrypts numbers as well as characters.  Normal caesar ciphers do not encrypt and decrypt numbers but only characters

//connecting main to header
#include <iostream>
#include "CaesarCipher.h"

int main() {

  //variables
  std::string text;
  int key;
  char choice;

  //asking for encryption or decryption
  std::cout<<"Enter 'e' for encryption or 'd' for decryption: ";
  std::cin>>choice;

  //asking for key(shift)
  std::cout<<"Enter key: ";
  std::cin>>key;

  //creating object
  CaesarCipher cipher(key);
  //ignores last characters
  std::cin.ignore();

  //conditional statement
  if(choice=='e')
  {
    //asking for plaintext
  std::cout<<"Enter plaintext: ";
    //getting whole line
  std::getline(std::cin,text);
  //printing out the encrpyted message
  std::cout<<"Encrypted Message: "<<cipher.encrypt(text);
  }
    //conditional statement
  else if(choice=='d')
  {
    //asking for ciphertext
    std::cout<<"Enter ciphertext: ";
    //getting whole line
    std::getline(std::cin, text);
    //priniing decrypted text
    std::cout<<"Decrypted Message: "<<cipher.decrypt(text);
  }

  return 0;
}
