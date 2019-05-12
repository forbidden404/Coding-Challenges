#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Tag {
    string name;
    vector<string> attribute_name;
    vector<string> attribute_value;
    vector<Tag *> children;
};

vector<Tag *> tags;
vector<Tag *> stack;
void get_tag(string line) {
    if (line.substr(0, 2) == "</") {
        stack.pop_back();
    } else {
        // create tag
        auto tag = new Tag();

        // name
        size_t initial = 1;
        size_t pos = line.find(" ");
        if (pos == string::npos) {
            pos = line.find(">");
        };
        tag->name = line.substr(initial, pos - initial);
        if (line.substr(pos) == ">") {
            pos = string::npos;
        }

        bool isAttributeName = true;
        while (pos != string::npos) {
            if (isAttributeName) {
                isAttributeName = false;
                initial = line.find(" ", pos) + 1;
                pos = line.find(" ", initial + 1);
                tag->attribute_name.push_back(line.substr(initial, pos - initial));
            } else {
                isAttributeName = true;
                initial = line.find("\"", pos) + 1;
                pos = line.find("\"", initial + 1);
                if (pos == string::npos) {
                    tag->attribute_value.push_back(
                            line.substr(initial, line.size() - initial - 1));
                } else {
                    tag->attribute_value.push_back(line.substr(initial, pos - initial));
                    if (line.substr(pos) == "\">") {
                        break;
                    }
                }
            }
        }

        if (!stack.empty()) {
            auto top = stack.back();
            top->children.push_back(tag);
        } else {
            tags.push_back(tag);
        }

        stack.push_back(tag);
    }
}

Tag *find(vector<Tag *> tags, string name) {
    for (int i = 0; i < tags.size(); i++) {
        if (tags[i]->name == name) {
            return tags[i];
        }
    }

    return nullptr;
}

void process_arg(string line) {
    vector<string> tag_names;
    int initial = 0;
    size_t pos = line.find(".");
    while (pos != string::npos) {
        tag_names.push_back(line.substr(initial, pos - initial));
        initial = pos + 1;
        pos = line.find(".", pos + 1);
    }

    pos = line.find("~");
    tag_names.push_back(line.substr(initial, pos - initial));
    auto attribute = line.substr(pos + 1);

    Tag *tag = nullptr;
    for (int i = 0; i < tag_names.size(); i++) {
        if (i == 0) {
            tag = find(tags, tag_names[i]);
            if (tag == nullptr)
                break;
        } else {
            if (tag == nullptr)
                break;
            tag = find(tag->children, tag_names[i]);
        }
    }

    if (tag == nullptr) {
        cout << "Not Found!" << endl;
        return;
    } else {
        for (int i = 0; i < tag->attribute_name.size(); i++) {
            if (tag->attribute_name[i] == attribute) {
                cout << tag->attribute_value[i] << endl;
                return;
            }
        }
        cout << "Not Found!" << endl;
    }
}

int main() {
    int q, n;
    scanf("%d %d%*c", &q, &n);

    for (int i = 0; i < q; i++) {
        string line;
        getline(cin, line);
        get_tag(line);
    }

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        process_arg(line);
    }

    return 0;
}

