#ifndef BANK_H
#define BANK_H

#include<fstream>

using namespace std;

struct account_info {
    int key;
    char fname[50], mname[50], lname[50], address[200], acc_no[10], mobile_no[10];
    // char email[50];
    long balance;
    int rec_state;
};


class bank {
    account_info acc;
    fstream in;
    public :
        bank();
        bank(int key, char * fname, char * mname, char * lname, char * address, char * acc_no, char * mobile_no, long balance);

        void createAccount(const int key, const char * fname, const char * mname, const char * lname, const char * address,
                           const char * acc_no, const char * mobile_no, /*const char *email,*/ long balance);
        account_info * searchAccount(int key);
        void printToFile();
        account_info readFromFile();

        ~bank();
};

#endif
