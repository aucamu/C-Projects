#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;

typedef long int typ;

void findNumber(promise<typ>&& valuePromise, typ start, typ end)
{
	typ value = 0;
	
	for(typ i = start; i < end; i++)
	{
		if(i & 1)
		{
			value ++;
		}
	}
	
	valuePromise.set_value(value);
}

int main ()
{
	typ start = 0;
	typ end = 1000;
	
	promise<typ> value;
	future<typ> valuePromise = value.get_future();
	
	thread th1(findNumber,move(value),start,end);
	
	
	cout << "valuePromise: " << valuePromise.get() << endl;
	
	th1.join();
	return 0;
	
}
