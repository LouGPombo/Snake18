#pragma once
class Cell
{
private:

	int _material;
public:
	Cell(); //Constructor
	Cell(int material); //Overload Constructor
	Cell(Cell & cell1); //Copy Constructor
	~Cell(); //Destructor
	void setMaterial(int newMaterial);
	int getMaterial();
};