#include <iostream>
#include <list>

// List Ver 0.1

using namespace std;

struct List
{
	int Value;
	List* Back;
};

void AddObject(List* _Next,const int& _Value);
void PrintList(List* _Next);

void Insert(List** _Next,const int& _Value,int _Where, int Count);
void Erase(List** _Next,int _Where , int Count);

int main(void)
{
	List* NumberList = new List;
	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
		// ** 10회 추가
		AddObject(NumberList, i * 10 + 10);

	Erase(&NumberList, 4, NULL);
	Insert(&NumberList, 22, 7,NULL);

	PrintList(NumberList);

	return 0;
}

void AddObject(List* _Next,const int& _Value)
{
	if (_Next->Back == nullptr)
	{
		List* Temp = new List;
		Temp->Value = _Value;
		Temp->Back = nullptr;
		_Next->Back = Temp;

	}
	else
		AddObject(_Next->Back, _Value);
}

void PrintList(List* _Next)
{
	cout << _Next->Value << endl;
		
	if (_Next->Back != nullptr)
		PrintList(_Next->Back);
}

// 이거 아래 두개 숙제
void Insert(List** _Next, const int& _Value, int _Where, int Count)
{
	if (Count == NULL && _Where == 0)
	{
		if ((*_Next)->Back != nullptr)
		{
			List* Add = new List;
			Add->Value = _Value;
			Add->Back = (*_Next);
			(*_Next) = Add;
		}
		else
		{
			List* Add = new List;
			Add->Value = _Value;
			Add->Back = (*_Next);
		}
	}
	else if (_Where == 0 && Count != NULL)
	{
		if ((*_Next)->Back != nullptr)
		{
			List* Add = new List;
			Add->Value = _Value;
			Add->Back = (*_Next)->Back->Back;
			(*_Next)->Back = Add;
		}
		else
		{
			List* Add = new List;
			Add->Value = _Value;
			(*_Next)->Back = Add;
		}
	}
	else
		Insert( &(*_Next)->Back, _Value, --_Where, ++Count);
}

void Erase(List** _Next, int _Where, int Count)
{
	if (Count == NULL && _Where == 0)
	{
		if ((*_Next)->Back != nullptr)
		{
			List* Add = (*_Next)->Back;
			delete (*_Next);
			(*_Next) = nullptr;
			(*_Next) = Add;
		}
		else
		{
			delete (*_Next);
			(*_Next) = nullptr;
		}
	}
	else if (Count != NULL && _Where == 0)
	{
		if ((*_Next)->Back != nullptr)
		{
			List* Add = (*_Next)->Back;
			delete (*_Next);
			(*_Next) = nullptr;
			(*_Next) = Add;
		}
		else
		{
			delete (*_Next);
			(*_Next) = nullptr;
		}
	}
	else
		Erase(&(*_Next)->Back, --_Where, ++Count);
}
