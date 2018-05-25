/*************************************************************************
	> File Name: List.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月25日 星期五 09时30分20秒
 ************************************************************************/

#include <iostream>
#include <exception>
#include <stdexcept>
#include <memory>
#include <list>

using namespace std;

// inner type cannot be access by no-relation class.
// FIXME, test() has segment fault.
/*
 * 两种选择,一个抉择,
 * 一--使用裸指针,内部类,进行内存的显式管理
 * 二--使用智能指针,名字空间的类,进行内存的隐式管理
 *
 * 首选的是哪个. 第二个.
 *
 */

namespace sczzq{

template<class T>
struct Link {
	T val;
	std::unique_ptr<Link<T>> next;
};

template<class T>
class List{
	public:
		void insert(T);
		T get();
		int size = 0;
	private:
		struct Chunk{
			enum { chunk_size = 15 };
			Link<T> v[chunk_size];
			std::unique_ptr<Chunk> next;
		};
		std::unique_ptr<Chunk> allocated;
		std::unique_ptr<Link<T>> free;
		std::unique_ptr<Link<T>> get_free();
		std::unique_ptr<Link<T>> head;
};

// 成员函数的实现.
template<class T>
void List<T>::insert(T val)
{
	std::unique_ptr<Link<T>> lnk = get_free();
	lnk->val = val;
	lnk->next = std::move(head);
	head = std::move(lnk);
	if(size % 100000 == 0)
		std::cout << &(*head) << std::endl;
}

template<class T>
T List<T>::get()
{
	if(head == nullptr)
		throw std::underflow_error("list is underflow");

	std::unique_ptr<Link<T>> p = std::move(head);
	if(p->next)
		head = std::move(p->next);
	else
		head = nullptr;
	p->next = std::move(free);
	// here the content of p is moved out,
	// so, donnot use p anymore.
	free = std::move(p);
	return free->val;
}

template<class T>
typename std::unique_ptr<Link<T>> List<T>::get_free()
{
	if(free == nullptr){
		free = std::move(unique_ptr<Link<T>>(new Link<T>));
		free->val = T{};
		free->next = nullptr;
		size++;
	}

	// here, the content of free is moved out.
	std::unique_ptr<Link<T>> p = std::move(free);
	if(p->next)
		free = std::move(p->next);
	else 
		free = nullptr;
	return p;
}

};

using namespace sczzq;

/*
 * FIXME, segment fault.
 *
 */
int test()
{
	try{
		int i = 0, j = 0;
		std::cout << &i << std::endl;
		List<int> li;
		// the scope of variable.
		// if put temp here, its maxsize is 1000*1000*16,
		List<int> temp;

		std::cout << i << std::endl;
		while(j++ < 100){
//			List<int> temp;
			std::cout << j << std::endl;
			while(i++ < 1000){
				li.insert(i);
			}
			while(--i > 0){
				temp.insert(li.get());
			}
		}
		std::cout << "temp.size(): " << temp.size << std::endl;
		std::cout << "sizeof(temp): " << sizeof(temp) << std::endl;
//		std::cout << li.get() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

/*
 * 测试 std::list 是否会出现 test() 的情况.
 * list.front() 无边界检查, 不会抛出异常, 而会出现段错误.
 */
int test2()
{
	try{
		int i = 0, j = 0;
		std::list<int> li;
		std::list<int> temp;

		std::cout << "init size of li: " << li.size() << std::endl;
//		while(j++ < 1000){
			while(i++ < 10){
				li.insert(li.begin(), i);
			}
			std::cout << i << std::endl;
			while(--i > 0){
				temp.insert(temp.begin(), li.front());
				li.pop_front();
			}
//		}
		if(li.empty())
			std::cout << "li is empty" << std::endl;
		// if list is empty, access to front(), is undefined.
		// so, donot do this.
//		std::cout << li.front() << std::endl;
//		std::cout << li.size() << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	test();
//	test2();
}


