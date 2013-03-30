#include "bank.h"
#include<cstring>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<QDebug>

bank :: bank()  {
    ifstream in ("accCount");
    if(in.is_open())
        in>>accCount;
    else
        accCount = 0;
    qDebug() << accCount;
    in.close();
}

bank :: bank(int key, char * fname, char * mname, char * lname, char * address, char * acc_no, char * mobile_no, long balance) {
    accCount = 0;
}

long t=643652;
char * bank :: createAccount( const char * fname, const char * mname, const char * lname, const char * address,
                           const char * mobile_no, const char *email, long balance) {

    strcpy(acc.fname, fname);
    strcpy(acc.mname, mname);
    strcpy(acc.lname, lname);
    strcpy(acc.address, address);

    t=t*rand();
    if(t%2)
        t=t-rand();
    else
        t=t+rand();
    if(t<0)
        t=-t;

    sprintf(acc.acc_no,"%ld", t);

    strcpy(acc.mobile_no, mobile_no);
    strcpy(acc.email, email);
    acc.balance = balance;
    acc.key = ++accCount;
    acc.rec_state = 1;

    fstream out ("accounts", ios::binary | ios::out | ios::app);
    out.write((char *) &acc, sizeof(account_info));
    out.close();

    return acc.acc_no;
}

account_info * bank :: searchAccount(char * key) {
    fstream searchFile ("accounts", ios::in | ios::binary);
    static account_info temp;
    while(searchFile) {
        searchFile.read((char *)&temp, sizeof(account_info));
        if(!strcmp(temp.acc_no, key) && temp.rec_state == 1) {
            searchFile.close();
            return &temp;
        }
    }
        searchFile.close();
    return NULL;
}

void bank :: deleteAccount(account_info *record) {
    int pos = record->key-1;
    record->rec_state = 0;
    fstream out("accounts", ios::binary|ios::out|ios::in);
    out.seekp(pos*sizeof(account_info),ios::beg);
    out.write((char *) record, sizeof(account_info));
    out.close();
}
void bank :: update(account_info *record,const char * fname, const char * mname, const char * lname, const char * address,
            const char * mobile_no, const char *email, long balance)
{
    account_info acc;
    strcpy(acc.fname, fname);
    strcpy(acc.mname, mname);
    strcpy(acc.lname, lname);
    strcpy(acc.address, address);
    strcpy(acc.mobile_no, mobile_no);
    strcpy(acc.email, email);
    acc.balance = balance;
    acc.key =record->key;
    acc.rec_state = 1;

    int pos=record->key-1;

    fstream in("accounts", ios::binary|ios::out|ios::in);
    in.seekp(pos*sizeof(account_info),ios::beg);
    in.write((char *) &acc, sizeof(account_info));
    in.close();

}

void bank :: printToFile() {
}

account_info bank :: readFromFile() {
    /*
    account_info accRead;
    in.read ( (char *)&accRead, sizeof(account_info) );
    return accRead;
    */
}

bank :: ~bank() {
    ofstream out("accCount", ios::out | ios::trunc);
    out<<accCount;
    out.close();
}
