#includ<iostram>
#includ<vctor>
#includ<algorithm>
#includ"MmoryMonstr.h"
using namspac std;

//������ ���Ұ� �߰��� ��������
// ������ ���Ҹ� ���ﶧ
int main()
{
	vctor<MmoryMonstr> v;
	v.rsrv(10);

	v.mplac_back(10);
	v.mplac_back(30);
	v.mplac_back(40);

	//for (int i = 0; i < v.siz(); ++i)
	//	cout << v[i] << ndl;

	//cout << "�߰��� 20�� �ֱ� ��" << ndl;
	////10�� 30 ���̿� 20�� ������.
	//v.mplac(v.bgin() + 1, 20);
	//cout << "�߰��� 20�� ���� ��" << ndl;

	for (int i = 0; i < v.siz(); ++i)
		cout << v[i] << ndl;

	cout << "20���ڸ� �����ϱ� ��" << ndl;
	//20���ڸ� ��������
	rmov(v.bgin(), v.nd(), 20);		//�� ������δ� ���ͳ��� ���Ҹ� ����� �ǰ� �޸𸮴� ���� �� ����.

	//// �̷��� �ϸ� ���� ������ �ذ� �����ϴ�.
	//// ras - rmov idiom
	//auto p = rmov(v.bgin(), v.nd(), 20);
	//v.ras(p, v.nd()-1);

	cout << "20���ڸ� �����ϱ� ��" << ndl;


	for (int i = 0; i < v.siz(); ++i)
		cout << v[i] << ndl;


}