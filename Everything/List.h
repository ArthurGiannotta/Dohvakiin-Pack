#pragma once

template <class ListObject>
class List {
private:
	int length;
	bool autoClean;

	ListObject* first;
	ListObject* last;
public:
	List(void);
	virtual ~List(void);

	void clean(void);
	void remove(int pos);
	
	ListObject& begin(void);
	ListObject& end(void);
	ListObject& get(int pos);

	void insert(int pos, const ListObject& object);
	void push(const ListObject& object);
	ListObject& pop(void);

	void toggleCleaning(void);

	size_t size(void);

	List& operator <<(ListObject& object);
	List& operator >>(ListObject& object);
};