string dayOfTheWeek(int day, int month, int year) {
        vector<int> months {0,31,59,90,120,151,181,212,243,273,304,334};
        vector<string> weeks {"Sunday", "Monday", "Tuesday", "Wednesday", 
        "Thursday", "Friday", "Saturday"};

        int days=(year-1971)*365+(year-1969)/4;
        days=days+months[month-1]+day;
        if(year%4==0 && month>2) ++days;

        days=days-((year-1)/100-19);
        if(year%100==0 && month>2) --days;
        if(year>2000) ++days;

        return &weeks[(days+4) % 7][0];
    }
