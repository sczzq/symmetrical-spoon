/*************************************************************************
    > File Name: turtle.h
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年11月25日 星期日 23时04分16秒
 ************************************************************************/

#pragma once

using namespace std;
class Turtle {
public:
  virtual ~Turtle() {}
  virtual void PenUp() = 0;
  virtual void PenDown() = 0;
  virtual void Forward(int distance) = 0;
  virtual void Turn(int degrees) = 0;
  virtual void GoTo(int x, int y) = 0;
  virtual int GetX() const = 0;
  virtual int GetY() const = 0;
};
