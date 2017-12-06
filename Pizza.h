#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include <list>


using namespace std;

namespace Factory {

class Pizza 
{
protected:
	string m_name;
	string m_dough;
	string m_sauce;
	list<string> m_toppings;
public:
	Pizza() {}
	virtual ~Pizza() {}
	virtual void prepare()
	{
		cout << "Preparing " << m_name << endl;
		cout << "Tossing dough..." << endl;
		cout << "Adding sauce..." << endl;
		cout << "Adding toppings:" << endl;
		list<string>::iterator i;
		for (i=m_toppings.begin(); i!=m_toppings.end(); i++) {
			cout << *i << endl;
		}
	}
	virtual void bake() 
	{
		cout << "Bake for 25 minutes at 350" << endl;
	}	
	virtual void cut() 
	{
		cout << "Cutting the pizza into diagonal slices" << endl;
	}
	virtual void box()
	{
		cout << "Place pizza in official PizzaStore box" << endl;
	}
	virtual string getName()
	{
		return m_name;
	}
};

class NYStyleCheesePizza : public Pizza
{
public:
	NYStyleCheesePizza()
	{
		this->m_name = "NY Style Sauce and Cheese Pizza";
		this->m_dough = "Thin Crust Dough";
		this->m_sauce = "Marinara Sauce";

		this->m_toppings.push_back("Grated");
		this->m_toppings.push_back("Reggiano");
		this->m_toppings.push_back("Cheese");
	}
};

class NYStylePepperoniPizza : public Pizza
{
public:
	NYStylePepperoniPizza()
	{
		this->m_name = "NY Style Pepperoni Pizza";
		this->m_dough = "Pepperoni Dough";
		this->m_sauce = "Pepperoni Sauce";

		this->m_toppings.push_back("Grated_p");
		this->m_toppings.push_back("Reggiano_p");
		this->m_toppings.push_back("Cheese_p");
	}
};

class NYStyleClamPizza : public Pizza 
{
public:
	NYStyleClamPizza()
	{
		this->m_name = "NY Style Clam Pizza";
		this->m_dough = "Clam Dough";
		this->m_sauce = "Clam Sauce";

		this->m_toppings.push_back("Grated_c");
		this->m_toppings.push_back("Reggiano_c");
		this->m_toppings.push_back("Cheese_c");
	}
};

class NYStyleVeggiePizza : public Pizza
{
public:
	NYStyleVeggiePizza()
	{
		this->m_name = "NY Style Veggie Pizza";
		this->m_dough = "Veggie Dough";
		this->m_sauce = "Veggie Sauce";

		this->m_toppings.push_back("Grated_v");
		this->m_toppings.push_back("Reggiano_v");
		this->m_toppings.push_back("Cheese_v");
	}
};

class ChicagoStyleCheesePizza : public Pizza
{
public:
	ChicagoStyleCheesePizza()
	{
		this->m_name = "Chicage Style Deep Dish Cheese Pizza";
		this->m_dough = "Extra Thick Crust Dough";
		this->m_sauce = "Plum Tomato Sauce";

		this->m_toppings.push_back("Shredded");
		this->m_toppings.push_back("Mozzarella");
		this->m_toppings.push_back("Cheese");
	}

	void cut()
	{
		cout << "Cutting the pizza into square slices" << endl;
	}
};

}


#endif
