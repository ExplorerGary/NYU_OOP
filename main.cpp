#include <iostream>
#include <string>
#include "Complex.h" // To DO
#include "Handler.h" // To DO

// replaced all system("clear") with system("cls") for Windows compatibility

int main() {
    int user_choice=0;
    while(user_choice!=6){
        user_choice= Handler::print_and_get_choices();
        switch (user_choice){
        case 1:
            system("cls");
            Handler::add_two_complex_numbers();
            break;
        case 2:
            system("cls");
            Handler::subtract_two_complex_numbers();
            break;
        case 3:
            system("cls");
            Handler::multiply_two_complex_numbers();
            break;
        case 4:
            system("cls");
            Handler::divide_two_complex_numbers();
            break;
        case 5:
            system("cls");
            Handler::find_conjugate_of_a_complex_number();
            break;
        }
        cout<<"============================================"<<endl;
        cout<<"press enter key to continue.."<<endl;
        getchar();
        getchar();
        system("cls");
    }
}