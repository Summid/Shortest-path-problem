#include<iostream>
#include<unordered_map>
#include<string>
#include<deque>
using namespace std;
using namespace stdext;

deque<string>deq;      //����һ����˫����У����ڴ�����Ҫ����Ԫ��
deque<string>done;    //����һ����˫����У����ڴ����Ѿ�������Ԫ��

string all[10][10] = { { "cat","dog","tiger" },{ "wolf","cow" },{ "cow" },{ "dragon","leopard" },{},{},{},{} };  //��ά���飬��һ���±�0��1��2���ζ�Ӧyou��cat��tiger���Դ�����
string you[10] = { "cat","dog","tiger" };   //0
string cat[10] = { "wolf","cow" };              //1
string tiger[10] = { "cow" };                      //2
string dog[10] = { "dragon","leopard" }; //3
string wolf[10] = {};                                   //4
string cow[10] = {};                                   //5
string dragon[10] = {};                             //6
string leopard[10] = {};                            //7

void Add(string num[10])        //�����ʼ���������Ԫ��
{
	for (int i = 0; i <= 10; i++)
	{
		if (num[i] == "")             //�������Ϊ�գ��Ͳ��ٸ��������Ԫ��
			break;
		else
		{
			deq.push_back(num[i]);
		}
	}
}

void add(string num)  //����֮����������Ԫ�أ��β�Ϊһ���ַ�����
{
	unordered_map<string, int>graph;   //����hash unordered map���ò�ͬ�ַ���ӳ�䵽��ͬ��Ψһ�����֣�������������Ϸ���ά����ĵ�һ���±��Ӧ
	graph["you"] = 0; graph["cat"] = 1; graph["tiger"] = 3; graph["dog"] = 4; graph["wolf"] = 5; graph["cow"] = 6;     //������ﶨ���ں���������ȫ�ֱ����ᱨ����֪��Ϊʲô
	graph["dragon"] = 7; graph["leopard"] = 8;

	for (int i = 0; i <= 10; i++)
	{
		if (all [graph [num] ] [i] == "")      //������ж�����  ���磺�β�numΪ�ַ�����cat������ôgraph[num]��������1��all [ graph[num] ] [i]�͵���all [1] [i]��������������Ķ�λ�����Ӧ������
			break;
		else
		{
			for (int j = 1; j <= done.size(); j++)        //done.size() ����done���е�Ԫ�ظ���
			{
				if (all[graph[num]][i] != done.at(j-1))           //�����forѭ�����������ĵط�XD
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
		if (deq.empty())    //����Ƿ��ǿն��У���������ж�Ϊ�棬������Ԫ����û�к��ʵ�Ԫ��
		{
			cout << "there is no result." << endl;
			system("pause");
			break;
		}

		else
		{
			if (if_person_is_investor(deq.front()))     //�жϴ�Ԫ���Ƿ��Ǻ��ʵ�Ԫ��
			{
				cout << deq.front() << " is who you are looking for" << endl;
				system("pause");
				return 0;
			}
			else
			{
				//string num=get_num(deq.front());
				done.push_back(deq.front());    //����Ԫ�ؼ��뵽�Ѽ����������ϣ����У�
				add(deq.front());        //����Ԫ�ص���������Ԫ����ӵ�����
				deq.pop_front();         //������Ԫ��
			}
		}
		
	}
}