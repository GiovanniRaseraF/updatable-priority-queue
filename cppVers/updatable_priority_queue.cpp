#include "updatable_priority_queue.hpp"

template <
	class T,
	class Container = std::vector<T>,
	class less_then = std::less<typename Container::value_type>,
	class equal = std::equal_to<typename Container::value_type>
>
	int insert(T& element) {
	//Importante per la concorrenza degli accessi alla struttura
	stop.lock();

	this->heap.push_back(element);
	int ret = this->bubble_up(this->heap.size() - 1);

	stop.unlock();
	return ret;
}

template <
	class T,
	class Container = std::vector<T>,
	class less_then = std::less<typename Container::value_type>,
	class equal = std::equal_to<typename Container::value_type>
>
	int update_key(T& caller, int index) {
	int new_index;
	return new_index;
}
