#include <vector>
#include <iostream> 
#include "account.hpp"

using namespace std;

double Account::sum_values(){
    double total=0;
    for (int i =0; i<this->history.size(); i++){
        total+= this->history[i];
    }
    this->total += total;
    return total;
}

void Account::show_data(){
    cout<<"Name \t : "<<this->name<<endl;
    cout<<"############ History ###########"<<endl;
    cout<<"No.\t |"<<"money history"<<endl;
    for (int i =0 ; i<this->history.size(); i++){
        cout<<i+1<<". |"<<this->history[i]<<endl;
    }
    cout<<"----------------------------------------"<<endl;
    cout<<"Total : "<<this->sum_values()<<endl;
    cout<<"----------------------------------------"<<endl;
    
}

void Account::change_name(string name){
    this->name = name;
}
void Account::add_money(double x){
    this->history.push_back(x);
    this->last_index +=1;
    this->reset_index();
}
void Account::cash_out(double x){
    this->total-=x;
    this->last_index+=1;
    this->history.push_back(-1 * x);
}
vector <double> Account::get_history(){
    return this->history;
}
string Account::get_name(){
    return this->name;
}
double Account::get_total(){
    return this->total;
}