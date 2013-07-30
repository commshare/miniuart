class Animal{
	int itsWeight;
	int itsAge;
public:
	void setValue(int ,int);
};

void Animal::setValue(int tw,int tn)
{
	itsWeight = tw;
	itsAge = tn;
}

int main()
{
	Animal peppy;
	peppy.setValue(7,9);
	return 0;
}
