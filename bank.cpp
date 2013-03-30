#include "bank.h"
#include<cstring>
#include<iostream>
#include<fstream>

bank :: bank() : in ("accounts", ios::binary | ios::in ) {
    //fstream in("accounts");
    accCount = 0;
}

bank :: bank(int key, char * fname, char * mname, char * lname, char * address, char * acc_no, char * mobile_no, long balance) : in ("accounts", ios::binary | ios::in )	{
    accCount = 0;
}

void bank :: createAccount(/*const int key,*/ const char * fname, const char * mname, const char * lname, const char * address,
                           const char * acc_no, const char * mobile_no, const char *email, long balance) {
    strcpy(acc.fname, fname);
    strcpy(acc.mname, mname);
    strcpy(acc.lname, lname);
    strcpy(acc.address, address);
    strcpy(acc.acc_no, acc_no);
    strcpy(acc.mobile_no, mobile_no);
    strcpy(acc.email, email);
    acc.balance = balance;
    acc.key = ++accCount;
    acc.rec_state = 1;

    fstream out ("accounts", ios::binary | ios::out | ios::app);
    out.write((char *) &acc, sizeof(account_info));
    out.close();
}

account_info * bank :: searchAccount(int key) {
    fstream searchFile ("accounts", ios::in | ios::binary);
    static account_info temp ;
    while(searchFile) {
        searchFile.read((char *)&temp, sizeof(account_info));
        if(temp.key == key && temp.rec_state == 1) {
            searchFile.close();
            return &temp;
        }
    }
        searchFile.close();
    return NULL;
}

void bank :: deleteAccount(account_info *record) {
    int pos = record->key - 1;
    record->rec_state = 0;
    fstream out("accounts", ios::binary | ios::out | ios::in);
    out.seekp(pos*sizeof(account_info), ios::beg);
    out.write((char *)record, sizeof(account_info));
    out.close();
}

void bank :: printToFile() {
}

account_info bank :: readFromFile() {
    account_info accRead;
    in.read ( (char *)&accRead, sizeof(account_info) );
    return accRead;
}

bank :: ~bank() {
    in.close();
}
