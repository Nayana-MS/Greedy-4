1055. Shortest Way to Form String


Time O(NlogN) 
Space O(N)

class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, vector<int>>s;
        int n= source.size(), m = target.size(), j=0, cnt=1;
        for(int i =0; i<n; i++){
            s[source[i]].push_back(i);
        }
        
        int ind, last=-1;
        char l;
        while(j<m){
            l = target[j];
            if(!s.count(l)) return -1;
            ind = (upper_bound(s[l].begin(), s[l].end(), last) - s[l].begin());
            if(ind == s[l].size() || s[l][ind] < last){
                last =-1; cnt++;
            } else{
                last = s[l][ind]; j++;
            }
        }
        return cnt;
    }
};
