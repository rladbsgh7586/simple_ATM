#include "Controller.h"

int	main()
{
	int flag_end = 0;
	int ATM_state = insert_card;
	string user_input, action_result, amount;
	int	command;
	Card current_card;
	Account current_account;
	map<string, Card> card_db;
	initializeDB(card_db);

	while (flag_end == 0)
	{
		switch(ATM_state)
		{
			case insert_card:
				printContour();
				cout << "Insert your card: " << endl;
				cin >> user_input;
				command = stringToEnum(user_input);
				if (controlCommand(command, card_db, current_card, flag_end))
					continue;
				else if (card_db.find(user_input) != card_db.end())
				{
					current_card = card_db[user_input];
					ATM_state = input_PIN_number;
				}
				else
					cout << "This is wrong card" << endl;
				break;
			case input_PIN_number:
				printContour();
				cout << "input Pin number: " << endl;
				cin >> user_input;
				command = stringToEnum(user_input);
				if (controlCommand(command, card_db, current_card, flag_end))
					continue;
				else
				{
					action_result = current_card.pinChecker(user_input);
					if (action_result.compare("success") == 0)
						ATM_state = select_account;
					else
						cout << action_result << endl;
				}
				break;
			case select_account:
				printContour();
				cout << "select your account: " << endl;
				cin >> user_input;
				command = stringToEnum(user_input);
				if (controlCommand(command, card_db, current_card, flag_end))
					continue;
				else
				{
					current_account = current_card.selectAccount(user_input);
					if (current_account.isNull())
						cout << "There is no right account." << endl;
					else
						ATM_state = after_select_account;
				}
				break;
			case after_select_account:
				printContour();
				cout << "What would you like to do? (balance/deposit/withdraw): " << endl;
				cin >> user_input;
				command = stringToEnum(user_input);
				if (controlCommand(command, card_db, current_card, flag_end))
					continue;
				else
				{
					switch (command)
					{
						case balance:
							cout << current_account.getBalance() << endl;
							break;
						case deposit:
							cout << "How much would you like to deposit?: " << endl;
							cin >> amount;
							cout << current_account.deposit(amount) << endl;
							break;
						case withdraw:
							cout << "How much would you like to withdraw?: " << endl;
							cin >> amount;
							cout << current_account.witdraw(amount) << endl;
							break;
						default:
							cout << "wrong input" << endl;
							break;
					}
				}
				break;
		}
	}
}

void initializeDB(map<string, Card>& card_db)
{
	Card card_a = { "asdf1313", "qwer1234" };
	card_a.createAccount("user", "0");
	card_a.createAccount("master", "100");
	card_a.createAccount("father", "20");
	card_a.createAccount("mother", "42");
	card_db.insert(pair<string, Card>("asdf1313", card_a));

	Card card_b = { "bbbb", "bbb1234" };
	card_b.createAccount("user", "100");
	card_b.createAccount("master", "100");
	card_db.insert(pair<string, Card>("bbbb", card_b));

	Card card_c = { "cccc", "ccc1234" };
	card_c.createAccount("user", "100");
	card_c.createAccount("master", "100");
	card_db.insert(pair<string, Card>("cccc", card_c));
}

void showDB(map<string, Card> card_db)
{
	for (auto it = card_db.cbegin(); it != card_db.cend(); it++)
		cout << it->first << endl;
}

int	controlCommand(int command, map<string, Card> card_db, Card current_card, int& flag_end)
{
	switch (command)
	{
		case showall:
			printContour();
			cout << "command: showall" << endl;
			for (auto it = card_db.cbegin(); it != card_db.cend(); it++) 
			{
				cout << "- " << it->first << " - " << card_db[it->first].getPin() << endl;
				card_db[it->first].showAccountListWithDeposit();
			}
			return 1;
		case showcard:
			printContour();
			cout << "command: showcard" << endl;
			for (auto it = card_db.cbegin(); it != card_db.cend(); it++)
				cout << "- " << it->first << endl;
			return 1;
		case showaccount:
			printContour();
			cout << "command: showaccount" << endl;
			if (current_card.isNull())
				cout << "fail_no_selected_card" << endl;
			else
				current_card.showAccountList();
			return 1;
		case help:
			printContour();
			cout << "command list" << endl;
			cout << "- showall" << endl;
			cout << "- showcard" << endl;
			cout << "- showaccount" << endl;
			cout << "- quit" << endl;
			break;
		case quit:
			cout << "command: quit" << endl;
			flag_end = 1;
			return 1;
		default:
			return 0;
	}
}

int	stringToEnum(string string) 
{
	if (string.compare("balance") == 0)
		return 0;
	else if (string.compare("deposit") == 0)
		return 1;
	else if (string.compare("withdraw") == 0)
		return 2;
	else if (string.compare("showall") == 0)
		return 3;
	else if (string.compare("showcard") == 0)
		return 4;
	else if (string.compare("showaccount") == 0)
		return 5;
	else if (string.compare("quit") == 0)
		return 6;
	else if (string.compare("insert_card") == 0)
		return 7;
	else if (string.compare("input_PIN_number") == 0)
		return 8;
	else if (string.compare("select_account") == 0)
		return 9;
	else if (string.compare("after_select_account") == 0)
		return 10;
	else if (string.compare("help") == 0)
		return 11;
	else
		return -1;
}

void printContour()
{
	cout << "\n============================\n" << endl;
}