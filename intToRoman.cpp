// Leetcode problem 12. Integer to Roman - July 2021
//Sriparna Majumdar
#include <iostream>
#include <cmath>
using namespace std;

string findromanChar(int n);
string intToRoman(int num);
string roman_char[] = {
             "I",
             "V",
             "X",
             "L",
             "C",
             "D",
             "M" };
         
int roman_num[] = {1, 5, 10, 50, 100, 500, 1000};
int length = 7;
        
int main() {
  std::cout << "Hello World!\n";
  // cout << findromanChar(500) << endl;
  cout << intToRoman(1994) << endl;
  cout << intToRoman(101) << endl;
};

// Return roman character matching an integer
 string findromanChar(int n){
            for (int i = 0; i < length; i++){
                if (roman_num[i] == n) {
                    return roman_char[i];
                }
            }
            return "";
        }   

// convert a number to a Roman character string
 string intToRoman(int num) {
          string roman = "";
          string str_num = to_string(num);
          int i = size(str_num) - 1;
          // cout << i << endl;
        
          while(i >= 0 && num != 0){
            int power = pow(10, i);
                         
            int digit = num / power;
            int temp = digit * power;            
            
            // cout << power << endl;
              
            if (digit <= 0){
                i--;
                continue;
            }
            // # V, L, D
            else if (size(findromanChar(temp)) > 0){
                roman = roman + findromanChar(temp);}
                
            // # if 90 + 10 == 100 print XC
            else if (size (findromanChar(temp + power)) > 0){
                roman = roman + findromanChar(power) + findromanChar(temp + power);
                }
               
            // # 6, 7, 8  print  V - VIII
            else if (digit > 5){
                roman = roman + findromanChar(5*power);
                int remain = digit - 5;
                
                while (remain > 0){
                  roman = roman + (findromanChar(power));
                  remain--;
                }
                }
           else if (size(findromanChar(power)) > 0){                
               while (digit > 0){
                  roman = roman + (findromanChar(power));
                  digit--;
                }
           }  
            num = num % power;
            i--;
            }
        return roman;        
    }