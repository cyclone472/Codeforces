#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cassert>
using namespace std;

map<string, string> flags;

// Input string이 Alphabet으로만 구성되어 있는지 검사
bool is_string(string input) {
    for (int i = 0; i < input.size(); i++) {
        if ((input[i] < 'a' || input[i] > 'z') &&
            (input[i] < 'A' || input[i] > 'Z')) {
            return false;
        }
    }
    return true;
}

// Input string이 Number로만 구성되어 있는지 검사
bool is_number(string input) {
    for (int i = 0; i < input.size(); i++) {
        if (input[i] < '0' || input[i] > '9') {
            return false;
        }
    }
    return true;
}

// 한 flag가 두 번 이상 출현했는지 검사
// flag가 등장한 횟수를 저장하는 map을 input으로 받는다.
bool is_flag_duplicated (map<string, int>& num_flag_appear) {
    // num_flag_appear[flag_name] = number of flag appearance
    for (auto iter = num_flag_appear.begin(); iter != num_flag_appear.end(); iter++) {
        if (iter->second > 1) {
            return true;
        }
    }
    return false;
}

vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
    vector<bool> answer;

    // Input을 받아와 flags map에 저장한다.
    for (string& flag_rule : flag_rules) {
        int len = flag_rule.length();
        for (int i = 0; i < len; i++) {
            // flag rule의 공백을 찾아 앞뒤로 잘라 name과 argument 분류
            if (flag_rule[i] == ' ') {
                string flag_name = flag_rule.substr(0, i);
                string flag_arg = flag_rule.substr(i+1, len);
                flags[flag_name] = flag_arg;
            }
        }
    }
    
    for (string& elem : commands) {
        // Commands의 string을 공백을 기준으로 하나씩 parsing해
        // command 배열에 삽입한다.
        vector<string> command;
        int prev_idx = 0;        
        for (int i = 0; i < elem.length(); i++) {
            if (elem[i] == ' ') {
                command.push_back(elem.substr(prev_idx, i - prev_idx));
                prev_idx = i+1;
            }
        }        
        // 마지막 원소는 반복문에서 들어가지 않았으므로 추가로 삽입
        command.push_back(elem.substr(prev_idx, elem.length()));

        // 1. Program name이 올바른지 검사한다.
        if (command[0] != program) {
            answer.push_back(false);
            continue;
        }

        // 2. Flag가 존재하는지 검사하고
        // 3. 존재한다면 Argument type이 올바른지 검사한다.
        bool parse_result = true;
        map<string, int> num_flag_appear;

        // Parsing한 command를 순회한다.
        // 첫 번째 원소는 program name이므로 두 번째 원소부터 순회함
        for (int i = 1; i < command.size(); i++) {
            string flag_name = command[i];
            num_flag_appear[flag_name]++;
            
            // flag_name을 가진 원소가 존재하면 argument를 검사
            if (flags.count(command[i]) > 0) {
                string flag_arg = flags[flag_name];
                if (flag_arg == "STRING") {
                    // 마지막 원소이거나 flag argument가 string이 아니면 false
                    if (i == command.size() - 1 || !is_string(command[i+1])) {
                        parse_result = false;
                        break;
                    }
                    i++;
                }
                else if (flag_arg == "NUMBER") {
                    // 마지막 원소이거나 flag argument가 number이 아니면 false
                    if (i == command.size() - 1 || !is_number(command[i+1])) {
                        parse_result = false;
                        break;
                    }
                    i++;
                } 
                else if (flag_arg == "NULL") {
                    // 마지막 원소도 아니고 다음 원소가 flag로 시작하지도 않으면 false
                    if (!(i == command.size() - 1 || command[i+1][0] == '-')) {
                        parse_result = false;
                        break;
                    }
                }
                else {
                    assert("Flag argument rule isn't exist");
                }
            }
            // Flag name이 존재하지 않으면 false
            else {
                parse_result = false;
            }
        }

        // 같은 flag가 두 번 이상 나오지는 않았는지 검사
        if (is_flag_duplicated(num_flag_appear)) {
            parse_result = false;
        }
        // 모든 조건을 통과하면 True, 그렇지 않으면 False를 answer에 추가
        answer.push_back(parse_result);
    }
    return answer;
}