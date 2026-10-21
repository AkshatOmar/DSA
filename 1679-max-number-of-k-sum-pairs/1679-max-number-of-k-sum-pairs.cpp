class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++) {
            mp[nums[i]]++;
        }
        int cnt = 0;
        for(int i = 0;i<n;i++) { 
            if(mp[nums[i]]<=0) continue;
            
                if(nums[i] == k-nums[i]){
                    if( mp[nums[i]] >= 2) { 
                    cnt++;
                    mp[nums[i]]-= 2;
                    
                    }
                }
                else {
                    
                    if(mp[k-nums[i]]>0){
                        cnt++;
                         mp[nums[i]]--;
                        mp[k-nums[i]]--;
                    
                    }
                   
                }
                
            
        }
        return cnt;
    }
};