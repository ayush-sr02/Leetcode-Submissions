class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        string word;
        map<string,vector<string>> mp;

        for(int i=0;i<paths.size();i++){
            stringstream str(paths[i]);
            string word;
            string xd="";
            int j=0;
            while(str>>word){
                j++;
                if(j==1){
                    xd=word;
                    continue;
                }
                string temp=word;
                string temp1;
                int a=0;
                while(a<temp.size() and temp[a]!='('){
                    temp1+=temp[a];
                    a++;
                }
                temp="";
                a++;
                while(a<word.size() and temp[a]!=')'){
                    temp+=word[a];
                    a++;
                }
                // cout<<temp<<" ";
                string xx = xd+'/'+temp1;
                mp[temp].push_back(xx);
            }
        }
        for(auto i:mp){
            vector<string> x = i.second;
            if(x.size()>1){
                vector<string> sol;
                for(auto j:x) sol.push_back(j);
                ans.push_back(sol);
            }
        }
        return ans;
    }
};
