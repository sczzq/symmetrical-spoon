/*************************************************************************
	> File Name: main.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月14日 星期一 11时03分54秒
 ************************************************************************/

#include <iostream>
//#include <memory>
#include "Container.h"
#include "Vector.h"
#include "Shape.h"
#include "Complex.h"
//#include "function_template.h"

template <typename T> 
using Vector = sczzq::Vector<T>;

using Vector_container = sczzq::Vector_container;

using Container = sczzq::Container;

using Shape = sczzq::Shape;
using Circle = sczzq::Circle;
using Smiley = sczzq::Smiley;
using Point = sczzq::Point;

int test_vector()
{
	int n = 10;
	Vector<double> v(n);

	{
		Vector<double> v2(2*n);
		v2[n] = 10;
		v[n/2] = 10;
	}

	for(auto i = 0; i < n; ++i){
		std::cout << v[i] << std::endl;
	}
	return 0;
}

int test_show_vector(Vector<double> v)
{
	for(int a = 0; a < v.size(); ++a)
		std::cout << v[a] << "  ";
	std::cout << "\n";
}

int test2_vector()
{
//	std::initializer_list<double> ilist1 {1, 2, 3, 4, 5, 6, 7};
	Vector<double> v = {1, 2, 3, 4, 5, 6, 7};

//	std::initializer_list<double> ilist { 1, 4, 6, 7, 9};
//		Vector v3 = { 1, 4, 6, 7, 9};
//		v3[v3.size()/2] = v3[v3.size()/2] * 2;
		v[v.size()/2] = v[v.size()/2] * 2;

	Vector<double> v1 (v);

	std::cout << "after initialize v1 using copy constructor from v\n";
	test_show_vector(v1);

	Vector<double> v3 = v;

	std::cout << "after copy from v3 to v1\n";
	v1 = v3;
	test_show_vector(v1);

	std::cout << "the v\n";
	test_show_vector(v);

	std::cout << "the v3\n";
	test_show_vector(v3);
	Vector<double> v4(std::move(v));
	std::cout << "after move construct from v to v4.\n";
	test_show_vector(v4);

	v4 = std::move(v3);
	std::cout << "after move assign from v3 to v4.\n";
	test_show_vector(v4);

	for(auto x : v4)
		std::cout << x << std::endl;
}

int test_container()
{
	Vector_container vc(10);

	for(int i = 0; i < vc.size(); ++i){
		vc[i] = i;
	}

	vc[vc.size()/2] *= 2;

	for(int i = 0; i < vc.size(); ++i){
		std::cout << vc[i] << std::endl;
	}
}

void test_shape_draw_all(std::vector<Shape *> vs)
{
	for(int i = 0; i < vs.size(); i++){
		Shape* p = vs[i];
		p->draw();
	}
}

int test_shape()
{
	std::vector<Shape*> vs;
	for(int i = 1; i < 3; i++){
		Smiley* p = new Smiley(Point(i, i+1), i+8);
		p->add_eye(new Circle(Point(i, i), i+2));
		p->add_eye(new Circle(Point(i+2, i+2), i+2));
		p->set_mouth(new Circle(Point(i+4, i+4), i+2));
		vs.push_back(p);
	}

	/*
	 * Smiley类中含有非基类成员,成员变量,成员函数,
	 * 不能通过基类Shape直接向派生类Smiley转换
	 * 那么,通过动态类型转换,使得可以进行类型转换.
	 *
	 */
	Smiley* s = dynamic_cast<Smiley*>(vs[0]);
	s->add_eye(new Circle(Point(1, 1), 2));

	test_shape_draw_all(vs);

	for(int i = 0; i < vs.size(); i++){
		vs[i]->move(Point(i+10, i+20));
	}

	test_shape_draw_all(vs);
}

/*
 * 如何调用对应的函数
 * 常见的做法是将虚函数的名字转换成函数指针表中对应的索引值
 * 每个对象中保存一个函数指针表
 */
void use(Container& c)
{
	const size_t sz = c.size();

	for(int i = 0; i < sz; ++i){
		std::cout << c[i] << "\n";
	}

}

int test_complex()
{
	using Complex = sczzq::Complex;
	Complex cx{1,2};
	Complex cx2{2,1};
	Complex cx3;

	// cx3.im = 2; // 不是出现在类内的对象,不能访问类内的私有成员.

	cx += cx2;
	cx3 = cx/cx2; // 使用名字空间sczzq内的 / 操作.

	std::cout << cx3 << std::endl; // 使用名字空间 sczzq 内的 << 操作.

	Complex a { 2.3 };
	Complex b { 1/a };
	Complex c { a + b * Complex{1,2.3} };

	if( c != b)
		c = -(b/a) + 2 * b;

	std::cout << a << b << c << std::endl;

}

//template<typename C, typename V>
//using sum = sczzq::sum<C, V>;

//using sczzq::sum;

int test_function_template()
{
//	using namespace sczzq;
	using Complex = sczzq::Complex;

	sczzq::Vector<int> vi {1, 2, 3, 4, 5, 6};
	std::list<double> ld{1, 2, 3, 4, 5, 6};
	std::vector<Complex> vc{ Complex(1, 2), Complex(2, 3), Complex(3, 4) };
//	int x = sum(vi, 0);
//	int y = sum(ld, 0);
//	auto z = sum(vc, Complex());

//	std::cout << x << ", " << y << ", " << z << std::endl;
}

int main()
{
//	test_vector();
	test2_vector();
//	test_function_template();

//	test_container();

//	using List_container = sczzq::List_container;
//	List_container lc{1, 2, 3, 4, 5, 6, 7};
//	use(lc);
//	test_shape();
}
