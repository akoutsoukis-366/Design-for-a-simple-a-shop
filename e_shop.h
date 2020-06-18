#pragma once
#include"Products.h"

// Class e-shop to add and display all the products of the shop
class e_shop
{
public:
	// Function to add products to the shop
	void addProduct(std::shared_ptr<IProducts>newProduct) { this->allProducts.push_back(newProduct); }
	// Function to display all the products of the shop
	void desplayAllProducts()
	{

		for (auto e:allProducts)
			std::cout << e->getProductName() << std::endl;
	}
private:
	// vector to keep all the products of the shop
	std::vector< std::shared_ptr<IProducts> > allProducts;
};
