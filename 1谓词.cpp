#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void printVector(int v)
{
	cout << v<< "  ";
}
bool greaterThan(int v)//普通函数寻找大于20
{
	return v > 20;
}
class MyCompare
{
public://降序重载小括号仿函数二元谓词调用
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
	bool operator()(int v)
	{//小括号重载仿函数一元谓词调用寻找比20大的元素
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
	sort(v.begin(), v.end());//升序排序vector
	for_each(v.begin(), v.end(), printVector);
	cout << endl;
	sort(v.begin(), v.end(),MyCompare());//降序排序vector
	for_each(v.begin(), v.end(), printVector);//普通函数调用
	//也可以用lambda表达式：这个表达式应该是上面函数的缩写
	for_each(v.begin(), v.end(), [](int val) {cout << val; });
	cout << endl;//MyCompare仿函数谓词有小括号
	vector<int>::iterator it=find_if(v.begin(), v.end(), MyCompare());
	if (it != v.end())
	{
		cout << "找到了元素：" << *it << endl;
	}
	else
	{
		cout << "没有找到！" << endl;
	}//greaterThan普通函数谓词没有小括号加上小括号就是   回调函数
	vector<int>::iterator pos = find_if(v.begin(), v.end(), greaterThan);
	if (pos != v.end())
	{
		cout << "找到了元素：" << *it << endl;
	}
	else
	{
		cout << "没有找到！" << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}