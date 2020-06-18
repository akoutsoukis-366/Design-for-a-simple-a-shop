#include "Products.h"
#include "e_shop.h"
#include"ProductsFactory.h"
#include "User.h"
int main()
{
	Client first("Aris", 12345);
	// create some products
	std::shared_ptr< IProducts > Product1 = std::make_shared<PC_Towers>();
	std::shared_ptr< IProducts > Product2 = std::make_shared<PC_Screen>();
	std::shared_ptr< IProducts > Product3 = std::make_shared<Personal_Computer>();
	std::shared_ptr< IProducts > Product4 = std::make_shared<Work_Station>();
	// create an e-shop and add the products created
	e_shop myEshop;
	myEshop.addProduct(Product1);
	myEshop.addProduct(Product2);
	myEshop.addProduct(Product3);
	myEshop.addProduct(Product4);
	myEshop.desplayAllProducts();
	std::string finish;
	 
	while(finish != "N" )
	{ 
	std::string choosedProduct;
	std::cout << std::endl;
	std::shared_ptr<IProducts> myProduct = nullptr;
	UserInputFactoryProduct ProductFactory;
	
	// choose a product and use factory to create the object based on the user input
	while (myProduct == nullptr )
	{
		std::cout << "Chose one of the above products : ";
		std::cin >> choosedProduct;

		myProduct = ProductFactory.createProduct(choosedProduct);
		
	} ;
	
	
	// display all the attributes of the product
	myProduct->DisplayComponents();
	// let the user to add values to components
	myProduct->setAttributes();
	// display the product ith the values of the user
	first.buyProduct(myProduct);
	std::cout << "Do you want to continue: Y or N :" ;
	std::cin >> finish;
	
	}
	std::cout << first.getName() << " bought :" << std::endl;
	first.checkOut();
	int c = getchar();
}
