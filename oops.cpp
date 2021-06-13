
1.//creating classes of students and product
class Student{
int age;
int rollno;
};

class Product{
int reg_no;
char name[100];
};

//To accesss them into we have to create an object
student s1;  //student is name of classs and s1 is the object
student s2;   //student is name of classs and s2 is the object

Product P1; //product is name of classs and p1 is the object



2.Creating objects from classes statically and dynamically

//dynamically -we have to allocate address when we have to go for address location of block by help of address

/*student.cpp*/
class Student{
public:
	int age;
	int rollno;
};

/*main.cpp file*/
#include<iostream>
using namespace std;
#include"student.cpp"   //jo bhi student .cpp ka code tah vo place hogya main file mei and we can use it
int main()
{
 //we have to create student file kei objects ko create kerna ha throug classes earlier  call by user
  Student s1;// create object statically
  Student s2;// create object statically
  //putting value in the objet by the help of object_name.property ka naam
  s1.age=10;
  s1.rollno=101;

  cout<<s1.age<<" " << s1.rollno;
 
  s2.age=23;
  cout<<s2.age;


//dynamically creation of block s6 where we have to pass address from a s6 to block
  Student *s6=new Student;
  //to enter value dynamically wwe have go for the (s6).age similarly for other
  (s6).age=10;
  (s6).rollno=102;
   s6->rollno=102;  s6.age=10;/arrpw sets the regrenced to particular block
  cout<<s6->age<<" "<<s6->rollno;

 
}


3.getters and setters

