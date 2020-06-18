#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Create an Interface for Product Objects
class IProducts
{
public:
	// Virtual Function to get the name of the product implementing the interface
	 virtual   const std::string getProductName() const  = 0;
	// Virtual Function to Display  the names of all components of a class implementing the interface
	virtual void DisplayComponents() = 0;
	// Virtual Function to display the values of the components of a class implementing the interface 
	virtual void Display() = 0;
	// Virtual Function to set the components to desired values 
	virtual void setAttributes() = 0;
};

// Concretion of Product Interface
class PC_Towers final : public IProducts
{
public:
	// Function to set the member variables of the class
	void setAttributes ()
	{
		
			std::cout << "Please enter Memory size for PC_Tower in GB : ";
			// MAke sure that the input in numeric
			while(!(std::cin >> this->Memory))
			{ 
				std::cout << "All input's must be numeric " << std::endl;

				break;
			}

			std::cout << "Please enter CPU size for PC_Tower in GHz : ";
			while (!(std::cin >> this->CPU))
			{

				std::cout << "All input's must be numeric " << std::endl;
				break;
			};
		 
		
		
		
	}
	// Function to get the Name of the product
	const std::string getProductName() const { return this->productName; }
	// Function to display the names of the components of the class
	void DisplayComponents() { std::cout<<"The Tower is composed from : 1) Memory  2) CPU " << std::endl; }
	// Function to display the values of the member variables
	void Display()
		{
		std::cout << "Your Tower has a Memory of " << this->Memory << " GB and a CPU of " << this->CPU << " GHZ" << std::endl;


		}
	

private:
	double Memory;
	double CPU;
	const std::string productName = "PC_Tower";
};

// Another concrition on the IProduct interface the same as the one before
class PC_Screen : public IProducts
{
public:
	void setAttributes () 
	{
		

		std::cout << "Please enter size of your Screen in inches: " ;
		while (!(std::cin >> this->Size_inch))
		{
			std::cout << "All input's must be numeric " << std::endl;
			break;


		}

		 
	
	}
	const std::string getProductName() const { return this->productName; }
	void DisplayComponents() { std::cout << "The screen is composed from a screen measured in inches " << std::endl; }
	void Display()
	{
		std::cout << "Your screen is " << this->Size_inch << " inches " << std::endl;


	}

private:
	double Size_inch;
	const std::string productName = "PC_Screen";
};
// Concrition of IProducts
class Personal_Computer : public IProducts
{
public:
	// Function to set the attributes of the member variable. In this case the function works as a decorator
	// arround the setAttributes of the IProduct adding functionalities to it
	void setAttributes() 
	{
		Tower.setAttributes();
		Screen.setAttributes();
		
		std::cout << " Please enter size of your HardDics in GB : " ;
		while (!(std::cin >> this->HardDisc))
		{
			std::cout << "All input's must be numeric " << std::endl;
			break;
		}
		
	
	
	}
	const std::string getProductName() const { return this->productName; }
	// Decorate the DisplayComponents() and add functionalities
	void DisplayComponents() 
	{ 
		std::cout << "Personal Computer is composed from: 1) Tower 2) PC Screen 3) Hard Disc" << std::endl;
		Tower.DisplayComponents();
		Screen.DisplayComponents();

	}
	// Decorate the Display() and add functionalities
	void Display()
	{
		Tower.Display();
		Screen.Display();
		std::cout << "Your Hard Disc has size : " << this->HardDisc << " GB " << std::endl;
	
	
	}


private:
	PC_Towers Tower;
	PC_Screen Screen;
	double HardDisc;
	const std::string productName = "Personal_Computer";
};

// Concretion of Iproduct
class Work_Station : public IProducts
{
public:
	void setAttributes()
	{
		Computer.setAttributes();
		
		std::cout << "Please Enter your Operating System " ;
		while (!(std::cin >> this->OperatingSystem))
		{
			std::cout << "Operating system must be string " << std::endl;
			break;
		}
		
	
	}
	const std::string getProductName() const  { return this->productName; }
	void DisplayComponents()
	{
		std::cout << "Work station is composed from : 1) Personal computer 2) Operating System (Linux or Windows) " << std::endl;
		Computer.DisplayComponents();
	}
	void Display()
	{
		Computer.Display();
		std::cout << "Your Operating System is :" << this->OperatingSystem << std::endl;
	
	}

private:
	Personal_Computer Computer;
	std::string OperatingSystem;
	std::string productName = "WorkStation";
};


