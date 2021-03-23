#include <iostream>
#include <cstring>
#include "Class.h"

int main()
{
	String s1,s2,s3;
	s1.setString("Hello ");
	s2.setString("World");
	s3 = s1 + s2;
	s1 += s2;
	s1.print();
	s3.print();
}
