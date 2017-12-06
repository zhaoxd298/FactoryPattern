#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include "Pizza.h"

namespace Factory {

class PizzaStore
{
protected:
	virtual Pizza* createPizza(string type) = 0;
public:
	PizzaStore()
	{}
	virtual ~PizzaStore()
	{}
	Pizza* orderPizza(string type)
	{
		Pizza* pizza = createPizza(type);
		if (pizza == NULL)
        {
            return NULL;
        }
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}
};


class NYPizzaStore : public PizzaStore
{
protected:
	Pizza* createPizza(string type)	
	{
		if ("cheese" == type) {
			return new NYStyleCheesePizza();
		} else if ("veggie" == type) {
			return new NYStyleVeggiePizza();
		} else if ("clam" == type) {
			return new NYStyleClamPizza();
		} else if ("pepperoni" == type) {
			return new NYStylePepperoniPizza();
		} else {
			return NULL;
		}
	}
};

class ChicagoPizzaStore : public PizzaStore
{
protected:
	Pizza* createPizza(string type)	
	{
		if ("cheese" == type) {
			return new ChicagoStyleCheesePizza();
		} else {
			return NULL;
		}
	}
};

}

#endif
