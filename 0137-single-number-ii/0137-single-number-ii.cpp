class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int k=0; k<=31; k++){
            int temp = (1<<k); // using this to check which bits are set and which are not later
            int zeroCnt = 0;
            int oneCnt = 0;
            for(auto &num: nums){
                if((num & temp) == 0) zeroCnt++;
                else oneCnt++;
            }
            if(oneCnt % 3 ==1) res = (res|temp);
        }
        return res;
    }
};