#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <mutex>
#include <assert.h>
/*
Implementazione in c++ della coda con priorità aggiornabile
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

 	class Compare = std::less<typename Container::value_type> 
	// Importante
	/*
	Questa riga della definizione del templase definisce la funzione con 
	cui comparo gli elementi ed è ciò che mi permette di astrarre dal tipo
	di dato che inserisco

	Da notare che definisco less e quindi devo definire
	come viene eseguita l'operazione di:

	a     <    b     ?

	tu dovrai definire come vanno comparati a e b
	*/
>

class UpdatablePriorityQueue{
private:
	Container heap;
	Compare	comparatore;

public:
	/// <summary>
	/// Costruttore a cui devo specificare come comparare due elementi
	/// </summary>
	/// <param name="comp"> Comparatore di less ( a < b ?) </param>
	UpdatablePriorityQueue(Compare& comp) : comparatore{ comp }, heap{}{}
	
	
	////////Sezione legata al get e non all'estrazione !!////
	/*
	Questo vuol dire che nessuna di queste funzioni modifica parametri
	All'interno della coda
	*/

	const T lookat(int index) {
		assert(index >= 0 && index < this->heap.size());
		//Copia
		T ret{ this->heap[index]};
		return ret;
	}




private:
	//TODO


};


int main() {
	using namespace std;
	cout << "hello";
	return 0;
}