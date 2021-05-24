#include "String.h"
#include <iostream>

void String::erase()
{
	delete[] string;
}
void String::resize()
{
	this->capacity *= 2;
	char* biggerString = new char[this->capacity];
	strcpy_s(biggerString, size + 1, this->string);
	delete[] string;
	this->string = biggerString;
}
String::String()
{
	size = 0;
	capacity = 12;
	string = new char[capacity];
	string[0] = '\0';
}
void String::copy(const String& other)
{
	this->string = new char[other.capacity];
	this->size = other.size;
	this->capacity = other.capacity;
	strcpy_s(string, other.size + 1, other.string);
}
String::String(const String& other)
{
	this->copy(other);
}
String::String(const char* other)
{
	this->size = strlen(other);
	this->capacity = strlen(other) * 2;
	this->string = new char[capacity];
	strcpy_s(string, strlen(other) + 1, other);
}
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}
String& String::operator=(const char* other)
{
	this->erase();
	this->size = strlen(other);
	this->capacity = strlen(other) * 2;
	this->string = new char[capacity];
	strcpy_s(string, strlen(other) + 1, other);
	return *this;
}
String::~String()
{
	this->erase();
}
void String::setString(const char* string)
{
	this->erase();
	size = strlen(string);
	capacity = size * 2;
	this->string = new char[capacity];
	strcpy_s(this->string, size + 1, string);
}
void String::add(char newChar)
{
	if (size >= capacity - 1)
	{
		this->resize();
	}
	this->string[size++] = newChar;
	this->string[size] = '\0';
}
void String::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << this->string[i];
	}
	std::cout << std::endl;
}
size_t String::getLenght() const
{
	return this->size;
}
void String::insertAt(int index, char elem)
{
	this->resize();
	size++;
	for (size_t i = size; i > index; i--)
	{
		string[i] = string[i - 1];
	}
	string[index] = elem;
}
void String::removeAt(int index)
{
	for (size_t i = index; i < size; i++)
	{
		string[i] = string[i + 1];
	}
	size--;
}
void String::trimStart()
{
	for (size_t i = 0; i < size; i++)
	{
		string[i] = string[i + 1];
	}
	size--;
}
void String::trimEnd()
{
	if (size > 0)
		this->size--;
}
void String::trimStart9000(int number)
{
	for (size_t i = 0; i < number; i++)
	{
		this->trimStart();
	}
}
void String::trimEnd9000(int number)
{
	for (size_t i = 0; i < number; i++)
	{
		this->trimEnd();
	}
}
String& String::operator+=(const String& other)
{
	*this = *this + other;
	return *this;
}
String String::operator+(const String& other)
{
	String temp1(*this);
	for (int i = 0; i < other.size; i++)
	{
		temp1.add(other.string[i]);
	}
	return temp1;
}
bool String::operator==(const String& other) const
{
	if (size == other.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (string[i] != other.string[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
bool String::operator==(const char* other) const
{
	if (size == strlen(other))
	{
		for (int i = 0; i < size; i++)
		{
			if (string[i] != other[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
bool String::operator!=(const String& other) const
{
	return !(*this == other);
}
bool String::operator!=(const char* other) const
{
	return !(*this == other);
}
char& String::operator[](int index) const
{
	return this->string[index];
}

std::ostream& operator<<(std::ostream& out, const String& string)
{
	out << string.string;
	return out;
}

std::istream& operator>>(std::istream& in, String& string)
{
	char c;
	do
	{
		c = in.get();
		string.add(c);
	} while (c != '\n');

	return in;
}
