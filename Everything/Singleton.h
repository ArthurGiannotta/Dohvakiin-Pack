#pragma once

template <class C>
class Singleton {
private:
	Singleton(void);
	~Singleton(void);
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
public:
	static C& instance(void)
	{
		static C inst;
		return inst;
	}
};