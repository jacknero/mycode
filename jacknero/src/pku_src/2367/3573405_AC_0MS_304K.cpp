#include <iostream>
#include <vector>
using namespace std;
 
#define MAX_NODE        101
 
int N;
vector<int> G[MAX_NODE];
int in[MAX_NODE]={0,};
int res[MAX_NODE];
 
bool toplogical_sort() {
        int i,t,front,rear;
 
        front=rear=1;
        for(i=1;i<=N;i++) if(in[i]==0) res[rear++]=i;
 
        while(front!=rear) {
                t = res[front++];
 
                for(i=G[t].size()-1;i>=0;i--) {
                        in[G[t][i]]--;
                        if(in[G[t][i]] == 0) {
                                res[rear++] = G[t][i];
                        }
                }
        }
 
        return front>N;
}
 
int main()
{
        int i,t;
 
        cin >> N;
        for(i=1;i<=N;i++) {
                for(;;) {
                        cin >> t;
                        if(t==0) break;
                        G[i].push_back(t);
                        in[t]++;
                }
        }
 
        toplogical_sort();
 
        for(i=1;i<=N;i++) cout << res[i] << " ";
        cout << endl;
 
        return 0;
}

