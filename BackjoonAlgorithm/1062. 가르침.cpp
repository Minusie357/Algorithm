//#include <iostream>
//#include <cstring>
//#include <string>
//using namespace std;
//
//#ifdef _DEBUG
//#include "Utility.h"
//#endif // _DEBUG
//
//
//constexpr int INF = 987654321;
//constexpr int NUM_ALPHABET = 26;
//constexpr int nmax = 50;
//
//int n, k;
//int answer = 0;
//
//bool flag = false;
//bool check[NUM_ALPHABET] = { false };
//string word[nmax];
//void backtracking(const int num_char, int start, int count = 0)
//{
//	if (count == num_char)
//	{
//#ifdef _DEBUG
//		for (int i = 0; i < NUM_ALPHABET; ++i)
//			if (check[i] == flag)
//				cout << (char)(i + 'a') << " ";
//#endif // _DEBUG
//
//		int num_word = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			bool success = true;
//			for (const auto& it : word[i])
//			{
//				if (check[it - 'a'] == false)
//				{
//					success = false;
//					break;
//				}
//			}
//			if(success == true)
//				num_word++;
//		}
//
//#ifdef _DEBUG
//		cout << num_word << "\n";
//#endif // _DEBUG
//
//		if (answer < num_word)
//			answer = num_word;
//		return;
//	}
//
//	for (int i = start; i < NUM_ALPHABET; ++i)
//	{
//		char character = i + 'a';
//		if (character == 'a' || character == 'c' || character == 't' ||
//			character == 'i' || character == 'n')
//			continue;
//		check[i] = flag;
//		backtracking(num_char, i + 1, count + 1);
//		check[i] = !flag;
//	}
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> n >> k;
//
//	if (k < 5)
//	{
//		cout << 0 << "\n";
//		return 0;
//	}
//
//	string input;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> input;
//		word[i].reserve(input.size() - 8);
//		for (const auto it : input)
//		{
//			if (it == 'a' || it == 'c' || it == 't' || it == 'i' || it == 'n')
//				continue;
//
//			word[i].push_back(it);
//		}
//	}
//
//	
//	if (k - 5 >= NUM_ALPHABET - k)
//	{
//		flag = false;
//		for (int i = 0; i < NUM_ALPHABET; ++i)
//			check[i] = !flag;
//		backtracking(NUM_ALPHABET - k, 0, 0);
//	}
//	else
//	{
//		flag = true;
//		for (int i = 0; i < NUM_ALPHABET; ++i)
//			check[i] = !flag;
//		backtracking(k - 5, 0, 0);
//	}
//
//	cout << answer << "\n";
//	return 0;
//}