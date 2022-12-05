#include "GameSet.h"
#include "DrawCard.h"

using namespace std;

int main() {
	cout << "Set ����" << endl;

	// �⺻ ��Ģ
	// 1. �� ����
	// 2. �����ؼ� 12�� spread
	// 3. ¦�� �ִ��� ���� Ȯ�� => ������ 3�� �� ����
	// 4. ������ ��Ʈ�� ã���� �� ������ ����� 3�� �� spread
	// 5. ���̻� ī�嵵 ����, ¦�� ������ ����

	// �߰� ����ϸ� ���� ��
	// 1. ��� ã��
	// 2. ��Ʈ �����ֱ�
	// 3. ��Ƽ�÷���

	GameSet test;

	// �ʱ׸���
	test.PrintMap(0, 0, 3, 5);

	int x, y, z;
	bool result = false;
	
	while (test.CheckTotSet()) {
		cout << "SET�� �Է��ϼ���" << endl;
		cin >> x >> y >> z;
		result = test.ChoiceCard(x, y, z);
		if (result) {
			test.PrintMap(0, 0, 3, 5);
		}
	}
	cout << "�� �̻� set�� �����ϴ�" << endl;
}