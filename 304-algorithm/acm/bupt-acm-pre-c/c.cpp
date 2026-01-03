#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>

using namespace std;

struct Node  
{  
    int key;  
    int flag;  
    Node(int x)  
    {  
        key = x;
        flag=0;  
    }  
};

int global_n;

void FindAllPath(vector<vector<int> >& Matrix, Node startNodeKey, 
    Node endNodeKey, stack<Node>& tempStack, bool* Mark, int* result,
    int& pathNum, int& nPos, int NUM, vector<vector<int> >& resultPath) {  
    result[nPos]=startNodeKey.key;  //将当前元素放入结果集中  
    Mark[startNodeKey.key-1]=true;  //将访问标记为已访问  
    nPos++;  //结果集索引加1  
    while(nPos!=0)
    {
        int tempVal=result[nPos-1];//获取到最前面的元素
        if (tempVal==endNodeKey.key)  //若当前元素为目标节点
        {
            vector<int> path;
            for (int j=0; j<nPos; j++)    
            {
                path.push_back(result[j]);
            }
            resultPath.push_back(path);
            nPos--;  //回溯至上一个节点  
            result[nPos]=0;  //结果集对应索引置为空  
            pathNum++;  //路径数目加1  
            Mark[endNodeKey.key-1]=false;
            break;
        }
        while(startNodeKey.flag<NUM)//利用flag来指示每次的元素的索引    
        {
            if (Matrix[tempVal-1][startNodeKey.flag]==1)    
            {
                if (Mark[startNodeKey.flag]==false)//利用Mark来判断是否已经访问过该节点    
                {
                    Node tempNode(startNodeKey.flag + 1);
                    FindAllPath(Matrix, tempNode, endNodeKey, 
                        tempStack, Mark, result, pathNum, 
                        nPos, NUM, resultPath);
                }
            }
            startNodeKey.flag++;//索引值相应的加一    
        }

        if (startNodeKey.flag==NUM)//如果已经是到最后的邻居，说明访问结束，    
        {
            nPos--;  //再次向上回溯  
            startNodeKey.flag=0;  //将节点的索引置为空  
            result[nPos]=0;  //将结果集中对应的索引置为空  
            Mark[startNodeKey.key-1]=false;  //访问之后标记为未访问。因为下面的元素已经访问结束，便于下次的访问  
            break;
        }
    }
}  



int  main(void) {
	ifstream infile;
	//infile.open("test.txt");
	int n, m;
	//infile >> n >> m;
    cin >> n >> m;
    global_n = n;
    int n_temp = n;
    std::vector<int> color_vector;
	while (n_temp--) {
		int col;
		// infile >> col;
        cin >> col;
		color_vector.push_back(col);
	}
    vector<int> temp_v(n, 0);
    vector<vector<int> > adj_matrix(n, temp_v);
    n_temp = n - 1;
    while (n_temp--) {
        int i, j;
        // infile >> i >> j; 
        cin >> i >> j; 
        adj_matrix[i - 1][j - 1] = 1;
    }

    char c;
    cin.get(c);
    // infile.get(c);

    while (m--) {
        //infile.get(c);
        cin.get(c);
        if (c == 'E') {
            for (int temp_idx = 0; temp_idx < 2; temp_idx++) {
                // infile.get(c);
                cin.get(c);
            }
            int number_n, new_color;
            //infile >> number_n >> new_color;
            cin >> number_n >> new_color;
            color_vector[number_n - 1] = new_color;
            //infile.get(c);
            cin.get(c);

        } else if (c == 'A') {
            for (int temp_idx = 0; temp_idx < 3; temp_idx++) {
                // infile.get(c);
                cin.get(c);
            }

            int b, e, target_color;
            //infile >> b >> e >> target_color;
            cin >> b >> e >> target_color;
            // infile.get(c);
            cin.get(c);
            // 找所有b到e的路径，计算target_color颜色占所有颜色的q/p，输出“q p”

            stack<Node> tempStack;
            Node headNode(b);//起始节点  
            Node endNode(e);//终止节点  
            bool Mark[n];
            memset(Mark, false, n);
            int result[n + 1];
            memset(result, 0, n + 1);
            vector<vector<int> > resultPath;
            int pathNum = 0;  
            int nPos = 0;  
            FindAllPath(adj_matrix, headNode, endNode, tempStack, Mark, result, 
            pathNum, nPos, n, resultPath);
            int all_nodes_on_all_paths = 0, target_color_nodes = 0;
            for (int i = 0; i < resultPath.size(); i++) {
                for (int j = 0; j < resultPath[i].size(); j++) {
                    if (color_vector[resultPath[i][j] - 1] == target_color) {
                        target_color_nodes++;
                    }
                    all_nodes_on_all_paths++;
                }
            }
            cout << target_color_nodes << " " << all_nodes_on_all_paths << endl;

        }
    }
	return 0;
}





  
