// 文字列の初期化
#include <iostream>
#include <string>

int main() {
    // 文字列の初期化
    std::string str1 = "Hello, World!";
    std::string str2("Hello, AtCoder!");

    // 出力例
    std::cout << str1 << std::endl; // Hello, World!
    std::cout << str2 << std::endl; // Hello, AtCoder!
    
    return 0;
}



// 文字列の連結
#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello, ";
    std::string str2 = "World!";
    std::string str3 = str1 + str2;

    // 出力例
    std::cout << str3 << std::endl; // Hello, World!
    
    return 0;
}



// アルファベットの大文字と小文字を入れ替える方法
#include <iostream>
#include <cctype>

int main() {
    char c = 'a';
    char converted;

    if (isupper(c)) {
        converted = tolower(c);
    } else if (islower(c)) {
        converted = toupper(c);
    } else {
        converted = c;  // アルファベットではない場合、そのままにする
    }

    std::cout << c << " を変換すると " << converted << " になります。" << std::endl;

    return 0;
}



// 文字列を数値に変換する方法
// std::stoi、std::stol、std::stoll、std::stof、std::stod、std::stold
// それぞれint、long、long long、float、double、long doubleに変換します。
#include <iostream>
#include <string>

int main() {
    std::string str = "12345";
    int num = std::stoi(str);
    std::cout << "Integer: " << num << std::endl;
    
    str = "123.45";
    double dnum = std::stod(str);
    std::cout << "Double: " << dnum << std::endl;

    return 0;
}


// 数値を文字列に変換する方法
#include <iostream>
#include <string>

int main() {
    int num = 12345;
    std::string str = std::to_string(num);
    std::cout << "String: " << str << std::endl;

    double dnum = 123.45;
    str = std::to_string(dnum);
    std::cout << "String: " << str << std::endl;

    return 0;
}



// 文字列の長さを取得
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // 文字列の長さを取得
    size_t length = str.length();

    // 出力例
    std::cout << "Length: " << length << std::endl; // Length: 13
    
    return 0;
}



// 文字列の部分文字列を取得
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // 部分文字列を取得
    std::string substr = str.substr(7, 5); // "World"

    // 出力例
    std::cout << "Substring: " << substr << std::endl; // Substring: World
    
    return 0;
}



// 文字列の置換
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // 文字列の置換
    str.replace(7, 5, "AtCoder");

    // 出力例
    std::cout << str << std::endl; // Hello, AtCoder!
    
    return 0;
}



// 文字列の分割
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string str = "Hello, World! This is AtCoder.";
    std::istringstream iss(str);
    std::string word;
    std::vector<std::string> words;

    // 文字列の分割
    while (iss >> word) {
        words.push_back(word);
    }

    // 出力例
    for (const auto& w : words) {
        std::cout << w << std::endl;
    }
    // Hello,
    // World!
    // This
    // is
    // AtCoder.

    return 0;
}



// 文字列の検索
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // 文字列の検索
    size_t pos = str.find("World");

    // 出力例
    if (pos != std::string::npos) {
        std::cout << "'World' found at position: " << pos << std::endl; // 'World' found at position: 7
    } else {
        std::cout << "'World' not found" << std::endl;
    }
    
    return 0;
}



// 特定の文字列を検索し、その位置を全て出力するには、
// std::string::findをループで使って繰り返し検索を行う方法があります。
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string str = "This is a test string. This string is for testing.";
    std::string target = "is";
    std::vector<size_t> positions;
    size_t pos = str.find(target);

    // target文字列が見つかる限りループ
    while (pos != std::string::npos) {
        positions.push_back(pos);
        pos = str.find(target, pos + 1);
    }

    // 結果を出力
    if (positions.empty()) {
        std::cout << "The substring \"" << target << "\" was not found in the string." << std::endl;
    } else {
        std::cout << "The substring \"" << target << "\" was found at positions: ";
        for (size_t p : positions) {
            std::cout << p << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}



// 特定の文字のカウント
#include <iostream>
#include <string>

int countOccurrences(const std::string& str, char ch) {
    size_t pos = str.find(ch);
    int count = 0;
    while (pos != std::string::npos) {
        ++count;
        pos = str.find(ch, pos + 1);
    }
    return count;
}

int main() {
    std::string str = "This is a test string.";
    char ch = 's';
    int count = countOccurrences(str, ch);
    std::cout << "Character '" << ch << "' appears " << count << " times in the string." << std::endl;
    return 0;
}



// 部分文字列のチェック
#include <iostream>
#include <string>

bool startsWith(const std::string& str, const std::string& prefix) {
    return str.find(prefix) == 0;
}

bool endsWith(const std::string& str, const std::string& suffix) {
    return str.rfind(suffix) == (str.size() - suffix.size());
}

int main() {
    std::string str = "Hello, world!";
    std::string prefix = "Hello";
    std::string suffix = "world!";
    
    if (startsWith(str, prefix)) {
        std::cout << "The string starts with \"" << prefix << "\"." << std::endl;
    }
    if (endsWith(str, suffix)) {
        std::cout << "The string ends with \"" << suffix << "\"." << std::endl;
    }
    
    return 0;
}



// 特定の位置からの検索
#include <iostream>
#include <string>

int main() {
    std::string str = "This is a test string. This string is for testing.";
    std::string target = "is";
    size_t startPos = 5;
    
    size_t pos = str.find(target, startPos);
    if (pos != std::string::npos) {
        std::cout << "Found \"" << target << "\" at position: " << pos << " starting from position " << startPos << std::endl;
    } else {
        std::cout << "\"" << target << "\" not found starting from position " << startPos << std::endl;
    }
    
    return 0;
}



// 文字列の一部を抽出
#include <iostream>
#include <string>

int main() {
    std::string str = "This is a test string.";
    std::string start = "is";
    std::string end = "st";
    
    size_t startPos = str.find(start);
    size_t endPos = str.find(end, startPos);
    
    if (startPos != std::string::npos && endPos != std::string::npos) {
        std::string extracted = str.substr(startPos, endPos - startPos + end.length());
        std::cout << "Extracted string: " << extracted << std::endl;
    } else {
        std::cout << "Could not extract the substring." << std::endl;
    }
    
    return 0;
}



// 文字列の置換
#include <iostream>
#include <string>

std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t startPos = 0;
    while((startPos = str.find(from, startPos)) != std::string::npos) {
        str.replace(startPos, from.length(), to);
        startPos += to.length();
    }
    return str;
}

int main() {
    std::string str = "This is a test string.";
    std::string from = "is";
    std::string to = "XX";
    
    std::string result = replaceAll(str, from, to);
    std::cout << "Original string: " << str << std::endl;
    std::cout << "Modified string: " << result << std::endl;
    
    return 0;
}