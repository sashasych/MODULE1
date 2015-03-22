#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;


/*class Item
{
long NumberOfBook;//����� �����
bool taken;//��������� �����
public:
Item(long num, bool x)//����������� ��� ���������� ������� "������" ������
{
NumberOfBook = taken = 0;
};
~Item();
void set()
{


};// ������� ��� ������������� ����� ��� ���������� "�������" �������
bool isTaken() const;//������� ,���� ����� �� �����
bool isAvailable() const; //������� ,���� ����� � ����������
long getNumberOfBook() const;
void Take();
void Return();
void print()
{
cout<<
};



};
*/
class Book 
{
char author[64];
char title[64];
char publisher[64];
short year;
int pages;
bool taken;
public:
	Book()  // ����������� ��� ���������� ������� "������" ������
{
		author[0] = title[0] = publisher[0] = taken= 0;
year = pages = 0;
}
Book(char a[],char t[],int p, short  y, char pub[]) //
// ���������� "�������" �������
{
strcpy(author,a );		
strcpy(title,t );
strcpy(publisher, pub);
year  =y ;
pages =p ;
taken = 0;
}
~Book() 
{
	author[0] = title[0] = publisher[0] =  taken = 0;
	year = pages = 0;
}
void print() // ������� ��� ������ ����� �������
{
	cout << "\nNazvanie :" << title << "\nauthor:" << author << "\npublisher :" << publisher << "\n god :" << year << "\npages" << pages;
}
void set(char a[], char t[], int p, short  y, char pub[]) //
// ���������� "�������" �������
{
	strcpy(author, a);
	strcpy(title, t);
	strcpy(publisher, pub);
	year = y;
	pages = p;
}
bool isTaken()
{
	return taken;
};//������� ,���� ����� �� �����
bool isAvailable()
{
	return !taken;
}; //������� ,���� ����� � ����������
void Take()
{
	taken = 1;
};
void Return()
{
	taken = 0;
};
};
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
class  Magazine
{

char volume[64];
short number;
char title1[64];
short year1;
public:
	Magazine()  // ����������� ��� ���������� ������� "������" ������
	{
		year1 = volume[0] = number = title1[0] = 0;
	}
	void set(char n[], char m[], int k1, int g1) // ������� ��� ������������� ����� ��� 
		// ���������� "�������" �������
	{
		strcpy(volume, n);
		strcpy(title1, m);// 
		year1 = k1;
		number = g1;// 
	}
	void print() // ������� ��� ������ ����� �������
	{
		cout << "\nNazvanie :" << title1 << "\nTOM:" << volume << "\nnomer :" << number << "\n god :" << year1;
	}
};
class Library 
{
	char name[64];
	char adress[64];
	vector<Book*> mas;
public:
	Library()  // ����������� ��� ���������� ������� "������" ������
	{
		name[0] = adress[0] = 0;
		mas.clear();
	}
	Library(char n[], char a[])  // ����������� ��� ���������� ������� "������" ������
	{
		strcpy(name, n);
		strcpy(adress, a);
		mas.clear();
	}
	~Library()  // ����������� ��� ���������� ������� "������" ������
	{
		name[0] = adress[0] = 0;
		for (int i = 0; i < mas.size(); i++)
			delete mas[i];
		mas.clear();
	}
	void set(char n[], char m[]) // ������� ��� ������������� ����� ��� 
		// ���������� "�������" �������
	{
		strcpy(name, n);
		strcpy(adress, m);// �������� ������, ���������� ����� ���������
	}
	void print() // ������� ��� ������ ����� �������
	{
		cout << "\n" << name << "\n" << adress << "\n";
		for (int i = 0; i < mas.size(); i++)
			mas[i]->print();
	}
	void printTaken() // ������� ��� ������ ����� �������
	{
		cout << "\n" << name << "\n" << adress << "\n";
		for (int i = 0; i < mas.size(); i++)
		if (mas[i]->isTaken())
			mas[i]->print();
	}
	void add(Book* b) // ������� ��� ������ ����� �������
	{
		mas.push_back(b);
	}
	Library& operator+ (Book* b){
		mas.push_back(b);
		return *this;
	}
	void Take(int k)
	{
		mas[k]->Take();
	};
	void Return(int k)
	{
		mas[k]->Return();
	};

	void del(int k)
	{
		delete mas[k];
		mas.erase(mas.begin()+k);
	};
};

int _tmain(int argc, _TCHAR* argv[])
{
	///////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////
	Library lib1("libr1", "addr1");
	int k, g;
	cout << "kolichestvo knig=";
		cin >> k;
//	cout << "kolichestvo gurnalov=";
//	cin >> g;
	char S[64], A[64], T[64];
/*	cout << "Nazvanie: ";
	cin >> S;
	cout << "Adress=";
	cin >> A;
	lib1.set(S, A, k, g); // �������� ������� set ��� ������������� ����� 
	// ��������
	// ���� ������ ����� ��� ��������
	lib1.print();
	S[0] = A[0] = k = g = 0;
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
    Magazine *pMagazine; // ��������� �� ������
	pMagazine = new Magazine[g]; // ��� ������� ������� ���������� ����������� ��� ����������, 
	// �.�. ������� "������" �������
	// ���� ����� ������ ��� ��������
	for (int i = 0; i<g; i++)
	{
		cout << "nazvanie=";
		cin >> S;  //
		cout << "Tom="; 
		cin >> A; 
		cout << "vvedite god=";
		cin >> k;
		cout << "vvedite nomer=";
		cin >> g;
		pMagazine[i].set(A,S,k,g); // �������� ������� set ��� ������������� ����� 
		// ��������
	}
	// ���� ������ ����� ��� ��������
	for (int i = 0; i<k; i++) pMagazine[i].print();
	*/
	/////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////
	Book *pBook; // ��������� �� ������
	//pBook = new Book[k]; // ��� ������� ������� ���������� ����������� ��� ����������, 
	// �.�. ������� "������" �������
	// ���� ����� ������ ��� ��������
	int p;
	for (int i = 0; i<k; i++)
	{
		cout << "nazvanie=";
		cin >> S; 
		cout << "author=";
		cin >> A;  
		cout << "publisher=";
	    cin >> T;
		cout << "year ";
		cin >> g;
		cout << "pages";
		cin >> p;
		pBook = new Book(S, A , p,g,T); // ��� ������� ������� ���������� ����������� ��� ����������,
		lib1+pBook;
		//b = new Book("t3", "a3", 1, 2001, "p3");
//		pBook[i].setbook(S, A , k,g,T); // �������� ������� set ��� ������������� �����
	}
	// ���� ������ ����� ��� ��������
//	for (int i = 0; i<k; i++) pBook[i].print();
	

	Book *b;
	b = new Book("t1", "a1", 1, 2001, "p1");
	lib1.add(b);
	b = new Book("t2", "a2", 1, 2001, "p2");
	lib1.add(b);
	b = new Book("t3", "a3", 1, 2001, "p3");
	lib1+b;
	lib1.print();
	cout << "\n======\n";

	lib1.Take(1);
	lib1.Take(3);
	cout << "======\n";
	lib1.printTaken();

	lib1.del(1);
	cout << "======\n";
	lib1.printTaken();


    _getch();
	return 0;
}

