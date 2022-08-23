#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Card.h"
#include "Account.h"
#include "Util.h"
#include <iostream>

enum Command {
	balance,
	deposit,
	withdraw,
	showall,
	showcard,
	showaccount,
	quit,
	insert_card,
	input_PIN_number,
	select_account,
	after_select_account,
	help
};

void initializeDB(map<string, Card>& card_db);
void showDB(map<string, Card> card_db);
int	controlCommand(int command, map<string, Card> card_db, Card current_card, int& flag_end);
int	stringToEnum(string string);
void printContour();

#endif