//header file
//include guard
#pragma once

//compiler
#include <string>

class CaesarCipher{
private:
//attribute
int shiftKey;
//shift function that can only be accessed from this class
std::string shift(const std::string& text, int shiftKey) const;

public:
//constructor to initialize the key variable
CaesarCipher(int key);
//encrypt function
std::string encrypt(const std::string& plaintext) const;
//decrypt function
std::string decrypt(const std::string& ciphertext) const;

void set_crypt(int s);
};
