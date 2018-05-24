/*************************************************************************
	> File Name: test_unique_ptr.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月15日 星期二 11时36分20秒
 ************************************************************************/

#include <iostream>

#include <memory>
#include <vector>

/*
 * 使用成对的构造/析构函数进行资源管理
 * 资源依赖于所属的对象,而不会超过对象的声明周期.
 *
 * 通常使用抛出和捕获异常进行错误处理.
 *
 * 注意 unique_ptr 不具有拷贝语义,只有构造和移动语义.
 *
 * 注意 unique_ptr 作用是资源管理,而不是数据竞争.
 */

class A{
	int id = 0;
	public:
		A(int i) : id{i}
		{ std::cout << "construct A " << id << "\n"; }
		~A() { std::cout << "deconstruct A" << id << "\n"; }
};

/*
 * 在vector 容器中保存 unique_ptr<A> 类型变量
 * 在弹出此变量时即会执行A的析构函数.
 *
 * 所以输出是
 * construct A 1
 * construct A 2
 * deconstruct A2
 * after one pop_back
 * deconstruct A1
 * after one pop_back
 *
 */
int test()
{
	using std::vector;
	using std::unique_ptr;

	vector<unique_ptr<A>> vud;

	vud.push_back(unique_ptr<A>(new A(1)));
	vud.push_back(unique_ptr<A>(new A(2)));

	// pop_back() just erase element.
	vud.pop_back();
	std::cout << "after one pop_back\n";
	vud.pop_back();
	std::cout << "after one pop_back\n";
}

/*
 * 输出
 * construct A 1
 * construct A 2
 * deconstruct A1
 * deconstruct A2
 */
int test2()
{
	using std::vector;
	using std::unique_ptr;

	vector<unique_ptr<A>> vud;

	vud.push_back(unique_ptr<A>(new A(1)));
	vud.push_back(unique_ptr<A>(new A(2)));

	unique_ptr<A> ua = std::move(vud[0]);
}

/*
 * 输出
 * construct A 1
 * construct A 2
 * deconstruct A1
 * after erase begin()
 * after erase begin()
 * deconstruct A2
 *
 */ 
int test3()
{
	using std::vector;
	using std::shared_ptr;

	vector<shared_ptr<A>> vsa;

	vsa.push_back(shared_ptr<A>(new A(1)));
	vsa.push_back(shared_ptr<A>(new A(2)));

	// copy a shared_ptr<A> of A 2
	shared_ptr<A> sa = vsa[1];

	// this erase will be dtor A 1
	vsa.erase(vsa.begin());
	std::cout << "after erase begin()\n";
	// this erase will not be dtor A 2
	vsa.erase(vsa.begin());
	std::cout << "after erase begin()\n";
	// out of function scope will be dtor A 2
}

/*
 * 综合上面输出:
 * 使用像socket这种全局唯一的资源句柄时
 * 如果要满足"读取一次即释放"的需求
 * 1, 可以使用unique_ptr<socket>保存到容器中,
 *    在收到读取请求时将unique_ptr<socket>从容器中取出,
 *    unique_ptr<socket>的声明周期成了执行函数层
 *    函数执行完毕后,自会释放socket
 * 2, 可以使用shared_ptr<socket>保存到容器中,
 *    在收到读取请求时将shared_ptr<socket>从容器中复制一份,
 *    执行读取操作,读取完成后即将shared_ptr<socket>从容器中删除,
 *    此时,函数退出后,shared_ptr<socket>的引用为0,即被释放
 *
 * 不同:
 *   若使用方式1,若读取失败,如果还需要读取,则需要将unique_ptr<socket>放入容器,
 *                          如果不需要读取,则不需要放入.
 *   若使用方式2,只有主动从容器中删除,才会导致函数退出时释放,
 *               这样可以使用此操作来释放.
 */

int main()
{
//	test();
//	test2();
	test3();
}

