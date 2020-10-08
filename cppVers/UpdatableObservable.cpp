#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <mutex>
#include <assert.h>

using namespace std;

class updatable_observable {
public:
	virtual void update_me(int& updater) {}
};