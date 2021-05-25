#pragma once
#include <iostream>
using namespace std;

template <class T>
class SmartPointer
{
public:
    SmartPointer() {Pointer = NULL;}
    
	SmartPointer(SmartPointer &point) 
	{
		Pointer = point.Pointer;
    	point.Pointer = NULL;
	};
	SmartPointer<T>& operator=(T* point) 
	{
		if (Pointer!=NULL) 
		{
			delete Pointer;
		}
		Pointer = point;
		return *this;
	};
	SmartPointer<T>& operator=(SmartPointer<T>& point) 
	{
		if (Pointer != NULL) 
		{
			delete Pointer;
		}
		
		Pointer = point.Pointer;
		point.Pointer = NULL;
	
		return *this;
	};
	T &operator * () {return *Pointer;};
	
	T *operator -> () {return Pointer;};
	
	bool isNull() {
		bool Null = false;
		if (Pointer == NULL) 
		{
			Null = true;
			return Null;
		}
		return Null;
	};
private:
    T *Pointer;

};

