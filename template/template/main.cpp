#include <iostream>
#include <string>
#include "Complex.h" // To DO
#include "Handler.h" // To DO
int main() {
    int user_choice=0;
    while(user_choice!=6){
        user_choice= Handler::print_and_get_choices();
        switch (user_choice){
        case 1:
            system("clear");
            Handler::add_two_complex_numbers();
            break;
        case 2:
            system("clear");
            Handler::subtract_two_complex_numbers();
            break;
        case 3:
            system("clear");
            Handler::multiply_two_complex_numbers();
            break;
        case 4:
            system("clear");
            Handler::divide_two_complex_numbers();
            break;
        case 5:
            system("clear");
            Handler::find_conjugate_of_a_complex_number();
            break;
        }
        cout<<"============================================"<<endl;
        cout<<"press enter key to continue.."<<endl;
        getchar();
        getchar();
        system("clear");
    }
}