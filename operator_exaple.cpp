#include <iostream>
using namespace std;
class Point
{
public:
	int x;
	int y;
	Point():x(0),y(0){}
	Point(int x,int y):x(x),y(y){}
	Point add(Point p1);
	Point operator+(Point &p1);
	Point operator++();
	Point operator++(int);	
	int operator*(Point &p1);
	bool operator==(Point &p1);	
};
bool Point::operator==(Point &p1)
{
	if((this->x == p1.x)&&(this->y == p1.y))	
		return 1;
	else
		return 0;
}
int Point::operator*(Point &p1)
{
	int a;
	a = this->x * p1.x + this->y * p1.y;	
	return a;
}
Point Point::add(Point p1)
{
	Point temp;
	temp.x = this->x + p1.x;
	temp.y = this->y + p1.y;	
	return temp;
}
Point Point::operator+(Point &p1)
{
	Point temp;
	temp.x = this->x + p1.x;
	temp.y = this->y + p1.y;	
	return temp;
}
Point Point::operator++()
{
	this->x++;
	this->y++;
}
Point Point::operator++(int)
{
	this->x++;
	this->y++;
}
Point *add1(Point p1,Point p2)
{
	Point *temp = new Point();
	temp->x = p1.x + p2.x;
	temp->y = p1.y + p2.y;
	return temp;
}
Point &add2(Point p1,Point p2)
{
	static Point temp;
	temp.x = p1.x + p2.x;
	temp.y = p1.y + p2.y;
	return temp;
}
int main()
{
	Point p1(3,4),p2(5,6),*p3, p4;
	p3 = add1(p1,p2);
	cout << p3->x << endl;
	cout << p3->y << endl;
	
	p4 = add2(p1,p2);
	cout << p4.x << endl;
	cout << p4.y << endl;		
		
	p4 = p1.add(p2);
	cout << p4.x << endl;
	cout << p4.y << endl;	
	
	Point p5;
	
	p5 = p1 + p2;
	cout << p5.x << endl;
	cout << p5.y << endl;
	
	++p5;
	cout << p5.x << endl; //9
	cout << p5.y << endl; //11
	p5++;
	cout << p5.x << endl; //10
	cout << p5.y << endl; //12
	
	cout << p1*p2 << endl;
	
	
	if(p1==p2)
	 	cout << "p1 == p2" << endl;
	else	
	 	cout << "p1 != p2" << endl;

	return 0;
 } 
