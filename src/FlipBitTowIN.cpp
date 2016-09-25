//============================================================================
// Name        : FlipBitTowIN.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
using namespace std;


int flipToBitToWin(int bit)
{
	int bitToCompare = 1;
	int currentBit;

	int bitCount = 0;
	int zeroCount = 0;
	int maxBitCount = 0;

	while(bit > 0)
	{
		//check if current bit is 1
		currentBit = bit & bitToCompare;

		if(currentBit > 0)
		{
			bitCount++;
			if(maxBitCount < bitCount)
				maxBitCount = bitCount;
		}
		else
		{
			zeroCount++;
			//if this is second time zero
			if(zeroCount > 1)
			{
				//reset zero count
				zeroCount = 1;

				if(maxBitCount < bitCount)
					maxBitCount = bitCount;

				//reset bitCount
				bitCount = 1;

			}
			else //first 0 bit
			{
				bitCount++;
				zeroCount++;
			}
		}


		//move bit to compare
		bit = (bit >> 1);

	}

	return maxBitCount;
}


int main()
{
	int num = 1775;
	cout << bitset<12>(num) << endl;


	cout << flipToBitToWin(num);



	return 0;
}
