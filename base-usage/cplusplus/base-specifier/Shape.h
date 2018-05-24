/*************************************************************************
	> File Name: Shape.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月14日 星期一 11时48分40秒
 ************************************************************************/

#include <iostream>
#include <vector>

#ifndef _SCZZQ_SHAPE_h_
#define _SCZZQ_SHAPE_h_

namespace sczzq{

// Point 拥有默认操作
//	默认拷贝操作
//	默认移动操作
//	默认析构操作
class Point {
	public:
		int x = 0;
		int y = 0;
		Point(int ix, int iy) : x{ix}, y{iy} { } 
};

class Shape {
	public:
		virtual Point center() const = 0;
		virtual void move(Point to) = 0;
		virtual void draw() const = 0;
		virtual void rotate(int angle) = 0;

		virtual ~Shape() { }
};

enum class Shape_kind { circle, triangle, smiley };

class Circle : public Shape {
	public:
		Circle(Point p, int rr) : x{p}, r{rr} { }
		Point center() const { return x; }
		void move(Point to) { x = to; }

		void draw() const { std::cout << "Circle Center{" << x.x << "," << x.y << "},radis:" << r << "\n"; }
		void rotate(int i) { std::cout << "rotate " << i << std::endl; }
	private:
		Point x; //圆心
		int r; // 半径
};

class Smiley : public Circle {
	public:
		Smiley(Point p, int r) : Circle{p, r}, mouth{nullptr} { }

		~Smiley()
		{
			delete mouth;
			for(auto p : eyes) delete p;
		}
		void move(Point to)
		{
			Circle::move(to);
			for(auto e : eyes)
				e->move(to);
			if(mouth)
				mouth->move(to);
		}

		void draw() const
		{
			std::cout << "here is my smiley shape\n";
			Circle::draw();
			std::cout << "and I have " << eyes.size() << " eyes.\n";
			for(auto p : eyes){
				p->draw();
			}
			if(mouth){
				std::cout << "and I have a mouth.\n";
				mouth->draw();
			}
			std::cout << "-----show you end ----------\n";
		}

		void rotate(int i) 
		{
			Circle::rotate( i);
			for(auto p : eyes){
				p->rotate( i);
			}
			if(mouth)
				mouth->rotate(i);
		}

		void add_eye(Shape* s){ eyes.push_back(s); }
		void set_mouth(Shape* s) { mouth = s; }
		virtual void wink(int i) { std::cout << "smiley wink " << i << " times.\n"; }

	private:
		std::vector<Shape*> eyes;
		Shape* mouth;
};

};

#endif

