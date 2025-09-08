#include <iostream>
using namespace std;
#include <string>

/*Substitution Cipher
 A simple and very old method of sending secret messages is the substitution cipher.
 Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
 
 Write a program that asks a user to enter a secret message.
 Encrypt this message using the substitution cipher and display the encrypted message.
 Then decrypt the encrypted message back to the original message.

 Use the two strings below for substitution.
 For example, to encypt you can replace the character at position n in alphabet with
 the character at position n in key.
  
 To decrypt you can replace the character at position n in key with the character
 at position n in alphabet. */
 
 
int main()
{
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    string s_message{};
	cout<<"Enter your secret message: ";
    getline(cin, s_message) ; // Because its more than one word
    
    //The Encryption
    string encrypted_message{};
    
    cout <<"\nEncrypting message... " <<endl;
    
    //Using range based for loop to go through every character in the string 
    for(char c:s_message){
        size_t position = alphabet.find(c); //looks for index number of the first character, if found
        if (position != string::npos) {     //If position is found then we will substitute, else we will add
           char new_char = {key.at(position)};                                 //to the encrypted message as it was.
           encrypted_message += new_char; 
        } else {
            encrypted_message += c;
        }
    }
    cout << endl;
    cout <<"Encrypted message: "<< encrypted_message << endl;
    
    //The Decryption
    string decryptd_msg{};
    
    cout <<"\nDecrypting message... " <<endl;
    
    for (char c:encrypted_message){
        size_t position = key.find(c);
        if(position != string::npos){
            char new_char = {alphabet.at(position)};
            decryptd_msg += new_char;
        }else{
            decryptd_msg += c;
        }
    }
    
    cout << "\nDecrypted message: " << decryptd_msg << endl;
	return 0;
}
