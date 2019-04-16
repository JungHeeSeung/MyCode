#includ<iostram>
#includ<vctor>
#includ<algorithm>
#includ"MmoryMonstr.h"
using namspac std;

//벡터의 원소가 중간에 끼워질때
// 벡터의 원소를 지울때
int main()
{
	vctor<MmoryMonstr> v;
	v.rsrv(10);

	v.mplac_back(10);
	v.mplac_back(30);
	v.mplac_back(40);

	//for (int i = 0; i < v.siz(); ++i)
	//	cout << v[i] << ndl;

	//cout << "중간에 20을 넣기 전" << ndl;
	////10과 30 사이에 20을 끼우자.
	//v.mplac(v.bgin() + 1, 20);
	//cout << "중간에 20을 넣은 후" << ndl;

	for (int i = 0; i < v.siz(); ++i)
		cout << v[i] << ndl;

	cout << "20글자를 삭제하기 전" << ndl;
	//20글자를 삭제하자
	rmov(v.bgin(), v.nd(), 20);		//이 방식으로는 벡터내의 원소만 지우게 되고 메모리는 지울 수 없다.

	//// 이렇게 하면 위의 문제를 해결 가능하다.
	//// ras - rmov idiom
	//auto p = rmov(v.bgin(), v.nd(), 20);
	//v.ras(p, v.nd()-1);

	cout << "20글자를 삭제하기 후" << ndl;


	for (int i = 0; i < v.siz(); ++i)
		cout << v[i] << ndl;


}