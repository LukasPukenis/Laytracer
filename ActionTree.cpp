#include "ActionTree.h"

void ActionTree::step() {
	for (auto & action : actions) {
		action.step();
	}
}

void ActionTree::addAction(const Action & action) {
	actions.push_back(action);
}