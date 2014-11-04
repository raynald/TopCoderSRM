nclude<string>

using namespace std;

class NamingConvention {
    public:
        string toCamelCase(string input) {
            string ans = "";
            for(int i=0;i<input.length();i++) {
                if(input[i]=='_') {
                    ans += char('A'+input[i+1]-'a');
                    i++;
                }
                else
                    ans += input[i];
            }
            return ans;
        }
};

