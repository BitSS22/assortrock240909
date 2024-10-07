class parent
{
public:
	int i = 0;

	virtual int funci64(__int64 _value)
	{
		return 0;
	}
	virtual int funci(int _value)
	{
		return 0;
	}
	virtual int funcf(float _value)
	{
		return 0;
	}
};

class child : public parent
{
	float f = 0.f;

	int funci64(__int64 _value)
	{
		return 0;
	}
	int funci(int _value)
	{
		return 0;
	}
	int funcf(float _value)
	{
		return 0;
	}
};

int main()
{
	child inst = {};

	return 0;
}