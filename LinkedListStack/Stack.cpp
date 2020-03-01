#include "Stack.h"
#include <assert.h>

Stack::Stack()
	:
	size(0),
	first(nullptr)
{
}

Stack::~Stack()
{
	DeleteMembers();
}

Stack::Stack(const Stack& source)
{
	/*const Member* sCur = source.first;
	Member** cur = &first;
	while (sCur != nullptr)
	{
		*cur = new Member(sCur->GetVal());
		sCur = sCur->GetNext();
		cur = (*cur)->GetPNext();
		size++;
	}
	assert(size == source.size);*/
	CopyMembers(source);
}

const Stack& Stack::operator=(const Stack& source)
{
	DeleteMembers();
	CopyMembers(source);
	return *this;
}

void Stack::Push(int val)
{
	if (size == 0)
	{
		assert(first == nullptr);
		first = new Member(val);
	}
	/*else
	{
		Member* cur = first;
		while (cur->GetNext() != nullptr)
		{
			cur = cur->GetNext();
		}
		cur->NewPush(val);
		for (int i = 0; i < size; i++)
		{
			cur = cur->GetNext();
		}
		cur->NewPush(val);
	}*/
	else
	{
		Member* cur = first;
		for (int i = 0; i < size - 1; i++)
		{
			assert(cur->GetNext() != nullptr);
			cur = cur->GetNext();
		}
		assert(cur->GetNext() == nullptr);
		cur->NewPush(val);
	}
	size++;
}

int Stack::Pop()
{
	int retVal = -1;
	if (size == 0)
	{
		assert(first == nullptr);
		return retVal;
	}
	else if (size == 1)
	{
		assert(first->GetNext() == nullptr);
		retVal = first->GetVal();
		delete first;
		first = nullptr;
		size--;
		return retVal;
	}
	else
	{
		Member* cur = first;
		for (int i = 0; i < size - 2; i++)
		{
			cur = cur->GetNext();
		}
		assert(cur->GetNext() != nullptr && cur->GetNext()->GetNext() == nullptr);
		retVal = cur->DeleteNext();
		size--;
		return retVal;
	}
}

int Stack::Size() const
{
	return size;
}

bool Stack::Empty() const
{
	return size == 0;
}

void Stack::DeleteMembers()
{
	if (size == 0)
	{
		assert(first == nullptr);
	}
	else if (size == 1)
	{
		assert(first != nullptr && first->GetNext() == nullptr);
		delete first;
		first = nullptr;
	}
	else
	{
		Member* cur = first;
		Member* next = cur->GetNext();
		while (next != nullptr)
		{
			delete cur;
			cur = next;
			next = cur->GetNext();
		}
		first = nullptr;
		delete cur;
	}
}

void Stack::CopyMembers(const Stack& source)
{
	const Member* sCur = source.first;
	Member** cur = &first;
	while (sCur != nullptr)
	{
		*cur = new Member(sCur->GetVal());
		sCur = sCur->GetNext();
		cur = (*cur)->GetPNext();
		size++;
	}
	assert(size == source.size);
}

Stack::Member::Member(int val)
	:
	val(val)
{
}

void Stack::Member::NewPush(int val)
{
	next = new Member(val);
}

int Stack::Member::DeleteNext()
{
	int nextVal = next->GetVal();
	delete next;
	next = nullptr;
	return nextVal;
}

Stack::Member* Stack::Member::GetNext() const
{
	return next;
}

Stack::Member** Stack::Member::GetPNext()
{
	return &next;
}

int Stack::Member::GetVal() const
{
	return val;
}
