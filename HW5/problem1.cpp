#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)

class Buyer;
class Seller {
private:
	static int numofSeller;
	static int totalApple;
	static int totalMoney;
	char* name;
	int money;
	int numofapple;
public:
	const int price;
	Seller(const char*, int, int, int);
	~Seller();
	bool haveapple(int);
	void giveapple(int, Buyer*);
	void getmoney(int);
	void Print();
	static void PrintAll();
};

class Buyer {
private:
	static int numofBuyer;
	static int totalApple;
	static int totalMoney;
	char* name;
	int money;
	int numofapple;
public:
	Buyer(const char*, int, int);
	~Buyer();
	bool havemoney(int);
	void givemoney(int, Seller*);
	void getapple(int);
	void Print();
	static void PrintAll();
};

// Problem 1-1
Seller::Seller(const char* name, int price, int numofapple, int money = 0) :price(price)
{
	/************ Implement here ***************/
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name) + 1; i++) {
		this->name[i] = name[i];
	}
	this->money = money;
	this->numofapple = numofapple;

	// Update static members
	numofSeller++;
	totalApple += numofapple;
	totalMoney += money;

	/************ Implement here ***************/
}

// Problem 1-2
Seller::~Seller()
{
	/************ Implement here ***************/
	delete this->name;
	numofSeller--;
	totalApple -= numofapple;
	totalMoney -= money;
	/************ Implement here ***************/
}


// Problem 1-3
bool Seller::haveapple(int numofapple) {
	/************ Implement here ***************/
	if (this->numofapple >= numofapple) {
		return true;
	}
	else {
		return false;
	}
	/************ Implement here ***************/
}

// Problem 1-4
void Seller::giveapple(int numofapple, Buyer* buyer) {
	/************ Implement here ***************/
	this->numofapple -= numofapple;
	totalApple -= numofapple;
	buyer->getapple(numofapple);

	/************ Implement here ***************/
}

// Problem 1-5
void Seller::getmoney(int money) {
	/************ Implement here ***************/
	this->money += money;
	totalMoney += money;
	/************ Implement here ***************/
}

// Problem 1-6
void Seller::Print() {
	/************ Implement here ***************/
	cout << "Seller " << this->name << " has " << this->money << " Won" << endl;
	cout << "Seller " << this->name << " has " << this->numofapple << " Won" << endl;
	/************ Implement here ***************/
}

// Problem 1-7
void Seller::PrintAll() {
	/************ Implement here ***************/
	cout << numofSeller << " sellers have " << totalMoney << " Won" << endl;
	cout << numofSeller << " sellers have " << totalApple << " apples" << endl;
	/************ Implement here ***************/
}

// PProblem 1-8
Buyer::Buyer(const char* name, int money, int numofapple = 0)
{
	/************ Implement here ***************/
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name) + 1; i++) {
		this->name[i] = name[i];
	}
	this->money = money;
	this->numofapple = numofapple;

	// Update static members
	numofBuyer++;
	totalApple += numofapple;
	totalMoney += money;
	/************ Implement here ***************/
}


// Problem 1-9
Buyer::~Buyer()
{
	/************ Implement here ***************/
	delete this->name;
	numofBuyer--;
	totalApple -= numofapple;
	totalMoney -= money;
	/************ Implement here ***************/
}


// Problem 1-10
bool Buyer::havemoney(int money) {
	/************ Implement here ***************/
	if (this->money >= money) {
		return true;
	}
	else {
		return false;
	}
	/************ Implement here ***************/
}

// Problem 1-11
void Buyer::givemoney(int money, Seller* seller) {
	/************ Implement here ***************/
	this->money -= money;
	totalMoney -= money;
	seller->getmoney(money);
	/************ Implement here ***************/
}

// Problem 1-12
void Buyer::getapple(int numofapple) {
	/************ Implement here ***************/
	this->numofapple += numofapple;
	totalApple += numofapple;
	/************ Implement here ***************/
}

// Problem 1-13
void Buyer::Print() {
	/************ Implement here ***************/
	cout << "Buyer " << this->name << " has " << this->money << " Won" << endl;
	cout << "Buyer " << this->name << " has " << this->numofapple << " Won" << endl;
	/************ Implement here ***************/
}

// Problem 1-14
void Buyer::PrintAll() {
	/************ Implement here ***************/
	cout << numofBuyer << " buyers have " << totalMoney << " Won" << endl;
	cout << numofBuyer << " buyers have " << totalApple << " apples" << endl;
	/************ Implement here ***************/
}

// Problem 1-15
/************ Implement here ***************/
int Seller::numofSeller = 0;
int Seller::totalApple = 0;
int Seller::totalMoney = 0;

int Buyer::numofBuyer = 0;
int Buyer::totalApple = 0;
int Buyer::totalMoney = 0;
/************ Implement here ***************/

// Problem 1-16
void Trade(Buyer* buyer, Seller* seller, int numofapple) {
	/************ Implement here ***************/
	bool isSellerHasApple = seller->haveapple(numofapple);
	bool isBuyerHasMoney = buyer->havemoney(seller->price * numofapple);

	if ((!isSellerHasApple) || (!isBuyerHasMoney)) {
		cout << "*** Trade is fail ***" << endl;
		if (!isBuyerHasMoney)
			cout << "REASON: Buyer don't have enough money" << endl;
		if (!isSellerHasApple)
			cout << "REASON: Seller don't have enough apples" << endl;

		cout << endl;
	}
	else {
		buyer->givemoney(numofapple * seller->price, seller);
		seller->giveapple(numofapple, buyer);
		cout << "*** Trade is complete ***" << endl;
		buyer->Print();
		seller->Print();
		cout << endl;
	}
	/************ Implement here ***************/
}

int main() {


	cout << "Problem 1" << endl << endl;
	Buyer KIM("KIM", 50000);
	Buyer LEE("LEE", 20000);
	Buyer PARK("PARK", 30000, 10);

	Seller JANG("JANG", 2000, 50);
	Seller CHOI("CHOI", 1000, 100);
	Seller NAM("NAM", 1000, 10, 20000);

	Buyer::PrintAll();
	Seller::PrintAll();
	cout << endl;

	Trade(&KIM, &JANG, 20);
	Trade(&LEE, &CHOI, 30);
	Trade(&PARK, &NAM, 50);

	Buyer::PrintAll();
	Seller::PrintAll();

	return 0;
}