#include "Fraction.h"

int main() {
  
    Fraction fr1(3, 4); 
    fr1.privedenieKnesokrat();
    fr1.OutputFraction();
    
    Fraction fr2(-50,5);
    fr2.privedenieKnesokrat();
    fr2.OutputFraction();
    
   
Fraction sum=fr1+fr2;//sum
std::cout << " summa:" << std::endl;
sum.OutputFraction(); //output


    Fraction s=fr1-fr2;
std::cout << " raznost':" << std::endl;
s.OutputFraction(); 



      Fraction f=fr1*fr2;
std::cout << " umnozheniye:" << std::endl;
f.OutputFraction(); 

        
          Fraction n=fr1/fr2;
std::cout << " deleniye:" << std::endl;
n.OutputFraction(); 




std::cout << " sravneniye drobey:" << std::endl;



bool flag=fr1==fr2;
if(flag){
    std::cout <<" fr1=fr2" << std::endl;
}
else{
  std::cout << "fr1!=fr2 "<< std::endl;  
}



bool fl=fr1!=fr2;//(!= test)
if(fl){
    std::cout << "fr1!=fr2" << std::endl;
}
else{
    std::cout << "fr1=fr2" << std::endl;
}


bool fl1=fr1<fr2;
if (fl1){
    std::cout << "fr1<fr2" << std::endl;
}
else{
    std::cout << "fr1!<fr2" << std::endl;
}


bool fl2=fr1>fr2;
if (fl1){
    std::cout << "fr1>fr2" << std::endl;
}
else{
    std::cout << "fr1!>fr2" << std::endl;
}


std::cout << " my wonderfull  unique methods" << std::endl;
//uniq methds
bool fl3=fr1<<fr2;
if (fl1){
    std::cout << "fr2.numerator is bigger" << std::endl;
}
else{
    std::cout << "fr2.numerator is not bigger" << std::endl;
}


bool fl4=fr1<<fr2;
if (fl1){
    std::cout << "fr2.denomirator is bigger" << std::endl;
}
else{
    std::cout << "fr2.denomirator is not bigger" << std::endl;
}




    Fraction f1; 
    f1 = f1.InputFraction(); 
    f1.OutputFraction(); 






    
  

    return 0;
}
