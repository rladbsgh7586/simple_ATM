#include "Card.h"

Card::Card(string id, string pin)
{
	this->m_card_id = id;
	this->m_pin_number = pin;
}

Card::Card(string id, string pin, map<string, Account> account_list)
{
	this->m_card_id = id;
	this->m_pin_number = pin;
	this->m_account_list = account_list;
}

string Card::pinChecker(string pin)
{
	if (this->m_pin_number.compare(pin) != 0)
		return "fail_wrong_pin";
	else
		return "success";
}

string Card::getPin()
{
	return this->m_pin_number;
}

string Card::createAccount(string account_id)
{
	if (this->m_account_list.find(account_id) != this->m_account_list.end())
		return "fail_duplicated";
	else
	{
		Account account = {account_id};
		this->m_account_list.insert(pair<string, Account>(account_id, account));
		return "success";
	}
}

string Card::createAccount(string account_id, string amount)
{
	if (this->m_account_list.find(account_id) != this->m_account_list.end())
		return "fail_duplicated";
	else
	{
		Account account = { account_id, amount };
		this->m_account_list.insert(pair<string, Account>(account_id, account));
		return "success";
	}
}

string Card::deleteAccount(string account_id)
{
	if (this->m_account_list.find(account_id) == this->m_account_list.end())
		return "fail_no_account";
	else
	{
		this->m_account_list.erase(account_id);
		return "success";
	}
}

Account Card::selectAccount(string account_id)
{
	if (this->m_account_list.find(account_id) != this->m_account_list.end())
		return this->m_account_list[account_id];
	else
	{
		Account null_obj;
		return null_obj;
	}
}

void Card::showAccountList()
{
	for (auto it = this->m_account_list.cbegin(); it != this->m_account_list.cend(); it++)
		cout << "-> " << it->first << endl;
}

void Card::showAccountListWithDeposit()
{
	for (auto it = this->m_account_list.cbegin(); it != this->m_account_list.cend(); it++)
		cout << "-> " << it->first << "  " << m_account_list[it->first].getBalance() << endl;
}