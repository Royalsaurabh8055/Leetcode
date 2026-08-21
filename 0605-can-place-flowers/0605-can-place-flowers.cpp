class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int cnt = n;
        int N = flowerbed.size();
        for(int i=0; i<flowerbed.size();i++)
        {
            if(flowerbed[i] == 0 && (i ==0 ||flowerbed[i-1]==0) &&  (i == N-1 ||flowerbed[i+1]==0))
            {
                cnt--;
                flowerbed[i] = 1;
            }
        }
        if(cnt <= 0) return true;

        else return false;
    }
};