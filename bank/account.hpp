#include <iostream>
#include <vector>
#include <string> 
using namespace std;

class Account{
    private :
        vector<double> history;
        string name;
        double in_money,out_money,total;
        int idx_max = 10,last_index=0;
    
        void reset_index (){
            if (this->last_index>=idx_max){
                this->history.clear();
            }
        }
    public :
        void show_data ();
        void add_money (double x);
        void cash_out (double x);
        void change_name (string name);
        double sum_values ();
        vector <double> get_history();
        string get_name();
        double get_total();



};