#pragma once

class Stack
{
private:
	class Memeber
	{
	public:

	private:
		int val;
		Memeber* next = nullptr;
	};
public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	int size = 0;
	Memeber* first = nullptr;
};