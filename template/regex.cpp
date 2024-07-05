// 正規表現を使った検索
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string str = "This is a test string. Test it well.";
    std::regex pattern("test", std::regex_constants::icase); // case-insensitive search
    
    auto words_begin = std::sregex_iterator(str.begin(), str.end(), pattern);
    auto words_end = std::sregex_iterator();
    
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::cout << "Found: " << match.str() << " at position " << match.position() << std::endl;
    }
    
    return 0;
}



// 正規表現による文字列の置換
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text = "The quick brown fox jumps over the lazy dog.";
    std::regex pattern("fox");
    std::string replacement = "cat";

    std::string result = std::regex_replace(text, pattern, replacement);
    std::cout << "Original: " << text << std::endl;
    std::cout << "Modified: " << result << std::endl;

    return 0;
}



// 複雑なパターンマッチング
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text = "Please contact us at support@example.com.";
    std::regex pattern(R"(([\w.%+-]+)@([\w.-]+\.[a-zA-Z]{2,}))");

    std::smatch match;
    if (std::regex_search(text, match, pattern)) {
        std::cout << "Email found: " << match.str() << std::endl;
        std::cout << "Local part: " << match[1].str() << std::endl;
        std::cout << "Domain part: " << match[2].str() << std::endl;
    } else {
        std::cout << "No email found." << std::endl;
    }

    return 0;
}



// 正規表現のフラグを使用
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text = "Line one\nLine two\nLine three";
    std::regex pattern(R"(^Line)", std::regex_constants::multiline);

    auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::cout << "Found: " << match.str() << " at position " << match.position() << std::endl;
    }

    return 0;
}



// 正規表現のグループ化とキャプチャ
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text = "My phone number is 123-456-7890.";
    std::regex pattern(R"((\d{3})-(\d{3})-(\d{4}))");

    std::smatch match;
    if (std::regex_search(text, match, pattern)) {
        std::cout << "Full match: " << match.str() << std::endl;
        std::cout << "Area code: " << match[1].str() << std::endl;
        std::cout << "Prefix: " << match[2].str() << std::endl;
        std::cout << "Line number: " << match[3].str() << std::endl;
    } else {
        std::cout << "No phone number found." << std::endl;
    }

    return 0;
}



// 主な正規表現フラグ

// std::regex_constants::icase
// 大文字と小文字を区別せずにマッチングを行います。
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text = "Hello World";
    std::regex pattern("hello", std::regex_constants::icase);
    
    if (std::regex_search(text, pattern)) {
        std::cout << "Match found!" << std::endl;
    } else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}

// std::regex_constants::multiline
// 行の先頭（^）と行の末尾（$）が、文字列全体の先頭や末尾ではなく、
// 各行の先頭や末尾にマッチするようになります。
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text = "Line one\nLine two\nLine three";
    std::regex pattern("^Line", std::regex_constants::multiline);

    auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::cout << "Found: " << match.str() << " at position " << match.position() << std::endl;
    }

    return 0;
}

// std::regex_constants::nosubs
// キャプチャグループの情報を保持せず、マッチ全体だけを考慮します。
// これは検索操作のパフォーマンスを向上させるために使用されます。
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text = "Sample text with numbers 12345";
    std::regex pattern(R"(\d+)", std::regex_constants::nosubs);

    if (std::regex_search(text, pattern)) {
        std::cout << "Match found!" << std::endl;
    } else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}

// std::regex_constants::optimize
// 正規表現の検索パフォーマンスを最適化します。
// コンパイル時間が長くなる場合がありますが、検索パフォーマンスが向上することがあります。
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text = "Optimization test text";
    std::regex pattern("test", std::regex_constants::optimize);

    if (std::regex_search(text, pattern)) {
        std::cout << "Match found!" << std::endl;
    } else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}

// std::regex_constants::egrep
// egrepスタイルの正規表現を使用します。これには、拡張されたメタ文字セットが含まれます。
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text = "Number: 12345";
    std::regex pattern(R"(\d+)", std::regex_constants::egrep);

    if (std::regex_search(text, pattern)) {
        std::cout << "Match found!" << std::endl;
    } else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}

// フラグの組み合わせ
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text = "First line\nSecond line\nTHIRD LINE";
    std::regex pattern("line$", std::regex_constants::icase | std::regex_constants::multiline);

    auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::cout << "Found: " << match.str() << " at position " << match.position() << std::endl;
    }

    return 0;
}



// 正規表現パターンの最初についているRは、生文字列リテラル（raw string literal）を表しています。
// C++11以降の機能で、Rを使うことでエスケープシーケンス（例えば、\nや\tなど）を無視し、文字列をそのままの形で扱うことができます。
// 正規表現パターンを記述する際に非常に便利です。

// 生文字列リテラル（raw string literal）の利点
// エスケープシーケンスを気にしなくて済む: 通常の文字列リテラルでは、バックスラッシュ（\）をエスケープする必要がありますが、生文字列リテラルではその必要がありません。
// 正規表現のパターンが見やすい: 正規表現の特定の文字（例えば、\dや\wなど）をエスケープする必要がなく、コードが読みやすくなります。

// 生文字列リテラルの使用例
// 通常の文字列リテラル
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "This is a test string with number 12345";
    std::regex pattern("\\d+"); // バックスラッシュをエスケープする必要がある

    if (std::regex_search(text, pattern)) {
        std::cout << "Match found!" << std::endl;
    } else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}

// 生文字列リテラル
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "This is a test string with number 12345";
    std::regex pattern(R"(\d+)"); // 生文字列リテラルを使うとエスケープが不要

    if (std::regex_search(text, pattern)) {
        std::cout << "Match found!" << std::endl;
    } else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}


// 例：Windowsファイルパス
#include <iostream>
#include <string>

int main() {
    std::string path = R"(C:\Users\Example\Documents\file.txt)";
    std::cout << "Path: " << path << std::endl;
    return 0;
}