class student{

public:
 int rollno;
private:
 int age;

void display()
{
cout<<age<<" "<<rollno;   //we can access both of them because we can access private member within the class
};
void getage()    //As we have our private class we can within the class as age varible but in main file we have to pass this by calling
{    //getter (read the value from private class)
 return age;
}


/*main.cpp file*/
#include<iostream>
using namespace std;
#include"student.cpp"   //jo bhi student .cpp ka code tah vo place hogya main file mei and we can use it
int main()
{
 //we have to create student file kei objects ko create kerna ha throug classes earlier  call by user
  Student s1;// create object statically
  Student s2;// create object statically
  //putting value in the objet by the help of object_name.property ka naam
//  s1.age=10;
  s1.rollno=101;
  s1.display(); 
  cout<<s1.getage<<" " << s1.rollno;
 
 // s2.age=23;
  cout<<s2.getage;//beacuse in student class file we have private class
  s2.display();


  //dynamically creation of block s6 where we have to pass address from a s6 to block
  Student *s6=new Student;
  //to enter value dynamically wwe have go for the (s6).age similarly for other
//  (*s6).age=10;
  (*s6).rollno=102;
   s6->rollno=102;  
  //s6.age=10;/arrpw sets the regrenced to particular block
  cout<<s6->age<<" "<<s6->rollno;

  //call of function/method
  (*s6).display();
  s6->display();

 
}



class student{

public:
 int rollno;
private:
 int age;

void display()
{
cout<<age<<" "<<rollno;   //we can access both of them because we can access private member within the class
};
void getage()    //As we have our private class we can within the class as age varible but in main file we have to pass this by calling
{    //getter (read the value from private class)
 return age;
}
void setage(int a,int password) //setters (insert,return the value of input)
{	
	if(password!=123) 	//by this we are lossing some of the property of private class by setting them but we can add certain contion to make it secure
	{return;}   
	if(age<0)
	{return ;}
	age=a;
};



#include<iostream>
using namespace std;
#include "student.cpp"
int main()
{
	Student s1;
        Student *s2=new Student;
	s1.setage(20);   //setage is used for getting input of age bcz age in student class is private to access it we have to getters
	*s2->setage(23);

	s1.display();   //both age and roll no
	s2->display();
}

4.Constructor and destructor
------------------------------------------------------------------------------
class student{

public:
 int rollno;
private:
 int age;


//default constuctor
Student(){  		//constuctor for the class inbuild call in memoory
}
//parametised contructor
Student(int r){
	cout<<"constctor clled!!:";
	this->rollno=r;
}
//parametised contructor
Student(int r,int a)
{
	cout<<"constructor 3 called!!";
	this->age=a;
	this->rollno=r;	
}
void display()
{
cout<<age<<" "<<rollno;   //we can access both of them because we can access private member within the class
};
-----------------------------------------------------------------------------

#include<iostream>
using namespace std;
int main()
{	
	Student s1;  //default constructor if their has no inbuild constructor
	s1.display(); 
	stident 2;
	student *s3=new Student;
	s3->display();

	//parmaterized constructor
	student s4(20);
	s4.display();

	student s5(10,20);
	s5.display();

	//this is a keyword which holds the address of current object
	student s6(10,1001);
	

}

copy constructor
#include<iostream>
using namespace std;
#include"student.cpp"
int main()
{
	student s1(10,20);
	student s2;
	s2.age=s1.age;s2.rollno=s1.rollno; // copy method using opeartor of each rpoperty of object
 
	student s3(s1);//copy constructor

	student *s4=new student(s3);
	
	student *s5=new student(*s4);
}

//copy assignment opeartor (as the cntuctor call all one time whilw creation of object we can't mae use of it while we have go changes after constructor is formed to do this kind of operation we have to g for copy assignement
#include<iostream>
using namespace std;
#include"student.cpp"
int main()
{
	student s1(10,1001);
	student s2(11,1002);
	student *s3=new student(13,1003);

	*s3=s1;//statically to dynamic
	s2=s1;//statically to statically
	s1=*s3; //dynamic to staticlly
}

//destructor //when object leaves memory then destructr is called or exitisting from memory
/*->same name of as of class ,no return type,no input aarguments,denoted by ~object name(){}*/
/*student .cpp*/ 
/*In student class we hav constructor and destructor call khuse deaflut */
/*code*/
~student(){
	cout<<"I am the destructor";
}
#include<iostream>
using namespace std;
#include"student.cpp"
int main()
{
	student s1;student s2;		
	delete s2;
}


7.Play with constructors 
#include<iostream>
using namespace std;
#include"student.cpp"
int main()
{
	student s1;            //constructor 1 called
	student s2(20);         //constructor 2 called
	student s3(10,103);    //contructor 3rd called
	
	student s4(s3);  //copy constructor call deafult 
        s2=s1;     //copy assignemnt opeartion called from here no contructor call bcz it call when we have time of creation of object
	student s5=s3;  //in memory it runs as an copy cnstructor so it will also works
}

9.Fraction class
/*12/5  numerator adn denomentator*/
for this we have 2 datameenbers 

class Fraction{
	private:
		int num;
		int den;
	public:
	//for not any garbage value we can create constructor
	Fraction(int num,int den){
		cout<<this<<"this"<<endl;
		this->num=num;
		this->den=den;
	}
	void displpay()
	{
		cout<<this->num<<" /" <<this->den;
	}
	
	void add(Fraction f2)
	{
		lcm=this->den*f2.den;
		int a=this->num*(lcm/this->num);
		int b=f2.num*(lcm/f2.num);
		int this->num=a+b;  //mtlb ki f1 mei updatekerdo f1+f2 ki fractional value
		int this->den=lcm;   ////mtlb ki f1 mei updatekerdo f1+f2 ki fractional value
	
	}
	void multiply(Fraction const &f2)
	{	
		int a=this->num*f2.num;
		int b=this->den*f2.den;
		this->num=a;
		this->den=b;
	}

}



#include<iostream>
using namespace std;
#include"Fraction.cpp"
int main()
{	
	//make an f1 and f2 and use function 	
}

11.Complex numbers
class ComplexNumbers{
	private:
		int real;
		int imaginary;
	public:
	void ComplexNumbers(int real,int imaginary)
	{	
		this->real=real;
		this->imaginary=imaginary;
	}
	void display()
	{
		cout<<this->real<<" + i" <<this->imaginary;
	}
	void add(ComplexNumbers const &f1)
	{
		this->real=this->real+f2.real;	
		this->imaginary=this->imaginary+f2.imaginary;		
	}
	void multiply(ComplexNumbers const &f2)
	{
		this->real=this->real*f2.real;	
		this->imaginary=this->imaginary*f2.imaginary;
	}
		
}
