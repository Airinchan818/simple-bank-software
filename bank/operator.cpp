#include "operator.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

void Operator::checking_to_next(){
    if (this->status_log==true){
        cout<<"login succes"<<endl;
    }else{
        this->login_admin();
    }
}
void Operator::login_admin(){
    string name,pw;
    cout<<"Name : ";
    cin>>name;
    cin.ignore();
    cout<<"password : ";
    cin>>pw;
    cin.ignore();

    if (this->name==name && this->pw == pw){
        this->status_log = true;
    }else{
        this->status_log = false;
    }
    this->checking_to_next();
}

void Operator::add_data(Account data){
    this ->data.push_back(data);
}
void Operator::delete_data(){
    int idx=0,index;
    cout<<"No |"<<"\t Name"<<endl;
    for (Account ac : this->data){
        cout<<idx<<". |"<<ac.get_name()<<" |"<<endl;
        idx +=1;
    }
    cout<<"delete by index :";
    cin>>index;
    this->data.erase(this->data.begin() + index);
}

void Operator::cs_operating(){
    bool run=true;

    while(run){
        cout<<"############ Bank Account #############"<<endl;
        cout<<"index | "<<" Name \t\t "<<"account_total"<<endl;
        int i =0;
        for (Account ac : this->data){
            cout<<i<<". |"<<" "<<ac.get_name()<<"\t"<<ac.get_total()<<endl;
            i+=1;
        }
        int idx;
        cout<<"choice account at index : ";
        cin>>idx;
        bool r = true;
        while(r) {
            this->data[idx].show_data();
            cout<<endl;
            cout<<"edit Action : "<<endl;
            cout<<"0. quit"<<endl;
            cout<<"1. change name"<<endl;
            cout<<"2. add cash"<<endl;
            cout<<"3. out cash"<<endl;

            int ac; 
            cout<<"choice action :";
            cin>>ac;
            switch (ac)
            {
                case 0:
                    r = false;
                    break;
                case 1 :
                    
                    try
                    {   
                        string Name;
                        cout<<"Input Name : ";
                        cin>>Name;
                        cin.ignore();
                        this->data[idx].change_name(Name);
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                        cout<<"Maybe program crash because invalid input"<<endl;
                    }
                    

                    break;
                
                case  2:
                    
                    try
                    {   
                        double x;
                        cout<<"input cas : ";
                        cin>>x;
                        this->data[idx].add_money(x);
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                        cout<<"Maybe program crash cause invalid input"<<endl;
                    }
                    
                    break;
                case 3 :
                    
                    try
                    {   
                        double x;
                        cout<<"Input cash : ";
                        cin>>x;
                        this->data[idx].cash_out(x);
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                        cout<<"program crash maybe cause invalid input"<<endl;
                    }
                    break;
                default:
                    cout<<"Choice operation not valid"<<endl;     
            }
            

        }
        run = false;
    }
}

void Operator::admin_operating(){
    bool run = true;
    vector<string> menu = {
        "add account","delete account","edit account","quit"
    };
    while (run){

      if (this->status_log == false){
        this->login_admin();
      }else{
            int i=0;
            cout<<"No. |"<<" Name"<<endl;
            for (Account ac : this->data){
                cout<<i+1<<". "<<ac.get_name()<<endl;
                i+=1;
            }
            cout<<"################### Tools Menu ##################"<<endl;
            for (int i = 0; i<menu.size(); i++){
                cout<<i<<". "<<menu[i]<<endl;
            } 
            int choice ; 
            cout<<"choice tools execution : ";
            cin>>choice;
            switch (choice)
            {
            case 0:
                try
                {
                    Account new_ac = Account();
                    string name;
                    double cash_start,out=0;
                    cout<<"Input name : ";
                    cin>>name;
                    cin.ignore();
                    cout<<"start cash at : ";
                    cin>>cash_start;
                    new_ac.change_name(name);
                    new_ac.add_money(cash_start);
                    new_ac.cash_out(out);
                    this->add_data(new_ac);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                    cout<<"Program crash maybe invalid input or something wrong on program"<<endl;
                }
                
                break;
            
            case 1 :
                try
                {
                    this->delete_data();
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                    cout<<"Program crash may system error "<<endl;
                }
                break;
            
            case 2 :
                try
                {
                    this->cs_operating();
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                    cout<<"Program error or invlid input"<<endl;
                }
                break;
            
            case 3 :
                run = false;
                break;
                
            
            default:
                cout<<"The choice protocol not aivable"<<endl;
                break;
            }
        }
    }

}