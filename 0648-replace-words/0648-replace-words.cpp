class Solution {
public:
    string replaceWords(vector<string>& dic, string sentence) {
        string ans="";
        stringstream ss(sentence);
        vector<string> v;
        string word;
        while(ss>>word) v.push_back(word);
        sort(begin(dic),end(dic));
        for(int i=0;i<v.size();i++){
            bool flag=true;
            for(int j=0;j<dic.size();j++){
                if(v[i].size()>=dic[j].size()){
                    string temp=v[i].substr(0,dic[j].size());
                    if(temp==dic[j]){
                        ans+=dic[j]+' ';
                        flag=false;break;
                    } 
                }
            }
            if(flag) ans+=v[i]+' ';
        }
        ans.pop_back();
        return ans;
    }
};