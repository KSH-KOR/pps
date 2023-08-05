// 불필요한 함수 find()를 제거하고, string::find()를 사용하여 문자열에서 문자를 찾도록 변경하였다.
// 불필요한 temp 벡터를 제거하고, 이전 스킬 순서를 추적하는 prevIndex 변수를 사용하여 스킬 트리를 검사하게 하였다.
// 중복된 조건문을 합쳐 코드를 더 간결하게 만들었다.
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    if (skill_trees.empty()) return 0;
    if (skill.empty()) return skill_trees.size();
    
    int answer = 0;
    for (const auto& skillTree : skill_trees) {
        int prevIndex = -1;
        bool isValid = true;
        
        for (char s : skillTree) {
            int index = skill.find(s);
            if (index == string::npos) continue;
            
            if (prevIndex != index - 1) {
                isValid = false;
                break;
            }
            prevIndex = index;
        }
        
        if (isValid) answer++;
    }
    
    return answer;
}


/*

#include <string>
#include <vector>

using namespace std;

int find(const string skillList, const char skill) {
    for (int i = 0; i < sizeof(skillList); i++) {
        if (skillList[i] == skill) return i;
    }
    return -1;
}

bool check(vector<int> temp) {
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] != i) return false;
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    if (skill_trees.empty()) return 0;
    if (skill.empty()) return skill_trees.size();
    int answer = 0;
    vector<int> temp;
    for (auto skillTree : skill_trees) {
        temp.clear();
        for (auto s : skillTree) {
            int index = find(skill, s);
            if (index == -1) continue;
            temp.push_back(index);
        }
        if (check(temp)) answer++;
    }
    return answer;
}

*/