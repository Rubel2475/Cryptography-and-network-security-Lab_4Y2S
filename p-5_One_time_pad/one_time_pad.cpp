#include<bits/stdc++.h>
using namespace std;


string encryption(string msg){

    string cipher="";
    string pad;

    ifstream rand_str;
    rand_str.open("random_string.txt");
    rand_str >> pad;

    for(int i=0; i<msg.size(); i++){

        if(isupper(msg[i])){
            cipher += char(((msg[i]-'A') + (pad[i]-'A')) %26 + 'A');
        }
        else if(islower(msg[i])){
            cipher += char(((msg[i]-'a') + (pad[i]-'A')) %26 + 'a');
        }
        else{
            cipher += msg[i];
        }   
    }

    rand_str.close();

    return cipher;
}

string decryption(string cipher){

    string msg="", pad;

    ifstream rand_str("random_string.txt");
    rand_str >> pad;

    for(int i=0; i<cipher.length(); i++){
        
        if(isupper(cipher[i])){
            msg += char(((cipher[i]-'A') - (pad[i]-'A') +26) % 26 + 'A');
        }
        else if(islower(cipher[i])){
            msg += char(((cipher[i]-'a') - (pad[i]-'A') +26) % 26 + 'a');
        }
        else{
            msg += cipher[i];
        }
    }

    rand_str.close();

    return msg;
}


int main(){

    string msg, cipher, decrypted_msg;

    ifstream in("in.txt");
    getline(in,msg);
    in.close();

    cipher = encryption(msg);
    decrypted_msg = decryption(cipher);

    ofstream out;
    out.open("out.txt");
    out << "Plaintext: " << msg << endl;
    out << "Encrypted: " << cipher << endl;         //file output
    out << "Decrypted: " << decrypted_msg << endl;
    out.close();


    cout << "Plaintext: " << msg << endl;
    cout << "Encrypted: " << cipher << endl;        //console output
    cout << "Decrypted: " << decrypted_msg << endl;

    return 0;
}