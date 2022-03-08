#include<bits/stdc++.h>
using namespace std;


map<string, string> hashMap;
map<string, string> revHashMap;


void GetHash(){

    ifstream fin;
    fin.open("hashfile.txt");

    string key, value;

    while(!fin.eof()){
        fin >> key >> value;
        hashMap[key] = value;
        revHashMap[value] = key;
    }

    fin.close();
}


string encryption(string text){

    string cipher="";
    for(int i=0; i<text.size(); i+=3){
        string tmp="";

        tmp += text[i];
        tmp += text[i+1];
        tmp += text[i+2];

        cipher += hashMap[tmp];
    }
    return cipher;
}

string decryption(string cipher){

    string plaintext="";
    for(int j=0; j<cipher.size(); j+=3){
        string tmp="";
        tmp += cipher[j];
        tmp += cipher[j+1];
        tmp += cipher[j+2];

        plaintext += revHashMap[tmp];
    }
    return plaintext;
}


int main(){

    string msg, plaintext, ciphertext;

    ifstream fin;
    fin.open("in.txt");
    fin >> msg;         //read from file
    fin.close();

    GetHash();
    ciphertext = encryption(msg);               //encrypting message
    plaintext = decryption(ciphertext);        //decrypting cipher text

    //cout << msg;
    cout << "ciphertext: " << ciphertext << endl;       //console output
    cout << "plaintext: "  << plaintext;

    ofstream fout;
    fout.open("out.txt");
    fout << "ciphertext: " << ciphertext << endl;       //write to file
    fout << "plaintext: " << plaintext;
    fout.close();

    return 0;
}
