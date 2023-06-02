#include <iostream>
using namespace std;

#include "student.h"

int main(int argc, char* argv[]) {
 // argc should be always be in [multiple of 3] + 1(./student)
  int n= (argc-1)/3; //# of students
  student *pt_std  =  new student[n]; 
  // Declare pointer to an array size n of student objects
  
  int i;
  //./student monkey 20 3.5 Art 15 2.5
  // For the input values there should be 3 for every student,   in detail each should have (*name, *age, *score) 

  float highest_score = 0.0;
  for(i=1;i<argc;i+=3)   {
  (*pt_std).set_all(
  argv[i],          // for (*name)
  atoi(argv[i+1]),  // for (*age)
  atof(argv[i+2])); // for (*score)

  if(pt_std->get_score()>highest_score)  {
    highest_score=(*pt_std).get_score(); }
    pt_std++; // for the next student
  }
  
  pt_std-=n; // This moves the pointer back to the start
  
  /*purpose of this is to put them in 2 different loops*/
  for(i=0;i<n;i++){  
     // (*(pt_std+i)).print_all(); This is for Alt.
    // (pt_std+i)-> print

    pt_std->print_all();
    pt_std++;
  }    
  
  pt_std-=n; // This moves the pointer back to the start

  cout <<"\nStudents with the highest score" << endl;
  for(i=0;i<n;i++){
    if(pt_std->get_score()==highest_score){
       pt_std->print_all();
    }
    pt_std++;
  }
  pt_std-=n;  
  delete [] pt_std;
}

//Purpose of Assignment 5 is to print only students with the highest score.
  


