#ifndef __CARD_H__
#define __CARD_H__

#include "Account.h"
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

class Card
{
private:
	string	m_card_id;
	string	m_pin_number;
	bool m_null = false;
	map<string, Account> m_account_list;

public:
	Card() { m_null = true; }
	Card(string id, string pin);
	Card(string id, string pin, map<string, Account> account_list);
	string pinChecker(string pin);
	string getPin();
	string createAccount(string account_id);
	string createAccount(string account_id, string amount);
	string deleteAccount(string account_id);
	Account selectAccount(string account_id);
	void showAccountList();
	void showAccountListWithDeposit();
	bool isNull() { return m_null; }
};

#endif