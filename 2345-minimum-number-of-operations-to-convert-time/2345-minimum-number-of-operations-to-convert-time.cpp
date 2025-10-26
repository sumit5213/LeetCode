class Solution {
public:
    int convertTimeStringToMinutes(string timeString) {
        stringstream ss(timeString);
        string segment;
        int hours = 0;
        int minutes = 0;

        if (getline(ss, segment, ':')) {
            hours = std::stoi(segment);
        } else {
            return -1;
        }
        if (getline(ss, segment)) {
            minutes = stoi(segment);
        } else {
            return -1; 
        }

        return (hours * 60) + minutes;
    }

    int convertTime(string current, string correct) {
        int curr = convertTimeStringToMinutes(current);
        int corr = convertTimeStringToMinutes(correct);

        int minutes=corr-curr;
        int count=0;
        while(minutes>0){
            if(minutes>=60){
                minutes-=60;
                count++;
            }else if(minutes>=15){
                minutes-=15;
                count++;
            }else if(minutes>=5){
                minutes-=5;
                count++;
            }else{
                minutes-=1;
                count++;
            }
        }
        return count;
    }
};