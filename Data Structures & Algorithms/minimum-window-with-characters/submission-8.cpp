class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for ( char c : t ) { t_map[c]++; }

        int left = -1;
        int start_left = -1;
        int word_len = INT_MAX;

        int need = t_map.size();
        int have = 0;

        for ( int right = 0; right < s.size(); right++ ) {
            //two cases
            //1. letter is not apart of the substring and we can continue
            //2. letter is apart of the word and we are interested

            char c = s[right];
            if ( t_map.count(c) ){
                left = ( left == -1 ) ? right : left; //we need to set left the first time we get a letter of interest
                                                        // manually set o.w.

                s_map[c]++;
                if ( s_map[c] == t_map[c] ) { have++; }

    

                //if we have collected all the groups then we can set our length
                if ( have == need ) {

                    cout << "Right: " << right << endl;
                    

                    int cur_size = right - left + 1;
                    word_len = setNewSize(word_len, cur_size, left, start_left);

                    cout << "Cur size: " << cur_size << endl;
                    cout << "Start left: " << start_left << endl;
                    

                    //after we have done this we need to move left until we break the 
                    //invariant that have = need
                    // we also keep moving until we are on a vowel

                    cout << "Have: " << have << endl;
                    cout << "Need: " << need << endl;

                    while ( have == need ) {
                        //set the new size here for if we have to loop > 1 time
                        int new_size = right - left + 1;
                        word_len = setNewSize(word_len, new_size, left, start_left);

                        cout << "In loop size: " << word_len << endl;

                        char l_char = s[left];
                        if ( !t_map.count(l_char) ) { left++; continue; }
                        s_map[l_char]--;

                        if ( s_map[l_char] < t_map[l_char] ) { have--; }

                        left++;
                    }

                    cout << "New left: " << left << endl;
                    cout << "-" << endl;

                    //now we have a new window, we just need to move in the window to start on a vowel
                    while ( left < right && !t_map.count(s[left]) ) {
                        left++;
                    }

                }
            }
        }
        return ( start_left == -1 ) ? "" : s.substr(start_left, word_len);
    }

    inline int setNewSize(int old_size, int new_size, int left, int& start_left){
        if ( new_size < old_size ) {
            start_left = left;
            return new_size;
        }
        return old_size;
    }
};
