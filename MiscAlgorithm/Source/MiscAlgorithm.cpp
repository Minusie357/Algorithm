#include "MiscAlgorithm.h"
#include "ExecuteInterface.h"


class AlgorithmExecutor : public IExecuteInterface
{
public:
	// 디폴트 생성자는 실행할 알고리즘에 대해 null로 초기화합니다.
	AlgorithmExecutor() = default;

	// 주어진 인터페이스로 알고리즘을 생성하는 생성자입니다.
	AlgorithmExecutor(IExecuteInterface* InExecute)
	{
		RegisterAlgorithm(InExecute);
	}



public:
	void RegisterAlgorithm(IExecuteInterface* InExecute)
	{
		if (InExecute == nullptr)
		{
			ALG_LOG("IExecuteInterface가 유효하지 않습니다");
			return;
		}

		AlgorithmToExecute = InExecute;
	}

	// 알고리즘 유효성을 체크하고 실행합니다.
	virtual void Execute() override
	{
		if (AlgorithmToExecute == nullptr)
		{
			ALG_LOG("해당 알고리즘이 유효하지 않습니다");
			return;
		}

		AlgorithmToExecute->Execute();
	}

private:
	IExecuteInterface * AlgorithmToExecute;
};





#include "Public\MazeRecursive.h"
#include "CountingCellsInBlob.h"
#include "NQueens.h"

static AlgorithmExecutor GAlgorithmExecutor;

#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> vec;

	/*	원소를 0에서 15까지 삽입합니다. */
	for (int i = 1; i <= 15; ++i)
	{
		vec.push_back(i);
	}

	/*	assign(std::initializer_list) 
	 *	결과 : 5 4 3 2 1 */
	vec.assign({ 5,4,3,2,1 });

	/*	assign(std::vector<T>::iterator, std::vector<T>::iterator>)
	 *	결과 : 8 7 6 5 4 3 2 */
	vector<int> vec_assign2 = { 2, 3, 4, 5, 6, 7, 8 };
	vec.assign(vec_assign2.rbegin(), vec_assign2.rend());

	/*	assign(const size_t, const T&)
	 *	결과 : 5 5 5 */
	vec.assign(3, 5);



	/*	push_back(T&& or const T&)
	 *	결과 : 5 5 5 3 */
	vec.push_back(3);



	/*	pop_back()
	 *	결과 : 5 5 5 */
	vec.pop_back();



	/*	insert(std::vector<T>::const_iterator, std::initializer_list)
	 *	결과 : 5 5 1 2 3 4 5 */
	vec.insert(vec.begin() + 2, { 1,2,3,4 });
	
	/*	insert(std::vector<T>::const_iterator, std;::vector<T>::iterator, std::vector<T>::iterator)
	 *	결과 : 10, 20, 30, 5, 5, 1, 2, 3, 4, 5 */
	vector<int> vec_insert2 = { 10, 20, 30, 40 };
	vec.insert(vec.begin(), vec_insert2.begin(), vec_insert2.end() - 1);

	/*	insert(std::vector<T>::const_iterator, const size_t, const T&)
	 *	결과 : 10, 20, 30, 5, 5, 1, 2, 3, 4, 5, 24, 24 */
	vec.insert(vec.end(), 2, 24);

	/*	insert(std::vector<T>::const_iterator, const T& or T&&)
	 *	결과 : 10, 20, 30, 40, 5, 5, 1, 2, 3, 4, 5, 24, 24*/
	vec.insert(vec.begin() + 3, 40);


	/*	erase(std::vector<T>::const_iterator)
	 *	결과 : 10, 20, 30, 40, 5, 5, 1, 2, 3, 4, 5, 24 
	 *	반환 : 삭제할 요소의 다음 요소의 위치를 가리키는 반복자 
	 *	경고 : 인자로 end()를 집어넣으면 미정의된 행동을 유발합니다. */
	vec.erase(vec.end() - 1);

	/*  erase(std::vector<T>::const_iteraotr, std::vector<T>::const_iterator)
	 *	결과 : 10, 20, 30, 40, 1, 2, 3, 4, 5, 24 */
	vec.erase(vec.begin() + 4, vec.begin() + 6);



	/*	swap(std::vector<T>&) 
	 *	결과 : 5, 4, 3, 2, 1 */
	vector<int> vec_swap = { 5, 4, 3, 2, 1 };
	vec.swap(vec_swap);

	

	/*	clear()
	 *	결과 : 아무 요소도 없음 */
	vec.clear();



	/*	emplace(std::vector<T>::iterator, T&&)
	 *	결과 : 5 */
	vec.emplace(vec.begin(), 5);

	
	
	/*	emplace_back(T&&)
	 *	결과 : 5, 10 */
	vec.emplace_back(10);
	

	return 0;
}

// 문제는 해당 알고리즘의 클래스 헤더 파일에서 정의합니다.
