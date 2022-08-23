#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "Util.h"
#include <iostream>
#include <sstream>

using namespace std;

class Account
{
private:
	string	m_account_id;
	bool m_null = false;
	int	m_balance;

public:
	Account() { this->m_null = true; }
	Account(string id);
	Account(string id, string amount);
	int	getBalance();
	string deposit(string amount);
	string witdraw(string amount);
	bool isNull() { return m_null; }
};

#endif