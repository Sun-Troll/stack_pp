#pragma once

class Stack
{
private:
	class Member
	{
	public:
		Member(int val);
		void NewPush(int val);
		int DeleteNext();
		void SetVal(int valS);
		Member* GetNext() const;
		Member** GetPNext();
		int GetVal() const;
	private:
		int val;
		Member* next = nullptr;
	};
public:
	Stack();
	~Stack();
	Stack(const Stack& source);
	const Stack& operator=(const Stack& source);
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	void DeleteMembers();
	void CopyMembers(const Stack& source);
private:
	int size = 0;
	Member* first = nullptr;
};