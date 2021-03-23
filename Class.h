#pragma once
#include <iostream>
#include <cstring>
class String
{
	char* string;
	size_t size;
	size_t capacity;
	void erase();
	void resize();
public:
	String();
	void copy(const String& other);
	String(const String& other);
	String& operator=(const String& other);
	~String();
	void setString(const char* string);
	const char* getString() const;
	const size_t getCapacity() const;
	const size_t getSize() const;
	void add(char newChar);
	void print();
	size_t getLenght();
	void insertAt(int index, char elem);
	void removeAt(int index);
	void trimStart();
	void trimEnd();
	void trimStart9000(int number);
	void trimEnd9000(int number);
	String& operator+=(const String& other);
	String operator+(const String& other);
	bool operator==(const String& other);
	bool operator!=(const String& other);
	char operator[](int index);
};



