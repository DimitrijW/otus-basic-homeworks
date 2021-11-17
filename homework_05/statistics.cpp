#include <iostream>
#include <math.h>

class IStatistics
{
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char* name() const = 0;
};

class Min : public IStatistics
{
public:
	Min() : m_min{0}, i{0} {
	}
	void update(double next) override
	{
		while (i < 1)
		{
			m_min = next;
			i++;
		}
		if (next <= m_min)
		{
			m_min = next;
		}
	}

	double eval() const override
	{
		return m_min;
	}

	const char* name() const override
	{
		return "min";
	}

private:
	double m_min;
	int i;
};

class Max : public IStatistics
{
public:
	Max() : m_max{0}, i{0} {
	}
	void update(double next) override
	{
		while (i < 1)
		{
			m_max = next;
			i++;
		}
		if (next >= m_max)
		{
			m_max = next;
		}
	}

	double eval() const override
	{
		return m_max;
	}

	const char* name() const override
	{
		return "max";
	}

private:
	double m_max;
	int i;
};

class Mean : public IStatistics
{
public:
	Mean() : m_mean{0}, sum{0}, i{0} {
	}
	void update(double next) override
	{
		sum += next;
		i++;
		m_mean = sum / i;
	}

	double eval() const override
	{
		return m_mean;
	}

	const char* name() const override
	{
		return "mean";
	}

private:
	double m_mean;
	double sum;
	int i;
};

class Std : public IStatistics
{
public:
	Std() : m_std{0}, sum{0}, m_mean{0}, i{1}, arr{0} {
	}

	void update(double next) override
	{
		double quad_std = 0;
		double x = 0;
		arr[i] = next;
		sum += next;
		m_mean = sum / i;
		i++;
		for (int j = 1; j < i; j++)
		{
			quad_std += abs((arr[j] - m_mean) * (arr[j] - m_mean));
			x = quad_std;
			x /= (i);
		}
		m_std = sqrt(x);
	}

	double eval() const override
	{
		return m_std;
	}

	const char* name() const override
	{
		return "std";
	}

private:
	double m_std;
	double sum;
	double m_mean;
	int i;
	double arr[100];

};
int main()
{
	const size_t statistics_count = 4;
	IStatistics* statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};

	double val = 0;
	while (std::cin >> val)
	{
		for (size_t i = 0; i < statistics_count; ++i)
		{
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good())
	{
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i)
	{
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i)
	{
		delete statistics[i];
	}

	return 0;
}