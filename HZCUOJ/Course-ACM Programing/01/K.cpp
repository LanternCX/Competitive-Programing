// 万能头文件
#include <bits/stdc++.h>
using namespace std;
// 病人结构体
struct node{
    // 病人编号
    int id;
    // 要求的医生 A
    int a;
    // 病人优先级 B
    int b;
    // 重载运算符 > ，提供给优先队列进行比较
	bool operator > (const node &x) const {
        // 若优先权相同则按照病人编号比较
		if(b == x.b){
			return id > x.id;
		}
        // 优先权不同优先权高的病人先进行诊治
		return b < x.b;
	} 
};
void slove(){
    // 发生事件的数目
	int n;
    // 通过判断是否到达 EOF 判断输入是否结束
	while(cin >> n){
        // 初始化优先队列，由于最多只有 3 个医生可以直接初始化优先队列大小为 3
		vector<priority_queue<node, vector<node>, greater<node>>> pq(3);
		// 初始化病人编号为 0
        int id = 0;
		for(int i = 0; i < n; i++){
            // 读取当前事件的操作
			string op;
			cin >> op;
            // 如果是 IN 事件
			if(op == "IN"){
                // 读入要求的医生和优先级
				int a, b;
				cin >> a >> b;
                // 对齐到 0 开头数组
				a--;
                // 更新编号
				id++;
                // 将病人结构体推入优先队列
				pq[a].push({id, a, b});
			}
            // 如果是 OUT 事件
			if(op == "OUT"){
                // 读入医生编号
				int a;
				cin >> a;
                // 对齐到 0 开头数组
				a--;
                // 如果当前医生的排队列表为空则打印 EMPTY 并执行下一个循环
				if(pq[a].empty()){
					cout << "EMPTY\n";
					continue;
				}
                // 打印需要诊治的病人编号
				cout << pq[a].top().id << '\n';
                // 将病人移除出优先队列
				pq[a].pop();
			}
		}
	}
}
int main(){
    // 关闭同步流，快读快写
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        slove();
    }
    return 0;
}