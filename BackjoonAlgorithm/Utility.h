﻿#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;




/* 랜덤 라이브러리를 초기화하는 데 사용되는 플래그 */
static bool bInitRand = false;

/* 배열을 출력하는 함수입니다. */
template<typename T>
void Print(T* Array, unsigned int Start, unsigned int Size, unsigned int Line = 10)
{
	unsigned int Count = 0;
	for (unsigned int i = Start; i < Size; ++i)
	{
		cout << Array[i] << " ";

		Count++;
		if (Count % Line == 0 && Count != Size)
		{
			cout << endl;
		}
	}
	cout << endl;
}



template<typename T>
void Print2Dimen(T* Array, unsigned int RSize, unsigned int CSize, bool bSpace = true, unsigned int RStart = 0, unsigned int CStart = 0)
{
	for (unsigned int i = RStart; i < RSize; ++i)
	{
		for (unsigned int j = CStart; j < CSize; ++j)
		{
			cout << Array[i][j];
			if (bSpace)
				cout << " ";
			else
				cout << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

template<typename T>
void Print2Dimen(T* Array, unsigned int rStart, unsigned int rEnd, unsigned int cStart, unsigned int cEnd, int printWidth = 3)
{
	for (unsigned int i = rStart; i < rEnd; ++i)
	{
		for (unsigned int j = cStart; j < cEnd; ++j)
		{
			cout.width(printWidth);
			cout << Array[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

template<typename T>
void Print3Dimen(T* Array, unsigned int HSize, unsigned int RSize, unsigned int CSize, unsigned int HStart = 0, unsigned int RStart = 0, unsigned int CStart = 0)
{
	for (unsigned int i = HStart; i < HSize; ++i)
	{
		for (unsigned int j = RStart; j < RSize; ++j)
		{
			for (unsigned int k = CStart; k < CSize; k++)
			{
				cout << Array[i][j][k];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n";
}

/* 단일 테스트데이터를 생성하는 함수입니다. */
template<typename T>
T GenerateSingleTestData(T Floor, T Ceil)
{
	if (bInitRand == false)
	{
		srand((unsigned int)time(NULL));
		bInitRand = true;
	}

	if (Floor > Ceil) return Floor;

	T Data = rand() % (Ceil - Floor + 1) + Floor;
	return Data;
}



/* 원하는 수들 중에서 하나를 생성하는 이산적인 테스트데이터를 생성하는 함수입니다. */
template<typename T>
T GenerateDiscreteSingleTestData(const vector<T>& Elements)
{
	if (bInitRand == false)
	{
		srand((unsigned int)time(NULL));
		bInitRand = true;
	}


	if (Elements.size() == 1)
	{
		return Elements[0];
	}
	else
	{
		size_t Index = rand() % Elements.size();
		return Elements[Index];
	}
}



/* 테스트데이터를 생성하는 함수입니다. */
template<typename T>
void GenerateTestData(unsigned int NumData, T Floor, T Ceil, vector<T>& Output)
{
	if (bInitRand == false)
	{
		srand((unsigned int)time(NULL));
		bInitRand = true;
	}

	if (Floor > Ceil)	return;

	T SingleData;
	for (unsigned int i = 0; i < NumData; ++i)
	{
		SingleData = rand() % (Ceil - Floor + 1) + Floor;
		Output.push_back(SingleData);
	}
}

void GenerateTestString(unsigned int NumData, unsigned int MinLength, unsigned int MaxLength, vector<string>& Output);

std::string GenerateSingleTestString(unsigned int MinLength, unsigned int MaxLength);