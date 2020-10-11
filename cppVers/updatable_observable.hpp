#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <mutex>
#include <assert.h>
#include "updatable_priority_queue.hpp"

class updatable_observable {
public:
	template<class T>
	void update_me(updatable_priority_queue<T>& updater);
};