#include <iostream>
#include "Array.h"

int main (int argc, char * argv []){

  Array a1(); 
  Array a2(5);
  Array a3(5 , 's'); 

  a2.set(4 , 'g');
  std::cout << a2.get(4) << std::endl;
  a2.resize(2);
  std::cout << a2.find('g') << std::endl;

  a3.set(2 , 'g');
  std::cout << a3.get(0);
  std::cout << a3.get(1);
  std::cout << a3.get(2);
  std::cout << a3.get(3);
  std::cout << a3.get(4) << std::endl;
  std::cout << a3.find('g') << std::endl;
  std::cout << a3.find('g' , 3) << std::endl;

  Array a4(a3);
  std::cout << a4.get(0);
  std::cout << a4.get(1);
  std::cout << a4.get(2);
  std::cout << a4.get(3);
  std::cout << a4.get(4) << std::endl;

  a3.set(0 , 'a');
  a3.set(1 , 'b');
  a3.set(2 , 'c');
  a3.set(3 , 'd');
  a3.set(4 , 'e');
  std::cout << a3.get(0);
  std::cout << a3.get(1);
  std::cout << a3.get(2);
  std::cout << a3.get(3);
  std::cout << a3.get(4) << std::endl;
  a3.reverse();
  std::cout << a3.get(0);
  std::cout << a3.get(1);
  std::cout << a3.get(2);
  std::cout << a3.get(3);
  std::cout << a3.get(4) << std::endl;

  a3.fill('a');
  std::cout << a3.get(0);
  std::cout << a3.get(1);
  std::cout << a3.get(2);
  std::cout << a3.get(3);
  std::cout << a3.get(4) << std::endl;

  a3.resize(3);
  a3.shrink();

  a2.resize(9);
  a2.set(0 , 's');
  a2.set(1 , 'a');
  a2.set(2 , 'l');
  a2.set(3 , 'v');
  a2.set(4 , 'a');
  a2.set(5 , 't');
  a2.set(6 , 'o');
  a2.set(7 , 'r');
  a2.set(8 , 'e');
  Array a5 = a2.slice(3);
  std::cout << a5.get(0);
  std::cout << a5.get(1);
  std::cout << a5.get(2);
  std::cout << a5.get(3);
  std::cout << a5.get(4);
  std::cout << a5.get(5) << std::endl;

  Array a6 = a2.slice(3 , 5);
  std::cout << a6.get(0);
  std::cout << a6.get(1);
  std::cout << a6.get(2) << std::endl;

  Array a7(3 , 't');
  Array a8(2);

  if(a7 == a8){
    std::cout << "TRUE" << std::endl;
  }
  else if(a7 != a8){
    std::cout << "FALSE" << std::endl;
  }
  else{
    std::cout << "SOMETHINGS SCUFFED" << std::endl;
  }

  a8 = a7;

  if(a7 == a8){
    std::cout << "TRUE" << std::endl;
  }
  else if(a7 != a8){
    std::cout << "FALSE" << std::endl;
  }
  else{
    std::cout << "SOMETHINGS SCUFFED" << std::endl;
  }

  return 0; 

}
