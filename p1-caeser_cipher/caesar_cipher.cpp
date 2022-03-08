#include<bits/stdc++.h>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;


string plaintext_to_cipher(string plaintext, int s){

    string result = "";

    for(int i=0; i<plaintext.length(); i++){
        if(isupper(plaintext[i])){
            result += char((int(plaintext[i])-65+s)%26 + 65);
        }
        else if(islower(plaintext[i])){
            result += char((int(plaintext[i])-97+s)%26 + 97);
        }
        else{
            result += plaintext[i];
        }
    }

    return result;
}

string cipher_to_plaintext(string cipher, int s){

    string result = "";
    int temp;

    for(int i=0; i<cipher.size(); i++){         //text.length() == text.size()
        if(isupper(cipher[i])){
                if(int(cipher[i])-65-s<0){
                    temp = int(cipher[i])-65-s+26;
                    result += char(temp%26 + 65);

                }
                else{
                        result += char((int(cipher[i])-65-s)%26 + 65);
                }
        }
        else if(islower(cipher[i])){
            if(int(cipher[i])-97-s<0){
                    temp = int(cipher[i])-97-s+26;
                    result += char(temp%26 + 97);

                }
                else{
                        result += char((int(cipher[i])-97-s)%26 + 97);
                }
        }
        else{
            result += cipher[i];
        }
    }

    return result;

}

int main(){

    string text, encrypted;
    int rs=3;       //rs = right shift

    ifstream in;
    in.open("plaintext.txt");
    // in >> text;            //it wil take untill the first space is occured
    getline(in, text);       //it will take entire text along with spaces
    in.close();


    encrypted = plaintext_to_cipher(text, rs);
    string decrypted = cipher_to_plaintext(encrypted, rs);


    ofstream out;           //Stream class to write on files
    out.open("encryption and decryption.txt");
    out << "encrypted ciphertext: " << encrypted << endl;
    out << "Decrypted plaintext : "<< decrypted  ;
    out.close();

    cout << text;


    return 0;
}
