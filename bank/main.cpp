#include <iostream> 
#include <vector>
#include "operator.hpp"

using namespace std;

int main(){
    Operator *ope = new Operator();
    ope->admin_operating();
    delete ope;
    return 0;
}