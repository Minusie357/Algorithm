//#include <iostream>
//#include <vector>
//#include <map>
//#include <string>
//
//using namespace std;
//#pragma warning(disable:4996)
//
//int main(int argc, char** argv)
//{
//	int test_case;
//	int T;
//	/*
//	아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
//	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
//	//여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
//	freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
//	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
//	freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
//	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
//	*/
//	freopen("sample_input.txt", "r", stdin);
//	cin >> T;
//	/*
//	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
//	*/
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		multimap<char, int> cards;
//		vector<int> cardNums;
//		vector<char> cardColors;
//
//		long long G;
//		cin >> G;
//
//		long long modularHigh = 10;
//		long long modularLow = 100000000;
//
//
//		int cardNum;
//		for (int i = 0; i < 9; ++i)
//		{
//			cardNum = (G / modularLow) % modularHigh;
//			cardNums.push_back(cardNum);
//			modularLow /= 10;
//		}
//
//		char cardColor;
//		for (int i = 0; i < 9; ++i)
//		{
//			cin >> cardColor;
//			cardColors.push_back(cardColor);
//		}
//
//		auto it = cardNums.begin();
//		auto jt = cardColors.begin();
//		for (; it != cardNums.end() || jt != cardColors.end(); ++it, ++jt)
//		{
//			cards.insert(make_pair(*jt, *it));
//		}
//
//		//for (const auto& it : cards)
//		//{
//		//	cout << it.first << "\t" << it.second << "\n";
//		//}
//		//cout << "\n";
//
//		std::string ret;
//		if ((cards.count('R') % 3 != 0) ||
//			(cards.count('G') % 3 != 0) ||
//			(cards.count('B') % 3 != 0))
//		{
//			ret = "Continue";
//		}
//		else
//		{
//			// red 수색
//			pair<map<char, int>::iterator, map<char, int>::iterator> iterPair;
//			int setElems[3] = { -1,-1,-1 };
//			int setCount = 0;
//			char setType;
//			int totalSetCount = 0;
//			iterPair = cards.equal_range('R');
//			for (auto it = iterPair.first; it != iterPair.second; ++it)
//			{
//				//cout << "setElems : " << setElems[0] << setElems[1] << setElems[2] << '\n';
//				//cout << "setCount : " << setCount << "\n";
//				//cout << "setType : " << setType << "\n";
//				//cout << "totalSetCount : " << totalSetCount << "\n\n";
//
//				if (setCount == 0)
//				{
//					setElems[setCount++] = it->second;
//				}
//				else if (setCount == 1)
//				{
//					if (it->second == setElems[setCount - 1])
//					{
//						setElems[setCount++] = it->second;
//						setType = 'E';
//					}
//					else if (it->second == setElems[setCount - 1] + 1)
//					{
//						setElems[setCount++] = it->second;
//						setType = 'A';
//					}
//					else
//					{
//						break;
//					}
//				}
//				else if (setCount == 2)
//				{
//					if (setType == 'E')
//					{
//						if (it->second == setElems[setCount - 1])
//						{
//							totalSetCount++;
//							setCount = 0;
//							setType = 0;
//						}
//						else if (it->second == setElems[setCount - 1] + 1)
//						{
//							setElems[0] = setElems[1];
//							setElems[1] = it->second;
//							setType = 'A';
//						}
//						else
//						{
//							break;
//						}
//					}
//					else if (setType == 'A')
//					{
//						if (it->second = setElems[setCount - 1] + 1)
//						{
//							totalSetCount++;
//							setCount = 0;
//							setType = 0;
//						}
//						else if (it->second == setElems[setCount - 1])
//						{
//							setElems[0] = setElems[1];
//							setElems[1] = it->second;
//							setType = 'E';
//						}
//						else
//						{
//							break;
//						}
//					}
//				}
//			}
//
//			// green 수색
//			iterPair = cards.equal_range('G');
//			for (auto it = iterPair.first; it != iterPair.second; ++it)
//			{
//				//cout << "setElems : " << setElems[0] << setElems[1] << setElems[2] << '\n';
//				//cout << "setCount : " << setCount << "\n";
//				//cout << "setType : " << setType << "\n";
//				//cout << "totalSetCount : " << totalSetCount << "\n\n";
//
//				if (setCount == 0)
//				{
//					setElems[setCount++] = it->second;
//				}
//				else if (setCount == 1)
//				{
//					if (it->second == setElems[setCount - 1])
//					{
//						setElems[setCount++] = it->second;
//						setType = 'E';
//					}
//					else if (it->second == setElems[setCount - 1] + 1)
//					{
//						setElems[setCount++] = it->second;
//						setType = 'A';
//					}
//					else
//					{
//						break;
//					}
//				}
//				else if (setCount == 2)
//				{
//					if (setType == 'E')
//					{
//						if (it->second == setElems[setCount - 1])
//						{
//							totalSetCount++;
//							setCount = 0;
//							setType = 0;
//						}
//						else if (it->second == setElems[setCount - 1] + 1)
//						{
//							setElems[0] = setElems[1];
//							setElems[1] = it->second;
//							setType = 'A';
//						}
//						else
//						{
//							break;
//						}
//					}
//					else if (setType == 'A')
//					{
//						if (it->second = setElems[setCount - 1] + 1)
//						{
//							totalSetCount++;
//							setCount = 0;
//							setType = 0;
//						}
//						else if (it->second == setElems[setCount - 1])
//						{
//							setElems[0] = setElems[1];
//							setElems[1] = it->second;
//							setType = 'E';
//						}
//						else
//						{
//							break;
//						}
//					}
//				}
//			}
//
//			// BLUE 수색
//			iterPair = cards.equal_range('B');
//			for (auto it = iterPair.first; it != iterPair.second; ++it)
//			{
//				//cout << "setElems : " << setElems[0] << setElems[1] << setElems[2] << '\n';
//				//cout << "setCount : " << setCount << "\n";
//				//cout << "setType : " << setType << "\n";
//				//cout << "totalSetCount : " << totalSetCount << "\n\n";
//
//				if (setCount == 0)
//				{
//					setElems[setCount++] = it->second;
//				}
//				else if (setCount == 1)
//				{
//					if (it->second == setElems[setCount - 1])
//					{
//						setElems[setCount++] = it->second;
//						setType = 'E';
//					}
//					else if (it->second == setElems[setCount - 1] + 1)
//					{
//						setElems[setCount++] = it->second;
//						setType = 'A';
//					}
//					else
//					{
//						break;
//					}
//				}
//				else if (setCount == 2)
//				{
//					if (setType == 'E')
//					{
//						if (it->second == setElems[setCount - 1])
//						{
//							totalSetCount++;
//							setCount = 0;
//							setType = 0;
//						}
//						else if (it->second == setElems[setCount - 1] + 1)
//						{
//							setElems[0] = setElems[1];
//							setElems[1] = it->second;
//							setType = 'A';
//						}
//						else
//						{
//							break;
//						}
//					}
//					else if (setType == 'A')
//					{
//						if (it->second = setElems[setCount - 1] + 1)
//						{
//							totalSetCount++;
//							setCount = 0;
//							setType = 0;
//						}
//						else if (it->second == setElems[setCount - 1])
//						{
//							setElems[0] = setElems[1];
//							setElems[1] = it->second;
//							setType = 'E';
//						}
//						else
//						{
//							break;
//						}
//					}
//				}
//			}
//
//
//			if (totalSetCount == 3)
//			{
//				ret = "Win";
//			}
//			else
//			{
//				ret = "Continue";
//			}
//		}
//	
//		cout << '#' << test_case << " " << ret << "\n";
//
//
//
//	}
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}