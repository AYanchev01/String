#include <iostream>
#include <cstring>
class String
{
	char* string;
	size_t size;
	size_t capacity;
	void erase()
	{
		delete[] string;
	}
	void resize()
	{
		this->capacity *= 2;
		char* biggerString = new char[this->capacity];
		strcpy_s(biggerString, strlen(this->string) + 1, this->string);
		delete[] string;
		this->string = biggerString;
	}
public:
	String()
	{
		size = 1;
		capacity = 12;
		string = new char[capacity];
		string[0] = '\0';
	}
	void copy(const String& other)
	{
		this->string = new char[other.capacity];
		this->size = other.size;
		this->capacity = other.capacity;
		strcpy_s(string, strlen(other.string) + 1, other.string);
	}
	String& operator=(const String& other)
	{
		if (this != &other)
		{
			this->erase();
			this->copy(other);
		}
		return *this;
	}
	~String()
	{
		this->erase();
	}
	void setString(const char* string)
	{
		this->erase();
		size = strlen(string);
		this->string = new char[size + 1];
		strcpy_s(this->string, size + 1, string);
	}
	const char* getString() const
	{
		return this->string;
	}
	const size_t getCapacity() const
	{
		return this->capacity;
	}
	const size_t getSize() const
	{
		return this->size;
	}
	void add(char newChar)
	{
		if (size >= capacity)
		{
			this->resize();
		}
		this->string[size++] = newChar;
		this->string[size++] = '\0';
		
	}
	void print()
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << this->string[i];
		}
		std::cout << std::endl;
	}
	size_t getLenght()
	{
		return strlen(this->string);
	}
	void insertAt(int index, char elem)
	{
		this->resize();
		size++;
		for (size_t i = size; i > index; i--)
		{
			string[i] = string[i - 1];
		}
		string[index] = elem;
	}
	void removeAt(int index)
	{
		for (size_t i = index; i <size; i++)
		{
			string[i] = string[i + 1];
		}
		size--;
	}
	void trimStart()
	{
		for (size_t i = 0; i < size; i++)
		{
			string[i] = string[i + 1];
		}
		size--;
	}
	void trimEnd()
	{
		if(size > 0)
			this->size--;
	}
	void trimStart9000(int number)
	{
		for (size_t i = 0; i < number; i++)
		{
			this->trimStart();
		}
	}
	void trimEnd9000(int number)
	{
		for (size_t i = 0; i < number; i++)
		{
			this->trimEnd();
		}
	}
	String& operator+=(const String& other)
	{
		int temp = this->size;
		this->size += other.size;
		while (size >= capacity)
		{
			this->resize();
		}
		for (size_t i = temp; i < size; i++)
		{
			string[i] = other.string[i-temp];
		}
		return *this;
	}
	String& operator+(const String& other)
	{
		String temp1;
		temp1 += other;
		temp1 += *this;
		return temp1;
	}
	bool operator==(const String& other) 
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
	bool operator!=(const String& other)
	{
		return !(*this == other);
	}
	char operator[](int index)
	{
		return this->string[index];
	}
}; 

int main()
{
	String s1,s2,s3;
	s1.setString("Hello ");
	s2.setString("World");
	s2.add('!');
	s2.print();
	std::cout << s1[2];
}
