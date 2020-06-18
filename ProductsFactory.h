#pragma once
#include"Products.h"

class IProductFactory
{
public:
	virtual std::shared_ptr<IProducts> createProduct(std::string) = 0;

};
// Concretion of Interface for IProduct creation. This Factory produces IProducts based on the an string input 
// to the function ( like a user input)
class UserInputFactoryProduct : public IProductFactory
{
public:

	std::shared_ptr<IProducts> createProduct(std::string myProduct)
	{
		std::shared_ptr<IProducts> product;
		if (myProduct == "PC_Tower")
			product = std::make_shared<PC_Towers>();
		else if (myProduct == "PC_Screen")
			product = std::make_shared<PC_Screen>();
		else if (myProduct == "Personal_Computer")
			product = std::make_shared<Personal_Computer>();
		else if (myProduct == "WorkStation")
			product = std::make_shared<Work_Station>();
		else
			product = nullptr;

		return product;

	}


};

