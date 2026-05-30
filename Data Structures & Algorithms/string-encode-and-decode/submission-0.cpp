class Solution {
public:

    string encode(vector<string>& strs) {
        string final_string = "";
        string delimeter = "/";

        for ( const auto& str : strs ) {
            final_string += (to_string(str.size()) + delimeter + str );
        }
    
        return final_string;

    }

    vector<string> decode(string s) {
        vector<string> ans;

        auto iter = s.begin();

        while (iter != s.end()) {
            auto number_iter = iter;
            while ( *number_iter  != '/') number_iter++;
            string num = {iter, number_iter};
            int bytes = std::stoi(num);

            number_iter++;
            //now number_iter is my character extractor start
            auto end_string = number_iter;
            while ( bytes > 0 ) { end_string++; bytes--; }
            string extracted = {number_iter, end_string};
            ans.emplace_back(extracted);
            iter = end_string;
        }
        return ans;

    }
};
