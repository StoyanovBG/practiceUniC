#include <iostream>
#include <string>


using namespace std;

class plane {
protected:
	int *maxHeight;
	double *weight;
	char *owner;
public:
	plane(void);
	plane(int const *,double const *,char const *);
	~plane() { delete maxHeight; delete weight; delete owner; }
	virtual void print(void);
};

plane::plane(void)
{
	maxHeight = 0;
	weight = 0;
	owner = new char[20];
	strcpy(owner, "none");
}

plane::plane(int const *mh, double const *w, char const *o)
{
	maxHeight = *mh;
	weight = *w;
	owner = new char[strlen(o) + 1];
	strcpy(owner, o);
}

void plane::print(void)
{
	cout << "Собственик на самолета: " << owner << " | " << "Максимална височина: " << maxHeight << " | " << "Тежест: " << weight << endl;
}

class att: public plane {
protected:
	char *mark;
	int *numPass;
public:
	att(void);
	att(int const *, double const *, char const *, char const *,int const *);
	~att() { delete maxHeight; delete weight; delete owner; delete mark; delete numPass; }
	virtual void print(void);
};

att::att(void)
{
	numPass = 0;
	mark = new char[20];
	strcpy(mark, "none");
}

att::att(int const *mh, double const *w, char const *o, int const *np, char const *m) : plane( mh, w, o)
{
	numPass = *np;
	mark = new char[strlen(m) + 1];
	strcpy(mark, m);
}

void att::print(void)
{
	plane::print;
	cout << "Брой пътници: " << numPass << " | " << "Марка самолет: " << mark << endl;
}

class cargo : public plane {
protected:
	int *maxDistance;
	double *loading;
	char *typeofCargo;
public:
	cargo(void);
	cargo(int const *, double const *, char const *,int const *,double const *,char const *);
	~cargo() { delete maxHeight; delete weight; delete owner; delete maxDistance; delete loading; delete typeofCargo; }
	virtual void print(void);
};

cargo::cargo(void)
{
	maxDistance = 0;
	loading = 0;
	typeofCargo = new char[20];
	strcpy(typeofCargo, "none");
}

cargo::cargo(int const *mh, double const *w, char const *o, int const *md, double const *l,char const *tc) : plane(mh, w, o)
{
	maxDistance = md;
	loading = l;
	typeofCargo = new char[strlen(tc) + 1];
	strcpy(typeofCargo, tc);
}

void cargo::print(void)
{

	plane::print;
	cout << "Максимална дистанция: " << maxDistance << " | " << "Товаримост: " << loading << " | " << "Тип пратка: " << typeofCargo << endl;
}


int main() {

	alfa = new plane(10000, 25000.50, "alfa");
	plane::print;
}
