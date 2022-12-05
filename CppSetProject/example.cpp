#include "GameSet.h"
#include "DrawCard.h"

using namespace std;

int main() {
	cout << "Set 시작" << endl;

	// 기본 규칙
	// 1. 패 생성
	// 2. 셔플해서 12개 spread
	// 3. 짝이 있는지 갯수 확인 => 없으면 3개 더 오픈
	// 4. 유저가 세트를 찾으면 그 공간만 지우고 3개 더 spread
	// 5. 더이상 카드도 없고, 짝도 없으면 종료

	// 추가 기능하면 좋을 것
	// 1. 기록 찾기
	// 2. 힌트 보여주기
	// 3. 멀티플레이

	GameSet test;

	// 맵그리기
	test.PrintMap(0, 0, 3, 5);

	int x, y, z;
	bool result = false;
	
	while (test.CheckTotSet()) {
		cout << "SET를 입력하세요" << endl;
		cin >> x >> y >> z;
		result = test.ChoiceCard(x, y, z);
		if (result) {
			test.PrintMap(0, 0, 3, 5);
		}
	}
	cout << "더 이상 set가 없습니다" << endl;
}