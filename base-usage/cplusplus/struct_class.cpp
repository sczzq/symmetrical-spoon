/*************************************************************************
	> File Name: struct_class.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 15 Apr 2018 11:15:28 AM CST
 ************************************************************************/

#include <iostream>

struct Point {
	int x, y;
};

struct Points{
	vector<Point> elem;
	Points(Point p0) { elem.push_back(p0); }
	Points(Point p0, Point p1) { elem.push_back(p0); elem.push_back(p1); }

};

