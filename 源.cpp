#include<iostream>
#include<unordered_map>
#include<string>
#include<deque>
using namespace std;
using namespace stdext;

deque<string>deq;      //建立一个空双向队列，用于储存需要检查的元素
deque<string>done;    //建立一个空双向队列，用于储存已经检查过的元素

string all[10][10] = { { "cat","dog","tiger" },{ "wolf","cow" },{ "cow" },{ "dragon","leopard" },{},{},{},{} };  //二维数组，第一个下标0、1、2依次对应you、cat、tiger，以此类推
string you[10] = { "cat","dog","tiger" };   //0
string cat[10] = { "wolf","cow" };              //1
string tiger[10] = { "cow" };                      //2
string dog[10] = { "dragon","leopard" }; //3
string wolf[10] = {};                                   //4
string cow[10] = {};                                   //5
string dragon[10] = {};                             //6
string leopard[10] = {};                            //7

void Add(string num[10])        //用于最开始给队列添加元素
{
	for (int i = 0; i <= 10; i++)
	{
		if (num[i] == "")             //如果数组为空，就不再给队列添加元素
			break;
		else
		{
			deq.push_back(num[i]);
		}
	}
}

void add(string num)  //用于之后给队列添加元素（形参为一个字符串）
{
	unordered_map<string, int>graph;   //建立hash unordered map，让不同字符串映射到不同且唯一的数字，且这个数字与上方二维数组的第一个下标对应
	graph["you"] = 0; graph["cat"] = 1; graph["tiger"] = 3; graph["dog"] = 4; graph["wolf"] = 5; graph["cow"] = 6;     //如果这里定义在函数外面做全局变量会报错，不知道为什么
	graph["dragon"] = 7; graph["leopard"] = 8;

	for (int i = 0; i <= 10; i++)
	{
		if (all [graph [num] ] [i] == "")      //这里的判断条件  比如：形参num为字符串“cat”，那么graph[num]等于数字1，all [ graph[num] ] [i]就等于all [1] [i]，这样就与上面的二位数组对应起来了
			break;
		else
		{
			for (int j = 1; j <= done.size(); j++)        //done.size() 返回done队列的元素个数
			{
				if (all[graph[num]][i] != done.at(j-1))           //这里的for循环是最难理解的地方XD
					if(j==done.size())   
						deq.push_back(all[graph[num]][i]);
					else
						continue;
				else
					break;
			}
		}
	}
}

//int if_person_is_checked(string num)
//{
//
//}

int if_person_is_investor(string num)
{
	if (num=="leopard")
		return true;
	else
		return false;
}

//string get_num(string num)
//{
//	return num;
//}

int main()
{
	//unordered_map<string,int>graph;
	//graph["you"] = 0; graph["cat"] = 1; graph["tiger"] = 3; graph["dog"] = 4; graph["wolf"] = 5; graph["cow"] = 6;
	//graph["dragon"] = 7; graph["leopard"] = 8;
	//cout << graph["you"];

	Add(you);

	while (true)
	{
		if (deq.empty())    //检查是否是空队列，如果条件判断为真，则被搜索元素中没有合适的元素
		{
			cout << "there is no result." << endl;
			system("pause");
			break;
		}

		else
		{
			if (if_person_is_investor(deq.front()))     //判断此元素是否是合适的元素
			{
				cout << deq.front() << " is who you are looking for" << endl;
				system("pause");
				return 0;
			}
			else
			{
				//string num=get_num(deq.front());
				done.push_back(deq.front());    //将此元素加入到已检查过的名单上（队列）
				add(deq.front());        //将此元素的所有相邻元素添加到队列
				deq.pop_front();         //弹出此元素
			}
		}
		
	}
}