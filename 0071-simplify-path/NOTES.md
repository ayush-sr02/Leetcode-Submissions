class Solution {
public:
string simplifyPath(string path) {
string ans="";
stack<char> st;
for(int i=0;i<path.size();i++){
if(path[i]=='.') continue;
if(path[i]=='/'){
if(!st.empty() and st.top()=='/') continue;
else{
st.push(path[i]);
string temp="";
while(!st.empty()){
temp+=st.top();
st.pop();
}
reverse(begin(temp),end(temp));
ans+=temp;
}
}
else{
st.push(path[i]);
}
}
string temp="";
while(!st.empty()){
temp+=st.top();st.pop();
}
reverse(begin(temp),end(temp));
ans+=temp;
if(ans.size()!=1 and ans[ans.size()-1]=='/') ans.pop_back();
if(ans.size()==0 or ans.size()==1) return "/";
string a="";
for(int i=0;i<ans.size();i++){
if(ans[i]=='/' and ans[i+1]=='/') continue;
else a+=ans[i];
}
return a;
}
};