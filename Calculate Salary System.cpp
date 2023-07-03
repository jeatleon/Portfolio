//Group 14 Assignment2
#include <iostream>
#include<iomanip>

using namespace std;

class factory//Base class
{
	public://Access specifier
		string mname;//Using string variable
		
		factory()//Default constructor
		{
			mname = "G14 Factory";//Set attribute value
		}
};

class calculate: public factory//First sub class derived from base class
{
	public://Access specifier
		int salary;//Using int variable
		
		void enters()//Function defined inside the class
		{
			cout<<" Enter Salary\t\t  : RM ";//Ask user to enter
			cin>>salary;
		}

		friend void cbonus(calculate);//Friend function
};

void cbonus(calculate s, float bonus, float &annual, float &gross)//To calculate bonus
{
	int b;//Using int variable
	
	annual = s.salary * 12;
	b= s.salary * bonus;
	gross = annual + b;
}

class employees: public factory//Second sub class derived from base class
{
	public://Access specifier
		string name;//Using string variable
		
		void entern()//Function defined inside the class
		{
			cout<<" Enter Name\t\t  : ";//Ask user to enter
			cin>>name;
		}
		
		friend void serviceYears(employees);//Friend function
};

void serviceYears(employees e, float &bonus)//To fine what grade
{
	int num;//Using int variable
	
	cout<<" Enter Your Service Years : ";//Ask user to enter
	cin>>num;
	
	//Using if else statements
	if(num <= 5){
		bonus = 0.5;//What is the grade of bonus
	}else
	if(num < 10 && num > 5){
		bonus = 0.75;
	}else
	if(num > 9){
		bonus = 1;
	}
}

void tax(float &total)//Create a function
{
	string name[4]= {"Social security tax", "Medicare tax", "Federal tax", "State tax"};//Using string array variable
	float *tax;//For using keyword new and delete
	
	for(int i=0; i<4; i++)//Using for loop
	{	
		tax = new float;//new operator
		cout<<" "<<i+1<<". "<<"Tax's Name : "<<name[i]<<endl;//Ask user to enter
		cout<<"   How Much of the Tax: RM ";
		cin>>*tax;
		total += *tax;//using operator to calculate total
		delete tax;//delete operator
	}//End loop
	
	cout<<" ----------------------------------------"<<endl;
	cout<<"\tTotal Tax : RM "<<fixed<<setprecision(2)<<total<<endl;
	cout<<" ----------------------------------------"<<endl<<endl;
}

void display()//Call function to displays all the information
{
	employees e;//Create an object of class employees
	calculate c;//Create an object of class calculate
	
	float bonus;//Using float variable
	
	cout<<" ----------------------------------------"<<endl;
	cout<<"               INFORMATION"<<endl;
	cout<<" ----------------------------------------"<<endl<<endl;
	e.entern();//Calling member of the derived class
	c.enters();//Calling member of the derived class
	serviceYears( e, bonus);//Calling friend of the derived class
	cout<<endl;
	
	cout<<" ----------------------------------------"<<endl;
	cout<<"                   TAX"<<endl;
	cout<<" ----------------------------------------"<<endl<<endl;
	float total;//Using float variable
	tax(total);//Call the function
	
	float annual, gross;//Using float variable

	cbonus(c, bonus, annual, gross);//Calling friend of the derived class
	
	cout<<endl;
	cout<<" ========================================"<<endl;
	cout<<"                  SALARY"<<endl;
	cout<<" ========================================"<<endl<<endl;
	
	//print out the result
	cout<<" Employee Name : "<<e.name<<endl;
	cout<<" Annual Salary : RM "<<fixed<<setprecision(2)<<annual<<endl;
	cout<<" Gross Salary : RM "<<fixed<<setprecision(2)<<gross<<endl;
	cout<<" Nett Salary : RM "<<fixed<<setprecision(2)<<gross - total<<endl;
}//End of function

int main()//Main function
{
	factory a;
	cout<<" ########################################"<<endl;
	cout<<"     Manufacturing Name : "<<a.mname<<endl;//Print attribute values
	cout<<" ########################################"<<endl<<endl;
	cout<<" ________________________________________"<<endl;
	cout<<"     Calculate Nett Salary System."<<endl;
	cout<<" ________________________________________"<<endl<<endl;
	
	display();//Calling function
	
	cout<<endl<<endl; 
	cout<<" ########################################"<<endl;
	cout<<"       THANK FOR USING OUR SYSTEM."<<endl;
	cout<<" ########################################"<<endl<<endl;
}//End of main
