#include <iostream>
#include <vector> 
#include "account.hpp"
#include <string>
using namespace std ;

class Operator {
    private :
        vector<Account> data;
        string name = "Airin",pw= "12345";
        bool status_log = false;

    
    public :
        void login_admin();
        void checking_to_next();
        void add_data (Account data);
        void delete_data ();
        void cs_operating ();
        void admin_operating();

};