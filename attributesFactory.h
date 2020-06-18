#pragma once
#include"Products.h"




class ConsoleInputAttributtes 
{
public:
	
	void setAttributtes(std::shared_ptr<IProducts> myProduct )
	{
		if (myProduct->getProductName() == "PC_Tower")
		{
			std::shared_ptr<PC_Towers> myTower = std::make_shared<PC_Towers>("PC_Tower");
			double memory;
			double CPU;
			std::cout << "Please enter Memory size for PC_Tower in GB : ";
			if (!(std::cin >> memory))
				std::cout << "All input's must be numeric " << std::endl;
			else
				myTower->setMemory(memory);

			std::cout << "Please enter CPU size for PC_Tower in GHz : ";
			if (!(std::cin >> CPU))
				std::cout << "All input's must be numeric " << std::endl;
			else
				myTower->setCPU(CPU);

			myProduct.reset();
			myProduct = myTower;
		}
		else if (myProduct->getProductName() == "PC_Screen")
		{
			std::shared_ptr<PC_Screen> myScreen = std::make_shared<PC_Screen>("PC_Screen");
			double screen;

			std::cout << "Please enter size of your Screen in inches: ";
			if (!(std::cin >> screen))
				std::cout << "All input's must be numeric " << std::endl;
			else
				myScreen->setScreen(screen);

			myProduct = myScreen;
		}
		else if (myProduct->getProductName() == "Personal_Computer")
		{
			std::shared_ptr<Personal_Computer> myComputer = std::make_shared<Personal_Computer>("Personal_Computer");
			double hardDisc;
			setAttributtes(myComputer->getTower());
			setAttributtes(myComputer->getScreen());

			std::cout << " Please enter size of your HardDics in GB : ";
			if (!(std::cin >> hardDisc))
				std::cout << "All input's must be numeric " << std::endl;
			else
				myComputer->setHardDisc(hardDisc);

			myComputer = myComputer;
		}
		else if (myProduct->getProductName() == "WorkStation")
		{
			std::shared_ptr<Work_Station> myWorkStation = std::make_shared<Work_Station>("WorkStation");
			std::string operatingSystem;
			setAttributtes(myWorkStation->getComputer());

			std::cout << "Please Enter your Operating System ";
			std::cin >> operatingSystem;
			myWorkStation->setOperatingSystem(operatingSystem);
			myProduct = myWorkStation;
		}
		else
			std::cout << "Can't find product";

	}
	
	



};