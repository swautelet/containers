#ifndef PRINT_MAP_HPP
# define PRINT_MAP_HPP

#include "Map.hpp"

template <class A, class B>
void    print_node(map_node<A, B>* x){
	if (!x){
		std::cout << "this is not a node but a null pointer " << std::endl;
		return ;
	}
	if (x->getParent())
		std::cout << "i have a parent : " << x->getParent()->First() << "    ";
	if (x->getChild_l() && x->getChild_r())
		std::cout << x << " : " << x->First() << "	this node has two child : " << x->getChild_l()->First() << " and " << x->getChild_r()->First() << std::endl;
	else if (x->getChild_r())
		std::cout << x << " : " << x->First() << "	this node has only a right child : " << x->getChild_r()->First() << std::endl;
	else if (x->getChild_l())
		std::cout << x << " : " << x->First() << "	this node has only a left child : " << x->getChild_l()->First() << std::endl;
	else 
		std::cout << x << " : " << x->First() << "	this node has no child : " << std::endl;
	// std::cout << " first : " << x->First() << " second : " << x->Second() << std::endl;
	if (x->getChild_l())
		print_node(x->getChild_l());
	if (x->getChild_r())
		print_node(x->getChild_r());
}



#endif