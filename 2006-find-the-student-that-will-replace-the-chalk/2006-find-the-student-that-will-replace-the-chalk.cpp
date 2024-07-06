class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum=0;
        for(int ch:chalk){
            sum+=ch;
        }
        k%=sum;
        for(int i=0;i<chalk.size();i++){
            if(chalk[i]>k) return i;
            else k-=chalk[i];
        }
        return 0;
    }
};