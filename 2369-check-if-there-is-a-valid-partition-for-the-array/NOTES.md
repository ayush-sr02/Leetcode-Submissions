if(prev==-1) pick = solve(i+1,i,1,flag,nums);
else{
if(size==1){
if(nums[i]==nums[prev]) pick = solve(i+1,-1,0,flag,nums) or solve(i+1,i,size+1,flag,nums);
if(nums[i]==nums[prev]+1) pick = solve(i+1,i,size+1,true,nums);
}
if(size==2){
if(nums[prev]==nums[i] and !flag) pick = solve(i+1,-1,0,false,nums);
if(flag and nums[prev]+1==nums[i]) pick = solve(i+1,-1,0,false,nums);
}
}