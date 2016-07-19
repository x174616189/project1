#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int t, n, m;
int a[6];
int vis[6][6];
char s[7];

int main()
{
    while(~scanf("%d", &n)) {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            int len = strlen(s);
            for(int j = 0; j < len; j++) {
                vis[i][s[j]-'0'] = 1;
            }
        }

        for(int i = 0; i < 6; i++) {
            a[i] = i;
        }

        int ans = 0;
        map <int, int> mp;
        do {
            int tot = 0;
            for(int i = 0; i < n; i++) {
                tot = tot*10 + a[i];
            }
            if(!mp[tot]) {
                mp[tot] = 1;
            }
            else {
                continue;
            }
            //printf("-");
            int ff = 1;
            for(int i = 0; i < n; i++) {
                if(vis[i][a[i]]) {
                    continue;
                }
                else {
                    ff = 0;
                    break;
                }
            }
            if(ff) {
                ans++;
            }
        }
        while(next_permutation(a, a+6));

        printf("%d\n", ans);
    }
    return 0;
}