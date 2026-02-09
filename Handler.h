#include <iostream>
#include <string>

using namespace std;

struct two_real_numbers_config{
    string first;
    string second;
};



class Handler{
    public:
        static int print_and_get_choices(){
            // To DO
            cout << "Please choose one of the following options:" << endl;
            cout << "(1) Add" << endl;
            cout << "(2) Subtract" << endl;
            cout << "(3) Multiply" << endl;
            cout << "(4) Divide" << endl;
            cout << "(5) Conjugate" << endl;
            cout << "(6) Exit" << endl;
            int choice;
            cin >> choice;
            return choice;

        }
        static void add_two_complex_numbers(){
            // To DO
            two_real_numbers_config numbers = real_number_input("Adding");
            Complex c1 = parse_complex(numbers.first);
            Complex c2 = parse_complex(numbers.second);
            Complex result = c1 + c2;
            cout << "result is: " << result.toString() << endl;
        }
        static void subtract_two_complex_numbers(){
            // To DO
            two_real_numbers_config numbers = real_number_input("Subtract");
            Complex c1 = parse_complex(numbers.first);
            Complex c2 = parse_complex(numbers.second);
            Complex result = c1 - c2;
            cout << "result is: " << result.toString() << endl;
        }
        static void multiply_two_complex_numbers(){
            // To DO
            two_real_numbers_config numbers = real_number_input("Multiply");
            Complex c1 = parse_complex(numbers.first);
            Complex c2 = parse_complex(numbers.second);
            Complex result = c1 * c2;
            cout << "result is: " << result.toString() << endl;
        }
        static void divide_two_complex_numbers(){
            // To DO
            two_real_numbers_config numbers = real_number_input("Divide");
            Complex c1 = parse_complex(numbers.first);
            Complex c2 = parse_complex(numbers.second);
            Complex result = c1 / c2;
            cout << "result is: " << result.toString() << endl;
        }
        static void find_conjugate_of_a_complex_number(){
            // To DO
            cout << "Find the conjugate of a complex number:" << endl;
            cout << "Enter the number with out spaces (for example 2+i3): ";
            string input;
            cin >> input;
            Complex c = parse_complex(input);
            Complex result = c.conjugate();
            cout << "result is: " << result.toString() << endl;
        }

        static two_real_numbers_config real_number_input(string operation){
            cout << operation << " two complex numbers:" << endl;
            cout << "Enter the first number with out spaces (for example 2+i3): ";
            string first;
            cin >> first;
            cout << "Enter the second number with out spaces (for example 2+i3): ";
            string second;
            cin >> second;
            return two_real_numbers_config{first, second};
        }
        
        static Complex parse_complex(const string& s) {

            float real = 0.0f;
            float imag = 0.0f;

            // check if we have imaginary part
            // be aware: size_t is an unsigned int type, and it's the dedicated type for indexing in C++

            size_t i_pos = s.find('i');

            // when there is no imaginary part
            if (i_pos == string::npos) { // string::npos means we do not found the character, it's a special constant
                real = stof(s);
                return Complex(real, 0.0f);
            }

            // when there is imaginary part

            // get the sign of imaginary part
            size_t sign_pos = s.rfind('+', i_pos);
            if (sign_pos == string::npos)
                sign_pos = s.rfind('-', i_pos);

            // real part extraction
            if (sign_pos == string::npos) {
                // no real part
                real = 0.0f;
            } else {
                string real_part = s.substr(0, sign_pos); 
                if (!real_part.empty())
                    real = stof(real_part);
            }

            // imaginary part extraction
            string imag_part = s.substr(i_pos + 1);

            if (imag_part.empty()) // if there the imag_part is empty, then there is no number after 'i', it means the imaginary part is 1
                imag = 1.0f;
            else
                imag = stof(imag_part);

            // apply sign to imaginary part
            if (sign_pos != string::npos && s[sign_pos] == '-')
                imag = -imag;

            // create an instance of Complex and return
            return Complex(real, imag);
        }

};
