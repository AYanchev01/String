#include <iostream>
#include <cstring>
#include "String.h"

int main()
{
	String s1, s2, s3;
	s1.setString("Hello ");
	s2.setString("World");
	s3 = s1 + s2;
	s1 += s2;
	s1.print();
	s3.print();
	s1.add('!');
	s1.print();
}
