#include <iostream>
#include "Sequence.h"
#include "SequenceD.h"
#include "Utils.h"
#include "Decrypt.h"
#include "Crypt.h"





int main() {

    string inFile,outFile,key1String,key2String;
    unsigned int key1Left,key1Right,key2Left,key2Right;
    SequenceD<64> key1Seq,key2Seq;

    int choice;

    std::cout <<"Donner le nom du fichier en entree";
    std::cout<<std::endl;
    getline(cin, inFile);
    std::cout<<std::endl;

    std::cout <<"Donner le nom du fichier en sortie";
    std::cout<<std::endl;
    getline(cin, outFile);
    std::cout<<std::endl;

    std::cout <<"Donner la premiere cle en hexadecimal, la cle doit etre composee de 8 caractere au maximum";
    std::cout<<std::endl;
    getline(cin, key1String);
    key1Left = Utils::getDecFromHexString(key1String, true);
    key1Right = Utils::getDecFromHexString(key1String,false);

    std::cout <<"Donner la seconde cle en hexadecimal, la cle doit etre composee de 8 caractere au maximum";
    std::cout<<std::endl;
    getline(cin, key2String);
    key2Left = Utils::getDecFromHexString(key2String, true);
    key2Right = Utils::getDecFromHexString(key2String, false);



    std::cout<<"Que voulez vous faire ?\n1-Decrypter \n2-Crypter";
    std::cout<<std::endl;

    std::cin>>choice;

    Sequence s1 = Sequence(32);
    Sequence s2 = Sequence(32);

    s1 = key1Left;
    s2 = key1Right;

    key1Seq = SequenceD<64>(s1,s2);

    s1 = key2Left;
    s2 = key2Right;

    key2Seq = SequenceD<64>(s1,s2);


    if (choice == 1)
    {
        Decrypt decrypt = Decrypt(key1Seq,key2Seq);
        decrypt(inFile,outFile);
        std::cout<<"fichier decrypte";
    } else
    {
        Crypt crypt = Crypt(key1Seq,key2Seq);
        crypt(inFile,outFile);
        std::cout<<"fichier crypte avec succes";
    }
    


}

