#include "Account.h"

Account::Account(string id)
{
	this->m_account_id = id;
	this->m_balance = 0;
}

Account::Account(string id, string amount)
{
	this->m_account_id = id;
	this->m_balance = stringToInt(amount);
}

int	Account::getBalance()
{
	return this->m_balance;
}

string Account::deposit(string amount)
{
	if (!isNumber(amount))
		return "fail_wrong_amount";
	else
	{
		this->m_balance += stringToInt(amount);
		return "success";
	}
}

string Account::witdraw(string amount)
{
	if (!isNumber(amount))
		return "fail_wrong_amount";
	int i = stringToInt(amount);
	if (this->m_balance < i)
		return "fail_lack_of_balance";
	else
	{
		this->m_balance -= i;
		return "success";
	}
}