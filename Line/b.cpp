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

bool is_flag_name (string input) {
    return input[0] == '-';
}

// command[idx]에 존재하는 flag에 대한 flag argument들을 return
vector<string> get_flag_arg(vector<string>& command, int idx) {
    vector<string> ret;

    // 새로운 flag name이 등장할 때까지 순회
    int iter = idx + 1;
    while (iter < command.size() && !is_flag_name(command[iter])) {
        ret.push_back(command[iter]);
        iter++;
    }
    return ret;
}

bool is_proper_arg_type (string flag_arg_type, vector<string>& flag_args) {
    int num_flag_arg = flag_args.size();
    if (flag_arg_type == "STRING") {
        // flag argument의 개수가 1개가 아니거나
        // argument의 type이 string이 아니면 false
        if (flag_args.size() != 1 || !is_string(flag_args[0])) {
            return false;
        }
    }
    else if (flag_arg_type == "STRINGS") {
        if (flag_args.size() < 1) {
            return false;
        }

        for (string& arg : flag_args) {
            if (!is_string(arg)) {
                return false;
            }
        }
    }
    else if (flag_arg_type == "NUMBER") {
        if (flag_args.size() != 1 || !is_number(flag_args[0])) {
            return false;
        }
    } 
    else if (flag_arg_type == "NUMBERS") {
        if (flag_args.size() < 1) {
            return false;
        }

        for (string& arg : flag_args) {
            if (!is_number(arg)) {
                return false;
            }
        }
    }
    else if (flag_arg_type == "NULL") {
        // 마지막 원소도 아니고 다음 원소가 flag로 시작하지도 않으면 틀림
        if (num_flag_arg != 0) {
            return false;
        }
    }
    else {
        assert("Flag argument rule isn't exist");
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
                string flag_arg_type = flags[flag_name];
                // flag argument들을 vector로 받아온다.
                vector<string> flag_args = get_flag_arg(command, i);
                int num_flag_arg = flag_args.size();

                // argument type이 올바른지 검사한다.
                parse_result = is_proper_arg_type(flag_arg_type, flag_args);

                if (parse_result == false) {
                    break;
                }
                else {
                    // 올바른 type이라면 flag argument의 개수만큼 더해줘서
                    // 다음 flag를 검사할 수 있도록 한다.
                    i += num_flag_arg;
                }                
            }
            // Flag name이 존재하지 않으면 false
            else {
                parse_result = false;
            }
        }
        
        // 같은 flag가 두 번 이상 나오지는 않았는지
        if (is_flag_duplicated(num_flag_appear)) {
            parse_result = false;
        }
        // 모든 조건을 통과하면 True, 그렇지 않으면 False를 answer에 추가
        answer.push_back(parse_result);
    }
    return answer;
}

int main() {
    string program = "line";
    vector<string> flag_rules;
    string rule[3] = {"-s STRINGS", "-n NUMBERS", "-e NULL"};
    for (int i = 0; i < 3; i++) {
        flag_rules.push_back(rule[i]);
    }
    vector<string> commands;
    commands.push_back("line -n 100 102 -s hi -e");

    vector<bool> answ = solution(program, flag_rules, commands);
    for (bool x : answ) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}