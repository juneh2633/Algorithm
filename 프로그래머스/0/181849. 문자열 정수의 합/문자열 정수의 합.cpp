#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    for(auto &c: num_str){
        answer+= c-'0';
    }
    return answer;
}