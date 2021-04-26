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
	String(const char* other);
	String& operator=(const String& other);
	String& operator=(const char* other);
	~String();
	void setString(const char* string);
	void add(char newChar);
	void print() const;
	size_t getLenght() const;
	void insertAt(int index, char elem);
	void removeAt(int index);
	void trimStart();
	void trimEnd();
	void trimStart9000(int number);
	void trimEnd9000(int number);
	String& operator+=(const String& other);
	String operator+(const String& other);
	bool operator==(const String& other) const;
	bool operator==(const char* other) const;
	bool operator!=(const String& other) const;
	bool operator!=(const char* other) const;
	char& operator[](int index) const;
};





