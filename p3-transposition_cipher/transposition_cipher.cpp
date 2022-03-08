#include<bits/stdc++.h>
using namespace std;


string Encrypt(string msg, int width){
    string cipher="";

    //int rows = ceil(msg.size()/(double)width);
    //cout << rows;
    int remainder = msg.size()%width;
    int trailing_spaces = width - remainder;

    for(int k=0; k<trailing_spaces; k++){
        msg += "$";         //using $ for extra spaces(that's not included in original text
    }

    for(int i=0; i<width; i++){
        for(int j=i; j<msg.size(); j+=width ){
            cipher += msg[j];
        }
    }

    return cipher;
}

string Decrypt(string cipher, int width){
    string plaintext ="";

    //int rows = ceil(msg.size()/(double)width);
    int rows = cipher.size()/width;

    for(int i=0; i<rows; i++){
        for(int j=i; j<cipher.size(); j+=rows){
            plaintext += cipher[j];
        }
    }

      //Removing Trailing Spaces
      int extra_spaces=0;
      for(int k=plaintext.size()-1; k>=0; k--){
        if(plaintext[k]=='$'){
            extra_spaces++;
        }else{
            break;
        }
      }
      plaintext = plaintext.substr(0, plaintext.size()-extra_spaces);

    return plaintext;
}


int main(){

    string msg, cipher;
    int width;

    cout<<"Enter Table Width: ";
    cin>>width;

    ifstream fin;
    fin.open("in.txt");
    getline(fin, msg);
    fin.close();

    cipher = Encrypt(msg, width);
    cout << "ciphertext: " << cipher << endl;
    msg = Decrypt(cipher, width);
    cout << "plaintext: " << msg << endl;

    ofstream fout;
    fout.open("out.txt");
    fout<<"Encrypted: "<<cipher<<endl;
    fout<<"Decrypted: "<<msg<<endl;
    fout.close();

    return 0;
}
