#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>

void print_list(const std::list<int>& mylist)
{
    for (int i : mylist)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

void print_deque(const std::deque<int>& dq)
{
    for (int i : dq) 
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

int main()
{
	// deque
    std::cout << "deque" << std::endl;
    std::deque<int> dq = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 

    print_deque(dq);

    std::cout << dq.size() << std::endl;

    dq.erase(dq.begin() + 2);
    dq.erase(dq.begin() + 3);
    dq.erase(dq.begin() + 4);

	print_deque(dq);

    dq.push_front(10);

	print_deque(dq);

    dq.insert(dq.begin() + 4, 20);

	print_deque(dq);

    dq.push_back(30);

    print_deque(dq);
    
    // list
    std::cout << "list" << std::endl;
    std::list<int> mylist = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    print_list(mylist);

    std::cout << mylist.size() << std::endl;

    std::list<int>::iterator it;
    it = mylist.begin();
    std::advance(it, 2);
    it = mylist.erase(it);
    it = mylist.begin();
    std::advance(it, 3);
    it = mylist.erase(it);
    it = mylist.begin();
    std::advance(it, 4);
    it = mylist.erase(it);

	print_list(mylist);

    mylist.push_front(10);

	print_list(mylist);

    it = mylist.begin();
    std::advance(it, 4);
    it = mylist.insert(it, 20);

	print_list(mylist);

    mylist.push_back(30);

	print_list(mylist);
}
