#include <iostream>
#include <list>

// List Ver 0.1

using namespace std;

struct List
{
	List* Front;
	int Value;
	List* Back;
};

void push_back(List* _Current,const int& _Value);
void PrintList(List* _Current);

void Insert(List* _Current,const int& _Value,int _Where, int Count);
void Erase(List** _Current,int _Where , int Count);

void T_Insert(List* _Current, const int& _Value, int _Where);
void T_Erase(List* _Current, int _Where);
void T_Pop_Back(List* _Current);

List* End = nullptr;


int main(void)
{
	List* NumberList = new List;
	NumberList->Front = nullptr;
	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
		// ** 10회 추가
		push_back(NumberList, i * 10 + 10);

	//Erase(&NumberList, 4, NULL);
	//Insert(NumberList, 22, 7,NULL);
	T_Insert(NumberList, 15, 2);
	T_Erase(NumberList, 2);

	T_Pop_Back(NumberList);
	PrintList(NumberList);

	return 0;
}

void push_back(List* _Current,const int& _Value)
{
	if (_Current->Back == nullptr)
	{
		List* Temp = new List;
		
		Temp->Front = _Current;
		Temp->Value = _Value;
		Temp->Back = nullptr;
		_Current->Back = Temp;

		End = Temp;
	}
	else
		push_back(_Current->Back, _Value);
}

void PrintList(List* _Current)
{
	cout << _Current->Value << endl;
		
	if (_Current->Back != nullptr)
		PrintList(_Current->Back);
}

// 이거 아래 두개 숙제 ->List에 Front 가 없을 떄 사용
void Insert(List* _Current, const int& _Value, int _Where, int Count)
{
	if (Count == NULL && _Where == 0)
	{
		if ((_Current)->Back != nullptr)
		{
			List* Add = new List;
			Add->Value = _Value;
			Add->Back = (_Current);
			(_Current) = Add;
		}
		else
		{
			List* Add = new List;
			Add->Value = _Value;
			Add->Back = (_Current);
		}
	}
	else if (_Where == 0 && Count != NULL)
	{
		if ((_Current)->Back != nullptr)
		{
			List* Add = new List;
			Add->Value = _Value;
			Add->Back = (_Current)->Back;
			(_Current)->Back = Add;
		}
		else
		{
			List* Add = new List;
			Add->Value = _Value;
			(_Current)->Back = Add;
		}
	}
	else
		Insert( (_Current)->Back, _Value, --_Where, ++Count);
}

void Erase(List** _Current, int _Where, int Count)
{
	if (Count == NULL && _Where == 0)
	{
		if ((*_Current)->Back != nullptr)
		{
			List* Add = (*_Current)->Back;
			delete (*_Current);
			(*_Current) = nullptr;
			(*_Current) = Add;
		}
		else
		{
			delete (*_Current);
			(*_Current) = nullptr;
		}
	}
	else if (Count != NULL && _Where == 0)
	{
		if ((*_Current)->Back != nullptr)
		{
			List* Add = (*_Current)->Back;
			delete (*_Current);
			(*_Current) = nullptr;
			(*_Current) = Add;
		}
		else
		{
			delete (*_Current);
			(*_Current) = nullptr;
		}
	}
	else
		Erase(&(*_Current)->Back, --_Where, ++Count);
}

void T_Insert(List* _Current, const int& _Value, int _Where)
{
	if (_Where == 1)
	{
		List* Temp = new List;

		Temp->Front = _Current;
		Temp->Value = _Value;
		Temp->Back = _Current->Back;

		_Current->Back = Temp;
	}
	else
		T_Insert(_Current->Back, _Value, --_Where);
}

List* Front = nullptr;

void T_Erase(List* _Current, int _Where)
{
	if (_Where == 1)
	{
		//auto Temp = _Current;
		//_Current = _Current->Back;

		//Front->Back = _Current->Back;

		List* del = _Current;

		_Current->Front->Back = _Current->Back;
		_Current->Back->Front = _Current->Front ;

		delete del;
		del = nullptr;

		
	}
	else
		T_Erase(_Current->Back, --_Where);
}

void T_Pop_Back(List* _Current)
{
	if (_Current->Back == nullptr)
	{
		End = _Current->Front;

		_Current->Front->Back = nullptr;

		delete _Current;
		_Current = nullptr;
	}
	else
		T_Pop_Back(_Current->Back);
}


