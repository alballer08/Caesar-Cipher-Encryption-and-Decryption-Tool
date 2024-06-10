// Name: Albert Zhang
// Date: 10 June 2024
// Program: Console Based Caesar Cipher Tool
// Extra: Allowing the user to choose between a randomly generated key or
// entering their own key.  The randomly generated key is printed so they can
// use it for later. connecting main to header
#include "CaesarCipher.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {

  // variables
  std::string text;
  int key;
  char choice;
  int gen;

  // asking for encryption or decryption
  // loop
  while (true) {
    std::cout << "Enter 'e' for encryption or 'd' for decryption: ";
    std::cin >> choice;
    // break out of loop
    if (choice == 'e' || choice == 'd') {
      break;
    }
  }
  // asking for key(shift)
  std::cout
      << "Would you like to enter your own key(1) or generate a random key(2)? "
      << std::endl;
  std::cin >> gen;

  // random
  srand(time(NULL));

  // loop
  while (true) {
    // checking what the user enters
    // if user enters 1
    if (gen == 1) {
      std::cout << "Enter key: ";
      std::cin >> key;
      break;
    }
    // if user enters 2
    else if (gen == 2) {
      // random key from 1 to 25
      key = rand() % 25 + 1;
      std::cout << "Randomly Generated Key: " << key << std::endl;
      break;
    }
    // if the user enters something else it will loop because there is no break
    else {
      std::cout << "Try again.  Please enter 1 or 2." << std::endl;
      std::cin >> gen;
    }
  }
  // creating object
  CaesarCipher cipher(key);
  // ignores last characters
  std::cin.ignore();

  // conditional statement
  if (choice == 'e') {
    // asking for plaintext
    std::cout << "Enter plaintext: ";
    // getting whole line
    std::getline(std::cin, text);
    // printing out the encrpyted message
    std::cout << "Encrypted Message: " << cipher.encrypt(text);
  }
  // conditional statement
  else if (choice == 'd') {
    // asking for ciphertext
    std::cout << "Enter ciphertext: ";
    // getting whole line
    std::getline(std::cin, text);
    // priniing decrypted text
    std::cout << "Decrypted Message: " << cipher.decrypt(text);
  }

  return 0;
}
