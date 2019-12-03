#pragma once
#include <iostream>

const int MAXSIZELIST = 1000;
using namespace std;

template<class Type>
class TList
{
	template<class Type>
	struct Node
	{
		Type key;    //значения
		Node *pNext; //указатель на следующий 
		Node *pPrev; //указатель на пердыдущий
		Node(Type val = {})
		{
			key = val;
			pNext = nullptr;
		}
	};
	int size;            //размер 
	Node<Type> *pFirst;  //указатель на первое звено

public:
	TList()
	{
		size = 0;
		pFirst = nullptr;
	}
	TList(const TList<Type> &list)                     //копирования
	{
		size = list.size;
		pFirst = nullptr;
		for (Node<Type> *res = list.pFirst; res != nullptr; res = res->pNext)
		{
			AddNodeInEnd(res->key);
		}
	}
	~TList()                                         //деструктор
	{
		while (pFirst != nullptr)
		{
			Node<Type> *res = pFirst;
			pFirst = pFirst->pNext;
			delete res;
		}
	}
	int GetSize()  { return size; }                   //получение длины
	bool IsEmpty() { return pFirst == nullptr; }      //проверка на пустоту

	TList<Type>& operator=(const TList<Type> &list);
	bool operator==(const TList<Type> &list);
	bool operator!=(const TList<Type> &list);	
	void AddNodeInEnd(Type _key);	
	void DeleteAllNodes();                            //удаление всего полинома     

	
	// класс (указатель на текущее звено)
	class TIndicator
	{
		Node<Type> *pointer; // указатель 
	public:
		TIndicator() { pointer = new Node<Type>; }                   //конструктор по умолчанию
		TIndicator(const TIndicator &ind) { pointer = ind.pointer; } //конструктор копирования		
		Node<Type>* operator->() const { return pointer; }           //указатель на текущий элемент 

		TIndicator& operator=(const TIndicator &ind)
		{
			pointer = ind.pointer;
			return *this;
		}
		TIndicator& operator ++()                    //перемещение указателя 
		{
			this->pointer = this->pointer->pNext;
			return *this;
		}
		bool operator==(const TIndicator &ind);
		bool operator!=(const TIndicator &ind);
		Type operator&()const;                        //адрес		
		void Change(Type _key);
	
	
		friend TList;
	};
	TIndicator Begin()      // указатель на первое звено
	{
		TIndicator ind;
		ind.pointer = pFirst;
		return ind;
	}
	TIndicator End()       //указатель на последнее звено
	{
		TIndicator ind;
		Node<Type> *res = pFirst;
		if (!IsEmpty())
		{
			while (res->pNext != nullptr)
			{
				res = res->pNext;
			}
			ind.pointer = res->pNext;
		}
		else
			ind.pointer = pFirst;
		return ind;
	}
	void Insert(TIndicator i, Type val);    //вставка по указателю
	void Delete(TIndicator i);              //удаление по указателю
	friend class TIndicator;
};

template<class Type>
inline TList<Type>& TList<Type>::operator=(const TList<Type>& list)
{
	DeleteAllNodes();
	Node<Type> *res = list.pFirst;
	while (res != nullptr)
	{
		AddNodeInEnd(res->key);
		res = res->pNext;
	}
	return *this;
}

template<class Type>
inline bool TList<Type>::operator==(const TList<Type>& list)
{
	if (list.size != size)
		return 0;
	Node<Type> *res1 = pFirst;
	Node<Type> *res2 = list.pFirst;
	while (res1 != nullptr)
	{
		if (res1->key == res2->key)
		{
			res1 = res1->pNext;
			res2 = res2->pNext;
		}
		else
			return 0;
	}
	return 1;
}

template<class Type>
inline bool TList<Type>::operator!=(const TList<Type>& list)
{
	return !(*this == list);
}

template<class Type>
inline void TList<Type>::AddNodeInEnd(Type _key)
{
	size++;
	if (IsEmpty())
	{
		Node<Type> *res = new Node<Type>;
		res->key = _key;
		pFirst = res;
	}
	else
	{
		if (size < MAXSIZELIST)
		{
			Node<Type> *res = pFirst;
			while (res->pNext != nullptr)
			{
				res = res->pNext;
			}
			Node<Type> *tmp = new Node<Type>;
			tmp->key = _key;
			tmp->pPrev = res;
			res->pNext = tmp;
		}
		else
			throw "List Full";
	}
}

template<class Type>
inline void TList<Type>::DeleteAllNodes()
{
	while (pFirst != nullptr)
	{
		Node<Type> *res = pFirst;
		pFirst = pFirst->pNext;
		delete res;
	}
}

template<class Type>
inline void TList<Type>::Insert(TIndicator i, Type val)
{
	Node<Type> *tmp = pFirst;
	Node<Type> *prev;
	Node<Type> *insert = new Node<Type>(val);
	int pos = 0;
	while (tmp != i.pointer)
	{
		prev = tmp;
		tmp = tmp->pNext;
		pos++;
	}
	if (pos == 0)
	{
		insert->pNext = tmp;
		pFirst = insert;
		size++;
	}
	else

	{
		insert->pNext = tmp;
		prev->pNext = insert;
		size++;
	}
}

template<class Type>
inline void TList<Type>::Delete(TIndicator i)
{
	Node<Type> *tmp = pFirst;
	Node<Type> *prev;
	int pos = 0;
	while (tmp != i.pointer)
	{
		prev = tmp;
		tmp = tmp->pNext;
		pos++;
	}
	if (pos == 0)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		size--;
	}
	else
	{
		prev->pNext = tmp->pNext;
		delete tmp;
		size--;
	}
}

template<class Type>
inline bool TList<Type>::TIndicator::operator==(const TIndicator & ind)
{
	if (pointer == ind.pointer)
		return 1;
	else
		return 0;
}

template<class Type>
inline bool TList<Type>::TIndicator::operator!=(const TIndicator & ind)

{
	if (pointer != ind.pointer)
		return 1;
	else
		return 0;
}

template<class Type>
inline Type TList<Type>::TIndicator::operator&() const
{
	if (pointer != nullptr)
		return pointer->key;
	else
		throw("Error");
}

template<class Type>
inline void TList<Type>::TIndicator::Change(Type _key)
{
	pointer->key = _key;

}	