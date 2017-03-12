#pragma once

#include <vector>
#include "Action.h"

class ActionTree {
public:
	ActionTree() {};

	void addAction(const Action & action);
	void step();
private:
	std::vector<Action> actions;
};