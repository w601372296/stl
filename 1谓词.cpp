#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void printVector(int v)
{
	cout << v<< "  ";
}
bool greaterThan(int v)//��ͨ����Ѱ�Ҵ���20
{
	return v > 20;
}
class MyCompare
{
public://��������С���ŷº�����Ԫν�ʵ���
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
	bool operator()(int v)
	{//С�������طº���һԪν�ʵ���Ѱ�ұ�20���Ԫ��
		return v > 20;
	}
};
void test()
{
	vector<int>v;
	v.push_back(30);
	v.push_back(20);
	v.push_back(10);
	v.push_back(40);
	sort(v.begin(), v.end());//��������vector
	for_each(v.begin(), v.end(), printVector);
	cout << endl;
	sort(v.begin(), v.end(),MyCompare());//��������vector
	for_each(v.begin(), v.end(), printVector);//��ͨ��������
	//Ҳ������lambda���ʽ��������ʽӦ�������溯������д
	for_each(v.begin(), v.end(), [](int val) {cout << val; });
	cout << endl;//MyCompare�º���ν����С����
	vector<int>::iterator it=find_if(v.begin(), v.end(), MyCompare());
	if (it != v.end())
	{
		cout << "�ҵ���Ԫ�أ�" << *it << endl;
	}
	else
	{
		cout << "û���ҵ���" << endl;
	}//greaterThan��ͨ����ν��û��С���ż���С���ž���   �ص�����
	vector<int>::iterator pos = find_if(v.begin(), v.end(), greaterThan);
	if (pos != v.end())
	{
		cout << "�ҵ���Ԫ�أ�" << *it << endl;
	}
	else
	{
		cout << "û���ҵ���" << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}