class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> atomCount;
        stack<map<string, int>> st;
        int n = formula.length();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                st.push(atomCount);
                atomCount.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int multiplicity =
                    (start < i) ? stoi(formula.substr(start, i - start)) : 1;

                if (!st.empty()) {
                    map<string, int> temp = atomCount;
                    atomCount = st.top();
                    st.pop();
                    for (auto& p : temp) {
                        atomCount[p.first] += p.second * multiplicity;
                    }
                }
            } else {
                int start = i;
                i++; // skip the uppercase letter
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string element = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int count =
                    (start < i) ? stoi(formula.substr(start, i - start)) : 1;
                atomCount[element] += count;
            }
        }

        string result;
        for (auto& p : atomCount) {
            result += p.first;
            if (p.second > 1) {
                result += to_string(p.second);
            }
        }
        return result;
    }
};