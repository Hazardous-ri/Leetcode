class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        map<char,int>freq;
        for(int i=0;i<word.length();i++){
            freq[word[i]]++;
        }
        vector<pair<char, int>> v(freq.begin(), freq.end());

    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.second > b.second;  
    });
    
    for(int i=0;i<v.size();i++){
        if(i<8){
            ans+=v[i].second;
        }
        else if(i<16)ans+=2*v[i].second;
        else if(i<24)ans+=3*v[i].second;
        else ans+=4*v[i].second;
    }
    return ans;
    }
};