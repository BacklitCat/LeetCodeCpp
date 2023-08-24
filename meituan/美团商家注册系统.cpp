#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_set>

using namespace std;

// 牛客 美团24秋招第2场第7题
// 送分语法题

bool is_valid(string &str) {
    for (auto s: str) {
        if (s < 'a' || s > 'z') {
            return false;
        }
    }
    return true;
}

// 主店 <店名,<地址,分店数量>>
map<string, pair<string, int>> master;
// 分店 <店名-地址>
unordered_set<string> slave;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string name, addr, slave_key;
    stringstream ss;
    master.clear();
    slave.clear();
    ss.clear();
    ss.str("");
    cin >> n;
    while (cin >> name >> addr) {
        // 合法校验
        if (!is_valid(name) || !is_valid(addr)) {
            continue;
        }
        // 注册主店
        auto master_itor = master.find(name);
        if (master_itor == master.end()) {
            master[name] = {addr, 0};
            continue;
        }else if(addr == master_itor->second.first){
            continue;
        }
        // 注册分店
        ss.str("");
        ss << name << "-" << addr;
        slave_key = ss.str();
//        cout << "slave_key="<<slave_key<<endl;
        // 已经注册过不再注册
        if (slave.find(slave_key) != slave.end()) {
            continue;
        }
        slave.emplace(slave_key);
        master_itor->second.second += 1;
    }

    for (auto const &kv: master) {
        cout << kv.first << " " << kv.second.first << " " << kv.second.second << endl;
    }
}
