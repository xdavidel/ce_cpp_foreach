#include <iostream>

typedef size_t uint;

class DoubleSum 
{
private:
	double &m_sum;

public:
	DoubleSum(double &sum):m_sum(sum)
	{}

	void operator()(double val)
	{
		m_sum += val;
	}

	double GetSum() const
	{
		return m_sum;
	}

};

template<typename T, typename ACTION>
void Foreach(T* arr, uint size, ACTION action)
{
	for (uint i = 0; i < size; i++)
	{
		T elem = arr[i];
		action(elem);
	}
}

template<typename T>
void Print(T item)
{
	std::cout << item << " ";
}

int main()
{
	int intArr[] = { 1, 4, 5 };
	double doubleArr[] = { 3.2, 1, 7.3, -7.12, 4 };

	double sum = 0.0;
	DoubleSum doubleSum(sum);

	// Print Int array using Foreach
	Foreach(intArr, 3, Print<int>);
	std::cout << std:: endl;

	// Sum double array using Foreach
	Foreach(doubleArr, 3, doubleSum);
	std::cout << "Sum= "<< doubleSum.GetSum() << std::endl;

	sum = 0;
	// Sum double element using Foreach and lambda
	Foreach(doubleArr, 3, [&sum](double element) {sum += element; });
	std::cout << "Sum with labmda= " << doubleSum.GetSum() << std::endl;

	return 0;
}