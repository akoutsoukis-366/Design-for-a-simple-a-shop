#pragma once
#include"Products.h"

class IUser 
{
public:
	IUser(const std::string myName, const double myPassword) { name = myName, password = myPassword; }
	const std::string getName() const
	{
		return name;
	}

	const double getPassword() const
	{
		return password;
	}
protected:
	std::string name;
	double password;
};

class Client : public IUser
{
public:
	Client(const std::string myName, double passWord) :IUser(myName, passWord) {};
	void buyProduct(std::shared_ptr<IProducts> currentProduct) { boughtProducts.push_back(currentProduct); }
	void checkOut() {
		for (size_t i = 0; i < boughtProducts.size(); ++i)
		{ 
			std::cout << "Your " << i + 1 << " bought product is " << boughtProducts[i]->getProductName() << " with the above charecteristics " << std::endl;
		    boughtProducts[i]->Display();
		}
	}
private:
	std::vector<std::shared_ptr<IProducts>> boughtProducts;

};