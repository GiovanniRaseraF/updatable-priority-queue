#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <mutex>
#include <assert.h>
#include "updatable_observable.hpp"

using namespace std;

/*
Implementazione in c++ della coda con priorit� aggiornabile
Authot:		Giovanni Rasera
Git:		https://github.com/GiovanniRaseraF/updatable-priority-queue
*/
template <
	class T,
	//Un qualsiasi tipo di dato 

	class Container = std::vector<T>,
	/*
	Un vettore di tipo
	IN C# dovrai specificare che sono
	comparabili {ma non sono sicuro}
	*/

	class less_then = std::less<typename Container::value_type>,
	// Importante
	/*
	Questa riga della definizione del templase definisce la funzione con
	cui comparo gli elementi ed � ci� che mi permette di astrarre dal tipo
	di dato che inserisco

	Da notare che definisco less e quindi devo definire
	come viene eseguita l'operazione di:

	a     <    b     ?

	tu dovrai definire come vanno comparati a e b
	*/

	class equal = std::equal_to<typename Container::value_type>
>


public:
	/// <summary>
	/// Costruttore a cui devo specificare come comparare due elementi
	/// </summary>
	/// <param name="comp"> Comparatore di less ( a < b ?) </param>
	updatable_priority_queue(less_then& comp, equal& eq) : le_then{ comp }, eq{ eq }, heap{}{
		//int val = is_base_of<updatable_observable, T>::value;
		(is_base_of<updatable_observable, T>::value);
		//if (val == 0) exit(1);

	}

	////////Sezione legata al settaggio di valori

	/// <summary>
	/// Inserisce un elemento
	/// </summary>
	/// <param name="element"></param>
	int insert(T& element) {
		//Importante per la concorrenza degli accessi alla struttura
		stop.lock();

		this->heap.push_back(element);
		int ret = this->bubble_up(this->heap.size() - 1);

		stop.unlock();
		return ret;
	}

	int update_key(T& caller, int index) {
		int new_index;

		return new_index;
	}

	/*
	Sezione legata al get e non all'estrazione

	Questo vuol dire che nessuna di queste funzioni modifica parametri
	All'interno della coda
	*/

	/*
	<summary>
	Guarda una copia dell'elemento
	</summary>
	<param name="index"> indice </param>
	<returns> Una copia dell'elemento alla posisione specificata</returns>
	*/
	T lookat(int index) {
		//std::cout << "Index: " << index << std::endl;
		assert(index >= 0 && index < this->heap.size());
		//Copia
		T ret{ this->heap[index] };
		return ret;
	}

	/*
	<summary>
	Guardo alla copia dell'elemento 0 che � il Minimo
	</summary>
	 */
	T peek() {
		if (this->heap.empty()) return nullptr;
		//Copio l'elemento 0
		T ret{ this->heap[0] };
		return ret;
	}

	/*
	<summary>
	guardo all'elemento 0 che � il minimo
	</summary>
	*/
	T& peek_address() {
		if (this->heap.empty()) return nullptr;
		return this->heap[0];
	}

	int size() {
		return this->heap.size();
	}

	bool empty() {
		return this->heap.empty();
	}

private:
	/*
	<summary>
	Ci permette di inserire un valore nella up_pr_queue
	</summary>
	<complexity>
	O(log2(this->size()))		->		se ho 100 elementi faccio massimo log2(100) = 6
										   iterazioni nel while
	</complexity>
	*/
	int bubble_up(int ind) {
		int index = ind;
		T element = this->heap[index];
		T parent = element;
		int parentIndex = 0;

		while (index > 0) {
			parentIndex = ((index + 1) / 2) - 1;
			parent = this->heap[parentIndex];
			//Controllo
			if (!this->le_then(element, parent) && !this->eq(element, parent)) {
				//Mi fermo se ho gia messo apposto la heap
				break;
			}
			//Mi sposto sul parent
			this->heap[parentIndex] = element;
			this->heap[index] = parent;
			index = parentIndex;
		}

		return index;
		//cout << "Index: " << index << " ParentIndex: " << parentIndex << endl;
	}

	int sink_down(int index) {
		int length = this->heap.size();
		T element = this->heap[index];
		int swapIndex = 0;

		while (true) {
			int rightChildIndex = (index + 1) * 2;
			int leftChildIndex = rightChildIndex - 1;
			swapIndex = -1;

			if (leftChildIndex < length) {
				T& leftChild = this->heap[leftChildIndex];

				if (this->le_then(leftChild, element)) swapIndex = leftChildIndex;

				if (rightChildIndex < length) {
					const T& rightChild = this->heap[rightChildIndex];
					if ((swapIndex == -1 || this->le_then(rightChild, leftChild)) && this->le_then(rightChild, element)) {
						swapIndex = rightChildIndex;
					}
				}
			}

			if (swapIndex == -1) {
				break;
			}

			std::swap(this->heap[index], this->heap[swapIndex]);
			index = swapIndex;
		}
		return 0;
	}
};


