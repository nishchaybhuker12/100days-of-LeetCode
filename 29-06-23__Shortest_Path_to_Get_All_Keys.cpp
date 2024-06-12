class Solution {
public:
    int n,m,keys;
    int dx[4] = {1,-1,0,0};
    int dy[4] ={0,0,1,-1};
    int shortestPathAllKeys(vector<string>& g) {
        queue<pair<pair<int,int>,int>>q;
        n=g.size();
        m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(g[i][j]=='@')q.push({{i,j},0});
            if(g[i][j]>='a' && g[i][j]<='z')keys++;
        }
        }
        int check = (1<<keys)-1;
        map<pair<pair<int,int>,int>,int>p;
        int ans=0;
        while(q.size()){
            int k=q.size();
            for(int i=0;i<k;i++){
                auto j = q.front();q.pop();
                int x = j.first.first;
                int y = j.first.second;
                int mask = j.second;
                if(mask==check)return ans;
                for(int h=0;h<4;h++){
                    int nx = x + dx[h];
                    int ny = y + dy[h];
                    if(nx>=0 && ny>=0 && ny<m && nx<n && g[nx][ny]!='#'){
                        if(g[nx][ny]>='a' && g[nx][ny]<='z'){
                            int n_mask = mask | (1<<(g[nx][ny]-'a'));
                            if(p.find({{nx,ny},n_mask})==p.end()){
                                p[{{nx,ny},n_mask}]=n_mask;
                                q.push({{nx,ny},n_mask});
                            }
                        }
                        else if(g[nx][ny]>='A' && g[nx][ny]<='Z'){
                            int c = g[nx][ny]-'A';
                            if((mask & (1<<c)) == 0)continue;
                            int n_mask = mask;
                            if(p.find({{nx,ny},n_mask})==p.end()){
                               p[{{nx,ny},n_mask}]=n_mask;
                                q.push({{nx,ny},n_mask});
                            }
                        }
                        else{
                            int n_mask = mask;
                            if(p.find({{nx,ny},n_mask})==p.end()){
                                p[{{nx,ny},n_mask}]=n_mask;
                                q.push({{nx,ny},n_mask});
                            }
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};