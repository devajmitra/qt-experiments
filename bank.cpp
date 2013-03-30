#include "bank.h"
#include<cstring>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<QDebug>

/*bank :: bank()  {
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
void bank :: updateAccount(account_info *record,const char * fname, const char * mname, const char * lname, const char * address,
            const char * mobile_no, const char *email, long balance)
{
    account_info acc;
    strcpy(acc.fname, fname);
    strcpy(acc.mname, mname);
    strcpy(acc.lname, lname);
    strcpy(acc.address, address);
    strcpy(acc.mobile_no, mobile_no);
    strcpy(acc.email, email);
    strcpy(acc.acc_no, record->acc_no);
    acc.balance = balance;
    acc.key =record->key;
    acc.rec_state = 1;

    int pos=record->key-1;

    fstream in("accounts", ios::binary|ios::out|ios::in);
    in.seekp(pos*sizeof(account_info),ios::beg);
    in.write((char *) &acc, sizeof(account_info));
    in.close();

}*/

bank :: bank() {
    accCount = 0;
    int i;
    fstream a;
    account_info ac;
    ac.rec_state=1;

    fstream st("accounts",ios::binary|ios::in);
    if(!st.is_open())
    {
        a.open("accounts",ios::binary|ios::out);
       for(i=0;i<100;i++)
          {
       a.write((char *) &ac,sizeof(account_info));
        }
        a.close();
    }
    else
    {
        st.close();
    }
}

bank :: bank(int key, char * fname, char * mname, char * lname, char * address, char * acc_no, char * mobile_no, long balance) {
    accCount = 0;

    int i;
    fstream a;
    account_info ac;
    ac.rec_state=1;

    a.open("accounts",ios::binary|ios::out);
    for(i=0;i<100;i++)
    {
        a.write((char *) &acc,sizeof(account_info));
    }
    a.close();
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
    acc.rec_state = 0;

    account_info a;
    int h1,j=0;

    h1=t%100;
    qDebug()<<h1;
    do
    {
    fstream in("accounts", ios::in | ios::binary);
    in.seekg(h1*sizeof(account_info),ios::beg);
    in.read((char *) &a,sizeof(account_info));
    in.close();
    if(a.rec_state==1)
    {
    fstream out ("accounts", ios::binary | ios::out|ios::in);
    out.seekp(h1*sizeof(account_info),ios::beg);
    out.write((char *) &acc, sizeof(account_info));
    out.close();
    break;
     }
    else
    {
        h1=((h1+1)%100);
    }
    }while(j==0);

    return acc.acc_no;
}
 account_info a1;
account_info * bank :: searchAccount(char * key) {

    int h1,k1,j=0;
    //fstream searchFile ("accounts", ios::in | ios::binary);

    qDebug()<<key;
    sscanf(key,"%ld", &k1);
    qDebug()<<k1;
    h1=(k1%100);
    qDebug()<<h1;

    for(j=0;j<100;j++)
    {
    fstream in("accounts", ios::in | ios::binary);
    in.seekg(h1*sizeof(account_info),ios::beg);
    in.read((char *) &a1,sizeof(account_info));
    in.close();
    if(!strcmp(a1.acc_no,key) && a1.rec_state == 0)
    {
       qDebug()<<a1.acc_no;
         return &a1;
     }
    else
    {
        h1=((h1+1)%100);
    }
    }

    /*while(searchFile) {
        searchFile.read((char *)&temp, sizeof(account_info));
        if(!strcmp(temp.acc_no, key) && temp.rec_state == 0) {
            searchFile.close();
            return &temp;
        }
    }
       searchFile.close();*/
    return NULL;
}

void bank :: deleteAccount(account_info *record) {
    int h1;
    long k1;
qDebug()<<record->acc_no;
    sscanf(record->acc_no,"%ld", &k1);
qDebug()<<k1;
    h1=(k1%100);
qDebug()<<h1;
    record->rec_state = 1;
    fstream out("accounts", ios::binary|ios::out|ios::in);
    out.seekp(h1*sizeof(account_info),ios::beg);
    out.write((char *) record, sizeof(account_info));
    out.close();
}
void bank :: updateAccount(account_info *record,const char * fname, const char * mname, const char * lname, const char * address,
            const char * mobile_no, const char *email, long balance)
{
    int h1;
    long k1;

    account_info acc;
    strcpy(acc.fname, fname);
    strcpy(acc.mname, mname);
    strcpy(acc.lname, lname);
    strcpy(acc.address, address);
    strcpy(acc.mobile_no, mobile_no);
    strcpy(acc.email, email);
    strcpy(acc.acc_no, record->acc_no);
    acc.balance = balance;
    acc.key =record->key;
    acc.rec_state = 0;

    sscanf(record->acc_no,"%ld", &k1);
    h1=(k1%100);

    fstream in("accounts", ios::binary|ios::out|ios::in);
    in.seekp(h1*sizeof(account_info),ios::beg);
    in.write((char *) &acc, sizeof(account_info));
    in.close();

}

void bank :: printToFile() {
}

account_info bank :: readFromFile() {
}

bank :: ~bank() {
    ofstream out("accCount", ios::out | ios::trunc);
    out<<accCount;
    out.close();
}
