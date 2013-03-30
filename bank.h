#ifndef BANK_H
#define BANK_H

#include<fstream>

using namespace std;

struct account_info {
    int key;
    char fname[50], mname[50], lname[50], address[200], acc_no[20], mobile_no[10];
    char email[50];
    long balance;
    int rec_state;
};


class bank {
    account_info acc;
    int accCount;
    public :
        bank();
        bank(int key, char * fname, char * mname, char * lname, char * address, char * acc_no, char * mobile_no, long balance);

        char * createAccount(/*const int key, */const char * fname, const char * mname, const char * lname, const char * address,
                           /*const char * acc_no,*/ const char * mobile_no, const char *email, long balance);
        account_info * searchAccount(char * key);
        void deleteAccount(account_info *record);
        void printToFile();
        account_info readFromFile();

        void update(account_info *record,const char * fname, const char * mname, const char * lname, const char * address,
                    const char * mobile_no, const char *email, long balance);

        ~bank();
};

#endif
